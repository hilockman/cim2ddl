package com.znd.test.mybatis;

import java.io.IOException;
import java.sql.Date;

import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

public class UpdateTest {
    @Test
    public void update() throws IOException{

        // 通过工厂得到SqlSession
        SqlSession session  = TestUtils.createSession();

        
        AuthorMapper mapper = TestUtils.getMapper(AuthorMapper.class, session);
 
        Author author = mapper.selectAuthor(1);
        System.out.println(author);
        
        
        author.setName(author.getName()+",test");
        mapper.updateAuthor(author);
        System.out.println(mapper.selectAuthor(1));
       
        
       
        


        

        
        session.commit();
        // 释放资源
        session.close();
        
        


        
    }
}
