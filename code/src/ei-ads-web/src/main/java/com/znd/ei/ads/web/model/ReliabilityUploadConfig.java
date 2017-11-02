package com.znd.ei.ads.web.model;

import org.springframework.web.multipart.MultipartFile;

public class ReliabilityUploadConfig {

    private String modelName;

    private MultipartFile[] files;
    
    private String sampleConfig;
    private String estimateConfig;


	public MultipartFile[] getFiles() {
		return files;
	}

	public void setFiles(MultipartFile[] files) {
		this.files = files;
	}

	public String getSampleConfig() {
		return sampleConfig;
	}

	public void setSampleConfig(String sampleConfig) {
		this.sampleConfig = sampleConfig;
	}

	public String getEstimateConfig() {
		return estimateConfig;
	}

	public void setEstimateConfig(String estimateConfig) {
		this.estimateConfig = estimateConfig;
	}

	public String getModelName() {
		return modelName;
	}

	public void setModelName(String modelName) {
		this.modelName = modelName;
	}

}
