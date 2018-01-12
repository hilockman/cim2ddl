package com.znd.ei.memdb;

import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

import javax.annotation.PostConstruct;

public class AbstractTableOperations<T> implements
		MemTableOperations<T> {
	private DbEntryOperations dbEntryOps;

	private MetaTable table;

	private Class<?> clazz;

	private Field memIndexField;
	private FieldInfo[] fieldInfos;

	public AbstractTableOperations(Class<T> clazz,
			DbEntryOperations dbEntryOps) {
		this.clazz = clazz;
		this.dbEntryOps = dbEntryOps;

	}

	@PostConstruct
	public void init() throws NoSuchMethodException, SecurityException, DbException {
		String className = clazz.getSimpleName();
		table = dbEntryOps.findTableByName(className);
		if (table == null) {
			throw new DbException("Find no table by class name : " + className);
		}
		Field[] fields = clazz.getDeclaredFields();
		fieldInfos = new FieldInfo[fields.length];

		int fieldNum = fields.length;
		for (int i = 0; i < fieldNum; i++) {
			Field f = fields[i];
			String name = f.getName();
			if (name.compareToIgnoreCase(DbEntry.MEM_INDEX_COLUMN_NAME) == 0) {
//				fields[i] = null;
				memIndexField = f;
				break;
			}
		}
		for (int i = 0; i < fieldNum; i++) {
			Field f = fields[i];
//			if (f == null)
//				continue;

			FieldInfo fieldInfo = new FieldInfo();
			f.setAccessible(true);
			fieldInfo.setField(f);
			String name = f.getName();
			MetaField mf = table.findFieldByName(name);
			fieldInfo.setMemField(mf);

			Class<?> fzz = f.getType();
			if (fzz == Short.class) {
				fieldInfo.setValueParser(ValueParse.Short_Parser);
			} else if (fzz == Double.class) {
				fieldInfo.setValueParser(ValueParse.Double_Parse);
			} else if (fzz == Integer.class) {
				fieldInfo.setValueParser(ValueParse.Integer_Parser);
			} else if (fzz == Float.class) {
				fieldInfo.setValueParser(ValueParse.Float_Parse);
			}

			fieldInfos[i] = fieldInfo;
		}

	}



	private String[] getTemplateRecord() {
		String[] strs = new String[table.getFields().size()];
		Arrays.fill(strs, "");
		return strs;
	}

	private void setMemIndex(Object obj, Integer id) {
		if (memIndexField == null)
			return;
		try {
			memIndexField.set(obj, id);
		} catch (IllegalArgumentException | IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private Integer getMemIndex(Object obj) {
		if (memIndexField == null)
			return null;
		try {
			return (Integer) memIndexField.get(obj);
		} catch (IllegalArgumentException | IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}
	
	/**
	 * Saves a given entity. Use the returned instance for further operations as
	 * the save operation might have changed the entity instance completely.
	 * 
	 * @param entity
	 * @return the saved entity
	 */
	public <S extends T> S saveOrUpdate(S entity) {
		List<S> entities = new ArrayList<S>();
		entities.add(entity);
		saveOrUpdate(entities);
		return entities.get(0);
	}
	
	@SuppressWarnings({ "rawtypes", "unchecked" })
	@Override
	public <S extends T> Iterable<S> saveOrUpdate(Iterable<S> entities) {
		if (entities == null)
			return null;
		
		List<String[]> newRecords = new ArrayList<String[]>();
		List<String[]> updateRecords = new ArrayList<String[]>();
		Iterator it = entities.iterator();
		try {
			List<S> newObjects = new ArrayList<S>(); 
			List<S> updateObjects  = new ArrayList<S>();
			
			while (it.hasNext()) {
				S entity = (S) it.next();

				String[] values = getTemplateRecord();

				for (FieldInfo f : fieldInfos) {
			
					if (f == null)
						continue;
						
					MetaField mfield = f.getMemField();
					if (mfield == null)
						continue;

					Field field = f.getField();
					if (field == null)
						continue;

					Object value = f.getField()
					.get(entity);
					if (value == null)
						continue;
					
					values[mfield.getIndex()] = value.toString();
				}
				
				Integer index = getMemIndex(entity);

				if (index != null) {
					updateRecords.add(values);
					updateObjects.add(entity);	
				} else {
					newRecords.add(values);
					newObjects.add(entity);					
				}

			}



			List<Integer> rowIndexes = dbEntryOps.saveRecords(table, newRecords);
			for (int i = 0; i < rowIndexes.size(); i++) {
				S e = newObjects.get(i);
				setMemIndex(e, rowIndexes.get(i));
			}
			
			
			dbEntryOps.updateRecords(table, updateRecords);
			
		} catch (DbException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return entities;
	}

	@SuppressWarnings({ "unchecked", "rawtypes" })
	@Override
	public List<T> findAll() {
		List entities = new ArrayList<T>();
		try {
			List<String[]> records = dbEntryOps.findAllRecords(table);
			for (int i = 0; i < records.size(); i++) {

				T entity = (T) clazz.newInstance();
				setMemIndex(entity, i);
				for (int j = 0; j < fieldInfos.length; j++) {
					FieldInfo f = fieldInfos[j];
					if (f == null)
						continue;

					MetaField mfield = f.getMemField();
					if (mfield == null)
						continue;

					Field field = f.getField();
					if (field == null)
						continue;

					String[] values = records.get(i);

					String value = values[mfield.getIndex()];
					field.set(entity, f.toObject(value));
				}

				entities.add(entity);
			}
		} catch (DbException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return entities;
	}

	@Override
	public long count() {
		return dbEntryOps.getRecordCount(table);
	}

	@Override
	public void delete(T entity) {
		String[] record = null;
		try {
			dbEntryOps.deleteRecord(table, record);
		} catch (DbException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	public void delete(Iterable<? extends T> entities) {
		// TODO Auto-generated method stub

	}

	@Override
	public void deleteAll() {
		dbEntryOps.clearTable(table);
	}

	public DbEntryOperations getMemDbRepository() {
		return dbEntryOps;
	}

	public void setMemDbRepository(DbEntryOperations memDbRepository) {
		this.dbEntryOps = memDbRepository;
	}
}



class FieldInfo {
	public FieldInfo() {
		super();
		// TODO Auto-generated constructor stub
	}

	private Field field;
	private MetaField memField;

	@SuppressWarnings("rawtypes")
	private ValueParse valueParser;

	public Field getField() {
		return field;
	}

	public void setField(Field field) {
		this.field = field;
	}

	public MetaField getMemField() {
		return memField;
	}

	public void setMemField(MetaField memField) {
		this.memField = memField;
	}

	@SuppressWarnings("rawtypes")
	public ValueParse getValueParser() {
		return valueParser;
	}

	@SuppressWarnings("rawtypes")
	public void setValueParser(ValueParse valueParser) {
		this.valueParser = valueParser;
	}
	
	public Object toObject(String value) {
		if (valueParser == null)
			return value;
		else
			return valueParser.toObject(value);
	}

}
