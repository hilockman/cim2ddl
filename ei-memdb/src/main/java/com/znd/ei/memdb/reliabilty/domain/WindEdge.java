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
  private String Bus;
  
  //母线电压(千伏)
  private Double kV;
  
  //变压器名称
  private String Name;
  
  //变压器索引
  private Integer TranPtr;
  
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
    return Bus;
  }
    
  public void setBus(String Bus)
  {
    this.Bus = Bus;
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
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public Integer getTranPtr()
  {
    return TranPtr;
  }
    
  public void setTranPtr(Integer TranPtr)
  {
    this.TranPtr = TranPtr;
  }
    
  public String toString()
  {
    return "WindEdge ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Bus = " + Bus
	 + ", kV = " + kV
	 + ", Name = " + Name
	 + ", TranPtr = " + TranPtr+"]";
  }
    
}
    
