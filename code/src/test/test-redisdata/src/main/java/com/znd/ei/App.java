package com.znd.ei;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.autoconfigure.SpringBootApplication;

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
@SpringBootApplication
public class App 
{
	 public final static Logger logger = LoggerFactory.getLogger(App.class);
	
    public static void main( String[] args )
    {
        System.out.println( "Hello World!" );
        
        logger.info("test");
		DFService service;
		RMemDBApi memDBApi; 
		
			try {
				
				service = ServiceFactory.getService();
				memDBApi = service.connect("pr");
				
				RMemDBBuilder memDBBuilder = memDBApi.getRMemDBBuilder("CommonBuffer1");
				
				boolean flag = memDBBuilder.checkAvailability();
				//if (!memDBBuilder.checkAvailability()) {	
					//创建buffer
					RBufferBuilder bufferBuilder = memDBBuilder.getBufferBuilder();	
					bufferBuilder.commit();
				//}
					
				flag = memDBBuilder.checkAvailability();
				service.disConnect();
				System.out.println("exit!");

			} catch (RedissonDBException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				
			}	
    }
}
