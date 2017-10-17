package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*直流母线表(DCBus)	*
***********************/
@Entity
public class BpaDat_DCBus
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //所有者
  private String dCBus_Owner;
  
  //Converter母线名称
  private String dCBus_Name;
  
  //Converter基准电压(kV)
  private Double dCBus_kV;
  
  //Zone,分区名
  private String dCBus_Zone;
  
  //整流线路的桥数
  private Integer dCBus_BRDGS;
  
  //平波电抗器电感(毫亨)
  private Double dCBus_SMTHGREACTOR;
  
  //作为整流器运行的最小触发角(度)
  private Double dCBus_ROPERMIN;
  
  //作为逆变器运行的最大触发角(度)
  private Double dCBus_IOPERSTOP;
  
  //每个桥阀的电压降(伏)
  private Double dCBus_DROP;
  
  //桥电流额定值(安培)
  private Double dCBus_BRDGRATE;
  
  //换流变压器一次侧母线名称
  private String dCBus_ACName;
  
  //换流变压器一次侧基准电压(kV)
  private Double dCBus_ACkV;
  
  //直流母线电压(kV)
  private Double dCBus_V;
  
  //直流母线功角(度)
  private Double dCBus_D;
  
  //直流输电有功(MW)
  private Double dCBus_P;
  
  //直流输电电流(A)
  private Double dCBus_I;
  
  //直流输电有功损耗(MW)
  private Double dCBus_LossP;
  
  //直流输电无功损耗(MVar)
  private Double dCBus_LossQ;
  
  //交流侧母线电压(kV)
  private Double dCBus_ACV;
  
  //触发/关断角(度)
  private Double dCBus_Angle;
  
  //换流变压器一次侧母线索引
  private Integer aCBus;
  
  //交流岛
  private Integer aCIsland;
  
  //母线所属BPA厂站
  private String sub;
  
  //直流母线别名
  private String alias;
  
  //状态
  private Integer status;
  
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
    
  public String getDCBus_Owner() 
  {
    return dCBus_Owner;
  }
    
  public void setDCBus_Owner(String dCBus_Owner)
  {
    this.dCBus_Owner = dCBus_Owner;
  }
    
  public String getDCBus_Name() 
  {
    return dCBus_Name;
  }
    
  public void setDCBus_Name(String dCBus_Name)
  {
    this.dCBus_Name = dCBus_Name;
  }
    
  public Double getDCBus_kV() 
  {
    return dCBus_kV;
  }
    
  public void setDCBus_kV(Double dCBus_kV)
  {
    this.dCBus_kV = dCBus_kV;
  }
    
  public String getDCBus_Zone() 
  {
    return dCBus_Zone;
  }
    
  public void setDCBus_Zone(String dCBus_Zone)
  {
    this.dCBus_Zone = dCBus_Zone;
  }
    
  public Integer getDCBus_BRDGS() 
  {
    return dCBus_BRDGS;
  }
    
  public void setDCBus_BRDGS(Integer dCBus_BRDGS)
  {
    this.dCBus_BRDGS = dCBus_BRDGS;
  }
    
  public Double getDCBus_SMTHGREACTOR() 
  {
    return dCBus_SMTHGREACTOR;
  }
    
  public void setDCBus_SMTHGREACTOR(Double dCBus_SMTHGREACTOR)
  {
    this.dCBus_SMTHGREACTOR = dCBus_SMTHGREACTOR;
  }
    
  public Double getDCBus_ROPERMIN() 
  {
    return dCBus_ROPERMIN;
  }
    
  public void setDCBus_ROPERMIN(Double dCBus_ROPERMIN)
  {
    this.dCBus_ROPERMIN = dCBus_ROPERMIN;
  }
    
  public Double getDCBus_IOPERSTOP() 
  {
    return dCBus_IOPERSTOP;
  }
    
  public void setDCBus_IOPERSTOP(Double dCBus_IOPERSTOP)
  {
    this.dCBus_IOPERSTOP = dCBus_IOPERSTOP;
  }
    
  public Double getDCBus_DROP() 
  {
    return dCBus_DROP;
  }
    
  public void setDCBus_DROP(Double dCBus_DROP)
  {
    this.dCBus_DROP = dCBus_DROP;
  }
    
  public Double getDCBus_BRDGRATE() 
  {
    return dCBus_BRDGRATE;
  }
    
  public void setDCBus_BRDGRATE(Double dCBus_BRDGRATE)
  {
    this.dCBus_BRDGRATE = dCBus_BRDGRATE;
  }
    
  public String getDCBus_ACName() 
  {
    return dCBus_ACName;
  }
    
  public void setDCBus_ACName(String dCBus_ACName)
  {
    this.dCBus_ACName = dCBus_ACName;
  }
    
  public Double getDCBus_ACkV() 
  {
    return dCBus_ACkV;
  }
    
  public void setDCBus_ACkV(Double dCBus_ACkV)
  {
    this.dCBus_ACkV = dCBus_ACkV;
  }
    
  public Double getDCBus_V() 
  {
    return dCBus_V;
  }
    
  public void setDCBus_V(Double dCBus_V)
  {
    this.dCBus_V = dCBus_V;
  }
    
  public Double getDCBus_D() 
  {
    return dCBus_D;
  }
    
  public void setDCBus_D(Double dCBus_D)
  {
    this.dCBus_D = dCBus_D;
  }
    
  public Double getDCBus_P() 
  {
    return dCBus_P;
  }
    
  public void setDCBus_P(Double dCBus_P)
  {
    this.dCBus_P = dCBus_P;
  }
    
  public Double getDCBus_I() 
  {
    return dCBus_I;
  }
    
  public void setDCBus_I(Double dCBus_I)
  {
    this.dCBus_I = dCBus_I;
  }
    
  public Double getDCBus_LossP() 
  {
    return dCBus_LossP;
  }
    
  public void setDCBus_LossP(Double dCBus_LossP)
  {
    this.dCBus_LossP = dCBus_LossP;
  }
    
  public Double getDCBus_LossQ() 
  {
    return dCBus_LossQ;
  }
    
  public void setDCBus_LossQ(Double dCBus_LossQ)
  {
    this.dCBus_LossQ = dCBus_LossQ;
  }
    
  public Double getDCBus_ACV() 
  {
    return dCBus_ACV;
  }
    
  public void setDCBus_ACV(Double dCBus_ACV)
  {
    this.dCBus_ACV = dCBus_ACV;
  }
    
  public Double getDCBus_Angle() 
  {
    return dCBus_Angle;
  }
    
  public void setDCBus_Angle(Double dCBus_Angle)
  {
    this.dCBus_Angle = dCBus_Angle;
  }
    
  public Integer getACBus() 
  {
    return aCBus;
  }
    
  public void setACBus(Integer aCBus)
  {
    this.aCBus = aCBus;
  }
    
  public Integer getACIsland() 
  {
    return aCIsland;
  }
    
  public void setACIsland(Integer aCIsland)
  {
    this.aCIsland = aCIsland;
  }
    
  public String getSub() 
  {
    return sub;
  }
    
  public void setSub(String sub)
  {
    this.sub = sub;
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
    
}
    
