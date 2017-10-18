package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*电调型(功率反馈)调速器模型表(GD)	*
***********************/
@Entity
public class BpaSwi_GD
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //发电机名称
  private String aCBus_Name;
  
  //发电机基准电压(kV)
  private Double aCBus_kV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //最大输出机械功率
  private Double gD_Pmax;
  
  //最小输出机械功率
  private Double gD_Pmin;
  
  //Δω的死区(Hz)
  private Double gD_DB;
  
  //稳态偏差(pu)
  private Double gD_R;
  
  //比例环节增益(pu/pu)
  private Double gD_Kp;
  
  //积分环节增益(pu/sec)
  private Double gD_Ki;
  
  //微分环节增益(pu·sec)
  private Double gD_Kd;
  
  //积分环节上限(pu)
  private Double gD_GOV_MAX;
  
  //积分环节下限(pu)
  private Double gD_GOV_Min;
  
  //输出上限(pu)
  private Double gD_DEMAND_MAX;
  
  //输出下限(pu)
  private Double gD_DEMAND_MIN;
  
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
    
  public Double getGD_Pmax() 
  {
    return gD_Pmax;
  }
    
  public void setGD_Pmax(Double gD_Pmax)
  {
    this.gD_Pmax = gD_Pmax;
  }
    
  public Double getGD_Pmin() 
  {
    return gD_Pmin;
  }
    
  public void setGD_Pmin(Double gD_Pmin)
  {
    this.gD_Pmin = gD_Pmin;
  }
    
  public Double getGD_DB() 
  {
    return gD_DB;
  }
    
  public void setGD_DB(Double gD_DB)
  {
    this.gD_DB = gD_DB;
  }
    
  public Double getGD_R() 
  {
    return gD_R;
  }
    
  public void setGD_R(Double gD_R)
  {
    this.gD_R = gD_R;
  }
    
  public Double getGD_Kp() 
  {
    return gD_Kp;
  }
    
  public void setGD_Kp(Double gD_Kp)
  {
    this.gD_Kp = gD_Kp;
  }
    
  public Double getGD_Ki() 
  {
    return gD_Ki;
  }
    
  public void setGD_Ki(Double gD_Ki)
  {
    this.gD_Ki = gD_Ki;
  }
    
  public Double getGD_Kd() 
  {
    return gD_Kd;
  }
    
  public void setGD_Kd(Double gD_Kd)
  {
    this.gD_Kd = gD_Kd;
  }
    
  public Double getGD_GOV_MAX() 
  {
    return gD_GOV_MAX;
  }
    
  public void setGD_GOV_MAX(Double gD_GOV_MAX)
  {
    this.gD_GOV_MAX = gD_GOV_MAX;
  }
    
  public Double getGD_GOV_Min() 
  {
    return gD_GOV_Min;
  }
    
  public void setGD_GOV_Min(Double gD_GOV_Min)
  {
    this.gD_GOV_Min = gD_GOV_Min;
  }
    
  public Double getGD_DEMAND_MAX() 
  {
    return gD_DEMAND_MAX;
  }
    
  public void setGD_DEMAND_MAX(Double gD_DEMAND_MAX)
  {
    this.gD_DEMAND_MAX = gD_DEMAND_MAX;
  }
    
  public Double getGD_DEMAND_MIN() 
  {
    return gD_DEMAND_MIN;
  }
    
  public void setGD_DEMAND_MIN(Double gD_DEMAND_MIN)
  {
    this.gD_DEMAND_MIN = gD_DEMAND_MIN;
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
    
