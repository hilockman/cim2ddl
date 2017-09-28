package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*水轮机调速模型表(GW)	*
***********************/
@Entity
public class BpaSwi_GW
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
  
  //原动机最大输出功率(MW)
  private Double gen_Pmax;
  
  //原动机最小输出功率(MW)
  private Double gen_Pmin;
  
  //调差系数
  private Double gW_R;
  
  //控制时间
  private Double gW_T1;
  
  //一般为零
  private Double gW_T2;
  
  //伺服机时间常数
  private Double gW_T3;
  
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
    
  public Double getGen_Pmax() 
  {
    return gen_Pmax;
  }
    
  public void setGen_Pmax(Double gen_Pmax)
  {
    this.gen_Pmax = gen_Pmax;
  }
    
  public Double getGen_Pmin() 
  {
    return gen_Pmin;
  }
    
  public void setGen_Pmin(Double gen_Pmin)
  {
    this.gen_Pmin = gen_Pmin;
  }
    
  public Double getGW_R() 
  {
    return gW_R;
  }
    
  public void setGW_R(Double gW_R)
  {
    this.gW_R = gW_R;
  }
    
  public Double getGW_T1() 
  {
    return gW_T1;
  }
    
  public void setGW_T1(Double gW_T1)
  {
    this.gW_T1 = gW_T1;
  }
    
  public Double getGW_T2() 
  {
    return gW_T2;
  }
    
  public void setGW_T2(Double gW_T2)
  {
    this.gW_T2 = gW_T2;
  }
    
  public Double getGW_T3() 
  {
    return gW_T3;
  }
    
  public void setGW_T3(Double gW_T3)
  {
    this.gW_T3 = gW_T3;
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
    
