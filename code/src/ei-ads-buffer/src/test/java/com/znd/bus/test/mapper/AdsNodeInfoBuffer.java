package com.znd.bus.test.mapper;

import java.util.List;


import com.znd.bus.test.model.NodeInfo;

public interface AdsNodeInfoBuffer {

	NodeInfo findById(String id);
	
	int insert(NodeInfo user);
	
	void update(NodeInfo user);
	
	void delete(NodeInfo user);
	
	List<NodeInfo> findAll();
	
	void insertList(List<NodeInfo> users);
	
	void deleteById(String id);
	
	void deleteAll();

}
