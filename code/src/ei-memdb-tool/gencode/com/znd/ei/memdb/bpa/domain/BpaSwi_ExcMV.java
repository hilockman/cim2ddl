package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*新励磁系统模型表(FM-FV)	*
***********************/
public class BpaSwi_ExcMV  implements MemIndexable 
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
  
  //负载补偿之有功关分量(pu)
  private Double ExcMV_RC;
  
  //负载补偿之有功关分量(pu)
  private Double ExcMV_XC;
  
  //调节器输入滤波器时间常数(秒)
  private Double ExcMV_TR;
  
  //调节器增益(pu)
  private Double ExcMV_K;
  
  //比例积分或纯积分调节选择因子
  private Double ExcMV_kV;
  
  //电压调节器时间常数(秒)
  private Double ExcMV_T1;
  
  //电压调节器时间常数(秒)
  private Double ExcMV_T2;
  
  //电压调节器时间常数(秒)
  private Double ExcMV_T3;
  
  //电压调节器时间常数(秒)
  private Double ExcMV_T4;
  
  //调压器增益(pu)
  private Double ExcMV_KA;
  
  //调压器放大器的时间常数(秒)
  private Double ExcMV_TA;
  
  //调压器稳定回路增益(pu)
  private Double ExcMV_KF;
  
  //调压器稳定回路时间常数(秒)
  private Double ExcMV_TF;
  
  //励磁机电流反馈增益(pu)
  private Double ExcMV_KH;
  
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
    
  public Double getExcMV_RC()
  {
    return ExcMV_RC;
  }
    
  public void setExcMV_RC(Double ExcMV_RC)
  {
    this.ExcMV_RC = ExcMV_RC;
  }
    
  public Double getExcMV_XC()
  {
    return ExcMV_XC;
  }
    
  public void setExcMV_XC(Double ExcMV_XC)
  {
    this.ExcMV_XC = ExcMV_XC;
  }
    
  public Double getExcMV_TR()
  {
    return ExcMV_TR;
  }
    
  public void setExcMV_TR(Double ExcMV_TR)
  {
    this.ExcMV_TR = ExcMV_TR;
  }
    
  public Double getExcMV_K()
  {
    return ExcMV_K;
  }
    
  public void setExcMV_K(Double ExcMV_K)
  {
    this.ExcMV_K = ExcMV_K;
  }
    
  public Double getExcMV_kV()
  {
    return ExcMV_kV;
  }
    
  public void setExcMV_kV(Double ExcMV_kV)
  {
    this.ExcMV_kV = ExcMV_kV;
  }
    
  public Double getExcMV_T1()
  {
    return ExcMV_T1;
  }
    
  public void setExcMV_T1(Double ExcMV_T1)
  {
    this.ExcMV_T1 = ExcMV_T1;
  }
    
  public Double getExcMV_T2()
  {
    return ExcMV_T2;
  }
    
  public void setExcMV_T2(Double ExcMV_T2)
  {
    this.ExcMV_T2 = ExcMV_T2;
  }
    
  public Double getExcMV_T3()
  {
    return ExcMV_T3;
  }
    
  public void setExcMV_T3(Double ExcMV_T3)
  {
    this.ExcMV_T3 = ExcMV_T3;
  }
    
  public Double getExcMV_T4()
  {
    return ExcMV_T4;
  }
    
  public void setExcMV_T4(Double ExcMV_T4)
  {
    this.ExcMV_T4 = ExcMV_T4;
  }
    
  public Double getExcMV_KA()
  {
    return ExcMV_KA;
  }
    
  public void setExcMV_KA(Double ExcMV_KA)
  {
    this.ExcMV_KA = ExcMV_KA;
  }
    
  public Double getExcMV_TA()
  {
    return ExcMV_TA;
  }
    
  public void setExcMV_TA(Double ExcMV_TA)
  {
    this.ExcMV_TA = ExcMV_TA;
  }
    
  public Double getExcMV_KF()
  {
    return ExcMV_KF;
  }
    
  public void setExcMV_KF(Double ExcMV_KF)
  {
    this.ExcMV_KF = ExcMV_KF;
  }
    
  public Double getExcMV_TF()
  {
    return ExcMV_TF;
  }
    
  public void setExcMV_TF(Double ExcMV_TF)
  {
    this.ExcMV_TF = ExcMV_TF;
  }
    
  public Double getExcMV_KH()
  {
    return ExcMV_KH;
  }
    
  public void setExcMV_KH(Double ExcMV_KH)
  {
    this.ExcMV_KH = ExcMV_KH;
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
    return "BpaSwi_ExcMV ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", ExcMV_RC = " + ExcMV_RC
	 + ", ExcMV_XC = " + ExcMV_XC
	 + ", ExcMV_TR = " + ExcMV_TR
	 + ", ExcMV_K = " + ExcMV_K
	 + ", ExcMV_kV = " + ExcMV_kV
	 + ", ExcMV_T1 = " + ExcMV_T1
	 + ", ExcMV_T2 = " + ExcMV_T2
	 + ", ExcMV_T3 = " + ExcMV_T3
	 + ", ExcMV_T4 = " + ExcMV_T4
	 + ", ExcMV_KA = " + ExcMV_KA
	 + ", ExcMV_TA = " + ExcMV_TA
	 + ", ExcMV_KF = " + ExcMV_KF
	 + ", ExcMV_TF = " + ExcMV_TF
	 + ", ExcMV_KH = " + ExcMV_KH
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
