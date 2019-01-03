package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*PSS模型SB表(SB)	*
***********************/
public class BpaSwi_PssSB  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //发电机名称
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_KV;
  
  //BusID识别码ID
  private Integer Gen_ID;
  
  //ISIG,输入信号标志
  private Integer PssSB_ISIG;
  
  //TD(秒)
  private Double PssSB_TD;
  
  //TW1(秒)
  private Double PssSB_TW1;
  
  //TW2(秒)
  private Double PssSB_TW2;
  
  //T6(秒)
  private Double PssSB_T6;
  
  //TW3(秒)
  private Double PssSB_TW3;
  
  //TW4(秒)
  private Double PssSB_TW4;
  
  //T7(秒)
  private Double PssSB_T7;
  
  //KS2
  private Double PssSB_KS2;
  
  //KS3
  private Double PssSB_KS3;
  
  //KPG(PU)
  private Double PssSB_KPG;
  
  //MVA_BSE(MVA)
  private Double PssSB_MVA_BSE;
  
  //T8(秒)
  private Double PssSB_T8;
  
  //T9(秒)
  private Double PssSB_T9;
  
  //M
  private Integer PssSB_M;
  
  //N
  private Integer PssSB_N;
  
  //KS1
  private Double PssSB_KS1;
  
  //T1(秒)
  private Double PssSB_T1;
  
  //T2(秒)
  private Double PssSB_T2;
  
  //T3(秒)
  private Double PssSB_T3;
  
  //T4(秒)
  private Double PssSB_T4;
  
  //VPMAX
  private Double PssSB_VPMax;
  
  //VPMIN
  private Double PssSB_VPMin;
  
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
    
  public Double getACBus_KV()
  {
    return ACBus_KV;
  }
    
  public void setACBus_KV(Double ACBus_KV)
  {
    this.ACBus_KV = ACBus_KV;
  }
    
  public Integer getGen_ID()
  {
    return Gen_ID;
  }
    
  public void setGen_ID(Integer Gen_ID)
  {
    this.Gen_ID = Gen_ID;
  }
    
  public Integer getPssSB_ISIG()
  {
    return PssSB_ISIG;
  }
    
  public void setPssSB_ISIG(Integer PssSB_ISIG)
  {
    this.PssSB_ISIG = PssSB_ISIG;
  }
    
  public Double getPssSB_TD()
  {
    return PssSB_TD;
  }
    
  public void setPssSB_TD(Double PssSB_TD)
  {
    this.PssSB_TD = PssSB_TD;
  }
    
  public Double getPssSB_TW1()
  {
    return PssSB_TW1;
  }
    
  public void setPssSB_TW1(Double PssSB_TW1)
  {
    this.PssSB_TW1 = PssSB_TW1;
  }
    
  public Double getPssSB_TW2()
  {
    return PssSB_TW2;
  }
    
  public void setPssSB_TW2(Double PssSB_TW2)
  {
    this.PssSB_TW2 = PssSB_TW2;
  }
    
  public Double getPssSB_T6()
  {
    return PssSB_T6;
  }
    
  public void setPssSB_T6(Double PssSB_T6)
  {
    this.PssSB_T6 = PssSB_T6;
  }
    
  public Double getPssSB_TW3()
  {
    return PssSB_TW3;
  }
    
  public void setPssSB_TW3(Double PssSB_TW3)
  {
    this.PssSB_TW3 = PssSB_TW3;
  }
    
  public Double getPssSB_TW4()
  {
    return PssSB_TW4;
  }
    
  public void setPssSB_TW4(Double PssSB_TW4)
  {
    this.PssSB_TW4 = PssSB_TW4;
  }
    
  public Double getPssSB_T7()
  {
    return PssSB_T7;
  }
    
  public void setPssSB_T7(Double PssSB_T7)
  {
    this.PssSB_T7 = PssSB_T7;
  }
    
  public Double getPssSB_KS2()
  {
    return PssSB_KS2;
  }
    
  public void setPssSB_KS2(Double PssSB_KS2)
  {
    this.PssSB_KS2 = PssSB_KS2;
  }
    
  public Double getPssSB_KS3()
  {
    return PssSB_KS3;
  }
    
  public void setPssSB_KS3(Double PssSB_KS3)
  {
    this.PssSB_KS3 = PssSB_KS3;
  }
    
  public Double getPssSB_KPG()
  {
    return PssSB_KPG;
  }
    
  public void setPssSB_KPG(Double PssSB_KPG)
  {
    this.PssSB_KPG = PssSB_KPG;
  }
    
  public Double getPssSB_MVA_BSE()
  {
    return PssSB_MVA_BSE;
  }
    
  public void setPssSB_MVA_BSE(Double PssSB_MVA_BSE)
  {
    this.PssSB_MVA_BSE = PssSB_MVA_BSE;
  }
    
  public Double getPssSB_T8()
  {
    return PssSB_T8;
  }
    
  public void setPssSB_T8(Double PssSB_T8)
  {
    this.PssSB_T8 = PssSB_T8;
  }
    
  public Double getPssSB_T9()
  {
    return PssSB_T9;
  }
    
  public void setPssSB_T9(Double PssSB_T9)
  {
    this.PssSB_T9 = PssSB_T9;
  }
    
  public Integer getPssSB_M()
  {
    return PssSB_M;
  }
    
  public void setPssSB_M(Integer PssSB_M)
  {
    this.PssSB_M = PssSB_M;
  }
    
  public Integer getPssSB_N()
  {
    return PssSB_N;
  }
    
  public void setPssSB_N(Integer PssSB_N)
  {
    this.PssSB_N = PssSB_N;
  }
    
  public Double getPssSB_KS1()
  {
    return PssSB_KS1;
  }
    
  public void setPssSB_KS1(Double PssSB_KS1)
  {
    this.PssSB_KS1 = PssSB_KS1;
  }
    
  public Double getPssSB_T1()
  {
    return PssSB_T1;
  }
    
  public void setPssSB_T1(Double PssSB_T1)
  {
    this.PssSB_T1 = PssSB_T1;
  }
    
  public Double getPssSB_T2()
  {
    return PssSB_T2;
  }
    
  public void setPssSB_T2(Double PssSB_T2)
  {
    this.PssSB_T2 = PssSB_T2;
  }
    
  public Double getPssSB_T3()
  {
    return PssSB_T3;
  }
    
  public void setPssSB_T3(Double PssSB_T3)
  {
    this.PssSB_T3 = PssSB_T3;
  }
    
  public Double getPssSB_T4()
  {
    return PssSB_T4;
  }
    
  public void setPssSB_T4(Double PssSB_T4)
  {
    this.PssSB_T4 = PssSB_T4;
  }
    
  public Double getPssSB_VPMax()
  {
    return PssSB_VPMax;
  }
    
  public void setPssSB_VPMax(Double PssSB_VPMax)
  {
    this.PssSB_VPMax = PssSB_VPMax;
  }
    
  public Double getPssSB_VPMin()
  {
    return PssSB_VPMin;
  }
    
  public void setPssSB_VPMin(Double PssSB_VPMin)
  {
    this.PssSB_VPMin = PssSB_VPMin;
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
    return "BpaSwi_PssSB ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_KV = " + ACBus_KV
	 + ", Gen_ID = " + Gen_ID
	 + ", PssSB_ISIG = " + PssSB_ISIG
	 + ", PssSB_TD = " + PssSB_TD
	 + ", PssSB_TW1 = " + PssSB_TW1
	 + ", PssSB_TW2 = " + PssSB_TW2
	 + ", PssSB_T6 = " + PssSB_T6
	 + ", PssSB_TW3 = " + PssSB_TW3
	 + ", PssSB_TW4 = " + PssSB_TW4
	 + ", PssSB_T7 = " + PssSB_T7
	 + ", PssSB_KS2 = " + PssSB_KS2
	 + ", PssSB_KS3 = " + PssSB_KS3
	 + ", PssSB_KPG = " + PssSB_KPG
	 + ", PssSB_MVA_BSE = " + PssSB_MVA_BSE
	 + ", PssSB_T8 = " + PssSB_T8
	 + ", PssSB_T9 = " + PssSB_T9
	 + ", PssSB_M = " + PssSB_M
	 + ", PssSB_N = " + PssSB_N
	 + ", PssSB_KS1 = " + PssSB_KS1
	 + ", PssSB_T1 = " + PssSB_T1
	 + ", PssSB_T2 = " + PssSB_T2
	 + ", PssSB_T3 = " + PssSB_T3
	 + ", PssSB_T4 = " + PssSB_T4
	 + ", PssSB_VPMax = " + PssSB_VPMax
	 + ", PssSB_VPMin = " + PssSB_VPMin
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
