package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*汽轮机调速模型1表(GS)	*
***********************/
public class BpaSwi_GS  implements MemIndexable 
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
  private Double GS_R;
  
  //控制时间
  private Double GS_T1;
  
  //一般为零
  private Double GS_T2;
  
  //伺服机时间常数
  private Double GS_T3;
  
  //最大的汽门开启速度(每秒标么),必为正数
  private Double GS_VELopen;
  
  //最大的汽门关闭速度(每秒标么),必为正数
  private Double GS_VELclose;
  
  //死区,为相对于系统频率的标么值
  private Double GS_E;
  
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
    
  public Double getGS_R()
  {
    return GS_R;
  }
    
  public void setGS_R(Double GS_R)
  {
    this.GS_R = GS_R;
  }
    
  public Double getGS_T1()
  {
    return GS_T1;
  }
    
  public void setGS_T1(Double GS_T1)
  {
    this.GS_T1 = GS_T1;
  }
    
  public Double getGS_T2()
  {
    return GS_T2;
  }
    
  public void setGS_T2(Double GS_T2)
  {
    this.GS_T2 = GS_T2;
  }
    
  public Double getGS_T3()
  {
    return GS_T3;
  }
    
  public void setGS_T3(Double GS_T3)
  {
    this.GS_T3 = GS_T3;
  }
    
  public Double getGS_VELopen()
  {
    return GS_VELopen;
  }
    
  public void setGS_VELopen(Double GS_VELopen)
  {
    this.GS_VELopen = GS_VELopen;
  }
    
  public Double getGS_VELclose()
  {
    return GS_VELclose;
  }
    
  public void setGS_VELclose(Double GS_VELclose)
  {
    this.GS_VELclose = GS_VELclose;
  }
    
  public Double getGS_E()
  {
    return GS_E;
  }
    
  public void setGS_E(Double GS_E)
  {
    this.GS_E = GS_E;
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
    return "BpaSwi_GS ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", Gen_Pmax = " + Gen_Pmax
	 + ", Gen_Pmin = " + Gen_Pmin
	 + ", GS_R = " + GS_R
	 + ", GS_T1 = " + GS_T1
	 + ", GS_T2 = " + GS_T2
	 + ", GS_T3 = " + GS_T3
	 + ", GS_VELopen = " + GS_VELopen
	 + ", GS_VELclose = " + GS_VELclose
	 + ", GS_E = " + GS_E
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
