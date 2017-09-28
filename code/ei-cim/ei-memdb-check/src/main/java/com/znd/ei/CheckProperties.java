package com.znd.ei;

import java.util.ArrayList;
import java.util.List;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.boot.context.properties.EnableConfigurationProperties;

@ConfigurationProperties("check")
@EnableConfigurationProperties(CheckProperties.class)
public class CheckProperties {

	private List<String> excludeTableNames = new ArrayList<String>();
    private List<String> excludeFieldNames = new ArrayList<String>();
    private String excludeFieldPattern;
    private String fieldPattern;
	public List<String> getExcludeFieldNames() {
		return excludeFieldNames;
	}

	public void setExcludeFieldNames(List<String> excludeFieldNames) {
		this.excludeFieldNames = excludeFieldNames;
	}


	public String getExcludeFieldPattern() {
		return excludeFieldPattern;
	}

	public void setExcludeFieldPattern(String excludeFieldPattern) {
		this.excludeFieldPattern = excludeFieldPattern;
	}

	public List<String> getExcludeTableNames() {
		return excludeTableNames;
	}

	public void setExcludeTableNames(List<String> excludeTableNames) {
		this.excludeTableNames = excludeTableNames;
	}

	public String getFieldPattern() {
		return fieldPattern;
	}

	public void setFieldPattern(String fieldPattern) {
		this.fieldPattern = fieldPattern;
	}
    

   
}
