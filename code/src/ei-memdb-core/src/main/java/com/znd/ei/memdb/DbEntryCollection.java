package com.znd.ei.memdb;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import org.springframework.stereotype.Component;

import com.ZhongND.memdb.MDBDefine;

/**
 * 内存数据库集合
 * @author wangheng
 *
 */
@Component
public class DbEntryCollection extends DbComponent {

	private List<DbEntry> dbEntrys = new ArrayList<DbEntry>();
	private Map<String, String> dbName2dbDesc = new HashMap<String, String>();
	public DbEntryCollection() {
		for (int i = 0; i < MDBDefine.g_strDBEntryArray.length; i++) {
			dbName2dbDesc.put(MDBDefine.g_strDBEntryArray[i], MDBDefine.g_strDBEntryDespArray[i]);
		}
	}
	@Override
	public void add(DbComponent component) throws DbException {
		if (component == null)
			return;

		if (!(component instanceof DbEntry)) {
			throw new DbException(component.getClass() + " is not "
					+ DbEntry.class);
		}
		
		dbEntrys.add((DbEntry) component);
	}

	public void remove(DbComponent component) throws DbException {
		if (component == null)
			return;
		
		if (!(component instanceof DbEntry)) {
			throw new DbException(component.getClass() + " is not "
					+ DbEntry.class);
		}
		
		int index = dbEntrys.indexOf(component);		
		if (index < 0)
			throw new DbException("Cann't find such entry ");
		
		throw new UnsupportedOperationException();
	}

	@Override
	public DbComponent getChild(int i) throws DbException {
		if (i < 0 || dbEntrys.size() <= i)
			throw new DbException("Out of bounds :  "+dbEntrys.size());
		
		return dbEntrys.get(i);
	}

	public String getName() {
		return "DbEntryCollection";
	}

	public String getDescription() {
		return getName();
	}

	public void print() {
		System.out.println("DbEntryCollection : size="+dbEntrys.size());
	}

	public Iterator<?> createIterator() {
		return new DbComponentIterator(dbEntrys.iterator());
	}
	
	public DbEntry createDbEntry(String name) throws DbException {
		if (!dbName2dbDesc.containsKey(name)) {
			throw new DbException("Invalid entry name :  "+name+String.format(", name must be in (%s)", String.join(",", dbName2dbDesc.keySet())));
		}
		
		Connection conn  = new Connection(name, dbName2dbDesc.get(name));
		DbEntry entry = new DbEntry(conn);
		dbEntrys.add(entry);
		return entry;
	}
	
	public DbEntry findDbEntry(String name) {
		for (DbEntry e : dbEntrys) {
			if (e.getName().compareToIgnoreCase(name) == 0) {
				return e;
			}
			
		}
		
		return null;
	}
	
	public DbEntry findOrCreateDbEntry(String name) throws DbException {
		DbEntry e = findDbEntry(name);
		if (e != null)
			return e;
		
		return createDbEntry(name);
	}
}
