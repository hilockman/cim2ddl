package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*暂态稳定器表(ST)	*
***********************/
public class BpaSwi_PssST  implements MemIndexable 
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
  
  //时间常数(秒)
  private Double pssST_T1;
  
  //时间常数(秒)
  private Double pssST_T2;
  
  //时间常数(秒)
  private Double pssST_T3;
  
  //频率标么值常数
  private Double pssST_K;
  
  //频率偏差1
  private Double pssST_DWt1;
  
  //频率偏差2
  private Double pssST_DWt2;
  
  //频率偏差3
  private Double pssST_DWpt;
  
  //触发延时时间常数(周)
  private Double pssST_TDelay;
  
  //时间常数(秒)
  private Double pssST_T4;
  
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
    
  public Double getPssST_T1()
  {
    return pssST_T1;
  }
    
  public void setPssST_T1(Double pssST_T1)
  {
    this.pssST_T1 = pssST_T1;
  }
    
  public Double getPssST_T2()
  {
    return pssST_T2;
  }
    
  public void setPssST_T2(Double pssST_T2)
  {
    this.pssST_T2 = pssST_T2;
  }
    
  public Double getPssST_T3()
  {
    return pssST_T3;
  }
    
  public void setPssST_T3(Double pssST_T3)
  {
    this.pssST_T3 = pssST_T3;
  }
    
  public Double getPssST_K()
  {
    return pssST_K;
  }
    
  public void setPssST_K(Double pssST_K)
  {
    this.pssST_K = pssST_K;
  }
    
  public Double getPssST_DWt1()
  {
    return pssST_DWt1;
  }
    
  public void setPssST_DWt1(Double pssST_DWt1)
  {
    this.pssST_DWt1 = pssST_DWt1;
  }
    
  public Double getPssST_DWt2()
  {
    return pssST_DWt2;
  }
    
  public void setPssST_DWt2(Double pssST_DWt2)
  {
    this.pssST_DWt2 = pssST_DWt2;
  }
    
  public Double getPssST_DWpt()
  {
    return pssST_DWpt;
  }
    
  public void setPssST_DWpt(Double pssST_DWpt)
  {
    this.pssST_DWpt = pssST_DWpt;
  }
    
  public Double getPssST_TDelay()
  {
    return pssST_TDelay;
  }
    
  public void setPssST_TDelay(Double pssST_TDelay)
  {
    this.pssST_TDelay = pssST_TDelay;
  }
    
  public Double getPssST_T4()
  {
    return pssST_T4;
  }
    
  public void setPssST_T4(Double pssST_T4)
  {
    this.pssST_T4 = pssST_T4;
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
    return "BpaSwi_PssST ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", pssST_T1 = " + pssST_T1
	 + ", pssST_T2 = " + pssST_T2
	 + ", pssST_T3 = " + pssST_T3
	 + ", pssST_K = " + pssST_K
	 + ", pssST_DWt1 = " + pssST_DWt1
	 + ", pssST_DWt2 = " + pssST_DWt2
	 + ", pssST_DWpt = " + pssST_DWpt
	 + ", pssST_TDelay = " + pssST_TDelay
	 + ", pssST_T4 = " + pssST_T4
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
