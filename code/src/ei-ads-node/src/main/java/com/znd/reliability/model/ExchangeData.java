package com.znd.reliability.model;


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
	
	public String getValue() {
		if (Content != null)
			return Content.getValue();
		return null;
	}

	public void setValue(String value) {
		if (Content != null) 
			Content.setValue(value);
	}

	@Override
	public String toString() {
		return "ExchangeData [Command=" + Command + ", Content=" + Content + "]";
	}
	
	
}
