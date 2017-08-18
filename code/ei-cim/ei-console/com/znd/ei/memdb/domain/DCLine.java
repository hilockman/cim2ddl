package com.znd.ei.memdb.domain;

/**********************
*直流线路	*
***********************/
class DCLine
{
  //名称
  private String name;

  //I侧直流节点名称
  private String dCBusI;

  //J侧直流节点名称
  private String dCBusJ;

  //长度(KM)
  private Double length;

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

  //I侧直流节点索引
  private Integer dCBusIPtr;

  //J侧直流节点索引
  private Integer dCBusJPtr;

  //停运
  private Integer outage;

  //名称
  public String getName() {
    return name;
  }

  public void setName(String name){
    this.name = name;
  }

  //I侧直流节点名称
  public String getDCBusI() {
    return dCBusI;
  }

  public void setDCBusI(String dCBusI){
    this.dCBusI = dCBusI;
  }

  //J侧直流节点名称
  public String getDCBusJ() {
    return dCBusJ;
  }

  public void setDCBusJ(String dCBusJ){
    this.dCBusJ = dCBusJ;
  }

  //长度(KM)
  public Double getLength() {
    return length;
  }

  public void setLength(Double length){
    this.length = length;
  }

  //故障率(次/年)
  public Double getRerr() {
    return rerr;
  }

  public void setRerr(Double rerr){
    this.rerr = rerr;
  }

  //修复率(次/年)
  public Double getRrep() {
    return rrep;
  }

  public void setRrep(Double rrep){
    this.rrep = rrep;
  }

  //修复时间(小时/次)
  public Double getTrep() {
    return trep;
  }

  public void setTrep(Double trep){
    this.trep = trep;
  }

  //完好概率
  public Double getGoodProb() {
    return goodProb;
  }

  public void setGoodProb(Double goodProb){
    this.goodProb = goodProb;
  }

  //故障概率
  public Double getFailProb() {
    return failProb;
  }

  public void setFailProb(Double failProb){
    this.failProb = failProb;
  }

  //实际值
  public Double getIRt() {
    return iRt;
  }

  public void setIRt(Double iRt){
    this.iRt = iRt;
  }

  //下限值
  public Double getIMax() {
    return iMax;
  }

  public void setIMax(Double iMax){
    this.iMax = iMax;
  }

  //上限值
  public Double getIMin() {
    return iMin;
  }

  public void setIMin(Double iMin){
    this.iMin = iMin;
  }

  //故障率上限值
  public Double getRerrMax() {
    return rerrMax;
  }

  public void setRerrMax(Double rerrMax){
    this.rerrMax = rerrMax;
  }

  //故障率下限值
  public Double getRerrMin() {
    return rerrMin;
  }

  public void setRerrMin(Double rerrMin){
    this.rerrMin = rerrMin;
  }

  //故障次数(次)
  public Integer getFaultFreq() {
    return faultFreq;
  }

  public void setFaultFreq(Integer faultFreq){
    this.faultFreq = faultFreq;
  }

  //I侧直流节点索引
  public Integer getDCBusIPtr() {
    return dCBusIPtr;
  }

  public void setDCBusIPtr(Integer dCBusIPtr){
    this.dCBusIPtr = dCBusIPtr;
  }

  //J侧直流节点索引
  public Integer getDCBusJPtr() {
    return dCBusJPtr;
  }

  public void setDCBusJPtr(Integer dCBusJPtr){
    this.dCBusJPtr = dCBusJPtr;
  }

  //停运
  public Integer getOutage() {
    return outage;
  }

  public void setOutage(Integer outage){
    this.outage = outage;
  }

}
