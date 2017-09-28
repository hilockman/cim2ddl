package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*1981年IEEE励磁系统模型表(F)	*
***********************/
@Entity
public class BpaSwi_Exc81
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
  
  //负载补偿之有功关分量(pu)
  private Double exc81_RC;
  
  //负载补偿之有功关分量(pu)
  private Double exc81_XC;
  
  //调节器输入滤波器时间常数(秒)
  private Double exc81_TR;
  
  //电压调节器滞后时间常数(秒)
  private Double exc81_VIAMax_VAMax;
  
  //电压调节器超前时间常数(秒)
  private Double exc81_VIMin_VAMin;
  
  //电压调节器增益(pu)
  private Double exc81_TB;
  
  //电压调节器滞后时间常数(秒)
  private Double exc81_TC;
  
  //电压调节器最大输出(pu)
  private Double exc81_KA_BusKV;
  
  //电压调节器最小输出(pu)
  private Double exc81_TA_TRH;
  
  //励磁机自励磁时间常数(pu)
  private Double exc81_VRMax_VAMax;
  
  //励磁机时间常数(秒)
  private Double exc81_VRMin_VAMin;
  
  //调压器稳定回路增益(pu)
  private Double exc81_EFDMax_VBMax;
  
  //第一级调节器增益(pu)
  private Double exc81_KE_KJ;
  
  //励磁机时间常数(秒)
  private Double exc81_TE;
  
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
    
  public Double getExc81_RC() 
  {
    return exc81_RC;
  }
    
  public void setExc81_RC(Double exc81_RC)
  {
    this.exc81_RC = exc81_RC;
  }
    
  public Double getExc81_XC() 
  {
    return exc81_XC;
  }
    
  public void setExc81_XC(Double exc81_XC)
  {
    this.exc81_XC = exc81_XC;
  }
    
  public Double getExc81_TR() 
  {
    return exc81_TR;
  }
    
  public void setExc81_TR(Double exc81_TR)
  {
    this.exc81_TR = exc81_TR;
  }
    
  public Double getExc81_VIAMax_VAMax() 
  {
    return exc81_VIAMax_VAMax;
  }
    
  public void setExc81_VIAMax_VAMax(Double exc81_VIAMax_VAMax)
  {
    this.exc81_VIAMax_VAMax = exc81_VIAMax_VAMax;
  }
    
  public Double getExc81_VIMin_VAMin() 
  {
    return exc81_VIMin_VAMin;
  }
    
  public void setExc81_VIMin_VAMin(Double exc81_VIMin_VAMin)
  {
    this.exc81_VIMin_VAMin = exc81_VIMin_VAMin;
  }
    
  public Double getExc81_TB() 
  {
    return exc81_TB;
  }
    
  public void setExc81_TB(Double exc81_TB)
  {
    this.exc81_TB = exc81_TB;
  }
    
  public Double getExc81_TC() 
  {
    return exc81_TC;
  }
    
  public void setExc81_TC(Double exc81_TC)
  {
    this.exc81_TC = exc81_TC;
  }
    
  public Double getExc81_KA_BusKV() 
  {
    return exc81_KA_BusKV;
  }
    
  public void setExc81_KA_BusKV(Double exc81_KA_BusKV)
  {
    this.exc81_KA_BusKV = exc81_KA_BusKV;
  }
    
  public Double getExc81_TA_TRH() 
  {
    return exc81_TA_TRH;
  }
    
  public void setExc81_TA_TRH(Double exc81_TA_TRH)
  {
    this.exc81_TA_TRH = exc81_TA_TRH;
  }
    
  public Double getExc81_VRMax_VAMax() 
  {
    return exc81_VRMax_VAMax;
  }
    
  public void setExc81_VRMax_VAMax(Double exc81_VRMax_VAMax)
  {
    this.exc81_VRMax_VAMax = exc81_VRMax_VAMax;
  }
    
  public Double getExc81_VRMin_VAMin() 
  {
    return exc81_VRMin_VAMin;
  }
    
  public void setExc81_VRMin_VAMin(Double exc81_VRMin_VAMin)
  {
    this.exc81_VRMin_VAMin = exc81_VRMin_VAMin;
  }
    
  public Double getExc81_EFDMax_VBMax() 
  {
    return exc81_EFDMax_VBMax;
  }
    
  public void setExc81_EFDMax_VBMax(Double exc81_EFDMax_VBMax)
  {
    this.exc81_EFDMax_VBMax = exc81_EFDMax_VBMax;
  }
    
  public Double getExc81_KE_KJ() 
  {
    return exc81_KE_KJ;
  }
    
  public void setExc81_KE_KJ(Double exc81_KE_KJ)
  {
    this.exc81_KE_KJ = exc81_KE_KJ;
  }
    
  public Double getExc81_TE() 
  {
    return exc81_TE;
  }
    
  public void setExc81_TE(Double exc81_TE)
  {
    this.exc81_TE = exc81_TE;
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
    
