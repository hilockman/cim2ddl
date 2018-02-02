package com.znd.ei.buffer;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.junit.AfterClass;
import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.annotation.Repeat;
import org.springframework.test.context.junit4.SpringRunner;

import com.ZhongND.RedisDataBus.Exception.RedissonDBException;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class BufferIOTests {
	
	public static TableMeta TEST_TABLE_MATA;
	public static TableMeta TEST_TABLE_MATA1;
	public static BufferFactory TEST_FACTORY;
	public static BufferConfig config;

	
	@Test
	public  void init() throws Exception  {

		
		System.out.println("------------------------start TestBus.init()----------------------------");

	   	config = new BufferConfig();
			config.setName("myTestBuffer");
			config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
			config.setCreateFlag(BufferConfig.CREATE);
			
			ColumnMeta [] columns = {new ColumnMeta("id", BufferFactoryBuilder.INT, true),
					new ColumnMeta("name", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("doubleCol", BufferFactoryBuilder.DOUBLE, true),
					new ColumnMeta("booleanCol", BufferFactoryBuilder.BOOLEAN, true)};
			TEST_TABLE_MATA = new TableMeta().setName("MyTestTable").setColumns(Arrays.asList(columns));
			
			
			ColumnMeta [] columns1 = {new ColumnMeta("id", BufferFactoryBuilder.INT, true),
					new ColumnMeta("col1", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col2", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col3", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col4", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col5", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col6", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col7", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col8", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col9", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col10", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col11", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col12", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col13", BufferFactoryBuilder.STRING, true),
					new ColumnMeta("col14", BufferFactoryBuilder.STRING, true)};
			
			TEST_TABLE_MATA1= new TableMeta().setName("MyTestTable1").setColumns(Arrays.asList(columns1));
			
			config.setTableMetas(new TableMeta[]{TEST_TABLE_MATA, TEST_TABLE_MATA1});
			
	
			BufferFactoryBuilder b = new BufferFactoryBuilder();
			TEST_FACTORY = b.build(config);
			
			
			Buffer session = TEST_FACTORY.openSession(false);
			//session.delete(TEST_TABLE_MATA);
			
			for (int j = 0; j < 1000; j++) {
				String[] record = { String.valueOf(j), "col"+j, String.valueOf(j*.1), String.valueOf(true) };	
				session.insert(TEST_TABLE_MATA.getName(), record);					
			}
			
			for (int j = 0; j < 10000; j++) {
				String[] record = new String[TEST_TABLE_MATA1.getColumnSize()];
				record[0] = String.valueOf(j);
				for (int k = 1; k < TEST_TABLE_MATA1.getColumnSize(); k++) {
					record[k] = "col_"+j+"_"+k;
				}
				session.insert(TEST_TABLE_MATA1.getName(), record);
			}
			
			session.commit();
			session.close();	
			

		
		
		System.out.println("------------------------end TestBus.init()----------------------------");
	}

	




	
//	@Test
//	public void testCreate1000Buffer() throws RedissonDBException {
//		int count = 1000;
//		
//		
//		for (int i = 0; i < count; i++) {
//			BufferConfig config = new BufferConfig();
//			config.setName("myBuffer"+i);
//			config.setAppName(BufferBuilder.DEFAULT_APPNAME);
//			config.setCreateFlag(BufferConfig.CREATE);
//			BufferBuilder b = new BufferBuilder();
//			b.build(config, null);
//		}
//	}
	

//	

    @Test
	public  void createOneTable() throws RedissonDBException {
    	System.out.println("------------------------start TestBus.createOneTable()----------------------------");	

		BufferConfig config = new BufferConfig();
		config.setName("myBuffer");
		config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
		config.setCreateFlag(BufferConfig.CREATE);
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		ColumnMeta [] columns = {new ColumnMeta("id", BufferFactoryBuilder.INT, true),
				new ColumnMeta("name", BufferFactoryBuilder.STRING, false),
				new ColumnMeta("doubleCol", BufferFactoryBuilder.DOUBLE, false),
				new ColumnMeta("booleanCol", BufferFactoryBuilder.BOOLEAN, false)};
		TableMeta[] tableMetas = {new TableMeta().setName("MyTable").setColumns(Arrays.asList(columns))};
		config.setTableMetas(tableMetas);
		b.build(config).destory();

		System.out.println("------------------------end TestBus.createOneTable()----------------------------");			
	}
    

    
//    @Test
//    public void testInsertOneRecord() {
//		//insert records		
//		List<String> colNames = table.getColumnNameArray();
//		for (int j = 0; j < 10000; j++) {
//			String[] record = new String[colNames.size()];
//			String[] index = {String.valueOf(j)};
//			record[0] = index[0];
//			for (int i = 1; i < colNames.size(); i++) {
//				record[i] = String.valueOf(i);
//			}
//	
//			table.setRecord(record, index);			
//		}
//		
//		
//		System.out.println("插入记录成功！record count = ");
//		
//		//read records
//		colNames = table.getColumnNameArray();
////		List<String[]> rt = table.getRecord(null);
////	    for (String [] rec : rt) {
////	    	System.out.print("rec :");
////	    	for (String str : rec) {
////	    		System.out.print(str+" ");
////	    	}
////	    	System.out.println();
////	    }
//		Map<String, String> conditions = new HashMap<String, String>();
//		String key = "String";
//		String value = "1000000";
//		conditions.put(key, value);
//		List<String> list = table.getCell(colNames.get(0), conditions);
//		System.out.println("get value：" + list.toString());
//		table.setCell(colNames.get(0), String.valueOf(10), conditions);
//		list = table.getCell(colNames.get(0), conditions);
//		System.out.println("get new value：" + list.toString());
//
//		System.out.println("删除Buffer:");
//		builder.destory();
//    }
//    
    @Test
    public void dropOneTable() throws RedissonDBException {
    	System.out.println("------------------------start TestBus.dropOneTable()----------------------------");
  
    	BufferConfig config = new BufferConfig();
		config.setName("myBuffer");
		config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
		config.setCreateFlag(BufferConfig.UPDATE);
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		ColumnMeta [] columns = {new ColumnMeta("id", BufferFactoryBuilder.INT, true),
				new ColumnMeta("name", BufferFactoryBuilder.STRING, true),
				new ColumnMeta("doubleCol", BufferFactoryBuilder.DOUBLE, true),
				new ColumnMeta("booleanCol", BufferFactoryBuilder.BOOLEAN, true)};
		TableMeta[] tableMetas = {new TableMeta().setName("MyTable").setColumns(Arrays.asList(columns))};
		config.setTableMetas(tableMetas);
		BufferFactory factory = b.build(config);	
		b.removeTable(factory, tableMetas[0].getName());
		
		factory.destory();

		System.out.println("------------------------end TestBus.dropOneTable()----------------------------");
    }
    
//    private List<String[]> createRecords(int count) {
//    	
//    	List<String[]> records = new ArrayList<>();
//		for (int j = 0; j < 10000; j++) {
//			String[] record = { String.valueOf(j), "col"+j, String.valueOf(j*.1), String.valueOf(true) };	
//			records.add(record)	;				
//		}	
//    	return records;
//    }
//    

    
    @Test
    public void insert10000Records() throws RedissonDBException {
    	System.out.println("------------------------start TestBus.insert10000Records()----------------------------");

		Buffer session = TEST_FACTORY.openSession(false);
		//session.delete(TEST_TABLE_MATA);
		
		for (int j = 0; j < 10000; j++) {
			String[] record = { String.valueOf(j), "col"+j, String.valueOf(j*.1), String.valueOf(true) };	
			session.insert(TEST_TABLE_MATA.getName(), record);					
		}
		
		session.commit();
		session.close();	
 	
		System.out.println("------------------------end TestBus.insert10000Records()----------------------------");		
    }
    
    
    @Test
    public void insert100000Records() {
    	System.out.println("------------------------start TestBus.insert100000Records()----------------------------");   

		Buffer session = TEST_FACTORY.openSession(false);
		
	//	session.delete(TEST_TABLE_MATA);
		
		for (int j = 0; j < 100000; j++) {
			String[] record = { String.valueOf(j), "col"+j, String.valueOf(j*.1), String.valueOf(true) };	
			session.insert(TEST_TABLE_MATA.getName(), record);					
		}
		
		session.commit();

		session.close();	

 
		System.out.println("------------------------end TestBus.insert100000Records()----------------------------");		
    }
    
    @Test 
    public void selectOneRecord() {
    	System.out.println("------------------------start TestBus.selectOneRecord()----------------------------"); 

    	Buffer buffer = TEST_FACTORY.openSession();
    	Map<String, String> condMap = new HashMap<String, String>();
    	condMap.put("id", "1");
    	String[] record = buffer.selectOne(TEST_TABLE_MATA1.getName(), condMap);
    	System.out.println("Select one record : "+String.join(",", record));
    	
    	System.out.println("------------------------end TestBus.selectOneRecord()----------------------------");    	
    }
    
    @Test
    public void selectAllRecords() {
    	System.out.println("------------------------start TestBus.selectAllRecords()----------------------------");    
	
    	Buffer buffer = TEST_FACTORY.openSession();
    	
    	
    	List<String[]> records = buffer.selectList(TEST_TABLE_MATA1.getName(), null);
    	
    	System.out.println("Select all records : count = "+records.size());    
    	buffer.close();
         	
    	System.out.println("------------------------end TestBus.selectAllRecords()----------------------------");    	
    }

    @Test
    public void testOpenBuffer() {
    	System.out.println("------------------------start TestBus.testOpenBuffer()----------------------------");    	
    	Buffer buffer = TEST_FACTORY.openSession();
    	buffer.close();
    	System.out.println("------------------------end TestBus.testOpenBuffer()----------------------------");    	
    }
    
    static public int count = 0;
    @Test
   // @Repeat(100)
    public void insertOneRecord() throws RedissonDBException  {

    	System.out.println("------------------------start TestBus.insertOneRecord()----------------------------"+count++);    	
    	BufferConfig config = new BufferConfig();
		config.setName("myBuffer");
		config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
		config.setCreateFlag(BufferConfig.CREATE);
		
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		ColumnMeta [] columns = {new ColumnMeta("id", BufferFactoryBuilder.INT, true),
				new ColumnMeta("name", BufferFactoryBuilder.STRING, false),
				new ColumnMeta("doubleCol", BufferFactoryBuilder.DOUBLE, false),
				new ColumnMeta("booleanCol", BufferFactoryBuilder.BOOLEAN, false)};
		TableMeta tableMeta = new TableMeta().setName("MyTable1").setColumns(Arrays.asList(columns));
		config.setTableMetas(new TableMeta[]{tableMeta});
		BufferFactory factory = b.build(config);
		
		Buffer session = factory.openSession(true);
		
		String[] record = { "1", "col", String.valueOf(.1), String.valueOf(true) };

		
		session.insert(tableMeta.getName(), record);
		
		session.close();
		
		factory.destory();
		b.removeBuffer(factory);
		System.out.println("------------------------end TestBus.insertOneRecord()----------------------------"+count);	

    }
    
    
	@AfterClass
	public static void destory() throws RedissonDBException {
		System.out.println("------------------------start TestBus.destory()----------------------------");

		BufferFactoryBuilder b = new BufferFactoryBuilder();
		b.removeBuffer(TEST_FACTORY);

		System.out.println("------------------------end TestBus.destory()----------------------------");
	}
}
