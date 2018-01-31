package com.znd.ei.buffer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.ServiceFactory;
import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RBufferBuilder;
import com.ZhongND.RedisDataBus.Api.RBufferOperation;
import com.ZhongND.RedisDataBus.Api.RMemDBApi;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.ZhongND.RedisDataBus.Api.RTableBuilder;
import com.ZhongND.RedisDataBus.Enum.RedisTableColumnType;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.znd.ei.buffer.imp.BufferFactoryImp;

public class BufferFactoryBuilder {

	public static final String DEFAULT_APPNAME = "pr";
	public static final String DEFAULT_BUFFERNAME = "CommonBuffer";
	private final Logger logger = LoggerFactory.getLogger(BufferFactoryBuilder.class);

	public static BufferConfig getDefaultConfig() {
		BufferConfig config = new BufferConfig();
		config.setAppName(DEFAULT_APPNAME);
		config.setName(DEFAULT_BUFFERNAME);
		return config;
	}

	private static final RedisTableColumnType[] types = {
			RedisTableColumnType.RedisTableColumnType_int,
			RedisTableColumnType.RedisTableColumnType_boolean,
			RedisTableColumnType.RedisTableColumnType_String,
			RedisTableColumnType.RedisTableColumnType_double,
			RedisTableColumnType.RedisTableColumnType_byte,
			RedisTableColumnType.RedisTableColumnType_float,
			RedisTableColumnType.RedisTableColumnType_long,
			RedisTableColumnType.RedisTableColumnType_short };

	public static final Integer INT = 0;
	public static final Integer BOOLEAN = 1;
	public static final Integer STRING = 2;
	public static final Integer DOUBLE = 3;
	public static final Integer BYTE = 4;
	public static final Integer FLOAT = 5;
	public static final Integer LONG = 6;
	public static final Integer SHORT = 7;

	private void makeTable(RBufferBuilder bufferBuilder, TableMeta tableDefine)
			throws RedissonDBException {
		if (bufferBuilder.checkIsExists(tableDefine.getName()))
			return;	
		
		RTableBuilder tableBuilder = bufferBuilder.getTableBuilder(tableDefine
				.getName());
		

		
		for (ColumnMeta c : tableDefine.getColumns()) {

			
			tableBuilder.setColumn(c.getName(), types[c.getType()],
					c.isIndexable());
		}

		logger.info("Table created: {}, clumn size = {}.",
				tableDefine.getName(), tableDefine.getColumnSize());
	}

//	private void rebuildTable(RMemDBBuilder memDBBuilder, List<TableMeta> changedTables) 
//			throws RedissonDBException {
//		// 创建bufferBuilder
//		RBufferBuilder bufferBuilder = memDBBuilder.getBufferBuilder();
//
//		for (TableMeta tableBuilder : changedTables) {
//			// 删除表
//			bufferBuilder.destory(tableBuilder.getName());
//			logger.info("Removed  RBufferTable:{}.", tableBuilder.getName());
//	
//			// 创建表
//			makeTable(bufferBuilder, tableBuilder);
//		}
//		
//		//commit
//		bufferBuilder.commit();
//	}

	private void removeBuffer(RMemDBBuilder memDBBuilder)
			throws RedissonDBException {
		memDBBuilder.destory();
	}

	private void makeBuffer(BufferConfig config, RMemDBBuilder memDBBuilder,
			TableMeta[] tableBuilders) throws RedissonDBException {
		
		// 创建buffer
		RBufferBuilder bufferBuilder = memDBBuilder.getBufferBuilder();
		logger.info("Buffer created : {}.{}.", config.getAppName(),
				config.getName());
		try {
			if (tableBuilders != null && tableBuilders.length > 0){		
				// 创建表
				for (TableMeta tableBuilder : tableBuilders) {
					makeTable(bufferBuilder, tableBuilder);
				}
			}
		} finally {
			// commit
			bufferBuilder.commit();
		}
	}

	// 判断表示否改变
	private boolean isTableChanged(List<String> columnNames,
			TableMeta tableBuilder) {
		List<ColumnMeta> columns = tableBuilder.getColumns();
		Collections.sort(columns, (a, b) -> {
			return a.getName().compareTo(b.getName());
		});
		Collections.sort(columnNames);
		int i = 0, j = 0;
		for (; i < columns.size() && j < columnNames.size();) {

			int c = columns.get(i).getName().compareTo(columnNames.get(j));
			if (c == 0) {
				i++;
				j++;
				continue;
			} else if (c < 0) {
				return true;
			} else {
				return true;
			}

		}

		return i != j;
	}

	public BufferFactory build(BufferConfig config) throws RedissonDBException {
		
		DFService service = ServiceFactory.getService();
		RMemDBApi memDBApi = service.connect(config.getAppName());

		RMemDBBuilder memDBBuilder = memDBApi
				.getRMemDBBuilder(config.getName());
		TableMeta[] tableMetas = config.getTableMetas();
		if (!memDBBuilder.checkAvailability()) {
			makeBuffer(config, memDBBuilder, tableMetas);
		} else {
			if (config.getCreateFlag() == BufferConfig.UPDATE) {
				// check buffer define changed or not ?
				if (tableMetas != null && tableMetas.length > 0) {
					RBufferOperation bufferOperation = memDBBuilder
							.getBufferOperation();
					
					List<TableMeta> changedTables = new ArrayList<>();
					for (TableMeta tableMeta : tableMetas) {
						List<String> columnNames = (bufferOperation != null) ? bufferOperation
								.getTableNameArray() : new ArrayList<>();

						if (isTableChanged(columnNames, tableMeta)) {
							changedTables.add(tableMeta);
							
						}
					}
					
//					if (!changedTables.isEmpty()) {
//						rebuildTable(memDBBuilder, changedTables);
//					}
					
					if (!changedTables.isEmpty()) {
						// remove buffer
						removeBuffer(memDBBuilder);
						// make buffer
						makeBuffer(config, memDBBuilder, tableMetas);
					}
				}
			} else if (config.getCreateFlag() == BufferConfig.CREATE) {
				// remove buffer
				removeBuffer(memDBBuilder);
				// make buffer
				makeBuffer(config, memDBBuilder, tableMetas);
			}

		}

		return new BufferFactoryImp(config, service, memDBApi, memDBBuilder);
	}

//	private void clearBuffer(RMemDBBuilder memDBBuilder, String appName,
//			String name) throws RedissonDBException {
//		memDBBuilder.destory();
//		logger.info("Buffer destoryed : {}.{}", appName, name);
//
//	}

	public void removeBuffer(BufferFactory factory) throws RedissonDBException {
		BufferFactoryImp imp = (BufferFactoryImp) factory;
		factory.destory();
		imp.getMemDBBuilder().destory();
		logger.info("Buffer destoryed : {}.{}", imp.getConfig().getAppName(), imp.getConfig().getName());		
	}

//	public void clearBuffer(BufferConfig config) throws RedissonDBException {
//		DFService service = ServiceFactory.getService();
//		RMemDBApi memDBApi = service.connect(config.getAppName());
//		RMemDBBuilder memDBBuilder = memDBApi
//				.getRMemDBBuilder(config.getName());
//		clearBuffer(memDBBuilder, config.getAppName(), config.getName());
//	}

	public void removeTable(BufferFactory factory, String name) throws RedissonDBException {
		((BufferFactoryImp)factory).getMemDBBuilder().getBufferBuilder().destory(name); 
	}

}
