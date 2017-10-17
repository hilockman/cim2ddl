package com.znd.ei.computing.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**
 * 
 * @author wangheng
 *抽样状态
 */
@Entity // This tells Hibernate to make a table out of this class
public class FState {
    @Id
    @GeneratedValue(strategy=GenerationType.AUTO)
    private Integer id;
    
    private Short	sampleType;		  //抽样算法;							
    private Short	fDevNum;			  //故障设备数;						
    private Double	probability;		//状态概率;						
    private Double	durition;			  //持续时间;							
    private Integer	stateNum;			  //状态出现次数;					
    private Float	fLossGen;			  //故障损失发电机出力(MW);	
    private Float	fLossGenCap;		  //故障损失发电机容量(MW)"
    private Float	fLossLoad;		      //故障损失负荷功率(MW);		
    private Short	mIsland;			  //形成多岛;						
    private Float	mIslandInsGen;	//孤岛增加出力(MW);			
    private Float	mIslandCutGen;	//孤岛减少出力(MW);			
    private Float	mIslandOutLoad;	//孤岛损失负荷(MW);			
    private Float	balanceInsGen;	//功率平衡发电机增出力(MW);		
    private Float	balanceCutGen;	//功率平衡发电机减出力(MW);		
    private Float	balanceCutLoad;	//功率平衡损失负荷(MW);				
    private Short	overLimit;		  //设备越限;						
    private Short	eLimit;			    //消限切负荷;						
    private Float	eLimitCutGen;		//消限减少出力(MW);	
    private Float	eLimitInsGen;		//消限增加出力(MW);	
    private Float	eLimitCutLoad;	//消限损失负荷(MW);	
    private Short	eLimitResult;		//充裕度评估消限结果"
    private Short	maxFaultZone;		//最大负荷损失分区索引"
    private Float	maxFaultRatio;	//最大负荷损失分区占比"
    private Short	faultGrade;		  //事故等级;							
    private Short	mSoutIndex;		  //多状态模型功率状态索引"
    private Short	estimated;		  //评估状态;
	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public Short getSampleType() {
		return sampleType;
	}
	public void setSampleType(Short sampleType) {
		this.sampleType = sampleType;
	}
	public Short getfDevNum() {
		return fDevNum;
	}
	public void setfDevNum(Short fDevNum) {
		this.fDevNum = fDevNum;
	}
	public Double getProbability() {
		return probability;
	}
	public void setProbability(Double probability) {
		this.probability = probability;
	}
	public Double getDurition() {
		return durition;
	}
	public void setDurition(Double durition) {
		this.durition = durition;
	}
	public Integer getStateNum() {
		return stateNum;
	}
	public void setStateNum(Integer stateNum) {
		this.stateNum = stateNum;
	}
	public Float getfLossGen() {
		return fLossGen;
	}
	public void setfLossGen(Float fLossGen) {
		this.fLossGen = fLossGen;
	}
	public Float getfLossGenCap() {
		return fLossGenCap;
	}
	public void setfLossGenCap(Float fLossGenCap) {
		this.fLossGenCap = fLossGenCap;
	}
	public Float getfLossLoad() {
		return fLossLoad;
	}
	public void setfLossLoad(Float fLossLoad) {
		this.fLossLoad = fLossLoad;
	}
	public Short getmIsland() {
		return mIsland;
	}
	public void setmIsland(Short mIsland) {
		this.mIsland = mIsland;
	}
	public Float getmIslandInsGen() {
		return mIslandInsGen;
	}
	public void setmIslandInsGen(Float mIslandInsGen) {
		this.mIslandInsGen = mIslandInsGen;
	}
	public Float getmIslandCutGen() {
		return mIslandCutGen;
	}
	public void setmIslandCutGen(Float mIslandCutGen) {
		this.mIslandCutGen = mIslandCutGen;
	}
	public Float getmIslandOutLoad() {
		return mIslandOutLoad;
	}
	public void setmIslandOutLoad(Float mIslandOutLoad) {
		this.mIslandOutLoad = mIslandOutLoad;
	}
	public Float getBalanceInsGen() {
		return balanceInsGen;
	}
	public void setBalanceInsGen(Float balanceInsGen) {
		this.balanceInsGen = balanceInsGen;
	}
	public Float getBalanceCutGen() {
		return balanceCutGen;
	}
	public void setBalanceCutGen(Float balanceCutGen) {
		this.balanceCutGen = balanceCutGen;
	}
	public Float getBalanceCutLoad() {
		return balanceCutLoad;
	}
	public void setBalanceCutLoad(Float balanceCutLoad) {
		this.balanceCutLoad = balanceCutLoad;
	}
	public Short getOverLimit() {
		return overLimit;
	}
	public void setOverLimit(Short overLimit) {
		this.overLimit = overLimit;
	}
	public Short geteLimit() {
		return eLimit;
	}
	public void seteLimit(Short eLimit) {
		this.eLimit = eLimit;
	}
	public Float geteLimitCutGen() {
		return eLimitCutGen;
	}
	public void seteLimitCutGen(Float eLimitCutGen) {
		this.eLimitCutGen = eLimitCutGen;
	}
	public Float geteLimitInsGen() {
		return eLimitInsGen;
	}
	public void seteLimitInsGen(Float eLimitInsGen) {
		this.eLimitInsGen = eLimitInsGen;
	}
	public Float geteLimitCutLoad() {
		return eLimitCutLoad;
	}
	public void seteLimitCutLoad(Float eLimitCutLoad) {
		this.eLimitCutLoad = eLimitCutLoad;
	}
	public Short geteLimitResult() {
		return eLimitResult;
	}
	public void seteLimitResult(Short eLimitResult) {
		this.eLimitResult = eLimitResult;
	}
	public Short getMaxFaultZone() {
		return maxFaultZone;
	}
	public void setMaxFaultZone(Short maxFaultZone) {
		this.maxFaultZone = maxFaultZone;
	}
	public Float getMaxFaultRatio() {
		return maxFaultRatio;
	}
	public void setMaxFaultRatio(Float maxFaultRatio) {
		this.maxFaultRatio = maxFaultRatio;
	}
	public Short getFaultGrade() {
		return faultGrade;
	}
	public void setFaultGrade(Short faultGrade) {
		this.faultGrade = faultGrade;
	}
	public Short getmSoutIndex() {
		return mSoutIndex;
	}
	public void setmSoutIndex(Short mSoutIndex) {
		this.mSoutIndex = mSoutIndex;
	}
	public Short getEstimated() {
		return estimated;
	}
	public void setEstimated(Short estimated) {
		this.estimated = estimated;
	}
    

}
