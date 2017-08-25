package com.znd.ei;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.context.annotation.Bean;

import com.znd.ei.memdb.dao.MemDbRepository;
import com.znd.ei.memdb.dao.MemField;
import com.znd.ei.memdb.dao.MemTable;

@SpringBootApplication
@EnableConfigurationProperties(CheckProperties.class)
public class Application {

    public static void main(String[] args) {
    	System.exit(SpringApplication.exit(SpringApplication.run(Application.class, args)));
    }
    
    @Bean
    public CommandLineRunner init(MemDbRepository repository, CheckProperties properties) {
        return (args) -> {
        	List<MemTable> tables = repository.getTables();
			List<String> names = properties.getExcludeFieldNames();
			List<Pattern> excludePatterns = new ArrayList<Pattern>();
			
			if (names != null && !names.isEmpty()) {
				System.out.println("--ExcludeFieldNames:"+names);
				String patternString = "("+String.join("|", names)+")";
				excludePatterns.add(Pattern.compile(patternString,Pattern.CASE_INSENSITIVE));
			}

			String str = properties.getExcludeFieldPattern();
			if (str != null && !str.isEmpty()) {
				excludePatterns.add(Pattern.compile(str));
				System.out.println("--ExcludeFieldPattern:"+str);
			}
			
        	for (MemTable t: tables) {
        		List<MemField> fields = t.getFields();
        		for (MemField f: fields) {
 			 
        			//System.out.println("Field:"+f.getName()+", Table:"+t.getName());

        			
        			for (Pattern excludePattern: excludePatterns) {
        	   		    Matcher isMatch = excludePattern.matcher(f.getName());
             		   
            		    if (isMatch.matches()) {
            		    	System.out.println("Error:"+f.getName()+", Table:"+t.getName());
            		    }
            				
        			}
        		}
        	}
        };
    } 
}
