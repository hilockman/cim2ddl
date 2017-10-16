package com.znd.ei.codegen.service;

import java.util.ArrayList;
import java.util.List;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.boot.context.properties.EnableConfigurationProperties;

@ConfigurationProperties("gencode")
@EnableConfigurationProperties(StorageProperties.class)
public class StorageProperties {

    /**
     * Folder location for storing files
     */
//    private String target = "com/znd/ei/memdb/domain";
	private String target = System.getProperty("user.dir");
	
    private List<DbInfo> dbInfos = new ArrayList<>();
    
    private boolean enableEntityAnnotation;

    private List<String> excludeClasses = new ArrayList<String>();
    



	public List<String> getExcludeClasses() {
		return excludeClasses;
	}

	public void setExcludeClasses(List<String> excludeClasses) {
		this.excludeClasses = excludeClasses;
	}

	public String getTarget() {
		return target;
	}

	public void setTarget(String target) {
		this.target = target;
	}

	public List<DbInfo> getDbInfos() {
		return dbInfos;
	}

	public void setDbInfos(List<DbInfo> dbInfos) {
		this.dbInfos = dbInfos;
	}

	public boolean isEnableEntityAnnotation() {
		return enableEntityAnnotation;
	}

	public void setEnableEntityAnnotation(boolean enableEntityAnnotation) {
		this.enableEntityAnnotation = enableEntityAnnotation;
	}
   
}
