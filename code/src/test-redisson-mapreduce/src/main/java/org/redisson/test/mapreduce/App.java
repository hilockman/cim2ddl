package org.redisson.test.mapreduce;

import java.util.Map;

import org.redisson.api.RExecutorService;
import org.redisson.api.RMap;
import org.redisson.api.RedissonClient;
import org.redisson.api.mapreduce.RMapReduce;
import org.redisson.config.Config;
import org.redisson.config.RedissonNodeConfig;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

/**
 * Hello world!
 *
 */
@SpringBootApplication
public class App 
{
	static class TestJson {
		
		int value1;
		String value2;
		double value3;
		public int getValue1() {
			return value1;
		}
		public void setValue1(int value1) {
			this.value1 = value1;
		}
		public String getValue2() {
			return value2;
		}
		public void setValue2(String value2) {
			this.value2 = value2;
		}
		public double getValue3() {
			return value3;
		}
		public void setValue3(double value3) {
			this.value3 = value3;
		}
		
		
	}
    @SuppressWarnings("unused")
	public static void main( String[] args )
    {
        //System.out.println( "Hello World!" );
		ApplicationContext ctx = (ApplicationContext) SpringApplication.run(App.class, args);


		RedissonClient redisson = ctx.getBean(RedissonClient.class);
	    RMap<String, String> map = redisson.getMap("wordsMap");
	    //map.clear();
	    map.put("line1", "Alice was beginning to get very tired"); 
	    map.put("line2", "of sitting by her sister on the bank and");
	    map.put("line3", "of having nothing to do once or twice she");
	    map.put("line4", "had peeped into the book her sister was reading");
	    map.put("line5", "but it had no pictures or conversations in it");
	    map.put("line6", "and what is the use of a book");
	    map.put("line7", "thought Alice without pictures or conversation");
	    Config config = ctx.getBean(Config.class);
	    
	    RedissonNodeConfig nodeConfig = new RedissonNodeConfig(config);
	   // redisson.getExecutorService(RExecutorService.MAPREDUCE_NAME).registerWorkers(5);
	   // String serviceName = "test1";
	   // System.out.println(serviceName);
	   // RScheduledExecutorService es = redisson.getExecutorService(serviceName);
	    //nodeConfig.setExecutor(es);
	   // es.MAPREDUCE_NAME;
	    
	    //RScheduledExecutorService mes = redisson.getExecutorService(RExecutorService.MAPREDUCE_NAME);
	    //nodeConfig.setMapReduceWorkers(5);
	    
//	   int n =  es.countActiveWorkers();
//	   boolean bt = es.isTerminated();
//	   boolean bs = es.isShutdown();
	   

//	    Map<String, Integer> workers = new HashMap<String, Integer>();
//	    workers.put("test1", 2);
//	    nodeConfig.setExecutorServiceWorkers(workers);
//	    RedissonNode node = RedissonNode.create(nodeConfig);
//	    node.start();
	    
	    int n = nodeConfig.getMapReduceWorkers();
	    RMapReduce<String, String, String, Integer> mapReduce
	             = map.<String, Integer>mapReduce()
	                  .mapper(new WordMapper())
	                  .reducer(new WordReducer());
	    
	    
	    System.out.println("Start statistic ...");

	    // 统计词频
	    Map<String, Integer> mapToNumber = mapReduce.execute();

	    // 统计字数
	    Integer totalWordsAmount = mapReduce.execute(new WordCollator());
	    
		System.out.println(totalWordsAmount);
		//System.exit(SpringApplication.exit(ctx));
    }
}
