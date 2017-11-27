package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*单再热器汽轮机模型表(TD)	*
***********************/
public class BpaSwi_TD  implements MemIndexable 
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
  private Double TD_TCH;
  
  //高压缸功率比例
  private Double TD_FHP;
  
  //再热器时间常数
  private Double TD_TRH;
  
  //中压缸功率比例
  private Double TD_FIP;
  
  //交叉管时间常数
  private Double TD_TCO;
  
  //低压缸功率比例或比例的一半
  private Double TD_FLP_1;
  
  //低压缸功率比例或比例的一半
  private Double TD_FLP_2;
  
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
    
  public Double getTD_TCH()
  {
    return TD_TCH;
  }
    
  public void setTD_TCH(Double TD_TCH)
  {
    this.TD_TCH = TD_TCH;
  }
    
  public Double getTD_FHP()
  {
    return TD_FHP;
  }
    
  public void setTD_FHP(Double TD_FHP)
  {
    this.TD_FHP = TD_FHP;
  }
    
  public Double getTD_TRH()
  {
    return TD_TRH;
  }
    
  public void setTD_TRH(Double TD_TRH)
  {
    this.TD_TRH = TD_TRH;
  }
    
  public Double getTD_FIP()
  {
    return TD_FIP;
  }
    
  public void setTD_FIP(Double TD_FIP)
  {
    this.TD_FIP = TD_FIP;
  }
    
  public Double getTD_TCO()
  {
    return TD_TCO;
  }
    
  public void setTD_TCO(Double TD_TCO)
  {
    this.TD_TCO = TD_TCO;
  }
    
  public Double getTD_FLP_1()
  {
    return TD_FLP_1;
  }
    
  public void setTD_FLP_1(Double TD_FLP_1)
  {
    this.TD_FLP_1 = TD_FLP_1;
  }
    
  public Double getTD_FLP_2()
  {
    return TD_FLP_2;
  }
    
  public void setTD_FLP_2(Double TD_FLP_2)
  {
    this.TD_FLP_2 = TD_FLP_2;
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
    return "BpaSwi_TD ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", TD_TCH = " + TD_TCH
	 + ", TD_FHP = " + TD_FHP
	 + ", TD_TRH = " + TD_TRH
	 + ", TD_FIP = " + TD_FIP
	 + ", TD_TCO = " + TD_TCO
	 + ", TD_FLP_1 = " + TD_FLP_1
	 + ", TD_FLP_2 = " + TD_FLP_2
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
