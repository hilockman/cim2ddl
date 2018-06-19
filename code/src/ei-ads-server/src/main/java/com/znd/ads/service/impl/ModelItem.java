package com.znd.ads.service.impl;

import java.util.Date;

public class ModelItem {

	private String id;
	private String name;
//	private String title;
//	private String key;
	private String desc;
	private Boolean folder;
	private Date lastUpdate;
	private Long space = new Long(0);
	//private List<ModelItem> children = new ArrayList<>();
	
	private String parentId;

	public Boolean getFolder() {
		return folder;
	}
	public void setFolder(Boolean folder) {
		this.folder = folder;
	}

	public Date getLastUpdate() {
		return lastUpdate;
	}
	public void setLastUpdate(Date lastUpdate) {
		this.lastUpdate = lastUpdate;
	}

	public String getDesc() {
		return desc;
	}
	public void setDesc(String desc) {
		this.desc = desc;
	}
	public Long getSpace() {
		return space;
	}
	public void setSpace(Long space) {
		this.space = space;
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getParentId() {
		return parentId;
	}
	public void setParentId(String parentId) {
		this.parentId = parentId;
	}
	@Override
	public String toString() {
		return "ModelItem [id=" + id + ", name=" + name + ", desc=" + desc
				+ ", folder=" + folder + ", lastUpdate=" + lastUpdate
				+ ", space=" + space + ", parentId=" + parentId + "]";
	}

}
