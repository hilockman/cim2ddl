package com.znd.bus.type;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.StatementException;
import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;

public class DateTypeHandler implements TypeHandler<Date> {

	public static final DateFormat FORMAT = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");
	private String format(Date date) {
		return date == null ? null : String.valueOf(date.getTime());
	}
	
	private Date parse(String value) {
		try {
			return (value == null  || value.trim().isEmpty()  || value.equalsIgnoreCase("null")) ? null : new Date(Long.valueOf(value));
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			
			//throw new TypHandleException("Fail to parse date : "+value, e);
			return null; 
		}
	}
	@Override
	public void setParameter(Statement ps, int i, Date parameter) throws StatementException {
		ps.set(i, format(parameter));
	}

	@Override
	public void setParameter(Statement ps, String key, Date parameter) throws StatementException {
		ps.set(key, format(parameter));
	}

	@Override
	public Date getResult(ResultSet rs, String columnName) throws BindingException {
		String rt = rs.get(columnName);
		return parse(rt);
	}

	@Override
	public Date getResult(ResultSet rs, int columnIndex) throws BindingException {
		String rt = rs.get(columnIndex);
		return parse(rt);
	}

}
