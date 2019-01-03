package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电网边-交流线路	*
***********************/
public class BpaDat_EdgeACLine  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //交流母线名称
  private String ACBusName;
  
  //交流母线电压(kV)
  private Double ACBuskV;
  
  //交流线路名称
  private String ACLineName;
  
  //交流线路索引
  private Integer ACLinePtr;
  
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
    
  public String getACLineName()
  {
    return ACLineName;
  }
    
  public void setACLineName(String ACLineName)
  {
    this.ACLineName = ACLineName;
  }
    
  public Integer getACLinePtr()
  {
    return ACLinePtr;
  }
    
  public void setACLinePtr(Integer ACLinePtr)
  {
    this.ACLinePtr = ACLinePtr;
  }
    
  public String toString()
  {
    return "BpaDat_EdgeACLine ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ACBusName = " + ACBusName
	 + ", ACBuskV = " + ACBuskV
	 + ", ACLineName = " + ACLineName
	 + ", ACLinePtr = " + ACLinePtr+"]";
  }
    
}
    
