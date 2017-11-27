package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*开断故障下孤岛信息	*
***********************/
public class TripMIsland  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //开断故障索引
  private Integer Trip;
  
  //孤岛母线
  private Integer OutageBus;
  
  //孤岛负荷功率(MW)
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
    
  public Integer getTrip()
  {
    return Trip;
  }
    
  public void setTrip(Integer Trip)
  {
    this.Trip = Trip;
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
    return "TripMIsland ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Trip = " + Trip
	 + ", OutageBus = " + OutageBus
	 + ", OutageLoadP = " + OutageLoadP+"]";
  }
    
}
    
