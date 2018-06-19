package com.znd.ads.service;

import java.util.List;

import com.znd.ads.model.ModelData;
import com.znd.ads.model.po.ModelSource;

public interface ModelService {

	 List getAll();

	List getRoots();
	

	void upload(ModelData model);

	void remove(String name);

	ModelSource findModel(String modelId);

}
