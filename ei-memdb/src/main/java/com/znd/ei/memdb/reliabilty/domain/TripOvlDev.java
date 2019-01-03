package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*开断故障下越限信息	*
***********************/
public class TripOvlDev  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //开断故障索引
  private Integer Trip;
  
  //越限设备类型
  private Integer OvlmtDevTyp;
  
  //越限设备索引
  private Integer OvlmtDevIdx;
  
  //越限值(兆瓦)
  private Double OvLmtValue;
  
  //额定值(兆瓦)
  private Double Rated;
  
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
    
  public Integer getTrip()
  {
    return Trip;
  }
    
  public void setTrip(Integer Trip)
  {
    this.Trip = Trip;
  }
    
  public Integer getOvlmtDevTyp()
  {
    return OvlmtDevTyp;
  }
    
  public void setOvlmtDevTyp(Integer OvlmtDevTyp)
  {
    this.OvlmtDevTyp = OvlmtDevTyp;
  }
    
  public Integer getOvlmtDevIdx()
  {
    return OvlmtDevIdx;
  }
    
  public void setOvlmtDevIdx(Integer OvlmtDevIdx)
  {
    this.OvlmtDevIdx = OvlmtDevIdx;
  }
    
  public Double getOvLmtValue()
  {
    return OvLmtValue;
  }
    
  public void setOvLmtValue(Double OvLmtValue)
  {
    this.OvLmtValue = OvLmtValue;
  }
    
  public Double getRated()
  {
    return Rated;
  }
    
  public void setRated(Double Rated)
  {
    this.Rated = Rated;
  }
    
  public String toString()
  {
    return "TripOvlDev ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Trip = " + Trip
	 + ", OvlmtDevTyp = " + OvlmtDevTyp
	 + ", OvlmtDevIdx = " + OvlmtDevIdx
	 + ", OvLmtValue = " + OvLmtValue
	 + ", Rated = " + Rated+"]";
  }
    
}
    
