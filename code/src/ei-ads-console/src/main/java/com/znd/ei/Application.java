package com.znd.ei;

import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.ExitCodeGenerator;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

import com.znd.ei.ads.apl.reliability.AppUtil;

@SpringBootApplication
public class Application {
//	@Bean
//	public ExitCodeGenerator exitCodeGenerator() {
//		return () -> {
//			System.out.println("************MemStarter -k************");
//			AppUtil.execBuilder("MemStarter").addParam("-k").exec();
//			return 0;
//
//		};
//	}

	public static void main(String[] args) {
		SpringApplication.run(Application.class, args);
		//System.exit(SpringApplication.exit(SpringApplication.run(Application.class, args)));
	}

	@Bean
	public CommandLineRunner init() {
		return (args) -> {
//			new Thread(() -> {
//				System.out.println("***********MemStarter -s****************");
//				AppUtil.execBuilder("MemStarter").addParam("-k").exec();
//				AppUtil.execBuilder("MemStarter").addParam("-s").exec();
//				System.out.println("***********MemStarter exit****************");
//			}).start();

		};
	}
}
