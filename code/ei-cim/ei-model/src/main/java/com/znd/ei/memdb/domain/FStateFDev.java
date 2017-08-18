package com.znd.ei.memdb.domain;

/**********************
*抽样状态下故障设备	*
***********************/
class FStateFDev
{
  //状态索引
  private Integer fState;

  //故障设备类型
  private Integer fDevTyp;

  //故障设备索引
  private Integer fDevIdx;

  //设备故障位置
  private Integer dFltPos;

  //设备故障类型
  private Integer dFltTyp;

  //状态索引
  public Integer getFState( ){
    return fState;
  }

  public void setFState(Integer fState){
    this.fState = fState;
  }

  //故障设备类型
  public Integer getFDevTyp( ){
    return fDevTyp;
  }

  public void setFDevTyp(Integer fDevTyp){
    this.fDevTyp = fDevTyp;
  }

  //故障设备索引
  public Integer getFDevIdx( ){
    return fDevIdx;
  }

  public void setFDevIdx(Integer fDevIdx){
    this.fDevIdx = fDevIdx;
  }

  //设备故障位置
  public Integer getDFltPos( ){
    return dFltPos;
  }

  public void setDFltPos(Integer dFltPos){
    this.dFltPos = dFltPos;
  }

  //设备故障类型
  public Integer getDFltTyp( ){
    return dFltTyp;
  }

  public void setDFltTyp(Integer dFltTyp){
    this.dFltTyp = dFltTyp;
  }

}
