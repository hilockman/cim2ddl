package com.znd.ei.memdb.domain;

/**********************
*可控串联补偿装置	*
***********************/
class TCSC
{
  //交流线路名称
  private String name;

  //安装母线名
  private String installBus;

  //串联电抗值(pu)
  private Double x;

  //故障率(次/年)
  private Double rerr;

  //修复率(次/年)
  private Double rrep;

  //修复时间(小时/次)
  private Double trep;

  //完好概率
  private Double goodProb;

  //故障概率
  private Double failProb;

  //实际值
  private Double iRt;

  //下限值
  private Double iMax;

  //上限值
  private Double iMin;

  //故障率上限值
  private Double rerrMax;

  //故障率下限值
  private Double rerrMin;

  //故障次数(次)
  private Integer faultFreq;

  //安装母线索引
  private Integer instBusPtr;

  //交流线路索引
  private Integer aCLinePtr;

  //停运
  private Integer outage;

  //交流线路名称
  public String getName( ){
    return name;
  }

  public void setName(String name){
    this.name = name;
  }

  //安装母线名
  public String getInstallBus( ){
    return installBus;
  }

  public void setInstallBus(String installBus){
    this.installBus = installBus;
  }

  //串联电抗值(pu)
  public Double getX( ){
    return x;
  }

  public void setX(Double x){
    this.x = x;
  }

  //故障率(次/年)
  public Double getRerr( ){
    return rerr;
  }

  public void setRerr(Double rerr){
    this.rerr = rerr;
  }

  //修复率(次/年)
  public Double getRrep( ){
    return rrep;
  }

  public void setRrep(Double rrep){
    this.rrep = rrep;
  }

  //修复时间(小时/次)
  public Double getTrep( ){
    return trep;
  }

  public void setTrep(Double trep){
    this.trep = trep;
  }

  //完好概率
  public Double getGoodProb( ){
    return goodProb;
  }

  public void setGoodProb(Double goodProb){
    this.goodProb = goodProb;
  }

  //故障概率
  public Double getFailProb( ){
    return failProb;
  }

  public void setFailProb(Double failProb){
    this.failProb = failProb;
  }

  //实际值
  public Double getIRt( ){
    return iRt;
  }

  public void setIRt(Double iRt){
    this.iRt = iRt;
  }

  //下限值
  public Double getIMax( ){
    return iMax;
  }

  public void setIMax(Double iMax){
    this.iMax = iMax;
  }

  //上限值
  public Double getIMin( ){
    return iMin;
  }

  public void setIMin(Double iMin){
    this.iMin = iMin;
  }

  //故障率上限值
  public Double getRerrMax( ){
    return rerrMax;
  }

  public void setRerrMax(Double rerrMax){
    this.rerrMax = rerrMax;
  }

  //故障率下限值
  public Double getRerrMin( ){
    return rerrMin;
  }

  public void setRerrMin(Double rerrMin){
    this.rerrMin = rerrMin;
  }

  //故障次数(次)
  public Integer getFaultFreq( ){
    return faultFreq;
  }

  public void setFaultFreq(Integer faultFreq){
    this.faultFreq = faultFreq;
  }

  //安装母线索引
  public Integer getInstBusPtr( ){
    return instBusPtr;
  }

  public void setInstBusPtr(Integer instBusPtr){
    this.instBusPtr = instBusPtr;
  }

  //交流线路索引
  public Integer getACLinePtr( ){
    return aCLinePtr;
  }

  public void setACLinePtr(Integer aCLinePtr){
    this.aCLinePtr = aCLinePtr;
  }

  //停运
  public Integer getOutage( ){
    return outage;
  }

  public void setOutage(Integer outage){
    this.outage = outage;
  }

}
