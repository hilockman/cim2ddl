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
  private String cardKey;
  
  //所有者
  private String wind_Owner;
  
  //母线名称1
  private String wind_BusI;
  
  //基准电压1(kV)
  private Double wind_kVI;
  
  //区域联络线测点标志
  private Integer wind_Meter;
  
  //母线名称2
  private String wind_BusJ;
  
  //基准电压2(kV)
  private Double wind_kVJ;
  
  //并联线路的回路标志
  private Integer wind_Loop;
  
  //分段串连而成的线路的段号
  private Integer wind_Section;
  
  //变压器额定容量(MVA)
  private Double wind_MVA;
  
  //并联变压器数目
  private Integer wind_LoopNum;
  
  //由铜损引起的等效电阻(pu)
  private Double wind_R;
  
  //漏抗(pu)
  private Double wind_X;
  
  //由铁损引起的等效电导(pu)
  private Double wind_G;
  
  //激磁导纳(pu)
  private Double wind_B;
  
  //母线1的固定分接头/移相器的固定移相角(度)
  private Double wind_TPI;
  
  //母线2的固定分接头
  private Double wind_TPJ;
  
  //变压器BUS1侧有功(MW)
  private Double wind_Pi;
  
  //变压器BUS1侧无功(MVar)
  private Double wind_Qi;
  
  //变压器BUS2侧有功(MW)
  private Double wind_Pz;
  
  //变压器BUS2侧无功(MVar)
  private Double wind_Qz;
  
  //变压器有功损耗(MW)
  private Double wind_LossP;
  
  //变压器无功损耗(MVar)
  private Double wind_LossQ;
  
  //变压器BUS1侧故障电流(A)
  private Double wind_SccAI;
  
  //变压器BUS1侧故障电流(A)
  private Double wind_SccAZ;
  
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
  private String keyName;
  
  //Ini母线名称1
  private String iniBusI;
  
  //Ini基准电压1(kV)
  private Double inikVI;
  
  //Ini母线名称2
  private String iniBusJ;
  
  //Ini基准电压2(kV)
  private Double inikVJ;
  
  //Ini并联线路的回路标志
  private Integer iniLoop;
  
  //变压器I母线索引
  private Integer iRBus;
  
  //变压器Z母线索引
  private Integer zRBus;
  
  //受控变压器(直流母线侧R=1-I,R=2-J)
  private Integer rCard;
  
  //变压器别名
  private String alias;
  
  //RT母线1的固定分接头
  private Double rtTPI;
  
  //RT母线2的固定分接头
  private Double rtTPJ;
  
  //状态
  private Integer status;
  
  //环网设备
  private Integer inRing;
  
  //所在辐射网
  private Integer radiate;
  
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
    return cardKey;
  }
    
  public void setCardKey(String cardKey)
  {
    this.cardKey = cardKey;
  }
    
  public String getWind_Owner()
  {
    return wind_Owner;
  }
    
  public void setWind_Owner(String wind_Owner)
  {
    this.wind_Owner = wind_Owner;
  }
    
  public String getWind_BusI()
  {
    return wind_BusI;
  }
    
  public void setWind_BusI(String wind_BusI)
  {
    this.wind_BusI = wind_BusI;
  }
    
  public Double getWind_kVI()
  {
    return wind_kVI;
  }
    
  public void setWind_kVI(Double wind_kVI)
  {
    this.wind_kVI = wind_kVI;
  }
    
  public Integer getWind_Meter()
  {
    return wind_Meter;
  }
    
  public void setWind_Meter(Integer wind_Meter)
  {
    this.wind_Meter = wind_Meter;
  }
    
  public String getWind_BusJ()
  {
    return wind_BusJ;
  }
    
  public void setWind_BusJ(String wind_BusJ)
  {
    this.wind_BusJ = wind_BusJ;
  }
    
  public Double getWind_kVJ()
  {
    return wind_kVJ;
  }
    
  public void setWind_kVJ(Double wind_kVJ)
  {
    this.wind_kVJ = wind_kVJ;
  }
    
  public Integer getWind_Loop()
  {
    return wind_Loop;
  }
    
  public void setWind_Loop(Integer wind_Loop)
  {
    this.wind_Loop = wind_Loop;
  }
    
  public Integer getWind_Section()
  {
    return wind_Section;
  }
    
  public void setWind_Section(Integer wind_Section)
  {
    this.wind_Section = wind_Section;
  }
    
  public Double getWind_MVA()
  {
    return wind_MVA;
  }
    
  public void setWind_MVA(Double wind_MVA)
  {
    this.wind_MVA = wind_MVA;
  }
    
  public Integer getWind_LoopNum()
  {
    return wind_LoopNum;
  }
    
  public void setWind_LoopNum(Integer wind_LoopNum)
  {
    this.wind_LoopNum = wind_LoopNum;
  }
    
  public Double getWind_R()
  {
    return wind_R;
  }
    
  public void setWind_R(Double wind_R)
  {
    this.wind_R = wind_R;
  }
    
  public Double getWind_X()
  {
    return wind_X;
  }
    
  public void setWind_X(Double wind_X)
  {
    this.wind_X = wind_X;
  }
    
  public Double getWind_G()
  {
    return wind_G;
  }
    
  public void setWind_G(Double wind_G)
  {
    this.wind_G = wind_G;
  }
    
  public Double getWind_B()
  {
    return wind_B;
  }
    
  public void setWind_B(Double wind_B)
  {
    this.wind_B = wind_B;
  }
    
  public Double getWind_TPI()
  {
    return wind_TPI;
  }
    
  public void setWind_TPI(Double wind_TPI)
  {
    this.wind_TPI = wind_TPI;
  }
    
  public Double getWind_TPJ()
  {
    return wind_TPJ;
  }
    
  public void setWind_TPJ(Double wind_TPJ)
  {
    this.wind_TPJ = wind_TPJ;
  }
    
  public Double getWind_Pi()
  {
    return wind_Pi;
  }
    
  public void setWind_Pi(Double wind_Pi)
  {
    this.wind_Pi = wind_Pi;
  }
    
  public Double getWind_Qi()
  {
    return wind_Qi;
  }
    
  public void setWind_Qi(Double wind_Qi)
  {
    this.wind_Qi = wind_Qi;
  }
    
  public Double getWind_Pz()
  {
    return wind_Pz;
  }
    
  public void setWind_Pz(Double wind_Pz)
  {
    this.wind_Pz = wind_Pz;
  }
    
  public Double getWind_Qz()
  {
    return wind_Qz;
  }
    
  public void setWind_Qz(Double wind_Qz)
  {
    this.wind_Qz = wind_Qz;
  }
    
  public Double getWind_LossP()
  {
    return wind_LossP;
  }
    
  public void setWind_LossP(Double wind_LossP)
  {
    this.wind_LossP = wind_LossP;
  }
    
  public Double getWind_LossQ()
  {
    return wind_LossQ;
  }
    
  public void setWind_LossQ(Double wind_LossQ)
  {
    this.wind_LossQ = wind_LossQ;
  }
    
  public Double getWind_SccAI()
  {
    return wind_SccAI;
  }
    
  public void setWind_SccAI(Double wind_SccAI)
  {
    this.wind_SccAI = wind_SccAI;
  }
    
  public Double getWind_SccAZ()
  {
    return wind_SccAZ;
  }
    
  public void setWind_SccAZ(Double wind_SccAZ)
  {
    this.wind_SccAZ = wind_SccAZ;
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
    return keyName;
  }
    
  public void setKeyName(String keyName)
  {
    this.keyName = keyName;
  }
    
  public String getIniBusI()
  {
    return iniBusI;
  }
    
  public void setIniBusI(String iniBusI)
  {
    this.iniBusI = iniBusI;
  }
    
  public Double getInikVI()
  {
    return inikVI;
  }
    
  public void setInikVI(Double inikVI)
  {
    this.inikVI = inikVI;
  }
    
  public String getIniBusJ()
  {
    return iniBusJ;
  }
    
  public void setIniBusJ(String iniBusJ)
  {
    this.iniBusJ = iniBusJ;
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
    return rCard;
  }
    
  public void setRCard(Integer rCard)
  {
    this.rCard = rCard;
  }
    
  public String getAlias()
  {
    return alias;
  }
    
  public void setAlias(String alias)
  {
    this.alias = alias;
  }
    
  public Double getRtTPI()
  {
    return rtTPI;
  }
    
  public void setRtTPI(Double rtTPI)
  {
    this.rtTPI = rtTPI;
  }
    
  public Double getRtTPJ()
  {
    return rtTPJ;
  }
    
  public void setRtTPJ(Double rtTPJ)
  {
    this.rtTPJ = rtTPJ;
  }
    
  public Integer getStatus()
  {
    return status;
  }
    
  public void setStatus(Integer status)
  {
    this.status = status;
  }
    
  public Integer getInRing()
  {
    return inRing;
  }
    
  public void setInRing(Integer inRing)
  {
    this.inRing = inRing;
  }
    
  public Integer getRadiate()
  {
    return radiate;
  }
    
  public void setRadiate(Integer radiate)
  {
    this.radiate = radiate;
  }
    
  public String toString()
  {
    return "BpaDat_Wind ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", wind_Owner = " + wind_Owner
	 + ", wind_BusI = " + wind_BusI
	 + ", wind_kVI = " + wind_kVI
	 + ", wind_Meter = " + wind_Meter
	 + ", wind_BusJ = " + wind_BusJ
	 + ", wind_kVJ = " + wind_kVJ
	 + ", wind_Loop = " + wind_Loop
	 + ", wind_Section = " + wind_Section
	 + ", wind_MVA = " + wind_MVA
	 + ", wind_LoopNum = " + wind_LoopNum
	 + ", wind_R = " + wind_R
	 + ", wind_X = " + wind_X
	 + ", wind_G = " + wind_G
	 + ", wind_B = " + wind_B
	 + ", wind_TPI = " + wind_TPI
	 + ", wind_TPJ = " + wind_TPJ
	 + ", wind_Pi = " + wind_Pi
	 + ", wind_Qi = " + wind_Qi
	 + ", wind_Pz = " + wind_Pz
	 + ", wind_Qz = " + wind_Qz
	 + ", wind_LossP = " + wind_LossP
	 + ", wind_LossQ = " + wind_LossQ
	 + ", wind_SccAI = " + wind_SccAI
	 + ", wind_SccAZ = " + wind_SccAZ
	 + ", vd_Rerr = " + vd_Rerr
	 + ", vd_RScc1 = " + vd_RScc1
	 + ", vd_RScc2 = " + vd_RScc2
	 + ", vd_RScc3 = " + vd_RScc3
	 + ", vd_RScc4 = " + vd_RScc4
	 + ", keyName = " + keyName
	 + ", iniBusI = " + iniBusI
	 + ", inikVI = " + inikVI
	 + ", iniBusJ = " + iniBusJ
	 + ", inikVJ = " + inikVJ
	 + ", iniLoop = " + iniLoop
	 + ", iRBus = " + iRBus
	 + ", zRBus = " + zRBus
	 + ", rCard = " + rCard
	 + ", alias = " + alias
	 + ", rtTPI = " + rtTPI
	 + ", rtTPJ = " + rtTPJ
	 + ", status = " + status
	 + ", inRing = " + inRing
	 + ", radiate = " + radiate+"]";
  }
    
}
    
