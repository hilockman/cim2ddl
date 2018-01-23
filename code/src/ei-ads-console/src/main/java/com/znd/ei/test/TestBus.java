package com.znd.ei.test;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.ZhongND.RedisDataBus.ServiceFactory;
import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RBufferBuilder;
import com.ZhongND.RedisDataBus.Api.RBufferOperation;
import com.ZhongND.RedisDataBus.Api.RMemDBApi;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.ZhongND.RedisDataBus.Api.RTableBuilder;
import com.ZhongND.RedisDataBus.Api.RTableOperation;
import com.ZhongND.RedisDataBus.Enum.RedisTableColumnType;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;


public class TestBus {
	public static void main(String[] args) throws RedissonDBException {
		DFService service = ServiceFactory.getService();
		RMemDBApi api = service.connect("pr");

		RMemDBBuilder builder = api.getRMemDBBuilder("CommonBuffer");
		RBufferBuilder buffer = null;
		if (!builder.checkAvailability()) {
			buffer = builder.getBufferBuilder();
			if (!buffer.checkIsExists("FState")) {
				RTableBuilder table = buffer.getTableBuilder("FState");
				table.setColumn("id", RedisTableColumnType.RedisTableColumnType_long, true);
				table.setColumn("Long", RedisTableColumnType.RedisTableColumnType_long, false);
				table.setColumn("Double",RedisTableColumnType.RedisTableColumnType_double, false);
				table.setColumn("Int", RedisTableColumnType.RedisTableColumnType_int, false);
				buffer.commit();
				System.out.println("表已创建完毕");

			} else {
				System.out.println("无法创建表，表已存在");
			}
		} 
		
		//insert records
		RBufferOperation bufferOps = builder.getBufferOperation();
		RTableOperation table = bufferOps.getTableOperation("FState");
		List<String> colNames = table.getColumnNameArray();
		for (int j = 0; j < 100; j++) {
		String[] record = new String[colNames.size()];
		String[] index = {String.valueOf(j)};
		record[0] = index[0];
		for (int i = 1; i < colNames.size(); i++) {
			record[i] = String.valueOf(i);
		}

		table.setRecord(record, null);
		
		

		System.out.println("插入记录成功！"+j);
		}
		
		
		//read records
		colNames = table.getColumnNameArray();
		Map<String, String> conditions = new HashMap<String, String>();
		String key = "String";
		String value = "1";
		conditions.put(key, value);
		List<String> list = table.getCell(colNames.get(0), conditions);
		System.out.println("get value：" + list.toString());
		table.setCell(colNames.get(0), String.valueOf(10), conditions);
		list = table.getCell(colNames.get(0), conditions);
		System.out.println("get new value：" + list.toString());

		
		builder.destory();
		service.disConnect();
	}
}
