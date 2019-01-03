package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*系统	*
***********************/
public class System  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //功率基准
  private Double MvaBase;
  
  //系统总发电(兆瓦)
  private Double GenP;
  
  //系统总负荷(兆瓦)
  private Double LoadP;
  
  //系统直流容量(兆瓦)
  private Double DCP;
  
  //系统总装机(兆瓦)
  private Double AvailGenP;
  
  //系统最大负荷(兆瓦)
  private Double MaxLoadP;
  
  //抽样方法
  private Integer SampleMethod;
  
  //抽样对象
  private Integer SampleObject;
  
  //最大支路故障重数
  private Integer MaxBranFlt;
  
  //最大发电机故障重数
  private Integer MaxGenFlt;
  
  //蒙特卡罗法模拟时间(小时)
  private Double MCSSimulateTime;
  
  //蒙特卡罗法最小概率值
  private Double MCSMinProb;
  
  //快速排序法截止累计概率值
  private Double FSTCumulateProb;
  
  //快速排序法截止状态数
  private Integer FSTMaxState;
  
  //快速排序法最小概率值
  private Double FSTMinProb;
  
  //状态抽样法截止状态数
  private Integer STSMaxState;
  
  //解析法最小概率值
  private Double ANAMinProb;
  
  //Bpa潮流文件
  private String BpaDatFile;
  
  //Bpa稳定文件
  private String BpaSwiFile;
  
  //安全评估运行目录
  private String SecurityExecDir;
  
  //安全评估结果目录
  private String SecurityDestDir;
  
  //安全评估最大功角差
  private Double SecurityMaxAngle;
  
  //安全评估最高电压
  private Double SecurityMaxVolt;
  
  //安全评估最高电压持续时间
  private Double SecurityMaxVDur;
  
  //安全评估最低电压
  private Double SecurityMinVolt;
  
  //安全评估最低电压持续时间
  private Double SecurityMinVDur;
  
  //安全评估最高频率
  private Double SecurityMaxFreq;
  
  //安全评估最高频率持续时间
  private Double SecurityMaxFDur;
  
  //安全评估最低频率
  private Double SecurityMinFreq;
  
  //安全评估最低频率持续时间
  private Double SecurityMinFDur;
  
  //停运概率表容量步长
  private Double CopStep;
  
  //最大故障设备重数
  private Integer MaxFltDev;
  
  //切负荷状态数
  private Integer CutLoadStateNum;
  
  //切负荷概率
  private Double PLC;
  
  //切负荷频率(次/年)
  private Double EFLC;
  
  //切负荷持续时间(小时/年)
  private Double EDLC;
  
  //每次切负荷持续时间(小时/次)
  private Double ADLC;
  
  //负荷切除期望值(兆瓦/年)
  private Double ELC;
  
  //电量不足期望值(兆瓦时/年)
  private Double EENS;
  
  //系统停电指标(兆瓦/兆瓦.年)
  private Double BPII;
  
  //系统削减电量指标(兆瓦时/兆瓦.年)
  private Double BPECI;
  
  //严重程度指标(系统分/年)
  private Double SI;
  
  //电力不足时间概率(天/年)
  private Double LOLP;
  
  //电力不足频率概率(次/年)
  private Double LOLF;
  
  //电力不足期望值(小时/年)
  private Double LOLE;
  
  //失稳概率
  private Double PLOS;
  
  //失稳频率(次/年)
  private Double FLOS;
  
  //平均稳定运行时间(小时)
  private Double MTTIS;
  
  //孤岛电量不足期望值(兆瓦时/年)
  private Double MIslandEENS;
  
  //失电电量不足期望值(兆瓦时/年)
  private Double LossGenEENS;
  
  //消限电量不足期望值(兆瓦时/年)
  private Double ERlimitEENS;
  
  //网络类型
  private Integer NetworkType;
  
  //非事故状态概率
  private Double FltGrade0Prob;
  
  //一般事故概率
  private Double FltGrade1Prob;
  
  //较大事故概率
  private Double FltGrade2Prob;
  
  //重大事故概率
  private Double FltGrade3Prob;
  
  //特别重大事故概率
  private Double FltGrade4Prob;
  
  //负荷曲线时间间隔
  private Integer LoadCurvePace;
  
  //多状态设备数
  private Integer MaxMSDevNum;
  
  public Integer getId()
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public Integer getMemIndex()
  {
    return memIndex;
  }
    
  public void setMemIndex(Integer memIndex)
  {
    this.memIndex = memIndex;
  }
    
  public Double getMvaBase()
  {
    return MvaBase;
  }
    
  public void setMvaBase(Double MvaBase)
  {
    this.MvaBase = MvaBase;
  }
    
  public Double getGenP()
  {
    return GenP;
  }
    
  public void setGenP(Double GenP)
  {
    this.GenP = GenP;
  }
    
  public Double getLoadP()
  {
    return LoadP;
  }
    
  public void setLoadP(Double LoadP)
  {
    this.LoadP = LoadP;
  }
    
  public Double getDCP()
  {
    return DCP;
  }
    
  public void setDCP(Double DCP)
  {
    this.DCP = DCP;
  }
    
  public Double getAvailGenP()
  {
    return AvailGenP;
  }
    
  public void setAvailGenP(Double AvailGenP)
  {
    this.AvailGenP = AvailGenP;
  }
    
  public Double getMaxLoadP()
  {
    return MaxLoadP;
  }
    
  public void setMaxLoadP(Double MaxLoadP)
  {
    this.MaxLoadP = MaxLoadP;
  }
    
  public Integer getSampleMethod()
  {
    return SampleMethod;
  }
    
  public void setSampleMethod(Integer SampleMethod)
  {
    this.SampleMethod = SampleMethod;
  }
    
  public Integer getSampleObject()
  {
    return SampleObject;
  }
    
  public void setSampleObject(Integer SampleObject)
  {
    this.SampleObject = SampleObject;
  }
    
  public Integer getMaxBranFlt()
  {
    return MaxBranFlt;
  }
    
  public void setMaxBranFlt(Integer MaxBranFlt)
  {
    this.MaxBranFlt = MaxBranFlt;
  }
    
  public Integer getMaxGenFlt()
  {
    return MaxGenFlt;
  }
    
  public void setMaxGenFlt(Integer MaxGenFlt)
  {
    this.MaxGenFlt = MaxGenFlt;
  }
    
  public Double getMCSSimulateTime()
  {
    return MCSSimulateTime;
  }
    
  public void setMCSSimulateTime(Double MCSSimulateTime)
  {
    this.MCSSimulateTime = MCSSimulateTime;
  }
    
  public Double getMCSMinProb()
  {
    return MCSMinProb;
  }
    
  public void setMCSMinProb(Double MCSMinProb)
  {
    this.MCSMinProb = MCSMinProb;
  }
    
  public Double getFSTCumulateProb()
  {
    return FSTCumulateProb;
  }
    
  public void setFSTCumulateProb(Double FSTCumulateProb)
  {
    this.FSTCumulateProb = FSTCumulateProb;
  }
    
  public Integer getFSTMaxState()
  {
    return FSTMaxState;
  }
    
  public void setFSTMaxState(Integer FSTMaxState)
  {
    this.FSTMaxState = FSTMaxState;
  }
    
  public Double getFSTMinProb()
  {
    return FSTMinProb;
  }
    
  public void setFSTMinProb(Double FSTMinProb)
  {
    this.FSTMinProb = FSTMinProb;
  }
    
  public Integer getSTSMaxState()
  {
    return STSMaxState;
  }
    
  public void setSTSMaxState(Integer STSMaxState)
  {
    this.STSMaxState = STSMaxState;
  }
    
  public Double getANAMinProb()
  {
    return ANAMinProb;
  }
    
  public void setANAMinProb(Double ANAMinProb)
  {
    this.ANAMinProb = ANAMinProb;
  }
    
  public String getBpaDatFile()
  {
    return BpaDatFile;
  }
    
  public void setBpaDatFile(String BpaDatFile)
  {
    this.BpaDatFile = BpaDatFile;
  }
    
  public String getBpaSwiFile()
  {
    return BpaSwiFile;
  }
    
  public void setBpaSwiFile(String BpaSwiFile)
  {
    this.BpaSwiFile = BpaSwiFile;
  }
    
  public String getSecurityExecDir()
  {
    return SecurityExecDir;
  }
    
  public void setSecurityExecDir(String SecurityExecDir)
  {
    this.SecurityExecDir = SecurityExecDir;
  }
    
  public String getSecurityDestDir()
  {
    return SecurityDestDir;
  }
    
  public void setSecurityDestDir(String SecurityDestDir)
  {
    this.SecurityDestDir = SecurityDestDir;
  }
    
  public Double getSecurityMaxAngle()
  {
    return SecurityMaxAngle;
  }
    
  public void setSecurityMaxAngle(Double SecurityMaxAngle)
  {
    this.SecurityMaxAngle = SecurityMaxAngle;
  }
    
  public Double getSecurityMaxVolt()
  {
    return SecurityMaxVolt;
  }
    
  public void setSecurityMaxVolt(Double SecurityMaxVolt)
  {
    this.SecurityMaxVolt = SecurityMaxVolt;
  }
    
  public Double getSecurityMaxVDur()
  {
    return SecurityMaxVDur;
  }
    
  public void setSecurityMaxVDur(Double SecurityMaxVDur)
  {
    this.SecurityMaxVDur = SecurityMaxVDur;
  }
    
  public Double getSecurityMinVolt()
  {
    return SecurityMinVolt;
  }
    
  public void setSecurityMinVolt(Double SecurityMinVolt)
  {
    this.SecurityMinVolt = SecurityMinVolt;
  }
    
  public Double getSecurityMinVDur()
  {
    return SecurityMinVDur;
  }
    
  public void setSecurityMinVDur(Double SecurityMinVDur)
  {
    this.SecurityMinVDur = SecurityMinVDur;
  }
    
  public Double getSecurityMaxFreq()
  {
    return SecurityMaxFreq;
  }
    
  public void setSecurityMaxFreq(Double SecurityMaxFreq)
  {
    this.SecurityMaxFreq = SecurityMaxFreq;
  }
    
  public Double getSecurityMaxFDur()
  {
    return SecurityMaxFDur;
  }
    
  public void setSecurityMaxFDur(Double SecurityMaxFDur)
  {
    this.SecurityMaxFDur = SecurityMaxFDur;
  }
    
  public Double getSecurityMinFreq()
  {
    return SecurityMinFreq;
  }
    
  public void setSecurityMinFreq(Double SecurityMinFreq)
  {
    this.SecurityMinFreq = SecurityMinFreq;
  }
    
  public Double getSecurityMinFDur()
  {
    return SecurityMinFDur;
  }
    
  public void setSecurityMinFDur(Double SecurityMinFDur)
  {
    this.SecurityMinFDur = SecurityMinFDur;
  }
    
  public Double getCopStep()
  {
    return CopStep;
  }
    
  public void setCopStep(Double CopStep)
  {
    this.CopStep = CopStep;
  }
    
  public Integer getMaxFltDev()
  {
    return MaxFltDev;
  }
    
  public void setMaxFltDev(Integer MaxFltDev)
  {
    this.MaxFltDev = MaxFltDev;
  }
    
  public Integer getCutLoadStateNum()
  {
    return CutLoadStateNum;
  }
    
  public void setCutLoadStateNum(Integer CutLoadStateNum)
  {
    this.CutLoadStateNum = CutLoadStateNum;
  }
    
  public Double getPLC()
  {
    return PLC;
  }
    
  public void setPLC(Double PLC)
  {
    this.PLC = PLC;
  }
    
  public Double getEFLC()
  {
    return EFLC;
  }
    
  public void setEFLC(Double EFLC)
  {
    this.EFLC = EFLC;
  }
    
  public Double getEDLC()
  {
    return EDLC;
  }
    
  public void setEDLC(Double EDLC)
  {
    this.EDLC = EDLC;
  }
    
  public Double getADLC()
  {
    return ADLC;
  }
    
  public void setADLC(Double ADLC)
  {
    this.ADLC = ADLC;
  }
    
  public Double getELC()
  {
    return ELC;
  }
    
  public void setELC(Double ELC)
  {
    this.ELC = ELC;
  }
    
  public Double getEENS()
  {
    return EENS;
  }
    
  public void setEENS(Double EENS)
  {
    this.EENS = EENS;
  }
    
  public Double getBPII()
  {
    return BPII;
  }
    
  public void setBPII(Double BPII)
  {
    this.BPII = BPII;
  }
    
  public Double getBPECI()
  {
    return BPECI;
  }
    
  public void setBPECI(Double BPECI)
  {
    this.BPECI = BPECI;
  }
    
  public Double getSI()
  {
    return SI;
  }
    
  public void setSI(Double SI)
  {
    this.SI = SI;
  }
    
  public Double getLOLP()
  {
    return LOLP;
  }
    
  public void setLOLP(Double LOLP)
  {
    this.LOLP = LOLP;
  }
    
  public Double getLOLF()
  {
    return LOLF;
  }
    
  public void setLOLF(Double LOLF)
  {
    this.LOLF = LOLF;
  }
    
  public Double getLOLE()
  {
    return LOLE;
  }
    
  public void setLOLE(Double LOLE)
  {
    this.LOLE = LOLE;
  }
    
  public Double getPLOS()
  {
    return PLOS;
  }
    
  public void setPLOS(Double PLOS)
  {
    this.PLOS = PLOS;
  }
    
  public Double getFLOS()
  {
    return FLOS;
  }
    
  public void setFLOS(Double FLOS)
  {
    this.FLOS = FLOS;
  }
    
  public Double getMTTIS()
  {
    return MTTIS;
  }
    
  public void setMTTIS(Double MTTIS)
  {
    this.MTTIS = MTTIS;
  }
    
  public Double getMIslandEENS()
  {
    return MIslandEENS;
  }
    
  public void setMIslandEENS(Double MIslandEENS)
  {
    this.MIslandEENS = MIslandEENS;
  }
    
  public Double getLossGenEENS()
  {
    return LossGenEENS;
  }
    
  public void setLossGenEENS(Double LossGenEENS)
  {
    this.LossGenEENS = LossGenEENS;
  }
    
  public Double getERlimitEENS()
  {
    return ERlimitEENS;
  }
    
  public void setERlimitEENS(Double ERlimitEENS)
  {
    this.ERlimitEENS = ERlimitEENS;
  }
    
  public Integer getNetworkType()
  {
    return NetworkType;
  }
    
  public void setNetworkType(Integer NetworkType)
  {
    this.NetworkType = NetworkType;
  }
    
  public Double getFltGrade0Prob()
  {
    return FltGrade0Prob;
  }
    
  public void setFltGrade0Prob(Double FltGrade0Prob)
  {
    this.FltGrade0Prob = FltGrade0Prob;
  }
    
  public Double getFltGrade1Prob()
  {
    return FltGrade1Prob;
  }
    
  public void setFltGrade1Prob(Double FltGrade1Prob)
  {
    this.FltGrade1Prob = FltGrade1Prob;
  }
    
  public Double getFltGrade2Prob()
  {
    return FltGrade2Prob;
  }
    
  public void setFltGrade2Prob(Double FltGrade2Prob)
  {
    this.FltGrade2Prob = FltGrade2Prob;
  }
    
  public Double getFltGrade3Prob()
  {
    return FltGrade3Prob;
  }
    
  public void setFltGrade3Prob(Double FltGrade3Prob)
  {
    this.FltGrade3Prob = FltGrade3Prob;
  }
    
  public Double getFltGrade4Prob()
  {
    return FltGrade4Prob;
  }
    
  public void setFltGrade4Prob(Double FltGrade4Prob)
  {
    this.FltGrade4Prob = FltGrade4Prob;
  }
    
  public Integer getLoadCurvePace()
  {
    return LoadCurvePace;
  }
    
  public void setLoadCurvePace(Integer LoadCurvePace)
  {
    this.LoadCurvePace = LoadCurvePace;
  }
    
  public Integer getMaxMSDevNum()
  {
    return MaxMSDevNum;
  }
    
  public void setMaxMSDevNum(Integer MaxMSDevNum)
  {
    this.MaxMSDevNum = MaxMSDevNum;
  }
    
  public String toString()
  {
    return "System ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", MvaBase = " + MvaBase
	 + ", GenP = " + GenP
	 + ", LoadP = " + LoadP
	 + ", DCP = " + DCP
	 + ", AvailGenP = " + AvailGenP
	 + ", MaxLoadP = " + MaxLoadP
	 + ", SampleMethod = " + SampleMethod
	 + ", SampleObject = " + SampleObject
	 + ", MaxBranFlt = " + MaxBranFlt
	 + ", MaxGenFlt = " + MaxGenFlt
	 + ", MCSSimulateTime = " + MCSSimulateTime
	 + ", MCSMinProb = " + MCSMinProb
	 + ", FSTCumulateProb = " + FSTCumulateProb
	 + ", FSTMaxState = " + FSTMaxState
	 + ", FSTMinProb = " + FSTMinProb
	 + ", STSMaxState = " + STSMaxState
	 + ", ANAMinProb = " + ANAMinProb
	 + ", BpaDatFile = " + BpaDatFile
	 + ", BpaSwiFile = " + BpaSwiFile
	 + ", SecurityExecDir = " + SecurityExecDir
	 + ", SecurityDestDir = " + SecurityDestDir
	 + ", SecurityMaxAngle = " + SecurityMaxAngle
	 + ", SecurityMaxVolt = " + SecurityMaxVolt
	 + ", SecurityMaxVDur = " + SecurityMaxVDur
	 + ", SecurityMinVolt = " + SecurityMinVolt
	 + ", SecurityMinVDur = " + SecurityMinVDur
	 + ", SecurityMaxFreq = " + SecurityMaxFreq
	 + ", SecurityMaxFDur = " + SecurityMaxFDur
	 + ", SecurityMinFreq = " + SecurityMinFreq
	 + ", SecurityMinFDur = " + SecurityMinFDur
	 + ", CopStep = " + CopStep
	 + ", MaxFltDev = " + MaxFltDev
	 + ", CutLoadStateNum = " + CutLoadStateNum
	 + ", PLC = " + PLC
	 + ", EFLC = " + EFLC
	 + ", EDLC = " + EDLC
	 + ", ADLC = " + ADLC
	 + ", ELC = " + ELC
	 + ", EENS = " + EENS
	 + ", BPII = " + BPII
	 + ", BPECI = " + BPECI
	 + ", SI = " + SI
	 + ", LOLP = " + LOLP
	 + ", LOLF = " + LOLF
	 + ", LOLE = " + LOLE
	 + ", PLOS = " + PLOS
	 + ", FLOS = " + FLOS
	 + ", MTTIS = " + MTTIS
	 + ", MIslandEENS = " + MIslandEENS
	 + ", LossGenEENS = " + LossGenEENS
	 + ", ERlimitEENS = " + ERlimitEENS
	 + ", NetworkType = " + NetworkType
	 + ", FltGrade0Prob = " + FltGrade0Prob
	 + ", FltGrade1Prob = " + FltGrade1Prob
	 + ", FltGrade2Prob = " + FltGrade2Prob
	 + ", FltGrade3Prob = " + FltGrade3Prob
	 + ", FltGrade4Prob = " + FltGrade4Prob
	 + ", LoadCurvePace = " + LoadCurvePace
	 + ", MaxMSDevNum = " + MaxMSDevNum+"]";
  }
    
}
    
