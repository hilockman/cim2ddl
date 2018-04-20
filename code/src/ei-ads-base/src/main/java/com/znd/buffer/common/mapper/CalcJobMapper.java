package com.znd.buffer.common.mapper;

import java.util.List;

import com.znd.buffer.common.model.CalcJob;

public interface CalcJobMapper {
	void save(CalcJob info);
	void delete(CalcJob info);
	void deleteByName(String name);
	List<CalcJob> findAll();
	CalcJob findByName(String name);
	void update(CalcJob info);
	CalcJob findById(String id);
}
