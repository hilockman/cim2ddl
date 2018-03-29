package com.znd.bus.statement;

import java.util.HashMap;
import java.util.Map;

public abstract class PrepareStatement implements Statement  {
	final protected Map<String, String> conditionMap = new HashMap<>();
	
	public PrepareStatement() {

	}

	public Map<String, String> getConditionMap() {
		return conditionMap;
	}
	
	public void set(String key, String value) {
		conditionMap.put(key, value);
	}
	
	public void putAll(Map<String, String> map) {
		conditionMap.putAll(map);
	}
}
