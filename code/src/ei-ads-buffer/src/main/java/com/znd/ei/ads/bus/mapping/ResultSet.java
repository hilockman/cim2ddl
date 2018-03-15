package com.znd.ei.ads.bus.mapping;

import java.util.List;

public class ResultSet {

	private List<String[]> results;

	public ResultSet(List<String[]> results) {
		this.results = results;
	}
	
	public List<String[]> getResults() {
		return results;
	}

	public void setResults(List<String[]> results) {
		this.results = results;
	}
	
	
}
