package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*双再热器汽轮机模型表(TC)	*
***********************/
@Entity
public class BpaSwi_TC
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
  private Double tC_TCH;
  
  //超高压缸功率比例
  private Double tC_FVHP;
  
  //第一再热器时间常数
  private Double tC_TRH1;
  
  //高压缸功率比例
  private Double tC_FHP;
  
  //第二再热器时间常数
  private Double tC_TRH2;
  
  //中压缸功率比例或比例
  private Double tC_FIP;
  
  //交叉管时间常数
  private Double tC_TCO;
  
  //低压缸功率比例或比例
  private Double tC_FLP;
  
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
    
  public Double getTC_TCH() 
  {
    return tC_TCH;
  }
    
  public void setTC_TCH(Double tC_TCH)
  {
    this.tC_TCH = tC_TCH;
  }
    
  public Double getTC_FVHP() 
  {
    return tC_FVHP;
  }
    
  public void setTC_FVHP(Double tC_FVHP)
  {
    this.tC_FVHP = tC_FVHP;
  }
    
  public Double getTC_TRH1() 
  {
    return tC_TRH1;
  }
    
  public void setTC_TRH1(Double tC_TRH1)
  {
    this.tC_TRH1 = tC_TRH1;
  }
    
  public Double getTC_FHP() 
  {
    return tC_FHP;
  }
    
  public void setTC_FHP(Double tC_FHP)
  {
    this.tC_FHP = tC_FHP;
  }
    
  public Double getTC_TRH2() 
  {
    return tC_TRH2;
  }
    
  public void setTC_TRH2(Double tC_TRH2)
  {
    this.tC_TRH2 = tC_TRH2;
  }
    
  public Double getTC_FIP() 
  {
    return tC_FIP;
  }
    
  public void setTC_FIP(Double tC_FIP)
  {
    this.tC_FIP = tC_FIP;
  }
    
  public Double getTC_TCO() 
  {
    return tC_TCO;
  }
    
  public void setTC_TCO(Double tC_TCO)
  {
    this.tC_TCO = tC_TCO;
  }
    
  public Double getTC_FLP() 
  {
    return tC_FLP;
  }
    
  public void setTC_FLP(Double tC_FLP)
  {
    this.tC_FLP = tC_FLP;
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
    
