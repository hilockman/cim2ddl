package com.znd.test.mybatis;

import java.io.IOException;
import java.sql.Date;

import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

public class InsertTest {
	   @Test
	    public void update() throws IOException{

	        // 通过工厂得到SqlSession
	        SqlSession session  = TestUtils.createSession();

	        
	        AuthorMapper mapper = TestUtils.getMapper(AuthorMapper.class, session);
	 
	        Author author = new Author(99, "test", "female", new Date(0, 0, 0), "local");
	        mapper.insertAuthor(author);
	        System.out.println(author);
	        
	   
	       
	        
	       
	        


	        

	        
	        session.commit();
	        // 释放资源
	        session.close();
	        
	        

	   }
	        
}
