package com.znd.bus.buffer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.TimeUnit;

import org.redisson.api.RBlockingQueue;
import org.redisson.api.RTopic;
import org.redisson.api.RedissonClient;
import org.redisson.api.listener.MessageListener;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.ServiceFactory;
import com.ZhongND.RedisDataBus.Api.DFService;
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
import com.ZhongND.RedisDataBus.Object.RedisColumnContent;
import com.znd.bus.channel.Channel;
import com.znd.bus.channel.ChannelConfig;
import com.znd.bus.channel.ChannelMessage;
import com.znd.bus.channel.ChannelType;
import com.znd.bus.channel.Listener;
import com.znd.bus.channel.defaults.DefaultChannel;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.BufferConfigException;
import com.znd.bus.config.ColumnMeta;
import com.znd.bus.config.TableMeta;
import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.BufferException;
import com.znd.bus.exception.MessageException;
import com.znd.bus.server.Topic;
import com.znd.ei.Utils;


public  class BufferContext {
	
	
	private final Logger logger = LoggerFactory.getLogger(BufferContext.class);
	
	private final String name;
	private final DFService service;
	private final RMemDBApi memDBApi;
	private final RMemDBBuilder memDBBuilder;
	private RBufferOperation bufferOperation;
	private final RPubSubManager pubSubManager;
	private final RedissonClient redisson;
	
	private final ExecutorService pool = Utils.threadPool();
	
	
	public BufferContext(String name, DFService service, RMemDBApi memDBApi, RMemDBBuilder memDBBuilder,  RPubSubManager pubSubManager, RedissonClient redisson) {
		this.name = name;
		this.service = service;
		this.memDBApi = memDBApi;
		this.memDBBuilder = memDBBuilder;
		this.pubSubManager = pubSubManager;
		this.redisson = redisson;
	}
	
//	public static class Connection {
//		private DFService service;
//		private RMemDBApi memDBApi;
//		
//		
//		private static volatile Connection instance;
//		private static Object mutex = new Object();
//
//		private Connection() {
//		}
//
//		public static Connection getInstance() {
//			Connection result = instance;
//			if (result == null) {
//				synchronized (mutex) {
//					result = instance;
//					if (result == null)
//						instance = result = new Connection();
//				}
//			}
//			return result;
//		}
//		
//	}
	
	public static class Builder {
		private BufferContext context;
		//private final BufferConfig config;
		private final String appName;
		private final String name;
		private final RedissonClient redisson;
		public Builder(BufferConfig config) {
			this.appName = config.getAppName();
			this.name = config.getName();
			this.redisson = config.getRedissonClient();
			//this.config = config;

		}
		
		public Builder(String appName, String name) {
			this.appName = appName;
			this.name = name;
			this.redisson = null;
		}
		
		public BufferContext build() {					
			try {
				if (name == null || name.isEmpty()) {
					throw new BufferConfigException("buffer name is null.");
				}
				DFService service = ServiceFactory.getService();
				RMemDBApi memDBApi = service.connect(appName);

				RMemDBBuilder memDBBuilder = memDBApi
						.getRMemDBBuilder(name);	
				
				context = new BufferContext(name, service, memDBApi, memDBBuilder, memDBApi.getPubSubManager(),redisson);									
			} catch (Throwable e) {
				throw new BufferConfigException(e.getMessage()+", name = "+name, e);
			}

			
			return context;
		}
		
	}
	
	public void initOperation() throws BufferException
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
	 * @throws BufferException 
	 */
	public boolean checkAvailable() throws BufferException {
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
	
	public List<String> getAllTableNames() throws BindingException {
		try {
			return bufferOperation.getTableNameArray();
		} catch (RedissonDBException e) {
					throw new BindingException("Fail to get table names .");
		}
				
					
	}
	
	public List<TableMeta> getTableMetas() throws BindingException {
		List<TableMeta> tables = new ArrayList<>();
		try {
			List<String> tableNames = bufferOperation.getTableNameArray();
			for (String tableName : tableNames) {
				TableMeta tableMeta = new TableMeta();
				tableMeta.setName(tableName);
				
				RTableOperation tableOps = bufferOperation.getTableOperation(tableName);
				if (tableOps == null) {
					throw new BindingException("Fail to get table operations : "+tableName);
				}				
				
				List<String> columnNames = tableOps.getColumnNameArray();

				int i = 0;
				for (String columnName : columnNames) {
					ColumnMeta columnMeta = new ColumnMeta();
					tableMeta.getColumns().add(columnMeta);
					
					RedisColumnContent colDefine = tableOps.getColumnDefine(columnName);
					colDefine.getIndexType();
					columnMeta.setIndexable(colDefine.getIndexType());
					columnMeta.setName(columnName);
					//columnMeta.setType(BufferFactoryBuilder.toType(colDefine.getType()));
					columnMeta.setDbIndex(tableOps.getColumnIndex(columnName));
					columnMeta.setIndex(i++);
				}
				tableMeta.formIndexColumn();				
			}
		} catch (RedissonDBException e) {
			throw new BindingException("Fail to get table names .");
		}
		
		return tables;		
	}
	
	public void updateTableMeta(TableMeta tableMeta) throws BindingException
	{
		try {			
			String tableName = tableMeta.getName();
			RTableOperation tableOps = bufferOperation.getTableOperation(tableName);
			if (tableOps == null) {
				throw new BindingException("Fail to get table operations : "+tableName);
			}

				
			List<String> columnNames = tableOps.getColumnNameArray();
//			for (ColumnMeta column : tableMeta.getColumns()) {
//				column.setIndex(-1);
//			}
			int i = 0;
			for (String columnName : columnNames) {
				ColumnMeta columnMeta = tableMeta.findColumn(columnName);
				if (columnMeta == null) {
					columnMeta = new ColumnMeta();
					tableMeta.getColumns().add(columnMeta);
				}
				RedisColumnContent colDefine = tableOps.getColumnDefine(columnName);
				columnMeta.setIndexable(colDefine.getIndexType());
				columnMeta.setName(columnName);
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
		List<ColumnMeta> columns = new ArrayList<>();
		columns.addAll(tableBuilder.getColumns());
		if (columnNames.size() != columns.size())
			return true;
		
		
			
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
	 * @throws BindingException 
	 */
	
	public boolean isBufferDefineChanged(BufferConfig config) throws BindingException {
		//List<TableMeta> changedTables = new ArrayList<>();
		List<String> tableNames;
		//try {
			try {
				tableNames = (bufferOperation != null) ? bufferOperation
						.getTableNameArray() : new ArrayList<>();
			} catch (RedissonDBException e) {
				throw new BindingException("Fail to getTableNameArray:", e);
			}
			TableMeta[] tableMetas = config.getCachedTableMetas();
			
			
			for (TableMeta tableMeta : tableMetas) {
				
				
				if (tableNames.indexOf(tableMeta.getName()) < 0) {
					//changedTables.add(tableMeta);
					//continue;
					return true;
				}
				
				List<RedisColumnContent> columnDefines = null;
				List<String> columnNames = null;
				RTableOperation ops = null;
				try {
					ops = bufferOperation.getTableOperation(tableMeta.getName());
				} catch (RedissonDBException e) {
					throw new BindingException("Fail to getTableOperation: table = "+tableMeta.getName(), e);
				}	
				
				try {
				   columnNames  = ops.getColumnNameArray();
				} catch (RedissonDBException e) {
					throw new BindingException("Fail to getColumnNameArray: table = "+tableMeta.getName(), e);
				}
				
				columnDefines = new ArrayList<>();
				for (String columnName : columnNames){
					try {
					  columnDefines.add(ops.getColumnDefine(columnName));
					} catch (RedissonDBException e) {
						throw new BindingException("Fail to getColumnDefine: table = "+tableMeta.getName()+", columnName = "+columnName, e);
					}	
				}
				
				if (isTableChanged(columnDefines, tableMeta)) {
					return true;				
				}
			}
			
	
//		} catch (RedissonDBException e) {
//			throw new BindingException(e.getMessage(), e);
//		}
			
		return false;
	}

	public String getName() {
		return name;
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

	public void makeBuffer(List<TableMeta> tableMetas) throws RedissonDBException, BufferException {
		
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
			throws RedissonDBException, BufferException {
		if (bufferBuilder.checkIsExists(tableDefine.getName()))
			return;	
		
		RTableBuilder tableBuilder = bufferBuilder.getTableBuilder(tableDefine
				.getName());
		
//		for (ColumnMeta c : tableDefine.getColumns()) {
//			tableBuilder.setColumn(c.getName(), typeMap.get(c.getType()), c.isIndexable());
//		}
		
	

		List<String> sb = new ArrayList<>();
		for (ColumnMeta c : tableDefine.getColumns()) {
			try {
			   sb.add(c.getName());
			   tableBuilder.setColumn(c.getName(), RedisTableColumnType.RedisTableColumnType_String, c.isIndexable());
			} catch (RedissonDBException e) {
				throw new BufferException("Fail to create colum : "+c.getName()+" for table :"+tableDefine.getName(), e);
			}
		}
		
		logger.info("Table created: {}, column size = {}, columns :{}.",
				tableDefine.getName(), tableDefine.getColumnSize(), String.join("|", sb));
	}

	public  class ChannelWrapper implements Channel
	{
		private final Channel delegate;
		public ChannelWrapper(Channel channel) {
			this.delegate  = channel;
		}

		@Override
		public void send(ChannelMessage message) {			
			sendMessage(delegate.getTopic(), message);
		}

		@Override
		public void register(Listener listener) {
			delegate.register(listener);
		}

		@Override
		public void receive(ChannelMessage e) {
			delegate.receive(e);
		}
		
		@Override
		public void close() {
			
//			MessageChannel channel = MessageChannel.OTHERCHANNEL;
//			synchronized (channel) {
//				  try {
//					channel.setStrChannel(getName());
//					new TimeCount.Builder()
//					.name("unsubscribe channel '%s'", getName())
//					.logger(logger).runnable(()->{
//							try {
//								pubSubManager.unSubscribeMessage(channel);
//							} catch (Exception e) {
//								throw new BufferException(e);
//							}
//						}
//					).build().exec();
//			
//				} catch (Exception e) {
//					throw new BufferException(e);
//				}
//				  				
//			}
			
			delegate.close();
		}
		

//		@Override
//		public void close() {
//			
//			MessageChannel channel = MessageChannel.OTHERCHANNEL;
//			synchronized (channel) {
//				  try {
//					channel.setStrChannel(getName());
//					new TimeCount.Builder()
//					.name("unsubscribe channel '%s'", getName())
//					.logger(logger).runnable(()->{
//							try {
//								pubSubManager.unSubscribeMessage(channel);
//							} catch (Exception e) {
//								throw new BufferException(e);
//							}
//						}
//					).build().exec();
//			
//				} catch (Exception e) {
//					throw new BufferException(e);
//				}
//				  				
//			}
//			
//			delegate.close();
//		}

		@Override
		public ChannelType getType() {
			return delegate.getType();
		}

		@Override
		public String getName() {
			return delegate.getName();
		}

		@Override
		public Topic getTopic() {
			// TODO Auto-generated method stub
			return delegate.getTopic();
		}
		
	}
	
	private Channel createChannelWrapper(String name, ChannelType type) {
		return new ChannelWrapper(new DefaultChannel(name, type));
	}
	
//	public Channel registChannel(ChannelConfig channelConfig) {		
//		MessageChannel channel = MessageChannel.OTHERCHANNEL;
//		synchronized (channel) {
//			try {
//				String name = channelConfig.getName();
//			    ChannelType type = channelConfig.getType();
//				channel.setStrChannel(name);
//				
//				final Channel bufferChannel = createChannelWrapper(name, type);
//				
//				if (type != ChannelType.SendOnly) {
//					pubSubManager.subscribeMessage(new MessageCallBack() {
//						
//						@Override
//						public void CallBack(int number, MessageContent messageContent) {
//							ChannelMessage event = new ChannelMessage(messageContent.getControlCode(), messageContent.getEventContent());
//							logger.debug("Receive message : number={}, content={}",number, event);
//							bufferChannel.receive(event);
//						}
//					}, channel, (type == ChannelType.Share ? true : false));
//					
//					logger.info("subscribe message : channel = {}, channelType= {}", channel, type);
//				}
//				return bufferChannel;
//			} catch (Exception e) {
//				throw new MessageException(e);
//			}
//		}
//	}
//	
//	public void sendMessage(String channelName, ChannelMessage message) {
//		MessageChannel channel = MessageChannel.OTHERCHANNEL;
//		synchronized (channel) {
//			try {
//				channel.setStrChannel(channelName);
//				pubSubManager.publishMessage(channel, message.getCode(), message.getContent());
//				logger.debug("Send message '{}', by channel : {} ", message, channelName);
//			} catch (Exception e) {
//				throw new MessageException(e);
//			}			
//		}
//
//	}
	
	
	public Channel registChannel(ChannelConfig channelConfig) throws MessageException {		
		MessageChannel channel = MessageChannel.OTHERCHANNEL;
		synchronized (channel) {
			try {
				String name = channelConfig.getName();
			    ChannelType type = channelConfig.getType();
				channel.setStrChannel(name);
				
				final Channel bufferChannel = createChannelWrapper(name, type);
				
				
						switch(type) {
						   case Share: {
							   
							   RBlockingQueue<ChannelMessage> queue = redisson.getBlockingQueue(name);
							   pool.execute(new Runnable() {
									
									@Override
									public void run() {
									   while(true) {
										   ChannelMessage message = null;
											try {
												message = queue.poll(10, TimeUnit.MINUTES);
											} catch (InterruptedException e) {
												e.printStackTrace();
												break;
											}
											
											if (message == null) {
												try {
													Thread.sleep(10);
												} catch (InterruptedException e) {
													// TODO Auto-generated catch block
													e.printStackTrace();
												}
												continue;
											}
										   
											 
										    logger.debug("Receive {} message : content={}", type, message);
										    final ChannelMessage msg = message;
											pool.execute(new Runnable() {
												
												@Override
												public void run() {
													bufferChannel.receive(msg);
												}
											});
											continue;
										   
									   }
									} 
								});
						   } break;
							case StandAlone: {
								RTopic<ChannelMessage> topic =  redisson.getTopic(name);
								topic.addListener(new MessageListener<ChannelMessage>() {
								    @Override
								    public void onMessage(String channel, ChannelMessage message) {
										logger.debug("Receive {} message : content={}", message);
										pool.execute(new Runnable() {
											
											@Override
											public void run() {
												bufferChannel.receive(message);
											}
										});
								    	
								    }
								});
							} break;
							default:
							break;
						
						
					}
	
				logger.info("subscribe message : channel = {}, channelType= {}", channel, type);				
				return bufferChannel;
			} catch (Exception e) {
				throw new MessageException(e);
			}
		}
	}
	
	public void sendMessage(Topic topic, ChannelMessage message) {

			switch (Topic.type(topic.getVerb())) {
			case Request:
			case Tansaction:
			{
				RBlockingQueue<ChannelMessage> queue = redisson.getBlockingQueue(topic.getName());
				queue.offer(message);
				
			}
			break;
			case Event:
			case Response:
			{
				RTopic<ChannelMessage> t = redisson.getTopic(topic.getName());
				t.publish(message);				
			}
			break;
			default:
				logger.error("Unknow topic verb type : {} ", topic.getVerb());
				return;
			}

			
			logger.debug("Send message '{}', by channel : {} ", message, topic.getName());


	}



}