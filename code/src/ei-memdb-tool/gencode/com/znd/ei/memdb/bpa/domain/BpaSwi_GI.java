package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*调节系统模型1表(GI)	*
***********************/
public class BpaSwi_GI  implements MemIndexable 
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
  
  //转速变换环节时间常数(秒)
  private Double GI_T1;
  
  //死区ε(相对系统频率的标么值)
  private Double GI_E;
  
  //转速偏差放大倍数
  private Double GI_K;
  
  //负荷自动开关
  private Integer GI_I1;
  
  //负荷控制器PID比例环节倍数
  private Double GI_KP1;
  
  //负荷控制器PID微分环节倍数
  private Double GI_KD1;
  
  //负荷控制器PID积分环节倍数
  private Double GI_KI1;
  
  //负荷控制器PID积分环节限幅上限
  private Double GI_INTG_MAX1;
  
  //负荷控制器PID积分环节限幅下限
  private Double GI_INTG_MIN1;
  
  //负荷控制器PID输出限幅环节的上限
  private Double GI_PID_MAX1;
  
  //负荷控制器PID输出限幅环节的下限
  private Double GI_PID_MIN1;
  
  //负荷前馈开关位置
  private Integer GI_I_Feed;
  
  //一次调频负荷
  private Double GI_W_MAX;
  
  //一次调频负荷
  private Double GI_W_MIN;
  
  //调节级压力自动开关
  private Integer GI_I2;
  
  //调节级压力控制器PID比例环节倍数
  private Double GI_KP2;
  
  //调节级压力控制器PID微分环节倍数
  private Double GI_KD2;
  
  //调节级压力控制器PID积分环节倍数
  private Double GI_KI2;
  
  //调节级压力控制器PID积分环节限幅上限
  private Double GI_INTG_MAX2;
  
  //调节级压力控制器PID积分环节限幅下限
  private Double GI_INTG_MIN2;
  
  //调节级压力控制器PID输出限幅环节的上限
  private Double GI_PID_MAX2;
  
  //调节级压力控制器PID输出限幅环节的下限
  private Double GI_PID_MIN2;
  
  //整个控制环节输出限幅环节的上限
  private Double GI_CON_MAX;
  
  //整个控制环节输出限幅环节的下限
  private Double GI_CON_MIN;
  
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
    
  public Double getGI_T1()
  {
    return GI_T1;
  }
    
  public void setGI_T1(Double GI_T1)
  {
    this.GI_T1 = GI_T1;
  }
    
  public Double getGI_E()
  {
    return GI_E;
  }
    
  public void setGI_E(Double GI_E)
  {
    this.GI_E = GI_E;
  }
    
  public Double getGI_K()
  {
    return GI_K;
  }
    
  public void setGI_K(Double GI_K)
  {
    this.GI_K = GI_K;
  }
    
  public Integer getGI_I1()
  {
    return GI_I1;
  }
    
  public void setGI_I1(Integer GI_I1)
  {
    this.GI_I1 = GI_I1;
  }
    
  public Double getGI_KP1()
  {
    return GI_KP1;
  }
    
  public void setGI_KP1(Double GI_KP1)
  {
    this.GI_KP1 = GI_KP1;
  }
    
  public Double getGI_KD1()
  {
    return GI_KD1;
  }
    
  public void setGI_KD1(Double GI_KD1)
  {
    this.GI_KD1 = GI_KD1;
  }
    
  public Double getGI_KI1()
  {
    return GI_KI1;
  }
    
  public void setGI_KI1(Double GI_KI1)
  {
    this.GI_KI1 = GI_KI1;
  }
    
  public Double getGI_INTG_MAX1()
  {
    return GI_INTG_MAX1;
  }
    
  public void setGI_INTG_MAX1(Double GI_INTG_MAX1)
  {
    this.GI_INTG_MAX1 = GI_INTG_MAX1;
  }
    
  public Double getGI_INTG_MIN1()
  {
    return GI_INTG_MIN1;
  }
    
  public void setGI_INTG_MIN1(Double GI_INTG_MIN1)
  {
    this.GI_INTG_MIN1 = GI_INTG_MIN1;
  }
    
  public Double getGI_PID_MAX1()
  {
    return GI_PID_MAX1;
  }
    
  public void setGI_PID_MAX1(Double GI_PID_MAX1)
  {
    this.GI_PID_MAX1 = GI_PID_MAX1;
  }
    
  public Double getGI_PID_MIN1()
  {
    return GI_PID_MIN1;
  }
    
  public void setGI_PID_MIN1(Double GI_PID_MIN1)
  {
    this.GI_PID_MIN1 = GI_PID_MIN1;
  }
    
  public Integer getGI_I_Feed()
  {
    return GI_I_Feed;
  }
    
  public void setGI_I_Feed(Integer GI_I_Feed)
  {
    this.GI_I_Feed = GI_I_Feed;
  }
    
  public Double getGI_W_MAX()
  {
    return GI_W_MAX;
  }
    
  public void setGI_W_MAX(Double GI_W_MAX)
  {
    this.GI_W_MAX = GI_W_MAX;
  }
    
  public Double getGI_W_MIN()
  {
    return GI_W_MIN;
  }
    
  public void setGI_W_MIN(Double GI_W_MIN)
  {
    this.GI_W_MIN = GI_W_MIN;
  }
    
  public Integer getGI_I2()
  {
    return GI_I2;
  }
    
  public void setGI_I2(Integer GI_I2)
  {
    this.GI_I2 = GI_I2;
  }
    
  public Double getGI_KP2()
  {
    return GI_KP2;
  }
    
  public void setGI_KP2(Double GI_KP2)
  {
    this.GI_KP2 = GI_KP2;
  }
    
  public Double getGI_KD2()
  {
    return GI_KD2;
  }
    
  public void setGI_KD2(Double GI_KD2)
  {
    this.GI_KD2 = GI_KD2;
  }
    
  public Double getGI_KI2()
  {
    return GI_KI2;
  }
    
  public void setGI_KI2(Double GI_KI2)
  {
    this.GI_KI2 = GI_KI2;
  }
    
  public Double getGI_INTG_MAX2()
  {
    return GI_INTG_MAX2;
  }
    
  public void setGI_INTG_MAX2(Double GI_INTG_MAX2)
  {
    this.GI_INTG_MAX2 = GI_INTG_MAX2;
  }
    
  public Double getGI_INTG_MIN2()
  {
    return GI_INTG_MIN2;
  }
    
  public void setGI_INTG_MIN2(Double GI_INTG_MIN2)
  {
    this.GI_INTG_MIN2 = GI_INTG_MIN2;
  }
    
  public Double getGI_PID_MAX2()
  {
    return GI_PID_MAX2;
  }
    
  public void setGI_PID_MAX2(Double GI_PID_MAX2)
  {
    this.GI_PID_MAX2 = GI_PID_MAX2;
  }
    
  public Double getGI_PID_MIN2()
  {
    return GI_PID_MIN2;
  }
    
  public void setGI_PID_MIN2(Double GI_PID_MIN2)
  {
    this.GI_PID_MIN2 = GI_PID_MIN2;
  }
    
  public Double getGI_CON_MAX()
  {
    return GI_CON_MAX;
  }
    
  public void setGI_CON_MAX(Double GI_CON_MAX)
  {
    this.GI_CON_MAX = GI_CON_MAX;
  }
    
  public Double getGI_CON_MIN()
  {
    return GI_CON_MIN;
  }
    
  public void setGI_CON_MIN(Double GI_CON_MIN)
  {
    this.GI_CON_MIN = GI_CON_MIN;
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
    return "BpaSwi_GI ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", GI_T1 = " + GI_T1
	 + ", GI_E = " + GI_E
	 + ", GI_K = " + GI_K
	 + ", GI_I1 = " + GI_I1
	 + ", GI_KP1 = " + GI_KP1
	 + ", GI_KD1 = " + GI_KD1
	 + ", GI_KI1 = " + GI_KI1
	 + ", GI_INTG_MAX1 = " + GI_INTG_MAX1
	 + ", GI_INTG_MIN1 = " + GI_INTG_MIN1
	 + ", GI_PID_MAX1 = " + GI_PID_MAX1
	 + ", GI_PID_MIN1 = " + GI_PID_MIN1
	 + ", GI_I_Feed = " + GI_I_Feed
	 + ", GI_W_MAX = " + GI_W_MAX
	 + ", GI_W_MIN = " + GI_W_MIN
	 + ", GI_I2 = " + GI_I2
	 + ", GI_KP2 = " + GI_KP2
	 + ", GI_KD2 = " + GI_KD2
	 + ", GI_KI2 = " + GI_KI2
	 + ", GI_INTG_MAX2 = " + GI_INTG_MAX2
	 + ", GI_INTG_MIN2 = " + GI_INTG_MIN2
	 + ", GI_PID_MAX2 = " + GI_PID_MAX2
	 + ", GI_PID_MIN2 = " + GI_PID_MIN2
	 + ", GI_CON_MAX = " + GI_CON_MAX
	 + ", GI_CON_MIN = " + GI_CON_MIN
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
