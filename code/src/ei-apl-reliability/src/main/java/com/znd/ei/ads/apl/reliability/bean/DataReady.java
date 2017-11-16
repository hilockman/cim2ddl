package com.znd.ei.ads.apl.reliability.bean;

import com.znd.ei.ads.config.PRAdequacySetting;

public class DataReady {

	public static String DATA_READY = "DataReady";
	
	private String Command = DATA_READY;

	private PRAdequacySetting Content = new PRAdequacySetting();
	
	public String getCommand() {
		return Command;
	}

	public void setCommand(String command) {
		Command = command;
	}

	public PRAdequacySetting getContent() {
		return Content;
	}

	public void setContent(PRAdequacySetting content) {
		Content = content;
	}
	
	
}
