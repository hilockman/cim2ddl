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
  private String CardKey;
  
  //发电机名称
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //转速偏差滤波器的时间常数(秒)
  private Double GK_TW;
  
  //转速偏差死区
  private Double GK_E;
  
  //转速采用滤波器或死区方式选择
  private Integer GK_I;
  
  //转速偏差放大倍数
  private Double GK_K1;
  
  //主汽压力偏差放大倍数
  private Double GK_K2;
  
  //控制方式选择	
  private Integer GK_I_Control;
  
  //PID比例环节倍数
  private Double GK_KP;
  
  //PID微分环节倍数
  private Double GK_KD;
  
  //PID积分环节倍数
  private Double GK_KI;
  
  //PID积分环节限幅上限
  private Double GK_INTG_MAX;
  
  //PID积分环节限幅下限
  private Double GK_INTG_MIN;
  
  //PID输出限幅环节的上限
  private Double GK_PID_MAX;
  
  //PID输出限幅环节的下限
  private Double GK_PID_MIN;
  
  //一次调频负荷上限
  private Double GK_W_MAX;
  
  //一次调频负荷下限
  private Double GK_W_MIN;
  
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
    
  public Double getGK_TW()
  {
    return GK_TW;
  }
    
  public void setGK_TW(Double GK_TW)
  {
    this.GK_TW = GK_TW;
  }
    
  public Double getGK_E()
  {
    return GK_E;
  }
    
  public void setGK_E(Double GK_E)
  {
    this.GK_E = GK_E;
  }
    
  public Integer getGK_I()
  {
    return GK_I;
  }
    
  public void setGK_I(Integer GK_I)
  {
    this.GK_I = GK_I;
  }
    
  public Double getGK_K1()
  {
    return GK_K1;
  }
    
  public void setGK_K1(Double GK_K1)
  {
    this.GK_K1 = GK_K1;
  }
    
  public Double getGK_K2()
  {
    return GK_K2;
  }
    
  public void setGK_K2(Double GK_K2)
  {
    this.GK_K2 = GK_K2;
  }
    
  public Integer getGK_I_Control()
  {
    return GK_I_Control;
  }
    
  public void setGK_I_Control(Integer GK_I_Control)
  {
    this.GK_I_Control = GK_I_Control;
  }
    
  public Double getGK_KP()
  {
    return GK_KP;
  }
    
  public void setGK_KP(Double GK_KP)
  {
    this.GK_KP = GK_KP;
  }
    
  public Double getGK_KD()
  {
    return GK_KD;
  }
    
  public void setGK_KD(Double GK_KD)
  {
    this.GK_KD = GK_KD;
  }
    
  public Double getGK_KI()
  {
    return GK_KI;
  }
    
  public void setGK_KI(Double GK_KI)
  {
    this.GK_KI = GK_KI;
  }
    
  public Double getGK_INTG_MAX()
  {
    return GK_INTG_MAX;
  }
    
  public void setGK_INTG_MAX(Double GK_INTG_MAX)
  {
    this.GK_INTG_MAX = GK_INTG_MAX;
  }
    
  public Double getGK_INTG_MIN()
  {
    return GK_INTG_MIN;
  }
    
  public void setGK_INTG_MIN(Double GK_INTG_MIN)
  {
    this.GK_INTG_MIN = GK_INTG_MIN;
  }
    
  public Double getGK_PID_MAX()
  {
    return GK_PID_MAX;
  }
    
  public void setGK_PID_MAX(Double GK_PID_MAX)
  {
    this.GK_PID_MAX = GK_PID_MAX;
  }
    
  public Double getGK_PID_MIN()
  {
    return GK_PID_MIN;
  }
    
  public void setGK_PID_MIN(Double GK_PID_MIN)
  {
    this.GK_PID_MIN = GK_PID_MIN;
  }
    
  public Double getGK_W_MAX()
  {
    return GK_W_MAX;
  }
    
  public void setGK_W_MAX(Double GK_W_MAX)
  {
    this.GK_W_MAX = GK_W_MAX;
  }
    
  public Double getGK_W_MIN()
  {
    return GK_W_MIN;
  }
    
  public void setGK_W_MIN(Double GK_W_MIN)
  {
    this.GK_W_MIN = GK_W_MIN;
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
    return "BpaSwi_GK ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", GK_TW = " + GK_TW
	 + ", GK_E = " + GK_E
	 + ", GK_I = " + GK_I
	 + ", GK_K1 = " + GK_K1
	 + ", GK_K2 = " + GK_K2
	 + ", GK_I_Control = " + GK_I_Control
	 + ", GK_KP = " + GK_KP
	 + ", GK_KD = " + GK_KD
	 + ", GK_KI = " + GK_KI
	 + ", GK_INTG_MAX = " + GK_INTG_MAX
	 + ", GK_INTG_MIN = " + GK_INTG_MIN
	 + ", GK_PID_MAX = " + GK_PID_MAX
	 + ", GK_PID_MIN = " + GK_PID_MIN
	 + ", GK_W_MAX = " + GK_W_MAX
	 + ", GK_W_MIN = " + GK_W_MIN
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
