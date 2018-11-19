package com.znd.memory;

/**
 * 数据库状态
 * @author wangheng
 * @date 2018年6月8日
 * @time 下午4:42:05
 * @type_name ShareMemState
 */
public enum ShareMemState {
	/**
	 * 未初始化
	 */
	Uninitialized,
	/**
	 * 已加载
	 */
	Loaded, 
	/**
	 * 正在加载
	 */
	Loading
}
