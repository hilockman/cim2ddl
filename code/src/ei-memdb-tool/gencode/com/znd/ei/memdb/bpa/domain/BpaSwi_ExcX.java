package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*新励磁系统模型表(FX)	*
***********************/
public class BpaSwi_ExcX  implements MemIndexable 
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
  private Double ExcX_RC;
  
  //负载补偿之有功关分量(pu)
  private Double ExcX_XC;
  
  //调节器输入滤波器时间常数(秒)
  private Double ExcX_TR;
  
  //调节器增益(pu)
  private Double ExcX_KA;
  
  //调节器时间常数(秒)
  private Double ExcX_TA;
  
  //比例增益(pu)
  private Double ExcX_Kp;
  
  //积分系数(pu)
  private Double ExcX_KI;
  
  //电压调节器最大输出(pu)
  private Double ExcX_VRMax;
  
  //电压调节器最小输出(pu)
  private Double ExcX_VRMin;
  
  //电流环比例增益(pu)
  private Double ExcX_IKp;
  
  //电流环积分系数(pu)
  private Double ExcX_IKI;
  
  //电流环的最大限幅(pu)
  private Double ExcX_VFMax;
  
  //电流环的最小限幅(pu)
  private Double ExcX_VFMin;
  
  //可控硅整流器增益(pu)
  private Double ExcX_KT;
  
  //可控硅整流器时间常数(秒)
  private Double ExcX_TT;
  
  //励磁电流反馈环节放大倍数
  private Double ExcEX_Kifd;
  
  //励磁电流反馈环节时间常数
  private Double ExcEX_Tifd;
  
  //最小励磁电压(pu)
  private Double ExcEX_EFDMin;
  
  //最大励磁电压(pu)
  private Double ExcEX_EFDMax;
  
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
    
  public Double getExcX_RC()
  {
    return ExcX_RC;
  }
    
  public void setExcX_RC(Double ExcX_RC)
  {
    this.ExcX_RC = ExcX_RC;
  }
    
  public Double getExcX_XC()
  {
    return ExcX_XC;
  }
    
  public void setExcX_XC(Double ExcX_XC)
  {
    this.ExcX_XC = ExcX_XC;
  }
    
  public Double getExcX_TR()
  {
    return ExcX_TR;
  }
    
  public void setExcX_TR(Double ExcX_TR)
  {
    this.ExcX_TR = ExcX_TR;
  }
    
  public Double getExcX_KA()
  {
    return ExcX_KA;
  }
    
  public void setExcX_KA(Double ExcX_KA)
  {
    this.ExcX_KA = ExcX_KA;
  }
    
  public Double getExcX_TA()
  {
    return ExcX_TA;
  }
    
  public void setExcX_TA(Double ExcX_TA)
  {
    this.ExcX_TA = ExcX_TA;
  }
    
  public Double getExcX_Kp()
  {
    return ExcX_Kp;
  }
    
  public void setExcX_Kp(Double ExcX_Kp)
  {
    this.ExcX_Kp = ExcX_Kp;
  }
    
  public Double getExcX_KI()
  {
    return ExcX_KI;
  }
    
  public void setExcX_KI(Double ExcX_KI)
  {
    this.ExcX_KI = ExcX_KI;
  }
    
  public Double getExcX_VRMax()
  {
    return ExcX_VRMax;
  }
    
  public void setExcX_VRMax(Double ExcX_VRMax)
  {
    this.ExcX_VRMax = ExcX_VRMax;
  }
    
  public Double getExcX_VRMin()
  {
    return ExcX_VRMin;
  }
    
  public void setExcX_VRMin(Double ExcX_VRMin)
  {
    this.ExcX_VRMin = ExcX_VRMin;
  }
    
  public Double getExcX_IKp()
  {
    return ExcX_IKp;
  }
    
  public void setExcX_IKp(Double ExcX_IKp)
  {
    this.ExcX_IKp = ExcX_IKp;
  }
    
  public Double getExcX_IKI()
  {
    return ExcX_IKI;
  }
    
  public void setExcX_IKI(Double ExcX_IKI)
  {
    this.ExcX_IKI = ExcX_IKI;
  }
    
  public Double getExcX_VFMax()
  {
    return ExcX_VFMax;
  }
    
  public void setExcX_VFMax(Double ExcX_VFMax)
  {
    this.ExcX_VFMax = ExcX_VFMax;
  }
    
  public Double getExcX_VFMin()
  {
    return ExcX_VFMin;
  }
    
  public void setExcX_VFMin(Double ExcX_VFMin)
  {
    this.ExcX_VFMin = ExcX_VFMin;
  }
    
  public Double getExcX_KT()
  {
    return ExcX_KT;
  }
    
  public void setExcX_KT(Double ExcX_KT)
  {
    this.ExcX_KT = ExcX_KT;
  }
    
  public Double getExcX_TT()
  {
    return ExcX_TT;
  }
    
  public void setExcX_TT(Double ExcX_TT)
  {
    this.ExcX_TT = ExcX_TT;
  }
    
  public Double getExcEX_Kifd()
  {
    return ExcEX_Kifd;
  }
    
  public void setExcEX_Kifd(Double ExcEX_Kifd)
  {
    this.ExcEX_Kifd = ExcEX_Kifd;
  }
    
  public Double getExcEX_Tifd()
  {
    return ExcEX_Tifd;
  }
    
  public void setExcEX_Tifd(Double ExcEX_Tifd)
  {
    this.ExcEX_Tifd = ExcEX_Tifd;
  }
    
  public Double getExcEX_EFDMin()
  {
    return ExcEX_EFDMin;
  }
    
  public void setExcEX_EFDMin(Double ExcEX_EFDMin)
  {
    this.ExcEX_EFDMin = ExcEX_EFDMin;
  }
    
  public Double getExcEX_EFDMax()
  {
    return ExcEX_EFDMax;
  }
    
  public void setExcEX_EFDMax(Double ExcEX_EFDMax)
  {
    this.ExcEX_EFDMax = ExcEX_EFDMax;
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
    return "BpaSwi_ExcX ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", ExcX_RC = " + ExcX_RC
	 + ", ExcX_XC = " + ExcX_XC
	 + ", ExcX_TR = " + ExcX_TR
	 + ", ExcX_KA = " + ExcX_KA
	 + ", ExcX_TA = " + ExcX_TA
	 + ", ExcX_Kp = " + ExcX_Kp
	 + ", ExcX_KI = " + ExcX_KI
	 + ", ExcX_VRMax = " + ExcX_VRMax
	 + ", ExcX_VRMin = " + ExcX_VRMin
	 + ", ExcX_IKp = " + ExcX_IKp
	 + ", ExcX_IKI = " + ExcX_IKI
	 + ", ExcX_VFMax = " + ExcX_VFMax
	 + ", ExcX_VFMin = " + ExcX_VFMin
	 + ", ExcX_KT = " + ExcX_KT
	 + ", ExcX_TT = " + ExcX_TT
	 + ", ExcEX_Kifd = " + ExcEX_Kifd
	 + ", ExcEX_Tifd = " + ExcEX_Tifd
	 + ", ExcEX_EFDMin = " + ExcEX_EFDMin
	 + ", ExcEX_EFDMax = " + ExcEX_EFDMax
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
