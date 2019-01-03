package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*两端直流系统简化模型(DT)	*
***********************/
public class BpaSwi_DT  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //直流母线名称
  private String DCBus_Name;
  
  //直流母线基准电压(kV)
  private Double DCBus_KV;
  
  //过载截断电压值(标么值)
  private Double DT_DV;
  
  //过电流能力(标么值)
  private Double DT_IMAX;
  
  //电流余裕值(标么值)
  private Double DT_IMARG;
  
  //电流测量回路时间常数(秒)
  private Double DT_Tc;
  
  //电压测量回路时间常数(秒)
  private Double DT_Tv;
  
  //逆变器最小点燃角
  private Double DT_AlphaStop;
  
  //余裕开关单元关键码
  private Integer DT_MSU;
  
  //数据库主键
  private String KeyName;
  
  //直流母线索引
  private Integer BusPtr;
  
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
    
  public String getDCBus_Name()
  {
    return DCBus_Name;
  }
    
  public void setDCBus_Name(String DCBus_Name)
  {
    this.DCBus_Name = DCBus_Name;
  }
    
  public Double getDCBus_KV()
  {
    return DCBus_KV;
  }
    
  public void setDCBus_KV(Double DCBus_KV)
  {
    this.DCBus_KV = DCBus_KV;
  }
    
  public Double getDT_DV()
  {
    return DT_DV;
  }
    
  public void setDT_DV(Double DT_DV)
  {
    this.DT_DV = DT_DV;
  }
    
  public Double getDT_IMAX()
  {
    return DT_IMAX;
  }
    
  public void setDT_IMAX(Double DT_IMAX)
  {
    this.DT_IMAX = DT_IMAX;
  }
    
  public Double getDT_IMARG()
  {
    return DT_IMARG;
  }
    
  public void setDT_IMARG(Double DT_IMARG)
  {
    this.DT_IMARG = DT_IMARG;
  }
    
  public Double getDT_Tc()
  {
    return DT_Tc;
  }
    
  public void setDT_Tc(Double DT_Tc)
  {
    this.DT_Tc = DT_Tc;
  }
    
  public Double getDT_Tv()
  {
    return DT_Tv;
  }
    
  public void setDT_Tv(Double DT_Tv)
  {
    this.DT_Tv = DT_Tv;
  }
    
  public Double getDT_AlphaStop()
  {
    return DT_AlphaStop;
  }
    
  public void setDT_AlphaStop(Double DT_AlphaStop)
  {
    this.DT_AlphaStop = DT_AlphaStop;
  }
    
  public Integer getDT_MSU()
  {
    return DT_MSU;
  }
    
  public void setDT_MSU(Integer DT_MSU)
  {
    this.DT_MSU = DT_MSU;
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
    
  public String toString()
  {
    return "BpaSwi_DT ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", DCBus_Name = " + DCBus_Name
	 + ", DCBus_KV = " + DCBus_KV
	 + ", DT_DV = " + DT_DV
	 + ", DT_IMAX = " + DT_IMAX
	 + ", DT_IMARG = " + DT_IMARG
	 + ", DT_Tc = " + DT_Tc
	 + ", DT_Tv = " + DT_Tv
	 + ", DT_AlphaStop = " + DT_AlphaStop
	 + ", DT_MSU = " + DT_MSU
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
