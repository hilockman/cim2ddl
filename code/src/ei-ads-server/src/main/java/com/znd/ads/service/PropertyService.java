package com.znd.ads.service;

import java.util.List;

import com.znd.ads.property.PropertyName;

/**
 * 配置信息服务
 * @author wangheng
 * @date 2018年6月1日
 * @time 上午9:43:28
 * @type_name PropertyService
 */
public interface PropertyService {
	/**
	 * 通过属性名称获取缺省配置
	 * @param type
	 * @return
	 */
	List getDefault(String type);

	/**
	 * 通过属性类型名获得属性名称列表
	 * @param type
	 * @return
	 */
	List getNames(String type);
	
	
	/**
	 * 按名称查找属性名
	 * @param type
	 * @param name
	 * @return
	 */
	PropertyName findName(String type, String name);
//
//	/**
//	 * 通过属性类信息，和属性名称获得外键
//	 * @param type
//	 * @param property
//	 * @return
//	 */
//	List getForeignKeys(String type, String property);
}
