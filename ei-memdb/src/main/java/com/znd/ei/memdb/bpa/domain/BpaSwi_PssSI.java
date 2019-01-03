package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*PSS模型SI表(SI)	*
***********************/
public class BpaSwi_PssSI  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //发电机母线名
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //TRW
  private Double PssSI_TRW;
  
  //T5
  private Double PssSI_T5;
  
  //T6
  private Double PssSI_T6;
  
  //T7
  private Double PssSI_T7;
  
  //KR
  private Double PssSI_KR;
  
  //TRP
  private Double PssSI_TRP;
  
  //TW
  private Double PssSI_TW;
  
  //TW1
  private Double PssSI_TW1;
  
  //TW2
  private Double PssSI_TW2;
  
  //KS
  private Double PssSI_KS;
  
  //T9
  private Double PssSI_T9;
  
  //T10
  private Double PssSI_T10;
  
  //T12
  private Double PssSI_T12;
  
  //输入信号
  private Integer PssSI_INP;
  
  //KP
  private Double PssSI_KP;
  
  //T1
  private Double PssSI_T1;
  
  //T2
  private Double PssSI_T2;
  
  //T13
  private Double PssSI_T13;
  
  //T14
  private Double PssSI_T14;
  
  //T3
  private Double PssSI_T3;
  
  //T4
  private Double PssSI_T4;
  
  //VSMAX
  private Double PssSI_VSMax;
  
  //VSMIN
  private Double PssSI_VSMin;
  
  //IB
  private Integer PssSI_IB;
  
  //MeaName
  private String PssSI_MeaBusName;
  
  //MeaKV
  private Double PssSI_MeaBusKV;
  
  //SI卡中的KR的基准容量(MVA)
  private Double PssSI_KMVA;
  
  //数据库主键
  private String KeyName;
  
  //发电机母线索引
  private Integer BusPtr;
  
  //量测母线索引
  private Integer Gen_iRMeaBus;
  
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
    
  public Double getPssSI_TRW()
  {
    return PssSI_TRW;
  }
    
  public void setPssSI_TRW(Double PssSI_TRW)
  {
    this.PssSI_TRW = PssSI_TRW;
  }
    
  public Double getPssSI_T5()
  {
    return PssSI_T5;
  }
    
  public void setPssSI_T5(Double PssSI_T5)
  {
    this.PssSI_T5 = PssSI_T5;
  }
    
  public Double getPssSI_T6()
  {
    return PssSI_T6;
  }
    
  public void setPssSI_T6(Double PssSI_T6)
  {
    this.PssSI_T6 = PssSI_T6;
  }
    
  public Double getPssSI_T7()
  {
    return PssSI_T7;
  }
    
  public void setPssSI_T7(Double PssSI_T7)
  {
    this.PssSI_T7 = PssSI_T7;
  }
    
  public Double getPssSI_KR()
  {
    return PssSI_KR;
  }
    
  public void setPssSI_KR(Double PssSI_KR)
  {
    this.PssSI_KR = PssSI_KR;
  }
    
  public Double getPssSI_TRP()
  {
    return PssSI_TRP;
  }
    
  public void setPssSI_TRP(Double PssSI_TRP)
  {
    this.PssSI_TRP = PssSI_TRP;
  }
    
  public Double getPssSI_TW()
  {
    return PssSI_TW;
  }
    
  public void setPssSI_TW(Double PssSI_TW)
  {
    this.PssSI_TW = PssSI_TW;
  }
    
  public Double getPssSI_TW1()
  {
    return PssSI_TW1;
  }
    
  public void setPssSI_TW1(Double PssSI_TW1)
  {
    this.PssSI_TW1 = PssSI_TW1;
  }
    
  public Double getPssSI_TW2()
  {
    return PssSI_TW2;
  }
    
  public void setPssSI_TW2(Double PssSI_TW2)
  {
    this.PssSI_TW2 = PssSI_TW2;
  }
    
  public Double getPssSI_KS()
  {
    return PssSI_KS;
  }
    
  public void setPssSI_KS(Double PssSI_KS)
  {
    this.PssSI_KS = PssSI_KS;
  }
    
  public Double getPssSI_T9()
  {
    return PssSI_T9;
  }
    
  public void setPssSI_T9(Double PssSI_T9)
  {
    this.PssSI_T9 = PssSI_T9;
  }
    
  public Double getPssSI_T10()
  {
    return PssSI_T10;
  }
    
  public void setPssSI_T10(Double PssSI_T10)
  {
    this.PssSI_T10 = PssSI_T10;
  }
    
  public Double getPssSI_T12()
  {
    return PssSI_T12;
  }
    
  public void setPssSI_T12(Double PssSI_T12)
  {
    this.PssSI_T12 = PssSI_T12;
  }
    
  public Integer getPssSI_INP()
  {
    return PssSI_INP;
  }
    
  public void setPssSI_INP(Integer PssSI_INP)
  {
    this.PssSI_INP = PssSI_INP;
  }
    
  public Double getPssSI_KP()
  {
    return PssSI_KP;
  }
    
  public void setPssSI_KP(Double PssSI_KP)
  {
    this.PssSI_KP = PssSI_KP;
  }
    
  public Double getPssSI_T1()
  {
    return PssSI_T1;
  }
    
  public void setPssSI_T1(Double PssSI_T1)
  {
    this.PssSI_T1 = PssSI_T1;
  }
    
  public Double getPssSI_T2()
  {
    return PssSI_T2;
  }
    
  public void setPssSI_T2(Double PssSI_T2)
  {
    this.PssSI_T2 = PssSI_T2;
  }
    
  public Double getPssSI_T13()
  {
    return PssSI_T13;
  }
    
  public void setPssSI_T13(Double PssSI_T13)
  {
    this.PssSI_T13 = PssSI_T13;
  }
    
  public Double getPssSI_T14()
  {
    return PssSI_T14;
  }
    
  public void setPssSI_T14(Double PssSI_T14)
  {
    this.PssSI_T14 = PssSI_T14;
  }
    
  public Double getPssSI_T3()
  {
    return PssSI_T3;
  }
    
  public void setPssSI_T3(Double PssSI_T3)
  {
    this.PssSI_T3 = PssSI_T3;
  }
    
  public Double getPssSI_T4()
  {
    return PssSI_T4;
  }
    
  public void setPssSI_T4(Double PssSI_T4)
  {
    this.PssSI_T4 = PssSI_T4;
  }
    
  public Double getPssSI_VSMax()
  {
    return PssSI_VSMax;
  }
    
  public void setPssSI_VSMax(Double PssSI_VSMax)
  {
    this.PssSI_VSMax = PssSI_VSMax;
  }
    
  public Double getPssSI_VSMin()
  {
    return PssSI_VSMin;
  }
    
  public void setPssSI_VSMin(Double PssSI_VSMin)
  {
    this.PssSI_VSMin = PssSI_VSMin;
  }
    
  public Integer getPssSI_IB()
  {
    return PssSI_IB;
  }
    
  public void setPssSI_IB(Integer PssSI_IB)
  {
    this.PssSI_IB = PssSI_IB;
  }
    
  public String getPssSI_MeaBusName()
  {
    return PssSI_MeaBusName;
  }
    
  public void setPssSI_MeaBusName(String PssSI_MeaBusName)
  {
    this.PssSI_MeaBusName = PssSI_MeaBusName;
  }
    
  public Double getPssSI_MeaBusKV()
  {
    return PssSI_MeaBusKV;
  }
    
  public void setPssSI_MeaBusKV(Double PssSI_MeaBusKV)
  {
    this.PssSI_MeaBusKV = PssSI_MeaBusKV;
  }
    
  public Double getPssSI_KMVA()
  {
    return PssSI_KMVA;
  }
    
  public void setPssSI_KMVA(Double PssSI_KMVA)
  {
    this.PssSI_KMVA = PssSI_KMVA;
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
    
  public Integer getGen_iRMeaBus()
  {
    return Gen_iRMeaBus;
  }
    
  public void setGen_iRMeaBus(Integer Gen_iRMeaBus)
  {
    this.Gen_iRMeaBus = Gen_iRMeaBus;
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
    return "BpaSwi_PssSI ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", PssSI_TRW = " + PssSI_TRW
	 + ", PssSI_T5 = " + PssSI_T5
	 + ", PssSI_T6 = " + PssSI_T6
	 + ", PssSI_T7 = " + PssSI_T7
	 + ", PssSI_KR = " + PssSI_KR
	 + ", PssSI_TRP = " + PssSI_TRP
	 + ", PssSI_TW = " + PssSI_TW
	 + ", PssSI_TW1 = " + PssSI_TW1
	 + ", PssSI_TW2 = " + PssSI_TW2
	 + ", PssSI_KS = " + PssSI_KS
	 + ", PssSI_T9 = " + PssSI_T9
	 + ", PssSI_T10 = " + PssSI_T10
	 + ", PssSI_T12 = " + PssSI_T12
	 + ", PssSI_INP = " + PssSI_INP
	 + ", PssSI_KP = " + PssSI_KP
	 + ", PssSI_T1 = " + PssSI_T1
	 + ", PssSI_T2 = " + PssSI_T2
	 + ", PssSI_T13 = " + PssSI_T13
	 + ", PssSI_T14 = " + PssSI_T14
	 + ", PssSI_T3 = " + PssSI_T3
	 + ", PssSI_T4 = " + PssSI_T4
	 + ", PssSI_VSMax = " + PssSI_VSMax
	 + ", PssSI_VSMin = " + PssSI_VSMin
	 + ", PssSI_IB = " + PssSI_IB
	 + ", PssSI_MeaBusName = " + PssSI_MeaBusName
	 + ", PssSI_MeaBusKV = " + PssSI_MeaBusKV
	 + ", PssSI_KMVA = " + PssSI_KMVA
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", Gen_iRMeaBus = " + Gen_iRMeaBus
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
