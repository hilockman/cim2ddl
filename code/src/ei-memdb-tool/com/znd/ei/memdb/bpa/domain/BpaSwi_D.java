package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*直流控制系统模型(D)	*
***********************/
@Entity
public class BpaSwi_D
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //直流母线名称
  private String dCBus_Name;
  
  //直流母线基准电压(kV)
  private Double dCBus_KV;
  
  //电流测量环节时间常数（秒）
  private Double tc;
  
  //电压测量环节时间常数（秒）
  private Double tv;
  
  //电流调节器时间常数1（秒）
  private Double t1;
  
  //电流调节器时间常数2（秒）
  private Double t2;
  
  //电流调节器时间常数3（秒）
  private Double t3;
  
  //电流调节器增益
  private Double ka;
  
  //控制方式,P＝定功率控制,I＝定电流控制
  private Integer mOD;
  
  //阀的过电流能力(pu)
  private Double iMAX;
  
  //电流余裕值(pu),逆变侧必须在0.05-0.3之间
  private Double iMARGIN;
  
  //作逆变器使用时的最小点燃角（度）
  private Double aLPHASTOP;
  
  //换相电压时间常数（秒）,缺省0.01秒
  private Double tD;
  
  //电流限制起始处的额定端电压(pu),缺省0.25pu
  private Double vLIM;
  
  //非空则消去该直流控制系统
  private Integer dISA;
  
  //余裕开关单元关键码
  private Integer mSU;
  
  //数据库主键
  private String keyName;
  
  //直流母线索引
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
    
  public String getDCBus_Name() 
  {
    return dCBus_Name;
  }
    
  public void setDCBus_Name(String dCBus_Name)
  {
    this.dCBus_Name = dCBus_Name;
  }
    
  public Double getDCBus_KV() 
  {
    return dCBus_KV;
  }
    
  public void setDCBus_KV(Double dCBus_KV)
  {
    this.dCBus_KV = dCBus_KV;
  }
    
  public Double getTc() 
  {
    return tc;
  }
    
  public void setTc(Double tc)
  {
    this.tc = tc;
  }
    
  public Double getTv() 
  {
    return tv;
  }
    
  public void setTv(Double tv)
  {
    this.tv = tv;
  }
    
  public Double getT1() 
  {
    return t1;
  }
    
  public void setT1(Double t1)
  {
    this.t1 = t1;
  }
    
  public Double getT2() 
  {
    return t2;
  }
    
  public void setT2(Double t2)
  {
    this.t2 = t2;
  }
    
  public Double getT3() 
  {
    return t3;
  }
    
  public void setT3(Double t3)
  {
    this.t3 = t3;
  }
    
  public Double getKa() 
  {
    return ka;
  }
    
  public void setKa(Double ka)
  {
    this.ka = ka;
  }
    
  public Integer getMOD() 
  {
    return mOD;
  }
    
  public void setMOD(Integer mOD)
  {
    this.mOD = mOD;
  }
    
  public Double getIMAX() 
  {
    return iMAX;
  }
    
  public void setIMAX(Double iMAX)
  {
    this.iMAX = iMAX;
  }
    
  public Double getIMARGIN() 
  {
    return iMARGIN;
  }
    
  public void setIMARGIN(Double iMARGIN)
  {
    this.iMARGIN = iMARGIN;
  }
    
  public Double getALPHASTOP() 
  {
    return aLPHASTOP;
  }
    
  public void setALPHASTOP(Double aLPHASTOP)
  {
    this.aLPHASTOP = aLPHASTOP;
  }
    
  public Double getTD() 
  {
    return tD;
  }
    
  public void setTD(Double tD)
  {
    this.tD = tD;
  }
    
  public Double getVLIM() 
  {
    return vLIM;
  }
    
  public void setVLIM(Double vLIM)
  {
    this.vLIM = vLIM;
  }
    
  public Integer getDISA() 
  {
    return dISA;
  }
    
  public void setDISA(Integer dISA)
  {
    this.dISA = dISA;
  }
    
  public Integer getMSU() 
  {
    return mSU;
  }
    
  public void setMSU(Integer mSU)
  {
    this.mSU = mSU;
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
    
