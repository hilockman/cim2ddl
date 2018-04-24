package com.znd.test;

import java.util.List;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.controller.MemoryController;
import com.znd.server.impl.MemoryServerImpl.DbInfo;
import com.znd.server.impl.MemoryServerImpl.TableInfo;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class MemoryControllerTest {

	@Autowired
	private MemoryController controller;
	
	
	@Test
	public void testGetDb() {
		List<?> connections = controller.dbList();
		for (Object o : connections) {
			
			System.out.println(o);
		}
	}
	
	
	@Test
	public void testGetTables() {
		List<?> connections = controller.dbList();
		for (Object o : connections) {
		
			DbInfo conn = (DbInfo)o;
			List<?> tables = controller.tableList(conn.getName());
			for (Object o1 : tables) {
				System.out.println("db = "+conn.getName()+", table : "+o1);
			}
			System.out.println("db table size = "+tables.size());
		}
	}
	
	@Test
	public void testGetRecords() {
		List<?> connections = controller.dbList();
		for (Object o : connections) {
			DbInfo conn = (DbInfo) o;
				
			List<?> tables = controller.tableList(conn.getName());
			for (Object o1 : tables) {
				TableInfo t = (TableInfo) o1;
				
				System.out.println("db = "+conn.getName()+", table : "+o1+", size = "+t.getRecordSize());
			}
			System.out.println("db table size = "+tables.size());
		}
	}
}
