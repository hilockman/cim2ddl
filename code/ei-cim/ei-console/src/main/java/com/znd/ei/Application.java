package com.znd.ei;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.context.properties.EnableConfigurationProperties;

import com.znd.ei.reliability.config.ReliabilityProperites;

@SpringBootApplication
@EnableConfigurationProperties(ReliabilityProperites.class)
public class Application {

    public static void main(String[] args) {
    	SpringApplication.run(Application.class, args);
    }
    
//    @Bean
//    public CommandLineRunner init(ClasssCreateService classCreator) {
//        return (args) -> {
//        	classCreator.createClasses();
//        };
//    } 
}
