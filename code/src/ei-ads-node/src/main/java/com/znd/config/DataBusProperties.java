package com.znd.config;

import java.io.IOException;
import java.net.URL;
import java.util.List;
import java.util.jar.JarInputStream;

import javax.annotation.PostConstruct;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.autoconfigure.AutoConfigureOrder;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.core.Ordered;
import org.springframework.core.annotation.Order;
import org.springframework.core.io.Resource;
import org.springframework.core.io.ResourceLoader;
import org.springframework.stereotype.Component;

import com.znd.bus.channel.ChannelConfig;
import com.znd.bus.config.TableMeta;
import com.znd.ei.JarStreamFactory;
import com.znd.ei.Utils;

@Component
@ConfigurationProperties(prefix = "buffer")
//@Order(Ordered.HIGHEST_PRECEDENCE)
@Order(-1)
@AutoConfigureOrder(Ordered.HIGHEST_PRECEDENCE)
public class DataBusProperties {


	private List<ChannelConfig> channels;

	private String id;
	private String name;
	private String alias;
	private String createFlag;
		
	private List<TableMeta> tables;

	private String typePackage;
	private String mapperPackage;
	
	private String redisConfig;
	
	private String localConfig;
	
	public DataBusProperties() {
		
	}
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public List<TableMeta> getTables() {
		return tables;
	}

	public void setTables(List<TableMeta> tables) {
		this.tables = tables;
	}

	public String getAlias() {
		return alias;
	}

	public void setAlias(String alias) {
		this.alias = alias;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getCreateFlag() {
		return createFlag;
	}

	public void setCreateFlag(String createFlag) {
		this.createFlag = createFlag;
	}
	
	public List<ChannelConfig> getChannels() {
		return channels;
	}

	public void setChannels(List<ChannelConfig> channels) {
		this.channels = channels;
	}
	
	
	public String getMapperPackage() {
		return mapperPackage;
	}

	public void setMapperPackage(String mapperPackage) {
		this.mapperPackage = mapperPackage;
	}

	public String getTypePackage() {
		return typePackage;
	}

	public void setTypePackage(String typePackage) {
		this.typePackage = typePackage;
	}

	public String getRedisConfig() {
		return redisConfig;
	}

	public void setRedisConfig(String redisConfig) {
		this.redisConfig = redisConfig;
	}

	public String getLocalConfig() {
		return localConfig;
	}

	public void setLocalConfig(String localConfig) {
		this.localConfig = localConfig;
	}
	
	
	@Autowired
	private ResourceLoader resourceLoader;

	@PostConstruct
	public void init() {
		System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DataBusProperties.init~~~~~~~~~~~~~~~~~~~~~~~~~~~");
// set jar stream loader for loading jar file from spring boot jar file。 
		Utils.setDefaultJarStreamFactory(new JarStreamFactory() {
			
			@Override
			public JarInputStream createStream(URL path) throws IOException {
				System.out.println("Url : "+path);
	        	StringBuilder jarUrl = new StringBuilder(path.toExternalForm());
	    	    int index = jarUrl.lastIndexOf(".jar");
	    	    if (index >= 0) {
	    	      jarUrl.setLength(index + 4);
	    	    }
	    	    
	        	System.out.println("Jar url : "+ jarUrl);
	        	Resource resource = resourceLoader.getResource(jarUrl.toString());
	        	System.out.println("resourceLoader:"+resourceLoader);
	        	System.out.println("resource:"+resource);
	        	JarInputStream jis = new JarInputStream(resource.getInputStream());
		        int rt = jis.available();
		        System.out.println("Available : "+rt);
	        	return jis;
	        	
				
			}
		});
		
//end set jar stream factory.
		
		System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DataBusProperties.init end~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	}
	
	
}
