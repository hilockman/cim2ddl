package com.znd.ei.memdb.dao;

import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class FieldInfo {
	public FieldInfo() {
		super();
		// TODO Auto-generated constructor stub
	}

	private Field field;
	private MemField memField;

	private ValueParse valueParser;

	public Field getField() {
		return field;
	}

	public void setField(Field field) {
		this.field = field;
	}

	public MemField getMemField() {
		return memField;
	}

	public void setMemField(MemField memField) {
		this.memField = memField;
	}

	public ValueParse getValueParser() {
		return valueParser;
	}

	public void setValueParser(ValueParse valueParser) {
		this.valueParser = valueParser;
	}
	
	public Object toObject(String value) {
		if (valueParser == null)
			return value;
		else
			return valueParser.toObject(value);
	}

}
