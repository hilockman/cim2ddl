package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*直流母线表(DCBus)	*
***********************/
public class BpaDat_DCBus  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //所有者
  private String DCBus_Owner;
  
  //Converter母线名称
  private String DCBus_Name;
  
  //Converter基准电压(kV)
  private Double DCBus_kV;
  
  //Zone,分区名
  private String DCBus_Zone;
  
  //整流线路的桥数
  private Integer DCBus_BRDGS;
  
  //平波电抗器电感(毫亨)
  private Double DCBus_SMTHGREACTOR;
  
  //作为整流器运行的最小触发角(度)
  private Double DCBus_ROPERMIN;
  
  //作为逆变器运行的最大触发角(度)
  private Double DCBus_IOPERSTOP;
  
  //每个桥阀的电压降(伏)
  private Double DCBus_DROP;
  
  //桥电流额定值(安培)
  private Double DCBus_BRDGRATE;
  
  //换流变压器一次侧母线名称
  private String DCBus_ACName;
  
  //换流变压器一次侧基准电压(kV)
  private Double DCBus_ACkV;
  
  //直流母线电压(kV)
  private Double DCBus_V;
  
  //直流母线功角(度)
  private Double DCBus_D;
  
  //直流输电有功(MW)
  private Double DCBus_P;
  
  //直流输电电流(A)
  private Double DCBus_I;
  
  //直流输电有功损耗(MW)
  private Double DCBus_LossP;
  
  //直流输电无功损耗(MVar)
  private Double DCBus_LossQ;
  
  //交流侧母线电压(kV)
  private Double DCBus_ACV;
  
  //触发/关断角(度)
  private Double DCBus_Angle;
  
  //换流变压器一次侧母线索引
  private Integer ACBus;
  
  //母线线路索引
  private Integer pRLine;
  
  //母线变压器索引
  private Integer pRTran;
  
  //交流岛
  private Integer ACIsland;
  
  //母线所属BPA厂站
  private String Sub;
  
  //直流母线别名
  private String Alias;
  
  //状态
  private Integer Status;
  
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
    
  public String getDCBus_Owner()
  {
    return DCBus_Owner;
  }
    
  public void setDCBus_Owner(String DCBus_Owner)
  {
    this.DCBus_Owner = DCBus_Owner;
  }
    
  public String getDCBus_Name()
  {
    return DCBus_Name;
  }
    
  public void setDCBus_Name(String DCBus_Name)
  {
    this.DCBus_Name = DCBus_Name;
  }
    
  public Double getDCBus_kV()
  {
    return DCBus_kV;
  }
    
  public void setDCBus_kV(Double DCBus_kV)
  {
    this.DCBus_kV = DCBus_kV;
  }
    
  public String getDCBus_Zone()
  {
    return DCBus_Zone;
  }
    
  public void setDCBus_Zone(String DCBus_Zone)
  {
    this.DCBus_Zone = DCBus_Zone;
  }
    
  public Integer getDCBus_BRDGS()
  {
    return DCBus_BRDGS;
  }
    
  public void setDCBus_BRDGS(Integer DCBus_BRDGS)
  {
    this.DCBus_BRDGS = DCBus_BRDGS;
  }
    
  public Double getDCBus_SMTHGREACTOR()
  {
    return DCBus_SMTHGREACTOR;
  }
    
  public void setDCBus_SMTHGREACTOR(Double DCBus_SMTHGREACTOR)
  {
    this.DCBus_SMTHGREACTOR = DCBus_SMTHGREACTOR;
  }
    
  public Double getDCBus_ROPERMIN()
  {
    return DCBus_ROPERMIN;
  }
    
  public void setDCBus_ROPERMIN(Double DCBus_ROPERMIN)
  {
    this.DCBus_ROPERMIN = DCBus_ROPERMIN;
  }
    
  public Double getDCBus_IOPERSTOP()
  {
    return DCBus_IOPERSTOP;
  }
    
  public void setDCBus_IOPERSTOP(Double DCBus_IOPERSTOP)
  {
    this.DCBus_IOPERSTOP = DCBus_IOPERSTOP;
  }
    
  public Double getDCBus_DROP()
  {
    return DCBus_DROP;
  }
    
  public void setDCBus_DROP(Double DCBus_DROP)
  {
    this.DCBus_DROP = DCBus_DROP;
  }
    
  public Double getDCBus_BRDGRATE()
  {
    return DCBus_BRDGRATE;
  }
    
  public void setDCBus_BRDGRATE(Double DCBus_BRDGRATE)
  {
    this.DCBus_BRDGRATE = DCBus_BRDGRATE;
  }
    
  public String getDCBus_ACName()
  {
    return DCBus_ACName;
  }
    
  public void setDCBus_ACName(String DCBus_ACName)
  {
    this.DCBus_ACName = DCBus_ACName;
  }
    
  public Double getDCBus_ACkV()
  {
    return DCBus_ACkV;
  }
    
  public void setDCBus_ACkV(Double DCBus_ACkV)
  {
    this.DCBus_ACkV = DCBus_ACkV;
  }
    
  public Double getDCBus_V()
  {
    return DCBus_V;
  }
    
  public void setDCBus_V(Double DCBus_V)
  {
    this.DCBus_V = DCBus_V;
  }
    
  public Double getDCBus_D()
  {
    return DCBus_D;
  }
    
  public void setDCBus_D(Double DCBus_D)
  {
    this.DCBus_D = DCBus_D;
  }
    
  public Double getDCBus_P()
  {
    return DCBus_P;
  }
    
  public void setDCBus_P(Double DCBus_P)
  {
    this.DCBus_P = DCBus_P;
  }
    
  public Double getDCBus_I()
  {
    return DCBus_I;
  }
    
  public void setDCBus_I(Double DCBus_I)
  {
    this.DCBus_I = DCBus_I;
  }
    
  public Double getDCBus_LossP()
  {
    return DCBus_LossP;
  }
    
  public void setDCBus_LossP(Double DCBus_LossP)
  {
    this.DCBus_LossP = DCBus_LossP;
  }
    
  public Double getDCBus_LossQ()
  {
    return DCBus_LossQ;
  }
    
  public void setDCBus_LossQ(Double DCBus_LossQ)
  {
    this.DCBus_LossQ = DCBus_LossQ;
  }
    
  public Double getDCBus_ACV()
  {
    return DCBus_ACV;
  }
    
  public void setDCBus_ACV(Double DCBus_ACV)
  {
    this.DCBus_ACV = DCBus_ACV;
  }
    
  public Double getDCBus_Angle()
  {
    return DCBus_Angle;
  }
    
  public void setDCBus_Angle(Double DCBus_Angle)
  {
    this.DCBus_Angle = DCBus_Angle;
  }
    
  public Integer getACBus()
  {
    return ACBus;
  }
    
  public void setACBus(Integer ACBus)
  {
    this.ACBus = ACBus;
  }
    
  public Integer getpRLine()
  {
    return pRLine;
  }
    
  public void setpRLine(Integer pRLine)
  {
    this.pRLine = pRLine;
  }
    
  public Integer getpRTran()
  {
    return pRTran;
  }
    
  public void setpRTran(Integer pRTran)
  {
    this.pRTran = pRTran;
  }
    
  public Integer getACIsland()
  {
    return ACIsland;
  }
    
  public void setACIsland(Integer ACIsland)
  {
    this.ACIsland = ACIsland;
  }
    
  public String getSub()
  {
    return Sub;
  }
    
  public void setSub(String Sub)
  {
    this.Sub = Sub;
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
    
  public String toString()
  {
    return "BpaDat_DCBus ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", DCBus_Owner = " + DCBus_Owner
	 + ", DCBus_Name = " + DCBus_Name
	 + ", DCBus_kV = " + DCBus_kV
	 + ", DCBus_Zone = " + DCBus_Zone
	 + ", DCBus_BRDGS = " + DCBus_BRDGS
	 + ", DCBus_SMTHGREACTOR = " + DCBus_SMTHGREACTOR
	 + ", DCBus_ROPERMIN = " + DCBus_ROPERMIN
	 + ", DCBus_IOPERSTOP = " + DCBus_IOPERSTOP
	 + ", DCBus_DROP = " + DCBus_DROP
	 + ", DCBus_BRDGRATE = " + DCBus_BRDGRATE
	 + ", DCBus_ACName = " + DCBus_ACName
	 + ", DCBus_ACkV = " + DCBus_ACkV
	 + ", DCBus_V = " + DCBus_V
	 + ", DCBus_D = " + DCBus_D
	 + ", DCBus_P = " + DCBus_P
	 + ", DCBus_I = " + DCBus_I
	 + ", DCBus_LossP = " + DCBus_LossP
	 + ", DCBus_LossQ = " + DCBus_LossQ
	 + ", DCBus_ACV = " + DCBus_ACV
	 + ", DCBus_Angle = " + DCBus_Angle
	 + ", ACBus = " + ACBus
	 + ", pRLine = " + pRLine
	 + ", pRTran = " + pRTran
	 + ", ACIsland = " + ACIsland
	 + ", Sub = " + Sub
	 + ", Alias = " + Alias
	 + ", Status = " + Status+"]";
  }
    
}
    
