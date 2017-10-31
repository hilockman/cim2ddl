package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*环辐网	*
***********************/
public class Radial  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //环网(环辐边界)母线名称
  private String ringBus;
  
  //环网(环辐边界)母线电压(kV)
  private Double ringkV;
  
  //辐射网内负荷(MW)
  private Double loadP;
  
  //环网(环辐边界)母线索引
  private Integer ringBoundBusPtr;
  
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
    
  public String getRingBus()
  {
    return ringBus;
  }
    
  public void setRingBus(String ringBus)
  {
    this.ringBus = ringBus;
  }
    
  public Double getRingkV()
  {
    return ringkV;
  }
    
  public void setRingkV(Double ringkV)
  {
    this.ringkV = ringkV;
  }
    
  public Double getLoadP()
  {
    return loadP;
  }
    
  public void setLoadP(Double loadP)
  {
    this.loadP = loadP;
  }
    
  public Integer getRingBoundBusPtr()
  {
    return ringBoundBusPtr;
  }
    
  public void setRingBoundBusPtr(Integer ringBoundBusPtr)
  {
    this.ringBoundBusPtr = ringBoundBusPtr;
  }
    
  public String toString()
  {
    return "Radial ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ringBus = " + ringBus
	 + ", ringkV = " + ringkV
	 + ", loadP = " + loadP
	 + ", ringBoundBusPtr = " + ringBoundBusPtr+"]";
  }
    
}
    
