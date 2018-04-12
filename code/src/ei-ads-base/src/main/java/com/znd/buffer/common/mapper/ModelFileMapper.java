package com.znd.buffer.common.mapper;

import java.util.List;

import com.znd.buffer.common.model.ModelFile;

public interface ModelFileMapper {
	void save(ModelFile info);
	void delete(ModelFile info);
	void deleteById(String id);
	List<ModelFile> findAll();
}
