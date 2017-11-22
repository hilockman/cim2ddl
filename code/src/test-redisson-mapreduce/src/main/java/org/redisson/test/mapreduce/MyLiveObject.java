package org.redisson.test.mapreduce;

import java.util.Map;

import org.redisson.api.annotation.REntity;
import org.redisson.api.annotation.RId;

@REntity
public class MyLiveObject {
	@RId
    private String name;
	
	private Map<String, String> values;
	
	private String value;
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Map<String, String> getValues() {
		return values;
	}

	public void setValues(Map<String, String> values) {
		this.values = values;
	}

	public String getValue() {
		return value;
	}

	public void setValue(String value) {
		this.value = value;
	}


}
