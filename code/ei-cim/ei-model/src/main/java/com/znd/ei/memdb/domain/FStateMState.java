package com.znd.ei.memdb.domain;

/**********************
*抽样状态下多状态	*
***********************/
class FStateMState
{
  //多状态设备类型
  private Integer mSDevType;

  //多状态设备索引
  private Integer mSDevIndex;

  //多状态出力状态
  private Double mStatePout;

  //多状态设备类型
  public Integer getMSDevType( ){
    return mSDevType;
  }

  public void setMSDevType(Integer mSDevType){
    this.mSDevType = mSDevType;
  }

  //多状态设备索引
  public Integer getMSDevIndex( ){
    return mSDevIndex;
  }

  public void setMSDevIndex(Integer mSDevIndex){
    this.mSDevIndex = mSDevIndex;
  }

  //多状态出力状态
  public Double getMStatePout( ){
    return mStatePout;
  }

  public void setMStatePout(Double mStatePout){
    this.mStatePout = mStatePout;
  }

}
