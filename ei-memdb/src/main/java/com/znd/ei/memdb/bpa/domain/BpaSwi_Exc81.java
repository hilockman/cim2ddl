package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*1981年IEEE励磁系统模型表(F)	*
***********************/
public class BpaSwi_Exc81  implements MemIndexable 
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
  private Double Exc81_RC;
  
  //负载补偿之有功关分量(pu)
  private Double Exc81_XC;
  
  //调节器输入滤波器时间常数(秒)
  private Double Exc81_TR;
  
  //电压调节器滞后时间常数(秒)
  private Double Exc81_VIAMax_VAMax;
  
  //电压调节器超前时间常数(秒)
  private Double Exc81_VIMin_VAMin;
  
  //电压调节器增益(pu)
  private Double Exc81_TB;
  
  //电压调节器滞后时间常数(秒)
  private Double Exc81_TC;
  
  //电压调节器最大输出(pu)
  private Double Exc81_KA_BusKV;
  
  //电压调节器最小输出(pu)
  private Double Exc81_TA_TRH;
  
  //励磁机自励磁时间常数(pu)
  private Double Exc81_VRMax_VAMax;
  
  //励磁机时间常数(秒)
  private Double Exc81_VRMin_VAMin;
  
  //调压器稳定回路增益(pu)
  private Double Exc81_EFDMax_VBMax;
  
  //第一级调节器增益(pu)
  private Double Exc81_KE_KJ;
  
  //励磁机时间常数(秒)
  private Double Exc81_TE;
  
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
    
  public Double getExc81_RC()
  {
    return Exc81_RC;
  }
    
  public void setExc81_RC(Double Exc81_RC)
  {
    this.Exc81_RC = Exc81_RC;
  }
    
  public Double getExc81_XC()
  {
    return Exc81_XC;
  }
    
  public void setExc81_XC(Double Exc81_XC)
  {
    this.Exc81_XC = Exc81_XC;
  }
    
  public Double getExc81_TR()
  {
    return Exc81_TR;
  }
    
  public void setExc81_TR(Double Exc81_TR)
  {
    this.Exc81_TR = Exc81_TR;
  }
    
  public Double getExc81_VIAMax_VAMax()
  {
    return Exc81_VIAMax_VAMax;
  }
    
  public void setExc81_VIAMax_VAMax(Double Exc81_VIAMax_VAMax)
  {
    this.Exc81_VIAMax_VAMax = Exc81_VIAMax_VAMax;
  }
    
  public Double getExc81_VIMin_VAMin()
  {
    return Exc81_VIMin_VAMin;
  }
    
  public void setExc81_VIMin_VAMin(Double Exc81_VIMin_VAMin)
  {
    this.Exc81_VIMin_VAMin = Exc81_VIMin_VAMin;
  }
    
  public Double getExc81_TB()
  {
    return Exc81_TB;
  }
    
  public void setExc81_TB(Double Exc81_TB)
  {
    this.Exc81_TB = Exc81_TB;
  }
    
  public Double getExc81_TC()
  {
    return Exc81_TC;
  }
    
  public void setExc81_TC(Double Exc81_TC)
  {
    this.Exc81_TC = Exc81_TC;
  }
    
  public Double getExc81_KA_BusKV()
  {
    return Exc81_KA_BusKV;
  }
    
  public void setExc81_KA_BusKV(Double Exc81_KA_BusKV)
  {
    this.Exc81_KA_BusKV = Exc81_KA_BusKV;
  }
    
  public Double getExc81_TA_TRH()
  {
    return Exc81_TA_TRH;
  }
    
  public void setExc81_TA_TRH(Double Exc81_TA_TRH)
  {
    this.Exc81_TA_TRH = Exc81_TA_TRH;
  }
    
  public Double getExc81_VRMax_VAMax()
  {
    return Exc81_VRMax_VAMax;
  }
    
  public void setExc81_VRMax_VAMax(Double Exc81_VRMax_VAMax)
  {
    this.Exc81_VRMax_VAMax = Exc81_VRMax_VAMax;
  }
    
  public Double getExc81_VRMin_VAMin()
  {
    return Exc81_VRMin_VAMin;
  }
    
  public void setExc81_VRMin_VAMin(Double Exc81_VRMin_VAMin)
  {
    this.Exc81_VRMin_VAMin = Exc81_VRMin_VAMin;
  }
    
  public Double getExc81_EFDMax_VBMax()
  {
    return Exc81_EFDMax_VBMax;
  }
    
  public void setExc81_EFDMax_VBMax(Double Exc81_EFDMax_VBMax)
  {
    this.Exc81_EFDMax_VBMax = Exc81_EFDMax_VBMax;
  }
    
  public Double getExc81_KE_KJ()
  {
    return Exc81_KE_KJ;
  }
    
  public void setExc81_KE_KJ(Double Exc81_KE_KJ)
  {
    this.Exc81_KE_KJ = Exc81_KE_KJ;
  }
    
  public Double getExc81_TE()
  {
    return Exc81_TE;
  }
    
  public void setExc81_TE(Double Exc81_TE)
  {
    this.Exc81_TE = Exc81_TE;
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
    return "BpaSwi_Exc81 ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", Exc81_RC = " + Exc81_RC
	 + ", Exc81_XC = " + Exc81_XC
	 + ", Exc81_TR = " + Exc81_TR
	 + ", Exc81_VIAMax_VAMax = " + Exc81_VIAMax_VAMax
	 + ", Exc81_VIMin_VAMin = " + Exc81_VIMin_VAMin
	 + ", Exc81_TB = " + Exc81_TB
	 + ", Exc81_TC = " + Exc81_TC
	 + ", Exc81_KA_BusKV = " + Exc81_KA_BusKV
	 + ", Exc81_TA_TRH = " + Exc81_TA_TRH
	 + ", Exc81_VRMax_VAMax = " + Exc81_VRMax_VAMax
	 + ", Exc81_VRMin_VAMin = " + Exc81_VRMin_VAMin
	 + ", Exc81_EFDMax_VBMax = " + Exc81_EFDMax_VBMax
	 + ", Exc81_KE_KJ = " + Exc81_KE_KJ
	 + ", Exc81_TE = " + Exc81_TE
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
