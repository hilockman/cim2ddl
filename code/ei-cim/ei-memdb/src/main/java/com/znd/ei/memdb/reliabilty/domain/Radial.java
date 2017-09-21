package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*环辐网	*
***********************/
@Entity
public class Radial
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //环网(环辐边界)母线名称
  private String ringBus;
  
  //环网(环辐边界)母线电压(kV)
  private Double ringkV;
  
  //辐射网内负荷(MW)
  private Double loadP;
  
  //环网(环辐边界)母线索引
  private Integer ringBoundBusPtr;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public String getRingBus() 
  {
    return ringBus;
  }
    
  public void setRingBus(String ringBus)
  {
    this.ringBus = ringBus;
  }
    
  public Double getRingkV() 
  {
    return ringkV;
  }
    
  public void setRingkV(Double ringkV)
  {
    this.ringkV = ringkV;
  }
    
  public Double getLoadP() 
  {
    return loadP;
  }
    
  public void setLoadP(Double loadP)
  {
    this.loadP = loadP;
  }
    
  public Integer getRingBoundBusPtr() 
  {
    return ringBoundBusPtr;
  }
    
  public void setRingBoundBusPtr(Integer ringBoundBusPtr)
  {
    this.ringBoundBusPtr = ringBoundBusPtr;
  }
    
}
    
