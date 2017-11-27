package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电液伺服系统模型表(GA)	*
***********************/
public class BpaSwi_GA  implements MemIndexable 
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
  
  //原动机额定输出功率(MW)
  private Double GA_Pe;
  
  //油动机关闭时间常数
  private Double GA_Tc;
  
  //油动机开启时间常数
  private Double GA_To;
  
  //过速关闭系数(pu)
  private Double GA_VELclose;
  
  //过速开启系数(pu)
  private Double GA_VELopen;
  
  //最大原动机输出功率(pu)
  private Double Gen_Pmax;
  
  //最小原动机输出功率(pu)
  private Double Gen_Pmin;
  
  //油动机行程反馈环节(LVDT)时间
  private Double GA_T1;
  
  //比例放大倍数
  private Double GA_KP;
  
  //微分倍数
  private Double GA_KD;
  
  //积分倍数
  private Double GA_KI;
  
  //积分上限
  private Double GA_INTG_MAX;
  
  //积分下限
  private Double GA_INTG_MIN;
  
  //输出上限
  private Double GA_PID_MAX;
  
  //输出下限
  private Double GA_PID_MIN;
  
  //功率输出信号的纯时迟(秒)
  private Double GA_PGV_DELAY;
  
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
    
  public Double getGA_Pe()
  {
    return GA_Pe;
  }
    
  public void setGA_Pe(Double GA_Pe)
  {
    this.GA_Pe = GA_Pe;
  }
    
  public Double getGA_Tc()
  {
    return GA_Tc;
  }
    
  public void setGA_Tc(Double GA_Tc)
  {
    this.GA_Tc = GA_Tc;
  }
    
  public Double getGA_To()
  {
    return GA_To;
  }
    
  public void setGA_To(Double GA_To)
  {
    this.GA_To = GA_To;
  }
    
  public Double getGA_VELclose()
  {
    return GA_VELclose;
  }
    
  public void setGA_VELclose(Double GA_VELclose)
  {
    this.GA_VELclose = GA_VELclose;
  }
    
  public Double getGA_VELopen()
  {
    return GA_VELopen;
  }
    
  public void setGA_VELopen(Double GA_VELopen)
  {
    this.GA_VELopen = GA_VELopen;
  }
    
  public Double getGen_Pmax()
  {
    return Gen_Pmax;
  }
    
  public void setGen_Pmax(Double Gen_Pmax)
  {
    this.Gen_Pmax = Gen_Pmax;
  }
    
  public Double getGen_Pmin()
  {
    return Gen_Pmin;
  }
    
  public void setGen_Pmin(Double Gen_Pmin)
  {
    this.Gen_Pmin = Gen_Pmin;
  }
    
  public Double getGA_T1()
  {
    return GA_T1;
  }
    
  public void setGA_T1(Double GA_T1)
  {
    this.GA_T1 = GA_T1;
  }
    
  public Double getGA_KP()
  {
    return GA_KP;
  }
    
  public void setGA_KP(Double GA_KP)
  {
    this.GA_KP = GA_KP;
  }
    
  public Double getGA_KD()
  {
    return GA_KD;
  }
    
  public void setGA_KD(Double GA_KD)
  {
    this.GA_KD = GA_KD;
  }
    
  public Double getGA_KI()
  {
    return GA_KI;
  }
    
  public void setGA_KI(Double GA_KI)
  {
    this.GA_KI = GA_KI;
  }
    
  public Double getGA_INTG_MAX()
  {
    return GA_INTG_MAX;
  }
    
  public void setGA_INTG_MAX(Double GA_INTG_MAX)
  {
    this.GA_INTG_MAX = GA_INTG_MAX;
  }
    
  public Double getGA_INTG_MIN()
  {
    return GA_INTG_MIN;
  }
    
  public void setGA_INTG_MIN(Double GA_INTG_MIN)
  {
    this.GA_INTG_MIN = GA_INTG_MIN;
  }
    
  public Double getGA_PID_MAX()
  {
    return GA_PID_MAX;
  }
    
  public void setGA_PID_MAX(Double GA_PID_MAX)
  {
    this.GA_PID_MAX = GA_PID_MAX;
  }
    
  public Double getGA_PID_MIN()
  {
    return GA_PID_MIN;
  }
    
  public void setGA_PID_MIN(Double GA_PID_MIN)
  {
    this.GA_PID_MIN = GA_PID_MIN;
  }
    
  public Double getGA_PGV_DELAY()
  {
    return GA_PGV_DELAY;
  }
    
  public void setGA_PGV_DELAY(Double GA_PGV_DELAY)
  {
    this.GA_PGV_DELAY = GA_PGV_DELAY;
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
    return "BpaSwi_GA ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", GA_Pe = " + GA_Pe
	 + ", GA_Tc = " + GA_Tc
	 + ", GA_To = " + GA_To
	 + ", GA_VELclose = " + GA_VELclose
	 + ", GA_VELopen = " + GA_VELopen
	 + ", Gen_Pmax = " + Gen_Pmax
	 + ", Gen_Pmin = " + Gen_Pmin
	 + ", GA_T1 = " + GA_T1
	 + ", GA_KP = " + GA_KP
	 + ", GA_KD = " + GA_KD
	 + ", GA_KI = " + GA_KI
	 + ", GA_INTG_MAX = " + GA_INTG_MAX
	 + ", GA_INTG_MIN = " + GA_INTG_MIN
	 + ", GA_PID_MAX = " + GA_PID_MAX
	 + ", GA_PID_MIN = " + GA_PID_MIN
	 + ", GA_PGV_DELAY = " + GA_PGV_DELAY
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
