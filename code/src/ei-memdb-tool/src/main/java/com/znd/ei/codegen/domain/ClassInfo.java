package com.znd.ei.codegen.domain;

import java.util.List;

public class ClassInfo {
	private String packageName;
	private String className;

	private List<String> importPackageNames;
	
	/**
	 * 注释
	 */
	private List<String> notes;

	/**
	 * 注释
	 */
	private List<String> annotations;

	public String getPackageName() {
		return packageName;
	}

	public void setPackageName(String packageName) {
		this.packageName = packageName;
	}

	public String getClassName() {
		return className;
	}

	public void setClassName(String className) {
		this.className = className;
	}

	public List<String> getImportPackageNames() {
		return importPackageNames;
	}

	public void setImportPackageNames(List<String> importPackageNames) {
		this.importPackageNames = importPackageNames;
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
