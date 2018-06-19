package com.znd.ads.property;

/**
 * 属性描述
 * @author wangheng
 * @date 2018年6月14日
 * @time 下午2:21:46
 * @type_name PropertyName
 */
public class PropertyName {
	private String name;
	private String group;
	private String desc;
	private PropertyTypeEnum type;
	private Boolean readonly;
	private String optionValues;
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
	public String getOptionValues() {
		return optionValues;
	}
	public void setOptionValues(String optionValues) {
		this.optionValues = optionValues;
	}
}
