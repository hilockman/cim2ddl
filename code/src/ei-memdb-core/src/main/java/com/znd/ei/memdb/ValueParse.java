package com.znd.ei.memdb;

@FunctionalInterface
public interface ValueParse<T> {

	T toObject(String value);

	@SuppressWarnings("rawtypes")
	public static ValueParse Integer_Parser = new ValueParse<Integer>() {

		@Override
		public Integer toObject(String value) {
			if (value.isEmpty())
				return 0;
			return Integer.valueOf(value);
		}
	};

	public static ValueParse Short_Parser = new ValueParse<Short>() {

		@Override
		public Short toObject(String value) {
			if (value.isEmpty())
				return 0;
			return Short.valueOf(value);
		}

	};

	public static ValueParse Float_Parse = new ValueParse<Float>() {

		@Override
		public Float toObject(String value) {
			if (value.isEmpty())
				return 0.0f;
			return Float.valueOf(value);
		}

	};


	public static ValueParse Double_Parse = new ValueParse<Double>() {

		@Override
		public Double toObject(String value) {
			if (value.isEmpty())
				return 0.0d;
			
			return Double.valueOf(value);
		}

	};
	
	public static void main(String [] args) {
		//System.out.println(Double.valueOf("0"));
	}
	
}
