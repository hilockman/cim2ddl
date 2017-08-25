package com.znd.ei.memdb.domain;

/**********************
*开断故障下越限信息	*
***********************/
class TripOvlDev
{
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

  //开断故障索引
  public Integer getTrip( ){
    return trip;
  }

  public void setTrip(Integer trip){
    this.trip = trip;
  }

  //越限设备类型
  public Integer getOvlmtDevTyp( ){
    return ovlmtDevTyp;
  }

  public void setOvlmtDevTyp(Integer ovlmtDevTyp){
    this.ovlmtDevTyp = ovlmtDevTyp;
  }

  //越限设备索引
  public Integer getOvlmtDevIdx( ){
    return ovlmtDevIdx;
  }

  public void setOvlmtDevIdx(Integer ovlmtDevIdx){
    this.ovlmtDevIdx = ovlmtDevIdx;
  }

  //越限值(MW)
  public Double getOvLmtValue( ){
    return ovLmtValue;
  }

  public void setOvLmtValue(Double ovLmtValue){
    this.ovLmtValue = ovLmtValue;
  }

  //额定值(MW)
  public Double getRated( ){
    return rated;
  }

  public void setRated(Double rated){
    this.rated = rated;
  }

}
