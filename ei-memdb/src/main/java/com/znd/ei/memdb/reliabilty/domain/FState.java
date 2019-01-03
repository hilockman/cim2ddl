package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*抽样状态	*
***********************/
public class FState  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //状态ID
  private Integer FStateID;
  
  //抽样算法
  private Integer SampleType;
  
  //故障设备数
  private Integer FDevNum;
  
  //状态概率
  private Double Probability;
  
  //持续时间
  private Double Durition;
  
  //状态出现次数
  private Integer StateNum;
  
  //故障损失发电机出力(兆瓦)
  private Double FLossGen;
  
  //故障损失发电机容量(兆瓦)
  private Double FLossGenCap;
  
  //故障损失负荷功率(兆瓦)
  private Double FLossLoad;
  
  //形成多岛
  private Integer MIsland;
  
  //孤岛增加出力(兆瓦)
  private Double MIslandInsGen;
  
  //孤岛减少出力(兆瓦)
  private Double MIslandCutGen;
  
  //孤岛损失负荷(兆瓦)
  private Double MIslandOutLoad;
  
  //功率平衡发电机增出力(兆瓦)
  private Double BalanceInsGen;
  
  //功率平衡发电机减出力(兆瓦)
  private Double BalanceCutGen;
  
  //功率平衡损失负荷(兆瓦)
  private Double BalanceCutLoad;
  
  //设备越限
  private Integer OverLimit;
  
  //消限切负荷
  private Integer ELimit;
  
  //消限减少出力(兆瓦)
  private Double ELimitCutGen;
  
  //消限增加出力(兆瓦)
  private Double ELimitInsGen;
  
  //消限损失负荷(兆瓦)
  private Double ELimitCutLoad;
  
  //充裕度评估消限结果
  private Integer ELimitResult;
  
  //最大负荷损失分区索引
  private Integer MaxFaultZone;
  
  //最大负荷损失分区占比
  private Double MaxFaultRatio;
  
  //事故等级
  private Integer FaultGrade;
  
  //多状态模型功率状态索引
  private Integer MSoutIndex;
  
  //评估状态
  private Integer Estimated;
  
  //评估时间
  private Double ElapseTime;
  
  public Integer getId()
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public Integer getMemIndex()
  {
    return memIndex;
  }
    
  public void setMemIndex(Integer memIndex)
  {
    this.memIndex = memIndex;
  }
    
  public Integer getFStateID()
  {
    return FStateID;
  }
    
  public void setFStateID(Integer FStateID)
  {
    this.FStateID = FStateID;
  }
    
  public Integer getSampleType()
  {
    return SampleType;
  }
    
  public void setSampleType(Integer SampleType)
  {
    this.SampleType = SampleType;
  }
    
  public Integer getFDevNum()
  {
    return FDevNum;
  }
    
  public void setFDevNum(Integer FDevNum)
  {
    this.FDevNum = FDevNum;
  }
    
  public Double getProbability()
  {
    return Probability;
  }
    
  public void setProbability(Double Probability)
  {
    this.Probability = Probability;
  }
    
  public Double getDurition()
  {
    return Durition;
  }
    
  public void setDurition(Double Durition)
  {
    this.Durition = Durition;
  }
    
  public Integer getStateNum()
  {
    return StateNum;
  }
    
  public void setStateNum(Integer StateNum)
  {
    this.StateNum = StateNum;
  }
    
  public Double getFLossGen()
  {
    return FLossGen;
  }
    
  public void setFLossGen(Double FLossGen)
  {
    this.FLossGen = FLossGen;
  }
    
  public Double getFLossGenCap()
  {
    return FLossGenCap;
  }
    
  public void setFLossGenCap(Double FLossGenCap)
  {
    this.FLossGenCap = FLossGenCap;
  }
    
  public Double getFLossLoad()
  {
    return FLossLoad;
  }
    
  public void setFLossLoad(Double FLossLoad)
  {
    this.FLossLoad = FLossLoad;
  }
    
  public Integer getMIsland()
  {
    return MIsland;
  }
    
  public void setMIsland(Integer MIsland)
  {
    this.MIsland = MIsland;
  }
    
  public Double getMIslandInsGen()
  {
    return MIslandInsGen;
  }
    
  public void setMIslandInsGen(Double MIslandInsGen)
  {
    this.MIslandInsGen = MIslandInsGen;
  }
    
  public Double getMIslandCutGen()
  {
    return MIslandCutGen;
  }
    
  public void setMIslandCutGen(Double MIslandCutGen)
  {
    this.MIslandCutGen = MIslandCutGen;
  }
    
  public Double getMIslandOutLoad()
  {
    return MIslandOutLoad;
  }
    
  public void setMIslandOutLoad(Double MIslandOutLoad)
  {
    this.MIslandOutLoad = MIslandOutLoad;
  }
    
  public Double getBalanceInsGen()
  {
    return BalanceInsGen;
  }
    
  public void setBalanceInsGen(Double BalanceInsGen)
  {
    this.BalanceInsGen = BalanceInsGen;
  }
    
  public Double getBalanceCutGen()
  {
    return BalanceCutGen;
  }
    
  public void setBalanceCutGen(Double BalanceCutGen)
  {
    this.BalanceCutGen = BalanceCutGen;
  }
    
  public Double getBalanceCutLoad()
  {
    return BalanceCutLoad;
  }
    
  public void setBalanceCutLoad(Double BalanceCutLoad)
  {
    this.BalanceCutLoad = BalanceCutLoad;
  }
    
  public Integer getOverLimit()
  {
    return OverLimit;
  }
    
  public void setOverLimit(Integer OverLimit)
  {
    this.OverLimit = OverLimit;
  }
    
  public Integer getELimit()
  {
    return ELimit;
  }
    
  public void setELimit(Integer ELimit)
  {
    this.ELimit = ELimit;
  }
    
  public Double getELimitCutGen()
  {
    return ELimitCutGen;
  }
    
  public void setELimitCutGen(Double ELimitCutGen)
  {
    this.ELimitCutGen = ELimitCutGen;
  }
    
  public Double getELimitInsGen()
  {
    return ELimitInsGen;
  }
    
  public void setELimitInsGen(Double ELimitInsGen)
  {
    this.ELimitInsGen = ELimitInsGen;
  }
    
  public Double getELimitCutLoad()
  {
    return ELimitCutLoad;
  }
    
  public void setELimitCutLoad(Double ELimitCutLoad)
  {
    this.ELimitCutLoad = ELimitCutLoad;
  }
    
  public Integer getELimitResult()
  {
    return ELimitResult;
  }
    
  public void setELimitResult(Integer ELimitResult)
  {
    this.ELimitResult = ELimitResult;
  }
    
  public Integer getMaxFaultZone()
  {
    return MaxFaultZone;
  }
    
  public void setMaxFaultZone(Integer MaxFaultZone)
  {
    this.MaxFaultZone = MaxFaultZone;
  }
    
  public Double getMaxFaultRatio()
  {
    return MaxFaultRatio;
  }
    
  public void setMaxFaultRatio(Double MaxFaultRatio)
  {
    this.MaxFaultRatio = MaxFaultRatio;
  }
    
  public Integer getFaultGrade()
  {
    return FaultGrade;
  }
    
  public void setFaultGrade(Integer FaultGrade)
  {
    this.FaultGrade = FaultGrade;
  }
    
  public Integer getMSoutIndex()
  {
    return MSoutIndex;
  }
    
  public void setMSoutIndex(Integer MSoutIndex)
  {
    this.MSoutIndex = MSoutIndex;
  }
    
  public Integer getEstimated()
  {
    return Estimated;
  }
    
  public void setEstimated(Integer Estimated)
  {
    this.Estimated = Estimated;
  }
    
  public Double getElapseTime()
  {
    return ElapseTime;
  }
    
  public void setElapseTime(Double ElapseTime)
  {
    this.ElapseTime = ElapseTime;
  }
    
  public String toString()
  {
    return "FState ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", FStateID = " + FStateID
	 + ", SampleType = " + SampleType
	 + ", FDevNum = " + FDevNum
	 + ", Probability = " + Probability
	 + ", Durition = " + Durition
	 + ", StateNum = " + StateNum
	 + ", FLossGen = " + FLossGen
	 + ", FLossGenCap = " + FLossGenCap
	 + ", FLossLoad = " + FLossLoad
	 + ", MIsland = " + MIsland
	 + ", MIslandInsGen = " + MIslandInsGen
	 + ", MIslandCutGen = " + MIslandCutGen
	 + ", MIslandOutLoad = " + MIslandOutLoad
	 + ", BalanceInsGen = " + BalanceInsGen
	 + ", BalanceCutGen = " + BalanceCutGen
	 + ", BalanceCutLoad = " + BalanceCutLoad
	 + ", OverLimit = " + OverLimit
	 + ", ELimit = " + ELimit
	 + ", ELimitCutGen = " + ELimitCutGen
	 + ", ELimitInsGen = " + ELimitInsGen
	 + ", ELimitCutLoad = " + ELimitCutLoad
	 + ", ELimitResult = " + ELimitResult
	 + ", MaxFaultZone = " + MaxFaultZone
	 + ", MaxFaultRatio = " + MaxFaultRatio
	 + ", FaultGrade = " + FaultGrade
	 + ", MSoutIndex = " + MSoutIndex
	 + ", Estimated = " + Estimated
	 + ", ElapseTime = " + ElapseTime+"]";
  }
    
}
    
