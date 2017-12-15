package com.znd.ei.ads.web.model;

import org.springframework.web.multipart.MultipartFile;

import com.znd.ei.ads.config.PRAdequacySetting;

public class ReliabilityUploadConfig    {

    private String modelName;

    private MultipartFile[] files;
    

    private String setting;

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

	public String getSetting() {
		return setting;
	}

	public void setSetting(String setting) {
		this.setting = setting;
	}


}
