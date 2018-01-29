package com.znd.test;

import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RBufferBuilder;
import com.ZhongND.RedisDataBus.Api.RMemDBApi;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;


public class BufferFactory {
	private DFService service;
	private RMemDBApi memDBApi; 
	private RMemDBBuilder memDBBuilder;
	private RBufferBuilder bufferBuilder;
	
	public BufferFactory(DFService service, RMemDBApi memDBApi, RMemDBBuilder memDBBuilder, RBufferBuilder bufferBuilder)
	{
		this.service = service;
		this.memDBApi = memDBApi;
		this.memDBBuilder = memDBBuilder;
		this.bufferBuilder = bufferBuilder;
	}
	
	public BufferSession openSession()   {
		return new BufferSessionImp();
	}
	

	public void destory() {
		service.disConnect();
	}
}
