package com.znd.ei.memdb.domain;

/**********************
*分区	*
***********************/
class Zone
{
  //分区名称
  private String name;

  //区域名称
  private String area;

  //分区发电(MW)
  private Double totalGenP;

  //分区负荷(MW)
  private Double totalLoadP;

  //分区事故切负荷(MW)
  private Double fCutLoadP;

  //分区名称
  public String getName( ){
    return name;
  }

  public void setName(String name){
    this.name = name;
  }

  //区域名称
  public String getArea( ){
    return area;
  }

  public void setArea(String area){
    this.area = area;
  }

  //分区发电(MW)
  public Double getTotalGenP( ){
    return totalGenP;
  }

  public void setTotalGenP(Double totalGenP){
    this.totalGenP = totalGenP;
  }

  //分区负荷(MW)
  public Double getTotalLoadP( ){
    return totalLoadP;
  }

  public void setTotalLoadP(Double totalLoadP){
    this.totalLoadP = totalLoadP;
  }

  //分区事故切负荷(MW)
  public Double getFCutLoadP( ){
    return fCutLoadP;
  }

  public void setFCutLoadP(Double fCutLoadP){
    this.fCutLoadP = fCutLoadP;
  }

}
