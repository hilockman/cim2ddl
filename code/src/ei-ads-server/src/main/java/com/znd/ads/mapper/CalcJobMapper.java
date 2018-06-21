package com.znd.ads.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Result;
import org.apache.ibatis.annotations.ResultMap;
import org.apache.ibatis.annotations.Results;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import com.znd.bus.common.model.CalcJob;

@Mapper

public interface CalcJobMapper {

	@Results(id = "calcJobResult", value = {
			  @Result(property = "id", column = "id", id = true),
			  @Result(property = "name", column = "name"),
			  @Result(property = "desc", column = "description"),
			  @Result(property = "modelId", column = "modelId"),
			  @Result(property = "typeId", column = "typeId"),
			  @Result(property = "start", column = "start"),
			  @Result(property = "end", column = "end"),
			  @Result(property = "state", column = "state")
			})
	@Select("select * from calc_job where id = #{id}")
	CalcJob findById(String id);
	
	@Insert("insert into calc_job (id, name, description, modelId, typeId, start, parameter) values(#{id}, #{name}, #{desc}, #{modelId}, #{typeId},#{start}, #{parameter})")
	int insert(CalcJob o);
	
	@Update("update calc_job set name=#{name}, description=#{desc}, modelId=#{modelId}, typeId=#{typeId}, start=#{start} where id = #{id}")
	void update(CalcJob o);
	
	@Delete("delete from calc_job where id=#{id}")
	void delete(CalcJob o);
	
	@Select("select * from calc_job")
	@ResultMap("calcJobResult")
	List<CalcJob> findAll();

	@Insert("insert into calc_job (id, name, description, modelId, typeId, start) values(#{id}, #{name}, #{desc}, #{modelId}, #{typeId},#{start})")
	void insertList(List<CalcJob> objects);
	
	@Delete("delete from calc_job where id=#{id}")
	void deleteById(String id);
	
	@Delete("delete from calc_job")
	void deleteAll();
}
