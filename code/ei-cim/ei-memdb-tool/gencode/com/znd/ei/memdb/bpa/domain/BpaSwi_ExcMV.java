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
  private String cardKey;
  
  //母线名
  private String aCBus_Name;
  
  //基准电压
  private Double aCBus_kV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //负载补偿之有功关分量(pu)
  private Double excMV_RC;
  
  //负载补偿之有功关分量(pu)
  private Double excMV_XC;
  
  //调节器输入滤波器时间常数(秒)
  private Double excMV_TR;
  
  //调节器增益(pu)
  private Double excMV_K;
  
  //比例积分或纯积分调节选择因子
  private Double excMV_kV;
  
  //电压调节器时间常数(秒)
  private Double excMV_T1;
  
  //电压调节器时间常数(秒)
  private Double excMV_T2;
  
  //电压调节器时间常数(秒)
  private Double excMV_T3;
  
  //电压调节器时间常数(秒)
  private Double excMV_T4;
  
  //调压器增益(pu)
  private Double excMV_KA;
  
  //调压器放大器的时间常数(秒)
  private Double excMV_TA;
  
  //调压器稳定回路增益(pu)
  private Double excMV_KF;
  
  //调压器稳定回路时间常数(秒)
  private Double excMV_TF;
  
  //励磁机电流反馈增益(pu)
  private Double excMV_KH;
  
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
    
  public Double getExcMV_RC()
  {
    return excMV_RC;
  }
    
  public void setExcMV_RC(Double excMV_RC)
  {
    this.excMV_RC = excMV_RC;
  }
    
  public Double getExcMV_XC()
  {
    return excMV_XC;
  }
    
  public void setExcMV_XC(Double excMV_XC)
  {
    this.excMV_XC = excMV_XC;
  }
    
  public Double getExcMV_TR()
  {
    return excMV_TR;
  }
    
  public void setExcMV_TR(Double excMV_TR)
  {
    this.excMV_TR = excMV_TR;
  }
    
  public Double getExcMV_K()
  {
    return excMV_K;
  }
    
  public void setExcMV_K(Double excMV_K)
  {
    this.excMV_K = excMV_K;
  }
    
  public Double getExcMV_kV()
  {
    return excMV_kV;
  }
    
  public void setExcMV_kV(Double excMV_kV)
  {
    this.excMV_kV = excMV_kV;
  }
    
  public Double getExcMV_T1()
  {
    return excMV_T1;
  }
    
  public void setExcMV_T1(Double excMV_T1)
  {
    this.excMV_T1 = excMV_T1;
  }
    
  public Double getExcMV_T2()
  {
    return excMV_T2;
  }
    
  public void setExcMV_T2(Double excMV_T2)
  {
    this.excMV_T2 = excMV_T2;
  }
    
  public Double getExcMV_T3()
  {
    return excMV_T3;
  }
    
  public void setExcMV_T3(Double excMV_T3)
  {
    this.excMV_T3 = excMV_T3;
  }
    
  public Double getExcMV_T4()
  {
    return excMV_T4;
  }
    
  public void setExcMV_T4(Double excMV_T4)
  {
    this.excMV_T4 = excMV_T4;
  }
    
  public Double getExcMV_KA()
  {
    return excMV_KA;
  }
    
  public void setExcMV_KA(Double excMV_KA)
  {
    this.excMV_KA = excMV_KA;
  }
    
  public Double getExcMV_TA()
  {
    return excMV_TA;
  }
    
  public void setExcMV_TA(Double excMV_TA)
  {
    this.excMV_TA = excMV_TA;
  }
    
  public Double getExcMV_KF()
  {
    return excMV_KF;
  }
    
  public void setExcMV_KF(Double excMV_KF)
  {
    this.excMV_KF = excMV_KF;
  }
    
  public Double getExcMV_TF()
  {
    return excMV_TF;
  }
    
  public void setExcMV_TF(Double excMV_TF)
  {
    this.excMV_TF = excMV_TF;
  }
    
  public Double getExcMV_KH()
  {
    return excMV_KH;
  }
    
  public void setExcMV_KH(Double excMV_KH)
  {
    this.excMV_KH = excMV_KH;
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
    return "BpaSwi_ExcMV ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", excMV_RC = " + excMV_RC
	 + ", excMV_XC = " + excMV_XC
	 + ", excMV_TR = " + excMV_TR
	 + ", excMV_K = " + excMV_K
	 + ", excMV_kV = " + excMV_kV
	 + ", excMV_T1 = " + excMV_T1
	 + ", excMV_T2 = " + excMV_T2
	 + ", excMV_T3 = " + excMV_T3
	 + ", excMV_T4 = " + excMV_T4
	 + ", excMV_KA = " + excMV_KA
	 + ", excMV_TA = " + excMV_TA
	 + ", excMV_KF = " + excMV_KF
	 + ", excMV_TF = " + excMV_TF
	 + ", excMV_KH = " + excMV_KH
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
