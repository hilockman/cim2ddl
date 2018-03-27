package com.znd.ei.ads.config;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.znd.ei.ads.bus.buffer.BufferFactory;
import com.znd.ei.ads.bus.buffer.BufferFactoryBuilder;
import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.bus.config.TableMeta;

@Configuration
@EnableAutoConfiguration
public class DataBusConfig {


	@Bean
	public BufferConfig bufferConfig(DabaBusProperties dabaBusProperties) {
		
		BufferConfig config = new BufferConfig();
			config.setId(dabaBusProperties.getId());
			config.setName(dabaBusProperties.getName());
			config.setAlias(dabaBusProperties.getAlias());
			config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
			config.setCreateFlag(dabaBusProperties.getCreateFlag());
			config.setTableMetas(dabaBusProperties.getTables().toArray(new TableMeta[0]));
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
}
