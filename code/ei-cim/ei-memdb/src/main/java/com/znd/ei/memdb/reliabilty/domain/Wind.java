package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*变压器绕组	*
***********************/
@Entity
public class Wind
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
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
  private Integer parlId;
  
  //电阻(pu)
  private Double r;
  
  //电抗(pu)
  private Double x;
  
  //额定容量(MW)
  private Double rated;
  
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
  
  //越限次数(次)
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
  
  //变压器索引
  private Integer serialNo;
  
  //交流电岛
  private Integer aCIsland;
  
  //发电机升压变标记
  private Integer genTran;
  
  //停运
  private Integer outage;
  
  //可靠性参数类型
  private Integer rParamType;
  
  //N-1多岛
  private Integer trMIsland;
  
  //一阶相关开断分布因子个数
  private Integer trFactorNum;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public String getName() 
  {
    return name;
  }
    
  public void setName(String name)
  {
    this.name = name;
  }
    
  public String getBusI() 
  {
    return busI;
  }
    
  public void setBusI(String busI)
  {
    this.busI = busI;
  }
    
  public String getBusJ() 
  {
    return busJ;
  }
    
  public void setBusJ(String busJ)
  {
    this.busJ = busJ;
  }
    
  public Double getkVI() 
  {
    return kVI;
  }
    
  public void setkVI(Double kVI)
  {
    this.kVI = kVI;
  }
    
  public Double getkVJ() 
  {
    return kVJ;
  }
    
  public void setkVJ(Double kVJ)
  {
    this.kVJ = kVJ;
  }
    
  public Integer getParlId() 
  {
    return parlId;
  }
    
  public void setParlId(Integer parlId)
  {
    this.parlId = parlId;
  }
    
  public Double getR() 
  {
    return r;
  }
    
  public void setR(Double r)
  {
    this.r = r;
  }
    
  public Double getX() 
  {
    return x;
  }
    
  public void setX(Double x)
  {
    this.x = x;
  }
    
  public Double getRated() 
  {
    return rated;
  }
    
  public void setRated(Double rated)
  {
    this.rated = rated;
  }
    
  public Double getWeights() 
  {
    return weights;
  }
    
  public void setWeights(Double weights)
  {
    this.weights = weights;
  }
    
  public Double getRerr() 
  {
    return rerr;
  }
    
  public void setRerr(Double rerr)
  {
    this.rerr = rerr;
  }
    
  public Double getRrep() 
  {
    return rrep;
  }
    
  public void setRrep(Double rrep)
  {
    this.rrep = rrep;
  }
    
  public Double getTrep() 
  {
    return trep;
  }
    
  public void setTrep(Double trep)
  {
    this.trep = trep;
  }
    
  public Double getGoodProb() 
  {
    return goodProb;
  }
    
  public void setGoodProb(Double goodProb)
  {
    this.goodProb = goodProb;
  }
    
  public Double getFailProb() 
  {
    return failProb;
  }
    
  public void setFailProb(Double failProb)
  {
    this.failProb = failProb;
  }
    
  public Double getIRt() 
  {
    return iRt;
  }
    
  public void setIRt(Double iRt)
  {
    this.iRt = iRt;
  }
    
  public Double getIMax() 
  {
    return iMax;
  }
    
  public void setIMax(Double iMax)
  {
    this.iMax = iMax;
  }
    
  public Double getIMin() 
  {
    return iMin;
  }
    
  public void setIMin(Double iMin)
  {
    this.iMin = iMin;
  }
    
  public Double getRerrMax() 
  {
    return rerrMax;
  }
    
  public void setRerrMax(Double rerrMax)
  {
    this.rerrMax = rerrMax;
  }
    
  public Double getRerrMin() 
  {
    return rerrMin;
  }
    
  public void setRerrMin(Double rerrMin)
  {
    this.rerrMin = rerrMin;
  }
    
  public Integer getFaultFreq() 
  {
    return faultFreq;
  }
    
  public void setFaultFreq(Integer faultFreq)
  {
    this.faultFreq = faultFreq;
  }
    
  public Integer getOLmtFreq() 
  {
    return oLmtFreq;
  }
    
  public void setOLmtFreq(Integer oLmtFreq)
  {
    this.oLmtFreq = oLmtFreq;
  }
    
  public Double getOLmtValue() 
  {
    return oLmtValue;
  }
    
  public void setOLmtValue(Double oLmtValue)
  {
    this.oLmtValue = oLmtValue;
  }
    
  public Double getELmtCutLoad() 
  {
    return eLmtCutLoad;
  }
    
  public void setELmtCutLoad(Double eLmtCutLoad)
  {
    this.eLmtCutLoad = eLmtCutLoad;
  }
    
  public Double getRtPi() 
  {
    return rtPi;
  }
    
  public void setRtPi(Double rtPi)
  {
    this.rtPi = rtPi;
  }
    
  public Double getRtQi() 
  {
    return rtQi;
  }
    
  public void setRtQi(Double rtQi)
  {
    this.rtQi = rtQi;
  }
    
  public Double getRtPz() 
  {
    return rtPz;
  }
    
  public void setRtPz(Double rtPz)
  {
    this.rtPz = rtPz;
  }
    
  public Double getRtQz() 
  {
    return rtQz;
  }
    
  public void setRtQz(Double rtQz)
  {
    this.rtQz = rtQz;
  }
    
  public Double getLossP() 
  {
    return lossP;
  }
    
  public void setLossP(Double lossP)
  {
    this.lossP = lossP;
  }
    
  public Double getPfPi() 
  {
    return pfPi;
  }
    
  public void setPfPi(Double pfPi)
  {
    this.pfPi = pfPi;
  }
    
  public Double getPfQi() 
  {
    return pfQi;
  }
    
  public void setPfQi(Double pfQi)
  {
    this.pfQi = pfQi;
  }
    
  public Double getPfPz() 
  {
    return pfPz;
  }
    
  public void setPfPz(Double pfPz)
  {
    this.pfPz = pfPz;
  }
    
  public Double getPfQz() 
  {
    return pfQz;
  }
    
  public void setPfQz(Double pfQz)
  {
    this.pfQz = pfQz;
  }
    
  public Double getTrPi() 
  {
    return trPi;
  }
    
  public void setTrPi(Double trPi)
  {
    this.trPi = trPi;
  }
    
  public Double getTrQi() 
  {
    return trQi;
  }
    
  public void setTrQi(Double trQi)
  {
    this.trQi = trQi;
  }
    
  public Double getTrPz() 
  {
    return trPz;
  }
    
  public void setTrPz(Double trPz)
  {
    this.trPz = trPz;
  }
    
  public Double getTrQz() 
  {
    return trQz;
  }
    
  public void setTrQz(Double trQz)
  {
    this.trQz = trQz;
  }
    
  public String getIniBusI() 
  {
    return iniBusI;
  }
    
  public void setIniBusI(String iniBusI)
  {
    this.iniBusI = iniBusI;
  }
    
  public String getIniBusJ() 
  {
    return iniBusJ;
  }
    
  public void setIniBusJ(String iniBusJ)
  {
    this.iniBusJ = iniBusJ;
  }
    
  public Double getInikVI() 
  {
    return inikVI;
  }
    
  public void setInikVI(Double inikVI)
  {
    this.inikVI = inikVI;
  }
    
  public Double getInikVJ() 
  {
    return inikVJ;
  }
    
  public void setInikVJ(Double inikVJ)
  {
    this.inikVJ = inikVJ;
  }
    
  public Integer getIniLoop() 
  {
    return iniLoop;
  }
    
  public void setIniLoop(Integer iniLoop)
  {
    this.iniLoop = iniLoop;
  }
    
  public Integer getBusIPtr() 
  {
    return busIPtr;
  }
    
  public void setBusIPtr(Integer busIPtr)
  {
    this.busIPtr = busIPtr;
  }
    
  public Integer getBusJPtr() 
  {
    return busJPtr;
  }
    
  public void setBusJPtr(Integer busJPtr)
  {
    this.busJPtr = busJPtr;
  }
    
  public Integer getRadIPtr() 
  {
    return radIPtr;
  }
    
  public void setRadIPtr(Integer radIPtr)
  {
    this.radIPtr = radIPtr;
  }
    
  public Integer getRadJPtr() 
  {
    return radJPtr;
  }
    
  public void setRadJPtr(Integer radJPtr)
  {
    this.radJPtr = radJPtr;
  }
    
  public Integer getSerialNo() 
  {
    return serialNo;
  }
    
  public void setSerialNo(Integer serialNo)
  {
    this.serialNo = serialNo;
  }
    
  public Integer getACIsland() 
  {
    return aCIsland;
  }
    
  public void setACIsland(Integer aCIsland)
  {
    this.aCIsland = aCIsland;
  }
    
  public Integer getGenTran() 
  {
    return genTran;
  }
    
  public void setGenTran(Integer genTran)
  {
    this.genTran = genTran;
  }
    
  public Integer getOutage() 
  {
    return outage;
  }
    
  public void setOutage(Integer outage)
  {
    this.outage = outage;
  }
    
  public Integer getRParamType() 
  {
    return rParamType;
  }
    
  public void setRParamType(Integer rParamType)
  {
    this.rParamType = rParamType;
  }
    
  public Integer getTrMIsland() 
  {
    return trMIsland;
  }
    
  public void setTrMIsland(Integer trMIsland)
  {
    this.trMIsland = trMIsland;
  }
    
  public Integer getTrFactorNum() 
  {
    return trFactorNum;
  }
    
  public void setTrFactorNum(Integer trFactorNum)
  {
    this.trFactorNum = trFactorNum;
  }
    
}
    
