package com.znd.ei.ads.bus.mapping;

import java.util.ArrayList;
import java.util.List;

public class ResultSet {

	private final List<String[]> results;
	
	

	public ResultSet(List<String[]> results) {
		this.results = results;
	}
	
	public ResultSet() {
		this.results = new ArrayList<String[]>();
	}
	
	public List<String[]> getResults() {
		return results;
	}
	
}
