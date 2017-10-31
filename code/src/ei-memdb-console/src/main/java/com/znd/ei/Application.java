package com.znd.ei;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class Application {

    public static void main(String[] args) {
    	SpringApplication.exit(SpringApplication.run(Application.class, args));
    }
    
//    @Bean
//    public CommandLineRunner init(ClasssCreateService classCreator) {
//        return (args) -> {
//        	classCreator.createClasses();
//        };
//    } 
}
