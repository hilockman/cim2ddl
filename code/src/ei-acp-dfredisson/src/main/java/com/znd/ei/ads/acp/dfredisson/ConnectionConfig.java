package com.znd.ei.ads.acp.dfredisson;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.net.URL;

import org.redisson.Redisson;
import org.redisson.RedissonNode;
import org.redisson.api.RedissonClient;
import org.redisson.config.ConfigSupport;
import org.redisson.config.RedissonNodeConfig;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.ei.ads.AdsServer;
import com.znd.ei.ads.AdsServerImp;
import com.znd.ei.ads.acp.ConnectionFactory;

@Configuration
@EnableAutoConfiguration
public class ConnectionConfig {

	@Bean
	public ConnectionFactory acpConnection() {
		ConnectionFactory conn =  new DFRedissonConnection();
		return conn;
	}
	
	private static String FILE_NAME = "redissonnode.json";

	
	private String read(Reader r) throws IOException {
		BufferedReader reader = new BufferedReader(r);
		
		StringBuilder stringBuilder = new StringBuilder();
		String content;
		while ((content = reader.readLine()) != null) {
			stringBuilder.append(content);
		}
		String str = stringBuilder.toString();
		return str;		
	}
	
	private String read(InputStream is) throws IOException {
		return read(new InputStreamReader(is));
		
	}
	
	
	@SuppressWarnings("static-access")
	@Bean
	public RedissonNodeConfig redissonNodeConfig() {

		FileInputStream fis = null;
		try {
			URL url = org.springframework.util.ResourceUtils.getURL("classpath:"+FILE_NAME);
			ConfigSupport support = new ConfigSupport();
			RedissonNodeConfig config =  support.fromJSON(url, RedissonNodeConfig.class);
			//InputStream is = this.getClass().getResourceAsStream("/"+FILE_NAME);
			
			//String content = read(is);

			
			// ConfigSupport support = new ConfigSupport();
			 //RedissonNodeConfig config =  support.fromJSON(content, RedissonNodeConfig.class);
			//System.out.println("Redisson Node Config : \n" + content);
			return config;
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			if (fis != null) {
				try {
					fis.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}

		return null;
	}
	
	@Bean
	public RedissonNode redissonNode() {
		RedissonNodeConfig nodeConfig = redissonNodeConfig();
	    RedissonNode node = RedissonNode.create(nodeConfig);
	    return node;
	}

	@Bean
	public RedissonClient redissonClient(RedissonNodeConfig config) {
		RedissonClient redisson = Redisson.create(config);
		return redisson;
	}
	
	@Bean
	public 	AdsServer adsServer() {
		return new AdsServerImp();
	}
    
}
