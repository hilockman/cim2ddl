package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*抽样状态下孤岛损失	*
***********************/
public class FStateMIsland  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //状态索引
  private Integer fState;
  
  //孤岛母线
  private Integer outageBus;
  
  //孤岛负荷功率(MW)
  private Double outageLoadP;
  
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
    
  public Integer getFState()
  {
    return fState;
  }
    
  public void setFState(Integer fState)
  {
    this.fState = fState;
  }
    
  public Integer getOutageBus()
  {
    return outageBus;
  }
    
  public void setOutageBus(Integer outageBus)
  {
    this.outageBus = outageBus;
  }
    
  public Double getOutageLoadP()
  {
    return outageLoadP;
  }
    
  public void setOutageLoadP(Double outageLoadP)
  {
    this.outageLoadP = outageLoadP;
  }
    
  public String toString()
  {
    return "FStateMIsland ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", fState = " + fState
	 + ", outageBus = " + outageBus
	 + ", outageLoadP = " + outageLoadP+"]";
  }
    
}
    
