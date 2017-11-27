package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电网边-变压器绕组	*
***********************/
public class BpaDat_EdgeWind  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //母线名称
  private String BusName;
  
  //母线电压(kV)
  private Double BuskV;
  
  //绕组名称
  private String WindName;
  
  //绕组索引
  private Integer WindPtr;
  
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
    
  public String getBusName()
  {
    return BusName;
  }
    
  public void setBusName(String BusName)
  {
    this.BusName = BusName;
  }
    
  public Double getBuskV()
  {
    return BuskV;
  }
    
  public void setBuskV(Double BuskV)
  {
    this.BuskV = BuskV;
  }
    
  public String getWindName()
  {
    return WindName;
  }
    
  public void setWindName(String WindName)
  {
    this.WindName = WindName;
  }
    
  public Integer getWindPtr()
  {
    return WindPtr;
  }
    
  public void setWindPtr(Integer WindPtr)
  {
    this.WindPtr = WindPtr;
  }
    
  public String toString()
  {
    return "BpaDat_EdgeWind ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", BusName = " + BusName
	 + ", BuskV = " + BuskV
	 + ", WindName = " + WindName
	 + ", WindPtr = " + WindPtr+"]";
  }
    
}
    
