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
			List<Pattern> excludeFieldPatterns = new ArrayList<Pattern>();			
			if (!names.isEmpty()) {
				System.out.println("--ExcludeFieldNames:"+names);
				String patternString = "("+String.join("|", names)+")";
				excludeFieldPatterns.add(Pattern.compile(patternString,Pattern.CASE_INSENSITIVE));
			}

			String str = properties.getExcludeFieldPattern();
			if (str != null && !str.isEmpty()) {
				excludeFieldPatterns.add(Pattern.compile(str));
				System.out.println("--ExcludeFieldPattern:"+str);
			}
			
			List<Pattern> excludeTablePatterns = new ArrayList<Pattern>();
			names = properties.getExcludeTableNames();
			if (!names.isEmpty()) {
				System.out.println("--ExcludeTableNames:"+names);
				String patternString = "("+String.join("|", names)+")";
				excludeTablePatterns.add(Pattern.compile(patternString,Pattern.CASE_INSENSITIVE));
			}
			
			
        	for (MemTable t: tables) {
    			for (Pattern excludePattern: excludeTablePatterns) {
    	   		    Matcher isMatch = excludePattern.matcher(t.getName());
         		   
        		    if (isMatch.matches()) {
        		    	System.out.println("表名:"+t.getName()+"("+t.getDescription()+")为保留名称,"+t.getName()+"("+t.getDescription()+")");
        		    }
    			}
    			
        		List<MemField> fields = t.getFields();
        		for (MemField f: fields) {
 			 
        			//System.out.println("Field:"+f.getName()+", Table:"+t.getName());
    			
        			for (Pattern excludePattern: excludeFieldPatterns) {
        	   		    Matcher isMatch = excludePattern.matcher(f.getName());
             		   
            		    if (isMatch.matches()) {
            		    	System.out.println("字段名:"+f.getName()+"("+f.getDescription()+")为保留名称, "+t.getName()+"("+t.getDescription()+")");
            		    }
        			}
        		}
        	}
        };
    } 
}
