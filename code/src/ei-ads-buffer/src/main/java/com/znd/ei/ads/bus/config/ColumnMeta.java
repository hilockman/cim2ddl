package com.znd.ei.ads.bus.config;
/**
 * 
 * @author wangheng
 * 列定义
 */
public class ColumnMeta {

	private int index;
	private String name;
	private String alias;
	private String type;
	private boolean indexable;
	private int dbIndex;
	private String dbType;
	
	public ColumnMeta() {
		
	}
	
	public ColumnMeta(String name, String type, boolean indexable) {
		this.name = name;
		this.type = type;
		this.indexable = indexable;
	}
	
	public String getName() {
		return name;
	}
	public ColumnMeta setName(String name) {
		this.name = name;
		return this;
	}
	public String getType() {
		return type;
	}
	public ColumnMeta setType(String type) {
		this.type = type;
		return this;
	}
	public boolean isIndexable() {
		return indexable;
	}
	public ColumnMeta setIndexable(boolean indexable) {
		this.indexable = indexable;
		return this;
	}

	@Override
	public String toString() {
		return "ColumnBuilder [name=" + name + ", type=" + type
				+ ", indexable=" + indexable + "]";
	}

	public int getIndex() {
		return index;
	}

	public void setIndex(int index) {
		this.index = index;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + index;
		result = prime * result + (indexable ? 1231 : 1237);
		result = prime * result + ((name == null) ? 0 : name.hashCode());
		result = prime * result + ((type == null) ? 0 : type.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		ColumnMeta other = (ColumnMeta) obj;
		if (index != other.index)
			return false;
		if (indexable != other.indexable)
			return false;
		if (name == null) {
			if (other.name != null)
				return false;
		} else if (!name.equals(other.name))
			return false;
		if (type != other.type)
			return false;
		return true;
	}

	public String getAlias() {
		return alias;
	}

	public void setAlias(String alias) {
		this.alias = alias;
	}

	public int getDbIndex() {
		return dbIndex;
	}

	public void setDbIndex(int dbIndex) {
		this.dbIndex = dbIndex;
	}

	public String getDbType() {
		return dbType;
	}

	public void setDbType(String dbType) {
		this.dbType = dbType;
	}
}
