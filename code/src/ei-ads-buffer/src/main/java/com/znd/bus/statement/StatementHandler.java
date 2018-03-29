package com.znd.bus.statement;


/**
 * 实现对象到字符串数组的转换
 * 输入参数条件转换成Map
 * @author wangheng
 * @date 2018年3月16日
 * @time 上午10:53:21
 * @type_name ParamerterHandler
 */
public interface StatementHandler {

	

	

//	/**
//	 * 值数组转换成对象
//	 * @param values
//	 * @return
//	 */
//	Object toObject(String[] values);
//	
//	
//	/**
//	 * 对象转换成字符数组
//	 * @param o
//	 * @return
//	 */
//	String[] toArrayValues(Object o);
//	
//	/**
//	 * 输入参数转换成Map
//	 * @param args
//	 * @return
//	 */
//	Map<String, String> toArgsMap(Object[] args);

	Statement newStatement();

	void parepared(Statement ps);

//	public default void parepared(Statement ps) {
//		throw new StatementException("no prepare function!");
//	}

	
}
