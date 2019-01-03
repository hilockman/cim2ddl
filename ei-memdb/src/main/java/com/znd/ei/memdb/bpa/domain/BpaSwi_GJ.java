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
  private String CardKey;
  
  //发电机名称
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //转速测量环节时间常数(秒)
  private Double GJ_T1;
  
  //转速偏差死区
  private Double GJ_E;
  
  //转速偏差放大倍数
  private Double GJ_K1;
  
  //控制方式选择
  private Integer GJ_I;
  
  //PID比例环节倍数
  private Double GJ_KP;
  
  //PID微分环节倍数
  private Double GJ_KD;
  
  //PID积分环节倍数
  private Double GJ_KI;
  
  //PID积分环节限幅上限
  private Double GJ_INTG_MAX;
  
  //PID积分环节限幅下限
  private Double GJ_INTG_MIN;
  
  //PID输出限幅环节的上限
  private Double GJ_PID_MAX;
  
  //PID输出限幅环节的下限
  private Double GJ_PID_MIN;
  
  //负荷控制前馈系数
  private Double GJ_K2;
  
  //一次调频负荷上限
  private Double GJ_W_MAX;
  
  //一次调频负荷下限
  private Double GJ_W_MIN;
  
  //频率输入信号的纯时迟(秒)
  private Double GJ_TW_DELAY;
  
  //功率反馈信号的纯时迟(秒)
  private Double GJ_TP_DELAY;
  
  //功率反馈信号对应的一阶惯性环节时间常数(秒)
  private Double GJ_TR;
  
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
    
  public Double getGJ_T1()
  {
    return GJ_T1;
  }
    
  public void setGJ_T1(Double GJ_T1)
  {
    this.GJ_T1 = GJ_T1;
  }
    
  public Double getGJ_E()
  {
    return GJ_E;
  }
    
  public void setGJ_E(Double GJ_E)
  {
    this.GJ_E = GJ_E;
  }
    
  public Double getGJ_K1()
  {
    return GJ_K1;
  }
    
  public void setGJ_K1(Double GJ_K1)
  {
    this.GJ_K1 = GJ_K1;
  }
    
  public Integer getGJ_I()
  {
    return GJ_I;
  }
    
  public void setGJ_I(Integer GJ_I)
  {
    this.GJ_I = GJ_I;
  }
    
  public Double getGJ_KP()
  {
    return GJ_KP;
  }
    
  public void setGJ_KP(Double GJ_KP)
  {
    this.GJ_KP = GJ_KP;
  }
    
  public Double getGJ_KD()
  {
    return GJ_KD;
  }
    
  public void setGJ_KD(Double GJ_KD)
  {
    this.GJ_KD = GJ_KD;
  }
    
  public Double getGJ_KI()
  {
    return GJ_KI;
  }
    
  public void setGJ_KI(Double GJ_KI)
  {
    this.GJ_KI = GJ_KI;
  }
    
  public Double getGJ_INTG_MAX()
  {
    return GJ_INTG_MAX;
  }
    
  public void setGJ_INTG_MAX(Double GJ_INTG_MAX)
  {
    this.GJ_INTG_MAX = GJ_INTG_MAX;
  }
    
  public Double getGJ_INTG_MIN()
  {
    return GJ_INTG_MIN;
  }
    
  public void setGJ_INTG_MIN(Double GJ_INTG_MIN)
  {
    this.GJ_INTG_MIN = GJ_INTG_MIN;
  }
    
  public Double getGJ_PID_MAX()
  {
    return GJ_PID_MAX;
  }
    
  public void setGJ_PID_MAX(Double GJ_PID_MAX)
  {
    this.GJ_PID_MAX = GJ_PID_MAX;
  }
    
  public Double getGJ_PID_MIN()
  {
    return GJ_PID_MIN;
  }
    
  public void setGJ_PID_MIN(Double GJ_PID_MIN)
  {
    this.GJ_PID_MIN = GJ_PID_MIN;
  }
    
  public Double getGJ_K2()
  {
    return GJ_K2;
  }
    
  public void setGJ_K2(Double GJ_K2)
  {
    this.GJ_K2 = GJ_K2;
  }
    
  public Double getGJ_W_MAX()
  {
    return GJ_W_MAX;
  }
    
  public void setGJ_W_MAX(Double GJ_W_MAX)
  {
    this.GJ_W_MAX = GJ_W_MAX;
  }
    
  public Double getGJ_W_MIN()
  {
    return GJ_W_MIN;
  }
    
  public void setGJ_W_MIN(Double GJ_W_MIN)
  {
    this.GJ_W_MIN = GJ_W_MIN;
  }
    
  public Double getGJ_TW_DELAY()
  {
    return GJ_TW_DELAY;
  }
    
  public void setGJ_TW_DELAY(Double GJ_TW_DELAY)
  {
    this.GJ_TW_DELAY = GJ_TW_DELAY;
  }
    
  public Double getGJ_TP_DELAY()
  {
    return GJ_TP_DELAY;
  }
    
  public void setGJ_TP_DELAY(Double GJ_TP_DELAY)
  {
    this.GJ_TP_DELAY = GJ_TP_DELAY;
  }
    
  public Double getGJ_TR()
  {
    return GJ_TR;
  }
    
  public void setGJ_TR(Double GJ_TR)
  {
    this.GJ_TR = GJ_TR;
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
    return "BpaSwi_GJ ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", GJ_T1 = " + GJ_T1
	 + ", GJ_E = " + GJ_E
	 + ", GJ_K1 = " + GJ_K1
	 + ", GJ_I = " + GJ_I
	 + ", GJ_KP = " + GJ_KP
	 + ", GJ_KD = " + GJ_KD
	 + ", GJ_KI = " + GJ_KI
	 + ", GJ_INTG_MAX = " + GJ_INTG_MAX
	 + ", GJ_INTG_MIN = " + GJ_INTG_MIN
	 + ", GJ_PID_MAX = " + GJ_PID_MAX
	 + ", GJ_PID_MIN = " + GJ_PID_MIN
	 + ", GJ_K2 = " + GJ_K2
	 + ", GJ_W_MAX = " + GJ_W_MAX
	 + ", GJ_W_MIN = " + GJ_W_MIN
	 + ", GJ_TW_DELAY = " + GJ_TW_DELAY
	 + ", GJ_TP_DELAY = " + GJ_TP_DELAY
	 + ", GJ_TR = " + GJ_TR
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
