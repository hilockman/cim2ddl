package com.znd.ei.ads.bus.type;

import java.text.DateFormat;
import java.text.ParseException;
import java.util.Date;

import com.znd.ei.ads.bus.mapping.ResultSet;
import com.znd.ei.ads.bus.statement.Statement;

public class DateTypeHandler implements TypeHandler<Date> {

	public static final DateFormat FORMAT = DateFormat.getDateInstance();
	
	@Override
	public void setParameter(Statement ps, int i, Date parameter) {
		ps.set(i, parameter == null ? null : FORMAT.format(parameter));
	}

	@Override
	public void setParameter(Statement ps, String key, Date parameter) {
		ps.set(key, parameter == null ? null : FORMAT.format(parameter));
	}

	@Override
	public Date getResult(ResultSet rs, String columnName) {
		String rt = rs.get(columnName);
		try {
			return rt == null ? null : FORMAT.parse(rt);
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			
			throw new TypHandleException("Fail to parse date : "+rt, e);
		}
	}

	@Override
	public Date getResult(ResultSet rs, int columnIndex) {
		String rt = rs.get(columnIndex);
		try {
			return rt == null ? null : FORMAT.parse(rt);
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			
			throw new TypHandleException("Fail to parse date : "+rt, e);
		}
	}

}
