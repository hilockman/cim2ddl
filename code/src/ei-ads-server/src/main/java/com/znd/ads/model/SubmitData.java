package com.znd.ads.model;

import org.springframework.web.multipart.MultipartFile;

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
