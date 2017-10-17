package com.znd.ei.memdb.reliabilty.domain;


/**********************
*停运概率	*
***********************/
public class CopTable
{
  private Integer id;
  
  private Integer memIndex;
  
  //状态
  private Integer state;
  
  //停运发电容量(MW)
  private Double outageCapacity;
  
  //可用发电容量(MW)
  private Double availCapacity;
  
  //状态概率
  private Double stateProb;
  
  //状态累计概率
  private Double accumProb;
  
  //状态频率(次)
  private Double stateFreq;
  
  //状态累计频率(次)
  private Double accumFreq;
  
  //递增有效离去率
  private Double depRP;
  
  //递减有效离去率
  private Double depRN;
  
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
    return state;
  }
    
  public void setState(Integer state)
  {
    this.state = state;
  }
    
  public Double getOutageCapacity()
  {
    return outageCapacity;
  }
    
  public void setOutageCapacity(Double outageCapacity)
  {
    this.outageCapacity = outageCapacity;
  }
    
  public Double getAvailCapacity()
  {
    return availCapacity;
  }
    
  public void setAvailCapacity(Double availCapacity)
  {
    this.availCapacity = availCapacity;
  }
    
  public Double getStateProb()
  {
    return stateProb;
  }
    
  public void setStateProb(Double stateProb)
  {
    this.stateProb = stateProb;
  }
    
  public Double getAccumProb()
  {
    return accumProb;
  }
    
  public void setAccumProb(Double accumProb)
  {
    this.accumProb = accumProb;
  }
    
  public Double getStateFreq()
  {
    return stateFreq;
  }
    
  public void setStateFreq(Double stateFreq)
  {
    this.stateFreq = stateFreq;
  }
    
  public Double getAccumFreq()
  {
    return accumFreq;
  }
    
  public void setAccumFreq(Double accumFreq)
  {
    this.accumFreq = accumFreq;
  }
    
  public Double getDepRP()
  {
    return depRP;
  }
    
  public void setDepRP(Double depRP)
  {
    this.depRP = depRP;
  }
    
  public Double getDepRN()
  {
    return depRN;
  }
    
  public void setDepRN(Double depRN)
  {
    this.depRN = depRN;
  }
    
  public String toString()
  {
    return "CopTable ["+	"id"=id,
	"memIndex"=memIndex,
	"state"=state,
	"outageCapacity"=outageCapacity,
	"availCapacity"=availCapacity,
	"stateProb"=stateProb,
	"accumProb"=accumProb,
	"stateFreq"=stateFreq,
	"accumFreq"=accumFreq,
	"depRP"=depRP,
	"depRN"=depRN+"]"
  }
    
}
    
