package com.znd.bus.util;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import org.slf4j.Logger;



public class TimeCount {
	
	private String name;
	private Logger logger;
	private Runnable r;
	private double elapsedSeconds;

	private TimeCount() {
		
	}
	
	public static class Builder
	{
		private TimeCount time = new TimeCount();
		public Builder()
		{
			
		}
		
		public Builder logger(Logger logger) {
			time.logger = logger;
			return this;
		}
		
		public Builder name(String str) {
			time.name = str;
			return this;
		}
		
		public Builder name(String formate, Object ... args) {
			time.name = String.format(formate, args);
			return this;
		}
		
		public Builder runnable(Runnable r) {
			time.r = r;
			return this;
		}
		
		public TimeCount build() {
			return time;
		}
		
		
	}

	private static ExecutorService pool = Executors.newCachedThreadPool();
	
	public static void exec(String name, Runnable r, Logger logger)
	{
		new TimeCount.Builder().name(name).runnable(r).logger(logger).build().exec();
	}
	
	public static TimeCount exec(String name, Runnable r)
	{
		TimeCount tc = new TimeCount.Builder().name(name).runnable(r).build();
		tc.exec();
		return tc;
	}
	
	public static final double LESS_ELAPSED_TIME = 1.0;
	public static final int CHECK_CYCLE_TIME = 20;
	public void exec() {
		long tStart = System.currentTimeMillis();
		Future<?> future = pool.submit(r);		
		long tDelta = 0;
		boolean flag = false;
		long tEnd;
		while (!future.isDone()) {
			tEnd = System.currentTimeMillis();
			tDelta = tEnd - tStart;
			double elapsedSeconds = tDelta / 1000.0;
			try {
				Thread.sleep(CHECK_CYCLE_TIME);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			if (elapsedSeconds > LESS_ELAPSED_TIME && !flag) {
				flag = true;
				log(String.format("Start to %s ...", name));
			}
		}
		
		tEnd = System.currentTimeMillis();
		tDelta = tEnd - tStart;
		elapsedSeconds = tDelta / 1000.0;
		log(String.format("Finished %s, consumed time is %f second.", name,  elapsedSeconds));

	}
	
	private void log(String str) {
		if (logger != null) {
			logger.info(str);
		} else {
			System.out.println(str);
		}
	}
		
}
