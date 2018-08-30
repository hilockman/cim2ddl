package com.znd.bus.server.message;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import com.znd.bus.message.OptionType;



public class RequestType {

    
    private Date startTime;
    private Date endTime;
    private List<OptionType> option = new ArrayList<>();

    private List<ID> id = new ArrayList<>();
    
	private List<Object> any = new ArrayList<>();
	
	public Date getStartTime() {
		return startTime;
	}
	public void setStartTime(Date startTime) {
		this.startTime = startTime;
	}
	public Date getEndTime() {
		return endTime;
	}
	public void setEndTime(Date endTime) {
		this.endTime = endTime;
	}
	public List<OptionType> getOption() {
		return option;
	}
	public void setOption(List<OptionType> option) {
		this.option = option;
	}
	public List<ID> getId() {
		return id;
	}
	public void setId(List<ID> id) {
		this.id = id;
	}
	public List<Object> getAny() {
		return any;
	}
	public void setAny(List<Object> any) {
		this.any = any;
	}	
}
