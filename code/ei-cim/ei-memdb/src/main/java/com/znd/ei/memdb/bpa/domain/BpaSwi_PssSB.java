package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*PSS模型SB表(SB)	*
***********************/
@Entity
public class BpaSwi_PssSB
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
  private Double aCBus_KV;
  
  //BusID识别码ID
  private Integer gen_ID;
  
  //ISIG,输入信号标志
  private Integer pssSB_ISIG;
  
  //TD(秒)
  private Double pssSB_TD;
  
  //TW1(秒)
  private Double pssSB_TW1;
  
  //TW2(秒)
  private Double pssSB_TW2;
  
  //T6(秒)
  private Double pssSB_T6;
  
  //TW3(秒)
  private Double pssSB_TW3;
  
  //TW4(秒)
  private Double pssSB_TW4;
  
  //T7(秒)
  private Double pssSB_T7;
  
  //KS2
  private Double pssSB_KS2;
  
  //KS3
  private Double pssSB_KS3;
  
  //KPG(PU)
  private Double pssSB_KPG;
  
  //MVA_BSE(MVA)
  private Double pssSB_MVA_BSE;
  
  //T8(秒)
  private Double pssSB_T8;
  
  //T9(秒)
  private Double pssSB_T9;
  
  //M
  private Integer pssSB_M;
  
  //N
  private Integer pssSB_N;
  
  //KS1
  private Double pssSB_KS1;
  
  //T1(秒)
  private Double pssSB_T1;
  
  //T2(秒)
  private Double pssSB_T2;
  
  //T3(秒)
  private Double pssSB_T3;
  
  //T4(秒)
  private Double pssSB_T4;
  
  //VPMAX
  private Double pssSB_VPMax;
  
  //VPMIN
  private Double pssSB_VPMin;
  
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
    
  public Double getACBus_KV() 
  {
    return aCBus_KV;
  }
    
  public void setACBus_KV(Double aCBus_KV)
  {
    this.aCBus_KV = aCBus_KV;
  }
    
  public Integer getGen_ID() 
  {
    return gen_ID;
  }
    
  public void setGen_ID(Integer gen_ID)
  {
    this.gen_ID = gen_ID;
  }
    
  public Integer getPssSB_ISIG() 
  {
    return pssSB_ISIG;
  }
    
  public void setPssSB_ISIG(Integer pssSB_ISIG)
  {
    this.pssSB_ISIG = pssSB_ISIG;
  }
    
  public Double getPssSB_TD() 
  {
    return pssSB_TD;
  }
    
  public void setPssSB_TD(Double pssSB_TD)
  {
    this.pssSB_TD = pssSB_TD;
  }
    
  public Double getPssSB_TW1() 
  {
    return pssSB_TW1;
  }
    
  public void setPssSB_TW1(Double pssSB_TW1)
  {
    this.pssSB_TW1 = pssSB_TW1;
  }
    
  public Double getPssSB_TW2() 
  {
    return pssSB_TW2;
  }
    
  public void setPssSB_TW2(Double pssSB_TW2)
  {
    this.pssSB_TW2 = pssSB_TW2;
  }
    
  public Double getPssSB_T6() 
  {
    return pssSB_T6;
  }
    
  public void setPssSB_T6(Double pssSB_T6)
  {
    this.pssSB_T6 = pssSB_T6;
  }
    
  public Double getPssSB_TW3() 
  {
    return pssSB_TW3;
  }
    
  public void setPssSB_TW3(Double pssSB_TW3)
  {
    this.pssSB_TW3 = pssSB_TW3;
  }
    
  public Double getPssSB_TW4() 
  {
    return pssSB_TW4;
  }
    
  public void setPssSB_TW4(Double pssSB_TW4)
  {
    this.pssSB_TW4 = pssSB_TW4;
  }
    
  public Double getPssSB_T7() 
  {
    return pssSB_T7;
  }
    
  public void setPssSB_T7(Double pssSB_T7)
  {
    this.pssSB_T7 = pssSB_T7;
  }
    
  public Double getPssSB_KS2() 
  {
    return pssSB_KS2;
  }
    
  public void setPssSB_KS2(Double pssSB_KS2)
  {
    this.pssSB_KS2 = pssSB_KS2;
  }
    
  public Double getPssSB_KS3() 
  {
    return pssSB_KS3;
  }
    
  public void setPssSB_KS3(Double pssSB_KS3)
  {
    this.pssSB_KS3 = pssSB_KS3;
  }
    
  public Double getPssSB_KPG() 
  {
    return pssSB_KPG;
  }
    
  public void setPssSB_KPG(Double pssSB_KPG)
  {
    this.pssSB_KPG = pssSB_KPG;
  }
    
  public Double getPssSB_MVA_BSE() 
  {
    return pssSB_MVA_BSE;
  }
    
  public void setPssSB_MVA_BSE(Double pssSB_MVA_BSE)
  {
    this.pssSB_MVA_BSE = pssSB_MVA_BSE;
  }
    
  public Double getPssSB_T8() 
  {
    return pssSB_T8;
  }
    
  public void setPssSB_T8(Double pssSB_T8)
  {
    this.pssSB_T8 = pssSB_T8;
  }
    
  public Double getPssSB_T9() 
  {
    return pssSB_T9;
  }
    
  public void setPssSB_T9(Double pssSB_T9)
  {
    this.pssSB_T9 = pssSB_T9;
  }
    
  public Integer getPssSB_M() 
  {
    return pssSB_M;
  }
    
  public void setPssSB_M(Integer pssSB_M)
  {
    this.pssSB_M = pssSB_M;
  }
    
  public Integer getPssSB_N() 
  {
    return pssSB_N;
  }
    
  public void setPssSB_N(Integer pssSB_N)
  {
    this.pssSB_N = pssSB_N;
  }
    
  public Double getPssSB_KS1() 
  {
    return pssSB_KS1;
  }
    
  public void setPssSB_KS1(Double pssSB_KS1)
  {
    this.pssSB_KS1 = pssSB_KS1;
  }
    
  public Double getPssSB_T1() 
  {
    return pssSB_T1;
  }
    
  public void setPssSB_T1(Double pssSB_T1)
  {
    this.pssSB_T1 = pssSB_T1;
  }
    
  public Double getPssSB_T2() 
  {
    return pssSB_T2;
  }
    
  public void setPssSB_T2(Double pssSB_T2)
  {
    this.pssSB_T2 = pssSB_T2;
  }
    
  public Double getPssSB_T3() 
  {
    return pssSB_T3;
  }
    
  public void setPssSB_T3(Double pssSB_T3)
  {
    this.pssSB_T3 = pssSB_T3;
  }
    
  public Double getPssSB_T4() 
  {
    return pssSB_T4;
  }
    
  public void setPssSB_T4(Double pssSB_T4)
  {
    this.pssSB_T4 = pssSB_T4;
  }
    
  public Double getPssSB_VPMax() 
  {
    return pssSB_VPMax;
  }
    
  public void setPssSB_VPMax(Double pssSB_VPMax)
  {
    this.pssSB_VPMax = pssSB_VPMax;
  }
    
  public Double getPssSB_VPMin() 
  {
    return pssSB_VPMin;
  }
    
  public void setPssSB_VPMin(Double pssSB_VPMin)
  {
    this.pssSB_VPMin = pssSB_VPMin;
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
    
