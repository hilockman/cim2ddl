package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电网边-线路	*
***********************/
public class BpaDat_EdgeLine  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //母线名称
  private String BusName;
  
  //母线电压(kV)
  private Double BuskV;
  
  //线路名称
  private String LineName;
  
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
    
  public String getLineName()
  {
    return LineName;
  }
    
  public void setLineName(String LineName)
  {
    this.LineName = LineName;
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
    return "BpaDat_EdgeLine ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", BusName = " + BusName
	 + ", BuskV = " + BuskV
	 + ", LineName = " + LineName
	 + ", LinePtr = " + LinePtr+"]";
  }
    
}
    
