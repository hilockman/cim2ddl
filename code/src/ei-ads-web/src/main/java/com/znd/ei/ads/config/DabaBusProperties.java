package com.znd.ei.ads.config;

import java.util.List;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

import com.znd.bus.config.TableMeta;

@Component
@ConfigurationProperties(prefix = "buffer")
public class DabaBusProperties {

	private String id;
	private String name;
	private String alias;
	private String createFlag;
	
	private List<TableMeta> tables;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public List<TableMeta> getTables() {
		return tables;
	}

	public void setTables(List<TableMeta> tables) {
		this.tables = tables;
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

	public String getCreateFlag() {
		return createFlag;
	}

	public void setCreateFlag(String createFlag) {
		this.createFlag = createFlag;
	}
}
