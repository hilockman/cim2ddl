package org.redisson.test.mapreduce;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;

import org.redisson.Redisson;
import org.redisson.api.RedissonClient;
import org.redisson.config.Config;
import org.redisson.config.ConfigSupport;
import org.redisson.config.RedissonNodeConfig;
import org.redisson.test.mapreduce.App.TestJson;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.google.gson.Gson;

@Configuration
@EnableAutoConfiguration
public class RedissonConfig {

	
	public static void main(String [] args) {
		Gson gson = new Gson();
		String str = gson.toJson(new TestJson());
		System.out.println(str);
		
		
		Config config = new Config();
		System.out.println(gson.toJson(config));
	}
	String FILE_NAME = "ClusterServersConfig.cfg";

	
	String read(Reader r) throws IOException {
		BufferedReader reader = new BufferedReader(r);
		
		StringBuilder stringBuilder = new StringBuilder();
		String content;
		while ((content = reader.readLine()) != null) {
			stringBuilder.append(content);
		}
		String str = stringBuilder.toString();
		return str;		
	}
	
	String read(InputStream is) throws IOException {
		return read(new InputStreamReader(is));
		
	}
	
	String readFile(File file) throws IOException {
		return read(new FileReader(file));
	}
	@SuppressWarnings("static-access")
	@Bean
	public RedissonNodeConfig config() {
		RedissonNodeConfig config = new RedissonNodeConfig();

		FileInputStream fis = null;
		try {
//			ResourcePatternResolver resolver = new PathMatchingResourcePatternResolver();
//			Resource[] resources = resolver.getResources("/resources/*.cfg");
			InputStream is = this.getClass().getResourceAsStream("/"+FILE_NAME);
			
			//String content = read(is);
			//System.out.println((char)is.read());
//			config = config.fromJSON(is);
	        
			//File file = ResourceUtils.getFile("classpath:" + FILE_NAME);
//			 is = new FileInputStream(file);
//
//			 config.fromJSON(is);
			
	        ConfigSupport support = new ConfigSupport();
	        config = support.fromJSON(is, RedissonNodeConfig.class);



			//config = config.fromJSON(is);

			// is = new FileInputStream(file);

			System.out.println("config : \n" + config);
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

		return config;
	}

	@Bean
	public RedissonClient redisson(Config config) {
		RedissonClient redisson = Redisson.create(config);
		return redisson;
	}
	
//	@Bean
//	public RedissonNode redissonNode(Config config) {
//		
//	}
} 
