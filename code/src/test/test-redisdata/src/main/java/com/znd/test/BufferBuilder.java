package com.znd.test;

import com.ZhongND.RedisDataBus.ServiceFactory;
import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RBufferBuilder;
import com.ZhongND.RedisDataBus.Api.RMemDBApi;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;

public class BufferBuilder {

	public static BufferConfig getDefaultConfig() {
		BufferConfig config = new BufferConfig();
		config.setAppName("pr");
		config.setName("CommonBuffer");
		return config;
	}
	
	public BufferFactory build(BufferConfig config) {
		DFService service;
		RMemDBApi memDBApi; 

			try {
				
				service = ServiceFactory.getService();
				memDBApi = service.connect(config.getAppName());
				
				RMemDBBuilder memDBBuilder = memDBApi.getRMemDBBuilder(config.getName());
				//if (!memDBBuilder.checkAvailability()) {	
					//创建buffer
					RBufferBuilder bufferBuilder = memDBBuilder.getBufferBuilder();				
				//}
					return new BufferFactory(service, memDBApi, memDBBuilder, bufferBuilder);		

			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();

			}
			return null;	
	}
}
