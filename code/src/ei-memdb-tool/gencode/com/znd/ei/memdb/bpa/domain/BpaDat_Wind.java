package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*变压器绕组表(Wind)	*
***********************/
public class BpaDat_Wind  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //所有者
  private String Wind_Owner;
  
  //母线名称1
  private String Wind_BusI;
  
  //基准电压1(kV)
  private Double Wind_kVI;
  
  //区域联络线测点标志
  private Integer Wind_Meter;
  
  //母线名称2
  private String Wind_BusJ;
  
  //基准电压2(kV)
  private Double Wind_kVJ;
  
  //并联线路的回路标志
  private Integer Wind_Loop;
  
  //分段串连而成的线路的段号
  private Integer Wind_Section;
  
  //变压器额定容量(MVA)
  private Double Wind_MVA;
  
  //并联变压器数目
  private Integer Wind_LoopNum;
  
  //由铜损引起的等效电阻(pu)
  private Double Wind_R;
  
  //漏抗(pu)
  private Double Wind_X;
  
  //由铁损引起的等效电导(pu)
  private Double Wind_G;
  
  //激磁导纳(pu)
  private Double Wind_B;
  
  //母线1的固定分接头/移相器的固定移相角(度)
  private Double Wind_TPI;
  
  //母线2的固定分接头
  private Double Wind_TPJ;
  
  //变压器BUS1侧有功(MW)
  private Double Wind_Pi;
  
  //变压器BUS1侧无功(MVar)
  private Double Wind_Qi;
  
  //变压器BUS2侧有功(MW)
  private Double Wind_Pz;
  
  //变压器BUS2侧无功(MVar)
  private Double Wind_Qz;
  
  //变压器有功损耗(MW)
  private Double Wind_LossP;
  
  //变压器无功损耗(MVar)
  private Double Wind_LossQ;
  
  //变压器BUS1侧故障电流(A)
  private Double Wind_SccAI;
  
  //变压器BUS1侧故障电流(A)
  private Double Wind_SccAZ;
  
  //变压器故障率(次/年)
  private Double vd_Rerr;
  
  //单相接地频率(次/年)
  private Double vd_RScc1;
  
  //相间短路频率(次/年)
  private Double vd_RScc2;
  
  //三相短路频率(次/年)
  private Double vd_RScc3;
  
  //两相接地频率(次/年)
  private Double vd_RScc4;
  
  //变压器名称
  private String KeyName;
  
  //Ini母线名称1
  private String IniBusI;
  
  //Ini基准电压1(kV)
  private Double InikVI;
  
  //Ini母线名称2
  private String IniBusJ;
  
  //Ini基准电压2(kV)
  private Double InikVJ;
  
  //Ini并联线路的回路标志
  private Integer IniLoop;
  
  //变压器I母线索引
  private Integer iRBus;
  
  //变压器Z母线索引
  private Integer zRBus;
  
  //受控变压器(直流母线侧R=1-I,R=2-J)
  private Integer RCard;
  
  //变压器别名
  private String Alias;
  
  //RT母线1的固定分接头
  private Double RtTPI;
  
  //RT母线2的固定分接头
  private Double RtTPJ;
  
  //状态
  private Integer Status;
  
  //环网设备
  private Integer InRing;
  
  //所在辐射网
  private Integer Radiate;
  
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
    
  public String getCardKey()
  {
    return CardKey;
  }
    
  public void setCardKey(String CardKey)
  {
    this.CardKey = CardKey;
  }
    
  public String getWind_Owner()
  {
    return Wind_Owner;
  }
    
  public void setWind_Owner(String Wind_Owner)
  {
    this.Wind_Owner = Wind_Owner;
  }
    
  public String getWind_BusI()
  {
    return Wind_BusI;
  }
    
  public void setWind_BusI(String Wind_BusI)
  {
    this.Wind_BusI = Wind_BusI;
  }
    
  public Double getWind_kVI()
  {
    return Wind_kVI;
  }
    
  public void setWind_kVI(Double Wind_kVI)
  {
    this.Wind_kVI = Wind_kVI;
  }
    
  public Integer getWind_Meter()
  {
    return Wind_Meter;
  }
    
  public void setWind_Meter(Integer Wind_Meter)
  {
    this.Wind_Meter = Wind_Meter;
  }
    
  public String getWind_BusJ()
  {
    return Wind_BusJ;
  }
    
  public void setWind_BusJ(String Wind_BusJ)
  {
    this.Wind_BusJ = Wind_BusJ;
  }
    
  public Double getWind_kVJ()
  {
    return Wind_kVJ;
  }
    
  public void setWind_kVJ(Double Wind_kVJ)
  {
    this.Wind_kVJ = Wind_kVJ;
  }
    
  public Integer getWind_Loop()
  {
    return Wind_Loop;
  }
    
  public void setWind_Loop(Integer Wind_Loop)
  {
    this.Wind_Loop = Wind_Loop;
  }
    
  public Integer getWind_Section()
  {
    return Wind_Section;
  }
    
  public void setWind_Section(Integer Wind_Section)
  {
    this.Wind_Section = Wind_Section;
  }
    
  public Double getWind_MVA()
  {
    return Wind_MVA;
  }
    
  public void setWind_MVA(Double Wind_MVA)
  {
    this.Wind_MVA = Wind_MVA;
  }
    
  public Integer getWind_LoopNum()
  {
    return Wind_LoopNum;
  }
    
  public void setWind_LoopNum(Integer Wind_LoopNum)
  {
    this.Wind_LoopNum = Wind_LoopNum;
  }
    
  public Double getWind_R()
  {
    return Wind_R;
  }
    
  public void setWind_R(Double Wind_R)
  {
    this.Wind_R = Wind_R;
  }
    
  public Double getWind_X()
  {
    return Wind_X;
  }
    
  public void setWind_X(Double Wind_X)
  {
    this.Wind_X = Wind_X;
  }
    
  public Double getWind_G()
  {
    return Wind_G;
  }
    
  public void setWind_G(Double Wind_G)
  {
    this.Wind_G = Wind_G;
  }
    
  public Double getWind_B()
  {
    return Wind_B;
  }
    
  public void setWind_B(Double Wind_B)
  {
    this.Wind_B = Wind_B;
  }
    
  public Double getWind_TPI()
  {
    return Wind_TPI;
  }
    
  public void setWind_TPI(Double Wind_TPI)
  {
    this.Wind_TPI = Wind_TPI;
  }
    
  public Double getWind_TPJ()
  {
    return Wind_TPJ;
  }
    
  public void setWind_TPJ(Double Wind_TPJ)
  {
    this.Wind_TPJ = Wind_TPJ;
  }
    
  public Double getWind_Pi()
  {
    return Wind_Pi;
  }
    
  public void setWind_Pi(Double Wind_Pi)
  {
    this.Wind_Pi = Wind_Pi;
  }
    
  public Double getWind_Qi()
  {
    return Wind_Qi;
  }
    
  public void setWind_Qi(Double Wind_Qi)
  {
    this.Wind_Qi = Wind_Qi;
  }
    
  public Double getWind_Pz()
  {
    return Wind_Pz;
  }
    
  public void setWind_Pz(Double Wind_Pz)
  {
    this.Wind_Pz = Wind_Pz;
  }
    
  public Double getWind_Qz()
  {
    return Wind_Qz;
  }
    
  public void setWind_Qz(Double Wind_Qz)
  {
    this.Wind_Qz = Wind_Qz;
  }
    
  public Double getWind_LossP()
  {
    return Wind_LossP;
  }
    
  public void setWind_LossP(Double Wind_LossP)
  {
    this.Wind_LossP = Wind_LossP;
  }
    
  public Double getWind_LossQ()
  {
    return Wind_LossQ;
  }
    
  public void setWind_LossQ(Double Wind_LossQ)
  {
    this.Wind_LossQ = Wind_LossQ;
  }
    
  public Double getWind_SccAI()
  {
    return Wind_SccAI;
  }
    
  public void setWind_SccAI(Double Wind_SccAI)
  {
    this.Wind_SccAI = Wind_SccAI;
  }
    
  public Double getWind_SccAZ()
  {
    return Wind_SccAZ;
  }
    
  public void setWind_SccAZ(Double Wind_SccAZ)
  {
    this.Wind_SccAZ = Wind_SccAZ;
  }
    
  public Double getvd_Rerr()
  {
    return vd_Rerr;
  }
    
  public void setvd_Rerr(Double vd_Rerr)
  {
    this.vd_Rerr = vd_Rerr;
  }
    
  public Double getvd_RScc1()
  {
    return vd_RScc1;
  }
    
  public void setvd_RScc1(Double vd_RScc1)
  {
    this.vd_RScc1 = vd_RScc1;
  }
    
  public Double getvd_RScc2()
  {
    return vd_RScc2;
  }
    
  public void setvd_RScc2(Double vd_RScc2)
  {
    this.vd_RScc2 = vd_RScc2;
  }
    
  public Double getvd_RScc3()
  {
    return vd_RScc3;
  }
    
  public void setvd_RScc3(Double vd_RScc3)
  {
    this.vd_RScc3 = vd_RScc3;
  }
    
  public Double getvd_RScc4()
  {
    return vd_RScc4;
  }
    
  public void setvd_RScc4(Double vd_RScc4)
  {
    this.vd_RScc4 = vd_RScc4;
  }
    
  public String getKeyName()
  {
    return KeyName;
  }
    
  public void setKeyName(String KeyName)
  {
    this.KeyName = KeyName;
  }
    
  public String getIniBusI()
  {
    return IniBusI;
  }
    
  public void setIniBusI(String IniBusI)
  {
    this.IniBusI = IniBusI;
  }
    
  public Double getInikVI()
  {
    return InikVI;
  }
    
  public void setInikVI(Double InikVI)
  {
    this.InikVI = InikVI;
  }
    
  public String getIniBusJ()
  {
    return IniBusJ;
  }
    
  public void setIniBusJ(String IniBusJ)
  {
    this.IniBusJ = IniBusJ;
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
    
  public Integer getiRBus()
  {
    return iRBus;
  }
    
  public void setiRBus(Integer iRBus)
  {
    this.iRBus = iRBus;
  }
    
  public Integer getzRBus()
  {
    return zRBus;
  }
    
  public void setzRBus(Integer zRBus)
  {
    this.zRBus = zRBus;
  }
    
  public Integer getRCard()
  {
    return RCard;
  }
    
  public void setRCard(Integer RCard)
  {
    this.RCard = RCard;
  }
    
  public String getAlias()
  {
    return Alias;
  }
    
  public void setAlias(String Alias)
  {
    this.Alias = Alias;
  }
    
  public Double getRtTPI()
  {
    return RtTPI;
  }
    
  public void setRtTPI(Double RtTPI)
  {
    this.RtTPI = RtTPI;
  }
    
  public Double getRtTPJ()
  {
    return RtTPJ;
  }
    
  public void setRtTPJ(Double RtTPJ)
  {
    this.RtTPJ = RtTPJ;
  }
    
  public Integer getStatus()
  {
    return Status;
  }
    
  public void setStatus(Integer Status)
  {
    this.Status = Status;
  }
    
  public Integer getInRing()
  {
    return InRing;
  }
    
  public void setInRing(Integer InRing)
  {
    this.InRing = InRing;
  }
    
  public Integer getRadiate()
  {
    return Radiate;
  }
    
  public void setRadiate(Integer Radiate)
  {
    this.Radiate = Radiate;
  }
    
  public String toString()
  {
    return "BpaDat_Wind ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", Wind_Owner = " + Wind_Owner
	 + ", Wind_BusI = " + Wind_BusI
	 + ", Wind_kVI = " + Wind_kVI
	 + ", Wind_Meter = " + Wind_Meter
	 + ", Wind_BusJ = " + Wind_BusJ
	 + ", Wind_kVJ = " + Wind_kVJ
	 + ", Wind_Loop = " + Wind_Loop
	 + ", Wind_Section = " + Wind_Section
	 + ", Wind_MVA = " + Wind_MVA
	 + ", Wind_LoopNum = " + Wind_LoopNum
	 + ", Wind_R = " + Wind_R
	 + ", Wind_X = " + Wind_X
	 + ", Wind_G = " + Wind_G
	 + ", Wind_B = " + Wind_B
	 + ", Wind_TPI = " + Wind_TPI
	 + ", Wind_TPJ = " + Wind_TPJ
	 + ", Wind_Pi = " + Wind_Pi
	 + ", Wind_Qi = " + Wind_Qi
	 + ", Wind_Pz = " + Wind_Pz
	 + ", Wind_Qz = " + Wind_Qz
	 + ", Wind_LossP = " + Wind_LossP
	 + ", Wind_LossQ = " + Wind_LossQ
	 + ", Wind_SccAI = " + Wind_SccAI
	 + ", Wind_SccAZ = " + Wind_SccAZ
	 + ", vd_Rerr = " + vd_Rerr
	 + ", vd_RScc1 = " + vd_RScc1
	 + ", vd_RScc2 = " + vd_RScc2
	 + ", vd_RScc3 = " + vd_RScc3
	 + ", vd_RScc4 = " + vd_RScc4
	 + ", KeyName = " + KeyName
	 + ", IniBusI = " + IniBusI
	 + ", InikVI = " + InikVI
	 + ", IniBusJ = " + IniBusJ
	 + ", InikVJ = " + InikVJ
	 + ", IniLoop = " + IniLoop
	 + ", iRBus = " + iRBus
	 + ", zRBus = " + zRBus
	 + ", RCard = " + RCard
	 + ", Alias = " + Alias
	 + ", RtTPI = " + RtTPI
	 + ", RtTPJ = " + RtTPJ
	 + ", Status = " + Status
	 + ", InRing = " + InRing
	 + ", Radiate = " + Radiate+"]";
  }
    
}
    
