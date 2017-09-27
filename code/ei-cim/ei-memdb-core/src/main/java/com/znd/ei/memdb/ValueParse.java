package com.znd.ei.memdb;
@FunctionalInterface
public interface ValueParse<T> {

	T toObject(String value);
	
	@SuppressWarnings("rawtypes")
	public static ValueParse Integer_Parser = value -> Integer.valueOf(value);
	
	public static ValueParse Short_Parser =  value -> Short.valueOf(value);
	
	public static ValueParse Float_Parse = value -> Float.valueOf(value);
	
	public static ValueParse Double_Parse = value -> Double.valueOf(value);
}
