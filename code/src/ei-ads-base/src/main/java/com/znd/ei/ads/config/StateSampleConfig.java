package com.znd.ei.ads.config;

public class StateSampleConfig {
	// 抽样对象类型，全网；输电；发电
	private String nPRSampleObject = "全网";
	// 抽样类型 
	private Integer nPRSampleMethod = 1;
	// 抽样最大发电机故障重数 
	private Integer nMaxGenFault  = 20;
	// 抽样最大支路故障重数 
	private Integer nMaxBranFault = 20;
	// MCS最大抽样仿真时长 
	private Integer nMCSSimulateTime = 2000000;
	// MCS[蒙特卡罗]设备故障概率门槛值 
	private Double fMCSMinStateProb = 0.000000;
	// FST[快速排序]累积概率 
	private Double fFSTMaxCumuProb = 0.990000;
	// FST[快速排序]设备故障概率门槛值 
	private Double fFSTMinStateProb = 1.000000;
	// FST[快速排序]最大状态数 
	private Integer nFSTMaxStateNum = 100000;
	// STS[状态抽样]最大状态数 
	private Integer nSTSMaxStateNum = 100000;
	// ANA[解析法]设备故障概率门槛值 
	private Double fANAMinStateProb = 1.000000;
	public String getnPRSampleObject() {
		return nPRSampleObject;
	}
	public void setnPRSampleObject(String nPRSampleObject) {
		this.nPRSampleObject = nPRSampleObject;
	}
	public Integer getnPRSampleMethod() {
		return nPRSampleMethod;
	}
	public void setnPRSampleMethod(Integer nPRSampleMethod) {
		this.nPRSampleMethod = nPRSampleMethod;
	}
	public Integer getnMaxGenFault() {
		return nMaxGenFault;
	}
	public void setnMaxGenFault(Integer nMaxGenFault) {
		this.nMaxGenFault = nMaxGenFault;
	}
	public Integer getnMaxBranFault() {
		return nMaxBranFault;
	}
	public void setnMaxBranFault(Integer nMaxBranFault) {
		this.nMaxBranFault = nMaxBranFault;
	}
	public Integer getnMCSSimulateTime() {
		return nMCSSimulateTime;
	}
	public void setnMCSSimulateTime(Integer nMCSSimulateTime) {
		this.nMCSSimulateTime = nMCSSimulateTime;
	}
	public Double getfMCSMinStateProb() {
		return fMCSMinStateProb;
	}
	public void setfMCSMinStateProb(Double fMCSMinStateProb) {
		this.fMCSMinStateProb = fMCSMinStateProb;
	}
	public Double getfFSTMaxCumuProb() {
		return fFSTMaxCumuProb;
	}
	public void setfFSTMaxCumuProb(Double fFSTMaxCumuProb) {
		this.fFSTMaxCumuProb = fFSTMaxCumuProb;
	}
	public Double getfFSTMinStateProb() {
		return fFSTMinStateProb;
	}
	public void setfFSTMinStateProb(Double fFSTMinStateProb) {
		this.fFSTMinStateProb = fFSTMinStateProb;
	}
	public Integer getnFSTMaxStateNum() {
		return nFSTMaxStateNum;
	}
	public void setnFSTMaxStateNum(Integer nFSTMaxStateNum) {
		this.nFSTMaxStateNum = nFSTMaxStateNum;
	}
	public Integer getnSTSMaxStateNum() {
		return nSTSMaxStateNum;
	}
	public void setnSTSMaxStateNum(Integer nSTSMaxStateNum) {
		this.nSTSMaxStateNum = nSTSMaxStateNum;
	}
	public Double getfANAMinStateProb() {
		return fANAMinStateProb;
	}
	public void setfANAMinStateProb(Double fANAMinStateProb) {
		this.fANAMinStateProb = fANAMinStateProb;
	}
	@Override
	public String toString() {
		return "StateSampleConfig [nPRSampleObject=" + nPRSampleObject
				+ ", nPRSampleMethod=" + nPRSampleMethod + ", nMaxGenFault="
				+ nMaxGenFault + ", nMaxBranFault=" + nMaxBranFault
				+ ", nMCSSimulateTime=" + nMCSSimulateTime
				+ ", fMCSMinStateProb=" + fMCSMinStateProb
				+ ", fFSTMaxCumuProb=" + fFSTMaxCumuProb
				+ ", fFSTMinStateProb=" + fFSTMinStateProb
				+ ", nFSTMaxStateNum=" + nFSTMaxStateNum + ", nSTSMaxStateNum="
				+ nSTSMaxStateNum + ", fANAMinStateProb=" + fANAMinStateProb
				+ "]";
	}
}
