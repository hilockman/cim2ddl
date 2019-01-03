package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电调型(功率反馈)调速器模型表(GD)	*
***********************/
public class BpaSwi_GD  implements MemIndexable 
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
  
  //最大输出机械功率
  private Double GD_Pmax;
  
  //最小输出机械功率
  private Double GD_Pmin;
  
  //Δω的死区(Hz)
  private Double GD_DB;
  
  //稳态偏差(pu)
  private Double GD_R;
  
  //比例环节增益(pu/pu)
  private Double GD_Kp;
  
  //积分环节增益(pu/sec)
  private Double GD_Ki;
  
  //微分环节增益(pu·sec)
  private Double GD_Kd;
  
  //积分环节上限(pu)
  private Double GD_GOV_MAX;
  
  //积分环节下限(pu)
  private Double GD_GOV_Min;
  
  //输出上限(pu)
  private Double GD_DEMAND_MAX;
  
  //输出下限(pu)
  private Double GD_DEMAND_MIN;
  
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
    
  public Double getGD_Pmax()
  {
    return GD_Pmax;
  }
    
  public void setGD_Pmax(Double GD_Pmax)
  {
    this.GD_Pmax = GD_Pmax;
  }
    
  public Double getGD_Pmin()
  {
    return GD_Pmin;
  }
    
  public void setGD_Pmin(Double GD_Pmin)
  {
    this.GD_Pmin = GD_Pmin;
  }
    
  public Double getGD_DB()
  {
    return GD_DB;
  }
    
  public void setGD_DB(Double GD_DB)
  {
    this.GD_DB = GD_DB;
  }
    
  public Double getGD_R()
  {
    return GD_R;
  }
    
  public void setGD_R(Double GD_R)
  {
    this.GD_R = GD_R;
  }
    
  public Double getGD_Kp()
  {
    return GD_Kp;
  }
    
  public void setGD_Kp(Double GD_Kp)
  {
    this.GD_Kp = GD_Kp;
  }
    
  public Double getGD_Ki()
  {
    return GD_Ki;
  }
    
  public void setGD_Ki(Double GD_Ki)
  {
    this.GD_Ki = GD_Ki;
  }
    
  public Double getGD_Kd()
  {
    return GD_Kd;
  }
    
  public void setGD_Kd(Double GD_Kd)
  {
    this.GD_Kd = GD_Kd;
  }
    
  public Double getGD_GOV_MAX()
  {
    return GD_GOV_MAX;
  }
    
  public void setGD_GOV_MAX(Double GD_GOV_MAX)
  {
    this.GD_GOV_MAX = GD_GOV_MAX;
  }
    
  public Double getGD_GOV_Min()
  {
    return GD_GOV_Min;
  }
    
  public void setGD_GOV_Min(Double GD_GOV_Min)
  {
    this.GD_GOV_Min = GD_GOV_Min;
  }
    
  public Double getGD_DEMAND_MAX()
  {
    return GD_DEMAND_MAX;
  }
    
  public void setGD_DEMAND_MAX(Double GD_DEMAND_MAX)
  {
    this.GD_DEMAND_MAX = GD_DEMAND_MAX;
  }
    
  public Double getGD_DEMAND_MIN()
  {
    return GD_DEMAND_MIN;
  }
    
  public void setGD_DEMAND_MIN(Double GD_DEMAND_MIN)
  {
    this.GD_DEMAND_MIN = GD_DEMAND_MIN;
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
    return "BpaSwi_GD ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", GD_Pmax = " + GD_Pmax
	 + ", GD_Pmin = " + GD_Pmin
	 + ", GD_DB = " + GD_DB
	 + ", GD_R = " + GD_R
	 + ", GD_Kp = " + GD_Kp
	 + ", GD_Ki = " + GD_Ki
	 + ", GD_Kd = " + GD_Kd
	 + ", GD_GOV_MAX = " + GD_GOV_MAX
	 + ", GD_GOV_Min = " + GD_GOV_Min
	 + ", GD_DEMAND_MAX = " + GD_DEMAND_MAX
	 + ", GD_DEMAND_MIN = " + GD_DEMAND_MIN
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
