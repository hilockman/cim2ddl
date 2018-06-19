package com.znd.ads.property;

import java.lang.reflect.Method;

/**
 * 类的属性列
 * @author wangheng
 * @date 2018年6月8日
 * @time 上午11:25:19
 * @type_name PropertyItem
 */
public class PropertyItem {

	private String name;
	private String group;
	private String desc;
	private PropertyTypeEnum type;
	private Object defaultValue;
	private Boolean readonly;
	
	private Method setInvoker;
	private Method getInvoker;
	
	private String optionValues;
	
	private ForeignKeysLoader loader;
	
	public PropertyItem(String name, PropertyTypeEnum type) {
		this.name = name;
		this.type = type;
	}
	
	public PropertyItem() {
		
	}
	
	public static PropertyItem NULL_GROUP = new PropertyItem("", PropertyTypeEnum.p_group);
		
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getGroup() {
		return group;
	}
	public void setGroup(String group) {
		this.group = group;
	}
	public String getDesc() {
		return desc;
	}
	public void setDesc(String desc) {
		this.desc = desc;
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
	

	public Method getSetInvoker() {
		return setInvoker;
	}
	public void setSetInvoker(Method setInvoker) {
		this.setInvoker = setInvoker;
	}
	public Method getGetInvoker() {
		return getInvoker;
	}
	public void setGetInvoker(Method getInvoker) {
		this.getInvoker = getInvoker;
	}
	public Object getDefaultValue() {
		return defaultValue;
	}
	public void setDefaultValue(String defaultValue) {
		this.defaultValue = defaultValue;
	}
	public String getOptionValues() {
		return optionValues;
	}
	public void setOptionValues(String optionValues) {
		this.optionValues = optionValues;
	}
	
	@Override
	public String toString() {
		return "PropertyItem [id=" + name + ", group=" + group + ", name=" + desc
				+ ", type=" + type + ", defaultValue=" + defaultValue
				+ ", readonly=" + readonly  + ", optionValues="
				+ optionValues + "]";
	}

	public ForeignKeysLoader getLoader() {
		return loader;
	}

	public void setLoader(ForeignKeysLoader loader) {
		this.loader = loader;
	}
}
