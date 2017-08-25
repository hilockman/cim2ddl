package com.znd.ei.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*系统	*
***********************/
@Entity
public class System
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //功率基准
  private Double mvaBase;
  
  //系统总发电(MW)
  private Double genP;
  
  //系统总负荷(MW)
  private Double loadP;
  
  //系统直流容量(MW)
  private Double dCP;
  
  //系统总装机(MW)
  private Double availGenP;
  
  //系统最大负荷(MW)
  private Double maxLoadP;
  
  //抽样方法
  private Integer sampleMethod;
  
  //抽样对象
  private Integer sampleObject;
  
  //最大支路故障重数
  private Integer maxBranFlt;
  
  //最大发电机故障重数
  private Integer maxGenFlt;
  
  //蒙特卡罗法模拟时间(小时)
  private Double mCSSimulateTime;
  
  //蒙特卡罗法最小概率值
  private Double mCSMinProb;
  
  //快速排序法截止累计概率值
  private Double fSTCumulateProb;
  
  //快速排序法截止状态数
  private Integer fSTMaxState;
  
  //快速排序法最小概率值
  private Double fSTMinProb;
  
  //状态抽样法截止状态数
  private Integer sTSMaxState;
  
  //解析法最小概率值
  private Double aNAMinProb;
  
  //Bpa潮流文件
  private String bpaDatFile;
  
  //Bpa稳定文件
  private String bpaSwiFile;
  
  //安全评估运行目录
  private String securityExecDir;
  
  //安全评估结果目录
  private String securityDestDir;
  
  //安全评估最大功角差
  private Double securityMaxAngle;
  
  //安全评估最高电压
  private Double securityMaxVolt;
  
  //安全评估最高电压持续时间
  private Double securityMaxVDur;
  
  //安全评估最低电压
  private Double securityMinVolt;
  
  //安全评估最低电压持续时间
  private Double securityMinVDur;
  
  //安全评估最高频率
  private Double securityMaxFreq;
  
  //安全评估最高频率持续时间
  private Double securityMaxFDur;
  
  //安全评估最低频率
  private Double securityMinFreq;
  
  //安全评估最低频率持续时间
  private Double securityMinFDur;
  
  //停运概率表容量步长
  private Double copStep;
  
  //最大故障设备重数
  private Integer maxFltDev;
  
  //切负荷状态数
  private Integer cutLoadStateNum;
  
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
  
  //系统停电指标(MW/MW.yr)
  private Double bPII;
  
  //系统削减电量指标(MWh/MW.年)
  private Double bPECI;
  
  //严重程度指标(系统分/年)
  private Double sI;
  
  //电力不足时间概率(天/年)
  private Double lOLP;
  
  //电力不足频率概率(次/年)
  private Double lOLF;
  
  //电力不足期望值(小时/年)
  private Double lOLE;
  
  //失稳概率
  private Double pLOS;
  
  //失稳频率(次/年)
  private Double fLOS;
  
  //平均稳定运行时间(小时)
  private Double mTTIS;
  
  //孤岛电量不足期望值(MWh/年)
  private Double mIslandEENS;
  
  //失电电量不足期望值(MWh/年)
  private Double lossGenEENS;
  
  //消限电量不足期望值(MWh/年)
  private Double eRlimitEENS;
  
  //网络类型
  private Integer networkType;
  
  //非事故状态概率
  private Double fltGrade0Prob;
  
  //一般事故概率
  private Double fltGrade1Prob;
  
  //较大事故概率
  private Double fltGrade2Prob;
  
  //重大事故概率
  private Double fltGrade3Prob;
  
  //特别重大事故概率
  private Double fltGrade4Prob;
  
  //负荷曲线时间间隔
  private Integer loadCurvePace;
  
  //多状态设备数
  private Integer maxMSDevNum;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public Double getMvaBase() 
  {
    return mvaBase;
  }
    
  public void setMvaBase(Double mvaBase)
  {
    this.mvaBase = mvaBase;
  }
    
  public Double getGenP() 
  {
    return genP;
  }
    
  public void setGenP(Double genP)
  {
    this.genP = genP;
  }
    
  public Double getLoadP() 
  {
    return loadP;
  }
    
  public void setLoadP(Double loadP)
  {
    this.loadP = loadP;
  }
    
  public Double getDCP() 
  {
    return dCP;
  }
    
  public void setDCP(Double dCP)
  {
    this.dCP = dCP;
  }
    
  public Double getAvailGenP() 
  {
    return availGenP;
  }
    
  public void setAvailGenP(Double availGenP)
  {
    this.availGenP = availGenP;
  }
    
  public Double getMaxLoadP() 
  {
    return maxLoadP;
  }
    
  public void setMaxLoadP(Double maxLoadP)
  {
    this.maxLoadP = maxLoadP;
  }
    
  public Integer getSampleMethod() 
  {
    return sampleMethod;
  }
    
  public void setSampleMethod(Integer sampleMethod)
  {
    this.sampleMethod = sampleMethod;
  }
    
  public Integer getSampleObject() 
  {
    return sampleObject;
  }
    
  public void setSampleObject(Integer sampleObject)
  {
    this.sampleObject = sampleObject;
  }
    
  public Integer getMaxBranFlt() 
  {
    return maxBranFlt;
  }
    
  public void setMaxBranFlt(Integer maxBranFlt)
  {
    this.maxBranFlt = maxBranFlt;
  }
    
  public Integer getMaxGenFlt() 
  {
    return maxGenFlt;
  }
    
  public void setMaxGenFlt(Integer maxGenFlt)
  {
    this.maxGenFlt = maxGenFlt;
  }
    
  public Double getMCSSimulateTime() 
  {
    return mCSSimulateTime;
  }
    
  public void setMCSSimulateTime(Double mCSSimulateTime)
  {
    this.mCSSimulateTime = mCSSimulateTime;
  }
    
  public Double getMCSMinProb() 
  {
    return mCSMinProb;
  }
    
  public void setMCSMinProb(Double mCSMinProb)
  {
    this.mCSMinProb = mCSMinProb;
  }
    
  public Double getFSTCumulateProb() 
  {
    return fSTCumulateProb;
  }
    
  public void setFSTCumulateProb(Double fSTCumulateProb)
  {
    this.fSTCumulateProb = fSTCumulateProb;
  }
    
  public Integer getFSTMaxState() 
  {
    return fSTMaxState;
  }
    
  public void setFSTMaxState(Integer fSTMaxState)
  {
    this.fSTMaxState = fSTMaxState;
  }
    
  public Double getFSTMinProb() 
  {
    return fSTMinProb;
  }
    
  public void setFSTMinProb(Double fSTMinProb)
  {
    this.fSTMinProb = fSTMinProb;
  }
    
  public Integer getSTSMaxState() 
  {
    return sTSMaxState;
  }
    
  public void setSTSMaxState(Integer sTSMaxState)
  {
    this.sTSMaxState = sTSMaxState;
  }
    
  public Double getANAMinProb() 
  {
    return aNAMinProb;
  }
    
  public void setANAMinProb(Double aNAMinProb)
  {
    this.aNAMinProb = aNAMinProb;
  }
    
  public String getBpaDatFile() 
  {
    return bpaDatFile;
  }
    
  public void setBpaDatFile(String bpaDatFile)
  {
    this.bpaDatFile = bpaDatFile;
  }
    
  public String getBpaSwiFile() 
  {
    return bpaSwiFile;
  }
    
  public void setBpaSwiFile(String bpaSwiFile)
  {
    this.bpaSwiFile = bpaSwiFile;
  }
    
  public String getSecurityExecDir() 
  {
    return securityExecDir;
  }
    
  public void setSecurityExecDir(String securityExecDir)
  {
    this.securityExecDir = securityExecDir;
  }
    
  public String getSecurityDestDir() 
  {
    return securityDestDir;
  }
    
  public void setSecurityDestDir(String securityDestDir)
  {
    this.securityDestDir = securityDestDir;
  }
    
  public Double getSecurityMaxAngle() 
  {
    return securityMaxAngle;
  }
    
  public void setSecurityMaxAngle(Double securityMaxAngle)
  {
    this.securityMaxAngle = securityMaxAngle;
  }
    
  public Double getSecurityMaxVolt() 
  {
    return securityMaxVolt;
  }
    
  public void setSecurityMaxVolt(Double securityMaxVolt)
  {
    this.securityMaxVolt = securityMaxVolt;
  }
    
  public Double getSecurityMaxVDur() 
  {
    return securityMaxVDur;
  }
    
  public void setSecurityMaxVDur(Double securityMaxVDur)
  {
    this.securityMaxVDur = securityMaxVDur;
  }
    
  public Double getSecurityMinVolt() 
  {
    return securityMinVolt;
  }
    
  public void setSecurityMinVolt(Double securityMinVolt)
  {
    this.securityMinVolt = securityMinVolt;
  }
    
  public Double getSecurityMinVDur() 
  {
    return securityMinVDur;
  }
    
  public void setSecurityMinVDur(Double securityMinVDur)
  {
    this.securityMinVDur = securityMinVDur;
  }
    
  public Double getSecurityMaxFreq() 
  {
    return securityMaxFreq;
  }
    
  public void setSecurityMaxFreq(Double securityMaxFreq)
  {
    this.securityMaxFreq = securityMaxFreq;
  }
    
  public Double getSecurityMaxFDur() 
  {
    return securityMaxFDur;
  }
    
  public void setSecurityMaxFDur(Double securityMaxFDur)
  {
    this.securityMaxFDur = securityMaxFDur;
  }
    
  public Double getSecurityMinFreq() 
  {
    return securityMinFreq;
  }
    
  public void setSecurityMinFreq(Double securityMinFreq)
  {
    this.securityMinFreq = securityMinFreq;
  }
    
  public Double getSecurityMinFDur() 
  {
    return securityMinFDur;
  }
    
  public void setSecurityMinFDur(Double securityMinFDur)
  {
    this.securityMinFDur = securityMinFDur;
  }
    
  public Double getCopStep() 
  {
    return copStep;
  }
    
  public void setCopStep(Double copStep)
  {
    this.copStep = copStep;
  }
    
  public Integer getMaxFltDev() 
  {
    return maxFltDev;
  }
    
  public void setMaxFltDev(Integer maxFltDev)
  {
    this.maxFltDev = maxFltDev;
  }
    
  public Integer getCutLoadStateNum() 
  {
    return cutLoadStateNum;
  }
    
  public void setCutLoadStateNum(Integer cutLoadStateNum)
  {
    this.cutLoadStateNum = cutLoadStateNum;
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
    
  public Double getBPII() 
  {
    return bPII;
  }
    
  public void setBPII(Double bPII)
  {
    this.bPII = bPII;
  }
    
  public Double getBPECI() 
  {
    return bPECI;
  }
    
  public void setBPECI(Double bPECI)
  {
    this.bPECI = bPECI;
  }
    
  public Double getSI() 
  {
    return sI;
  }
    
  public void setSI(Double sI)
  {
    this.sI = sI;
  }
    
  public Double getLOLP() 
  {
    return lOLP;
  }
    
  public void setLOLP(Double lOLP)
  {
    this.lOLP = lOLP;
  }
    
  public Double getLOLF() 
  {
    return lOLF;
  }
    
  public void setLOLF(Double lOLF)
  {
    this.lOLF = lOLF;
  }
    
  public Double getLOLE() 
  {
    return lOLE;
  }
    
  public void setLOLE(Double lOLE)
  {
    this.lOLE = lOLE;
  }
    
  public Double getPLOS() 
  {
    return pLOS;
  }
    
  public void setPLOS(Double pLOS)
  {
    this.pLOS = pLOS;
  }
    
  public Double getFLOS() 
  {
    return fLOS;
  }
    
  public void setFLOS(Double fLOS)
  {
    this.fLOS = fLOS;
  }
    
  public Double getMTTIS() 
  {
    return mTTIS;
  }
    
  public void setMTTIS(Double mTTIS)
  {
    this.mTTIS = mTTIS;
  }
    
  public Double getMIslandEENS() 
  {
    return mIslandEENS;
  }
    
  public void setMIslandEENS(Double mIslandEENS)
  {
    this.mIslandEENS = mIslandEENS;
  }
    
  public Double getLossGenEENS() 
  {
    return lossGenEENS;
  }
    
  public void setLossGenEENS(Double lossGenEENS)
  {
    this.lossGenEENS = lossGenEENS;
  }
    
  public Double getERlimitEENS() 
  {
    return eRlimitEENS;
  }
    
  public void setERlimitEENS(Double eRlimitEENS)
  {
    this.eRlimitEENS = eRlimitEENS;
  }
    
  public Integer getNetworkType() 
  {
    return networkType;
  }
    
  public void setNetworkType(Integer networkType)
  {
    this.networkType = networkType;
  }
    
  public Double getFltGrade0Prob() 
  {
    return fltGrade0Prob;
  }
    
  public void setFltGrade0Prob(Double fltGrade0Prob)
  {
    this.fltGrade0Prob = fltGrade0Prob;
  }
    
  public Double getFltGrade1Prob() 
  {
    return fltGrade1Prob;
  }
    
  public void setFltGrade1Prob(Double fltGrade1Prob)
  {
    this.fltGrade1Prob = fltGrade1Prob;
  }
    
  public Double getFltGrade2Prob() 
  {
    return fltGrade2Prob;
  }
    
  public void setFltGrade2Prob(Double fltGrade2Prob)
  {
    this.fltGrade2Prob = fltGrade2Prob;
  }
    
  public Double getFltGrade3Prob() 
  {
    return fltGrade3Prob;
  }
    
  public void setFltGrade3Prob(Double fltGrade3Prob)
  {
    this.fltGrade3Prob = fltGrade3Prob;
  }
    
  public Double getFltGrade4Prob() 
  {
    return fltGrade4Prob;
  }
    
  public void setFltGrade4Prob(Double fltGrade4Prob)
  {
    this.fltGrade4Prob = fltGrade4Prob;
  }
    
  public Integer getLoadCurvePace() 
  {
    return loadCurvePace;
  }
    
  public void setLoadCurvePace(Integer loadCurvePace)
  {
    this.loadCurvePace = loadCurvePace;
  }
    
  public Integer getMaxMSDevNum() 
  {
    return maxMSDevNum;
  }
    
  public void setMaxMSDevNum(Integer maxMSDevNum)
  {
    this.maxMSDevNum = maxMSDevNum;
  }
    
}
    
