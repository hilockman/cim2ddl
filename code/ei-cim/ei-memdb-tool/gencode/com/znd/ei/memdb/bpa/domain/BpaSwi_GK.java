package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*调节系统模型3表(GK)	*
***********************/
public class BpaSwi_GK  implements MemIndexable 
{
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
  
  //转速偏差滤波器的时间常数(秒)
  private Double gK_TW;
  
  //转速偏差死区
  private Double gK_E;
  
  //转速采用滤波器或死区方式选择
  private Integer gK_I;
  
  //转速偏差放大倍数
  private Double gK_K1;
  
  //主汽压力偏差放大倍数
  private Double gK_K2;
  
  //控制方式选择	
  private Integer gK_I_Control;
  
  //PID比例环节倍数
  private Double gK_KP;
  
  //PID微分环节倍数
  private Double gK_KD;
  
  //PID积分环节倍数
  private Double gK_KI;
  
  //PID积分环节限幅上限
  private Double gK_INTG_MAX;
  
  //PID积分环节限幅下限
  private Double gK_INTG_MIN;
  
  //PID输出限幅环节的上限
  private Double gK_PID_MAX;
  
  //PID输出限幅环节的下限
  private Double gK_PID_MIN;
  
  //一次调频负荷上限
  private Double gK_W_MAX;
  
  //一次调频负荷下限
  private Double gK_W_MIN;
  
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
    
  public Double getGK_TW()
  {
    return gK_TW;
  }
    
  public void setGK_TW(Double gK_TW)
  {
    this.gK_TW = gK_TW;
  }
    
  public Double getGK_E()
  {
    return gK_E;
  }
    
  public void setGK_E(Double gK_E)
  {
    this.gK_E = gK_E;
  }
    
  public Integer getGK_I()
  {
    return gK_I;
  }
    
  public void setGK_I(Integer gK_I)
  {
    this.gK_I = gK_I;
  }
    
  public Double getGK_K1()
  {
    return gK_K1;
  }
    
  public void setGK_K1(Double gK_K1)
  {
    this.gK_K1 = gK_K1;
  }
    
  public Double getGK_K2()
  {
    return gK_K2;
  }
    
  public void setGK_K2(Double gK_K2)
  {
    this.gK_K2 = gK_K2;
  }
    
  public Integer getGK_I_Control()
  {
    return gK_I_Control;
  }
    
  public void setGK_I_Control(Integer gK_I_Control)
  {
    this.gK_I_Control = gK_I_Control;
  }
    
  public Double getGK_KP()
  {
    return gK_KP;
  }
    
  public void setGK_KP(Double gK_KP)
  {
    this.gK_KP = gK_KP;
  }
    
  public Double getGK_KD()
  {
    return gK_KD;
  }
    
  public void setGK_KD(Double gK_KD)
  {
    this.gK_KD = gK_KD;
  }
    
  public Double getGK_KI()
  {
    return gK_KI;
  }
    
  public void setGK_KI(Double gK_KI)
  {
    this.gK_KI = gK_KI;
  }
    
  public Double getGK_INTG_MAX()
  {
    return gK_INTG_MAX;
  }
    
  public void setGK_INTG_MAX(Double gK_INTG_MAX)
  {
    this.gK_INTG_MAX = gK_INTG_MAX;
  }
    
  public Double getGK_INTG_MIN()
  {
    return gK_INTG_MIN;
  }
    
  public void setGK_INTG_MIN(Double gK_INTG_MIN)
  {
    this.gK_INTG_MIN = gK_INTG_MIN;
  }
    
  public Double getGK_PID_MAX()
  {
    return gK_PID_MAX;
  }
    
  public void setGK_PID_MAX(Double gK_PID_MAX)
  {
    this.gK_PID_MAX = gK_PID_MAX;
  }
    
  public Double getGK_PID_MIN()
  {
    return gK_PID_MIN;
  }
    
  public void setGK_PID_MIN(Double gK_PID_MIN)
  {
    this.gK_PID_MIN = gK_PID_MIN;
  }
    
  public Double getGK_W_MAX()
  {
    return gK_W_MAX;
  }
    
  public void setGK_W_MAX(Double gK_W_MAX)
  {
    this.gK_W_MAX = gK_W_MAX;
  }
    
  public Double getGK_W_MIN()
  {
    return gK_W_MIN;
  }
    
  public void setGK_W_MIN(Double gK_W_MIN)
  {
    this.gK_W_MIN = gK_W_MIN;
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
    
  public String toString()
  {
    return "BpaSwi_GK ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", gK_TW = " + gK_TW
	 + ", gK_E = " + gK_E
	 + ", gK_I = " + gK_I
	 + ", gK_K1 = " + gK_K1
	 + ", gK_K2 = " + gK_K2
	 + ", gK_I_Control = " + gK_I_Control
	 + ", gK_KP = " + gK_KP
	 + ", gK_KD = " + gK_KD
	 + ", gK_KI = " + gK_KI
	 + ", gK_INTG_MAX = " + gK_INTG_MAX
	 + ", gK_INTG_MIN = " + gK_INTG_MIN
	 + ", gK_PID_MAX = " + gK_PID_MAX
	 + ", gK_PID_MIN = " + gK_PID_MIN
	 + ", gK_W_MAX = " + gK_W_MAX
	 + ", gK_W_MIN = " + gK_W_MIN
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
