package com.znd.test.mybatis;

import java.io.IOException;
import java.io.Reader;
import java.sql.Connection;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.jdbc.ScriptRunner;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

public class TestScript {
	//@Test
	public void testRunScript() throws IOException {

		SqlSession session = TestUtils.createSession();
		
		Connection conn = session.getConnection();
		
		Reader reader = Resources.getResourceAsReader("script/CreateDB.sql");
		
		ScriptRunner runner = new ScriptRunner(conn);
		runner.setErrorLogWriter(null);
		runner.runScript(reader);
		reader.close();
		session.close();
	}
	
	@Test
	public void testBlogScript()throws IOException {

		SqlSession session = TestUtils.createSession();
		
		Connection conn = session.getConnection();
		
		Reader reader = Resources.getResourceAsReader("script/eumji-blog.sql");
		
		ScriptRunner runner = new ScriptRunner(conn);
		runner.setErrorLogWriter(null);
		runner.runScript(reader);
		reader.close();
		session.close();
	}

}
