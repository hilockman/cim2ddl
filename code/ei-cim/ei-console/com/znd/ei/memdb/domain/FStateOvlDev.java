package com.znd.ei.memdb.domain;

/**********************
*抽样状态下越限设备	*
***********************/
class FStateOvlDev
{
  //状态索引
  private Integer fState;

  //越限设备类型
  private Integer devTyp;

  //越限设备索引
  private Integer devIdx;

  //越限值(MW)
  private Double ovLmtP;

  //额定值(MW)
  private Double rated;

  //消限值(MW)
  private Double adLmtP;

  //状态索引
  public Integer getFState() {
    return fState;
  }

  public void setFState(Integer fState){
    this.fState = fState;
  }

  //越限设备类型
  public Integer getDevTyp() {
    return devTyp;
  }

  public void setDevTyp(Integer devTyp){
    this.devTyp = devTyp;
  }

  //越限设备索引
  public Integer getDevIdx() {
    return devIdx;
  }

  public void setDevIdx(Integer devIdx){
    this.devIdx = devIdx;
  }

  //越限值(MW)
  public Double getOvLmtP() {
    return ovLmtP;
  }

  public void setOvLmtP(Double ovLmtP){
    this.ovLmtP = ovLmtP;
  }

  //额定值(MW)
  public Double getRated() {
    return rated;
  }

  public void setRated(Double rated){
    this.rated = rated;
  }

  //消限值(MW)
  public Double getAdLmtP() {
    return adLmtP;
  }

  public void setAdLmtP(Double adLmtP){
    this.adLmtP = adLmtP;
  }

}
