package org.test.java;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

import org.junit.Test;

public class BlockingQueueTest {

	private BlockingQueue<String> queue = new ArrayBlockingQueue<>(100);
	
	@Test
	public void test() throws InterruptedException {
		new Thread(new Runnable() {
			
			@Override
			public void run() {
				while (true) {
					try {
						String str = queue.take();
						System.out.println("rec : "+str);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						break;
					}
					
				}
			}
		}).start();
		
		
		queue.put("hello1");
		queue.put("hello2");
				
	}
}
