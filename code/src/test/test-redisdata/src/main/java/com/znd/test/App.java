package com.znd.test;

import com.ZhongND.RedisDataBus.ServiceFactory;
import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RBufferBuilder;
import com.ZhongND.RedisDataBus.Api.RMemDBApi;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        System.out.println( "Hello World!" );
        
		DFService service;
		RMemDBApi memDBApi; 
		
			try {
				
				service = ServiceFactory.getService();
				memDBApi = service.connect("pr");
				
				RMemDBBuilder memDBBuilder = memDBApi.getRMemDBBuilder("CommonBuffer");
				//if (!memDBBuilder.checkAvailability()) {	
					//创建buffer
					RBufferBuilder bufferBuilder = memDBBuilder.getBufferBuilder();				
				//}
				service.disConnect();
				System.out.println("exit!");

			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				
			}	
    }
}
