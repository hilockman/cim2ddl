package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电压等级	*
***********************/
public class VoltageLevel  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //所属厂站
  private String Substation;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //平均电压(千伏)
  private Double nominalVoltage;
  
  //高压限值(千伏)
  private Double highVoltageLimit;
  
  //低压限值(千伏)
  private Double lowVoltageLimit;
  
  //厂站的索引
  private Integer SubstationPtr;
  
  //母线范围
  private Integer BusbarSectionRange;
  
  //发电机范围
  private Integer SynchronousMachineRange;
  
  //负荷范围
  private Integer EnergyConsumerRange;
  
  //并联补偿范围
  private Integer ShuntCompensatorRange;
  
  //串联补偿范围
  private Integer SeriesCompensatorRange;
  
  //断路器范围
  private Integer BreakerRange;
  
  //隔离开关范围
  private Integer DisconnectorRange;
  
  //接地刀闸范围
  private Integer GroundDisconnectorRange;
  
  //接地变范围
  private Integer GroundTransformerRange;
  
  //直流母线范围
  private Integer DCBusbarSectionRange;
  
  //直流断路器范围
  private Integer DCBreakerRange;
  
  //直流短路电流限制器范围
  private Integer DCShortCircuitLimitRange;
  
  //节点的范围
  private Integer ConnectivityNodeRange;
  
  //直流电压等级
  private Integer DCVoltageLevel;
  
  //辅助信息
  private Integer Outage;
  
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
    
  public String getResourceID()
  {
    return ResourceID;
  }
    
  public void setResourceID(String ResourceID)
  {
    this.ResourceID = ResourceID;
  }
    
  public String getSubstation()
  {
    return Substation;
  }
    
  public void setSubstation(String Substation)
  {
    this.Substation = Substation;
  }
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public String getDescription()
  {
    return Description;
  }
    
  public void setDescription(String Description)
  {
    this.Description = Description;
  }
    
  public Double getnominalVoltage()
  {
    return nominalVoltage;
  }
    
  public void setnominalVoltage(Double nominalVoltage)
  {
    this.nominalVoltage = nominalVoltage;
  }
    
  public Double gethighVoltageLimit()
  {
    return highVoltageLimit;
  }
    
  public void sethighVoltageLimit(Double highVoltageLimit)
  {
    this.highVoltageLimit = highVoltageLimit;
  }
    
  public Double getlowVoltageLimit()
  {
    return lowVoltageLimit;
  }
    
  public void setlowVoltageLimit(Double lowVoltageLimit)
  {
    this.lowVoltageLimit = lowVoltageLimit;
  }
    
  public Integer getSubstationPtr()
  {
    return SubstationPtr;
  }
    
  public void setSubstationPtr(Integer SubstationPtr)
  {
    this.SubstationPtr = SubstationPtr;
  }
    
  public Integer getBusbarSectionRange()
  {
    return BusbarSectionRange;
  }
    
  public void setBusbarSectionRange(Integer BusbarSectionRange)
  {
    this.BusbarSectionRange = BusbarSectionRange;
  }
    
  public Integer getSynchronousMachineRange()
  {
    return SynchronousMachineRange;
  }
    
  public void setSynchronousMachineRange(Integer SynchronousMachineRange)
  {
    this.SynchronousMachineRange = SynchronousMachineRange;
  }
    
  public Integer getEnergyConsumerRange()
  {
    return EnergyConsumerRange;
  }
    
  public void setEnergyConsumerRange(Integer EnergyConsumerRange)
  {
    this.EnergyConsumerRange = EnergyConsumerRange;
  }
    
  public Integer getShuntCompensatorRange()
  {
    return ShuntCompensatorRange;
  }
    
  public void setShuntCompensatorRange(Integer ShuntCompensatorRange)
  {
    this.ShuntCompensatorRange = ShuntCompensatorRange;
  }
    
  public Integer getSeriesCompensatorRange()
  {
    return SeriesCompensatorRange;
  }
    
  public void setSeriesCompensatorRange(Integer SeriesCompensatorRange)
  {
    this.SeriesCompensatorRange = SeriesCompensatorRange;
  }
    
  public Integer getBreakerRange()
  {
    return BreakerRange;
  }
    
  public void setBreakerRange(Integer BreakerRange)
  {
    this.BreakerRange = BreakerRange;
  }
    
  public Integer getDisconnectorRange()
  {
    return DisconnectorRange;
  }
    
  public void setDisconnectorRange(Integer DisconnectorRange)
  {
    this.DisconnectorRange = DisconnectorRange;
  }
    
  public Integer getGroundDisconnectorRange()
  {
    return GroundDisconnectorRange;
  }
    
  public void setGroundDisconnectorRange(Integer GroundDisconnectorRange)
  {
    this.GroundDisconnectorRange = GroundDisconnectorRange;
  }
    
  public Integer getGroundTransformerRange()
  {
    return GroundTransformerRange;
  }
    
  public void setGroundTransformerRange(Integer GroundTransformerRange)
  {
    this.GroundTransformerRange = GroundTransformerRange;
  }
    
  public Integer getDCBusbarSectionRange()
  {
    return DCBusbarSectionRange;
  }
    
  public void setDCBusbarSectionRange(Integer DCBusbarSectionRange)
  {
    this.DCBusbarSectionRange = DCBusbarSectionRange;
  }
    
  public Integer getDCBreakerRange()
  {
    return DCBreakerRange;
  }
    
  public void setDCBreakerRange(Integer DCBreakerRange)
  {
    this.DCBreakerRange = DCBreakerRange;
  }
    
  public Integer getDCShortCircuitLimitRange()
  {
    return DCShortCircuitLimitRange;
  }
    
  public void setDCShortCircuitLimitRange(Integer DCShortCircuitLimitRange)
  {
    this.DCShortCircuitLimitRange = DCShortCircuitLimitRange;
  }
    
  public Integer getConnectivityNodeRange()
  {
    return ConnectivityNodeRange;
  }
    
  public void setConnectivityNodeRange(Integer ConnectivityNodeRange)
  {
    this.ConnectivityNodeRange = ConnectivityNodeRange;
  }
    
  public Integer getDCVoltageLevel()
  {
    return DCVoltageLevel;
  }
    
  public void setDCVoltageLevel(Integer DCVoltageLevel)
  {
    this.DCVoltageLevel = DCVoltageLevel;
  }
    
  public Integer getOutage()
  {
    return Outage;
  }
    
  public void setOutage(Integer Outage)
  {
    this.Outage = Outage;
  }
    
  public String toString()
  {
    return "VoltageLevel ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Substation = " + Substation
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", nominalVoltage = " + nominalVoltage
	 + ", highVoltageLimit = " + highVoltageLimit
	 + ", lowVoltageLimit = " + lowVoltageLimit
	 + ", SubstationPtr = " + SubstationPtr
	 + ", BusbarSectionRange = " + BusbarSectionRange
	 + ", SynchronousMachineRange = " + SynchronousMachineRange
	 + ", EnergyConsumerRange = " + EnergyConsumerRange
	 + ", ShuntCompensatorRange = " + ShuntCompensatorRange
	 + ", SeriesCompensatorRange = " + SeriesCompensatorRange
	 + ", BreakerRange = " + BreakerRange
	 + ", DisconnectorRange = " + DisconnectorRange
	 + ", GroundDisconnectorRange = " + GroundDisconnectorRange
	 + ", GroundTransformerRange = " + GroundTransformerRange
	 + ", DCBusbarSectionRange = " + DCBusbarSectionRange
	 + ", DCBreakerRange = " + DCBreakerRange
	 + ", DCShortCircuitLimitRange = " + DCShortCircuitLimitRange
	 + ", ConnectivityNodeRange = " + ConnectivityNodeRange
	 + ", DCVoltageLevel = " + DCVoltageLevel
	 + ", Outage = " + Outage+"]";
  }
    
}
    
