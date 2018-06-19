package com.znd.ads.property;



/**
 * 外键加载器
 * @author wangheng
 * @date 2018年6月1日
 * @time 下午2:02:15
 * @type_name ForeignKeysLoader
 */
public interface ForeignKeysLoader {

	/**
	 * "id:name;id:name"
	 * @return
	 */
	String values();
}
