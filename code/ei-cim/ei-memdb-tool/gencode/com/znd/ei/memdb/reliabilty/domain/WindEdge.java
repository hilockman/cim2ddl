package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*变压器绕组边	*
***********************/
public class WindEdge  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
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
    
  public Integer getMemIndex()
  {
    return memIndex;
  }
    
  public void setMemIndex(Integer memIndex)
  {
    this.memIndex = memIndex;
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
    
  public String toString()
  {
    return "WindEdge ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", bus = " + bus
	 + ", kV = " + kV
	 + ", name = " + name
	 + ", tranPtr = " + tranPtr+"]";
  }
    
}
    
