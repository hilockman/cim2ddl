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
  private String RingBus;
  
  //环网(环辐边界)母线电压(千伏)
  private Double RingkV;
  
  //辐射网内负荷(兆瓦)
  private Double LoadP;
  
  //环网(环辐边界)母线索引
  private Integer RingBoundBusPtr;
  
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
    return RingBus;
  }
    
  public void setRingBus(String RingBus)
  {
    this.RingBus = RingBus;
  }
    
  public Double getRingkV()
  {
    return RingkV;
  }
    
  public void setRingkV(Double RingkV)
  {
    this.RingkV = RingkV;
  }
    
  public Double getLoadP()
  {
    return LoadP;
  }
    
  public void setLoadP(Double LoadP)
  {
    this.LoadP = LoadP;
  }
    
  public Integer getRingBoundBusPtr()
  {
    return RingBoundBusPtr;
  }
    
  public void setRingBoundBusPtr(Integer RingBoundBusPtr)
  {
    this.RingBoundBusPtr = RingBoundBusPtr;
  }
    
  public String toString()
  {
    return "Radial ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", RingBus = " + RingBus
	 + ", RingkV = " + RingkV
	 + ", LoadP = " + LoadP
	 + ", RingBoundBusPtr = " + RingBoundBusPtr+"]";
  }
    
}
    
