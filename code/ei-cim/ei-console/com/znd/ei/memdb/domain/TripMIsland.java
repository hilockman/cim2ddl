package com.znd.ei.memdb.domain;

/**********************
*开断故障下孤岛信息	*
***********************/
class TripMIsland
{
  //开断故障索引
  private Integer trip;

  //孤岛母线
  private Integer outageBus;

  //孤岛负荷功率(MW)
  private Double outageLoadP;

  //开断故障索引
  public Integer getTrip() {
    return trip;
  }

  public void setTrip(Integer trip){
    this.trip = trip;
  }

  //孤岛母线
  public Integer getOutageBus() {
    return outageBus;
  }

  public void setOutageBus(Integer outageBus){
    this.outageBus = outageBus;
  }

  //孤岛负荷功率(MW)
  public Double getOutageLoadP() {
    return outageLoadP;
  }

  public void setOutageLoadP(Double outageLoadP){
    this.outageLoadP = outageLoadP;
  }

}
