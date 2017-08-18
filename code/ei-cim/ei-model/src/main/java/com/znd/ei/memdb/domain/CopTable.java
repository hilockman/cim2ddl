package com.znd.ei.memdb.domain;

/**********************
*停运概率	*
***********************/
class CopTable
{
  //状态
  private Integer state;

  //停运发电容量(MW)
  private Double outageCapacity;

  //可用发电容量(MW)
  private Double availCapacity;

  //状态概率
  private Double stateProb;

  //状态累计概率
  private Double accumProb;

  //状态频率(次)
  private Double stateFreq;

  //状态累计频率(次)
  private Double accumFreq;

  //递增有效离去率
  private Double depRP;

  //递减有效离去率
  private Double depRN;

  //状态
  public Integer getState( ){
    return state;
  }

  public void setState(Integer state){
    this.state = state;
  }

  //停运发电容量(MW)
  public Double getOutageCapacity( ){
    return outageCapacity;
  }

  public void setOutageCapacity(Double outageCapacity){
    this.outageCapacity = outageCapacity;
  }

  //可用发电容量(MW)
  public Double getAvailCapacity( ){
    return availCapacity;
  }

  public void setAvailCapacity(Double availCapacity){
    this.availCapacity = availCapacity;
  }

  //状态概率
  public Double getStateProb( ){
    return stateProb;
  }

  public void setStateProb(Double stateProb){
    this.stateProb = stateProb;
  }

  //状态累计概率
  public Double getAccumProb( ){
    return accumProb;
  }

  public void setAccumProb(Double accumProb){
    this.accumProb = accumProb;
  }

  //状态频率(次)
  public Double getStateFreq( ){
    return stateFreq;
  }

  public void setStateFreq(Double stateFreq){
    this.stateFreq = stateFreq;
  }

  //状态累计频率(次)
  public Double getAccumFreq( ){
    return accumFreq;
  }

  public void setAccumFreq(Double accumFreq){
    this.accumFreq = accumFreq;
  }

  //递增有效离去率
  public Double getDepRP( ){
    return depRP;
  }

  public void setDepRP(Double depRP){
    this.depRP = depRP;
  }

  //递减有效离去率
  public Double getDepRN( ){
    return depRN;
  }

  public void setDepRN(Double depRN){
    this.depRN = depRN;
  }

}
