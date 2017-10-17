package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*调节系统模型1表(GI)	*
***********************/
@Entity
public class BpaSwi_GI
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
  
  //转速变换环节时间常数(秒)
  private Double gI_T1;
  
  //死区ε(相对系统频率的标么值)
  private Double gI_E;
  
  //转速偏差放大倍数
  private Double gI_K;
  
  //负荷自动开关
  private Integer gI_I1;
  
  //负荷控制器PID比例环节倍数
  private Double gI_KP1;
  
  //负荷控制器PID微分环节倍数
  private Double gI_KD1;
  
  //负荷控制器PID积分环节倍数
  private Double gI_KI1;
  
  //负荷控制器PID积分环节限幅上限
  private Double gI_INTG_MAX1;
  
  //负荷控制器PID积分环节限幅下限
  private Double gI_INTG_MIN1;
  
  //负荷控制器PID输出限幅环节的上限
  private Double gI_PID_MAX1;
  
  //负荷控制器PID输出限幅环节的下限
  private Double gI_PID_MIN1;
  
  //负荷前馈开关位置
  private Integer gI_I_Feed;
  
  //一次调频负荷
  private Double gI_W_MAX;
  
  //一次调频负荷
  private Double gI_W_MIN;
  
  //调节级压力自动开关
  private Integer gI_I2;
  
  //调节级压力控制器PID比例环节倍数
  private Double gI_KP2;
  
  //调节级压力控制器PID微分环节倍数
  private Double gI_KD2;
  
  //调节级压力控制器PID积分环节倍数
  private Double gI_KI2;
  
  //调节级压力控制器PID积分环节限幅上限
  private Double gI_INTG_MAX2;
  
  //调节级压力控制器PID积分环节限幅下限
  private Double gI_INTG_MIN2;
  
  //调节级压力控制器PID输出限幅环节的上限
  private Double gI_PID_MAX2;
  
  //调节级压力控制器PID输出限幅环节的下限
  private Double gI_PID_MIN2;
  
  //整个控制环节输出限幅环节的上限
  private Double gI_CON_MAX;
  
  //整个控制环节输出限幅环节的下限
  private Double gI_CON_MIN;
  
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
    
  public Double getGI_T1() 
  {
    return gI_T1;
  }
    
  public void setGI_T1(Double gI_T1)
  {
    this.gI_T1 = gI_T1;
  }
    
  public Double getGI_E() 
  {
    return gI_E;
  }
    
  public void setGI_E(Double gI_E)
  {
    this.gI_E = gI_E;
  }
    
  public Double getGI_K() 
  {
    return gI_K;
  }
    
  public void setGI_K(Double gI_K)
  {
    this.gI_K = gI_K;
  }
    
  public Integer getGI_I1() 
  {
    return gI_I1;
  }
    
  public void setGI_I1(Integer gI_I1)
  {
    this.gI_I1 = gI_I1;
  }
    
  public Double getGI_KP1() 
  {
    return gI_KP1;
  }
    
  public void setGI_KP1(Double gI_KP1)
  {
    this.gI_KP1 = gI_KP1;
  }
    
  public Double getGI_KD1() 
  {
    return gI_KD1;
  }
    
  public void setGI_KD1(Double gI_KD1)
  {
    this.gI_KD1 = gI_KD1;
  }
    
  public Double getGI_KI1() 
  {
    return gI_KI1;
  }
    
  public void setGI_KI1(Double gI_KI1)
  {
    this.gI_KI1 = gI_KI1;
  }
    
  public Double getGI_INTG_MAX1() 
  {
    return gI_INTG_MAX1;
  }
    
  public void setGI_INTG_MAX1(Double gI_INTG_MAX1)
  {
    this.gI_INTG_MAX1 = gI_INTG_MAX1;
  }
    
  public Double getGI_INTG_MIN1() 
  {
    return gI_INTG_MIN1;
  }
    
  public void setGI_INTG_MIN1(Double gI_INTG_MIN1)
  {
    this.gI_INTG_MIN1 = gI_INTG_MIN1;
  }
    
  public Double getGI_PID_MAX1() 
  {
    return gI_PID_MAX1;
  }
    
  public void setGI_PID_MAX1(Double gI_PID_MAX1)
  {
    this.gI_PID_MAX1 = gI_PID_MAX1;
  }
    
  public Double getGI_PID_MIN1() 
  {
    return gI_PID_MIN1;
  }
    
  public void setGI_PID_MIN1(Double gI_PID_MIN1)
  {
    this.gI_PID_MIN1 = gI_PID_MIN1;
  }
    
  public Integer getGI_I_Feed() 
  {
    return gI_I_Feed;
  }
    
  public void setGI_I_Feed(Integer gI_I_Feed)
  {
    this.gI_I_Feed = gI_I_Feed;
  }
    
  public Double getGI_W_MAX() 
  {
    return gI_W_MAX;
  }
    
  public void setGI_W_MAX(Double gI_W_MAX)
  {
    this.gI_W_MAX = gI_W_MAX;
  }
    
  public Double getGI_W_MIN() 
  {
    return gI_W_MIN;
  }
    
  public void setGI_W_MIN(Double gI_W_MIN)
  {
    this.gI_W_MIN = gI_W_MIN;
  }
    
  public Integer getGI_I2() 
  {
    return gI_I2;
  }
    
  public void setGI_I2(Integer gI_I2)
  {
    this.gI_I2 = gI_I2;
  }
    
  public Double getGI_KP2() 
  {
    return gI_KP2;
  }
    
  public void setGI_KP2(Double gI_KP2)
  {
    this.gI_KP2 = gI_KP2;
  }
    
  public Double getGI_KD2() 
  {
    return gI_KD2;
  }
    
  public void setGI_KD2(Double gI_KD2)
  {
    this.gI_KD2 = gI_KD2;
  }
    
  public Double getGI_KI2() 
  {
    return gI_KI2;
  }
    
  public void setGI_KI2(Double gI_KI2)
  {
    this.gI_KI2 = gI_KI2;
  }
    
  public Double getGI_INTG_MAX2() 
  {
    return gI_INTG_MAX2;
  }
    
  public void setGI_INTG_MAX2(Double gI_INTG_MAX2)
  {
    this.gI_INTG_MAX2 = gI_INTG_MAX2;
  }
    
  public Double getGI_INTG_MIN2() 
  {
    return gI_INTG_MIN2;
  }
    
  public void setGI_INTG_MIN2(Double gI_INTG_MIN2)
  {
    this.gI_INTG_MIN2 = gI_INTG_MIN2;
  }
    
  public Double getGI_PID_MAX2() 
  {
    return gI_PID_MAX2;
  }
    
  public void setGI_PID_MAX2(Double gI_PID_MAX2)
  {
    this.gI_PID_MAX2 = gI_PID_MAX2;
  }
    
  public Double getGI_PID_MIN2() 
  {
    return gI_PID_MIN2;
  }
    
  public void setGI_PID_MIN2(Double gI_PID_MIN2)
  {
    this.gI_PID_MIN2 = gI_PID_MIN2;
  }
    
  public Double getGI_CON_MAX() 
  {
    return gI_CON_MAX;
  }
    
  public void setGI_CON_MAX(Double gI_CON_MAX)
  {
    this.gI_CON_MAX = gI_CON_MAX;
  }
    
  public Double getGI_CON_MIN() 
  {
    return gI_CON_MIN;
  }
    
  public void setGI_CON_MIN(Double gI_CON_MIN)
  {
    this.gI_CON_MIN = gI_CON_MIN;
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
    
