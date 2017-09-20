package org.test.redisson.mapreduce;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import org.redisson.Redisson;
import org.redisson.RedissonNode;
import org.redisson.api.RedissonClient;
import org.redisson.config.Config;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.util.ResourceUtils;
import org.test.redisson.mapreduce.App.TestJson;

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

	@SuppressWarnings("static-access")
	@Bean
	public Config config() {
		Config config = new Config();

		FileInputStream is = null;
		try {
			File file = ResourceUtils.getFile("classpath:" + FILE_NAME);
//			 is = new FileInputStream(file);
//
//			 config.fromJSON(is);

			@SuppressWarnings("resource")
			BufferedReader bufferedReader = new BufferedReader(new FileReader(
					file));
			StringBuilder stringBuilder = new StringBuilder();
			String content;
			while ((content = bufferedReader.readLine()) != null) {
				stringBuilder.append(content);
			}
			String str = stringBuilder.toString();
			config = config.fromJSON(str);

			// is = new FileInputStream(file);

			System.out.println("config : \n" + config);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			if (is != null) {
				try {
					is.close();
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
