package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*PSS模型SA表(SA)	*
***********************/
public class BpaSwi_PssSA  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //发电机名称
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //T1,滤波器时间常数
  private Double PssSA_T1;
  
  //T2,滤波器时间常数
  private Double PssSA_T2;
  
  //T3,滤波器时间常数
  private Double PssSA_T3;
  
  //T4,滤波器时间常数
  private Double PssSA_T4;
  
  //T5,滤波器时间常数
  private Double PssSA_T5;
  
  //T6,滤波器时间常数
  private Double PssSA_T6;
  
  //K1,速度信号放大倍数
  private Double PssSA_K1;
  
  //K2,加速度信号放大倍数
  private Double PssSA_K2;
  
  //K*
  private Double PssSA_K;
  
  //A,放大倍数
  private Double PssSA_A;
  
  //P,相位
  private Double PssSA_P;
  
  //LIMIT-MAX,输出的最大限幅
  private Double PssSA_LimitMax;
  
  //LIMIT-MIN,输出的最大限幅
  private Double PssSA_LimitMin;
  
  //K的基准容量
  private Double PssSA_KMVA;
  
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
    
  public Double getPssSA_T1()
  {
    return PssSA_T1;
  }
    
  public void setPssSA_T1(Double PssSA_T1)
  {
    this.PssSA_T1 = PssSA_T1;
  }
    
  public Double getPssSA_T2()
  {
    return PssSA_T2;
  }
    
  public void setPssSA_T2(Double PssSA_T2)
  {
    this.PssSA_T2 = PssSA_T2;
  }
    
  public Double getPssSA_T3()
  {
    return PssSA_T3;
  }
    
  public void setPssSA_T3(Double PssSA_T3)
  {
    this.PssSA_T3 = PssSA_T3;
  }
    
  public Double getPssSA_T4()
  {
    return PssSA_T4;
  }
    
  public void setPssSA_T4(Double PssSA_T4)
  {
    this.PssSA_T4 = PssSA_T4;
  }
    
  public Double getPssSA_T5()
  {
    return PssSA_T5;
  }
    
  public void setPssSA_T5(Double PssSA_T5)
  {
    this.PssSA_T5 = PssSA_T5;
  }
    
  public Double getPssSA_T6()
  {
    return PssSA_T6;
  }
    
  public void setPssSA_T6(Double PssSA_T6)
  {
    this.PssSA_T6 = PssSA_T6;
  }
    
  public Double getPssSA_K1()
  {
    return PssSA_K1;
  }
    
  public void setPssSA_K1(Double PssSA_K1)
  {
    this.PssSA_K1 = PssSA_K1;
  }
    
  public Double getPssSA_K2()
  {
    return PssSA_K2;
  }
    
  public void setPssSA_K2(Double PssSA_K2)
  {
    this.PssSA_K2 = PssSA_K2;
  }
    
  public Double getPssSA_K()
  {
    return PssSA_K;
  }
    
  public void setPssSA_K(Double PssSA_K)
  {
    this.PssSA_K = PssSA_K;
  }
    
  public Double getPssSA_A()
  {
    return PssSA_A;
  }
    
  public void setPssSA_A(Double PssSA_A)
  {
    this.PssSA_A = PssSA_A;
  }
    
  public Double getPssSA_P()
  {
    return PssSA_P;
  }
    
  public void setPssSA_P(Double PssSA_P)
  {
    this.PssSA_P = PssSA_P;
  }
    
  public Double getPssSA_LimitMax()
  {
    return PssSA_LimitMax;
  }
    
  public void setPssSA_LimitMax(Double PssSA_LimitMax)
  {
    this.PssSA_LimitMax = PssSA_LimitMax;
  }
    
  public Double getPssSA_LimitMin()
  {
    return PssSA_LimitMin;
  }
    
  public void setPssSA_LimitMin(Double PssSA_LimitMin)
  {
    this.PssSA_LimitMin = PssSA_LimitMin;
  }
    
  public Double getPssSA_KMVA()
  {
    return PssSA_KMVA;
  }
    
  public void setPssSA_KMVA(Double PssSA_KMVA)
  {
    this.PssSA_KMVA = PssSA_KMVA;
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
    return "BpaSwi_PssSA ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", PssSA_T1 = " + PssSA_T1
	 + ", PssSA_T2 = " + PssSA_T2
	 + ", PssSA_T3 = " + PssSA_T3
	 + ", PssSA_T4 = " + PssSA_T4
	 + ", PssSA_T5 = " + PssSA_T5
	 + ", PssSA_T6 = " + PssSA_T6
	 + ", PssSA_K1 = " + PssSA_K1
	 + ", PssSA_K2 = " + PssSA_K2
	 + ", PssSA_K = " + PssSA_K
	 + ", PssSA_A = " + PssSA_A
	 + ", PssSA_P = " + PssSA_P
	 + ", PssSA_LimitMax = " + PssSA_LimitMax
	 + ", PssSA_LimitMin = " + PssSA_LimitMin
	 + ", PssSA_KMVA = " + PssSA_KMVA
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
