package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电网边-高抗	*
***********************/
public class BpaDat_EdgeLineHG  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //母线名称
  private String BusName;
  
  //母线电压(kV)
  private Double BuskV;
  
  //高抗名称
  private String LineHGName;
  
  //高抗索引
  private Integer LineHGPtr;
  
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
    
  public String getLineHGName()
  {
    return LineHGName;
  }
    
  public void setLineHGName(String LineHGName)
  {
    this.LineHGName = LineHGName;
  }
    
  public Integer getLineHGPtr()
  {
    return LineHGPtr;
  }
    
  public void setLineHGPtr(Integer LineHGPtr)
  {
    this.LineHGPtr = LineHGPtr;
  }
    
  public String toString()
  {
    return "BpaDat_EdgeLineHG ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", BusName = " + BusName
	 + ", BuskV = " + BuskV
	 + ", LineHGName = " + LineHGName
	 + ", LineHGPtr = " + LineHGPtr+"]";
  }
    
}
    
