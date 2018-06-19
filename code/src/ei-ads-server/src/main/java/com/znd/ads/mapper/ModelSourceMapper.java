package com.znd.ads.mapper;

import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Result;
import org.apache.ibatis.annotations.ResultMap;
import org.apache.ibatis.annotations.Results;
import org.apache.ibatis.annotations.Select;

import com.znd.ads.model.po.ModelSource;

@Mapper
public interface ModelSourceMapper {
	@Insert("insert into model_source (id, name, typeName, lastUpdate, description) values(#{id}, #{name}, #{type}, #{lastUpdate}, #{desc})")
	int insert(ModelSource o);
	
	@Delete("delete from model_source where name = #{name}")
	void removeByName(String name);
	

	
	@Delete("delete from model_source where id = #{id}")
	void removeById(String id);
	
	@Results(id = "modelSourceResult", value = {
			  @Result(property = "id", column = "id", id = true),
			  @Result(property = "name", column = "name"),
			  @Result(property = "type", column = "typeName"),
			  @Result(property = "lastUpdate", column = "lastUpdate"),
			  @Result(property = "desc", column = "description")
			})
	@Select("select * from model_source where name = #{name}")
	ModelSource findByName(String name);
	
	@ResultMap("modelSourceResult")
	@Select("select * from model_source where id = #{id}")
	ModelSource findById(String id);	
	
}
