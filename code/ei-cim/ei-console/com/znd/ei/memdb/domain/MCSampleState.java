package com.znd.ei.memdb.domain;

/**********************
*蒙特卡罗抽样状态	*
***********************/
class MCSampleState
{
  //状态索引
  private Integer fState;

  //损失负荷状态
  private Integer outLoad;

  //多状态场景
  private Integer mState;

  //状态索引
  public Integer getFState() {
    return fState;
  }

  public void setFState(Integer fState){
    this.fState = fState;
  }

  //损失负荷状态
  public Integer getOutLoad() {
    return outLoad;
  }

  public void setOutLoad(Integer outLoad){
    this.outLoad = outLoad;
  }

  //多状态场景
  public Integer getMState() {
    return mState;
  }

  public void setMState(Integer mState){
    this.mState = mState;
  }

}
