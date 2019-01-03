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
  private String CardKey;
  
  //母线名
  private String ACBus_Name;
  
  //基准电压
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //时间常数(秒)
  private Double PssST_T1;
  
  //时间常数(秒)
  private Double PssST_T2;
  
  //时间常数(秒)
  private Double PssST_T3;
  
  //频率标么值常数
  private Double PssST_K;
  
  //频率偏差1
  private Double PssST_DWt1;
  
  //频率偏差2
  private Double PssST_DWt2;
  
  //频率偏差3
  private Double PssST_DWpt;
  
  //触发延时时间常数(周)
  private Double PssST_TDelay;
  
  //时间常数(秒)
  private Double PssST_T4;
  
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
    
  public Double getPssST_T1()
  {
    return PssST_T1;
  }
    
  public void setPssST_T1(Double PssST_T1)
  {
    this.PssST_T1 = PssST_T1;
  }
    
  public Double getPssST_T2()
  {
    return PssST_T2;
  }
    
  public void setPssST_T2(Double PssST_T2)
  {
    this.PssST_T2 = PssST_T2;
  }
    
  public Double getPssST_T3()
  {
    return PssST_T3;
  }
    
  public void setPssST_T3(Double PssST_T3)
  {
    this.PssST_T3 = PssST_T3;
  }
    
  public Double getPssST_K()
  {
    return PssST_K;
  }
    
  public void setPssST_K(Double PssST_K)
  {
    this.PssST_K = PssST_K;
  }
    
  public Double getPssST_DWt1()
  {
    return PssST_DWt1;
  }
    
  public void setPssST_DWt1(Double PssST_DWt1)
  {
    this.PssST_DWt1 = PssST_DWt1;
  }
    
  public Double getPssST_DWt2()
  {
    return PssST_DWt2;
  }
    
  public void setPssST_DWt2(Double PssST_DWt2)
  {
    this.PssST_DWt2 = PssST_DWt2;
  }
    
  public Double getPssST_DWpt()
  {
    return PssST_DWpt;
  }
    
  public void setPssST_DWpt(Double PssST_DWpt)
  {
    this.PssST_DWpt = PssST_DWpt;
  }
    
  public Double getPssST_TDelay()
  {
    return PssST_TDelay;
  }
    
  public void setPssST_TDelay(Double PssST_TDelay)
  {
    this.PssST_TDelay = PssST_TDelay;
  }
    
  public Double getPssST_T4()
  {
    return PssST_T4;
  }
    
  public void setPssST_T4(Double PssST_T4)
  {
    this.PssST_T4 = PssST_T4;
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
    return "BpaSwi_PssST ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", PssST_T1 = " + PssST_T1
	 + ", PssST_T2 = " + PssST_T2
	 + ", PssST_T3 = " + PssST_T3
	 + ", PssST_K = " + PssST_K
	 + ", PssST_DWt1 = " + PssST_DWt1
	 + ", PssST_DWt2 = " + PssST_DWt2
	 + ", PssST_DWpt = " + PssST_DWpt
	 + ", PssST_TDelay = " + PssST_TDelay
	 + ", PssST_T4 = " + PssST_T4
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
