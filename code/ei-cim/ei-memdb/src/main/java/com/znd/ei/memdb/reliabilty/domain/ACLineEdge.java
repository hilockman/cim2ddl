package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*交流线路边	*
***********************/
@Entity
public class ACLineEdge
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //母线名称
  private String bus;
  
  //母线电压(kV)
  private Double kV;
  
  //线路名称
  private String name;
  
  //线路索引
  private Integer linePtr;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public String getBus() 
  {
    return bus;
  }
    
  public void setBus(String bus)
  {
    this.bus = bus;
  }
    
  public Double getkV() 
  {
    return kV;
  }
    
  public void setkV(Double kV)
  {
    this.kV = kV;
  }
    
  public String getName() 
  {
    return name;
  }
    
  public void setName(String name)
  {
    this.name = name;
  }
    
  public Integer getLinePtr() 
  {
    return linePtr;
  }
    
  public void setLinePtr(Integer linePtr)
  {
    this.linePtr = linePtr;
  }
    
}
    
