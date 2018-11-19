package com.znd.bus.test;

import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;

import org.junit.Test;

public class TimerTest {

	@Test
	public void test() {
		TimerTask timerTask = new TimerTask() {
			
			@Override
			public void run() {
		        System.out.println("Timer task started at:"+new Date());
		       
		        System.out.println("Timer task finished at:"+new Date());
			}
		};
        //running timer task as daemon thread
        Timer timer = new Timer(true);
        timer.scheduleAtFixedRate(timerTask, 0, 1*1000);
        System.out.println("TimerTask started");
        //cancel after sometime
        try {
            Thread.sleep(120000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        timer.cancel();
        System.out.println("TimerTask cancelled");
        try {
            Thread.sleep(30000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    
	}
}
