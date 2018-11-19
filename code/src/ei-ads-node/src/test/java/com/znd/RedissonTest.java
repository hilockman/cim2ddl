package com.znd;

import java.io.File;
import java.io.IOException;

import org.junit.Test;
import org.redisson.Redisson;
import org.redisson.api.RTopic;
import org.redisson.api.RedissonClient;
import org.redisson.client.codec.StringCodec;
import org.redisson.config.Config;

public class RedissonTest {

	@Test
	public void test() {
		ClassLoader classLoader = getClass().getClassLoader();
		File file = new File(classLoader.getResource("static/redisson/localredis.yaml").getFile());
		try {
			Config config = Config.fromYAML(file);
			RedissonClient redisson = Redisson.create(config);
			RTopic<String> topic0 = redisson.getTopic("startStateEstimateTopic", new StringCodec());
			topic0.publish("start");
			RTopic<String> topic = redisson.getTopic("stateEstimateTopic", new StringCodec());
			for (int i = 0; i < 14841; i++) {
				topic.publish("test");
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
