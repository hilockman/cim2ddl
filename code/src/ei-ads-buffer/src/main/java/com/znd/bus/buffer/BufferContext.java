package com.znd.bus.buffer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.ServiceFactory;
import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.MessageCallBack;
import com.ZhongND.RedisDataBus.Api.RBufferBuilder;
import com.ZhongND.RedisDataBus.Api.RBufferOperation;
import com.ZhongND.RedisDataBus.Api.RMemDBApi;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.ZhongND.RedisDataBus.Api.RPubSubManager;
import com.ZhongND.RedisDataBus.Api.RTableBuilder;
import com.ZhongND.RedisDataBus.Api.RTableOperation;
import com.ZhongND.RedisDataBus.Enum.MessageChannel;
import com.ZhongND.RedisDataBus.Enum.RedisTableColumnType;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.ZhongND.RedisDataBus.Object.MessageContent;
import com.ZhongND.RedisDataBus.Object.RedisColumnContent;
import com.znd.bus.binding.BindingException;
import com.znd.bus.channel.Channel;
import com.znd.bus.channel.ChannelConfig;
import com.znd.bus.channel.ChannelType;
import com.znd.bus.channel.Event;
import com.znd.bus.channel.Listener;
import com.znd.bus.channel.Message;
import com.znd.bus.channel.defaults.DefaultChannel;
import com.znd.bus.channel.defaults.MessageException;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.BufferConfigException;
import com.znd.bus.config.ColumnMeta;
import com.znd.bus.config.TableMeta;
import com.znd.bus.util.TimeCount;


public  class BufferContext {
	
	
	private final Logger logger = LoggerFactory.getLogger(BufferContext.class);
	
	private final String name;
	private final DFService service;
	private final RMemDBApi memDBApi;
	private final RMemDBBuilder memDBBuilder;
	private RBufferOperation bufferOperation;
	private final RPubSubManager pubSubManager;
	
	
	public BufferContext(String name, DFService service, RMemDBApi memDBApi, RMemDBBuilder memDBBuilder,  RPubSubManager pubSubManager) {
		this.name = name;
		this.service = service;
		this.memDBApi = memDBApi;
		this.memDBBuilder = memDBBuilder;
		this.pubSubManager = pubSubManager;
	}
	
	public static class Builder {
		private BufferContext context;
		private final BufferConfig config;
		public Builder(BufferConfig config) {
			this.config = config;

		}
		
		public BufferContext build() {					
			try {
				if (config.getName() == null || config.getName().isEmpty()) {
					throw new BufferConfigException("buffer name is null.");
				}
				DFService service = ServiceFactory.getService();
				RMemDBApi memDBApi = service.connect(config.getAppName());

				RMemDBBuilder memDBBuilder = memDBApi
						.getRMemDBBuilder(config.getName());	
				
				context = new BufferContext(config.getName(), service, memDBApi, memDBBuilder, memDBApi.getPubSubManager());									
			} catch (Throwable e) {
				throw new BufferConfigException(e.getMessage(), e);
			}

			
			return context;
		}
		
	}
	
	public void initOperation()
	{
		if (bufferOperation != null)
			return;
		
		//get buffer
		try {
			bufferOperation = memDBBuilder.getBufferOperation();
			logger.info("Succeed to get buffer operation : {}.", name);		
		} catch (RedissonDBException e) {
			throw new BufferException("Fail to get buffer operation.", e);
		}	
	}
	
	/**
	 * check buffer is available or not.
	 */
	public boolean checkAvailable() {
		try {
			return memDBBuilder.checkAvailability();			
		} catch (RedissonDBException e) {
			throw new BufferException("Fail to check availability.", e);
		}
	}

	public DFService getService() {
		return service;
	}

	public RMemDBApi getMemDBApi() {
		return memDBApi;
	}

	public RMemDBBuilder getMemDBBuilder() {
		return memDBBuilder;
	}
	
	public void updateTableMeta(TableMeta tableMeta)
	{
		try {			
			String tableName = tableMeta.getName();
			RTableOperation tableOps = bufferOperation.getTableOperation(tableName);
			if (tableOps == null) {
				throw new BindingException("Fail to get table operations : "+tableName);
			}

				
			List<String> columnNames = tableOps.getColumnNameArray();
			for (ColumnMeta column : tableMeta.getColumns()) {
				column.setIndex(-1);
			}
			int i = 0;
			for (String columnName : columnNames) {
				ColumnMeta columnMeta = tableMeta.findColumn(columnName);
				if (columnMeta == null) {
					columnMeta = new ColumnMeta();
					tableMeta.getColumns().add(columnMeta);
				}
				RedisColumnContent colDefine = tableOps.getColumnDefine(columnName);
				colDefine.getIndexType();
				columnMeta.setIndexable(colDefine.getIndexType());
				columnMeta.setName(columnName);
				//columnMeta.setType(BufferFactoryBuilder.toType(colDefine.getType()));
				columnMeta.setDbIndex(tableOps.getColumnIndex(columnName));
				columnMeta.setIndex(i++);
			}
			tableMeta.formIndexColumn();

		} catch (RedissonDBException e) {
			throw new BindingException(e.getMessage(), e);
		}
	}
	
	// 判断表示否改变
	private boolean isTableChanged(List<RedisColumnContent> columnNames,
			TableMeta tableBuilder) {
		List<ColumnMeta> columns = tableBuilder.getColumns();
		Collections.sort(columns, (a, b) -> {
			return a.getName().compareTo(b.getName());
		});
		Collections.sort(columnNames, (a, b)->{ return a.getStrFieldName().compareTo(b.getStrFieldName());});
		int i = 0, j = 0;
		for (; i < columns.size() && j < columnNames.size();) {

			RedisColumnContent columDefine = columnNames.get(j);
			int c = columns.get(i).getName().compareTo(columDefine.getStrFieldName());
			if (c == 0) {
				if (!columDefine.getIndexType() == columns.get(i).isIndexable())
					return true;
				i++;
				j++;
				continue;
			} else if (c < 0) {
				return true;
			} else {
				return true;
			}

		}

		return i != j;
	}
	
	/**
	 * 判断buffer定义师傅有变化
	 * @param config
	 * @return
	 */
	
	public boolean isBufferDefineChanged(BufferConfig config) {
		List<TableMeta> changedTables = new ArrayList<>();
		List<String> tableNames;
		try {
			tableNames = (bufferOperation != null) ? bufferOperation
					.getTableNameArray() : new ArrayList<>();
			TableMeta[] tableMetas = config.getTableMetas();
			for (TableMeta tableMeta : tableMetas) {
				
				
				if (tableNames.indexOf(tableMeta.getName()) < 0) {
					changedTables.add(tableMeta);
					continue;
				}
												
				RTableOperation ops = bufferOperation.getTableOperation(tableMeta.getName());
				List<String> columnNames = ops.getColumnNameArray();
				List<RedisColumnContent> columnDefines = new ArrayList<>();
				for (String columnName : columnNames){
					columnDefines.add(ops.getColumnDefine(columnName));
				}
				if (isTableChanged(columnDefines, tableMeta)) {
					changedTables.add(tableMeta);
					
				}
			}
			
			if (!changedTables.isEmpty()) 
				return true;	
		
		} catch (RedissonDBException e) {
			throw new BindingException(e.getMessage(), e);
		}
			
		return false;
	}

	public String getName() {
		return name;
	}
	
	private  void loadColumnMetas(TableMeta tableMeta, RBufferOperation bufferOps) throws RedissonDBException {	
		RTableOperation tableOps = bufferOps.getTableOperation(tableMeta.getName());
		List<String> colNames = tableOps.getColumnNameArray();
		for (int i = 0; i < colNames.size(); i++) {
			RedisColumnContent content = tableOps.getColumnDefine(colNames.get(i));
			ColumnMeta col = new ColumnMeta();
			col.setName(content.getStrFieldName());
			col.setIndexable(content.getIndexType());
			//col.setType(BufferFactoryBuilder.toType(content.getType()));
			tableMeta.getIndexColumns().add(col);		
		}
		tableMeta.formIndexColumn();
	}
	
	public TableMeta  createTableMeta(String tableName) {

			try {
				RBufferOperation bufferOps = memDBBuilder.getBufferOperation();
				List<String> tables = bufferOps.getTableNameArray();
				Collections.sort(tables);
				int index = Collections.binarySearch(tables, tableName);
				if (index == -1) {
					throw new RuntimeException(String.format("Find no table:'%s', in buffer : %s", tableName, this.name));
				}
				TableMeta tableMeta = new TableMeta();
				tableMeta.setName(tableName);
				
				loadColumnMetas(tableMeta, bufferOps);			
		        return tableMeta;				
			} catch (RedissonDBException e) {
				e.printStackTrace();
				throw new RuntimeException(e);
			}			
		
	}
	
	public RTableOperation getTableOperation(TableMeta tableMeta){

		try {
			RBufferOperation bufferOps = memDBBuilder.getBufferOperation();
			return bufferOps.getTableOperation(tableMeta.getName());
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			throw new RuntimeException("Find no talbe :"+tableMeta.getKey());
		}
	}

	/**
	 * 关闭连接，会造成reddison连接关闭
	 */
	public void close() {
		service.disConnect();
	}
	
	
	public void removeTable(String name) throws RedissonDBException {
		memDBBuilder.getBufferBuilder().destory(name); 
		logger.info("Table removed : {} .", name);
	}

	public void removeBuffer() throws RedissonDBException {
		//close();
		removeBuffer(memDBBuilder, name);
	}
	
	private void removeBuffer(RMemDBBuilder memDBBuilder, String key)
			throws RedissonDBException {
		memDBBuilder.destory();
		logger.info("Buffer destoryed : {}", key);			
	}

	public void makeBuffer(List<TableMeta> tableMetas) throws RedissonDBException {
		
		// 创建buffer
		RBufferBuilder bufferBuilder = memDBBuilder.getBufferBuilder();
		logger.info("Succeed to create buffer : {}.", name);
				
		try {
			
			//create system table : log, task
			
			if (tableMetas != null && !tableMetas.isEmpty()){		
				// 创建表
				for (TableMeta tableBuilder : tableMetas) {
					makeTable(bufferBuilder, tableBuilder);
				}
			}
			
		} finally {
			// commit buffer
			bufferBuilder.commit();
			logger.info("Succeed to commit buffer: {}.", name);
			
			initOperation();
		}
	}

	public void makeTable(RBufferBuilder bufferBuilder, TableMeta tableDefine)
			throws RedissonDBException {
		if (bufferBuilder.checkIsExists(tableDefine.getName()))
			return;	
		
		RTableBuilder tableBuilder = bufferBuilder.getTableBuilder(tableDefine
				.getName());
		
//		for (ColumnMeta c : tableDefine.getColumns()) {
//			tableBuilder.setColumn(c.getName(), typeMap.get(c.getType()), c.isIndexable());
//		}

		for (ColumnMeta c : tableDefine.getColumns()) {
			try {
			tableBuilder.setColumn(c.getName(), RedisTableColumnType.RedisTableColumnType_String, c.isIndexable());
			} catch (RedissonDBException e) {
				throw new BufferException("Fail to create colum : "+c.getName()+" for table :"+tableDefine.getName(), e);
			}
		}
		
		logger.info("Table created: {}, clumn size = {}.",
				tableDefine.getName(), tableDefine.getColumnSize());
	}

	public  class ChannelWrapper implements Channel
	{
		private final Channel delegate;
		public ChannelWrapper(Channel channel) {
			this.delegate  = channel;
		}

		@Override
		public void send(Message message) {			
			sendMessage(delegate.getName(), message);
		}

		@Override
		public void register(Listener listener) {
			delegate.register(listener);
		}

		@Override
		public void receive(Event e) {
			delegate.receive(e);
		}

		@Override
		public void close() {
			
			MessageChannel channel = MessageChannel.OTHERCHANNEL;
			synchronized (channel) {
				  try {
					channel.setStrChannel(getName());
					new TimeCount.Builder()
					.name("unsubscribe channel '%s'", getName())
					.logger(logger).runnable(()->{
							try {
								pubSubManager.unSubscribeMessage(channel);
							} catch (Exception e) {
								throw new BufferException(e);
							}
						}
					).build().exec();
			
				} catch (Exception e) {
					throw new BufferException(e);
				}
				  				
			}
			
			delegate.close();
		}

		@Override
		public ChannelType getType() {
			return delegate.getType();
		}

		@Override
		public String getName() {
			return delegate.getName();
		}
		
	}
	
	private Channel createChannelWrapper(String name, ChannelType type) {
		return new ChannelWrapper(new DefaultChannel(name, type));
	}
	
	public Channel registChannel(ChannelConfig channelConfig) {		
		MessageChannel channel = MessageChannel.OTHERCHANNEL;
		synchronized (channel) {
			try {
				String name = channelConfig.getName();
			    ChannelType type = channelConfig.getType();
				channel.setStrChannel(name);
				
				final Channel bufferChannel = createChannelWrapper(name, type);
				
				if (type != ChannelType.SEND) {
					pubSubManager.subscribeMessage(new MessageCallBack() {
						
						@Override
						public void CallBack(int number, MessageContent messageContent) {
							Event event = new Event(messageContent.getControlCode(), messageContent.getEventContent());
							logger.debug("Receive message : number={}, content={}",number, event);
							bufferChannel.receive(event);
						}
					}, channel, type == ChannelType.CACHE ? true : false);
				}
				return bufferChannel;
			} catch (Exception e) {
				throw new MessageException(e);
			}
		}
	}
	
	public void sendMessage(String channelName, Message message) {
		MessageChannel channel = MessageChannel.OTHERCHANNEL;
		synchronized (channel) {
			try {
				channel.setStrChannel(channelName);
				pubSubManager.publishMessage(channel, message.getCode(), message.getContent());
				logger.debug("Send message '{}', by channel : {} ", message, channelName);
			} catch (Exception e) {
				throw new MessageException(e);
			}			
		}

	}


}