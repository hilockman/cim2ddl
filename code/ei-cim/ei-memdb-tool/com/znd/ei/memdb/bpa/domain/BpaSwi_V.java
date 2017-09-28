package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*静止无功补偿器(SVC)	*
***********************/
@Entity
public class BpaSwi_V
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称
  private String aCBus_Name;
  
  //母线基准电压(kV)
  private Double aCBus_KV;
  
  //并联支路识别码
  private Integer iD;
  
  //滤波器时间常数(秒)
  private Double tS1;
  
  //最大电压偏差(pu)
  private Double vEMAX;
  
  //第一级超前时间常数(秒)
  private Double tS2;
  
  //第一级滞后时间常数(秒)
  private Double tS3;
  
  //超前识别码(不能为0)
  private Integer a;
  
  //滞后识别码(不能为0)
  private Integer b;
  
  //第二级超前时间常数(秒)
  private Double tS4;
  
  //第二级滞后时间常数(秒)
  private Double tS5;
  
  //连续控制增益
  private Double kSVS;
  
  //间断控制增益
  private Double kSD;
  
  //最大导纳(pu)
  private Double bMAX;
  
  //连续控制的最大导纳(pu)
  private Double bPMAX;
  
  //连续控制的最小导纳(pu)
  private Double bPMIN;
  
  //最小导纳(pu)
  private Double bMIN;
  
  //可控硅(Thyristor)触发时延(秒)
  private Double tS6;
  
  //电压偏差
  private Double dV;
  
  //被控母线名
  private String cON_NAME;
  
  //被控母线基准电压
  private Double cON_KV;
  
  //数据库主键
  private String keyName;
  
  //母线索引
  private Integer busPtr;
  
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
    
  public Double getACBus_KV() 
  {
    return aCBus_KV;
  }
    
  public void setACBus_KV(Double aCBus_KV)
  {
    this.aCBus_KV = aCBus_KV;
  }
    
  public Integer getID() 
  {
    return iD;
  }
    
  public void setID(Integer iD)
  {
    this.iD = iD;
  }
    
  public Double getTS1() 
  {
    return tS1;
  }
    
  public void setTS1(Double tS1)
  {
    this.tS1 = tS1;
  }
    
  public Double getVEMAX() 
  {
    return vEMAX;
  }
    
  public void setVEMAX(Double vEMAX)
  {
    this.vEMAX = vEMAX;
  }
    
  public Double getTS2() 
  {
    return tS2;
  }
    
  public void setTS2(Double tS2)
  {
    this.tS2 = tS2;
  }
    
  public Double getTS3() 
  {
    return tS3;
  }
    
  public void setTS3(Double tS3)
  {
    this.tS3 = tS3;
  }
    
  public Integer getA() 
  {
    return a;
  }
    
  public void setA(Integer a)
  {
    this.a = a;
  }
    
  public Integer getB() 
  {
    return b;
  }
    
  public void setB(Integer b)
  {
    this.b = b;
  }
    
  public Double getTS4() 
  {
    return tS4;
  }
    
  public void setTS4(Double tS4)
  {
    this.tS4 = tS4;
  }
    
  public Double getTS5() 
  {
    return tS5;
  }
    
  public void setTS5(Double tS5)
  {
    this.tS5 = tS5;
  }
    
  public Double getKSVS() 
  {
    return kSVS;
  }
    
  public void setKSVS(Double kSVS)
  {
    this.kSVS = kSVS;
  }
    
  public Double getKSD() 
  {
    return kSD;
  }
    
  public void setKSD(Double kSD)
  {
    this.kSD = kSD;
  }
    
  public Double getBMAX() 
  {
    return bMAX;
  }
    
  public void setBMAX(Double bMAX)
  {
    this.bMAX = bMAX;
  }
    
  public Double getBPMAX() 
  {
    return bPMAX;
  }
    
  public void setBPMAX(Double bPMAX)
  {
    this.bPMAX = bPMAX;
  }
    
  public Double getBPMIN() 
  {
    return bPMIN;
  }
    
  public void setBPMIN(Double bPMIN)
  {
    this.bPMIN = bPMIN;
  }
    
  public Double getBMIN() 
  {
    return bMIN;
  }
    
  public void setBMIN(Double bMIN)
  {
    this.bMIN = bMIN;
  }
    
  public Double getTS6() 
  {
    return tS6;
  }
    
  public void setTS6(Double tS6)
  {
    this.tS6 = tS6;
  }
    
  public Double getDV() 
  {
    return dV;
  }
    
  public void setDV(Double dV)
  {
    this.dV = dV;
  }
    
  public String getCON_NAME() 
  {
    return cON_NAME;
  }
    
  public void setCON_NAME(String cON_NAME)
  {
    this.cON_NAME = cON_NAME;
  }
    
  public Double getCON_KV() 
  {
    return cON_KV;
  }
    
  public void setCON_KV(Double cON_KV)
  {
    this.cON_KV = cON_KV;
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
    
}
    
