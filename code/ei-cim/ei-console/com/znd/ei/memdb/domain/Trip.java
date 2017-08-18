package com.znd.ei.memdb.domain;

/**********************
*开断故障信息	*
***********************/
class Trip
{
  //开断设备数
  private Integer tripDevNum;

  //开断设备1类型
  private Integer trB1Type;

  //开断设备1索引
  private Integer trB1Bran;

  //开断设备2类型
  private Integer trB2Type;

  //开断设备2索引
  private Integer trB2Bran;

  //故障类型
  private Integer faultType;

  //失电总负荷
  private Double outageLoadP;

  //是否越限
  private Integer overLmt;

  //开断设备数
  public Integer getTripDevNum() {
    return tripDevNum;
  }

  public void setTripDevNum(Integer tripDevNum){
    this.tripDevNum = tripDevNum;
  }

  //开断设备1类型
  public Integer getTrB1Type() {
    return trB1Type;
  }

  public void setTrB1Type(Integer trB1Type){
    this.trB1Type = trB1Type;
  }

  //开断设备1索引
  public Integer getTrB1Bran() {
    return trB1Bran;
  }

  public void setTrB1Bran(Integer trB1Bran){
    this.trB1Bran = trB1Bran;
  }

  //开断设备2类型
  public Integer getTrB2Type() {
    return trB2Type;
  }

  public void setTrB2Type(Integer trB2Type){
    this.trB2Type = trB2Type;
  }

  //开断设备2索引
  public Integer getTrB2Bran() {
    return trB2Bran;
  }

  public void setTrB2Bran(Integer trB2Bran){
    this.trB2Bran = trB2Bran;
  }

  //故障类型
  public Integer getFaultType() {
    return faultType;
  }

  public void setFaultType(Integer faultType){
    this.faultType = faultType;
  }

  //失电总负荷
  public Double getOutageLoadP() {
    return outageLoadP;
  }

  public void setOutageLoadP(Double outageLoadP){
    this.outageLoadP = outageLoadP;
  }

  //是否越限
  public Integer getOverLmt() {
    return overLmt;
  }

  public void setOverLmt(Integer overLmt){
    this.overLmt = overLmt;
  }

}
