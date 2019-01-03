package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*抽样状态下孤岛损失	*
***********************/
public class FStateMIsland  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //状态ID
  private Integer FStateId;
  
  //状态序号
  private Integer FStateNo;
  
  //孤岛母线
  private Integer OutageBus;
  
  //孤岛负荷功率(兆瓦)
  private Double OutageLoadP;
  
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
    
  public Integer getFStateId()
  {
    return FStateId;
  }
    
  public void setFStateId(Integer FStateId)
  {
    this.FStateId = FStateId;
  }
    
  public Integer getFStateNo()
  {
    return FStateNo;
  }
    
  public void setFStateNo(Integer FStateNo)
  {
    this.FStateNo = FStateNo;
  }
    
  public Integer getOutageBus()
  {
    return OutageBus;
  }
    
  public void setOutageBus(Integer OutageBus)
  {
    this.OutageBus = OutageBus;
  }
    
  public Double getOutageLoadP()
  {
    return OutageLoadP;
  }
    
  public void setOutageLoadP(Double OutageLoadP)
  {
    this.OutageLoadP = OutageLoadP;
  }
    
  public String toString()
  {
    return "FStateMIsland ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", FStateId = " + FStateId
	 + ", FStateNo = " + FStateNo
	 + ", OutageBus = " + OutageBus
	 + ", OutageLoadP = " + OutageLoadP+"]";
  }
    
}
    
