package com.znd.ads.service.impl;

import java.io.Closeable;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import javax.annotation.PostConstruct;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ads.model.CategoryInfo;
import com.znd.ads.service.BufferService;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.buffer.BufferFactoryBuilder;
import com.znd.bus.common.buffer.CalcJobBuffer;
import com.znd.bus.common.model.CalcJob;
import com.znd.bus.common.model.CategoryTypeEnum;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.ColumnMeta;
import com.znd.bus.config.CreateFlag;
import com.znd.bus.config.TableMeta;
import com.znd.bus.mapping.RawArrayBufferMapper;
import com.znd.bus.task.CalcTaskList;

/**
 * 公共数据读取服务
 * @author wangheng
 * @date 2018年11月7日
 * @time 上午10:10:04
 * @type_name BufferServiceImpl
 */
@Service
public class BufferServiceImpl implements BufferService {

	@Autowired
	private BufferConfig bufferConfig;
				
//	@Autowired
//	private LogBuffer logBuffer;
	
//	@Autowired
//	private Buffer defaultBuffer;
	
	@Autowired
	private CalcJobBuffer jobBuffer;
	
//	@Autowired
//	private Channel commonChannel;
	
	
	public class MyBufferFactory implements BufferFactory , Closeable {

		private BufferFactory factory;
		private BufferConfig config;
		private Buffer buffer;
		
		public MyBufferFactory(String dbid) {
			factory = getBufferFactory(dbid);
		    config = factory.config();
		    buffer = factory.openSession();
		}
		
		
		public RawArrayBufferMapper getMapper(Class<RawArrayBufferMapper> type,
				String tableName) {
		
			return config.getMapper(type, tableName, buffer);
		}
		
		public List<TableMeta> getAllTableMetas() {
			return config.getAllTableMetas();
		}
		
		public TableMeta getTableMeta(String tableName) {
			return config.getTableMeta(tableName);
		}
		
		public List<String> getAllTableNames()
		{
			return config.getAllTableNames();
		}
		
		@Override
		public Buffer openSession() {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public Buffer openSession(boolean autoCommit) {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public BufferConfig config() {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public void destory() {
			// TODO Auto-generated method stub
			
		}

		@Override
		public <E> CalcTaskList<E> taskList(String taskName) {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public void close() throws IOException {
			if (buffer != null)
				buffer.close();
		}
		
	}
	
	
	private final  Map<String, MyBufferFactory> bufferFactoryMap = new ConcurrentHashMap<>();
	
	@PostConstruct
	public void init() {
		bufferFactoryMap.put(bufferConfig.getName(), new MyBufferFactory(bufferConfig.getName()));
	}
	
	private MyBufferFactory getFactory(String dbid) {
		if (bufferFactoryMap.containsKey(dbid)) {
			return bufferFactoryMap.get(dbid);
		}
		
		MyBufferFactory factory = new MyBufferFactory(dbid);
		bufferFactoryMap.put(dbid, new MyBufferFactory(dbid));
		return factory;
	}
	
	
	@Override
	public List<CategoryInfo> getDbNodes() {
		List<CategoryInfo> items = new ArrayList<>();
		CategoryInfo rootItem = new CategoryInfo();
		rootItem.setId(bufferConfig.getName());
		rootItem.setName(bufferConfig.getName());
		rootItem.setAlias(bufferConfig.getName());
		rootItem.setType(CategoryTypeEnum.common);
		items.add(rootItem);
		
		
		List<CalcJob> jobs = jobBuffer.findAll();
		for (CalcJob job : jobs) {
			if (!BufferConfig.exist(job.getId())) {
				continue;
			}
			
			rootItem = new CategoryInfo();
			rootItem.setId(job.getId());
			rootItem.setName(job.getName());
			rootItem.setType(CategoryTypeEnum.job);
			items.add(rootItem);
		}
		return items;
	}

	
	private BufferFactory getBufferFactory(String dbid) {
		BufferConfig config = new BufferConfig();
		BufferFactoryBuilder builder  = new BufferFactoryBuilder();
		config.setSimpleModel(true);
		return builder.build(dbid, CreateFlag.FALSE, null, null, config);
	}
	

	@Override
	public List<CategoryInfo> getTableNodes(String dbid, CategoryTypeEnum type) {
		MyBufferFactory f = getFactory(dbid);
		
		List<String> tables =  f.getAllTableNames();
		List<CategoryInfo> nodes = new ArrayList<>();
		for (String table : tables) {
			CategoryInfo node = new CategoryInfo();
			node.setId(table);
			node.setName(table);
			node.setAlias(table);
			
			nodes.add(node);		
		}
		return nodes;
	}

//	@Override
//	public void sendMessage(ChannelMessage message) {
//		commonChannel.send(message);
//	}

//	@Override
//	public List getLogs() {
//		return logBuffer.findAll();
//	}

	@Override
	public List<String[]> getRecords(String dbid, String tableid) {
		MyBufferFactory f = getFactory(dbid);
		
		RawArrayBufferMapper m = f.getMapper(RawArrayBufferMapper.class, tableid);
		return m.getAll();
		
	}

	@Override
	public List<ColumnMeta> getTableColumns(String dbid, String tableid) {
		MyBufferFactory f = getFactory(dbid);	
		TableMeta table = f.getTableMeta(tableid);
		if (table != null)
			return table.getColumns();
		
		return null;

	}

	@Override
	public void removeRecords(String dbid, String tableid, String[] ids) {
		MyBufferFactory f = getFactory(dbid);
		RawArrayBufferMapper m = f.getMapper(RawArrayBufferMapper.class, tableid);
		if (ids.length == 0)
			m.removeAll();
		else {
			for (String id : ids) {
				m.remove(id);
			}			
		}

	}

}
