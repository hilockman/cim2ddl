package com.znd.ei.memdb.domain;

/**********************
*抽样状态下孤岛损失	*
***********************/
class FStateMIsland
{
  //状态索引
  private Integer fState;

  //孤岛母线
  private Integer outageBus;

  //孤岛负荷功率(MW)
  private Double outageLoadP;

  //状态索引
  public Integer getFState( ){
    return fState;
  }

  public void setFState(Integer fState){
    this.fState = fState;
  }

  //孤岛母线
  public Integer getOutageBus( ){
    return outageBus;
  }

  public void setOutageBus(Integer outageBus){
    this.outageBus = outageBus;
  }

  //孤岛负荷功率(MW)
  public Double getOutageLoadP( ){
    return outageLoadP;
  }

  public void setOutageLoadP(Double outageLoadP){
    this.outageLoadP = outageLoadP;
  }

}
