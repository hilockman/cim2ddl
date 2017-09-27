package com.znd.ei.memdb;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MemTable {
	private String name;
	private String description;
	private List<MemField> fields;
	private Map<String, MemField> fieldMap;
	private List<MemField> keyFields;
	private int index;
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getDescription() {
		return description;
	}
	public void setDescription(String description) {
		this.description = description;
	}


	public void addField(MemField field) {
		if (fields == null) {
			fields = new ArrayList<MemField>();
			fieldMap = new HashMap<String, MemField>();
		}
		
		fields.add(field);
		fieldMap.put(field.getName().toUpperCase(), field);
	}
	public List<MemField> getFields() {
		return fields;
	}
	public void setFields(List<MemField> fields) {
		this.fields = fields;
	}
	
	public MemField findFieldByName(String name) {
		return fieldMap.get(name.toUpperCase());
	}
	public List<MemField> getKeyFields() {
		return keyFields;
	}
	public void setKeyFields(List<MemField> keyFields) {
		this.keyFields = keyFields;
	}
	
	public MemField getFiled(int index) {
		if (fields == null || fields.size() <= index || index < 0)
			return null;
		
		return fields.get(index);
	}
	public int getIndex() {
		return index;
	}
	public void setIndex(int index) {
		this.index = index;
	}
}
