package com.znd.bus.common.buffer;

import java.util.List;

import com.znd.bus.common.model.ModelFile;

public interface ModelFileBuffer {
	void save(ModelFile info);
	//void delete(ModelFile info);
	void deleteById(String id);
	List<ModelFile> findAll();
	void deleteByModel(String modelId); 
	List<ModelFile> findBy(String modelId); 
}
