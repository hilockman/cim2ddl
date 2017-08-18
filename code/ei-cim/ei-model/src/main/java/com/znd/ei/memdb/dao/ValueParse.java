package com.znd.ei.memdb.dao;

public interface ValueParse {

	Object toObject(String value);
	
	public static ValueParse Integer_Parser = new ValueParse() {
		
		@Override
		public Object toObject(String value) {
			// TODO Auto-generated method stub
			return Integer.valueOf(value);
		}
	};
	
	public static ValueParse Short_Parser = new ValueParse() {
		
		@Override
		public Object toObject(String value) {
			// TODO Auto-generated method stub
			return Short.valueOf(value);
		}
	};
	
	public static ValueParse Float_Parse = new ValueParse() {
		
		@Override
		public Object toObject(String value) {
			// TODO Auto-generated method stub
			return Float.valueOf(value);
		}
	};
	
	public static ValueParse Double_Parse = new ValueParse() {
		
		@Override
		public Object toObject(String value) {
			// TODO Auto-generated method stub
			return Double.valueOf(value);
		}
	};
}
