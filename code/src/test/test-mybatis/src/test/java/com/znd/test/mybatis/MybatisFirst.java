package com.znd.test.mybatis;


import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.sql.Connection;
import java.util.Date;
import java.util.List;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.jdbc.ScriptRunner;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Test;

/**
 * Created by Administrator on 2016/2/23.
 */
public class MybatisFirst {

    //根据id查询用户信息，得到一条记录结果
	
	private SqlSession createSession() throws IOException {
        // mybatis配置文件
        String resource = "SqlMapConfig.xml";
        // 得到配置文件流
        InputStream inputStream =  Resources.getResourceAsStream(resource);
        
        //创建会话工厂，传入mybatis配置文件的信息
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
        
		SqlSession session = sqlSessionFactory.openSession();
		
		return session;
	}
	
	@Test
	public void testRunScript() throws IOException {

		SqlSession session = createSession();
		
		Connection conn = session.getConnection();
		
		Reader reader = Resources.getResourceAsReader("script/CreateDB.sql");
		
		ScriptRunner runner = new ScriptRunner(conn);
		runner.setErrorLogWriter(null);
		runner.runScript(reader);
		reader.close();
		session.close();
	}

    @Test
    public void findUserByIdTest() throws IOException{

        // 通过工厂得到SqlSession
        SqlSession sqlSession  = createSession();

        // 通过SqlSession操作数据库
        // 第一个参数：映射文件中statement的id，等于=namespace+"."+statement的id
        // 第二个参数：指定和映射文件中所匹配的parameterType类型的参数
        // sqlSession.selectOne结果 是与映射文件中所匹配的resultType类型的对象
        // selectOne查询出一条记录
        User user = sqlSession.selectOne("test.findUserById", 1);

        System.out.println(user);

        // 释放资源
        sqlSession.close();

    }

    // 根据用户名称模糊查询用户列表
    @Test
    public void findUserByNameTest() throws IOException {
        // 通过工厂得到SqlSession
        SqlSession sqlSession  = createSession();
        
        // list中的user和映射文件中resultType所指定的类型一致
        List<User> list = sqlSession.selectList("test.findUserByName", "小明");
        System.out.println(list);
        sqlSession.close();

    }

 // 添加用户信息
    @Test
    public void insertUserTest() throws IOException {
        // 通过工厂得到SqlSession
        SqlSession sqlSession  = createSession();
        
        // 插入用户对象
        User user = new User();
        user.setUsername("王小军");
        user.setBirthday(new Date());
        user.setSex("1");
        user.setAddress("河南郑州");

        sqlSession.insert("test.insertUser", user);

        // 提交事务
        sqlSession.commit();

        // 获取用户信息主键
        System.out.println(user.getId());
        // 关闭会话
        sqlSession.close();

    }

    // 根据id删除 用户信息
    @Test
    public void deleteUserTest() throws IOException {
        // 通过工厂得到SqlSession
        SqlSession sqlSession  = createSession();

        // 传入id删除 用户
        sqlSession.delete("test.deleteUser", 29);

        // 提交事务
        sqlSession.commit();

        // 关闭会话
        sqlSession.close();

    }

    // 根据删除所有用户信息
    @Test
    public void deleteAllUser() throws IOException {
        // 通过工厂得到SqlSession
        SqlSession sqlSession  = createSession();

        // 传入id删除 用户
        sqlSession.delete("test.deleteUsers");

        // 提交事务
        sqlSession.commit();

        // 关闭会话
        sqlSession.close();

    }
    
    // 更新用户信息
    @Test
    public void updateUserTest() throws IOException {
        // 通过工厂得到SqlSession
        SqlSession sqlSession  = createSession();
        
        // 更新用户信息

        User user = new User();
        //必须设置id
        user.setId(2);
        user.setUsername("王大军");
        user.setBirthday(new Date());
        user.setSex("2");
        user.setAddress("河南郑州");

        sqlSession.update("test.updateUser", user);

        // 提交事务
        sqlSession.commit();

        // 关闭会话
        sqlSession.close();

    }
}