package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*高压直流系统	*
***********************/
public class HVDC  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String Name;
  
  //整流交流节点名称
  private String ACBusR;
  
  //逆变交流节点名称
  private String ACBusI;
  
  //整流侧电压(千伏)
  private Double kVR;
  
  //逆变侧电压(千伏)
  private Double kVI;
  
  //电阻(欧姆)
  private Double R;
  
  //电感(毫亨)
  private Double L;
  
  //电容(微法)
  private Double C;
  
  //控制测R/I
  private Integer Con;
  
  //额定电流(安)
  private Double RatedC;
  
  //整流侧直流电压(千伏)
  private Double RectV;
  
  //额定功率(兆瓦)
  private Double RatedP;
  
  //长度(千米)
  private Double Length;
  
  //安排的直流功率(兆瓦)
  private Double Power;
  
  //整流侧功率(兆瓦)
  private Double PwrR;
  
  //逆变侧功率(兆瓦)
  private Double PwrI;
  
  //损耗(兆瓦)
  private Double LossP;
  
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
  
  //多状态功率状态
  private Double MSPout;
  
  //Ini整流节点名称
  private String IniBusR;
  
  //Ini逆变节点名称
  private String IniBusI;
  
  //Ini整流侧功率(兆瓦)
  private Double IniPwrR;
  
  //Ini逆变侧功率(兆瓦)
  private Double IniPwrI;
  
  //整流节点索引
  private Integer ACBusRPtr;
  
  //逆变节点索引
  private Integer ACBusIPtr;
  
  //整流侧交流电岛
  private Integer ACIslandR;
  
  //逆变侧交流电岛
  private Integer ACIslandI;
  
  //直流索引
  private Integer SerialNo;
  
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
    
  public String getACBusR()
  {
    return ACBusR;
  }
    
  public void setACBusR(String ACBusR)
  {
    this.ACBusR = ACBusR;
  }
    
  public String getACBusI()
  {
    return ACBusI;
  }
    
  public void setACBusI(String ACBusI)
  {
    this.ACBusI = ACBusI;
  }
    
  public Double getkVR()
  {
    return kVR;
  }
    
  public void setkVR(Double kVR)
  {
    this.kVR = kVR;
  }
    
  public Double getkVI()
  {
    return kVI;
  }
    
  public void setkVI(Double kVI)
  {
    this.kVI = kVI;
  }
    
  public Double getR()
  {
    return R;
  }
    
  public void setR(Double R)
  {
    this.R = R;
  }
    
  public Double getL()
  {
    return L;
  }
    
  public void setL(Double L)
  {
    this.L = L;
  }
    
  public Double getC()
  {
    return C;
  }
    
  public void setC(Double C)
  {
    this.C = C;
  }
    
  public Integer getCon()
  {
    return Con;
  }
    
  public void setCon(Integer Con)
  {
    this.Con = Con;
  }
    
  public Double getRatedC()
  {
    return RatedC;
  }
    
  public void setRatedC(Double RatedC)
  {
    this.RatedC = RatedC;
  }
    
  public Double getRectV()
  {
    return RectV;
  }
    
  public void setRectV(Double RectV)
  {
    this.RectV = RectV;
  }
    
  public Double getRatedP()
  {
    return RatedP;
  }
    
  public void setRatedP(Double RatedP)
  {
    this.RatedP = RatedP;
  }
    
  public Double getLength()
  {
    return Length;
  }
    
  public void setLength(Double Length)
  {
    this.Length = Length;
  }
    
  public Double getPower()
  {
    return Power;
  }
    
  public void setPower(Double Power)
  {
    this.Power = Power;
  }
    
  public Double getPwrR()
  {
    return PwrR;
  }
    
  public void setPwrR(Double PwrR)
  {
    this.PwrR = PwrR;
  }
    
  public Double getPwrI()
  {
    return PwrI;
  }
    
  public void setPwrI(Double PwrI)
  {
    this.PwrI = PwrI;
  }
    
  public Double getLossP()
  {
    return LossP;
  }
    
  public void setLossP(Double LossP)
  {
    this.LossP = LossP;
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
    
  public String getIniBusR()
  {
    return IniBusR;
  }
    
  public void setIniBusR(String IniBusR)
  {
    this.IniBusR = IniBusR;
  }
    
  public String getIniBusI()
  {
    return IniBusI;
  }
    
  public void setIniBusI(String IniBusI)
  {
    this.IniBusI = IniBusI;
  }
    
  public Double getIniPwrR()
  {
    return IniPwrR;
  }
    
  public void setIniPwrR(Double IniPwrR)
  {
    this.IniPwrR = IniPwrR;
  }
    
  public Double getIniPwrI()
  {
    return IniPwrI;
  }
    
  public void setIniPwrI(Double IniPwrI)
  {
    this.IniPwrI = IniPwrI;
  }
    
  public Integer getACBusRPtr()
  {
    return ACBusRPtr;
  }
    
  public void setACBusRPtr(Integer ACBusRPtr)
  {
    this.ACBusRPtr = ACBusRPtr;
  }
    
  public Integer getACBusIPtr()
  {
    return ACBusIPtr;
  }
    
  public void setACBusIPtr(Integer ACBusIPtr)
  {
    this.ACBusIPtr = ACBusIPtr;
  }
    
  public Integer getACIslandR()
  {
    return ACIslandR;
  }
    
  public void setACIslandR(Integer ACIslandR)
  {
    this.ACIslandR = ACIslandR;
  }
    
  public Integer getACIslandI()
  {
    return ACIslandI;
  }
    
  public void setACIslandI(Integer ACIslandI)
  {
    this.ACIslandI = ACIslandI;
  }
    
  public Integer getSerialNo()
  {
    return SerialNo;
  }
    
  public void setSerialNo(Integer SerialNo)
  {
    this.SerialNo = SerialNo;
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
    return "HVDC ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", ACBusR = " + ACBusR
	 + ", ACBusI = " + ACBusI
	 + ", kVR = " + kVR
	 + ", kVI = " + kVI
	 + ", R = " + R
	 + ", L = " + L
	 + ", C = " + C
	 + ", Con = " + Con
	 + ", RatedC = " + RatedC
	 + ", RectV = " + RectV
	 + ", RatedP = " + RatedP
	 + ", Length = " + Length
	 + ", Power = " + Power
	 + ", PwrR = " + PwrR
	 + ", PwrI = " + PwrI
	 + ", LossP = " + LossP
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
	 + ", IniBusR = " + IniBusR
	 + ", IniBusI = " + IniBusI
	 + ", IniPwrR = " + IniPwrR
	 + ", IniPwrI = " + IniPwrI
	 + ", ACBusRPtr = " + ACBusRPtr
	 + ", ACBusIPtr = " + ACBusIPtr
	 + ", ACIslandR = " + ACIslandR
	 + ", ACIslandI = " + ACIslandI
	 + ", SerialNo = " + SerialNo
	 + ", RParamType = " + RParamType
	 + ", Outage = " + Outage+"]";
  }
    
}
    
