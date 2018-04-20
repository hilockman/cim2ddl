package com.znd.config;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.memdb.MDBDefine;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.client.Client;
import com.znd.client.impl.DefaultClient;
import com.znd.ei.memdb.DbEntryCollection;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.DbException;

@Configuration
@EnableAutoConfiguration
public class Config {

	@Bean 
	public ClientConfig clientConfig(AdsClientProperties property, BufferFactory bufferFactory) {
		ClientConfig config = new ClientConfig();
		config.setHeartbeat(property.getHeartbeat());
		config.setPort(property.getPort());
	
		ExecutorService pool;
		if (property.getThread() < 0) {
			pool =  Executors.newCachedThreadPool();
		} else {
			pool =  Executors.newFixedThreadPool(property.getThread());
		}
		
		config.setThreadPool(pool);
		config.setPort(property.getPort());
		
        InetAddress ip;
        String hostname;
        try {
            ip = InetAddress.getLocalHost();//TODO : how to deal with a host with more than one IP address.
            hostname = ip.getHostName();
            config.setHostName(hostname);
            if (property.getIp() != null)
    			config.setIp(property.getIp());
            else
               config.setIp(ip.getHostAddress());
        } catch (UnknownHostException e) {
 
            e.printStackTrace();
        }
		
			
		
//		Buffer buffer = bufferFactory.openSession();
////		buffer.selectList(statement, parameter);
//		buffer.close();
		return config;
	}
	
	@Bean
	public Client client(ClientConfig clientConfig, Buffer defaultBuffer) {
		return new DefaultClient();
	}
	
//	@Bean
//	@Order(10)
//	public Client defaultClient(ClientConfig clientConfig) {
//		return new DefaultClient();
//	}
//	
	
	@Bean
	public DbEntryOperations[] dbOps(DbEntryCollection c) throws DbException {
		String[] entryNames = {MDBDefine.g_strPRDBEntry, MDBDefine.g_strBpaDBEntry};
		DbEntryOperations[] opss = new DbEntryOperations[entryNames.length];
		int index = 0;

		for (String entryName : entryNames) {
			DbEntryOperations ops = c.findOrCreateDbEntry(entryName);
			opss[index++] = ops;
		}

		return opss;
	}
}
