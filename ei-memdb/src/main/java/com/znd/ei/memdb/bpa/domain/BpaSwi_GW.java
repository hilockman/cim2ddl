package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*水轮机调速模型表(GW)	*
***********************/
public class BpaSwi_GW  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //发电机名称
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //原动机最大输出功率(MW)
  private Double Gen_Pmax;
  
  //原动机最小输出功率(MW)
  private Double Gen_Pmin;
  
  //调差系数
  private Double GW_R;
  
  //控制时间
  private Double GW_T1;
  
  //一般为零
  private Double GW_T2;
  
  //伺服机时间常数
  private Double GW_T3;
  
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
    
  public Double getGen_Pmax()
  {
    return Gen_Pmax;
  }
    
  public void setGen_Pmax(Double Gen_Pmax)
  {
    this.Gen_Pmax = Gen_Pmax;
  }
    
  public Double getGen_Pmin()
  {
    return Gen_Pmin;
  }
    
  public void setGen_Pmin(Double Gen_Pmin)
  {
    this.Gen_Pmin = Gen_Pmin;
  }
    
  public Double getGW_R()
  {
    return GW_R;
  }
    
  public void setGW_R(Double GW_R)
  {
    this.GW_R = GW_R;
  }
    
  public Double getGW_T1()
  {
    return GW_T1;
  }
    
  public void setGW_T1(Double GW_T1)
  {
    this.GW_T1 = GW_T1;
  }
    
  public Double getGW_T2()
  {
    return GW_T2;
  }
    
  public void setGW_T2(Double GW_T2)
  {
    this.GW_T2 = GW_T2;
  }
    
  public Double getGW_T3()
  {
    return GW_T3;
  }
    
  public void setGW_T3(Double GW_T3)
  {
    this.GW_T3 = GW_T3;
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
    return "BpaSwi_GW ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", Gen_Pmax = " + Gen_Pmax
	 + ", Gen_Pmin = " + Gen_Pmin
	 + ", GW_R = " + GW_R
	 + ", GW_T1 = " + GW_T1
	 + ", GW_T2 = " + GW_T2
	 + ", GW_T3 = " + GW_T3
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
