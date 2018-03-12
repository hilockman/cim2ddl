package com.ei.ads.config;

import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.ei.ads.buffer.Buffer;
import com.znd.ei.ads.buffer.BufferFactoryBuilder;
import com.znd.ei.ads.buffer.config.BufferConfig;
import com.znd.ei.ads.buffer.config.TableMeta;
import com.znd.ei.ads.buffer.factory.BufferFactory;

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
		
		
//		Buffer buffer = bufferFactory.openSession();
////		buffer.selectList(statement, parameter);
//		buffer.close();
		return config;
	}
}
