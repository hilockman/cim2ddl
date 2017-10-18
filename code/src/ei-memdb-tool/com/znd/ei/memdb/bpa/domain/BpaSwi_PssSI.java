package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*PSS模型SI表(SI)	*
***********************/
@Entity
public class BpaSwi_PssSI
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //发电机母线名
  private String aCBus_Name;
  
  //发电机基准电压(kV)
  private Double aCBus_kV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //TRW
  private Double pssSI_TRW;
  
  //T5
  private Double pssSI_T5;
  
  //T6
  private Double pssSI_T6;
  
  //T7
  private Double pssSI_T7;
  
  //KR
  private Double pssSI_KR;
  
  //TRP
  private Double pssSI_TRP;
  
  //TW
  private Double pssSI_TW;
  
  //TW1
  private Double pssSI_TW1;
  
  //TW2
  private Double pssSI_TW2;
  
  //KS
  private Double pssSI_KS;
  
  //T9
  private Double pssSI_T9;
  
  //T10
  private Double pssSI_T10;
  
  //T12
  private Double pssSI_T12;
  
  //输入信号
  private Integer pssSI_INP;
  
  //KP
  private Double pssSI_KP;
  
  //T1
  private Double pssSI_T1;
  
  //T2
  private Double pssSI_T2;
  
  //T13
  private Double pssSI_T13;
  
  //T14
  private Double pssSI_T14;
  
  //T3
  private Double pssSI_T3;
  
  //T4
  private Double pssSI_T4;
  
  //VSMAX
  private Double pssSI_VSMax;
  
  //VSMIN
  private Double pssSI_VSMin;
  
  //IB
  private Integer pssSI_IB;
  
  //MeaName
  private String pssSI_MeaBusName;
  
  //MeaKV
  private Double pssSI_MeaBusKV;
  
  //SI卡中的KR的基准容量(MVA)
  private Double pssSI_KMVA;
  
  //数据库主键
  private String keyName;
  
  //发电机母线索引
  private Integer busPtr;
  
  //量测母线索引
  private Integer gen_iRMeaBus;
  
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
    
  public Double getPssSI_TRW() 
  {
    return pssSI_TRW;
  }
    
  public void setPssSI_TRW(Double pssSI_TRW)
  {
    this.pssSI_TRW = pssSI_TRW;
  }
    
  public Double getPssSI_T5() 
  {
    return pssSI_T5;
  }
    
  public void setPssSI_T5(Double pssSI_T5)
  {
    this.pssSI_T5 = pssSI_T5;
  }
    
  public Double getPssSI_T6() 
  {
    return pssSI_T6;
  }
    
  public void setPssSI_T6(Double pssSI_T6)
  {
    this.pssSI_T6 = pssSI_T6;
  }
    
  public Double getPssSI_T7() 
  {
    return pssSI_T7;
  }
    
  public void setPssSI_T7(Double pssSI_T7)
  {
    this.pssSI_T7 = pssSI_T7;
  }
    
  public Double getPssSI_KR() 
  {
    return pssSI_KR;
  }
    
  public void setPssSI_KR(Double pssSI_KR)
  {
    this.pssSI_KR = pssSI_KR;
  }
    
  public Double getPssSI_TRP() 
  {
    return pssSI_TRP;
  }
    
  public void setPssSI_TRP(Double pssSI_TRP)
  {
    this.pssSI_TRP = pssSI_TRP;
  }
    
  public Double getPssSI_TW() 
  {
    return pssSI_TW;
  }
    
  public void setPssSI_TW(Double pssSI_TW)
  {
    this.pssSI_TW = pssSI_TW;
  }
    
  public Double getPssSI_TW1() 
  {
    return pssSI_TW1;
  }
    
  public void setPssSI_TW1(Double pssSI_TW1)
  {
    this.pssSI_TW1 = pssSI_TW1;
  }
    
  public Double getPssSI_TW2() 
  {
    return pssSI_TW2;
  }
    
  public void setPssSI_TW2(Double pssSI_TW2)
  {
    this.pssSI_TW2 = pssSI_TW2;
  }
    
  public Double getPssSI_KS() 
  {
    return pssSI_KS;
  }
    
  public void setPssSI_KS(Double pssSI_KS)
  {
    this.pssSI_KS = pssSI_KS;
  }
    
  public Double getPssSI_T9() 
  {
    return pssSI_T9;
  }
    
  public void setPssSI_T9(Double pssSI_T9)
  {
    this.pssSI_T9 = pssSI_T9;
  }
    
  public Double getPssSI_T10() 
  {
    return pssSI_T10;
  }
    
  public void setPssSI_T10(Double pssSI_T10)
  {
    this.pssSI_T10 = pssSI_T10;
  }
    
  public Double getPssSI_T12() 
  {
    return pssSI_T12;
  }
    
  public void setPssSI_T12(Double pssSI_T12)
  {
    this.pssSI_T12 = pssSI_T12;
  }
    
  public Integer getPssSI_INP() 
  {
    return pssSI_INP;
  }
    
  public void setPssSI_INP(Integer pssSI_INP)
  {
    this.pssSI_INP = pssSI_INP;
  }
    
  public Double getPssSI_KP() 
  {
    return pssSI_KP;
  }
    
  public void setPssSI_KP(Double pssSI_KP)
  {
    this.pssSI_KP = pssSI_KP;
  }
    
  public Double getPssSI_T1() 
  {
    return pssSI_T1;
  }
    
  public void setPssSI_T1(Double pssSI_T1)
  {
    this.pssSI_T1 = pssSI_T1;
  }
    
  public Double getPssSI_T2() 
  {
    return pssSI_T2;
  }
    
  public void setPssSI_T2(Double pssSI_T2)
  {
    this.pssSI_T2 = pssSI_T2;
  }
    
  public Double getPssSI_T13() 
  {
    return pssSI_T13;
  }
    
  public void setPssSI_T13(Double pssSI_T13)
  {
    this.pssSI_T13 = pssSI_T13;
  }
    
  public Double getPssSI_T14() 
  {
    return pssSI_T14;
  }
    
  public void setPssSI_T14(Double pssSI_T14)
  {
    this.pssSI_T14 = pssSI_T14;
  }
    
  public Double getPssSI_T3() 
  {
    return pssSI_T3;
  }
    
  public void setPssSI_T3(Double pssSI_T3)
  {
    this.pssSI_T3 = pssSI_T3;
  }
    
  public Double getPssSI_T4() 
  {
    return pssSI_T4;
  }
    
  public void setPssSI_T4(Double pssSI_T4)
  {
    this.pssSI_T4 = pssSI_T4;
  }
    
  public Double getPssSI_VSMax() 
  {
    return pssSI_VSMax;
  }
    
  public void setPssSI_VSMax(Double pssSI_VSMax)
  {
    this.pssSI_VSMax = pssSI_VSMax;
  }
    
  public Double getPssSI_VSMin() 
  {
    return pssSI_VSMin;
  }
    
  public void setPssSI_VSMin(Double pssSI_VSMin)
  {
    this.pssSI_VSMin = pssSI_VSMin;
  }
    
  public Integer getPssSI_IB() 
  {
    return pssSI_IB;
  }
    
  public void setPssSI_IB(Integer pssSI_IB)
  {
    this.pssSI_IB = pssSI_IB;
  }
    
  public String getPssSI_MeaBusName() 
  {
    return pssSI_MeaBusName;
  }
    
  public void setPssSI_MeaBusName(String pssSI_MeaBusName)
  {
    this.pssSI_MeaBusName = pssSI_MeaBusName;
  }
    
  public Double getPssSI_MeaBusKV() 
  {
    return pssSI_MeaBusKV;
  }
    
  public void setPssSI_MeaBusKV(Double pssSI_MeaBusKV)
  {
    this.pssSI_MeaBusKV = pssSI_MeaBusKV;
  }
    
  public Double getPssSI_KMVA() 
  {
    return pssSI_KMVA;
  }
    
  public void setPssSI_KMVA(Double pssSI_KMVA)
  {
    this.pssSI_KMVA = pssSI_KMVA;
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
    
  public Integer getGen_iRMeaBus() 
  {
    return gen_iRMeaBus;
  }
    
  public void setGen_iRMeaBus(Integer gen_iRMeaBus)
  {
    this.gen_iRMeaBus = gen_iRMeaBus;
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
    
