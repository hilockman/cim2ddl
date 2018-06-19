package com.znd.ads.model.dto;

import com.fasterxml.jackson.annotation.JsonAutoDetect;
import com.fasterxml.jackson.annotation.JsonAutoDetect.Visibility;
import com.fasterxml.jackson.annotation.JsonIgnoreProperties;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.znd.ads.annotation.Comment;
import com.znd.ads.annotation.ForeignColumn;

@Comment(name="reliability")
@JsonAutoDetect(fieldVisibility = Visibility.ANY, getterVisibility = Visibility.NONE, setterVisibility = Visibility.NONE)
@JsonIgnoreProperties(ignoreUnknown = true)
public class PRAdequacySetting {
	@Comment(alias="模型", group="模型", fk=@ForeignColumn(table="model_source", value="name"))
	private String modelId;
	
	@Comment(alias="解析法最小状态概率", group="抽样参数")
	@JsonProperty("ANAMinStateProb")
    private Double ANAMinStateProb = 1.0e-9;   
	 
	@JsonProperty("BpaDatFile")
	private String BpaDatFile = "";
	
	@JsonProperty("BpaRParamFile")
    private String BpaRParamFile = "";
	
	@JsonProperty("BpaSwiFile")
    private String BpaSwiFile = "";
	
	@Comment(alias="状态抽样类型", group="抽样参数", tr="0:全网,1:输电,2:发电")
    @JsonProperty("PRSampleObject")
    private Integer PRSampleObject = 0;  
    
	@Comment(alias="状态抽样方法", group="抽样参数", tr="1:蒙特卡罗,2:解析,3:状态抽样,4:快速排序")
    @JsonProperty("PRSampleMethod")
    private Integer PRSampleMethod = 1;  
    	    
    @Comment(alias="最大发电机故障", group="抽样参数")
    @JsonProperty("MaxGenFault")
    private Integer MaxGenFault = 20;
    
    @Comment(alias="最大支路故障", group="抽样参数")
    @JsonProperty("MaxBranFault")
    private Integer MaxBranFault = 20;  
	
	@Comment(alias="蒙特卡罗模拟时间", group="抽样参数")
    @JsonProperty("MCSSimulateTime")
    private Integer MCSSimulateTime = 2000000;  
    
	@Comment(alias="蒙特卡罗最小状态概率", group="抽样参数")
    @JsonProperty("MCSMinStateProb")
    private Double MCSMinStateProb = 0.000000;    
    
	@Comment(alias="快速排序最大累积概率", group="抽样参数")
    @JsonProperty("FSTMaxCumuProb")
    private Double FSTMaxCumuProb = 0.990000;      
    
	@Comment(alias="快速排序最大状态数", group="抽样参数")
    @JsonProperty("FSTMaxStateNum")
    private Integer FSTMaxStateNum = 100000; 
	
	@Comment(alias="状态抽样最大状态数", group="抽样参数")
    @JsonProperty("STSMaxStateNum")
    private Integer STSMaxStateNum = 100000; 	
    
	@Comment(alias="解析法最小状态概率", group="抽样参数")
    @JsonProperty("FSTMinStateProb")
    private Double FSTMinStateProb = 1.0e-009; 
    
    @JsonProperty("GenBusLoadAsAux")
    private Integer GenBusLoadAsAux = 0;    
       
	@Comment(alias="直变交系数", group="后评估参数")
    @JsonProperty("Dc2AcFactor")
    private Double Dc2AcFactor = 1.100000;
    
    @Comment(alias="孤岛的最小容载比", group="后评估参数")
    @JsonProperty("MinIslandGLRatio")
    private Double MinIslandGLRatio = 0.500000;     

    @Comment(alias="线路消限", group="后评估参数", tr="0:否,1:是")
    @JsonProperty("LineELimit")
    private Integer LineELimit = 1;   
    
    @Comment(alias="主变消限", group="后评估参数", tr="0:否,1:是")
    @JsonProperty("TranELimit")
    private Integer TranELimit = 1;    
    
    @Comment(alias="调整发电机消限", group="后评估参数", tr="0:否,1:是")
    @JsonProperty("GenPELimit")
    private Integer GenPELimit = 1;   
    
    @Comment(alias="调整UPFC消限", group="后评估参数", tr="0:否,1:是")
    @JsonProperty("UPFCELimit")
    private Integer UPFCELimit = 1;      
    
	@Comment(alias="厂用电参与消限", group="后评估参数", tr="0:否,1:是")
	@JsonProperty("AuxLoadAdjust")
    private Integer AuxLoadAdjust = 1;        
    
	@Comment(alias="等值发电机参与消限", group="后评估参数", tr="0:否,1:是")
    @JsonProperty("EQGenAdjust")
    private Integer EQGenAdjust = 1;
    
	@Comment(alias="等值负荷参与消限", group="后评估参数", tr="0:否, 1:是")
    @JsonProperty("EQLoadAdjust")
    private Integer EQLoadAdjust = 1; 
	
	@Comment(alias="UPFC采用变容法", group="后评估参数", tr="0:否, 1:是")
    @JsonProperty("UPFCAdjustRC")
    private Integer UPFCAdjustRC = 1;     
    	  
    @JsonProperty("LowVoltThreshold")
    private Double LowVoltThreshold = 0.000000; 
     
    @JsonProperty("MultiThread")
    private Integer MultiThread = 2;     
       
    @JsonProperty("TinyGenThreshold")
    private Double TinyGenThreshold = 0.000000;   
      
    @JsonProperty("ZIL")
    private Double ZIL = 0.000010;
    
    
	public Double getANAMinStateProb() {
		return ANAMinStateProb;
	}
	public void setANAMinStateProb(Double aNAMinStateProb) {
		ANAMinStateProb = aNAMinStateProb;
	}
	public Integer getAuxLoadAdjust() {
		return AuxLoadAdjust;
	}
	public void setAuxLoadAdjust(Integer auxLoadAdjust) {
		AuxLoadAdjust = auxLoadAdjust;
	}
	public String getBpaDatFile() {
		return BpaDatFile;
	}
	public void setBpaDatFile(String bpaDatFile) {
		BpaDatFile = bpaDatFile;
	}
	public String getBpaRParamFile() {
		return BpaRParamFile;
	}
	public void setBpaRParamFile(String bpaRParamFile) {
		BpaRParamFile = bpaRParamFile;
	}
	public String getBpaSwiFile() {
		return BpaSwiFile;
	}
	public void setBpaSwiFile(String bpaSwiFile) {
		BpaSwiFile = bpaSwiFile;
	}
	public Double getDc2AcFactor() {
		return Dc2AcFactor;
	}
	public void setDc2AcFactor(Double dc2AcFactor) {
		Dc2AcFactor = dc2AcFactor;
	}
	public Integer getEQGenAdjust() {
		return EQGenAdjust;
	}
	public void setEQGenAdjust(Integer eQGenAdjust) {
		EQGenAdjust = eQGenAdjust;
	}
	public Integer getEQLoadAdjust() {
		return EQLoadAdjust;
	}
	public void setEQLoadAdjust(Integer eQLoadAdjust) {
		EQLoadAdjust = eQLoadAdjust;
	}
	public Double getFSTMaxCumuProb() {
		return FSTMaxCumuProb;
	}
	public void setFSTMaxCumuProb(Double fSTMaxCumuProb) {
		FSTMaxCumuProb = fSTMaxCumuProb;
	}
	public Integer getFSTMaxStateNum() {
		return FSTMaxStateNum;
	}
	public void setFSTMaxStateNum(Integer fSTMaxStateNum) {
		FSTMaxStateNum = fSTMaxStateNum;
	}
	public Double getFSTMinStateProb() {
		return FSTMinStateProb;
	}
	public void setFSTMinStateProb(Double fSTMinStateProb) {
		FSTMinStateProb = fSTMinStateProb;
	}
	public Integer getGenBusLoadAsAux() {
		return GenBusLoadAsAux;
	}
	public void setGenBusLoadAsAux(Integer genBusLoadAsAux) {
		GenBusLoadAsAux = genBusLoadAsAux;
	}
	public Integer getGenPELimit() {
		return GenPELimit;
	}
	public void setGenPELimit(Integer genPELimit) {
		GenPELimit = genPELimit;
	}
	public Integer getLineELimit() {
		return LineELimit;
	}
	public void setLineELimit(Integer lineELimit) {
		LineELimit = lineELimit;
	}
	public Double getLowVoltThreshold() {
		return LowVoltThreshold;
	}
	public void setLowVoltThreshold(Double lowVoltThreshold) {
		LowVoltThreshold = lowVoltThreshold;
	}
	public Double getMCSMinStateProb() {
		return MCSMinStateProb;
	}
	public void setMCSMinStateProb(Double mCSMinStateProb) {
		MCSMinStateProb = mCSMinStateProb;
	}
	public Integer getMCSSimulateTime() {
		return MCSSimulateTime;
	}
	public void setMCSSimulateTime(Integer mCSSimulateTime) {
		MCSSimulateTime = mCSSimulateTime;
	}
	public Integer getMaxBranFault() {
		return MaxBranFault;
	}
	public void setMaxBranFault(Integer maxBranFault) {
		MaxBranFault = maxBranFault;
	}
	public Integer getMaxGenFault() {
		return MaxGenFault;
	}
	public void setMaxGenFault(Integer maxGenFault) {
		MaxGenFault = maxGenFault;
	}
	public Double getMinIslandGLRatio() {
		return MinIslandGLRatio;
	}
	public void setMinIslandGLRatio(Double minIslandGLRatio) {
		MinIslandGLRatio = minIslandGLRatio;
	}
	public Integer getMultiThread() {
		return MultiThread;
	}
	public void setMultiThread(Integer multiThread) {
		MultiThread = multiThread;
	}
	public Integer getPRSampleMethod() {
		return PRSampleMethod;
	}
	public void setPRSampleMethod(Integer pRSampleMethod) {
		PRSampleMethod = pRSampleMethod;
	}
	public Integer getPRSampleObject() {
		return PRSampleObject;
	}
	public void setPRSampleObject(Integer pRSampleObject) {
		PRSampleObject = pRSampleObject;
	}
	public Integer getSTSMaxStateNum() {
		return STSMaxStateNum;
	}
	public void setSTSMaxStateNum(Integer sTSMaxStateNum) {
		STSMaxStateNum = sTSMaxStateNum;
	}
	public Double getTinyGenThreshold() {
		return TinyGenThreshold;
	}
	public void setTinyGenThreshold(Double tinyGenThreshold) {
		TinyGenThreshold = tinyGenThreshold;
	}
	public Integer getTranELimit() {
		return TranELimit;
	}
	public void setTranELimit(Integer tranELimit) {
		TranELimit = tranELimit;
	}
	public Integer getUPFCAdjustRC() {
		return UPFCAdjustRC;
	}
	public void setUPFCAdjustRC(Integer uPFCAdjustRC) {
		UPFCAdjustRC = uPFCAdjustRC;
	}
	public Integer getUPFCELimit() {
		return UPFCELimit;
	}
	public void setUPFCELimit(Integer uPFCELimit) {
		UPFCELimit = uPFCELimit;
	}
	public Double getZIL() {
		return ZIL;
	}
	public void setZIL(Double zIL) {
		ZIL = zIL;
	}
	@Override
	public String toString() {
		return "PRAdequacySetting [ANAMinStateProb=" + ANAMinStateProb
				+ ", AuxLoadAdjust=" + AuxLoadAdjust + ", BpaDatFile="
				+ BpaDatFile + ", BpaRParamFile=" + BpaRParamFile
				+ ", BpaSwiFile=" + BpaSwiFile + ", Dc2AcFactor=" + Dc2AcFactor
				+ ", EQGenAdjust=" + EQGenAdjust + ", EQLoadAdjust="
				+ EQLoadAdjust + ", FSTMaxCumuProb=" + FSTMaxCumuProb
				+ ", FSTMaxStateNum=" + FSTMaxStateNum + ", FSTMinStateProb="
				+ FSTMinStateProb + ", GenBusLoadAsAux=" + GenBusLoadAsAux
				+ ", GenPELimit=" + GenPELimit + ", LineELimit=" + LineELimit
				+ ", LowVoltThreshold=" + LowVoltThreshold
				+ ", MCSMinStateProb=" + MCSMinStateProb + ", MCSSimulateTime="
				+ MCSSimulateTime + ", MaxBranFault=" + MaxBranFault
				+ ", MaxGenFault=" + MaxGenFault + ", MinIslandGLRatio="
				+ MinIslandGLRatio + ", MultiThread=" + MultiThread
				+ ", PRSampleMethod=" + PRSampleMethod + ", PRSampleObject="
				+ PRSampleObject + ", STSMaxStateNum=" + STSMaxStateNum
				+ ", TinyGenThreshold=" + TinyGenThreshold + ", TranELimit="
				+ TranELimit + ", UPFCAdjustRC=" + UPFCAdjustRC
				+ ", UPFCELimit=" + UPFCELimit + ", ZIL=" + ZIL + "]";
	}
	public String getModelId() {
		return modelId;
	}
	public void setModelId(String model) {
		this.modelId = model;
	}

}
