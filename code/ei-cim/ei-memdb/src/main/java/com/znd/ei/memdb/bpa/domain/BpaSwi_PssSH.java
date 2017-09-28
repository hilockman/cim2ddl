package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*PSS模型SH表(SH)	*
***********************/
@Entity
public class BpaSwi_PssSH
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名
  private String aCBus_Name;
  
  //基准电压
  private Double aCBus_kV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //TD
  private Double pssSH_TD;
  
  //T1
  private Double pssSH_T1;
  
  //T2
  private Double pssSH_T2;
  
  //T3
  private Double pssSH_T3;
  
  //K0
  private Double pssSH_K0;
  
  //K1
  private Double pssSH_K1;
  
  //K2
  private Double pssSH_K2;
  
  //K3
  private Double pssSH_K3;
  
  //K
  private Double pssSH_K;
  
  //PSS最大输出(pu)
  private Double pssSH_VSMax;
  
  //PSS最小输出(pu)
  private Double pssSH_VSMin;
  
  //KP
  private Double pssSH_KP;
  
  //KP的基准容量(MVA)
  private Double pssSH_KMVA;
  
  //KPM
  private Double pssSHEX_KPM;
  
  //TPM
  private Double pssSHEX_TPM;
  
  //KPE
  private Double pssSHEX_KPE;
  
  //TPE
  private Double pssSHEX_TPE;
  
  //KW
  private Double pssSHEX_KW;
  
  //TW
  private Double pssSHEX_TW;
  
  //TD1
  private Double pssSHEX_TD1;
  
  //TD2
  private Double pssSHEX_TD2;
  
  //本参数目前仅限于填写0或者1
  private Integer pssSHEX_KD1;
  
  //T4
  private Double pssSHEX_T4;
  
  //K4
  private Double pssSHEX_K4;
  
  //KPM和KPE的基准容量(MVA)
  private Double pssSHEX_KMVA;
  
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
    
  public Double getPssSH_TD() 
  {
    return pssSH_TD;
  }
    
  public void setPssSH_TD(Double pssSH_TD)
  {
    this.pssSH_TD = pssSH_TD;
  }
    
  public Double getPssSH_T1() 
  {
    return pssSH_T1;
  }
    
  public void setPssSH_T1(Double pssSH_T1)
  {
    this.pssSH_T1 = pssSH_T1;
  }
    
  public Double getPssSH_T2() 
  {
    return pssSH_T2;
  }
    
  public void setPssSH_T2(Double pssSH_T2)
  {
    this.pssSH_T2 = pssSH_T2;
  }
    
  public Double getPssSH_T3() 
  {
    return pssSH_T3;
  }
    
  public void setPssSH_T3(Double pssSH_T3)
  {
    this.pssSH_T3 = pssSH_T3;
  }
    
  public Double getPssSH_K0() 
  {
    return pssSH_K0;
  }
    
  public void setPssSH_K0(Double pssSH_K0)
  {
    this.pssSH_K0 = pssSH_K0;
  }
    
  public Double getPssSH_K1() 
  {
    return pssSH_K1;
  }
    
  public void setPssSH_K1(Double pssSH_K1)
  {
    this.pssSH_K1 = pssSH_K1;
  }
    
  public Double getPssSH_K2() 
  {
    return pssSH_K2;
  }
    
  public void setPssSH_K2(Double pssSH_K2)
  {
    this.pssSH_K2 = pssSH_K2;
  }
    
  public Double getPssSH_K3() 
  {
    return pssSH_K3;
  }
    
  public void setPssSH_K3(Double pssSH_K3)
  {
    this.pssSH_K3 = pssSH_K3;
  }
    
  public Double getPssSH_K() 
  {
    return pssSH_K;
  }
    
  public void setPssSH_K(Double pssSH_K)
  {
    this.pssSH_K = pssSH_K;
  }
    
  public Double getPssSH_VSMax() 
  {
    return pssSH_VSMax;
  }
    
  public void setPssSH_VSMax(Double pssSH_VSMax)
  {
    this.pssSH_VSMax = pssSH_VSMax;
  }
    
  public Double getPssSH_VSMin() 
  {
    return pssSH_VSMin;
  }
    
  public void setPssSH_VSMin(Double pssSH_VSMin)
  {
    this.pssSH_VSMin = pssSH_VSMin;
  }
    
  public Double getPssSH_KP() 
  {
    return pssSH_KP;
  }
    
  public void setPssSH_KP(Double pssSH_KP)
  {
    this.pssSH_KP = pssSH_KP;
  }
    
  public Double getPssSH_KMVA() 
  {
    return pssSH_KMVA;
  }
    
  public void setPssSH_KMVA(Double pssSH_KMVA)
  {
    this.pssSH_KMVA = pssSH_KMVA;
  }
    
  public Double getPssSHEX_KPM() 
  {
    return pssSHEX_KPM;
  }
    
  public void setPssSHEX_KPM(Double pssSHEX_KPM)
  {
    this.pssSHEX_KPM = pssSHEX_KPM;
  }
    
  public Double getPssSHEX_TPM() 
  {
    return pssSHEX_TPM;
  }
    
  public void setPssSHEX_TPM(Double pssSHEX_TPM)
  {
    this.pssSHEX_TPM = pssSHEX_TPM;
  }
    
  public Double getPssSHEX_KPE() 
  {
    return pssSHEX_KPE;
  }
    
  public void setPssSHEX_KPE(Double pssSHEX_KPE)
  {
    this.pssSHEX_KPE = pssSHEX_KPE;
  }
    
  public Double getPssSHEX_TPE() 
  {
    return pssSHEX_TPE;
  }
    
  public void setPssSHEX_TPE(Double pssSHEX_TPE)
  {
    this.pssSHEX_TPE = pssSHEX_TPE;
  }
    
  public Double getPssSHEX_KW() 
  {
    return pssSHEX_KW;
  }
    
  public void setPssSHEX_KW(Double pssSHEX_KW)
  {
    this.pssSHEX_KW = pssSHEX_KW;
  }
    
  public Double getPssSHEX_TW() 
  {
    return pssSHEX_TW;
  }
    
  public void setPssSHEX_TW(Double pssSHEX_TW)
  {
    this.pssSHEX_TW = pssSHEX_TW;
  }
    
  public Double getPssSHEX_TD1() 
  {
    return pssSHEX_TD1;
  }
    
  public void setPssSHEX_TD1(Double pssSHEX_TD1)
  {
    this.pssSHEX_TD1 = pssSHEX_TD1;
  }
    
  public Double getPssSHEX_TD2() 
  {
    return pssSHEX_TD2;
  }
    
  public void setPssSHEX_TD2(Double pssSHEX_TD2)
  {
    this.pssSHEX_TD2 = pssSHEX_TD2;
  }
    
  public Integer getPssSHEX_KD1() 
  {
    return pssSHEX_KD1;
  }
    
  public void setPssSHEX_KD1(Integer pssSHEX_KD1)
  {
    this.pssSHEX_KD1 = pssSHEX_KD1;
  }
    
  public Double getPssSHEX_T4() 
  {
    return pssSHEX_T4;
  }
    
  public void setPssSHEX_T4(Double pssSHEX_T4)
  {
    this.pssSHEX_T4 = pssSHEX_T4;
  }
    
  public Double getPssSHEX_K4() 
  {
    return pssSHEX_K4;
  }
    
  public void setPssSHEX_K4(Double pssSHEX_K4)
  {
    this.pssSHEX_K4 = pssSHEX_K4;
  }
    
  public Double getPssSHEX_KMVA() 
  {
    return pssSHEX_KMVA;
  }
    
  public void setPssSHEX_KMVA(Double pssSHEX_KMVA)
  {
    this.pssSHEX_KMVA = pssSHEX_KMVA;
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
    
