package com.znd.ei.codegen.domain;

import java.util.ArrayList;
import java.util.List;

public class FieldInfo {
	/**
	 * 名称
	 */
	private String name;
	
	/**
	 * 标准名称(首字母小写的名称)
	 */
	private String standardName;
	
	/**
	 * 类型名称(String, Integer, 
	 */
	private String typeName;
	
	/**
	 * 注释
	 */
	private List<String> notes;
	
	/**
	 * 注释
	 */
	private List<String> annotations;

	
	public FieldInfo() {
		notes = new ArrayList<String>();
		annotations = new ArrayList<String>();
	}
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getStandardName() {
		return standardName;
	}

	public void setStandardName(String standardName) {
		this.standardName = standardName;
	}

	public String getTypeName() {
		return typeName;
	}

	public void setTypeName(String typeName) {
		this.typeName = typeName;
	}

	public List<String> getNotes() {
		return notes;
	}

	public void setNotes(List<String> notes) {
		this.notes = notes;
	}

	public List<String> getAnnotations() {
		return annotations;
	}

	public void setAnnotations(List<String> annotations) {
		this.annotations = annotations;
	}
}
