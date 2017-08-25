package com.znd.ei.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*抽样状态	*
***********************/
@Entity
public class FState
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //抽样算法
  private Integer sampleType;
  
  //故障设备数
  private Integer fDevNum;
  
  //状态概率
  private Double probability;
  
  //持续时间
  private Double durition;
  
  //状态出现次数
  private Integer stateNum;
  
  //故障损失发电机出力(MW)
  private Double fLossGen;
  
  //故障损失发电机容量(MW)
  private Double fLossGenCap;
  
  //故障损失负荷功率(MW)
  private Double fLossLoad;
  
  //形成多岛
  private Integer mIsland;
  
  //孤岛增加出力(MW)
  private Double mIslandInsGen;
  
  //孤岛减少出力(MW)
  private Double mIslandCutGen;
  
  //孤岛损失负荷(MW)
  private Double mIslandOutLoad;
  
  //功率平衡发电机增出力(MW)
  private Double balanceInsGen;
  
  //功率平衡发电机减出力(MW)
  private Double balanceCutGen;
  
  //功率平衡损失负荷(MW)
  private Double balanceCutLoad;
  
  //设备越限
  private Integer overLimit;
  
  //消限切负荷
  private Integer eLimit;
  
  //消限减少出力(MW)
  private Double eLimitCutGen;
  
  //消限增加出力(MW)
  private Double eLimitInsGen;
  
  //消限损失负荷(MW)
  private Double eLimitCutLoad;
  
  //充裕度评估消限结果
  private Integer eLimitResult;
  
  //最大负荷损失分区索引
  private Integer maxFaultZone;
  
  //最大负荷损失分区占比
  private Double maxFaultRatio;
  
  //事故等级
  private Integer faultGrade;
  
  //多状态模型功率状态索引
  private Integer mSoutIndex;
  
  //评估状态
  private Integer estimated;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public Integer getSampleType() 
  {
    return sampleType;
  }
    
  public void setSampleType(Integer sampleType)
  {
    this.sampleType = sampleType;
  }
    
  public Integer getFDevNum() 
  {
    return fDevNum;
  }
    
  public void setFDevNum(Integer fDevNum)
  {
    this.fDevNum = fDevNum;
  }
    
  public Double getProbability() 
  {
    return probability;
  }
    
  public void setProbability(Double probability)
  {
    this.probability = probability;
  }
    
  public Double getDurition() 
  {
    return durition;
  }
    
  public void setDurition(Double durition)
  {
    this.durition = durition;
  }
    
  public Integer getStateNum() 
  {
    return stateNum;
  }
    
  public void setStateNum(Integer stateNum)
  {
    this.stateNum = stateNum;
  }
    
  public Double getFLossGen() 
  {
    return fLossGen;
  }
    
  public void setFLossGen(Double fLossGen)
  {
    this.fLossGen = fLossGen;
  }
    
  public Double getFLossGenCap() 
  {
    return fLossGenCap;
  }
    
  public void setFLossGenCap(Double fLossGenCap)
  {
    this.fLossGenCap = fLossGenCap;
  }
    
  public Double getFLossLoad() 
  {
    return fLossLoad;
  }
    
  public void setFLossLoad(Double fLossLoad)
  {
    this.fLossLoad = fLossLoad;
  }
    
  public Integer getMIsland() 
  {
    return mIsland;
  }
    
  public void setMIsland(Integer mIsland)
  {
    this.mIsland = mIsland;
  }
    
  public Double getMIslandInsGen() 
  {
    return mIslandInsGen;
  }
    
  public void setMIslandInsGen(Double mIslandInsGen)
  {
    this.mIslandInsGen = mIslandInsGen;
  }
    
  public Double getMIslandCutGen() 
  {
    return mIslandCutGen;
  }
    
  public void setMIslandCutGen(Double mIslandCutGen)
  {
    this.mIslandCutGen = mIslandCutGen;
  }
    
  public Double getMIslandOutLoad() 
  {
    return mIslandOutLoad;
  }
    
  public void setMIslandOutLoad(Double mIslandOutLoad)
  {
    this.mIslandOutLoad = mIslandOutLoad;
  }
    
  public Double getBalanceInsGen() 
  {
    return balanceInsGen;
  }
    
  public void setBalanceInsGen(Double balanceInsGen)
  {
    this.balanceInsGen = balanceInsGen;
  }
    
  public Double getBalanceCutGen() 
  {
    return balanceCutGen;
  }
    
  public void setBalanceCutGen(Double balanceCutGen)
  {
    this.balanceCutGen = balanceCutGen;
  }
    
  public Double getBalanceCutLoad() 
  {
    return balanceCutLoad;
  }
    
  public void setBalanceCutLoad(Double balanceCutLoad)
  {
    this.balanceCutLoad = balanceCutLoad;
  }
    
  public Integer getOverLimit() 
  {
    return overLimit;
  }
    
  public void setOverLimit(Integer overLimit)
  {
    this.overLimit = overLimit;
  }
    
  public Integer getELimit() 
  {
    return eLimit;
  }
    
  public void setELimit(Integer eLimit)
  {
    this.eLimit = eLimit;
  }
    
  public Double getELimitCutGen() 
  {
    return eLimitCutGen;
  }
    
  public void setELimitCutGen(Double eLimitCutGen)
  {
    this.eLimitCutGen = eLimitCutGen;
  }
    
  public Double getELimitInsGen() 
  {
    return eLimitInsGen;
  }
    
  public void setELimitInsGen(Double eLimitInsGen)
  {
    this.eLimitInsGen = eLimitInsGen;
  }
    
  public Double getELimitCutLoad() 
  {
    return eLimitCutLoad;
  }
    
  public void setELimitCutLoad(Double eLimitCutLoad)
  {
    this.eLimitCutLoad = eLimitCutLoad;
  }
    
  public Integer getELimitResult() 
  {
    return eLimitResult;
  }
    
  public void setELimitResult(Integer eLimitResult)
  {
    this.eLimitResult = eLimitResult;
  }
    
  public Integer getMaxFaultZone() 
  {
    return maxFaultZone;
  }
    
  public void setMaxFaultZone(Integer maxFaultZone)
  {
    this.maxFaultZone = maxFaultZone;
  }
    
  public Double getMaxFaultRatio() 
  {
    return maxFaultRatio;
  }
    
  public void setMaxFaultRatio(Double maxFaultRatio)
  {
    this.maxFaultRatio = maxFaultRatio;
  }
    
  public Integer getFaultGrade() 
  {
    return faultGrade;
  }
    
  public void setFaultGrade(Integer faultGrade)
  {
    this.faultGrade = faultGrade;
  }
    
  public Integer getMSoutIndex() 
  {
    return mSoutIndex;
  }
    
  public void setMSoutIndex(Integer mSoutIndex)
  {
    this.mSoutIndex = mSoutIndex;
  }
    
  public Integer getEstimated() 
  {
    return estimated;
  }
    
  public void setEstimated(Integer estimated)
  {
    this.estimated = estimated;
  }
    
}
    
