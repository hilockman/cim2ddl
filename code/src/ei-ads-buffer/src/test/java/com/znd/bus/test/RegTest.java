package com.znd.bus.test;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.junit.Test;


public class RegTest {

	public class ReplaceInfo {
		int start;
		int size;
	}
	private  String format(String message, Object...args) {
		 if (message == null)
			 return null;
		 
		 String pattern = "(\\{\\s*\\})";
		 
	      // 创建 Pattern 对象
	      Pattern r = Pattern.compile(pattern);
	 
	      
		 Matcher m = r.matcher(message);

		 StringBuilder builder = new StringBuilder();
		 int pos = 0;
		 int index = 0;
		 while (m.find()) {		
			Object object = ((index < args.length ) ? args[index] : null);
			builder.append(message.substring(pos, m.start()));
			builder.append(object != null ? object.toString() : "");
			pos = m.end();
			index++;
		 }
		 
		 if (pos < message.length()) {
			 builder.append(message.substring(pos));
		 }
		 

		 
//		 String target = message;
//		 
//		 for (Object obj : args) {
//			 target = target.replaceFirst("\\{\\s*\\}", obj.toString());
//		 }
//		 
		 return builder.toString();
	}
	@Test
	public void func() {
		
		System.out.println(format("{ }, {}, {		}+    hello", 1,2,3));
	}
	
}
