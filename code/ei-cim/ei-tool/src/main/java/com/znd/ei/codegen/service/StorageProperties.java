package com.znd.ei.codegen.service;

import java.util.List;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.boot.context.properties.EnableConfigurationProperties;

@ConfigurationProperties("storage")
@EnableConfigurationProperties(StorageProperties.class)
public class StorageProperties {

    /**
     * Folder location for storing files
     */
    private String location = "com/znd/ei/memdb/domain";

    private List<String> excludeClasses;
    
    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

	public List<String> getExcludeClasses() {
		return excludeClasses;
	}

	public void setExcludeClasses(List<String> excludeClasses) {
		this.excludeClasses = excludeClasses;
	}
   
}
