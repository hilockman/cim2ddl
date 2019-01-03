package com.znd.ads.service.impl;

import java.util.ArrayList;
import java.util.List;

import javax.annotation.PostConstruct;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ads.exception.FactoryException;
import com.znd.ads.model.CategoryInfo;
import com.znd.ads.service.BufferService;
import com.znd.bus.common.buffer.CalcJobBuffer;
import com.znd.bus.common.model.CalcJob;
import com.znd.bus.common.model.CategoryTypeEnum;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.ColumnMeta;
import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.BufferException;
import com.znd.bus.exception.MessageException;
import com.znd.bus.mapping.RawArrayBufferMapper;

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
	
	

	@Autowired
	MyBufferFactoryRegistory factoryRegistory;
	
	

	
	@PostConstruct
	public void init() {
//		bufferFactoryMap.put(bufferConfig.getName(), new MyBufferFactory(bufferConfig.getName()));
		try {
			factoryRegistory.put(bufferConfig.getName(), new MyBufferFactory(bufferConfig.getName()));
		} catch (BindingException | BufferException | MessageException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
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

	

	

	@Override
	public List<CategoryInfo> getTableNodes(String dbid, CategoryTypeEnum type) throws FactoryException {
		MyBufferFactory f = factoryRegistory.getFactory(dbid);
		
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
	public List<String[]> getRecords(String dbid, String tableid) throws FactoryException {
		MyBufferFactory f = factoryRegistory.getFactory(dbid);
		return f.getRecords(tableid);	
	}

	@Override
	public List<ColumnMeta> getTableColumns(String dbid, String tableid) throws FactoryException {
		MyBufferFactory f = factoryRegistory.getFactory(dbid);	
		return f.getTableColumns(tableid);
	}

	@Override
	public void removeRecords(String dbid, String tableid, String[] ids) throws FactoryException {
		MyBufferFactory f = factoryRegistory.getFactory(dbid);
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
