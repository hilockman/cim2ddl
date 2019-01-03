package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*负荷	*
***********************/
public class PowerLoad  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String Name;
  
  //母线
  private String BusName;
  
  //电压(千伏)
  private Double BuskV;
  
  //分区
  private String Zone;
  
  //有功(兆瓦)
  private Double P;
  
  //无功(兆乏)
  private Double Q;
  
  //最大有功(兆瓦)
  private Double PMax;
  
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
  
  //多状态模型
  private Integer MSModel;
  
  //多状态状态数
  private Integer MStateNum;
  
  //多状态功率(兆瓦)
  private Double MSPout;
  
  //给定有功(兆瓦)
  private Double ReferenceP;
  
  //给定无功(兆乏)
  private Double ReferenceQ;
  
  //环辐网编号
  private Integer Radial;
  
  //母线索引
  private Integer BusPtr;
  
  //厂用电标记
  private Integer AuxLoad;
  
  //等值负荷标记
  private Integer EQLoad;
  
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
    
  public String getBusName()
  {
    return BusName;
  }
    
  public void setBusName(String BusName)
  {
    this.BusName = BusName;
  }
    
  public Double getBuskV()
  {
    return BuskV;
  }
    
  public void setBuskV(Double BuskV)
  {
    this.BuskV = BuskV;
  }
    
  public String getZone()
  {
    return Zone;
  }
    
  public void setZone(String Zone)
  {
    this.Zone = Zone;
  }
    
  public Double getP()
  {
    return P;
  }
    
  public void setP(Double P)
  {
    this.P = P;
  }
    
  public Double getQ()
  {
    return Q;
  }
    
  public void setQ(Double Q)
  {
    this.Q = Q;
  }
    
  public Double getPMax()
  {
    return PMax;
  }
    
  public void setPMax(Double PMax)
  {
    this.PMax = PMax;
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
    
  public Integer getMSModel()
  {
    return MSModel;
  }
    
  public void setMSModel(Integer MSModel)
  {
    this.MSModel = MSModel;
  }
    
  public Integer getMStateNum()
  {
    return MStateNum;
  }
    
  public void setMStateNum(Integer MStateNum)
  {
    this.MStateNum = MStateNum;
  }
    
  public Double getMSPout()
  {
    return MSPout;
  }
    
  public void setMSPout(Double MSPout)
  {
    this.MSPout = MSPout;
  }
    
  public Double getReferenceP()
  {
    return ReferenceP;
  }
    
  public void setReferenceP(Double ReferenceP)
  {
    this.ReferenceP = ReferenceP;
  }
    
  public Double getReferenceQ()
  {
    return ReferenceQ;
  }
    
  public void setReferenceQ(Double ReferenceQ)
  {
    this.ReferenceQ = ReferenceQ;
  }
    
  public Integer getRadial()
  {
    return Radial;
  }
    
  public void setRadial(Integer Radial)
  {
    this.Radial = Radial;
  }
    
  public Integer getBusPtr()
  {
    return BusPtr;
  }
    
  public void setBusPtr(Integer BusPtr)
  {
    this.BusPtr = BusPtr;
  }
    
  public Integer getAuxLoad()
  {
    return AuxLoad;
  }
    
  public void setAuxLoad(Integer AuxLoad)
  {
    this.AuxLoad = AuxLoad;
  }
    
  public Integer getEQLoad()
  {
    return EQLoad;
  }
    
  public void setEQLoad(Integer EQLoad)
  {
    this.EQLoad = EQLoad;
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
    return "PowerLoad ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", BusName = " + BusName
	 + ", BuskV = " + BuskV
	 + ", Zone = " + Zone
	 + ", P = " + P
	 + ", Q = " + Q
	 + ", PMax = " + PMax
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
	 + ", MSModel = " + MSModel
	 + ", MStateNum = " + MStateNum
	 + ", MSPout = " + MSPout
	 + ", ReferenceP = " + ReferenceP
	 + ", ReferenceQ = " + ReferenceQ
	 + ", Radial = " + Radial
	 + ", BusPtr = " + BusPtr
	 + ", AuxLoad = " + AuxLoad
	 + ", EQLoad = " + EQLoad
	 + ", RParamType = " + RParamType
	 + ", Outage = " + Outage+"]";
  }
    
}
    
