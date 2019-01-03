package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电网边-线路高抗	*
***********************/
public class BpaDat_EdgeLineHG  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //交流母线名称
  private String ACBusName;
  
  //交流母线电压(kV)
  private Double ACBuskV;
  
  //线路高抗名称
  private String LineHGName;
  
  //线路高抗索引
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
	 + ", ACBusName = " + ACBusName
	 + ", ACBuskV = " + ACBuskV
	 + ", LineHGName = " + LineHGName
	 + ", LineHGPtr = " + LineHGPtr+"]";
  }
    
}
    
