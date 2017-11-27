package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*双再热器汽轮机模型表(TC)	*
***********************/
public class BpaSwi_TC  implements MemIndexable 
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
  private Double TC_TCH;
  
  //超高压缸功率比例
  private Double TC_FVHP;
  
  //第一再热器时间常数
  private Double TC_TRH1;
  
  //高压缸功率比例
  private Double TC_FHP;
  
  //第二再热器时间常数
  private Double TC_TRH2;
  
  //中压缸功率比例或比例
  private Double TC_FIP;
  
  //交叉管时间常数
  private Double TC_TCO;
  
  //低压缸功率比例或比例
  private Double TC_FLP;
  
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
    
  public Double getTC_TCH()
  {
    return TC_TCH;
  }
    
  public void setTC_TCH(Double TC_TCH)
  {
    this.TC_TCH = TC_TCH;
  }
    
  public Double getTC_FVHP()
  {
    return TC_FVHP;
  }
    
  public void setTC_FVHP(Double TC_FVHP)
  {
    this.TC_FVHP = TC_FVHP;
  }
    
  public Double getTC_TRH1()
  {
    return TC_TRH1;
  }
    
  public void setTC_TRH1(Double TC_TRH1)
  {
    this.TC_TRH1 = TC_TRH1;
  }
    
  public Double getTC_FHP()
  {
    return TC_FHP;
  }
    
  public void setTC_FHP(Double TC_FHP)
  {
    this.TC_FHP = TC_FHP;
  }
    
  public Double getTC_TRH2()
  {
    return TC_TRH2;
  }
    
  public void setTC_TRH2(Double TC_TRH2)
  {
    this.TC_TRH2 = TC_TRH2;
  }
    
  public Double getTC_FIP()
  {
    return TC_FIP;
  }
    
  public void setTC_FIP(Double TC_FIP)
  {
    this.TC_FIP = TC_FIP;
  }
    
  public Double getTC_TCO()
  {
    return TC_TCO;
  }
    
  public void setTC_TCO(Double TC_TCO)
  {
    this.TC_TCO = TC_TCO;
  }
    
  public Double getTC_FLP()
  {
    return TC_FLP;
  }
    
  public void setTC_FLP(Double TC_FLP)
  {
    this.TC_FLP = TC_FLP;
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
    return "BpaSwi_TC ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", TC_TCH = " + TC_TCH
	 + ", TC_FVHP = " + TC_FVHP
	 + ", TC_TRH1 = " + TC_TRH1
	 + ", TC_FHP = " + TC_FHP
	 + ", TC_TRH2 = " + TC_TRH2
	 + ", TC_FIP = " + TC_FIP
	 + ", TC_TCO = " + TC_TCO
	 + ", TC_FLP = " + TC_FLP
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
