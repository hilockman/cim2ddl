package com.znd.ei;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.context.ApplicationContext;

import com.znd.ei.reliability.config.ReliabilityProperites;

@SpringBootApplication
@EnableConfigurationProperties(ReliabilityProperites.class)
public class Application {

    public static void main(String[] args) {
    	ApplicationContext context = SpringApplication.run(Application.class, args);

    	
    	AppCommand command = context.getBean(AppCommand.class);
    	if (command.isExit()) {
    		System.exit(SpringApplication.exit(context));
    	}
    			
    }
//    
//    @Bean
//    public CommandLineRunner init() {
//        return (args) -> {
//        	
//        };
//    }  
}
