package com.znd.ads.property;

public class PropertyValue {

	private String id;
	private String pid;
	private String name;
	private PropertyTypeEnum type;
	private Object value;
	private Boolean readonly;
	private String optionValues;

	
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getPid() {
		return pid;
	}
	public void setPid(String pid) {
		this.pid = pid;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Object getValue() {
		return value;
	}
	public void setValue(Object value) {
		this.value = value;
	}
	public PropertyTypeEnum getType() {
		return type;
	}
	public void setType(PropertyTypeEnum type) {
		this.type = type;
	}
	public Boolean getReadonly() {
		return readonly;
	}
	public void setReadonly(Boolean readonly) {
		this.readonly = readonly;
	}
	public String getOptionValues() {
		return optionValues;
	}
	public void setOptionValues(String optionValues) {
		this.optionValues = optionValues;
	}
	
}
