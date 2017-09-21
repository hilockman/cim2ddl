package com.znd.ei.memdb.dao;

import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import javax.annotation.PostConstruct;


public abstract class AbstractMemTableRepository<T> implements
		MemTableRepository<T> {
	private MemDbRepository memDbRepository;

	private MemTable table;

	private Class clazz;

	private FieldInfo[] fieldInfos;

	public AbstractMemTableRepository(Class<T> clazz) {
		this.clazz = clazz;

	}

	@PostConstruct
	public void init() throws NoSuchMethodException, SecurityException {
		String className = clazz.getSimpleName();
		table = memDbRepository.findTableByName(className);
		if (table == null) {
			System.out.println("Find no table by class name : " + className);
		}
		Field[] fields = clazz.getDeclaredFields();
		fieldInfos = new FieldInfo[fields.length];

		int fieldNum = fields.length;
		for (int i = 0; i < fieldNum; i++) {
			Field f = fields[i];
			String name = f.getName();
			if (name.compareToIgnoreCase("id") == 0) {
				fields[i] = null;
				break;
			}
		}
		for (int i = 0; i < fieldNum; i++) {
			Field f = fields[i];
			if (f == null)
				continue;

			String name = f.getName();

			StringBuffer sb = new StringBuffer();
			sb.append("set").append(name.substring(0, 1).toUpperCase())
					.append(name.substring(1));
			StringBuffer sb1 = new StringBuffer();
			sb1.append("get").append(name.substring(0, 1).toUpperCase())
					.append(name.substring(1));

			FieldInfo fieldInfo = new FieldInfo();
			f.setAccessible(true);

			if (table != null)
				fieldInfo.setMemField(table.findFieldByName(name));
			
			fieldInfo.setField(f);

			Class fzz = f.getType();
			
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

	/**
	 * Saves a given entity. Use the returned instance for further operations as
	 * the save operation might have changed the entity instance completely.
	 * 
	 * @param entity
	 * @return the saved entity
	 */
	public <S extends T> S save(S entity) {
		List<S> entities = new ArrayList<S>();
		entities.add(entity);
		save(entities);
		return entities.get(0);
	}

	private String[] getTemplateRecord() {
		return new String[table.getFields().size()];
	}

	@Override
	public <S extends T> Iterable<S> save(Iterable<S> entities) {
		List<String[]> records = new ArrayList<String[]>();
		Iterator it = entities.iterator();
		try {
			while (it.hasNext()) {
				S entity = (S) it.next();

				String[] values = getTemplateRecord();

				for (int i = 0; i < fieldInfos.length; i++) {
					FieldInfo f = fieldInfos[i];
					MemField mfield = f.getMemField();
					if (mfield == null)
						continue;

					Field field = f.getField();
					if (field == null)
						continue;

					values[f.getMemField().getIndex()] = f.getField()
							.get(entity).toString();
				}

			}

			memDbRepository.saveRecords(table, records);
		} catch (MemDbError e) {
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
	public Iterable<T> findAll() {
		List entities = new ArrayList<T>();
		try {
			List<String []> records = memDbRepository.findAllRecords(table);
			for (int i = 0; i < records.size(); i++) {
				
				T entity = (T)clazz.newInstance();
				for (int j = 0; j < fieldInfos.length; j++) {
					FieldInfo f = fieldInfos[j];
					if (f == null)
						continue;
					
					MemField mfield = f.getMemField();
					if (mfield == null)
						continue;

					Field field = f.getField();
					if (field == null)
						continue;

					String[] values = records.get(i);
					
					String value = values[f.getMemField().getIndex()];
					field.set(entity, f.toObject(value));
				}		
				
				entities.add(entity);
			}
		} catch (MemDbError e) {
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
		return memDbRepository.getRecordCount(table);
	}

	@Override
	public void delete(T entity) {
		// TODO Auto-generated method stub

	}

	@Override
	public void delete(Iterable<? extends T> entities) {
		// TODO Auto-generated method stub

	}

	@Override
	public void deleteAll() {
		// TODO Auto-generated method stub

	}
}
