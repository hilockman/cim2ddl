package com.znd.ei.ads.apl.reliability.bean;

import java.io.Serializable;

public class StateEstimateConfig  implements Serializable
{
	// 直流潮流2 交流潮流系数 
	private Float dc2AcFactor = 1.100000f;
	// 线路消限 
	private Integer lineELimit= 1;
	
	// 主变消限 
	private Integer tranELimit = 1;
	
	// 调整发电机消限 
	private Integer genPELimit = 1;
	
	// 调整UPFC消限 
	private Integer uPFCELimit = 1;
	
	// 厂用电参与消限 
	private Integer auxLoadAdjust = 1;

	// 等值发电机参与消限 
	private Integer eQGenAdjust = 0;
	
	// 等值负荷参与消限 
	private Integer eQLoadAdjust = 0;
	
	// 孤岛的最小容载比 
	private Float minIslandGLRatio = 0.500000f;
	
	// UPFC采用变容法 
	private Integer uPFCAdjustRC = 1;

	public Float getDc2AcFactor() {
		return dc2AcFactor;
	}

	public void setDc2AcFactor(Float dc2AcFactor) {
		this.dc2AcFactor = dc2AcFactor;
	}

	public Integer getLineELimit() {
		return lineELimit;
	}

	public void setLineELimit(Integer lineELimit) {
		this.lineELimit = lineELimit;
	}

	public Integer getTranELimit() {
		return tranELimit;
	}

	public void setTranELimit(Integer tranELimit) {
		this.tranELimit = tranELimit;
	}

	public Integer getGenPELimit() {
		return genPELimit;
	}

	public void setGenPELimit(Integer genPELimit) {
		this.genPELimit = genPELimit;
	}

	public Integer getuPFCELimit() {
		return uPFCELimit;
	}

	public void setuPFCELimit(Integer uPFCELimit) {
		this.uPFCELimit = uPFCELimit;
	}

	public Integer getAuxLoadAdjust() {
		return auxLoadAdjust;
	}

	public void setAuxLoadAdjust(Integer auxLoadAdjust) {
		this.auxLoadAdjust = auxLoadAdjust;
	}

	public Integer geteQGenAdjust() {
		return eQGenAdjust;
	}

	public void seteQGenAdjust(Integer eQGenAdjust) {
		this.eQGenAdjust = eQGenAdjust;
	}

	public Integer geteQLoadAdjust() {
		return eQLoadAdjust;
	}

	public void seteQLoadAdjust(Integer eQLoadAdjust) {
		this.eQLoadAdjust = eQLoadAdjust;
	}

	public Float getMinIslandGLRatio() {
		return minIslandGLRatio;
	}

	public void setMinIslandGLRatio(Float minIslandGLRatio) {
		this.minIslandGLRatio = minIslandGLRatio;
	}

	public Integer getuPFCAdjustRC() {
		return uPFCAdjustRC;
	}

	public void setuPFCAdjustRC(Integer uPFCAdjustRC) {
		this.uPFCAdjustRC = uPFCAdjustRC;
	}
	
}