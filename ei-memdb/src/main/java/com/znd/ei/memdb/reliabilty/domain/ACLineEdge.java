package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*交流线路边	*
***********************/
public class ACLineEdge  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //母线名称
  private String Bus;
  
  //母线电压(千伏)
  private Double kV;
  
  //线路名称
  private String Name;
  
  //线路索引
  private Integer LinePtr;
  
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
    
  public Integer getLinePtr()
  {
    return LinePtr;
  }
    
  public void setLinePtr(Integer LinePtr)
  {
    this.LinePtr = LinePtr;
  }
    
  public String toString()
  {
    return "ACLineEdge ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Bus = " + Bus
	 + ", kV = " + kV
	 + ", Name = " + Name
	 + ", LinePtr = " + LinePtr+"]";
  }
    
}
    
