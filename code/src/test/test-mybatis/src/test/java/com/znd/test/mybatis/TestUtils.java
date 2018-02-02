package com.znd.test.mybatis;

import java.io.IOException;
import java.io.InputStream;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

public class TestUtils {
    //根据id查询用户信息，得到一条记录结果
	
	public static SqlSession createSession(boolean autoCommit) throws IOException {
        // mybatis配置文件
        String resource = "SqlMapConfig.xml";
        // 得到配置文件流
        InputStream inputStream =  Resources.getResourceAsStream(resource);
        
        //创建会话工厂，传入mybatis配置文件的信息
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
        
		SqlSession session = sqlSessionFactory.openSession(autoCommit);
		
		return session;
	}
	
	public static SqlSession createSession() throws IOException {
        return createSession(false);
	}
	
}
