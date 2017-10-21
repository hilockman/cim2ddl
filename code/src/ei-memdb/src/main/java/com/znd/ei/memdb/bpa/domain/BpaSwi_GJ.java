package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*调节系统模型2表(GJ)	*
***********************/
public class BpaSwi_GJ  implements MemIndexable 
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
  
  //转速测量环节时间常数(秒)
  private Double gJ_T1;
  
  //转速偏差死区
  private Double gJ_E;
  
  //转速偏差放大倍数
  private Double gJ_K1;
  
  //控制方式选择
  private Integer gJ_I;
  
  //PID比例环节倍数
  private Double gJ_KP;
  
  //PID微分环节倍数
  private Double gJ_KD;
  
  //PID积分环节倍数
  private Double gJ_KI;
  
  //PID积分环节限幅上限
  private Double gJ_INTG_MAX;
  
  //PID积分环节限幅下限
  private Double gJ_INTG_MIN;
  
  //PID输出限幅环节的上限
  private Double gJ_PID_MAX;
  
  //PID输出限幅环节的下限
  private Double gJ_PID_MIN;
  
  //负荷控制前馈系数
  private Double gJ_K2;
  
  //一次调频负荷上限
  private Double gJ_W_MAX;
  
  //一次调频负荷下限
  private Double gJ_W_MIN;
  
  //频率输入信号的纯时迟(秒)
  private Double gJ_TW_DELAY;
  
  //功率反馈信号的纯时迟(秒)
  private Double gJ_TP_DELAY;
  
  //功率反馈信号对应的一阶惯性环节时间常数(秒)
  private Double gJ_TR;
  
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
    
  public Double getGJ_T1()
  {
    return gJ_T1;
  }
    
  public void setGJ_T1(Double gJ_T1)
  {
    this.gJ_T1 = gJ_T1;
  }
    
  public Double getGJ_E()
  {
    return gJ_E;
  }
    
  public void setGJ_E(Double gJ_E)
  {
    this.gJ_E = gJ_E;
  }
    
  public Double getGJ_K1()
  {
    return gJ_K1;
  }
    
  public void setGJ_K1(Double gJ_K1)
  {
    this.gJ_K1 = gJ_K1;
  }
    
  public Integer getGJ_I()
  {
    return gJ_I;
  }
    
  public void setGJ_I(Integer gJ_I)
  {
    this.gJ_I = gJ_I;
  }
    
  public Double getGJ_KP()
  {
    return gJ_KP;
  }
    
  public void setGJ_KP(Double gJ_KP)
  {
    this.gJ_KP = gJ_KP;
  }
    
  public Double getGJ_KD()
  {
    return gJ_KD;
  }
    
  public void setGJ_KD(Double gJ_KD)
  {
    this.gJ_KD = gJ_KD;
  }
    
  public Double getGJ_KI()
  {
    return gJ_KI;
  }
    
  public void setGJ_KI(Double gJ_KI)
  {
    this.gJ_KI = gJ_KI;
  }
    
  public Double getGJ_INTG_MAX()
  {
    return gJ_INTG_MAX;
  }
    
  public void setGJ_INTG_MAX(Double gJ_INTG_MAX)
  {
    this.gJ_INTG_MAX = gJ_INTG_MAX;
  }
    
  public Double getGJ_INTG_MIN()
  {
    return gJ_INTG_MIN;
  }
    
  public void setGJ_INTG_MIN(Double gJ_INTG_MIN)
  {
    this.gJ_INTG_MIN = gJ_INTG_MIN;
  }
    
  public Double getGJ_PID_MAX()
  {
    return gJ_PID_MAX;
  }
    
  public void setGJ_PID_MAX(Double gJ_PID_MAX)
  {
    this.gJ_PID_MAX = gJ_PID_MAX;
  }
    
  public Double getGJ_PID_MIN()
  {
    return gJ_PID_MIN;
  }
    
  public void setGJ_PID_MIN(Double gJ_PID_MIN)
  {
    this.gJ_PID_MIN = gJ_PID_MIN;
  }
    
  public Double getGJ_K2()
  {
    return gJ_K2;
  }
    
  public void setGJ_K2(Double gJ_K2)
  {
    this.gJ_K2 = gJ_K2;
  }
    
  public Double getGJ_W_MAX()
  {
    return gJ_W_MAX;
  }
    
  public void setGJ_W_MAX(Double gJ_W_MAX)
  {
    this.gJ_W_MAX = gJ_W_MAX;
  }
    
  public Double getGJ_W_MIN()
  {
    return gJ_W_MIN;
  }
    
  public void setGJ_W_MIN(Double gJ_W_MIN)
  {
    this.gJ_W_MIN = gJ_W_MIN;
  }
    
  public Double getGJ_TW_DELAY()
  {
    return gJ_TW_DELAY;
  }
    
  public void setGJ_TW_DELAY(Double gJ_TW_DELAY)
  {
    this.gJ_TW_DELAY = gJ_TW_DELAY;
  }
    
  public Double getGJ_TP_DELAY()
  {
    return gJ_TP_DELAY;
  }
    
  public void setGJ_TP_DELAY(Double gJ_TP_DELAY)
  {
    this.gJ_TP_DELAY = gJ_TP_DELAY;
  }
    
  public Double getGJ_TR()
  {
    return gJ_TR;
  }
    
  public void setGJ_TR(Double gJ_TR)
  {
    this.gJ_TR = gJ_TR;
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
    return "BpaSwi_GJ ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", gJ_T1 = " + gJ_T1
	 + ", gJ_E = " + gJ_E
	 + ", gJ_K1 = " + gJ_K1
	 + ", gJ_I = " + gJ_I
	 + ", gJ_KP = " + gJ_KP
	 + ", gJ_KD = " + gJ_KD
	 + ", gJ_KI = " + gJ_KI
	 + ", gJ_INTG_MAX = " + gJ_INTG_MAX
	 + ", gJ_INTG_MIN = " + gJ_INTG_MIN
	 + ", gJ_PID_MAX = " + gJ_PID_MAX
	 + ", gJ_PID_MIN = " + gJ_PID_MIN
	 + ", gJ_K2 = " + gJ_K2
	 + ", gJ_W_MAX = " + gJ_W_MAX
	 + ", gJ_W_MIN = " + gJ_W_MIN
	 + ", gJ_TW_DELAY = " + gJ_TW_DELAY
	 + ", gJ_TP_DELAY = " + gJ_TP_DELAY
	 + ", gJ_TR = " + gJ_TR
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
