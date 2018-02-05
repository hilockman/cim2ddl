package com.znd.test.mybatis;

import java.io.IOException;
import java.sql.Date;

import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

public class TestJavaMapper {
    @Test
    public void findUserByIdTest() throws IOException{

        // 通过工厂得到SqlSession
        SqlSession session  = TestUtils.createSession();

        
        AuthorMapper mapper = TestUtils.getMapper(AuthorMapper.class, session);
        
        Author author = new Author("author0", "female", new Date(0), "newman");
        author.setId(0);
        mapper.insertAuthor(author);
        
       
        author = mapper.selectAuthor(8);
        


        System.out.println(author);

        session.commit();
        // 释放资源
        session.close();

    }
}
