package com.znd.bus.mapping;

import java.util.List;

import com.znd.bus.annotation.Param;
import com.znd.bus.annotation.Select;

public interface RawArrayBufferMapper {

	List<String[]> getAll();
	
	String[] findById(String id);
	
	
	void remove(String id);
	
	void removeAll();
	
	void upate(String[] record);

	void update(List<String[]> records);
	
	@Select("Select ${columnName} from ${tableName}")
	List<String> getColumnValues(@Param("columnName")String columnName, @Param("tableName")String tableName);
	
}
