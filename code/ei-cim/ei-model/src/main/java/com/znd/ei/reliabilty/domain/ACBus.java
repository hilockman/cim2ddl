package com.znd.ei.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*交流母线	*
***********************/
@Entity
class ACBus
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //名称
  private String name;
  
  //计算平均电压(kV)
  private Double kV;
  
  //分区
  private String zone;
  
  //母线发电有功(MW)
  private Double genP;
  
  //母线发电无功(MVar)
  private Double genQ;
  
  //母线负荷有功(MW)
  private Double loadP;
  
  //母线负荷无功(MVar)
  private Double loadQ;
  
  //辐射网等效负荷(MW)
  private Double radP;
  
  //母线补偿无功(MVar)
  private Double shuntQ;
  
  //故障率(次/年)
  private Double rerr;
  
  //修复率(次/年)
  private Double rrep;
  
  //修复时间(小时/次)
  private Double trep;
  
  //发电机调节量(MW)
  private Double adGenP;
  
  //负荷调节量(MW)
  private Double adLoadP;
  
  //辐射网等效负荷调节量(MW)
  private Double adRadP;
  
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
  
  //电压计算结果(kV)
  private Double rtV;
  
  //功角计算结果(Deg)
  private Double pfD;
  
  //切负荷概率
  private Double pLC;
  
  //切负荷频率(次/年)
  private Double eFLC;
  
  //切负荷持续时间(小时/年)
  private Double eDLC;
  
  //每次切负荷持续时间(小时/次)
  private Double aDLC;
  
  //负荷切除期望值(MW/年)
  private Double eLC;
  
  //电量不足期望值(MWh/年)
  private Double eENS;
  
  //系统削减电量指标(MWh/MW.年)
  private Double bPECI;
  
  //系统停电指标(MW/MW.年)
  private Double bPII;
  
  //严重程度指标(系统分/年)
  private Double sI;
  
  //交流电岛
  private Integer aCIsland;
  
  //电压越上限次数(次)
  private Integer uVOLmtFreq;
  
  //频率越上限次数(次)
  private Integer uFOLmtFreq;
  
  //电压越下限次数(次)
  private Integer dVOLmtFreq;
  
  //频率越下限次数(次)
  private Integer dFOLmtFreq;
  
  //环辐网编号
  private Integer radial;
  
  //平衡母线标记
  private Integer slack;
  
  //电源母线标记
  private Integer srcBus;
  
  //中性点标记
  private Integer midBus;
  
  //母线所接发电机容量上限(MW)
  private Double genPMax;
  
  //母线所接发电机容量下限(MW)
  private Double genPMin;
  
  //母线所接负荷功率下限(MW)
  private Double loadPMin;
  
  //母线线路指针
  private Integer bus2Line;
  
  //母线变压器指针
  private Integer bus2Tran;
  
  //母线分区索引
  private Integer zoneIndex;
  
  //环网内环辐边界母线标记
  private Integer ringBound;
  
  //母线负荷多状态
  private Integer loadMState;
  
  //直流母线标记
  private Integer dCBus;
  
  //可靠性参数类型
  private Integer rParamType;
  
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
    
  public Double getkV() 
  {
    return kV;
  }
    
  public void setkV(Double kV)
  {
    this.kV = kV;
  }
    
  public String getZone() 
  {
    return zone;
  }
    
  public void setZone(String zone)
  {
    this.zone = zone;
  }
    
  public Double getGenP() 
  {
    return genP;
  }
    
  public void setGenP(Double genP)
  {
    this.genP = genP;
  }
    
  public Double getGenQ() 
  {
    return genQ;
  }
    
  public void setGenQ(Double genQ)
  {
    this.genQ = genQ;
  }
    
  public Double getLoadP() 
  {
    return loadP;
  }
    
  public void setLoadP(Double loadP)
  {
    this.loadP = loadP;
  }
    
  public Double getLoadQ() 
  {
    return loadQ;
  }
    
  public void setLoadQ(Double loadQ)
  {
    this.loadQ = loadQ;
  }
    
  public Double getRadP() 
  {
    return radP;
  }
    
  public void setRadP(Double radP)
  {
    this.radP = radP;
  }
    
  public Double getShuntQ() 
  {
    return shuntQ;
  }
    
  public void setShuntQ(Double shuntQ)
  {
    this.shuntQ = shuntQ;
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
    
  public Double getAdGenP() 
  {
    return adGenP;
  }
    
  public void setAdGenP(Double adGenP)
  {
    this.adGenP = adGenP;
  }
    
  public Double getAdLoadP() 
  {
    return adLoadP;
  }
    
  public void setAdLoadP(Double adLoadP)
  {
    this.adLoadP = adLoadP;
  }
    
  public Double getAdRadP() 
  {
    return adRadP;
  }
    
  public void setAdRadP(Double adRadP)
  {
    this.adRadP = adRadP;
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
    
  public Double getRtV() 
  {
    return rtV;
  }
    
  public void setRtV(Double rtV)
  {
    this.rtV = rtV;
  }
    
  public Double getPfD() 
  {
    return pfD;
  }
    
  public void setPfD(Double pfD)
  {
    this.pfD = pfD;
  }
    
  public Double getPLC() 
  {
    return pLC;
  }
    
  public void setPLC(Double pLC)
  {
    this.pLC = pLC;
  }
    
  public Double getEFLC() 
  {
    return eFLC;
  }
    
  public void setEFLC(Double eFLC)
  {
    this.eFLC = eFLC;
  }
    
  public Double getEDLC() 
  {
    return eDLC;
  }
    
  public void setEDLC(Double eDLC)
  {
    this.eDLC = eDLC;
  }
    
  public Double getADLC() 
  {
    return aDLC;
  }
    
  public void setADLC(Double aDLC)
  {
    this.aDLC = aDLC;
  }
    
  public Double getELC() 
  {
    return eLC;
  }
    
  public void setELC(Double eLC)
  {
    this.eLC = eLC;
  }
    
  public Double getEENS() 
  {
    return eENS;
  }
    
  public void setEENS(Double eENS)
  {
    this.eENS = eENS;
  }
    
  public Double getBPECI() 
  {
    return bPECI;
  }
    
  public void setBPECI(Double bPECI)
  {
    this.bPECI = bPECI;
  }
    
  public Double getBPII() 
  {
    return bPII;
  }
    
  public void setBPII(Double bPII)
  {
    this.bPII = bPII;
  }
    
  public Double getSI() 
  {
    return sI;
  }
    
  public void setSI(Double sI)
  {
    this.sI = sI;
  }
    
  public Integer getACIsland() 
  {
    return aCIsland;
  }
    
  public void setACIsland(Integer aCIsland)
  {
    this.aCIsland = aCIsland;
  }
    
  public Integer getUVOLmtFreq() 
  {
    return uVOLmtFreq;
  }
    
  public void setUVOLmtFreq(Integer uVOLmtFreq)
  {
    this.uVOLmtFreq = uVOLmtFreq;
  }
    
  public Integer getUFOLmtFreq() 
  {
    return uFOLmtFreq;
  }
    
  public void setUFOLmtFreq(Integer uFOLmtFreq)
  {
    this.uFOLmtFreq = uFOLmtFreq;
  }
    
  public Integer getDVOLmtFreq() 
  {
    return dVOLmtFreq;
  }
    
  public void setDVOLmtFreq(Integer dVOLmtFreq)
  {
    this.dVOLmtFreq = dVOLmtFreq;
  }
    
  public Integer getDFOLmtFreq() 
  {
    return dFOLmtFreq;
  }
    
  public void setDFOLmtFreq(Integer dFOLmtFreq)
  {
    this.dFOLmtFreq = dFOLmtFreq;
  }
    
  public Integer getRadial() 
  {
    return radial;
  }
    
  public void setRadial(Integer radial)
  {
    this.radial = radial;
  }
    
  public Integer getSlack() 
  {
    return slack;
  }
    
  public void setSlack(Integer slack)
  {
    this.slack = slack;
  }
    
  public Integer getSrcBus() 
  {
    return srcBus;
  }
    
  public void setSrcBus(Integer srcBus)
  {
    this.srcBus = srcBus;
  }
    
  public Integer getMidBus() 
  {
    return midBus;
  }
    
  public void setMidBus(Integer midBus)
  {
    this.midBus = midBus;
  }
    
  public Double getGenPMax() 
  {
    return genPMax;
  }
    
  public void setGenPMax(Double genPMax)
  {
    this.genPMax = genPMax;
  }
    
  public Double getGenPMin() 
  {
    return genPMin;
  }
    
  public void setGenPMin(Double genPMin)
  {
    this.genPMin = genPMin;
  }
    
  public Double getLoadPMin() 
  {
    return loadPMin;
  }
    
  public void setLoadPMin(Double loadPMin)
  {
    this.loadPMin = loadPMin;
  }
    
  public Integer getBus2Line() 
  {
    return bus2Line;
  }
    
  public void setBus2Line(Integer bus2Line)
  {
    this.bus2Line = bus2Line;
  }
    
  public Integer getBus2Tran() 
  {
    return bus2Tran;
  }
    
  public void setBus2Tran(Integer bus2Tran)
  {
    this.bus2Tran = bus2Tran;
  }
    
  public Integer getZoneIndex() 
  {
    return zoneIndex;
  }
    
  public void setZoneIndex(Integer zoneIndex)
  {
    this.zoneIndex = zoneIndex;
  }
    
  public Integer getRingBound() 
  {
    return ringBound;
  }
    
  public void setRingBound(Integer ringBound)
  {
    this.ringBound = ringBound;
  }
    
  public Integer getLoadMState() 
  {
    return loadMState;
  }
    
  public void setLoadMState(Integer loadMState)
  {
    this.loadMState = loadMState;
  }
    
  public Integer getDCBus() 
  {
    return dCBus;
  }
    
  public void setDCBus(Integer dCBus)
  {
    this.dCBus = dCBus;
  }
    
  public Integer getRParamType() 
  {
    return rParamType;
  }
    
  public void setRParamType(Integer rParamType)
  {
    this.rParamType = rParamType;
  }
    
}
    
