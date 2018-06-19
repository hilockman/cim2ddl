package com.znd.bus.common.buffer;

import java.util.List;

import com.znd.bus.common.MapperInterface;
import com.znd.bus.common.model.CalcJob;

public interface CalcJobBuffer extends MapperInterface<CalcJob> {

	CalcJob findByName(String name);

	List<CalcJob> findByModel(String modelId);

}
