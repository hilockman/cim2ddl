package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*交流母线	*
***********************/
public class ACBus  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String Name;
  
  //计算平均电压(千伏)
  private Double kV;
  
  //分区
  private String Zone;
  
  //母线发电有功(兆瓦)
  private Double GenP;
  
  //母线发电无功(兆乏)
  private Double GenQ;
  
  //母线负荷有功(兆瓦)
  private Double LoadP;
  
  //母线负荷无功(兆乏)
  private Double LoadQ;
  
  //辐射网等效负荷(兆瓦)
  private Double RadP;
  
  //母线补偿无功(兆乏)
  private Double ShuntQ;
  
  //故障率(次/年)
  private Double Rerr;
  
  //修复率(次/年)
  private Double Rrep;
  
  //修复时间(小时/次)
  private Double Trep;
  
  //发电机调节量(兆瓦)
  private Double AdGenP;
  
  //负荷调节量(兆瓦)
  private Double AdLoadP;
  
  //辐射网等效负荷调节量(兆瓦)
  private Double AdRadP;
  
  //完好概率
  private Double GoodProb;
  
  //故障概率
  private Double FailProb;
  
  //实际值
  private Double IRt;
  
  //下限值
  private Double IMax;
  
  //上限值
  private Double IMin;
  
  //故障率上限值
  private Double RerrMax;
  
  //故障率下限值
  private Double RerrMin;
  
  //故障次数(次)
  private Integer FaultFreq;
  
  //电压计算结果(千伏)
  private Double RtV;
  
  //功角计算结果(度)
  private Double PfD;
  
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
  
  //系统削减电量指标(兆瓦时/兆瓦.年)
  private Double BPECI;
  
  //系统停电指标(兆瓦/兆瓦.年)
  private Double BPII;
  
  //严重程度指标(系统分/年)
  private Double SI;
  
  //交流电岛
  private Integer ACIsland;
  
  //电压越上限次数(次)
  private Integer UVOLmtFreq;
  
  //频率越上限次数(次)
  private Integer UFOLmtFreq;
  
  //电压越下限次数(次)
  private Integer DVOLmtFreq;
  
  //频率越下限次数(次)
  private Integer DFOLmtFreq;
  
  //环辐网编号
  private Integer Radial;
  
  //平衡母线标记
  private Integer Slack;
  
  //电源母线标记
  private Integer SrcBus;
  
  //中性点标记
  private Integer MidBus;
  
  //母线所接发电机容量上限(兆瓦)
  private Double GenPMax;
  
  //母线所接发电机容量下限(兆瓦)
  private Double GenPMin;
  
  //母线所接负荷功率下限(兆瓦)
  private Double LoadPMin;
  
  //母线线路指针
  private Integer Bus2Line;
  
  //母线变压器指针
  private Integer Bus2Tran;
  
  //母线分区索引
  private Integer ZoneIndex;
  
  //环网内环辐边界母线标记
  private Integer RingBound;
  
  //母线负荷多状态
  private Integer LoadMState;
  
  //直流母线标记
  private Integer DCBus;
  
  //可靠性参数类型
  private Integer RParamType;
  
  //停运
  private Integer Outage;
  
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
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
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
    return Zone;
  }
    
  public void setZone(String Zone)
  {
    this.Zone = Zone;
  }
    
  public Double getGenP()
  {
    return GenP;
  }
    
  public void setGenP(Double GenP)
  {
    this.GenP = GenP;
  }
    
  public Double getGenQ()
  {
    return GenQ;
  }
    
  public void setGenQ(Double GenQ)
  {
    this.GenQ = GenQ;
  }
    
  public Double getLoadP()
  {
    return LoadP;
  }
    
  public void setLoadP(Double LoadP)
  {
    this.LoadP = LoadP;
  }
    
  public Double getLoadQ()
  {
    return LoadQ;
  }
    
  public void setLoadQ(Double LoadQ)
  {
    this.LoadQ = LoadQ;
  }
    
  public Double getRadP()
  {
    return RadP;
  }
    
  public void setRadP(Double RadP)
  {
    this.RadP = RadP;
  }
    
  public Double getShuntQ()
  {
    return ShuntQ;
  }
    
  public void setShuntQ(Double ShuntQ)
  {
    this.ShuntQ = ShuntQ;
  }
    
  public Double getRerr()
  {
    return Rerr;
  }
    
  public void setRerr(Double Rerr)
  {
    this.Rerr = Rerr;
  }
    
  public Double getRrep()
  {
    return Rrep;
  }
    
  public void setRrep(Double Rrep)
  {
    this.Rrep = Rrep;
  }
    
  public Double getTrep()
  {
    return Trep;
  }
    
  public void setTrep(Double Trep)
  {
    this.Trep = Trep;
  }
    
  public Double getAdGenP()
  {
    return AdGenP;
  }
    
  public void setAdGenP(Double AdGenP)
  {
    this.AdGenP = AdGenP;
  }
    
  public Double getAdLoadP()
  {
    return AdLoadP;
  }
    
  public void setAdLoadP(Double AdLoadP)
  {
    this.AdLoadP = AdLoadP;
  }
    
  public Double getAdRadP()
  {
    return AdRadP;
  }
    
  public void setAdRadP(Double AdRadP)
  {
    this.AdRadP = AdRadP;
  }
    
  public Double getGoodProb()
  {
    return GoodProb;
  }
    
  public void setGoodProb(Double GoodProb)
  {
    this.GoodProb = GoodProb;
  }
    
  public Double getFailProb()
  {
    return FailProb;
  }
    
  public void setFailProb(Double FailProb)
  {
    this.FailProb = FailProb;
  }
    
  public Double getIRt()
  {
    return IRt;
  }
    
  public void setIRt(Double IRt)
  {
    this.IRt = IRt;
  }
    
  public Double getIMax()
  {
    return IMax;
  }
    
  public void setIMax(Double IMax)
  {
    this.IMax = IMax;
  }
    
  public Double getIMin()
  {
    return IMin;
  }
    
  public void setIMin(Double IMin)
  {
    this.IMin = IMin;
  }
    
  public Double getRerrMax()
  {
    return RerrMax;
  }
    
  public void setRerrMax(Double RerrMax)
  {
    this.RerrMax = RerrMax;
  }
    
  public Double getRerrMin()
  {
    return RerrMin;
  }
    
  public void setRerrMin(Double RerrMin)
  {
    this.RerrMin = RerrMin;
  }
    
  public Integer getFaultFreq()
  {
    return FaultFreq;
  }
    
  public void setFaultFreq(Integer FaultFreq)
  {
    this.FaultFreq = FaultFreq;
  }
    
  public Double getRtV()
  {
    return RtV;
  }
    
  public void setRtV(Double RtV)
  {
    this.RtV = RtV;
  }
    
  public Double getPfD()
  {
    return PfD;
  }
    
  public void setPfD(Double PfD)
  {
    this.PfD = PfD;
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
    
  public Double getBPECI()
  {
    return BPECI;
  }
    
  public void setBPECI(Double BPECI)
  {
    this.BPECI = BPECI;
  }
    
  public Double getBPII()
  {
    return BPII;
  }
    
  public void setBPII(Double BPII)
  {
    this.BPII = BPII;
  }
    
  public Double getSI()
  {
    return SI;
  }
    
  public void setSI(Double SI)
  {
    this.SI = SI;
  }
    
  public Integer getACIsland()
  {
    return ACIsland;
  }
    
  public void setACIsland(Integer ACIsland)
  {
    this.ACIsland = ACIsland;
  }
    
  public Integer getUVOLmtFreq()
  {
    return UVOLmtFreq;
  }
    
  public void setUVOLmtFreq(Integer UVOLmtFreq)
  {
    this.UVOLmtFreq = UVOLmtFreq;
  }
    
  public Integer getUFOLmtFreq()
  {
    return UFOLmtFreq;
  }
    
  public void setUFOLmtFreq(Integer UFOLmtFreq)
  {
    this.UFOLmtFreq = UFOLmtFreq;
  }
    
  public Integer getDVOLmtFreq()
  {
    return DVOLmtFreq;
  }
    
  public void setDVOLmtFreq(Integer DVOLmtFreq)
  {
    this.DVOLmtFreq = DVOLmtFreq;
  }
    
  public Integer getDFOLmtFreq()
  {
    return DFOLmtFreq;
  }
    
  public void setDFOLmtFreq(Integer DFOLmtFreq)
  {
    this.DFOLmtFreq = DFOLmtFreq;
  }
    
  public Integer getRadial()
  {
    return Radial;
  }
    
  public void setRadial(Integer Radial)
  {
    this.Radial = Radial;
  }
    
  public Integer getSlack()
  {
    return Slack;
  }
    
  public void setSlack(Integer Slack)
  {
    this.Slack = Slack;
  }
    
  public Integer getSrcBus()
  {
    return SrcBus;
  }
    
  public void setSrcBus(Integer SrcBus)
  {
    this.SrcBus = SrcBus;
  }
    
  public Integer getMidBus()
  {
    return MidBus;
  }
    
  public void setMidBus(Integer MidBus)
  {
    this.MidBus = MidBus;
  }
    
  public Double getGenPMax()
  {
    return GenPMax;
  }
    
  public void setGenPMax(Double GenPMax)
  {
    this.GenPMax = GenPMax;
  }
    
  public Double getGenPMin()
  {
    return GenPMin;
  }
    
  public void setGenPMin(Double GenPMin)
  {
    this.GenPMin = GenPMin;
  }
    
  public Double getLoadPMin()
  {
    return LoadPMin;
  }
    
  public void setLoadPMin(Double LoadPMin)
  {
    this.LoadPMin = LoadPMin;
  }
    
  public Integer getBus2Line()
  {
    return Bus2Line;
  }
    
  public void setBus2Line(Integer Bus2Line)
  {
    this.Bus2Line = Bus2Line;
  }
    
  public Integer getBus2Tran()
  {
    return Bus2Tran;
  }
    
  public void setBus2Tran(Integer Bus2Tran)
  {
    this.Bus2Tran = Bus2Tran;
  }
    
  public Integer getZoneIndex()
  {
    return ZoneIndex;
  }
    
  public void setZoneIndex(Integer ZoneIndex)
  {
    this.ZoneIndex = ZoneIndex;
  }
    
  public Integer getRingBound()
  {
    return RingBound;
  }
    
  public void setRingBound(Integer RingBound)
  {
    this.RingBound = RingBound;
  }
    
  public Integer getLoadMState()
  {
    return LoadMState;
  }
    
  public void setLoadMState(Integer LoadMState)
  {
    this.LoadMState = LoadMState;
  }
    
  public Integer getDCBus()
  {
    return DCBus;
  }
    
  public void setDCBus(Integer DCBus)
  {
    this.DCBus = DCBus;
  }
    
  public Integer getRParamType()
  {
    return RParamType;
  }
    
  public void setRParamType(Integer RParamType)
  {
    this.RParamType = RParamType;
  }
    
  public Integer getOutage()
  {
    return Outage;
  }
    
  public void setOutage(Integer Outage)
  {
    this.Outage = Outage;
  }
    
  public String toString()
  {
    return "ACBus ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", kV = " + kV
	 + ", Zone = " + Zone
	 + ", GenP = " + GenP
	 + ", GenQ = " + GenQ
	 + ", LoadP = " + LoadP
	 + ", LoadQ = " + LoadQ
	 + ", RadP = " + RadP
	 + ", ShuntQ = " + ShuntQ
	 + ", Rerr = " + Rerr
	 + ", Rrep = " + Rrep
	 + ", Trep = " + Trep
	 + ", AdGenP = " + AdGenP
	 + ", AdLoadP = " + AdLoadP
	 + ", AdRadP = " + AdRadP
	 + ", GoodProb = " + GoodProb
	 + ", FailProb = " + FailProb
	 + ", IRt = " + IRt
	 + ", IMax = " + IMax
	 + ", IMin = " + IMin
	 + ", RerrMax = " + RerrMax
	 + ", RerrMin = " + RerrMin
	 + ", FaultFreq = " + FaultFreq
	 + ", RtV = " + RtV
	 + ", PfD = " + PfD
	 + ", PLC = " + PLC
	 + ", EFLC = " + EFLC
	 + ", EDLC = " + EDLC
	 + ", ADLC = " + ADLC
	 + ", ELC = " + ELC
	 + ", EENS = " + EENS
	 + ", BPECI = " + BPECI
	 + ", BPII = " + BPII
	 + ", SI = " + SI
	 + ", ACIsland = " + ACIsland
	 + ", UVOLmtFreq = " + UVOLmtFreq
	 + ", UFOLmtFreq = " + UFOLmtFreq
	 + ", DVOLmtFreq = " + DVOLmtFreq
	 + ", DFOLmtFreq = " + DFOLmtFreq
	 + ", Radial = " + Radial
	 + ", Slack = " + Slack
	 + ", SrcBus = " + SrcBus
	 + ", MidBus = " + MidBus
	 + ", GenPMax = " + GenPMax
	 + ", GenPMin = " + GenPMin
	 + ", LoadPMin = " + LoadPMin
	 + ", Bus2Line = " + Bus2Line
	 + ", Bus2Tran = " + Bus2Tran
	 + ", ZoneIndex = " + ZoneIndex
	 + ", RingBound = " + RingBound
	 + ", LoadMState = " + LoadMState
	 + ", DCBus = " + DCBus
	 + ", RParamType = " + RParamType
	 + ", Outage = " + Outage+"]";
  }
    
}
    
