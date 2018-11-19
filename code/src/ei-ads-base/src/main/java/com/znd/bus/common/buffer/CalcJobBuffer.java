package com.znd.bus.common.buffer;

import java.util.List;

import com.znd.bus.common.model.CalcJob;
import com.znd.bus.operations.Operations;

public interface CalcJobBuffer extends Operations<CalcJob> {

	CalcJob findByName(String name);

	List<CalcJob> findByModel(String modelId);

}
