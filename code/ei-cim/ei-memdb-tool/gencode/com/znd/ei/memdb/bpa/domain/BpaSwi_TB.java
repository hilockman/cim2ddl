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
  private String cardKey;
  
  //发电机名称
  private String aCBus_Name;
  
  //发电机基准电压(kV)
  private Double aCBus_kV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //蒸汽容积时间常数(秒)
  private Double tB_TCH;
  
  //高压缸功率比例
  private Double tB_FHP;
  
  //再热器时间常数
  private Double tB_TRH;
  
  //中压缸功率比例
  private Double tB_FIP;
  
  //交叉管时间常数
  private Double tB_TCO;
  
  //低压缸功率比例或比例
  private Double tB_FLP;
  
  //高压缸功率自然过调系数
  private Double tB_Lambda;
  
  //数据库主键
  private String keyName;
  
  //发电机母线索引
  private Integer busPtr;
  
  //新增记录标记
  private Integer appendTag;
  
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
    
  public String getACBus_Name()
  {
    return aCBus_Name;
  }
    
  public void setACBus_Name(String aCBus_Name)
  {
    this.aCBus_Name = aCBus_Name;
  }
    
  public Double getACBus_kV()
  {
    return aCBus_kV;
  }
    
  public void setACBus_kV(Double aCBus_kV)
  {
    this.aCBus_kV = aCBus_kV;
  }
    
  public Integer getGen_ID()
  {
    return gen_ID;
  }
    
  public void setGen_ID(Integer gen_ID)
  {
    this.gen_ID = gen_ID;
  }
    
  public Double getTB_TCH()
  {
    return tB_TCH;
  }
    
  public void setTB_TCH(Double tB_TCH)
  {
    this.tB_TCH = tB_TCH;
  }
    
  public Double getTB_FHP()
  {
    return tB_FHP;
  }
    
  public void setTB_FHP(Double tB_FHP)
  {
    this.tB_FHP = tB_FHP;
  }
    
  public Double getTB_TRH()
  {
    return tB_TRH;
  }
    
  public void setTB_TRH(Double tB_TRH)
  {
    this.tB_TRH = tB_TRH;
  }
    
  public Double getTB_FIP()
  {
    return tB_FIP;
  }
    
  public void setTB_FIP(Double tB_FIP)
  {
    this.tB_FIP = tB_FIP;
  }
    
  public Double getTB_TCO()
  {
    return tB_TCO;
  }
    
  public void setTB_TCO(Double tB_TCO)
  {
    this.tB_TCO = tB_TCO;
  }
    
  public Double getTB_FLP()
  {
    return tB_FLP;
  }
    
  public void setTB_FLP(Double tB_FLP)
  {
    this.tB_FLP = tB_FLP;
  }
    
  public Double getTB_Lambda()
  {
    return tB_Lambda;
  }
    
  public void setTB_Lambda(Double tB_Lambda)
  {
    this.tB_Lambda = tB_Lambda;
  }
    
  public String getKeyName()
  {
    return keyName;
  }
    
  public void setKeyName(String keyName)
  {
    this.keyName = keyName;
  }
    
  public Integer getBusPtr()
  {
    return busPtr;
  }
    
  public void setBusPtr(Integer busPtr)
  {
    this.busPtr = busPtr;
  }
    
  public Integer getAppendTag()
  {
    return appendTag;
  }
    
  public void setAppendTag(Integer appendTag)
  {
    this.appendTag = appendTag;
  }
    
  public String toString()
  {
    return "BpaSwi_TB ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", tB_TCH = " + tB_TCH
	 + ", tB_FHP = " + tB_FHP
	 + ", tB_TRH = " + tB_TRH
	 + ", tB_FIP = " + tB_FIP
	 + ", tB_TCO = " + tB_TCO
	 + ", tB_FLP = " + tB_FLP
	 + ", tB_Lambda = " + tB_Lambda
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
