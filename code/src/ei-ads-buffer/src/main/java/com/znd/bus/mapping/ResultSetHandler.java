package com.znd.bus.mapping;

import java.util.List;

import com.znd.bus.exception.BindingException;

public interface ResultSetHandler<T> {
	 List<T> handle(ResultSet resultSet) throws BindingException;
	
	
	public final static ResultSetHandler<String[]> DEFAULT_HANDLER = new ResultSetHandler<String[]>() {

		@Override
		public List<String[]> handle(ResultSet resultSet) {
			//System.out.println(">>>>>>>>>>>>>>>>>>DEFAULT_HANDLER.handle");
			return resultSet.getResults();
		}
	};
}
