package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*开断故障下孤岛信息	*
***********************/
@Entity
public class TripMIsland
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //开断故障索引
  private Integer trip;
  
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
    
  public Integer getTrip() 
  {
    return trip;
  }
    
  public void setTrip(Integer trip)
  {
    this.trip = trip;
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
    
}
    
