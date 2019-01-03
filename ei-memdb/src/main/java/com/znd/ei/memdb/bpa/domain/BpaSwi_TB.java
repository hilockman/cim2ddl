package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*单再热器汽轮机模型表(TB)	*
***********************/
public class BpaSwi_TB  implements MemIndexable 
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
  private Double TB_TCH;
  
  //高压缸功率比例
  private Double TB_FHP;
  
  //再热器时间常数
  private Double TB_TRH;
  
  //中压缸功率比例
  private Double TB_FIP;
  
  //交叉管时间常数
  private Double TB_TCO;
  
  //低压缸功率比例或比例
  private Double TB_FLP;
  
  //高压缸功率自然过调系数
  private Double TB_Lambda;
  
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
    
  public Double getTB_TCH()
  {
    return TB_TCH;
  }
    
  public void setTB_TCH(Double TB_TCH)
  {
    this.TB_TCH = TB_TCH;
  }
    
  public Double getTB_FHP()
  {
    return TB_FHP;
  }
    
  public void setTB_FHP(Double TB_FHP)
  {
    this.TB_FHP = TB_FHP;
  }
    
  public Double getTB_TRH()
  {
    return TB_TRH;
  }
    
  public void setTB_TRH(Double TB_TRH)
  {
    this.TB_TRH = TB_TRH;
  }
    
  public Double getTB_FIP()
  {
    return TB_FIP;
  }
    
  public void setTB_FIP(Double TB_FIP)
  {
    this.TB_FIP = TB_FIP;
  }
    
  public Double getTB_TCO()
  {
    return TB_TCO;
  }
    
  public void setTB_TCO(Double TB_TCO)
  {
    this.TB_TCO = TB_TCO;
  }
    
  public Double getTB_FLP()
  {
    return TB_FLP;
  }
    
  public void setTB_FLP(Double TB_FLP)
  {
    this.TB_FLP = TB_FLP;
  }
    
  public Double getTB_Lambda()
  {
    return TB_Lambda;
  }
    
  public void setTB_Lambda(Double TB_Lambda)
  {
    this.TB_Lambda = TB_Lambda;
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
    return "BpaSwi_TB ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", TB_TCH = " + TB_TCH
	 + ", TB_FHP = " + TB_FHP
	 + ", TB_TRH = " + TB_TRH
	 + ", TB_FIP = " + TB_FIP
	 + ", TB_TCO = " + TB_TCO
	 + ", TB_FLP = " + TB_FLP
	 + ", TB_Lambda = " + TB_Lambda
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
