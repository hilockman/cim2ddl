package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*交流线路表(ACLine)	*
***********************/
public class BpaDat_ACLine  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //所有者
  private String ACLine_Owner;
  
  //母线名称1
  private String ACLine_BusI;
  
  //基准电压1(kV)
  private Double ACLine_kVI;
  
  //区域联络线测点标志
  private Integer ACLine_Meter;
  
  //母线名称2
  private String ACLine_BusJ;
  
  //基准电压2(kV)
  private Double ACLine_kVJ;
  
  //并联线路的回路标志
  private Integer ACLine_Loop;
  
  //分段串连而成的线路的段号
  private Integer ACLine_Section;
  
  //线路额定电流(安培)
  private Double ACLine_AMP;
  
  //并联线路数目
  private Integer ACLine_LoopNum;
  
  //电阻(R,pu)
  private Double ACLine_R;
  
  //电抗(X,pu)
  private Double ACLine_X;
  
  //线路母线1端对地电导(G/2,pu)
  private Double ACLine_G1;
  
  //线路母线1端对地电纳(B/2,pu)
  private Double ACLine_B1;
  
  //线路母线2端对地电导(G/2,pu)
  private Double ACLine_G2;
  
  //线路母线2端对地电纳(B/2,pu)
  private Double ACLine_B2;
  
  //线路或段长度
  private Double ACLine_Miles;
  
  //线路故障率(次/年)
  private Double vd_Rerr;
  
  //单相接地频率(次/年)
  private Double vd_RScc1;
  
  //相间短路频率(次/年)
  private Double vd_RScc2;
  
  //三相短路频率(次/年)
  private Double vd_RScc3;
  
  //两相接地频率(次/年)
  private Double vd_RScc4;
  
  //线路BUS1侧有功(MW)
  private Double ACLine_Pi;
  
  //线路BUS1侧无功(MVar)
  private Double ACLine_Qi;
  
  //线路BUS2侧有功(MW)
  private Double ACLine_Pz;
  
  //线路BUS2侧无功(MVar)
  private Double ACLine_Qz;
  
  //线路有功损耗(MW)
  private Double ACLine_LossP;
  
  //线路无功损耗(MVar)
  private Double ACLine_LossQ;
  
  //线路故障电流(A)
  private Double ACLine_SccA;
  
  //线路中点单相接地暂降母线数
  private Integer ACLine_VDipBus1;
  
  //线路中点相间短路暂降母线数
  private Integer ACLine_VDipBus2;
  
  //线路中点三相短路暂降母线数
  private Integer ACLine_VDipBus3;
  
  //线路中点两相接地暂降母线数
  private Integer ACLine_VDipBus4;
  
  //线路名称
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
  
  //线路I母线索引
  private Integer iRBus;
  
  //线路Z母线索引
  private Integer zRBus;
  
  //交流线路别名
  private String Alias;
  
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
    
  public String getACLine_Owner()
  {
    return ACLine_Owner;
  }
    
  public void setACLine_Owner(String ACLine_Owner)
  {
    this.ACLine_Owner = ACLine_Owner;
  }
    
  public String getACLine_BusI()
  {
    return ACLine_BusI;
  }
    
  public void setACLine_BusI(String ACLine_BusI)
  {
    this.ACLine_BusI = ACLine_BusI;
  }
    
  public Double getACLine_kVI()
  {
    return ACLine_kVI;
  }
    
  public void setACLine_kVI(Double ACLine_kVI)
  {
    this.ACLine_kVI = ACLine_kVI;
  }
    
  public Integer getACLine_Meter()
  {
    return ACLine_Meter;
  }
    
  public void setACLine_Meter(Integer ACLine_Meter)
  {
    this.ACLine_Meter = ACLine_Meter;
  }
    
  public String getACLine_BusJ()
  {
    return ACLine_BusJ;
  }
    
  public void setACLine_BusJ(String ACLine_BusJ)
  {
    this.ACLine_BusJ = ACLine_BusJ;
  }
    
  public Double getACLine_kVJ()
  {
    return ACLine_kVJ;
  }
    
  public void setACLine_kVJ(Double ACLine_kVJ)
  {
    this.ACLine_kVJ = ACLine_kVJ;
  }
    
  public Integer getACLine_Loop()
  {
    return ACLine_Loop;
  }
    
  public void setACLine_Loop(Integer ACLine_Loop)
  {
    this.ACLine_Loop = ACLine_Loop;
  }
    
  public Integer getACLine_Section()
  {
    return ACLine_Section;
  }
    
  public void setACLine_Section(Integer ACLine_Section)
  {
    this.ACLine_Section = ACLine_Section;
  }
    
  public Double getACLine_AMP()
  {
    return ACLine_AMP;
  }
    
  public void setACLine_AMP(Double ACLine_AMP)
  {
    this.ACLine_AMP = ACLine_AMP;
  }
    
  public Integer getACLine_LoopNum()
  {
    return ACLine_LoopNum;
  }
    
  public void setACLine_LoopNum(Integer ACLine_LoopNum)
  {
    this.ACLine_LoopNum = ACLine_LoopNum;
  }
    
  public Double getACLine_R()
  {
    return ACLine_R;
  }
    
  public void setACLine_R(Double ACLine_R)
  {
    this.ACLine_R = ACLine_R;
  }
    
  public Double getACLine_X()
  {
    return ACLine_X;
  }
    
  public void setACLine_X(Double ACLine_X)
  {
    this.ACLine_X = ACLine_X;
  }
    
  public Double getACLine_G1()
  {
    return ACLine_G1;
  }
    
  public void setACLine_G1(Double ACLine_G1)
  {
    this.ACLine_G1 = ACLine_G1;
  }
    
  public Double getACLine_B1()
  {
    return ACLine_B1;
  }
    
  public void setACLine_B1(Double ACLine_B1)
  {
    this.ACLine_B1 = ACLine_B1;
  }
    
  public Double getACLine_G2()
  {
    return ACLine_G2;
  }
    
  public void setACLine_G2(Double ACLine_G2)
  {
    this.ACLine_G2 = ACLine_G2;
  }
    
  public Double getACLine_B2()
  {
    return ACLine_B2;
  }
    
  public void setACLine_B2(Double ACLine_B2)
  {
    this.ACLine_B2 = ACLine_B2;
  }
    
  public Double getACLine_Miles()
  {
    return ACLine_Miles;
  }
    
  public void setACLine_Miles(Double ACLine_Miles)
  {
    this.ACLine_Miles = ACLine_Miles;
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
    
  public Double getACLine_Pi()
  {
    return ACLine_Pi;
  }
    
  public void setACLine_Pi(Double ACLine_Pi)
  {
    this.ACLine_Pi = ACLine_Pi;
  }
    
  public Double getACLine_Qi()
  {
    return ACLine_Qi;
  }
    
  public void setACLine_Qi(Double ACLine_Qi)
  {
    this.ACLine_Qi = ACLine_Qi;
  }
    
  public Double getACLine_Pz()
  {
    return ACLine_Pz;
  }
    
  public void setACLine_Pz(Double ACLine_Pz)
  {
    this.ACLine_Pz = ACLine_Pz;
  }
    
  public Double getACLine_Qz()
  {
    return ACLine_Qz;
  }
    
  public void setACLine_Qz(Double ACLine_Qz)
  {
    this.ACLine_Qz = ACLine_Qz;
  }
    
  public Double getACLine_LossP()
  {
    return ACLine_LossP;
  }
    
  public void setACLine_LossP(Double ACLine_LossP)
  {
    this.ACLine_LossP = ACLine_LossP;
  }
    
  public Double getACLine_LossQ()
  {
    return ACLine_LossQ;
  }
    
  public void setACLine_LossQ(Double ACLine_LossQ)
  {
    this.ACLine_LossQ = ACLine_LossQ;
  }
    
  public Double getACLine_SccA()
  {
    return ACLine_SccA;
  }
    
  public void setACLine_SccA(Double ACLine_SccA)
  {
    this.ACLine_SccA = ACLine_SccA;
  }
    
  public Integer getACLine_VDipBus1()
  {
    return ACLine_VDipBus1;
  }
    
  public void setACLine_VDipBus1(Integer ACLine_VDipBus1)
  {
    this.ACLine_VDipBus1 = ACLine_VDipBus1;
  }
    
  public Integer getACLine_VDipBus2()
  {
    return ACLine_VDipBus2;
  }
    
  public void setACLine_VDipBus2(Integer ACLine_VDipBus2)
  {
    this.ACLine_VDipBus2 = ACLine_VDipBus2;
  }
    
  public Integer getACLine_VDipBus3()
  {
    return ACLine_VDipBus3;
  }
    
  public void setACLine_VDipBus3(Integer ACLine_VDipBus3)
  {
    this.ACLine_VDipBus3 = ACLine_VDipBus3;
  }
    
  public Integer getACLine_VDipBus4()
  {
    return ACLine_VDipBus4;
  }
    
  public void setACLine_VDipBus4(Integer ACLine_VDipBus4)
  {
    this.ACLine_VDipBus4 = ACLine_VDipBus4;
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
    
  public String getAlias()
  {
    return Alias;
  }
    
  public void setAlias(String Alias)
  {
    this.Alias = Alias;
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
    return "BpaDat_ACLine ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACLine_Owner = " + ACLine_Owner
	 + ", ACLine_BusI = " + ACLine_BusI
	 + ", ACLine_kVI = " + ACLine_kVI
	 + ", ACLine_Meter = " + ACLine_Meter
	 + ", ACLine_BusJ = " + ACLine_BusJ
	 + ", ACLine_kVJ = " + ACLine_kVJ
	 + ", ACLine_Loop = " + ACLine_Loop
	 + ", ACLine_Section = " + ACLine_Section
	 + ", ACLine_AMP = " + ACLine_AMP
	 + ", ACLine_LoopNum = " + ACLine_LoopNum
	 + ", ACLine_R = " + ACLine_R
	 + ", ACLine_X = " + ACLine_X
	 + ", ACLine_G1 = " + ACLine_G1
	 + ", ACLine_B1 = " + ACLine_B1
	 + ", ACLine_G2 = " + ACLine_G2
	 + ", ACLine_B2 = " + ACLine_B2
	 + ", ACLine_Miles = " + ACLine_Miles
	 + ", vd_Rerr = " + vd_Rerr
	 + ", vd_RScc1 = " + vd_RScc1
	 + ", vd_RScc2 = " + vd_RScc2
	 + ", vd_RScc3 = " + vd_RScc3
	 + ", vd_RScc4 = " + vd_RScc4
	 + ", ACLine_Pi = " + ACLine_Pi
	 + ", ACLine_Qi = " + ACLine_Qi
	 + ", ACLine_Pz = " + ACLine_Pz
	 + ", ACLine_Qz = " + ACLine_Qz
	 + ", ACLine_LossP = " + ACLine_LossP
	 + ", ACLine_LossQ = " + ACLine_LossQ
	 + ", ACLine_SccA = " + ACLine_SccA
	 + ", ACLine_VDipBus1 = " + ACLine_VDipBus1
	 + ", ACLine_VDipBus2 = " + ACLine_VDipBus2
	 + ", ACLine_VDipBus3 = " + ACLine_VDipBus3
	 + ", ACLine_VDipBus4 = " + ACLine_VDipBus4
	 + ", KeyName = " + KeyName
	 + ", IniBusI = " + IniBusI
	 + ", InikVI = " + InikVI
	 + ", IniBusJ = " + IniBusJ
	 + ", InikVJ = " + InikVJ
	 + ", IniLoop = " + IniLoop
	 + ", iRBus = " + iRBus
	 + ", zRBus = " + zRBus
	 + ", Alias = " + Alias
	 + ", Status = " + Status
	 + ", InRing = " + InRing
	 + ", Radiate = " + Radiate+"]";
  }
    
}
    
