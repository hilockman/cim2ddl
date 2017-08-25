package com.znd.ei.memdb.domain;

/**********************
*环辐网	*
***********************/
class Radial
{
  //环网(环辐边界)母线名称
  private String ringBus;

  //环网(环辐边界)母线电压(kV)
  private Double ringkV;

  //辐射网内负荷(MW)
  private Double loadP;

  //环网(环辐边界)母线索引
  private Integer ringBoundBusPtr;

  //环网(环辐边界)母线名称
  public String getRingBus( ){
    return ringBus;
  }

  public void setRingBus(String ringBus){
    this.ringBus = ringBus;
  }

  //环网(环辐边界)母线电压(kV)
  public Double getRingkV( ){
    return ringkV;
  }

  public void setRingkV(Double ringkV){
    this.ringkV = ringkV;
  }

  //辐射网内负荷(MW)
  public Double getLoadP( ){
    return loadP;
  }

  public void setLoadP(Double loadP){
    this.loadP = loadP;
  }

  //环网(环辐边界)母线索引
  public Integer getRingBoundBusPtr( ){
    return ringBoundBusPtr;
  }

  public void setRingBoundBusPtr(Integer ringBoundBusPtr){
    this.ringBoundBusPtr = ringBoundBusPtr;
  }

}
