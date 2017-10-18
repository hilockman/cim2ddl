package com.znd.ei.codegen.service;

import java.util.ArrayList;
import java.util.List;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Component
@ConfigurationProperties("dbcheck")
public class CheckProperties {

	private List<String> invalidTableNames = new ArrayList<String>();
    private List<String> invalidFieldNames = new ArrayList<String>();
    private String invalidFieldPattern;
    private String validFieldPattern;
    
	public List<String> getInvalidTableNames() {
		return invalidTableNames;
	}
	public void setInvalidTableNames(List<String> invalidTableNames) {
		this.invalidTableNames = invalidTableNames;
	}
	public List<String> getInvalidFieldNames() {
		return invalidFieldNames;
	}
	public void setInvalidFieldNames(List<String> invalidFieldNames) {
		this.invalidFieldNames = invalidFieldNames;
	}
	public String getInvalidFieldPattern() {
		return invalidFieldPattern;
	}
	public void setInvalidFieldPattern(String invalidFieldPattern) {
		this.invalidFieldPattern = invalidFieldPattern;
	}
	public String getValidFieldPattern() {
		return validFieldPattern;
	}
	public void setValidFieldPattern(String validFieldPattern) {
		this.validFieldPattern = validFieldPattern;
	}
}
