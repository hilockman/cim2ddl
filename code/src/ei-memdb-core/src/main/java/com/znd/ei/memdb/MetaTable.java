package com.znd.ei.memdb;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MetaTable {
	private String name;
	private String description;
	private List<MetaField> fields;
	private Map<String, MetaField> fieldMap;
	private List<MetaField> keyFields;
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


	public void addField(MetaField field) {
		if (fields == null) {
			fields = new ArrayList<MetaField>();
			fieldMap = new HashMap<String, MetaField>();
		}
		
		fields.add(field);
		fieldMap.put(field.getName().toUpperCase(), field);
	}
	public List<MetaField> getFields() {
		return fields;
	}
	public void setFields(List<MetaField> fields) {
		this.fields = fields;
	}
	
	public MetaField findFieldByName(String name) {
		return fieldMap.get(name.toUpperCase());
	}
	public List<MetaField> getKeyFields() {
		return keyFields;
	}
	public void setKeyFields(List<MetaField> keyFields) {
		this.keyFields = keyFields;
	}
	
	public MetaField getFiled(int index) {
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
	@Override
	public String toString() {
		return "MetaTable [name=" + name + ", description=" + description + "]";
	}
}
