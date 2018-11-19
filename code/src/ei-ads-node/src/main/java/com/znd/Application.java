package com.znd;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class Application 
{
    public static void main( String[] args ) throws Exception
    {
    	//try {
    	SpringApplication.run(Application.class, args);
//    	} catch (RuntimeException e) {
//    		System.err.println(e.getMessage());
//    		e.printStackTrace();
//    	}
    }
}
