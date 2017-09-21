package com.znd.ei.memdb.dao;
@FunctionalInterface
public interface ValueParse<T> {

	T toObject(String value);
	
	public static ValueParse Integer_Parser = value -> Integer.valueOf(value);
	
	public static ValueParse Short_Parser =  value -> Short.valueOf(value);
	
	public static ValueParse Float_Parse = value -> Float.valueOf(value);
	
	public static ValueParse Double_Parse = value -> Double.valueOf(value);
}
