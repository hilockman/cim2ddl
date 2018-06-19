package com.znd.ads.model;

import java.util.ArrayList;
import java.util.List;

public class CategoryInfo {

	public static final String MEMORY = "memory";
	public static final String BUFFER = "buffer";
	private String id;
	private String name;
	private String alias;
	private String type;
	
	private List<CategoryInfo> children = new ArrayList<>();
	private int childCount = 0;
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getAlias() {
		return alias;
	}
	public void setAlias(String alias) {
		this.alias = alias;
	}
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public List<CategoryInfo> getChildren() {
		return children;
	}
	public void setChildren(List<CategoryInfo> children) {
		this.children = children;
	}
	public int getChildCount() {
		return childCount;
	}
	public void setChildCount(int childCount) {
		this.childCount = childCount;
	}
}
