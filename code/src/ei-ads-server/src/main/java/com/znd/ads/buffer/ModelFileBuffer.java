package com.znd.ads.buffer;

import java.util.List;

import com.znd.bus.common.model.ModelFile;
import com.znd.bus.operations.Operations;

public interface ModelFileBuffer  extends Operations<ModelFile> {
//	void save(ModelFile info);
	//void delete(ModelFile info);
	//void deleteById(String id);
	//List<ModelFile> findAll();
	void deleteByModel(String modelId); 
	List<ModelFile> findBy(String modelId); 
}
