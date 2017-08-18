package com.znd.ei.memdb.domain;

/**********************
*停运发电	*
***********************/
class CopGen
{
  //设备索引
  private Integer index;

  //发电机容量(MW)
  private Double capacity;

  //折算系数
  private Double alpha;

  //发电机折算容量1(MW)
  private Double s1Capacity;

  //发电机折算容量2(MW)
  private Double s2Capacity;

  //故障率(次/天)
  private Double rerr;

  //修复时间(天/次)
  private Double trep;

  //修复率(次/天)
  private Double rrep;

  //停运率(次/天)
  private Double rout;

  //三状态
  private Integer 3STATE;

  //设备索引
  public Integer getIndex() {
    return index;
  }

  public void setIndex(Integer index){
    this.index = index;
  }

  //发电机容量(MW)
  public Double getCapacity() {
    return capacity;
  }

  public void setCapacity(Double capacity){
    this.capacity = capacity;
  }

  //折算系数
  public Double getAlpha() {
    return alpha;
  }

  public void setAlpha(Double alpha){
    this.alpha = alpha;
  }

  //发电机折算容量1(MW)
  public Double getS1Capacity() {
    return s1Capacity;
  }

  public void setS1Capacity(Double s1Capacity){
    this.s1Capacity = s1Capacity;
  }

  //发电机折算容量2(MW)
  public Double getS2Capacity() {
    return s2Capacity;
  }

  public void setS2Capacity(Double s2Capacity){
    this.s2Capacity = s2Capacity;
  }

  //故障率(次/天)
  public Double getRerr() {
    return rerr;
  }

  public void setRerr(Double rerr){
    this.rerr = rerr;
  }

  //修复时间(天/次)
  public Double getTrep() {
    return trep;
  }

  public void setTrep(Double trep){
    this.trep = trep;
  }

  //修复率(次/天)
  public Double getRrep() {
    return rrep;
  }

  public void setRrep(Double rrep){
    this.rrep = rrep;
  }

  //停运率(次/天)
  public Double getRout() {
    return rout;
  }

  public void setRout(Double rout){
    this.rout = rout;
  }

  //三状态
  public Integer get3STATE() {
    return 3STATE;
  }

  public void set3STATE(Integer 3STATE){
    this.3STATE = 3STATE;
  }

}
