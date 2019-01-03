package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电网边-直流线路	*
***********************/
public class BpaDat_EdgeDCLine  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //直流母线名称
  private String DCBusName;
  
  //直流母线电压(kV)
  private Double DCBuskV;
  
  //直流线路名称
  private String DCLineName;
  
  //直流线路索引
  private Integer DCLinePtr;
  
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
    
  public String getDCLineName()
  {
    return DCLineName;
  }
    
  public void setDCLineName(String DCLineName)
  {
    this.DCLineName = DCLineName;
  }
    
  public Integer getDCLinePtr()
  {
    return DCLinePtr;
  }
    
  public void setDCLinePtr(Integer DCLinePtr)
  {
    this.DCLinePtr = DCLinePtr;
  }
    
  public String toString()
  {
    return "BpaDat_EdgeDCLine ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", DCBusName = " + DCBusName
	 + ", DCBuskV = " + DCBuskV
	 + ", DCLineName = " + DCLineName
	 + ", DCLinePtr = " + DCLinePtr+"]";
  }
    
}
    
