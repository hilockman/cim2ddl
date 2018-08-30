package com.znd.bus.common.model;


public enum CalcJobStateEnum {
	//等待执行
	waiting,
	
	//正在执行
	running,
	
	//暂停
	suspend,
	
	//停止
	stop,
	
	//异常
	abnormal
}
