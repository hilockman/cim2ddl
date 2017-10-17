package com.znd.ei.memdb.reliabilty.domain;


/**********************
*开断故障下越限信息	*
***********************/
public class TripOvlDev
{
  private Integer id;
  
  private Integer memIndex;
  
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
    
  public String toString()
  {
    return "TripOvlDev ["+	"id"=id,
	"memIndex"=memIndex,
	"trip"=trip,
	"ovlmtDevTyp"=ovlmtDevTyp,
	"ovlmtDevIdx"=ovlmtDevIdx,
	"ovLmtValue"=ovLmtValue,
	"rated"=rated+"]"
  }
    
}
    
