package com.znd.test;

import java.io.IOException;
import java.util.List;
import java.util.Map;

public class BufferSessionImp implements BufferSession {
	@Override
	public void close() throws IOException {
		// TODO Auto-generated method stub
		
	}

	@Override
	public <T> T selectOne(String statement, Object parameter) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public <E> List<E> selectList(String statement, Object parameter) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public <K, V> Map<K, V> selectMap(String statement, Object parameter,
			String mapKey) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int insert(String statement, Object parameter) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int update(String statement, Object parameter) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int delete(String statement, Object parameter) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public <T> T selectOne(String statement) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public <E> List<E> selectList(String statement) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public <K, V> Map<K, V> selectMap(String statement, String mapKey) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int insert(String statement) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int update(String statement) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int delete(String statement) {
		// TODO Auto-generated method stub
		return 0;
	}

}
