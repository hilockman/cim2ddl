package com.znd.ei.ads.config;

import java.io.File;

public class ModelConfig {
	private String name;
	private File datFile;
	private File swiFile;
	private File configFile;
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public File getDatFile() {
		return datFile;
	}
	public void setDatFile(File datFile) {
		this.datFile = datFile;
	}
	public File getSwiFile() {
		return swiFile;
	}
	public void setSwiFile(File swiFile) {
		this.swiFile = swiFile;
	}
	public File getConfigFile() {
		return configFile;
	}
	public void setConfigFile(File configFile) {
		this.configFile = configFile;
	}
}
