package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*PSS模型SH表(SH)	*
***********************/
public class BpaSwi_PssSH  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名
  private String ACBus_Name;
  
  //基准电压
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //TD
  private Double PssSH_TD;
  
  //T1
  private Double PssSH_T1;
  
  //T2
  private Double PssSH_T2;
  
  //T3
  private Double PssSH_T3;
  
  //K0
  private Double PssSH_K0;
  
  //K1
  private Double PssSH_K1;
  
  //K2
  private Double PssSH_K2;
  
  //K3
  private Double PssSH_K3;
  
  //K
  private Double PssSH_K;
  
  //PSS最大输出(pu)
  private Double PssSH_VSMax;
  
  //PSS最小输出(pu)
  private Double PssSH_VSMin;
  
  //KP
  private Double PssSH_KP;
  
  //KP的基准容量(MVA)
  private Double PssSH_KMVA;
  
  //KPM
  private Double PssSHEX_KPM;
  
  //TPM
  private Double PssSHEX_TPM;
  
  //KPE
  private Double PssSHEX_KPE;
  
  //TPE
  private Double PssSHEX_TPE;
  
  //KW
  private Double PssSHEX_KW;
  
  //TW
  private Double PssSHEX_TW;
  
  //TD1
  private Double PssSHEX_TD1;
  
  //TD2
  private Double PssSHEX_TD2;
  
  //本参数目前仅限于填写0或者1
  private Integer PssSHEX_KD1;
  
  //T4
  private Double PssSHEX_T4;
  
  //K4
  private Double PssSHEX_K4;
  
  //KPM和KPE的基准容量(MVA)
  private Double PssSHEX_KMVA;
  
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
    
  public Double getPssSH_TD()
  {
    return PssSH_TD;
  }
    
  public void setPssSH_TD(Double PssSH_TD)
  {
    this.PssSH_TD = PssSH_TD;
  }
    
  public Double getPssSH_T1()
  {
    return PssSH_T1;
  }
    
  public void setPssSH_T1(Double PssSH_T1)
  {
    this.PssSH_T1 = PssSH_T1;
  }
    
  public Double getPssSH_T2()
  {
    return PssSH_T2;
  }
    
  public void setPssSH_T2(Double PssSH_T2)
  {
    this.PssSH_T2 = PssSH_T2;
  }
    
  public Double getPssSH_T3()
  {
    return PssSH_T3;
  }
    
  public void setPssSH_T3(Double PssSH_T3)
  {
    this.PssSH_T3 = PssSH_T3;
  }
    
  public Double getPssSH_K0()
  {
    return PssSH_K0;
  }
    
  public void setPssSH_K0(Double PssSH_K0)
  {
    this.PssSH_K0 = PssSH_K0;
  }
    
  public Double getPssSH_K1()
  {
    return PssSH_K1;
  }
    
  public void setPssSH_K1(Double PssSH_K1)
  {
    this.PssSH_K1 = PssSH_K1;
  }
    
  public Double getPssSH_K2()
  {
    return PssSH_K2;
  }
    
  public void setPssSH_K2(Double PssSH_K2)
  {
    this.PssSH_K2 = PssSH_K2;
  }
    
  public Double getPssSH_K3()
  {
    return PssSH_K3;
  }
    
  public void setPssSH_K3(Double PssSH_K3)
  {
    this.PssSH_K3 = PssSH_K3;
  }
    
  public Double getPssSH_K()
  {
    return PssSH_K;
  }
    
  public void setPssSH_K(Double PssSH_K)
  {
    this.PssSH_K = PssSH_K;
  }
    
  public Double getPssSH_VSMax()
  {
    return PssSH_VSMax;
  }
    
  public void setPssSH_VSMax(Double PssSH_VSMax)
  {
    this.PssSH_VSMax = PssSH_VSMax;
  }
    
  public Double getPssSH_VSMin()
  {
    return PssSH_VSMin;
  }
    
  public void setPssSH_VSMin(Double PssSH_VSMin)
  {
    this.PssSH_VSMin = PssSH_VSMin;
  }
    
  public Double getPssSH_KP()
  {
    return PssSH_KP;
  }
    
  public void setPssSH_KP(Double PssSH_KP)
  {
    this.PssSH_KP = PssSH_KP;
  }
    
  public Double getPssSH_KMVA()
  {
    return PssSH_KMVA;
  }
    
  public void setPssSH_KMVA(Double PssSH_KMVA)
  {
    this.PssSH_KMVA = PssSH_KMVA;
  }
    
  public Double getPssSHEX_KPM()
  {
    return PssSHEX_KPM;
  }
    
  public void setPssSHEX_KPM(Double PssSHEX_KPM)
  {
    this.PssSHEX_KPM = PssSHEX_KPM;
  }
    
  public Double getPssSHEX_TPM()
  {
    return PssSHEX_TPM;
  }
    
  public void setPssSHEX_TPM(Double PssSHEX_TPM)
  {
    this.PssSHEX_TPM = PssSHEX_TPM;
  }
    
  public Double getPssSHEX_KPE()
  {
    return PssSHEX_KPE;
  }
    
  public void setPssSHEX_KPE(Double PssSHEX_KPE)
  {
    this.PssSHEX_KPE = PssSHEX_KPE;
  }
    
  public Double getPssSHEX_TPE()
  {
    return PssSHEX_TPE;
  }
    
  public void setPssSHEX_TPE(Double PssSHEX_TPE)
  {
    this.PssSHEX_TPE = PssSHEX_TPE;
  }
    
  public Double getPssSHEX_KW()
  {
    return PssSHEX_KW;
  }
    
  public void setPssSHEX_KW(Double PssSHEX_KW)
  {
    this.PssSHEX_KW = PssSHEX_KW;
  }
    
  public Double getPssSHEX_TW()
  {
    return PssSHEX_TW;
  }
    
  public void setPssSHEX_TW(Double PssSHEX_TW)
  {
    this.PssSHEX_TW = PssSHEX_TW;
  }
    
  public Double getPssSHEX_TD1()
  {
    return PssSHEX_TD1;
  }
    
  public void setPssSHEX_TD1(Double PssSHEX_TD1)
  {
    this.PssSHEX_TD1 = PssSHEX_TD1;
  }
    
  public Double getPssSHEX_TD2()
  {
    return PssSHEX_TD2;
  }
    
  public void setPssSHEX_TD2(Double PssSHEX_TD2)
  {
    this.PssSHEX_TD2 = PssSHEX_TD2;
  }
    
  public Integer getPssSHEX_KD1()
  {
    return PssSHEX_KD1;
  }
    
  public void setPssSHEX_KD1(Integer PssSHEX_KD1)
  {
    this.PssSHEX_KD1 = PssSHEX_KD1;
  }
    
  public Double getPssSHEX_T4()
  {
    return PssSHEX_T4;
  }
    
  public void setPssSHEX_T4(Double PssSHEX_T4)
  {
    this.PssSHEX_T4 = PssSHEX_T4;
  }
    
  public Double getPssSHEX_K4()
  {
    return PssSHEX_K4;
  }
    
  public void setPssSHEX_K4(Double PssSHEX_K4)
  {
    this.PssSHEX_K4 = PssSHEX_K4;
  }
    
  public Double getPssSHEX_KMVA()
  {
    return PssSHEX_KMVA;
  }
    
  public void setPssSHEX_KMVA(Double PssSHEX_KMVA)
  {
    this.PssSHEX_KMVA = PssSHEX_KMVA;
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
    return "BpaSwi_PssSH ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", PssSH_TD = " + PssSH_TD
	 + ", PssSH_T1 = " + PssSH_T1
	 + ", PssSH_T2 = " + PssSH_T2
	 + ", PssSH_T3 = " + PssSH_T3
	 + ", PssSH_K0 = " + PssSH_K0
	 + ", PssSH_K1 = " + PssSH_K1
	 + ", PssSH_K2 = " + PssSH_K2
	 + ", PssSH_K3 = " + PssSH_K3
	 + ", PssSH_K = " + PssSH_K
	 + ", PssSH_VSMax = " + PssSH_VSMax
	 + ", PssSH_VSMin = " + PssSH_VSMin
	 + ", PssSH_KP = " + PssSH_KP
	 + ", PssSH_KMVA = " + PssSH_KMVA
	 + ", PssSHEX_KPM = " + PssSHEX_KPM
	 + ", PssSHEX_TPM = " + PssSHEX_TPM
	 + ", PssSHEX_KPE = " + PssSHEX_KPE
	 + ", PssSHEX_TPE = " + PssSHEX_TPE
	 + ", PssSHEX_KW = " + PssSHEX_KW
	 + ", PssSHEX_TW = " + PssSHEX_TW
	 + ", PssSHEX_TD1 = " + PssSHEX_TD1
	 + ", PssSHEX_TD2 = " + PssSHEX_TD2
	 + ", PssSHEX_KD1 = " + PssSHEX_KD1
	 + ", PssSHEX_T4 = " + PssSHEX_T4
	 + ", PssSHEX_K4 = " + PssSHEX_K4
	 + ", PssSHEX_KMVA = " + PssSHEX_KMVA
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
