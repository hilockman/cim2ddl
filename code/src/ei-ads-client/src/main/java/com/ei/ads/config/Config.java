package com.ei.ads.config;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.ei.ads.bus.buffer.BufferFactory;
import com.znd.ei.ads.bus.buffer.BufferFactoryBuilder;
import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.bus.config.TableMeta;

@Configuration
@EnableAutoConfiguration
public class Config {


	@Bean
	public BufferConfig bufferConfig(DabaBusProperties dabaBusProperties) {
		
		BufferConfig config = new BufferConfig();
			config.setId(dabaBusProperties.getId());
			config.setName(dabaBusProperties.getName());
			config.setAlias(dabaBusProperties.getAlias());
			config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
			config.setCreateFlag(BufferConfig.UPDATE);
			List<TableMeta> tables = dabaBusProperties.getTables();
			config.setTableMetas(tables != null? tables.toArray(new TableMeta[0]) : null);
			return config;
			
//			ColumnMeta [] columns = {new ColumnMeta("id", BufferFactoryBuilder.INT, true),
//					new ColumnMeta("name", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("doubleCol", BufferFactoryBuilder.DOUBLE, true),
//					new ColumnMeta("booleanCol", BufferFactoryBuilder.BOOLEAN, true)};
//			TEST_TABLE_MATA = new TableMeta().setName("MyTestTable").setColumns(Arrays.asList(columns));
//			
//			
//			ColumnMeta [] columns1 = {new ColumnMeta("id", BufferFactoryBuilder.INT, true),
//					new ColumnMeta("col1", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col2", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col3", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col4", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col5", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col6", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col7", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col8", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col9", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col10", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col11", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col12", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col13", BufferFactoryBuilder.STRING, true),
//					new ColumnMeta("col14", BufferFactoryBuilder.STRING, true)};
//			
//			TEST_TABLE_MATA1= new TableMeta().setName("MyTestTable1").setColumns(Arrays.asList(columns1));
			
//			config.setTableMetas(new TableMeta[]{TEST_TABLE_MATA, TEST_TABLE_MATA1});
			
	
//			BufferFactoryBuilder b = new BufferFactoryBuilder();
//			TEST_FACTORY = b.build(config);
	}
	
	
	@Bean 
	public BufferFactory bufferFactory(BufferConfig config) {
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		return b.build(config);
	}
	

	
	@Bean 
	public ClientConfig clientConfig(AdsClientProperties property, BufferFactory bufferFactory) {
		ClientConfig config = new ClientConfig();
		config.setHeartbeat(property.getHeartbeat());
		ExecutorService pool;
		if (property.getThread() < 0) {
			pool =  Executors.newCachedThreadPool();
		} else {
			pool =  Executors.newFixedThreadPool(property.getThread());
		}
		
		config.setThreadPool(pool);
		config.setPort(property.getPort());
		if (property.getIp() != null)
		config.setIp(property.getIp());
		else {
	        InetAddress ip;
	        String hostname;
	        try {
	            ip = InetAddress.getLocalHost();//TODO : how to deal with a host with more than one IP address.
	            hostname = ip.getHostName();
	            config.setHostName(hostname);
	            config.setIp(ip.getHostAddress());
	        } catch (UnknownHostException e) {
	 
	            e.printStackTrace();
	        }
		}
			
		
//		Buffer buffer = bufferFactory.openSession();
////		buffer.selectList(statement, parameter);
//		buffer.close();
		return config;
	}
}
