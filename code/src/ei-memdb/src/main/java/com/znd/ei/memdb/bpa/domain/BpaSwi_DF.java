package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*两端直流换相失败模型(DF)	*
***********************/
public class BpaSwi_DF  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //直流母线名称
  private String DCBus_Name;
  
  //直流母线基准电压(kV)
  private Double DCBus_KV;
  
  //直流系统可能发生换相失败的电压变化率的门槛值
  private Double DF_DVDT;
  
  //直流系统可能发生换相失败的电压的门槛值
  private Double DF_Vf1;
  
  //直流系统可能发生换相失败的电压的门槛值
  private Double DF_Vf2;
  
  //换相失败发生到直流系统闭锁的时间
  private Double DF_DT;
  
  //直流系统恢复换相的电压的门槛值
  private Double DF_Vrs;
  
  //从恢复换相到T1时刻(秒)直流功率恢复的百分数
  private Double DF_C1;
  
  //T1时间
  private Double DF_T1;
  
  //从恢复换相到T2时刻(秒)直流功率恢复的百分数
  private Double DF_C2;
  
  //T2时间
  private Double DF_T2;
  
  //从恢复换相到T3时刻(秒)直流功率恢复的百分数
  private Double DF_C3;
  
  //T3时间
  private Double DF_T3;
  
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
    
  public Double getDF_DVDT()
  {
    return DF_DVDT;
  }
    
  public void setDF_DVDT(Double DF_DVDT)
  {
    this.DF_DVDT = DF_DVDT;
  }
    
  public Double getDF_Vf1()
  {
    return DF_Vf1;
  }
    
  public void setDF_Vf1(Double DF_Vf1)
  {
    this.DF_Vf1 = DF_Vf1;
  }
    
  public Double getDF_Vf2()
  {
    return DF_Vf2;
  }
    
  public void setDF_Vf2(Double DF_Vf2)
  {
    this.DF_Vf2 = DF_Vf2;
  }
    
  public Double getDF_DT()
  {
    return DF_DT;
  }
    
  public void setDF_DT(Double DF_DT)
  {
    this.DF_DT = DF_DT;
  }
    
  public Double getDF_Vrs()
  {
    return DF_Vrs;
  }
    
  public void setDF_Vrs(Double DF_Vrs)
  {
    this.DF_Vrs = DF_Vrs;
  }
    
  public Double getDF_C1()
  {
    return DF_C1;
  }
    
  public void setDF_C1(Double DF_C1)
  {
    this.DF_C1 = DF_C1;
  }
    
  public Double getDF_T1()
  {
    return DF_T1;
  }
    
  public void setDF_T1(Double DF_T1)
  {
    this.DF_T1 = DF_T1;
  }
    
  public Double getDF_C2()
  {
    return DF_C2;
  }
    
  public void setDF_C2(Double DF_C2)
  {
    this.DF_C2 = DF_C2;
  }
    
  public Double getDF_T2()
  {
    return DF_T2;
  }
    
  public void setDF_T2(Double DF_T2)
  {
    this.DF_T2 = DF_T2;
  }
    
  public Double getDF_C3()
  {
    return DF_C3;
  }
    
  public void setDF_C3(Double DF_C3)
  {
    this.DF_C3 = DF_C3;
  }
    
  public Double getDF_T3()
  {
    return DF_T3;
  }
    
  public void setDF_T3(Double DF_T3)
  {
    this.DF_T3 = DF_T3;
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
    return "BpaSwi_DF ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", DCBus_Name = " + DCBus_Name
	 + ", DCBus_KV = " + DCBus_KV
	 + ", DF_DVDT = " + DF_DVDT
	 + ", DF_Vf1 = " + DF_Vf1
	 + ", DF_Vf2 = " + DF_Vf2
	 + ", DF_DT = " + DF_DT
	 + ", DF_Vrs = " + DF_Vrs
	 + ", DF_C1 = " + DF_C1
	 + ", DF_T1 = " + DF_T1
	 + ", DF_C2 = " + DF_C2
	 + ", DF_T2 = " + DF_T2
	 + ", DF_C3 = " + DF_C3
	 + ", DF_T3 = " + DF_T3
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
