package com.znd.test;

import com.ZhongND.RedisDataBus.ServiceFactory;
import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;

public class BufferFactory {
	static private DFService service;
	
	static {
		try {
			service = ServiceFactory.getService();
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}	
	}
	
	static public MemBuffer createBuffer(String name) throws RedissonDBException  {
		return new MemBuffer(service, name);
	}
	
	static public void destory() {
		service.disConnect();
	}
}
