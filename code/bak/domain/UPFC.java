package com.znd.ei.memdb.domain;

/**********************
*统一潮流控制器	*
***********************/
class UPFC
{
  //交流线路名称
  private String name;

  //串联母线名
  private String seriesBus;

  //并联母线名
  private String parallelBus;

  //容量(MVA)
  private Double capacity;

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

  //串联侧注入功率(MW)
  private Double linePse;

  //串联侧控制功率(MW)
  private Double p;

  //故障次数(次)
  private Integer faultFreq;

  //串联母线索引
  private Integer seriesBusPtr;

  //并联母线索引
  private Integer parallelBusPtr;

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

  //串联母线名
  public String getSeriesBus( ){
    return seriesBus;
  }

  public void setSeriesBus(String seriesBus){
    this.seriesBus = seriesBus;
  }

  //并联母线名
  public String getParallelBus( ){
    return parallelBus;
  }

  public void setParallelBus(String parallelBus){
    this.parallelBus = parallelBus;
  }

  //容量(MVA)
  public Double getCapacity( ){
    return capacity;
  }

  public void setCapacity(Double capacity){
    this.capacity = capacity;
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

  //串联侧注入功率(MW)
  public Double getLinePse( ){
    return linePse;
  }

  public void setLinePse(Double linePse){
    this.linePse = linePse;
  }

  //串联侧控制功率(MW)
  public Double getP( ){
    return p;
  }

  public void setP(Double p){
    this.p = p;
  }

  //故障次数(次)
  public Integer getFaultFreq( ){
    return faultFreq;
  }

  public void setFaultFreq(Integer faultFreq){
    this.faultFreq = faultFreq;
  }

  //串联母线索引
  public Integer getSeriesBusPtr( ){
    return seriesBusPtr;
  }

  public void setSeriesBusPtr(Integer seriesBusPtr){
    this.seriesBusPtr = seriesBusPtr;
  }

  //并联母线索引
  public Integer getParallelBusPtr( ){
    return parallelBusPtr;
  }

  public void setParallelBusPtr(Integer parallelBusPtr){
    this.parallelBusPtr = parallelBusPtr;
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
