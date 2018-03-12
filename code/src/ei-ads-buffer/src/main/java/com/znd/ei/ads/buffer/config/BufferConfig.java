package com.znd.ei.ads.buffer.config;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class BufferConfig {
	
	private String appName;
	private String id;
	private String name;
	private String alias;
	
	private List<TableMeta> tableMetas = new ArrayList<>();
	
	private Map<String, TableMeta> metaMap = new HashMap<>();

	/**
	 * 每次重新创建buffer
	 */
	public static final Integer CREATE = 0; 
	
	/**
	 * 不更新
	 */
	public static final Integer FALSE = 1;  
	
	/**
	 * 每次检查buffer定义，如果有变化则更新
	 */
	public static final Integer UPDATE = 2; 
	
	//更新标志,值为0， 1， 2, 缺省为update
	private int createFlag = UPDATE; 
	

	
	public String getAppName() {
		return appName;
	}
	public BufferConfig setAppName(String appName) {
		this.appName = appName;
		return this;
	}
	public String getName() {
		return name;
	}
	public BufferConfig setName(String name) {
		this.name = name;
		return this;
	}
	
	
	public String getKey() {
		return appName+"."+name;
	}
	public int getCreateFlag() {
		return createFlag;
	}
	public void setCreateFlag(int createFlag) {
		this.createFlag = createFlag;
	}
	
	public TableMeta[] getTableMetas() {
		return tableMetas.toArray(new TableMeta[0]);
	}
	
	public void setTableMetas(TableMeta[] tableMetas) {
		if (tableMetas == null)
			return;
		
		this.tableMetas = Arrays.asList(tableMetas);
		metaMap.clear();
		for (TableMeta meta : tableMetas) {
			metaMap.put(meta.getName(), meta);
		}
	}
	
	public TableMeta find(String tableName) {
		return metaMap.get(tableName);
	}
	
	
	public void build() {
		for (int i = 0; i < tableMetas.size(); i++) {
			tableMetas.get(i).formIndexColumn();
		}
	}
	
	public void add(TableMeta tableMeta) {
		tableMetas.add(tableMeta);
		metaMap.put(tableMeta.getName(), tableMeta);
	}
	
	public String getAlias() {
		return alias;
	}
	public void setAlias(String alias) {
		this.alias = alias;
	}
	
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}	
}
