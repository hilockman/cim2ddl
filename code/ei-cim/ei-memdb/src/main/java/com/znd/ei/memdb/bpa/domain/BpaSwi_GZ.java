package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*电调型(功率反馈)调速器模型表(GZ)	*
***********************/
@Entity
public class BpaSwi_GZ
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
  
  //伺服系统时间常数(秒)	
  private Double gZ_Tsm;
  
  //汽门最大开启速度(p.u.gate/sec)
  private Double gZ_Ropen;
  
  //汽门最大关闭速度(p.u.gate/sec)
  private Double gZ_Rclose;
  
  //EHC最大位置限制(pu)
  private Double gZ_EHC_MAX;
  
  //EHC最小位置限制(pu)
  private Double gZ_EHC_MIN;
  
  //控制阀开启时间常数(sec)
  private Double gZ_T_Open;
  
  //控制阀关闭时间常数(sec)
  private Double gZ_T_Close;
  
  //阀的死区(pu)
  private Double gZ_DB_Value;
  
  //阀的死区(pu)
  private Double gZ_CV_MAX;
  
  //控制阀下限(pu)
  private Double gZ_CV_MIN;
  
  //电磁功率反馈增益(pu/pu)	
  private Double gZ_Kpe;
  
  //电磁功率反馈时间常数(sec)
  private Double gZ_Tpe;
  
  //控制模式
  private Integer gZ_Mode;
  
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
    
  public Double getGZ_Tsm() 
  {
    return gZ_Tsm;
  }
    
  public void setGZ_Tsm(Double gZ_Tsm)
  {
    this.gZ_Tsm = gZ_Tsm;
  }
    
  public Double getGZ_Ropen() 
  {
    return gZ_Ropen;
  }
    
  public void setGZ_Ropen(Double gZ_Ropen)
  {
    this.gZ_Ropen = gZ_Ropen;
  }
    
  public Double getGZ_Rclose() 
  {
    return gZ_Rclose;
  }
    
  public void setGZ_Rclose(Double gZ_Rclose)
  {
    this.gZ_Rclose = gZ_Rclose;
  }
    
  public Double getGZ_EHC_MAX() 
  {
    return gZ_EHC_MAX;
  }
    
  public void setGZ_EHC_MAX(Double gZ_EHC_MAX)
  {
    this.gZ_EHC_MAX = gZ_EHC_MAX;
  }
    
  public Double getGZ_EHC_MIN() 
  {
    return gZ_EHC_MIN;
  }
    
  public void setGZ_EHC_MIN(Double gZ_EHC_MIN)
  {
    this.gZ_EHC_MIN = gZ_EHC_MIN;
  }
    
  public Double getGZ_T_Open() 
  {
    return gZ_T_Open;
  }
    
  public void setGZ_T_Open(Double gZ_T_Open)
  {
    this.gZ_T_Open = gZ_T_Open;
  }
    
  public Double getGZ_T_Close() 
  {
    return gZ_T_Close;
  }
    
  public void setGZ_T_Close(Double gZ_T_Close)
  {
    this.gZ_T_Close = gZ_T_Close;
  }
    
  public Double getGZ_DB_Value() 
  {
    return gZ_DB_Value;
  }
    
  public void setGZ_DB_Value(Double gZ_DB_Value)
  {
    this.gZ_DB_Value = gZ_DB_Value;
  }
    
  public Double getGZ_CV_MAX() 
  {
    return gZ_CV_MAX;
  }
    
  public void setGZ_CV_MAX(Double gZ_CV_MAX)
  {
    this.gZ_CV_MAX = gZ_CV_MAX;
  }
    
  public Double getGZ_CV_MIN() 
  {
    return gZ_CV_MIN;
  }
    
  public void setGZ_CV_MIN(Double gZ_CV_MIN)
  {
    this.gZ_CV_MIN = gZ_CV_MIN;
  }
    
  public Double getGZ_Kpe() 
  {
    return gZ_Kpe;
  }
    
  public void setGZ_Kpe(Double gZ_Kpe)
  {
    this.gZ_Kpe = gZ_Kpe;
  }
    
  public Double getGZ_Tpe() 
  {
    return gZ_Tpe;
  }
    
  public void setGZ_Tpe(Double gZ_Tpe)
  {
    this.gZ_Tpe = gZ_Tpe;
  }
    
  public Integer getGZ_Mode() 
  {
    return gZ_Mode;
  }
    
  public void setGZ_Mode(Integer gZ_Mode)
  {
    this.gZ_Mode = gZ_Mode;
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
    
