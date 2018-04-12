package com.znd.bus.test.mapper;

import java.util.List;

import com.znd.bus.test.model.UserInfo;

public interface UserInfoMapper {
	UserInfo findById(String id);
	
	int insert(UserInfo user);
	
	void update(UserInfo user);
	
	void delete(UserInfo user);
	
	List<UserInfo> findAll();
	
	void insertList(List<UserInfo> users);
	
	void deleteById(String id);
	
	void deleteAll();
}
