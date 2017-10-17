package com.znd.ei.memdb;

public class Connection {

	private String name;
	private String desc;

	// private String targetPackage;

	public Connection(String name, String desc) {
		this.name = name;
		this.desc = desc;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getDesc() {
		return desc;
	}

	public void setDesc(String desc) {
		this.desc = desc;
	}

	// public String getTargetPackage() {
	// return targetPackage;
	// }
	//
	// public void setTargetPackage(String targetPackage) {
	// this.targetPackage = targetPackage;
	// }
}
