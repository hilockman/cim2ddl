package com.znd.ei.memdb.domain;

/**********************
*交流线路边	*
***********************/
class ACLineEdge
{
  //母线名称
  private String bus;

  //母线电压(kV)
  private Double kV;

  //线路名称
  private String name;

  //线路索引
  private Integer linePtr;

  //母线名称
  public String getBus( ){
    return bus;
  }

  public void setBus(String bus){
    this.bus = bus;
  }

  //母线电压(kV)
  public Double getkV( ){
    return kV;
  }

  public void setkV(Double kV){
    this.kV = kV;
  }

  //线路名称
  public String getName( ){
    return name;
  }

  public void setName(String name){
    this.name = name;
  }

  //线路索引
  public Integer getLinePtr( ){
    return linePtr;
  }

  public void setLinePtr(Integer linePtr){
    this.linePtr = linePtr;
  }

}
