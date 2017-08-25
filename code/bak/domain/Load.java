package com.znd.ei.memdb.domain;

/**********************
*负荷	*
***********************/
class Load
{
  //名称
  private String name;

  //母线
  private String busName;

  //电压(kV)
  private Double buskV;

  //分区
  private String zone;

  //有功(MW)
  private Double p;

  //无功(MVar)
  private Double q;

  //最大有功(MW)
  private Double pMax;

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

  //多状态模型
  private Integer mSModel;

  //多状态状态数
  private Integer mStateNum;

  //多状态功率(MW)
  private Double mSPout;

  //给定有功(MW)
  private Double referenceP;

  //给定无功(MVar)
  private Double referenceQ;

  //环辐网编号
  private Integer radial;

  //母线索引
  private Integer busPtr;

  //厂用电标记
  private Integer auxLoad;

  //等值负荷标记
  private Integer eQLoad;

  //可靠性参数类型
  private Integer rParamType;

  //停运
  private Integer outage;

  //名称
  public String getName( ){
    return name;
  }

  public void setName(String name){
    this.name = name;
  }

  //母线
  public String getBusName( ){
    return busName;
  }

  public void setBusName(String busName){
    this.busName = busName;
  }

  //电压(kV)
  public Double getBuskV( ){
    return buskV;
  }

  public void setBuskV(Double buskV){
    this.buskV = buskV;
  }

  //分区
  public String getZone( ){
    return zone;
  }

  public void setZone(String zone){
    this.zone = zone;
  }

  //有功(MW)
  public Double getP( ){
    return p;
  }

  public void setP(Double p){
    this.p = p;
  }

  //无功(MVar)
  public Double getQ( ){
    return q;
  }

  public void setQ(Double q){
    this.q = q;
  }

  //最大有功(MW)
  public Double getPMax( ){
    return pMax;
  }

  public void setPMax(Double pMax){
    this.pMax = pMax;
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

  //多状态模型
  public Integer getMSModel( ){
    return mSModel;
  }

  public void setMSModel(Integer mSModel){
    this.mSModel = mSModel;
  }

  //多状态状态数
  public Integer getMStateNum( ){
    return mStateNum;
  }

  public void setMStateNum(Integer mStateNum){
    this.mStateNum = mStateNum;
  }

  //多状态功率(MW)
  public Double getMSPout( ){
    return mSPout;
  }

  public void setMSPout(Double mSPout){
    this.mSPout = mSPout;
  }

  //给定有功(MW)
  public Double getReferenceP( ){
    return referenceP;
  }

  public void setReferenceP(Double referenceP){
    this.referenceP = referenceP;
  }

  //给定无功(MVar)
  public Double getReferenceQ( ){
    return referenceQ;
  }

  public void setReferenceQ(Double referenceQ){
    this.referenceQ = referenceQ;
  }

  //环辐网编号
  public Integer getRadial( ){
    return radial;
  }

  public void setRadial(Integer radial){
    this.radial = radial;
  }

  //母线索引
  public Integer getBusPtr( ){
    return busPtr;
  }

  public void setBusPtr(Integer busPtr){
    this.busPtr = busPtr;
  }

  //厂用电标记
  public Integer getAuxLoad( ){
    return auxLoad;
  }

  public void setAuxLoad(Integer auxLoad){
    this.auxLoad = auxLoad;
  }

  //等值负荷标记
  public Integer getEQLoad( ){
    return eQLoad;
  }

  public void setEQLoad(Integer eQLoad){
    this.eQLoad = eQLoad;
  }

  //可靠性参数类型
  public Integer getRParamType( ){
    return rParamType;
  }

  public void setRParamType(Integer rParamType){
    this.rParamType = rParamType;
  }

  //停运
  public Integer getOutage( ){
    return outage;
  }

  public void setOutage(Integer outage){
    this.outage = outage;
  }

}