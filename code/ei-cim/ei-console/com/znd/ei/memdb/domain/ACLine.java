package com.znd.ei.memdb.domain;

/**********************
*交流线路	*
***********************/
class ACLine
{
  //名称
  private String name;

  //起节点名称
  private String busI;

  //终节点名称
  private String busJ;

  //I侧电压(kV)
  private Double kVI;

  //J侧电压(kV)
  private Double kVJ;

  //并联回路号
  private Integer loop;

  //电阻(pu)
  private Double r;

  //电抗(pu)
  private Double x;

  //电纳(pu)
  private Double b;

  //额定容量(MW)
  private Double rated;

  //长度(KM)
  private Double length;

  //越限指标权重
  private Double weights;

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

  //越限次数
  private Integer oLmtFreq;

  //越限功率(MW/次)
  private Double oLmtValue;

  //消限切负荷电量(MW.h/年)
  private Double eLmtCutLoad;

  //RT起点有功(MW)
  private Double rtPi;

  //RT起点无功(MVar)
  private Double rtQi;

  //RT终点有功(MW)
  private Double rtPz;

  //RT终点无功(MVar)
  private Double rtQz;

  //损耗(MW)
  private Double lossP;

  //PF起点有功(MW)
  private Double pfPi;

  //PF起点无功(MVar)
  private Double pfQi;

  //PF终点有功(MW)
  private Double pfPz;

  //PF终点无功(MVar)
  private Double pfQz;

  //TR起点有功(MW)
  private Double trPi;

  //TR起点无功(MVar)
  private Double trQi;

  //TR终点有功(MW)
  private Double trPz;

  //TR终点无功(MVar)
  private Double trQz;

  //Ini起节点名称
  private String iniBusI;

  //Ini终节点名称
  private String iniBusJ;

  //Ini起点侧电压(kV)
  private Double inikVI;

  //Ini终点侧电压(kV)
  private Double inikVJ;

  //Ini并联回路号
  private Integer iniLoop;

  //起节点索引
  private Integer busIPtr;

  //终节点索引
  private Integer busJPtr;

  //起节点辐网编号
  private Integer radIPtr;

  //终节点辐网编号
  private Integer radJPtr;

  //线路索引
  private Integer index;

  //交流电岛
  private Integer aCIsland;

  //停运
  private Integer outage;

  //可靠性参数类型
  private Integer rParamType;

  //N-1多岛
  private Integer trMIsland;

  //一阶相关开断分布因子个数
  private Integer trFactorNum;

  //TCSC索引
  private Integer tCSCPtr;

  //UPFC索引
  private Integer uPFCPtr;

  //名称
  public String getName() {
    return name;
  }

  public void setName(String name){
    this.name = name;
  }

  //起节点名称
  public String getBusI() {
    return busI;
  }

  public void setBusI(String busI){
    this.busI = busI;
  }

  //终节点名称
  public String getBusJ() {
    return busJ;
  }

  public void setBusJ(String busJ){
    this.busJ = busJ;
  }

  //I侧电压(kV)
  public Double getkVI() {
    return kVI;
  }

  public void setkVI(Double kVI){
    this.kVI = kVI;
  }

  //J侧电压(kV)
  public Double getkVJ() {
    return kVJ;
  }

  public void setkVJ(Double kVJ){
    this.kVJ = kVJ;
  }

  //并联回路号
  public Integer getLoop() {
    return loop;
  }

  public void setLoop(Integer loop){
    this.loop = loop;
  }

  //电阻(pu)
  public Double getR() {
    return r;
  }

  public void setR(Double r){
    this.r = r;
  }

  //电抗(pu)
  public Double getX() {
    return x;
  }

  public void setX(Double x){
    this.x = x;
  }

  //电纳(pu)
  public Double getB() {
    return b;
  }

  public void setB(Double b){
    this.b = b;
  }

  //额定容量(MW)
  public Double getRated() {
    return rated;
  }

  public void setRated(Double rated){
    this.rated = rated;
  }

  //长度(KM)
  public Double getLength() {
    return length;
  }

  public void setLength(Double length){
    this.length = length;
  }

  //越限指标权重
  public Double getWeights() {
    return weights;
  }

  public void setWeights(Double weights){
    this.weights = weights;
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

  //越限次数
  public Integer getOLmtFreq() {
    return oLmtFreq;
  }

  public void setOLmtFreq(Integer oLmtFreq){
    this.oLmtFreq = oLmtFreq;
  }

  //越限功率(MW/次)
  public Double getOLmtValue() {
    return oLmtValue;
  }

  public void setOLmtValue(Double oLmtValue){
    this.oLmtValue = oLmtValue;
  }

  //消限切负荷电量(MW.h/年)
  public Double getELmtCutLoad() {
    return eLmtCutLoad;
  }

  public void setELmtCutLoad(Double eLmtCutLoad){
    this.eLmtCutLoad = eLmtCutLoad;
  }

  //RT起点有功(MW)
  public Double getRtPi() {
    return rtPi;
  }

  public void setRtPi(Double rtPi){
    this.rtPi = rtPi;
  }

  //RT起点无功(MVar)
  public Double getRtQi() {
    return rtQi;
  }

  public void setRtQi(Double rtQi){
    this.rtQi = rtQi;
  }

  //RT终点有功(MW)
  public Double getRtPz() {
    return rtPz;
  }

  public void setRtPz(Double rtPz){
    this.rtPz = rtPz;
  }

  //RT终点无功(MVar)
  public Double getRtQz() {
    return rtQz;
  }

  public void setRtQz(Double rtQz){
    this.rtQz = rtQz;
  }

  //损耗(MW)
  public Double getLossP() {
    return lossP;
  }

  public void setLossP(Double lossP){
    this.lossP = lossP;
  }

  //PF起点有功(MW)
  public Double getPfPi() {
    return pfPi;
  }

  public void setPfPi(Double pfPi){
    this.pfPi = pfPi;
  }

  //PF起点无功(MVar)
  public Double getPfQi() {
    return pfQi;
  }

  public void setPfQi(Double pfQi){
    this.pfQi = pfQi;
  }

  //PF终点有功(MW)
  public Double getPfPz() {
    return pfPz;
  }

  public void setPfPz(Double pfPz){
    this.pfPz = pfPz;
  }

  //PF终点无功(MVar)
  public Double getPfQz() {
    return pfQz;
  }

  public void setPfQz(Double pfQz){
    this.pfQz = pfQz;
  }

  //TR起点有功(MW)
  public Double getTrPi() {
    return trPi;
  }

  public void setTrPi(Double trPi){
    this.trPi = trPi;
  }

  //TR起点无功(MVar)
  public Double getTrQi() {
    return trQi;
  }

  public void setTrQi(Double trQi){
    this.trQi = trQi;
  }

  //TR终点有功(MW)
  public Double getTrPz() {
    return trPz;
  }

  public void setTrPz(Double trPz){
    this.trPz = trPz;
  }

  //TR终点无功(MVar)
  public Double getTrQz() {
    return trQz;
  }

  public void setTrQz(Double trQz){
    this.trQz = trQz;
  }

  //Ini起节点名称
  public String getIniBusI() {
    return iniBusI;
  }

  public void setIniBusI(String iniBusI){
    this.iniBusI = iniBusI;
  }

  //Ini终节点名称
  public String getIniBusJ() {
    return iniBusJ;
  }

  public void setIniBusJ(String iniBusJ){
    this.iniBusJ = iniBusJ;
  }

  //Ini起点侧电压(kV)
  public Double getInikVI() {
    return inikVI;
  }

  public void setInikVI(Double inikVI){
    this.inikVI = inikVI;
  }

  //Ini终点侧电压(kV)
  public Double getInikVJ() {
    return inikVJ;
  }

  public void setInikVJ(Double inikVJ){
    this.inikVJ = inikVJ;
  }

  //Ini并联回路号
  public Integer getIniLoop() {
    return iniLoop;
  }

  public void setIniLoop(Integer iniLoop){
    this.iniLoop = iniLoop;
  }

  //起节点索引
  public Integer getBusIPtr() {
    return busIPtr;
  }

  public void setBusIPtr(Integer busIPtr){
    this.busIPtr = busIPtr;
  }

  //终节点索引
  public Integer getBusJPtr() {
    return busJPtr;
  }

  public void setBusJPtr(Integer busJPtr){
    this.busJPtr = busJPtr;
  }

  //起节点辐网编号
  public Integer getRadIPtr() {
    return radIPtr;
  }

  public void setRadIPtr(Integer radIPtr){
    this.radIPtr = radIPtr;
  }

  //终节点辐网编号
  public Integer getRadJPtr() {
    return radJPtr;
  }

  public void setRadJPtr(Integer radJPtr){
    this.radJPtr = radJPtr;
  }

  //线路索引
  public Integer getIndex() {
    return index;
  }

  public void setIndex(Integer index){
    this.index = index;
  }

  //交流电岛
  public Integer getACIsland() {
    return aCIsland;
  }

  public void setACIsland(Integer aCIsland){
    this.aCIsland = aCIsland;
  }

  //停运
  public Integer getOutage() {
    return outage;
  }

  public void setOutage(Integer outage){
    this.outage = outage;
  }

  //可靠性参数类型
  public Integer getRParamType() {
    return rParamType;
  }

  public void setRParamType(Integer rParamType){
    this.rParamType = rParamType;
  }

  //N-1多岛
  public Integer getTrMIsland() {
    return trMIsland;
  }

  public void setTrMIsland(Integer trMIsland){
    this.trMIsland = trMIsland;
  }

  //一阶相关开断分布因子个数
  public Integer getTrFactorNum() {
    return trFactorNum;
  }

  public void setTrFactorNum(Integer trFactorNum){
    this.trFactorNum = trFactorNum;
  }

  //TCSC索引
  public Integer getTCSCPtr() {
    return tCSCPtr;
  }

  public void setTCSCPtr(Integer tCSCPtr){
    this.tCSCPtr = tCSCPtr;
  }

  //UPFC索引
  public Integer getUPFCPtr() {
    return uPFCPtr;
  }

  public void setUPFCPtr(Integer uPFCPtr){
    this.uPFCPtr = uPFCPtr;
  }

}
