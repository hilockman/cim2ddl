package com.znd.ei.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*变压器绕组边	*
***********************/
@Entity
public class WindEdge
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //母线名称
  private String bus;
  
  //母线电压(kV)
  private Double kV;
  
  //变压器名称
  private String name;
  
  //变压器索引
  private Integer tranPtr;
  
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
    
  public Integer getTranPtr() 
  {
    return tranPtr;
  }
    
  public void setTranPtr(Integer tranPtr)
  {
    this.tranPtr = tranPtr;
  }
    
}
    
