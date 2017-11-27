package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*停运概率	*
***********************/
public class CopTable  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //状态
  private Integer State;
  
  //停运发电容量(MW)
  private Double OutageCapacity;
  
  //可用发电容量(MW)
  private Double AvailCapacity;
  
  //状态概率
  private Double StateProb;
  
  //状态累计概率
  private Double AccumProb;
  
  //状态频率(次)
  private Double StateFreq;
  
  //状态累计频率(次)
  private Double AccumFreq;
  
  //递增有效离去率
  private Double DepRP;
  
  //递减有效离去率
  private Double DepRN;
  
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
    
  public Integer getState()
  {
    return State;
  }
    
  public void setState(Integer State)
  {
    this.State = State;
  }
    
  public Double getOutageCapacity()
  {
    return OutageCapacity;
  }
    
  public void setOutageCapacity(Double OutageCapacity)
  {
    this.OutageCapacity = OutageCapacity;
  }
    
  public Double getAvailCapacity()
  {
    return AvailCapacity;
  }
    
  public void setAvailCapacity(Double AvailCapacity)
  {
    this.AvailCapacity = AvailCapacity;
  }
    
  public Double getStateProb()
  {
    return StateProb;
  }
    
  public void setStateProb(Double StateProb)
  {
    this.StateProb = StateProb;
  }
    
  public Double getAccumProb()
  {
    return AccumProb;
  }
    
  public void setAccumProb(Double AccumProb)
  {
    this.AccumProb = AccumProb;
  }
    
  public Double getStateFreq()
  {
    return StateFreq;
  }
    
  public void setStateFreq(Double StateFreq)
  {
    this.StateFreq = StateFreq;
  }
    
  public Double getAccumFreq()
  {
    return AccumFreq;
  }
    
  public void setAccumFreq(Double AccumFreq)
  {
    this.AccumFreq = AccumFreq;
  }
    
  public Double getDepRP()
  {
    return DepRP;
  }
    
  public void setDepRP(Double DepRP)
  {
    this.DepRP = DepRP;
  }
    
  public Double getDepRN()
  {
    return DepRN;
  }
    
  public void setDepRN(Double DepRN)
  {
    this.DepRN = DepRN;
  }
    
  public String toString()
  {
    return "CopTable ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", State = " + State
	 + ", OutageCapacity = " + OutageCapacity
	 + ", AvailCapacity = " + AvailCapacity
	 + ", StateProb = " + StateProb
	 + ", AccumProb = " + AccumProb
	 + ", StateFreq = " + StateFreq
	 + ", AccumFreq = " + AccumFreq
	 + ", DepRP = " + DepRP
	 + ", DepRN = " + DepRN+"]";
  }
    
}
    
