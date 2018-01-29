package com.znd.test;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.junit.Test;

import com.ZhongND.RedisDataBus.ServiceFactory;
import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RBufferBuilder;
import com.ZhongND.RedisDataBus.Api.RMemDBApi;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.ZhongND.RedisDataBus.Api.RTableBuilder;
import com.ZhongND.RedisDataBus.Api.RTableOperation;
import com.ZhongND.RedisDataBus.Enum.RedisTableColumnType;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;


public class TestBus {
	
	static private DFService service;
	static public String applicationName = "pr";
	static public RMemDBApi memDBApi; 
	
	static {
		try {
			service = ServiceFactory.getService();
			memDBApi = service.connect(applicationName);
			
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}	
	}
	
	
	private List<RMemDBBuilder> createBuffers(String [] bufferNames) throws RedissonDBException {
		List<RMemDBBuilder> builders = new ArrayList<>();
		List<String> succeeds = new ArrayList<>();
		List<String> fails = new ArrayList<>();
		try {
			for (String bufferName : bufferNames) {
				RMemDBBuilder builder = memDBApi.getRMemDBBuilder(bufferName);
				if (!builder.checkAvailability()) {	
					//创建buffer
					builder.getBufferBuilder();
					succeeds.add(bufferName);
				
				} else {
					fails.add(bufferName);
				}
				
				builders.add(builder);
			}
		} finally {
			System.out.println(String.format("Create buffer , request:%d, succeed:%d, fail:%d.", bufferNames.length, succeeds.size(), fails.size()));	
		}
				
		return builders;
	}
	

	
	private void destoryBuffers(List<RMemDBBuilder> buffers) throws RedissonDBException {
		for (RMemDBBuilder buffer : buffers) {
			buffer.destory();
		}
	}
	
	private RMemDBBuilder createBuffer(String  bufferName) throws RedissonDBException {
		return createBuffers(new String[] { bufferName}).get(0);
	}
	private void destoryBuffer(RMemDBBuilder buffer) throws RedissonDBException {
		buffer.destory();
	}
	
	@Test
	public void testCreateOneBuffer() throws RedissonDBException {
		createBuffers(new String[] {"myBuffer" });	
	}
	
	@Test
	public void testDestoryOneBuffer() throws RedissonDBException {
	   destoryBuffer(createBuffer("myBuffer"));
	}
	
	@Test
	public void testCreate100Buffer() throws RedissonDBException {
		int count = 100;
		
		
		String[] bufferNames = new String[count];
		for (int i = 0; i < count; i++) {
			bufferNames[i] = "myBuffer"+i;
		}
		createBuffers(bufferNames);	
	}
	
	@Test
	public void testDestory100Buffer() throws RedissonDBException {
		int count = 100;
		
		
		String[] bufferNames = new String[count];
		for (int i = 0; i < count; i++) {
			bufferNames[i] = "myBuffer"+i;
		}
		List<RMemDBBuilder> buffers = createBuffers(bufferNames);	
		destoryBuffers(buffers);
	}
	
	@Test
	public void testCreate1000Buffer() throws RedissonDBException {
		int count = 1000;
		
		
		String[] bufferNames = new String[count];
		for (int i = 0; i < count; i++) {
			bufferNames[i] = "myBuffer"+i;
		}
		createBuffers(bufferNames);	
	}
	
	@Test
	public void testDestory1000Buffer() throws RedissonDBException {
		int count = 1000;
		
		
		String[] bufferNames = new String[count];
		for (int i = 0; i < count; i++) {
			bufferNames[i] = "myBuffer"+i;
		}
		List<RMemDBBuilder> buffers = createBuffers(bufferNames);	
		destoryBuffers(buffers);
	}
	
	
	private RTableOperation createTable(RMemDBBuilder builder, String tableName) throws RedissonDBException {
		RBufferBuilder buffer  = builder.getBufferBuilder();
		
		if (!buffer.checkIsExists(tableName)) {
			RTableBuilder table = buffer.getTableBuilder(tableName);
			table.setColumn("id", RedisTableColumnType.RedisTableColumnType_long, true);
			table.setColumn("Long", RedisTableColumnType.RedisTableColumnType_long, false);
			table.setColumn("Double",RedisTableColumnType.RedisTableColumnType_double, false);
			table.setColumn("Int", RedisTableColumnType.RedisTableColumnType_int, false);
			buffer.commit();
			System.out.print(String.format("'%s'表已创建完毕!", tableName));
		} else {
			System.out.print(String.format("'%s'表已存在!", tableName));
		}
		
		
		RTableOperation ops =  builder.getBufferOperation().getTableOperation(tableName);
		List<String> columnNames = ops.getColumnNameArray();
		System.out.println(String.format("表列数量为%d : \n %s (%s)", columnNames.size(), String.join("|", columnNames)));
		return ops;
	}
	
	private void deleteTable(RBufferBuilder builder, String tableName) throws RedissonDBException {
		builder.destory(tableName);
	}
	
	private RTableOperation findOrCreateTable(String bufferName, String tableName) throws RedissonDBException {
		
		RMemDBBuilder builder = createBuffer(bufferName);

		RBufferBuilder buffer  = builder.getBufferBuilder();
		
		if (!buffer.checkIsExists(tableName)) {
			RTableBuilder table = buffer.getTableBuilder(tableName);
			table.setColumn("id", RedisTableColumnType.RedisTableColumnType_long, true);
			table.setColumn("Long", RedisTableColumnType.RedisTableColumnType_long, false);
			table.setColumn("Double",RedisTableColumnType.RedisTableColumnType_double, false);
			table.setColumn("Int", RedisTableColumnType.RedisTableColumnType_int, false);
			buffer.commit();
			System.out.println(String.format("'%s'表已创建完毕!", tableName));
		}				
	
		return builder.getBufferOperation().getTableOperation(tableName);
	}
	
//	@Test 
//	public void createOneRecord() throws RedissonDBException {
//		RMemDBBuilder builder = createBuffer("CommonBuffer");
//		RTableOperation tableOps = createTable(builder, "FState");
//		
//		String[] record = new String[colNames.size()];
//		String[] index = {String.valueOf(j)};
//		record[0] = index[0];
//		for (int i = 1; i < colNames.size(); i++) {
//			record[i] = String.valueOf(i);
//		}
//
//		table.setRecord(record, index);			
//	}
//	
//    @Test
//	public  void testCreateTable() throws RedissonDBException {
//		
//		RMemDBBuilder builder = createBuffer("CommonBuffer");
//		RTableOperation tableOps = createTable(builder, "FState");
//		
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
//	
//	}
//    
    @Test
    public void dropTable() throws RedissonDBException {
	
		RMemDBBuilder dbBuilder = memDBApi.getRMemDBBuilder("CommonBuffer");
		
		RBufferBuilder bufferBuilder  = dbBuilder.getBufferBuilder();
		String tableName = "testTable1";
		if (!bufferBuilder.checkIsExists(tableName)) {
			RTableBuilder tableBuilder = bufferBuilder.getTableBuilder(tableName);
			tableBuilder.setColumn("id", RedisTableColumnType.RedisTableColumnType_long, true);
			tableBuilder.setColumn("Long", RedisTableColumnType.RedisTableColumnType_long, false);
			tableBuilder.setColumn("Double",RedisTableColumnType.RedisTableColumnType_double, false);
			tableBuilder.setColumn("Int", RedisTableColumnType.RedisTableColumnType_int, false);
			bufferBuilder.commit();
			System.out.println("表已创建完毕, tableName="+tableName);
			bufferBuilder.destory(tableName);
			
			System.out.println("表已创建完毕, tableName="+tableName);
			
		} else {
			System.out.println("无法创建表，表已存在"+tableName);
		}		
    }
    
    @Test
    public void testBatch10000Records() {
    	
    }
}
