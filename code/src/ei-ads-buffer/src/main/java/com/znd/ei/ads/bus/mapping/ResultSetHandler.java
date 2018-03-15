package com.znd.ei.ads.bus.mapping;

import java.util.List;

public interface ResultSetHandler<T> {
	 List<T> handle(ResultSet resultSet);
	
	
	public final static ResultSetHandler<String[]> DEFAULT_HANDLER = new ResultSetHandler<String[]>() {

		@Override
		public List<String[]> handle(ResultSet resultSet) {
			return resultSet.getResults();
		}
	};
}
