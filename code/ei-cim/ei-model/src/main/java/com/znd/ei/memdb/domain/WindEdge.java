package com.znd.ei.memdb.domain;

/**********************
*变压器绕组边	*
***********************/
class WindEdge
{
  //母线名称
  private String bus;

  //母线电压(kV)
  private Double kV;

  //变压器名称
  private String name;

  //变压器索引
  private Integer tranPtr;

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

  //变压器名称
  public String getName( ){
    return name;
  }

  public void setName(String name){
    this.name = name;
  }

  //变压器索引
  public Integer getTranPtr( ){
    return tranPtr;
  }

  public void setTranPtr(Integer tranPtr){
    this.tranPtr = tranPtr;
  }

}
