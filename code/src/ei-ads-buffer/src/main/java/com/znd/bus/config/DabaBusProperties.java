package com.znd.bus.config;

import java.util.List;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.core.Ordered;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;

import com.znd.bus.channel.ChannelConfig;

@Component
@ConfigurationProperties(prefix = "buffer")
@Order(Ordered.HIGHEST_PRECEDENCE)
public class DabaBusProperties {

	private List<ChannelConfig> channels;

	private String id;
	private String name;
	private String alias;
	private String createFlag;
	
	
	private List<TableMeta> tables;

	private String typePackage;
	private String mapperPackage;
	
	private String redisConfig;
	
	private String localConfig;
	
	public DabaBusProperties() {
		
	}
	
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
	
	

	public List<ChannelConfig> getChannels() {
		return channels;
	}

	public void setChannels(List<ChannelConfig> channels) {
		this.channels = channels;
	}
	
	
	public String getMapperPackage() {
		return mapperPackage;
	}

	public void setMapperPackage(String mapperPackage) {
		this.mapperPackage = mapperPackage;
	}

	public String getTypePackage() {
		return typePackage;
	}

	public void setTypePackage(String typePackage) {
		this.typePackage = typePackage;
	}

	public String getRedisConfig() {
		return redisConfig;
	}

	public void setRedisConfig(String redisConfig) {
		this.redisConfig = redisConfig;
	}

	public String getLocalConfig() {
		return localConfig;
	}

	public void setLocalConfig(String localConfig) {
		this.localConfig = localConfig;
	}
}
