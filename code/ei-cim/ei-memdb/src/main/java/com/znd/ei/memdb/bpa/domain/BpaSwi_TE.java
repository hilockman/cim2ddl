package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*单再热器汽轮机模型表(TE)	*
***********************/
@Entity
public class BpaSwi_TE
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
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
  private Double tE_TCH;
  
  //高压缸功率比例
  private Double tE_FHP;
  
  //再热器时间常数
  private Double tE_TRH;
  
  //中压缸功率比例
  private Double tE_FIP;
  
  //交叉管时间常数
  private Double tE_TCO;
  
  //低压缸功率比例
  private Double tE_FLP;
  
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
    
  public Double getTE_TCH() 
  {
    return tE_TCH;
  }
    
  public void setTE_TCH(Double tE_TCH)
  {
    this.tE_TCH = tE_TCH;
  }
    
  public Double getTE_FHP() 
  {
    return tE_FHP;
  }
    
  public void setTE_FHP(Double tE_FHP)
  {
    this.tE_FHP = tE_FHP;
  }
    
  public Double getTE_TRH() 
  {
    return tE_TRH;
  }
    
  public void setTE_TRH(Double tE_TRH)
  {
    this.tE_TRH = tE_TRH;
  }
    
  public Double getTE_FIP() 
  {
    return tE_FIP;
  }
    
  public void setTE_FIP(Double tE_FIP)
  {
    this.tE_FIP = tE_FIP;
  }
    
  public Double getTE_TCO() 
  {
    return tE_TCO;
  }
    
  public void setTE_TCO(Double tE_TCO)
  {
    this.tE_TCO = tE_TCO;
  }
    
  public Double getTE_FLP() 
  {
    return tE_FLP;
  }
    
  public void setTE_FLP(Double tE_FLP)
  {
    this.tE_FLP = tE_FLP;
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
    
}
    
