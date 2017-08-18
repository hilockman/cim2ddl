package com.znd.ei.memdb.domain;

/**********************
*共因故障	*
***********************/
class CommonFault
{
  //Id
  private Integer iD;

  //共因故障类型
  private Integer commonFaultType;

  //共因设备类型
  private Integer commonDeviceType;

  //设备类型
  private Integer devType;

  //设备名称
  private String devName;

  //设备索引
  private Integer devIndex;

  //Id
  public Integer getID() {
    return iD;
  }

  public void setID(Integer iD){
    this.iD = iD;
  }

  //共因故障类型
  public Integer getCommonFaultType() {
    return commonFaultType;
  }

  public void setCommonFaultType(Integer commonFaultType){
    this.commonFaultType = commonFaultType;
  }

  //共因设备类型
  public Integer getCommonDeviceType() {
    return commonDeviceType;
  }

  public void setCommonDeviceType(Integer commonDeviceType){
    this.commonDeviceType = commonDeviceType;
  }

  //设备类型
  public Integer getDevType() {
    return devType;
  }

  public void setDevType(Integer devType){
    this.devType = devType;
  }

  //设备名称
  public String getDevName() {
    return devName;
  }

  public void setDevName(String devName){
    this.devName = devName;
  }

  //设备索引
  public Integer getDevIndex() {
    return devIndex;
  }

  public void setDevIndex(Integer devIndex){
    this.devIndex = devIndex;
  }

}
