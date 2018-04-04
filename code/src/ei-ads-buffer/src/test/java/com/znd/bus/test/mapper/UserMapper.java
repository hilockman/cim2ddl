package com.znd.bus.test.mapper;

import java.util.List;

import com.znd.bus.test.model.User;

public interface UserMapper {

	
//	User findUserByName(String name);
//	
	User findUserById(String id);
	
	int insertUser(User user);
	
	void updateUser(User user);
	
	void deleteUser(User user);
	
	List<User> findAll();
	
	void insertUsers(List<User> users);
}
