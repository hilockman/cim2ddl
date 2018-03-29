package com.znd.bus.task;

import java.util.List;

public interface CalcJobMapper {
	void save(CalcJob info);
	void delete(CalcJob info);
	List<CalcJob> findAll();
}
