package com.znd.ads.service.impl;

import java.io.Closeable;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.buffer.BufferFactoryBuilder;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.ColumnMeta;
import com.znd.bus.config.CreateFlag;
import com.znd.bus.config.TableMeta;
import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.BufferException;
import com.znd.bus.exception.MessageException;
import com.znd.bus.mapping.RawArrayBufferMapper;
import com.znd.bus.task.CalcTaskList;

public class MyBufferFactory implements BufferFactory , Closeable {

	private BufferFactory factory;
	private BufferConfig config;
	private Buffer buffer;
	
	public MyBufferFactory(String dbid) throws BindingException, BufferException, MessageException {
		factory = getBufferFactory(dbid);
	    config = factory.config();
	    buffer = factory.openSession();
	}
	
	private BufferFactory getBufferFactory(String dbid) throws BindingException, BufferException, MessageException {
		BufferConfig config = new BufferConfig();
		BufferFactoryBuilder builder  = new BufferFactoryBuilder();
		config.setSimpleModel(true);
		return builder.build(dbid, CreateFlag.FALSE, null, null, config);
	}
	
	
	public List<String[]> getRecords(String tableid) {
		RawArrayBufferMapper m = getMapper(RawArrayBufferMapper.class, tableid);
		return m.getAll();
		
	}
//	public List<String> getRecordMaps(String tableid) {
//		RawArrayBufferMapper m = getMapper(RawArrayBufferMapper.class, tableid);
//		List<String[]> records = m.getAll();
//		
//		
//		List<ColumnMeta> columns = getTableColumns(tableid);
//		List<String> list = new ArrayList<>();
//		
//		for (String[] record : records) {
//			Map<String, String> map = new HashMap<>();
//			for (int i = 0; i < record.length && i < columns.size(); i++) {
//				map.put(columns.get(i).getName(), record[i]);
//			}
//			
//			;
//			list.add(Utils.toJson(map));
//		}
//		
//		
//		return list;
//	}
	public List<Map<String, String>> getRecordMaps(String tableid) {
		RawArrayBufferMapper m = getMapper(RawArrayBufferMapper.class, tableid);
		List<String[]> records = m.getAll();
		
		
		List<ColumnMeta> columns;
		columns = getTableColumns(tableid);
		List<Map<String, String>> list = new ArrayList<>();
		
		for (String[] record : records) {
			Map<String, String> map = new HashMap<>();
			for (int i = 0; i < record.length && i < columns.size(); i++) {
				map.put(columns.get(i).getName(), record[i]);
			}
			
			list.add(map);
		}
		
		
		return list;
	}
	
	public List<ColumnMeta> getTableColumns(String tableid) {
		TableMeta table;
		try {
			table = getTableMeta(tableid);
		} catch (BindingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}
		if (table != null)
			return table.getColumns();
		
		return null;
	}
	
	
	public RawArrayBufferMapper getMapper(Class<RawArrayBufferMapper> type,
			String tableName) {
	
		try {
			return config.getMapper(type, tableName, buffer);
		} catch (BindingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}
	}
	
	public List<TableMeta> getAllTableMetas() throws BindingException {
		return config.getAllTableMetas();
	}
	
	public TableMeta getTableMeta(String tableName) throws BindingException {
		return config.getTableMeta(tableName);
	}
	
	public List<String> getAllTableNames()
	{
		try {
			return config.getAllTableNames();
		} catch (BindingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}
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