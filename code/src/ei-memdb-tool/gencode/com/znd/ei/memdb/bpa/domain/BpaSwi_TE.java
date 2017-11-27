package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*单再热器汽轮机模型表(TE)	*
***********************/
public class BpaSwi_TE  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //发电机名称
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //蒸汽容积时间常数(秒)
  private Double TE_TCH;
  
  //高压缸功率比例
  private Double TE_FHP;
  
  //再热器时间常数
  private Double TE_TRH;
  
  //中压缸功率比例
  private Double TE_FIP;
  
  //交叉管时间常数
  private Double TE_TCO;
  
  //低压缸功率比例
  private Double TE_FLP;
  
  //数据库主键
  private String KeyName;
  
  //发电机母线索引
  private Integer BusPtr;
  
  //新增记录标记
  private Integer AppendTag;
  
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
    
  public Double getTE_TCH()
  {
    return TE_TCH;
  }
    
  public void setTE_TCH(Double TE_TCH)
  {
    this.TE_TCH = TE_TCH;
  }
    
  public Double getTE_FHP()
  {
    return TE_FHP;
  }
    
  public void setTE_FHP(Double TE_FHP)
  {
    this.TE_FHP = TE_FHP;
  }
    
  public Double getTE_TRH()
  {
    return TE_TRH;
  }
    
  public void setTE_TRH(Double TE_TRH)
  {
    this.TE_TRH = TE_TRH;
  }
    
  public Double getTE_FIP()
  {
    return TE_FIP;
  }
    
  public void setTE_FIP(Double TE_FIP)
  {
    this.TE_FIP = TE_FIP;
  }
    
  public Double getTE_TCO()
  {
    return TE_TCO;
  }
    
  public void setTE_TCO(Double TE_TCO)
  {
    this.TE_TCO = TE_TCO;
  }
    
  public Double getTE_FLP()
  {
    return TE_FLP;
  }
    
  public void setTE_FLP(Double TE_FLP)
  {
    this.TE_FLP = TE_FLP;
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
    
  public Integer getAppendTag()
  {
    return AppendTag;
  }
    
  public void setAppendTag(Integer AppendTag)
  {
    this.AppendTag = AppendTag;
  }
    
  public String toString()
  {
    return "BpaSwi_TE ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", TE_TCH = " + TE_TCH
	 + ", TE_FHP = " + TE_FHP
	 + ", TE_TRH = " + TE_TRH
	 + ", TE_FIP = " + TE_FIP
	 + ", TE_TCO = " + TE_TCO
	 + ", TE_FLP = " + TE_FLP
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
