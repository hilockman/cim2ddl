package com.znd.ei.memdb.bpa.domain;


/**********************
*交流线路表(ACLine)	*
***********************/
public class BpaDat_ACLine
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //所有者
  private String aCLine_Owner;
  
  //母线名称1
  private String aCLine_BusI;
  
  //基准电压1(kV)
  private Double aCLine_kVI;
  
  //区域联络线测点标志
  private Integer aCLine_Meter;
  
  //母线名称2
  private String aCLine_BusJ;
  
  //基准电压2(kV)
  private Double aCLine_kVJ;
  
  //并联线路的回路标志
  private Integer aCLine_Loop;
  
  //分段串连而成的线路的段号
  private Integer aCLine_Section;
  
  //线路额定电流(安培)
  private Double aCLine_AMP;
  
  //并联线路数目
  private Integer aCLine_LoopNum;
  
  //电阻(R,pu)
  private Double aCLine_R;
  
  //电抗(X,pu)
  private Double aCLine_X;
  
  //线路母线1端对地电导(G/2,pu)
  private Double aCLine_G1;
  
  //线路母线1端对地电纳(B/2,pu)
  private Double aCLine_B1;
  
  //线路母线2端对地电导(G/2,pu)
  private Double aCLine_G2;
  
  //线路母线2端对地电纳(B/2,pu)
  private Double aCLine_B2;
  
  //线路或段长度
  private Double aCLine_Miles;
  
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
  private Double aCLine_Pi;
  
  //线路BUS1侧无功(MVar)
  private Double aCLine_Qi;
  
  //线路BUS2侧有功(MW)
  private Double aCLine_Pz;
  
  //线路BUS2侧无功(MVar)
  private Double aCLine_Qz;
  
  //线路有功损耗(MW)
  private Double aCLine_LossP;
  
  //线路无功损耗(MVar)
  private Double aCLine_LossQ;
  
  //线路故障电流(A)
  private Double aCLine_SccA;
  
  //线路中点单相接地暂降母线数
  private Integer aCLine_VDipBus1;
  
  //线路中点相间短路暂降母线数
  private Integer aCLine_VDipBus2;
  
  //线路中点三相短路暂降母线数
  private Integer aCLine_VDipBus3;
  
  //线路中点两相接地暂降母线数
  private Integer aCLine_VDipBus4;
  
  //线路名称
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
  
  //线路I母线索引
  private Integer iRBus;
  
  //线路Z母线索引
  private Integer zRBus;
  
  //交流线路别名
  private String alias;
  
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
    
  public String getACLine_Owner()
  {
    return aCLine_Owner;
  }
    
  public void setACLine_Owner(String aCLine_Owner)
  {
    this.aCLine_Owner = aCLine_Owner;
  }
    
  public String getACLine_BusI()
  {
    return aCLine_BusI;
  }
    
  public void setACLine_BusI(String aCLine_BusI)
  {
    this.aCLine_BusI = aCLine_BusI;
  }
    
  public Double getACLine_kVI()
  {
    return aCLine_kVI;
  }
    
  public void setACLine_kVI(Double aCLine_kVI)
  {
    this.aCLine_kVI = aCLine_kVI;
  }
    
  public Integer getACLine_Meter()
  {
    return aCLine_Meter;
  }
    
  public void setACLine_Meter(Integer aCLine_Meter)
  {
    this.aCLine_Meter = aCLine_Meter;
  }
    
  public String getACLine_BusJ()
  {
    return aCLine_BusJ;
  }
    
  public void setACLine_BusJ(String aCLine_BusJ)
  {
    this.aCLine_BusJ = aCLine_BusJ;
  }
    
  public Double getACLine_kVJ()
  {
    return aCLine_kVJ;
  }
    
  public void setACLine_kVJ(Double aCLine_kVJ)
  {
    this.aCLine_kVJ = aCLine_kVJ;
  }
    
  public Integer getACLine_Loop()
  {
    return aCLine_Loop;
  }
    
  public void setACLine_Loop(Integer aCLine_Loop)
  {
    this.aCLine_Loop = aCLine_Loop;
  }
    
  public Integer getACLine_Section()
  {
    return aCLine_Section;
  }
    
  public void setACLine_Section(Integer aCLine_Section)
  {
    this.aCLine_Section = aCLine_Section;
  }
    
  public Double getACLine_AMP()
  {
    return aCLine_AMP;
  }
    
  public void setACLine_AMP(Double aCLine_AMP)
  {
    this.aCLine_AMP = aCLine_AMP;
  }
    
  public Integer getACLine_LoopNum()
  {
    return aCLine_LoopNum;
  }
    
  public void setACLine_LoopNum(Integer aCLine_LoopNum)
  {
    this.aCLine_LoopNum = aCLine_LoopNum;
  }
    
  public Double getACLine_R()
  {
    return aCLine_R;
  }
    
  public void setACLine_R(Double aCLine_R)
  {
    this.aCLine_R = aCLine_R;
  }
    
  public Double getACLine_X()
  {
    return aCLine_X;
  }
    
  public void setACLine_X(Double aCLine_X)
  {
    this.aCLine_X = aCLine_X;
  }
    
  public Double getACLine_G1()
  {
    return aCLine_G1;
  }
    
  public void setACLine_G1(Double aCLine_G1)
  {
    this.aCLine_G1 = aCLine_G1;
  }
    
  public Double getACLine_B1()
  {
    return aCLine_B1;
  }
    
  public void setACLine_B1(Double aCLine_B1)
  {
    this.aCLine_B1 = aCLine_B1;
  }
    
  public Double getACLine_G2()
  {
    return aCLine_G2;
  }
    
  public void setACLine_G2(Double aCLine_G2)
  {
    this.aCLine_G2 = aCLine_G2;
  }
    
  public Double getACLine_B2()
  {
    return aCLine_B2;
  }
    
  public void setACLine_B2(Double aCLine_B2)
  {
    this.aCLine_B2 = aCLine_B2;
  }
    
  public Double getACLine_Miles()
  {
    return aCLine_Miles;
  }
    
  public void setACLine_Miles(Double aCLine_Miles)
  {
    this.aCLine_Miles = aCLine_Miles;
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
    return aCLine_Pi;
  }
    
  public void setACLine_Pi(Double aCLine_Pi)
  {
    this.aCLine_Pi = aCLine_Pi;
  }
    
  public Double getACLine_Qi()
  {
    return aCLine_Qi;
  }
    
  public void setACLine_Qi(Double aCLine_Qi)
  {
    this.aCLine_Qi = aCLine_Qi;
  }
    
  public Double getACLine_Pz()
  {
    return aCLine_Pz;
  }
    
  public void setACLine_Pz(Double aCLine_Pz)
  {
    this.aCLine_Pz = aCLine_Pz;
  }
    
  public Double getACLine_Qz()
  {
    return aCLine_Qz;
  }
    
  public void setACLine_Qz(Double aCLine_Qz)
  {
    this.aCLine_Qz = aCLine_Qz;
  }
    
  public Double getACLine_LossP()
  {
    return aCLine_LossP;
  }
    
  public void setACLine_LossP(Double aCLine_LossP)
  {
    this.aCLine_LossP = aCLine_LossP;
  }
    
  public Double getACLine_LossQ()
  {
    return aCLine_LossQ;
  }
    
  public void setACLine_LossQ(Double aCLine_LossQ)
  {
    this.aCLine_LossQ = aCLine_LossQ;
  }
    
  public Double getACLine_SccA()
  {
    return aCLine_SccA;
  }
    
  public void setACLine_SccA(Double aCLine_SccA)
  {
    this.aCLine_SccA = aCLine_SccA;
  }
    
  public Integer getACLine_VDipBus1()
  {
    return aCLine_VDipBus1;
  }
    
  public void setACLine_VDipBus1(Integer aCLine_VDipBus1)
  {
    this.aCLine_VDipBus1 = aCLine_VDipBus1;
  }
    
  public Integer getACLine_VDipBus2()
  {
    return aCLine_VDipBus2;
  }
    
  public void setACLine_VDipBus2(Integer aCLine_VDipBus2)
  {
    this.aCLine_VDipBus2 = aCLine_VDipBus2;
  }
    
  public Integer getACLine_VDipBus3()
  {
    return aCLine_VDipBus3;
  }
    
  public void setACLine_VDipBus3(Integer aCLine_VDipBus3)
  {
    this.aCLine_VDipBus3 = aCLine_VDipBus3;
  }
    
  public Integer getACLine_VDipBus4()
  {
    return aCLine_VDipBus4;
  }
    
  public void setACLine_VDipBus4(Integer aCLine_VDipBus4)
  {
    this.aCLine_VDipBus4 = aCLine_VDipBus4;
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
    
  public String getAlias()
  {
    return alias;
  }
    
  public void setAlias(String alias)
  {
    this.alias = alias;
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
    return "BpaDat_ACLine ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"aCLine_Owner"=aCLine_Owner,
	"aCLine_BusI"=aCLine_BusI,
	"aCLine_kVI"=aCLine_kVI,
	"aCLine_Meter"=aCLine_Meter,
	"aCLine_BusJ"=aCLine_BusJ,
	"aCLine_kVJ"=aCLine_kVJ,
	"aCLine_Loop"=aCLine_Loop,
	"aCLine_Section"=aCLine_Section,
	"aCLine_AMP"=aCLine_AMP,
	"aCLine_LoopNum"=aCLine_LoopNum,
	"aCLine_R"=aCLine_R,
	"aCLine_X"=aCLine_X,
	"aCLine_G1"=aCLine_G1,
	"aCLine_B1"=aCLine_B1,
	"aCLine_G2"=aCLine_G2,
	"aCLine_B2"=aCLine_B2,
	"aCLine_Miles"=aCLine_Miles,
	"vd_Rerr"=vd_Rerr,
	"vd_RScc1"=vd_RScc1,
	"vd_RScc2"=vd_RScc2,
	"vd_RScc3"=vd_RScc3,
	"vd_RScc4"=vd_RScc4,
	"aCLine_Pi"=aCLine_Pi,
	"aCLine_Qi"=aCLine_Qi,
	"aCLine_Pz"=aCLine_Pz,
	"aCLine_Qz"=aCLine_Qz,
	"aCLine_LossP"=aCLine_LossP,
	"aCLine_LossQ"=aCLine_LossQ,
	"aCLine_SccA"=aCLine_SccA,
	"aCLine_VDipBus1"=aCLine_VDipBus1,
	"aCLine_VDipBus2"=aCLine_VDipBus2,
	"aCLine_VDipBus3"=aCLine_VDipBus3,
	"aCLine_VDipBus4"=aCLine_VDipBus4,
	"keyName"=keyName,
	"iniBusI"=iniBusI,
	"inikVI"=inikVI,
	"iniBusJ"=iniBusJ,
	"inikVJ"=inikVJ,
	"iniLoop"=iniLoop,
	"iRBus"=iRBus,
	"zRBus"=zRBus,
	"alias"=alias,
	"status"=status,
	"inRing"=inRing,
	"radiate"=radiate+"]"
  }
    
}
    
