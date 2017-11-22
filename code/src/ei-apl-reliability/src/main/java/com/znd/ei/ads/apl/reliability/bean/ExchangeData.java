package com.znd.ei.ads.apl.reliability.bean;


public  class ExchangeData <T extends ExchangeContent> {

	private String Command;
	
	private T Content ;
	
	public ExchangeData() {
		this(null, null);
	}
	
	public ExchangeData(String command, T content) {
		this.Command = command;
		
		this.Content = content;
	}

	public String getCommand() {
		return Command;
	}

	public void setCommand(String command) {
		Command = command;
	}



	public T getContent() {
		return Content;
	}

	public void setContent(T content) {
		Content = content;
	}
	
	public Integer getValue() {
		if (Content != null)
			return Content.getValue();
		return null;
	}

	public void setValue(Integer value) {
		if (Content != null) 
			Content.setValue(value);
	}
	
	
}
