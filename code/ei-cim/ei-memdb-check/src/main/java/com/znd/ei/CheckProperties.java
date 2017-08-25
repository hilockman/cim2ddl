package com.znd.ei;

import java.util.ArrayList;
import java.util.List;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.boot.context.properties.EnableConfigurationProperties;

@ConfigurationProperties("check")
@EnableConfigurationProperties(CheckProperties.class)
public class CheckProperties {

    private List<String> excludeFieldNames = new ArrayList<String>();
    private String excludeFieldPattern;
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
    

   
}
