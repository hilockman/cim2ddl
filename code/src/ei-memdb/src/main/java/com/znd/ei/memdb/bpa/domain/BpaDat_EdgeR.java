package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电网边-直流调压器	*
***********************/
public class BpaDat_EdgeR  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //直流母线名称
  private String DCBusName;
  
  //直流母线电压(kV)
  private Double DCBuskV;
  
  //调压器名称
  private String WindName;
  
  //调压器索引
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
    
  public String getDCBusName()
  {
    return DCBusName;
  }
    
  public void setDCBusName(String DCBusName)
  {
    this.DCBusName = DCBusName;
  }
    
  public Double getDCBuskV()
  {
    return DCBuskV;
  }
    
  public void setDCBuskV(Double DCBuskV)
  {
    this.DCBuskV = DCBuskV;
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
    return "BpaDat_EdgeR ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", DCBusName = " + DCBusName
	 + ", DCBuskV = " + DCBuskV
	 + ", WindName = " + WindName
	 + ", WindPtr = " + WindPtr+"]";
  }
    
}
    
