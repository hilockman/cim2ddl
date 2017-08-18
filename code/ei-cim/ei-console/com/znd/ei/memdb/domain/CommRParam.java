package com.znd.ei.memdb.domain;

/**********************
*可靠性公共参数	*
***********************/
class CommRParam
{
  //设备类型
  private Integer devType;

  //关键字
  private String keyWord;

  //容量上限
  private Double upCapLmt;

  //容量下限
  private Double dnCapLmt;

  //电压上限
  private Double upVLmt;

  //电压下限
  private Double dnVLmt;

  //故障率
  private Double rerr;

  //修复时间
  private Double trep;

  //设备类型
  public Integer getDevType() {
    return devType;
  }

  public void setDevType(Integer devType){
    this.devType = devType;
  }

  //关键字
  public String getKeyWord() {
    return keyWord;
  }

  public void setKeyWord(String keyWord){
    this.keyWord = keyWord;
  }

  //容量上限
  public Double getUpCapLmt() {
    return upCapLmt;
  }

  public void setUpCapLmt(Double upCapLmt){
    this.upCapLmt = upCapLmt;
  }

  //容量下限
  public Double getDnCapLmt() {
    return dnCapLmt;
  }

  public void setDnCapLmt(Double dnCapLmt){
    this.dnCapLmt = dnCapLmt;
  }

  //电压上限
  public Double getUpVLmt() {
    return upVLmt;
  }

  public void setUpVLmt(Double upVLmt){
    this.upVLmt = upVLmt;
  }

  //电压下限
  public Double getDnVLmt() {
    return dnVLmt;
  }

  public void setDnVLmt(Double dnVLmt){
    this.dnVLmt = dnVLmt;
  }

  //故障率
  public Double getRerr() {
    return rerr;
  }

  public void setRerr(Double rerr){
    this.rerr = rerr;
  }

  //修复时间
  public Double getTrep() {
    return trep;
  }

  public void setTrep(Double trep){
    this.trep = trep;
  }

}
