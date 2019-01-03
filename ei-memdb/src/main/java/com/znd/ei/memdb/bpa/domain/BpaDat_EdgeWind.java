package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电网边-变压器绕组	*
***********************/
public class BpaDat_EdgeWind  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //交流母线名称
  private String ACBusName;
  
  //交流母线电压(kV)
  private Double ACBuskV;
  
  //变压器绕组名称
  private String WindName;
  
  //变压器绕组索引
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
    
  public String getACBusName()
  {
    return ACBusName;
  }
    
  public void setACBusName(String ACBusName)
  {
    this.ACBusName = ACBusName;
  }
    
  public Double getACBuskV()
  {
    return ACBuskV;
  }
    
  public void setACBuskV(Double ACBuskV)
  {
    this.ACBuskV = ACBuskV;
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
	 + ", ACBusName = " + ACBusName
	 + ", ACBuskV = " + ACBuskV
	 + ", WindName = " + WindName
	 + ", WindPtr = " + WindPtr+"]";
  }
    
}
    
