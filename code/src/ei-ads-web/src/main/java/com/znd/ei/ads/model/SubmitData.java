package com.znd.ei.ads.model;

import org.springframework.web.multipart.MultipartFile;

import com.znd.ads.model.PRAdequacySetting;

public class SubmitData extends PRAdequacySetting  {

    private String modelName;

    private MultipartFile[] files;
    

	public MultipartFile[] getFiles() {
		return files;
	}

	public void setFiles(MultipartFile[] files) {
		this.files = files;
	}



	public String getModelName() {
		return modelName;
	}

	public void setModelName(String modelName) {
		this.modelName = modelName;
	}

}
