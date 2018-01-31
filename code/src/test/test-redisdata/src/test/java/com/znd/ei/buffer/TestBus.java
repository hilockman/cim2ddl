package com.znd.ei.buffer;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.znd.ei.buffer.BufferConfig;
import com.znd.ei.buffer.BufferFactory;
import com.znd.ei.buffer.BufferFactoryBuilder;
import com.znd.ei.buffer.Buffer;
import com.znd.ei.buffer.ColumnMeta;
import com.znd.ei.buffer.TableMeta;

@RunWith(SpringRunner.class)
@SpringBootTest
public class TestBus {
	
	public static TableMeta TEST_TABLE_MATA;
	public static TableMeta TEST_TABLE_MATA1;
	public static BufferFactory TEST_FACTORY;

	static {
    	BufferConfig config = new BufferConfig();
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
		
		
		try {
			BufferFactoryBuilder b = new BufferFactoryBuilder();
			TEST_FACTORY = b.build(config);
			
			
			Buffer session = TEST_FACTORY.openSession(false);
			//session.delete(TEST_TABLE_MATA);
			
			for (int j = 0; j < 10000; j++) {
				String[] record = { String.valueOf(j), "col"+j, String.valueOf(j*.1), String.valueOf(true) };	
				session.insert(TEST_TABLE_MATA.getName(), record);					
			}
			
			for (int j = 0; j < 10; j++) {
				String[] record = new String[TEST_TABLE_MATA1.getColumnSize()];
				record[0] = String.valueOf(j);
				for (int k = 1; k < TEST_TABLE_MATA1.getColumnSize(); k++) {
					record[k] = "col_"+j+"_"+k;
				}
				session.insert(TEST_TABLE_MATA1.getName(), record);
			}
			
			session.commit();
			session.close();
			
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
	}


	@Test
	public void insertOneBuffer() throws RedissonDBException {
		BufferConfig config = new BufferConfig();
		config.setName("myBuffer");
		config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
		config.setCreateFlag(BufferConfig.CREATE);
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		b.build(config);
	}
	
	@Test
	public void destoryOneBuffer() throws RedissonDBException {
		BufferConfig config = new BufferConfig();
		config.setName("myBuffer");
		config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
		config.setCreateFlag(BufferConfig.FALSE);
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		b.build(config);
		
		b.removeBuffer(b.build(config));
	}
	
	//@Test
	public void create10Buffers() throws RedissonDBException {
		int count = 10;
		
		
		for (int i = 0; i < count; i++) {
			BufferConfig config = new BufferConfig();
			config.setName("myBuffer"+i);
			config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
			config.setCreateFlag(BufferConfig.CREATE);
			
			BufferFactoryBuilder b = new BufferFactoryBuilder();
			b.build(config);
		}

	}
	
	@Test
	public void destory10Buffer() throws RedissonDBException {
		int count = 10;
		
		for (int i = 0; i < count; i++) {
			BufferConfig config = new BufferConfig();
			config.setName("myBuffer"+i);
			config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
			config.setCreateFlag(BufferConfig.FALSE);
			BufferFactoryBuilder b = new BufferFactoryBuilder();
			BufferFactory factory = b.build(config);
			b.removeBuffer(factory);
		}
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
		
		BufferConfig config = new BufferConfig();
		config.setName("myBuffer");
		config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
		config.setCreateFlag(BufferConfig.CREATE);
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		ColumnMeta [] columns = {new ColumnMeta("id", BufferFactoryBuilder.INT, true),
				new ColumnMeta("name", BufferFactoryBuilder.STRING, true),
				new ColumnMeta("doubleCol", BufferFactoryBuilder.DOUBLE, true),
				new ColumnMeta("booleanCol", BufferFactoryBuilder.BOOLEAN, true)};
		TableMeta[] tableMetas = {new TableMeta().setName("MyTable").setColumns(Arrays.asList(columns))};
		config.setTableMetas(tableMetas);
		b.build(config).destory();
			
	}
    
    @Test
	public  void createTable() throws RedissonDBException {
		
		BufferConfig config = new BufferConfig();
		config.setName("myBuffer");
		config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
		config.setCreateFlag(BufferConfig.CREATE);
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		ColumnMeta [] columns = {new ColumnMeta("id", BufferFactoryBuilder.INT, true),
				new ColumnMeta("name", BufferFactoryBuilder.STRING, true),
				new ColumnMeta("doubleCol", BufferFactoryBuilder.DOUBLE, true),
				new ColumnMeta("booleanCol", BufferFactoryBuilder.BOOLEAN, true)};
		TableMeta[] tableMetas = {new TableMeta().setName("MyTable").setColumns(Arrays.asList(columns))};
		config.setTableMetas(tableMetas);
		b.build(config).destory();
			
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
    }
    
    private List<String[]> createRecords(int count) {
    	
    	List<String[]> records = new ArrayList<>();
		for (int j = 0; j < 10000; j++) {
			String[] record = { String.valueOf(j), "col"+j, String.valueOf(j*.1), String.valueOf(true) };	
			records.add(record)	;				
		}	
    	return records;
    }
    
    @Test
    public void create10000Records() {
    	createRecords(10000);
    }
    
    @Test
    public void insert10000Records() throws RedissonDBException {
    	
		Buffer session = TEST_FACTORY.openSession(false);
		//session.delete(TEST_TABLE_MATA);
		
		for (int j = 0; j < 10000; j++) {
			String[] record = { String.valueOf(j), "col"+j, String.valueOf(j*.1), String.valueOf(true) };	
			session.insert(TEST_TABLE_MATA.getName(), record);					
		}
		
		session.commit();

		session.close();	
    }
    
    
    @Test
    public void insert100000Records() throws RedissonDBException {
    	
		Buffer session = TEST_FACTORY.openSession(false);
		
	//	session.delete(TEST_TABLE_MATA);
		
		for (int j = 0; j < 100000; j++) {
			String[] record = { String.valueOf(j), "col"+j, String.valueOf(j*.1), String.valueOf(true) };	
			session.insert(TEST_TABLE_MATA.getName(), record);					
		}
		
		session.commit();

		session.close();	
    }
    
    @Test 
    public void selectOneRecord() {
    	Buffer buffer = TEST_FACTORY.openSession();
    	buffer.selectList(TEST_TABLE_MATA1.getName(), null);
    }
    
    @Test
    public void insertOneRecord() throws RedissonDBException {
    	BufferConfig config = new BufferConfig();
		config.setName("myBuffer");
		config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
		config.setCreateFlag(BufferConfig.UPDATE);
		
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		ColumnMeta [] columns = {new ColumnMeta("id", BufferFactoryBuilder.INT, true),
				new ColumnMeta("name", BufferFactoryBuilder.STRING, true),
				new ColumnMeta("doubleCol", BufferFactoryBuilder.DOUBLE, true),
				new ColumnMeta("booleanCol", BufferFactoryBuilder.BOOLEAN, true)};
		TableMeta tableMeta = new TableMeta().setName("MyTable1").setColumns(Arrays.asList(columns));
		config.setTableMetas(new TableMeta[]{tableMeta});
		BufferFactory factory = b.build(config);
		
		Buffer session = factory.openSession(true);
		
		String[] record = { "1", "col", String.valueOf(.1), String.valueOf(true) };

		
		session.insert(tableMeta.getName(), record);
		
		session.close();
		
		factory.destory();		
    }
}
