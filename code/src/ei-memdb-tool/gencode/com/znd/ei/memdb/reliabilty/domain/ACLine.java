package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*交流线路	*
***********************/
public class ACLine  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String Name;
  
  //起节点名称
  private String BusI;
  
  //终节点名称
  private String BusJ;
  
  //I侧电压(kV)
  private Double kVI;
  
  //J侧电压(kV)
  private Double kVJ;
  
  //并联回路号
  private Integer ParlId;
  
  //电阻(pu)
  private Double R;
  
  //电抗(pu)
  private Double X;
  
  //电纳(pu)
  private Double B;
  
  //额定容量(MW)
  private Double Rated;
  
  //长度(KM)
  private Double Length;
  
  //越限指标权重
  private Double Weights;
  
  //故障率(次/年)
  private Double Rerr;
  
  //修复率(次/年)
  private Double Rrep;
  
  //修复时间(小时/次)
  private Double Trep;
  
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
  
  //越限次数
  private Integer OLmtFreq;
  
  //越限功率(MW/次)
  private Double OLmtValue;
  
  //消限切负荷电量(MW.h/年)
  private Double ELmtCutLoad;
  
  //RT起点有功(MW)
  private Double RtPi;
  
  //RT起点无功(MVar)
  private Double RtQi;
  
  //RT终点有功(MW)
  private Double RtPz;
  
  //RT终点无功(MVar)
  private Double RtQz;
  
  //损耗(MW)
  private Double LossP;
  
  //PF起点有功(MW)
  private Double PfPi;
  
  //PF起点无功(MVar)
  private Double PfQi;
  
  //PF终点有功(MW)
  private Double PfPz;
  
  //PF终点无功(MVar)
  private Double PfQz;
  
  //TR起点有功(MW)
  private Double TrPi;
  
  //TR起点无功(MVar)
  private Double TrQi;
  
  //TR终点有功(MW)
  private Double TrPz;
  
  //TR终点无功(MVar)
  private Double TrQz;
  
  //Ini起节点名称
  private String IniBusI;
  
  //Ini终节点名称
  private String IniBusJ;
  
  //Ini起点侧电压(kV)
  private Double InikVI;
  
  //Ini终点侧电压(kV)
  private Double InikVJ;
  
  //Ini并联回路号
  private Integer IniLoop;
  
  //起节点索引
  private Integer BusIPtr;
  
  //终节点索引
  private Integer BusJPtr;
  
  //起节点辐网编号
  private Integer RadIPtr;
  
  //终节点辐网编号
  private Integer RadJPtr;
  
  //线路索引
  private Integer SerialNo;
  
  //交流电岛
  private Integer ACIsland;
  
  //停运
  private Integer Outage;
  
  //可靠性参数类型
  private Integer RParamType;
  
  //N-1多岛
  private Integer TrMIsland;
  
  //一阶相关开断分布因子个数
  private Integer TrFactorNum;
  
  //TCSC索引
  private Integer TCSCPtr;
  
  //UPFC索引
  private Integer UPFCPtr;
  
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
    
  public String getBusI()
  {
    return BusI;
  }
    
  public void setBusI(String BusI)
  {
    this.BusI = BusI;
  }
    
  public String getBusJ()
  {
    return BusJ;
  }
    
  public void setBusJ(String BusJ)
  {
    this.BusJ = BusJ;
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
    return ParlId;
  }
    
  public void setParlId(Integer ParlId)
  {
    this.ParlId = ParlId;
  }
    
  public Double getR()
  {
    return R;
  }
    
  public void setR(Double R)
  {
    this.R = R;
  }
    
  public Double getX()
  {
    return X;
  }
    
  public void setX(Double X)
  {
    this.X = X;
  }
    
  public Double getB()
  {
    return B;
  }
    
  public void setB(Double B)
  {
    this.B = B;
  }
    
  public Double getRated()
  {
    return Rated;
  }
    
  public void setRated(Double Rated)
  {
    this.Rated = Rated;
  }
    
  public Double getLength()
  {
    return Length;
  }
    
  public void setLength(Double Length)
  {
    this.Length = Length;
  }
    
  public Double getWeights()
  {
    return Weights;
  }
    
  public void setWeights(Double Weights)
  {
    this.Weights = Weights;
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
    
  public Integer getOLmtFreq()
  {
    return OLmtFreq;
  }
    
  public void setOLmtFreq(Integer OLmtFreq)
  {
    this.OLmtFreq = OLmtFreq;
  }
    
  public Double getOLmtValue()
  {
    return OLmtValue;
  }
    
  public void setOLmtValue(Double OLmtValue)
  {
    this.OLmtValue = OLmtValue;
  }
    
  public Double getELmtCutLoad()
  {
    return ELmtCutLoad;
  }
    
  public void setELmtCutLoad(Double ELmtCutLoad)
  {
    this.ELmtCutLoad = ELmtCutLoad;
  }
    
  public Double getRtPi()
  {
    return RtPi;
  }
    
  public void setRtPi(Double RtPi)
  {
    this.RtPi = RtPi;
  }
    
  public Double getRtQi()
  {
    return RtQi;
  }
    
  public void setRtQi(Double RtQi)
  {
    this.RtQi = RtQi;
  }
    
  public Double getRtPz()
  {
    return RtPz;
  }
    
  public void setRtPz(Double RtPz)
  {
    this.RtPz = RtPz;
  }
    
  public Double getRtQz()
  {
    return RtQz;
  }
    
  public void setRtQz(Double RtQz)
  {
    this.RtQz = RtQz;
  }
    
  public Double getLossP()
  {
    return LossP;
  }
    
  public void setLossP(Double LossP)
  {
    this.LossP = LossP;
  }
    
  public Double getPfPi()
  {
    return PfPi;
  }
    
  public void setPfPi(Double PfPi)
  {
    this.PfPi = PfPi;
  }
    
  public Double getPfQi()
  {
    return PfQi;
  }
    
  public void setPfQi(Double PfQi)
  {
    this.PfQi = PfQi;
  }
    
  public Double getPfPz()
  {
    return PfPz;
  }
    
  public void setPfPz(Double PfPz)
  {
    this.PfPz = PfPz;
  }
    
  public Double getPfQz()
  {
    return PfQz;
  }
    
  public void setPfQz(Double PfQz)
  {
    this.PfQz = PfQz;
  }
    
  public Double getTrPi()
  {
    return TrPi;
  }
    
  public void setTrPi(Double TrPi)
  {
    this.TrPi = TrPi;
  }
    
  public Double getTrQi()
  {
    return TrQi;
  }
    
  public void setTrQi(Double TrQi)
  {
    this.TrQi = TrQi;
  }
    
  public Double getTrPz()
  {
    return TrPz;
  }
    
  public void setTrPz(Double TrPz)
  {
    this.TrPz = TrPz;
  }
    
  public Double getTrQz()
  {
    return TrQz;
  }
    
  public void setTrQz(Double TrQz)
  {
    this.TrQz = TrQz;
  }
    
  public String getIniBusI()
  {
    return IniBusI;
  }
    
  public void setIniBusI(String IniBusI)
  {
    this.IniBusI = IniBusI;
  }
    
  public String getIniBusJ()
  {
    return IniBusJ;
  }
    
  public void setIniBusJ(String IniBusJ)
  {
    this.IniBusJ = IniBusJ;
  }
    
  public Double getInikVI()
  {
    return InikVI;
  }
    
  public void setInikVI(Double InikVI)
  {
    this.InikVI = InikVI;
  }
    
  public Double getInikVJ()
  {
    return InikVJ;
  }
    
  public void setInikVJ(Double InikVJ)
  {
    this.InikVJ = InikVJ;
  }
    
  public Integer getIniLoop()
  {
    return IniLoop;
  }
    
  public void setIniLoop(Integer IniLoop)
  {
    this.IniLoop = IniLoop;
  }
    
  public Integer getBusIPtr()
  {
    return BusIPtr;
  }
    
  public void setBusIPtr(Integer BusIPtr)
  {
    this.BusIPtr = BusIPtr;
  }
    
  public Integer getBusJPtr()
  {
    return BusJPtr;
  }
    
  public void setBusJPtr(Integer BusJPtr)
  {
    this.BusJPtr = BusJPtr;
  }
    
  public Integer getRadIPtr()
  {
    return RadIPtr;
  }
    
  public void setRadIPtr(Integer RadIPtr)
  {
    this.RadIPtr = RadIPtr;
  }
    
  public Integer getRadJPtr()
  {
    return RadJPtr;
  }
    
  public void setRadJPtr(Integer RadJPtr)
  {
    this.RadJPtr = RadJPtr;
  }
    
  public Integer getSerialNo()
  {
    return SerialNo;
  }
    
  public void setSerialNo(Integer SerialNo)
  {
    this.SerialNo = SerialNo;
  }
    
  public Integer getACIsland()
  {
    return ACIsland;
  }
    
  public void setACIsland(Integer ACIsland)
  {
    this.ACIsland = ACIsland;
  }
    
  public Integer getOutage()
  {
    return Outage;
  }
    
  public void setOutage(Integer Outage)
  {
    this.Outage = Outage;
  }
    
  public Integer getRParamType()
  {
    return RParamType;
  }
    
  public void setRParamType(Integer RParamType)
  {
    this.RParamType = RParamType;
  }
    
  public Integer getTrMIsland()
  {
    return TrMIsland;
  }
    
  public void setTrMIsland(Integer TrMIsland)
  {
    this.TrMIsland = TrMIsland;
  }
    
  public Integer getTrFactorNum()
  {
    return TrFactorNum;
  }
    
  public void setTrFactorNum(Integer TrFactorNum)
  {
    this.TrFactorNum = TrFactorNum;
  }
    
  public Integer getTCSCPtr()
  {
    return TCSCPtr;
  }
    
  public void setTCSCPtr(Integer TCSCPtr)
  {
    this.TCSCPtr = TCSCPtr;
  }
    
  public Integer getUPFCPtr()
  {
    return UPFCPtr;
  }
    
  public void setUPFCPtr(Integer UPFCPtr)
  {
    this.UPFCPtr = UPFCPtr;
  }
    
  public String toString()
  {
    return "ACLine ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", BusI = " + BusI
	 + ", BusJ = " + BusJ
	 + ", kVI = " + kVI
	 + ", kVJ = " + kVJ
	 + ", ParlId = " + ParlId
	 + ", R = " + R
	 + ", X = " + X
	 + ", B = " + B
	 + ", Rated = " + Rated
	 + ", Length = " + Length
	 + ", Weights = " + Weights
	 + ", Rerr = " + Rerr
	 + ", Rrep = " + Rrep
	 + ", Trep = " + Trep
	 + ", GoodProb = " + GoodProb
	 + ", FailProb = " + FailProb
	 + ", IRt = " + IRt
	 + ", IMax = " + IMax
	 + ", IMin = " + IMin
	 + ", RerrMax = " + RerrMax
	 + ", RerrMin = " + RerrMin
	 + ", FaultFreq = " + FaultFreq
	 + ", OLmtFreq = " + OLmtFreq
	 + ", OLmtValue = " + OLmtValue
	 + ", ELmtCutLoad = " + ELmtCutLoad
	 + ", RtPi = " + RtPi
	 + ", RtQi = " + RtQi
	 + ", RtPz = " + RtPz
	 + ", RtQz = " + RtQz
	 + ", LossP = " + LossP
	 + ", PfPi = " + PfPi
	 + ", PfQi = " + PfQi
	 + ", PfPz = " + PfPz
	 + ", PfQz = " + PfQz
	 + ", TrPi = " + TrPi
	 + ", TrQi = " + TrQi
	 + ", TrPz = " + TrPz
	 + ", TrQz = " + TrQz
	 + ", IniBusI = " + IniBusI
	 + ", IniBusJ = " + IniBusJ
	 + ", InikVI = " + InikVI
	 + ", InikVJ = " + InikVJ
	 + ", IniLoop = " + IniLoop
	 + ", BusIPtr = " + BusIPtr
	 + ", BusJPtr = " + BusJPtr
	 + ", RadIPtr = " + RadIPtr
	 + ", RadJPtr = " + RadJPtr
	 + ", SerialNo = " + SerialNo
	 + ", ACIsland = " + ACIsland
	 + ", Outage = " + Outage
	 + ", RParamType = " + RParamType
	 + ", TrMIsland = " + TrMIsland
	 + ", TrFactorNum = " + TrFactorNum
	 + ", TCSCPtr = " + TCSCPtr
	 + ", UPFCPtr = " + UPFCPtr+"]";
  }
    
}
    
