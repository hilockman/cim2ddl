package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*励磁系统继续卡(F#)	*
***********************/
@Entity
public class BpaSwi_FCB
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
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
  
  //IPID
  private Integer f#_IPID;
  
  //并联PID环节的比例环节系数
  private Double f#_KP;
  
  //并联PID环节的积分环节系数
  private Double f#_KI;
  
  //并联PID环节的微分环节系数
  private Double f#_KD;
  
  //并联PID环节的微分环节时间常数(秒)
  private Double f#_TD;
  
  //并联PID环节的积分环节限幅最大值
  private Double f#_INTMAX;
  
  //并联PID环节的积分环节限幅最小值
  private Double f#_INTMIN;
  
  //并联PID环节的微分环节限幅最大值
  private Double f#_DEVMAX;
  
  //并联PID环节的微分环节限幅最小值
  private Double f#_DEVMIN;
  
  //串联PID环节的限幅最大值
  private Double f#_VAlMax;
  
  //串联PID环节的限幅最小值
  private Double f#_VAlMin;
  
  //FU、FV励磁模型是否含有可控硅整流器输出的修订
  private Integer f#_IFUFV;
  
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
    
  public Integer getF#_IPID() 
  {
    return f#_IPID;
  }
    
  public void setF#_IPID(Integer f#_IPID)
  {
    this.f#_IPID = f#_IPID;
  }
    
  public Double getF#_KP() 
  {
    return f#_KP;
  }
    
  public void setF#_KP(Double f#_KP)
  {
    this.f#_KP = f#_KP;
  }
    
  public Double getF#_KI() 
  {
    return f#_KI;
  }
    
  public void setF#_KI(Double f#_KI)
  {
    this.f#_KI = f#_KI;
  }
    
  public Double getF#_KD() 
  {
    return f#_KD;
  }
    
  public void setF#_KD(Double f#_KD)
  {
    this.f#_KD = f#_KD;
  }
    
  public Double getF#_TD() 
  {
    return f#_TD;
  }
    
  public void setF#_TD(Double f#_TD)
  {
    this.f#_TD = f#_TD;
  }
    
  public Double getF#_INTMAX() 
  {
    return f#_INTMAX;
  }
    
  public void setF#_INTMAX(Double f#_INTMAX)
  {
    this.f#_INTMAX = f#_INTMAX;
  }
    
  public Double getF#_INTMIN() 
  {
    return f#_INTMIN;
  }
    
  public void setF#_INTMIN(Double f#_INTMIN)
  {
    this.f#_INTMIN = f#_INTMIN;
  }
    
  public Double getF#_DEVMAX() 
  {
    return f#_DEVMAX;
  }
    
  public void setF#_DEVMAX(Double f#_DEVMAX)
  {
    this.f#_DEVMAX = f#_DEVMAX;
  }
    
  public Double getF#_DEVMIN() 
  {
    return f#_DEVMIN;
  }
    
  public void setF#_DEVMIN(Double f#_DEVMIN)
  {
    this.f#_DEVMIN = f#_DEVMIN;
  }
    
  public Double getF#_VAlMax() 
  {
    return f#_VAlMax;
  }
    
  public void setF#_VAlMax(Double f#_VAlMax)
  {
    this.f#_VAlMax = f#_VAlMax;
  }
    
  public Double getF#_VAlMin() 
  {
    return f#_VAlMin;
  }
    
  public void setF#_VAlMin(Double f#_VAlMin)
  {
    this.f#_VAlMin = f#_VAlMin;
  }
    
  public Integer getF#_IFUFV() 
  {
    return f#_IFUFV;
  }
    
  public void setF#_IFUFV(Integer f#_IFUFV)
  {
    this.f#_IFUFV = f#_IFUFV;
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
    
