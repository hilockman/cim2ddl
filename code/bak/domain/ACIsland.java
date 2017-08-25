package com.znd.ei.memdb.domain;

/**********************
*交流电岛	*
***********************/
class ACIsland
{
  //岛发电(MW)
  private Double genP;

  //岛负荷(MW)
  private Double loadP;

  //岛内母线数
  private Integer busNum;

  //平衡节点
  private Integer swingBus;

  //死岛
  private Integer dead;

  //岛发电(MW)
  public Double getGenP( ){
    return genP;
  }

  public void setGenP(Double genP){
    this.genP = genP;
  }

  //岛负荷(MW)
  public Double getLoadP( ){
    return loadP;
  }

  public void setLoadP(Double loadP){
    this.loadP = loadP;
  }

  //岛内母线数
  public Integer getBusNum( ){
    return busNum;
  }

  public void setBusNum(Integer busNum){
    this.busNum = busNum;
  }

  //平衡节点
  public Integer getSwingBus( ){
    return swingBus;
  }

  public void setSwingBus(Integer swingBus){
    this.swingBus = swingBus;
  }

  //死岛
  public Integer getDead( ){
    return dead;
  }

  public void setDead(Integer dead){
    this.dead = dead;
  }

}
