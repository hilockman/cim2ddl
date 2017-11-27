package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*GE风机模型表(WINDG_GE)	*
***********************/
public class BpaSwi_WGEGen  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //电机母线名
  private String ACBus_Name;
  
  //电机母线电压(kV)
  private Double ACBus_kV;
  
  //电机识别码
  private Integer Gen_ID;
  
  //风电机组类型代码
  private String GE_TYPE;
  
  //风电机组台数
  private Integer NG;
  
  //风电场无功控制节点名称
  private String NAME_CON;
  
  //风电场无功控制节点基准电压
  private Double BASE_CON;
  
  //有功占潮流总出力比例
  private Double PPER;
  
  //无功占潮流总出力比例
  private Double QPER;
  
  //初始风速(m/s)
  private Double V0;
  
  //=0考虑双质量块,否则单质量块
  private Integer NMASS_FLG;
  
  //=0不考虑QDROOP,否则考虑
  private Integer QDROOP_FLG;
  
  //=0风电场无功电压/恒功率因数控制模式
  private Integer WINDCON_FLG;
  
  //=0电气控制采用电压反馈
  private Integer EWVOL_FLG;
  
  //=0不采用APC有功控制功能,否则采用
  private Integer APCFLG;
  
  //=0APC功能中采用最大输出限制控制功能
  private Integer FFLG;
  
  //=0不采用WINDINERTIA功能
  private Integer INERTIA;
  
  //=0无功优先标志,否则有功优先(直驱)
  private Integer PQFLG;
  
  //数据库主键
  private String KeyName;
  
  //发电机母线索引
  private Integer BusPtr;
  
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
    
  public String getACBus_Name()
  {
    return ACBus_Name;
  }
    
  public void setACBus_Name(String ACBus_Name)
  {
    this.ACBus_Name = ACBus_Name;
  }
    
  public Double getACBus_kV()
  {
    return ACBus_kV;
  }
    
  public void setACBus_kV(Double ACBus_kV)
  {
    this.ACBus_kV = ACBus_kV;
  }
    
  public Integer getGen_ID()
  {
    return Gen_ID;
  }
    
  public void setGen_ID(Integer Gen_ID)
  {
    this.Gen_ID = Gen_ID;
  }
    
  public String getGE_TYPE()
  {
    return GE_TYPE;
  }
    
  public void setGE_TYPE(String GE_TYPE)
  {
    this.GE_TYPE = GE_TYPE;
  }
    
  public Integer getNG()
  {
    return NG;
  }
    
  public void setNG(Integer NG)
  {
    this.NG = NG;
  }
    
  public String getNAME_CON()
  {
    return NAME_CON;
  }
    
  public void setNAME_CON(String NAME_CON)
  {
    this.NAME_CON = NAME_CON;
  }
    
  public Double getBASE_CON()
  {
    return BASE_CON;
  }
    
  public void setBASE_CON(Double BASE_CON)
  {
    this.BASE_CON = BASE_CON;
  }
    
  public Double getPPER()
  {
    return PPER;
  }
    
  public void setPPER(Double PPER)
  {
    this.PPER = PPER;
  }
    
  public Double getQPER()
  {
    return QPER;
  }
    
  public void setQPER(Double QPER)
  {
    this.QPER = QPER;
  }
    
  public Double getV0()
  {
    return V0;
  }
    
  public void setV0(Double V0)
  {
    this.V0 = V0;
  }
    
  public Integer getNMASS_FLG()
  {
    return NMASS_FLG;
  }
    
  public void setNMASS_FLG(Integer NMASS_FLG)
  {
    this.NMASS_FLG = NMASS_FLG;
  }
    
  public Integer getQDROOP_FLG()
  {
    return QDROOP_FLG;
  }
    
  public void setQDROOP_FLG(Integer QDROOP_FLG)
  {
    this.QDROOP_FLG = QDROOP_FLG;
  }
    
  public Integer getWINDCON_FLG()
  {
    return WINDCON_FLG;
  }
    
  public void setWINDCON_FLG(Integer WINDCON_FLG)
  {
    this.WINDCON_FLG = WINDCON_FLG;
  }
    
  public Integer getEWVOL_FLG()
  {
    return EWVOL_FLG;
  }
    
  public void setEWVOL_FLG(Integer EWVOL_FLG)
  {
    this.EWVOL_FLG = EWVOL_FLG;
  }
    
  public Integer getAPCFLG()
  {
    return APCFLG;
  }
    
  public void setAPCFLG(Integer APCFLG)
  {
    this.APCFLG = APCFLG;
  }
    
  public Integer getFFLG()
  {
    return FFLG;
  }
    
  public void setFFLG(Integer FFLG)
  {
    this.FFLG = FFLG;
  }
    
  public Integer getINERTIA()
  {
    return INERTIA;
  }
    
  public void setINERTIA(Integer INERTIA)
  {
    this.INERTIA = INERTIA;
  }
    
  public Integer getPQFLG()
  {
    return PQFLG;
  }
    
  public void setPQFLG(Integer PQFLG)
  {
    this.PQFLG = PQFLG;
  }
    
  public String getKeyName()
  {
    return KeyName;
  }
    
  public void setKeyName(String KeyName)
  {
    this.KeyName = KeyName;
  }
    
  public Integer getBusPtr()
  {
    return BusPtr;
  }
    
  public void setBusPtr(Integer BusPtr)
  {
    this.BusPtr = BusPtr;
  }
    
  public String toString()
  {
    return "BpaSwi_WGEGen ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", GE_TYPE = " + GE_TYPE
	 + ", NG = " + NG
	 + ", NAME_CON = " + NAME_CON
	 + ", BASE_CON = " + BASE_CON
	 + ", PPER = " + PPER
	 + ", QPER = " + QPER
	 + ", V0 = " + V0
	 + ", NMASS_FLG = " + NMASS_FLG
	 + ", QDROOP_FLG = " + QDROOP_FLG
	 + ", WINDCON_FLG = " + WINDCON_FLG
	 + ", EWVOL_FLG = " + EWVOL_FLG
	 + ", APCFLG = " + APCFLG
	 + ", FFLG = " + FFLG
	 + ", INERTIA = " + INERTIA
	 + ", PQFLG = " + PQFLG
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
