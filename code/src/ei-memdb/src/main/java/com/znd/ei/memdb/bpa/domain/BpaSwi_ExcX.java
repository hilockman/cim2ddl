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
  private String cardKey;
  
  //母线名
  private String aCBus_Name;
  
  //基准电压
  private Double aCBus_kV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //负载补偿之有功关分量(pu)
  private Double excX_RC;
  
  //负载补偿之有功关分量(pu)
  private Double excX_XC;
  
  //调节器输入滤波器时间常数(秒)
  private Double excX_TR;
  
  //调节器增益(pu)
  private Double excX_KA;
  
  //调节器时间常数(秒)
  private Double excX_TA;
  
  //比例增益(pu)
  private Double excX_Kp;
  
  //积分系数(pu)
  private Double excX_KI;
  
  //电压调节器最大输出(pu)
  private Double excX_VRMax;
  
  //电压调节器最小输出(pu)
  private Double excX_VRMin;
  
  //电流环比例增益(pu)
  private Double excX_IKp;
  
  //电流环积分系数(pu)
  private Double excX_IKI;
  
  //电流环的最大限幅(pu)
  private Double excX_VFMax;
  
  //电流环的最小限幅(pu)
  private Double excX_VFMin;
  
  //可控硅整流器增益(pu)
  private Double excX_KT;
  
  //可控硅整流器时间常数(秒)
  private Double excX_TT;
  
  //励磁电流反馈环节放大倍数
  private Double excEX_Kifd;
  
  //励磁电流反馈环节时间常数
  private Double excEX_Tifd;
  
  //最小励磁电压(pu)
  private Double excEX_EFDMin;
  
  //最大励磁电压(pu)
  private Double excEX_EFDMax;
  
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
    
  public Double getExcX_RC()
  {
    return excX_RC;
  }
    
  public void setExcX_RC(Double excX_RC)
  {
    this.excX_RC = excX_RC;
  }
    
  public Double getExcX_XC()
  {
    return excX_XC;
  }
    
  public void setExcX_XC(Double excX_XC)
  {
    this.excX_XC = excX_XC;
  }
    
  public Double getExcX_TR()
  {
    return excX_TR;
  }
    
  public void setExcX_TR(Double excX_TR)
  {
    this.excX_TR = excX_TR;
  }
    
  public Double getExcX_KA()
  {
    return excX_KA;
  }
    
  public void setExcX_KA(Double excX_KA)
  {
    this.excX_KA = excX_KA;
  }
    
  public Double getExcX_TA()
  {
    return excX_TA;
  }
    
  public void setExcX_TA(Double excX_TA)
  {
    this.excX_TA = excX_TA;
  }
    
  public Double getExcX_Kp()
  {
    return excX_Kp;
  }
    
  public void setExcX_Kp(Double excX_Kp)
  {
    this.excX_Kp = excX_Kp;
  }
    
  public Double getExcX_KI()
  {
    return excX_KI;
  }
    
  public void setExcX_KI(Double excX_KI)
  {
    this.excX_KI = excX_KI;
  }
    
  public Double getExcX_VRMax()
  {
    return excX_VRMax;
  }
    
  public void setExcX_VRMax(Double excX_VRMax)
  {
    this.excX_VRMax = excX_VRMax;
  }
    
  public Double getExcX_VRMin()
  {
    return excX_VRMin;
  }
    
  public void setExcX_VRMin(Double excX_VRMin)
  {
    this.excX_VRMin = excX_VRMin;
  }
    
  public Double getExcX_IKp()
  {
    return excX_IKp;
  }
    
  public void setExcX_IKp(Double excX_IKp)
  {
    this.excX_IKp = excX_IKp;
  }
    
  public Double getExcX_IKI()
  {
    return excX_IKI;
  }
    
  public void setExcX_IKI(Double excX_IKI)
  {
    this.excX_IKI = excX_IKI;
  }
    
  public Double getExcX_VFMax()
  {
    return excX_VFMax;
  }
    
  public void setExcX_VFMax(Double excX_VFMax)
  {
    this.excX_VFMax = excX_VFMax;
  }
    
  public Double getExcX_VFMin()
  {
    return excX_VFMin;
  }
    
  public void setExcX_VFMin(Double excX_VFMin)
  {
    this.excX_VFMin = excX_VFMin;
  }
    
  public Double getExcX_KT()
  {
    return excX_KT;
  }
    
  public void setExcX_KT(Double excX_KT)
  {
    this.excX_KT = excX_KT;
  }
    
  public Double getExcX_TT()
  {
    return excX_TT;
  }
    
  public void setExcX_TT(Double excX_TT)
  {
    this.excX_TT = excX_TT;
  }
    
  public Double getExcEX_Kifd()
  {
    return excEX_Kifd;
  }
    
  public void setExcEX_Kifd(Double excEX_Kifd)
  {
    this.excEX_Kifd = excEX_Kifd;
  }
    
  public Double getExcEX_Tifd()
  {
    return excEX_Tifd;
  }
    
  public void setExcEX_Tifd(Double excEX_Tifd)
  {
    this.excEX_Tifd = excEX_Tifd;
  }
    
  public Double getExcEX_EFDMin()
  {
    return excEX_EFDMin;
  }
    
  public void setExcEX_EFDMin(Double excEX_EFDMin)
  {
    this.excEX_EFDMin = excEX_EFDMin;
  }
    
  public Double getExcEX_EFDMax()
  {
    return excEX_EFDMax;
  }
    
  public void setExcEX_EFDMax(Double excEX_EFDMax)
  {
    this.excEX_EFDMax = excEX_EFDMax;
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
    
  public String toString()
  {
    return "BpaSwi_ExcX ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", excX_RC = " + excX_RC
	 + ", excX_XC = " + excX_XC
	 + ", excX_TR = " + excX_TR
	 + ", excX_KA = " + excX_KA
	 + ", excX_TA = " + excX_TA
	 + ", excX_Kp = " + excX_Kp
	 + ", excX_KI = " + excX_KI
	 + ", excX_VRMax = " + excX_VRMax
	 + ", excX_VRMin = " + excX_VRMin
	 + ", excX_IKp = " + excX_IKp
	 + ", excX_IKI = " + excX_IKI
	 + ", excX_VFMax = " + excX_VFMax
	 + ", excX_VFMin = " + excX_VFMin
	 + ", excX_KT = " + excX_KT
	 + ", excX_TT = " + excX_TT
	 + ", excEX_Kifd = " + excEX_Kifd
	 + ", excEX_Tifd = " + excEX_Tifd
	 + ", excEX_EFDMin = " + excEX_EFDMin
	 + ", excEX_EFDMax = " + excEX_EFDMax
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
