package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*PSS模型SA表(SA)	*
***********************/
@Entity
public class BpaSwi_PssSA
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
  
  //T1,滤波器时间常数
  private Double pssSA_T1;
  
  //T2,滤波器时间常数
  private Double pssSA_T2;
  
  //T3,滤波器时间常数
  private Double pssSA_T3;
  
  //T4,滤波器时间常数
  private Double pssSA_T4;
  
  //T5,滤波器时间常数
  private Double pssSA_T5;
  
  //T6,滤波器时间常数
  private Double pssSA_T6;
  
  //K1,速度信号放大倍数
  private Double pssSA_K1;
  
  //K2,加速度信号放大倍数
  private Double pssSA_K2;
  
  //K*
  private Double pssSA_K;
  
  //A,放大倍数
  private Double pssSA_A;
  
  //P,相位
  private Double pssSA_P;
  
  //LIMIT-MAX,输出的最大限幅
  private Double pssSA_LimitMax;
  
  //LIMIT-MIN,输出的最大限幅
  private Double pssSA_LimitMin;
  
  //K的基准容量
  private Double pssSA_KMVA;
  
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
    
  public Double getPssSA_T1() 
  {
    return pssSA_T1;
  }
    
  public void setPssSA_T1(Double pssSA_T1)
  {
    this.pssSA_T1 = pssSA_T1;
  }
    
  public Double getPssSA_T2() 
  {
    return pssSA_T2;
  }
    
  public void setPssSA_T2(Double pssSA_T2)
  {
    this.pssSA_T2 = pssSA_T2;
  }
    
  public Double getPssSA_T3() 
  {
    return pssSA_T3;
  }
    
  public void setPssSA_T3(Double pssSA_T3)
  {
    this.pssSA_T3 = pssSA_T3;
  }
    
  public Double getPssSA_T4() 
  {
    return pssSA_T4;
  }
    
  public void setPssSA_T4(Double pssSA_T4)
  {
    this.pssSA_T4 = pssSA_T4;
  }
    
  public Double getPssSA_T5() 
  {
    return pssSA_T5;
  }
    
  public void setPssSA_T5(Double pssSA_T5)
  {
    this.pssSA_T5 = pssSA_T5;
  }
    
  public Double getPssSA_T6() 
  {
    return pssSA_T6;
  }
    
  public void setPssSA_T6(Double pssSA_T6)
  {
    this.pssSA_T6 = pssSA_T6;
  }
    
  public Double getPssSA_K1() 
  {
    return pssSA_K1;
  }
    
  public void setPssSA_K1(Double pssSA_K1)
  {
    this.pssSA_K1 = pssSA_K1;
  }
    
  public Double getPssSA_K2() 
  {
    return pssSA_K2;
  }
    
  public void setPssSA_K2(Double pssSA_K2)
  {
    this.pssSA_K2 = pssSA_K2;
  }
    
  public Double getPssSA_K() 
  {
    return pssSA_K;
  }
    
  public void setPssSA_K(Double pssSA_K)
  {
    this.pssSA_K = pssSA_K;
  }
    
  public Double getPssSA_A() 
  {
    return pssSA_A;
  }
    
  public void setPssSA_A(Double pssSA_A)
  {
    this.pssSA_A = pssSA_A;
  }
    
  public Double getPssSA_P() 
  {
    return pssSA_P;
  }
    
  public void setPssSA_P(Double pssSA_P)
  {
    this.pssSA_P = pssSA_P;
  }
    
  public Double getPssSA_LimitMax() 
  {
    return pssSA_LimitMax;
  }
    
  public void setPssSA_LimitMax(Double pssSA_LimitMax)
  {
    this.pssSA_LimitMax = pssSA_LimitMax;
  }
    
  public Double getPssSA_LimitMin() 
  {
    return pssSA_LimitMin;
  }
    
  public void setPssSA_LimitMin(Double pssSA_LimitMin)
  {
    this.pssSA_LimitMin = pssSA_LimitMin;
  }
    
  public Double getPssSA_KMVA() 
  {
    return pssSA_KMVA;
  }
    
  public void setPssSA_KMVA(Double pssSA_KMVA)
  {
    this.pssSA_KMVA = pssSA_KMVA;
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
    
