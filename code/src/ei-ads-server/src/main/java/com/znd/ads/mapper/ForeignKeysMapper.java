package com.znd.ads.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.ResultType;
import org.apache.ibatis.annotations.Select;

import com.znd.ads.model.dto.ForeignKeyValue;


/**
 * 字典信息描述
 * @author wangheng
 * @date 2018年6月4日
 * @time 下午5:21:43
 * @type_name DictValuesMapper
 */
@Mapper
public interface ForeignKeysMapper {
	
	@Select("select ${keyColumn} as 'key', ${valueColumn} as value from ${tableName}")
	@ResultType(ForeignKeyValue.class)
	List<ForeignKeyValue> getValues(@Param("tableName") String tableName, @Param("keyColumn") String keyColumn, @Param("valueColumn") String valueColumn);
}
