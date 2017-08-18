package com.znd.ei.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*开断故障下越限信息	*
***********************/
@Entity
class TripOvlDev
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //开断故障索引
  private Integer trip;
  
  //越限设备类型
  private Integer ovlmtDevTyp;
  
  //越限设备索引
  private Integer ovlmtDevIdx;
  
  //越限值(MW)
  private Double ovLmtValue;
  
  //额定值(MW)
  private Double rated;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public Integer getTrip() 
  {
    return trip;
  }
    
  public void setTrip(Integer trip)
  {
    this.trip = trip;
  }
    
  public Integer getOvlmtDevTyp() 
  {
    return ovlmtDevTyp;
  }
    
  public void setOvlmtDevTyp(Integer ovlmtDevTyp)
  {
    this.ovlmtDevTyp = ovlmtDevTyp;
  }
    
  public Integer getOvlmtDevIdx() 
  {
    return ovlmtDevIdx;
  }
    
  public void setOvlmtDevIdx(Integer ovlmtDevIdx)
  {
    this.ovlmtDevIdx = ovlmtDevIdx;
  }
    
  public Double getOvLmtValue() 
  {
    return ovLmtValue;
  }
    
  public void setOvLmtValue(Double ovLmtValue)
  {
    this.ovLmtValue = ovLmtValue;
  }
    
  public Double getRated() 
  {
    return rated;
  }
    
  public void setRated(Double rated)
  {
    this.rated = rated;
  }
    
}
    
