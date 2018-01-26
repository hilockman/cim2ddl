package com.znd.test;

import java.io.Closeable;
import java.io.IOException;

import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RMemDBApi;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;

public class MemBuffer implements Closeable {

	private RMemDBBuilder dbBuilder;
	private RMemDBApi api;
	public MemBuffer(DFService service, String name) throws RedissonDBException {
		api = service.connect("pr");
		dbBuilder = api.getRMemDBBuilder("CommonBuffer");
	}
	public void close() throws IOException {
		// TODO Auto-generated method stub
		
	}


}
