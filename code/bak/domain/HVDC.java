package com.znd.ei.memdb.domain;

/**********************
*高压直流系统	*
***********************/
class HVDC
{
  //名称
  private String name;

  //整流交流节点名称
  private String aCBusR;

  //逆变交流节点名称
  private String aCBusI;

  //整流侧电压(kV)
  private Double kVR;

  //逆变侧电压(kV)
  private Double kVI;

  //电阻(欧姆)
  private Double r;

  //电感(毫亨)
  private Double l;

  //电容(微法)
  private Double c;

  //控制测R/I
  private Integer con;

  //额定电流(A)
  private Double ratedC;

  //整流侧直流电压(kV)
  private Double rectV;

  //额定功率(MW)
  private Double ratedP;

  //安排的直流功率(MW)
  private Double power;

  //整流侧功率(MW)
  private Double pwrR;

  //逆变侧功率(MW)
  private Double pwrI;

  //损耗(MW)
  private Double lossP;

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

  //多状态功率状态
  private Double mSPout;

  //Ini整流节点名称
  private String iniBusR;

  //Ini逆变节点名称
  private String iniBusI;

  //Ini整流侧功率(MW)
  private Double iniPwrR;

  //Ini逆变侧功率(MW)
  private Double iniPwrI;

  //整流节点索引
  private Integer aCBusRPtr;

  //逆变节点索引
  private Integer aCBusIPtr;

  //直流索引
  private Integer index;

  //停运
  private Integer outage;

  //名称
  public String getName( ){
    return name;
  }

  public void setName(String name){
    this.name = name;
  }

  //整流交流节点名称
  public String getACBusR( ){
    return aCBusR;
  }

  public void setACBusR(String aCBusR){
    this.aCBusR = aCBusR;
  }

  //逆变交流节点名称
  public String getACBusI( ){
    return aCBusI;
  }

  public void setACBusI(String aCBusI){
    this.aCBusI = aCBusI;
  }

  //整流侧电压(kV)
  public Double getkVR( ){
    return kVR;
  }

  public void setkVR(Double kVR){
    this.kVR = kVR;
  }

  //逆变侧电压(kV)
  public Double getkVI( ){
    return kVI;
  }

  public void setkVI(Double kVI){
    this.kVI = kVI;
  }

  //电阻(欧姆)
  public Double getR( ){
    return r;
  }

  public void setR(Double r){
    this.r = r;
  }

  //电感(毫亨)
  public Double getL( ){
    return l;
  }

  public void setL(Double l){
    this.l = l;
  }

  //电容(微法)
  public Double getC( ){
    return c;
  }

  public void setC(Double c){
    this.c = c;
  }

  //控制测R/I
  public Integer getCon( ){
    return con;
  }

  public void setCon(Integer con){
    this.con = con;
  }

  //额定电流(A)
  public Double getRatedC( ){
    return ratedC;
  }

  public void setRatedC(Double ratedC){
    this.ratedC = ratedC;
  }

  //整流侧直流电压(kV)
  public Double getRectV( ){
    return rectV;
  }

  public void setRectV(Double rectV){
    this.rectV = rectV;
  }

  //额定功率(MW)
  public Double getRatedP( ){
    return ratedP;
  }

  public void setRatedP(Double ratedP){
    this.ratedP = ratedP;
  }

  //安排的直流功率(MW)
  public Double getPower( ){
    return power;
  }

  public void setPower(Double power){
    this.power = power;
  }

  //整流侧功率(MW)
  public Double getPwrR( ){
    return pwrR;
  }

  public void setPwrR(Double pwrR){
    this.pwrR = pwrR;
  }

  //逆变侧功率(MW)
  public Double getPwrI( ){
    return pwrI;
  }

  public void setPwrI(Double pwrI){
    this.pwrI = pwrI;
  }

  //损耗(MW)
  public Double getLossP( ){
    return lossP;
  }

  public void setLossP(Double lossP){
    this.lossP = lossP;
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

  //多状态功率状态
  public Double getMSPout( ){
    return mSPout;
  }

  public void setMSPout(Double mSPout){
    this.mSPout = mSPout;
  }

  //Ini整流节点名称
  public String getIniBusR( ){
    return iniBusR;
  }

  public void setIniBusR(String iniBusR){
    this.iniBusR = iniBusR;
  }

  //Ini逆变节点名称
  public String getIniBusI( ){
    return iniBusI;
  }

  public void setIniBusI(String iniBusI){
    this.iniBusI = iniBusI;
  }

  //Ini整流侧功率(MW)
  public Double getIniPwrR( ){
    return iniPwrR;
  }

  public void setIniPwrR(Double iniPwrR){
    this.iniPwrR = iniPwrR;
  }

  //Ini逆变侧功率(MW)
  public Double getIniPwrI( ){
    return iniPwrI;
  }

  public void setIniPwrI(Double iniPwrI){
    this.iniPwrI = iniPwrI;
  }

  //整流节点索引
  public Integer getACBusRPtr( ){
    return aCBusRPtr;
  }

  public void setACBusRPtr(Integer aCBusRPtr){
    this.aCBusRPtr = aCBusRPtr;
  }

  //逆变节点索引
  public Integer getACBusIPtr( ){
    return aCBusIPtr;
  }

  public void setACBusIPtr(Integer aCBusIPtr){
    this.aCBusIPtr = aCBusIPtr;
  }

  //直流索引
  public Integer getIndex( ){
    return index;
  }

  public void setIndex(Integer index){
    this.index = index;
  }

  //停运
  public Integer getOutage( ){
    return outage;
  }

  public void setOutage(Integer outage){
    this.outage = outage;
  }

}