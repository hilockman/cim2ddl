package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*电液伺服系统模型表(GA)	*
***********************/
@Entity
public class BpaSwi_GA
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
  
  //原动机额定输出功率(MW)
  private Double gA_Pe;
  
  //油动机关闭时间常数
  private Double gA_Tc;
  
  //油动机开启时间常数
  private Double gA_To;
  
  //过速关闭系数(pu)
  private Double gA_VELclose;
  
  //过速开启系数(pu)
  private Double gA_VELopen;
  
  //最大原动机输出功率(pu)
  private Double gen_Pmax;
  
  //最小原动机输出功率(pu)
  private Double gen_Pmin;
  
  //油动机行程反馈环节(LVDT)时间
  private Double gA_T1;
  
  //比例放大倍数
  private Double gA_KP;
  
  //微分倍数
  private Double gA_KD;
  
  //积分倍数
  private Double gA_KI;
  
  //积分上限
  private Double gA_INTG_MAX;
  
  //积分下限
  private Double gA_INTG_MIN;
  
  //输出上限
  private Double gA_PID_MAX;
  
  //输出下限
  private Double gA_PID_MIN;
  
  //功率输出信号的纯时迟(秒)
  private Double gA_PGV_DELAY;
  
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
    
  public Double getGA_Pe() 
  {
    return gA_Pe;
  }
    
  public void setGA_Pe(Double gA_Pe)
  {
    this.gA_Pe = gA_Pe;
  }
    
  public Double getGA_Tc() 
  {
    return gA_Tc;
  }
    
  public void setGA_Tc(Double gA_Tc)
  {
    this.gA_Tc = gA_Tc;
  }
    
  public Double getGA_To() 
  {
    return gA_To;
  }
    
  public void setGA_To(Double gA_To)
  {
    this.gA_To = gA_To;
  }
    
  public Double getGA_VELclose() 
  {
    return gA_VELclose;
  }
    
  public void setGA_VELclose(Double gA_VELclose)
  {
    this.gA_VELclose = gA_VELclose;
  }
    
  public Double getGA_VELopen() 
  {
    return gA_VELopen;
  }
    
  public void setGA_VELopen(Double gA_VELopen)
  {
    this.gA_VELopen = gA_VELopen;
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
    
  public Double getGA_T1() 
  {
    return gA_T1;
  }
    
  public void setGA_T1(Double gA_T1)
  {
    this.gA_T1 = gA_T1;
  }
    
  public Double getGA_KP() 
  {
    return gA_KP;
  }
    
  public void setGA_KP(Double gA_KP)
  {
    this.gA_KP = gA_KP;
  }
    
  public Double getGA_KD() 
  {
    return gA_KD;
  }
    
  public void setGA_KD(Double gA_KD)
  {
    this.gA_KD = gA_KD;
  }
    
  public Double getGA_KI() 
  {
    return gA_KI;
  }
    
  public void setGA_KI(Double gA_KI)
  {
    this.gA_KI = gA_KI;
  }
    
  public Double getGA_INTG_MAX() 
  {
    return gA_INTG_MAX;
  }
    
  public void setGA_INTG_MAX(Double gA_INTG_MAX)
  {
    this.gA_INTG_MAX = gA_INTG_MAX;
  }
    
  public Double getGA_INTG_MIN() 
  {
    return gA_INTG_MIN;
  }
    
  public void setGA_INTG_MIN(Double gA_INTG_MIN)
  {
    this.gA_INTG_MIN = gA_INTG_MIN;
  }
    
  public Double getGA_PID_MAX() 
  {
    return gA_PID_MAX;
  }
    
  public void setGA_PID_MAX(Double gA_PID_MAX)
  {
    this.gA_PID_MAX = gA_PID_MAX;
  }
    
  public Double getGA_PID_MIN() 
  {
    return gA_PID_MIN;
  }
    
  public void setGA_PID_MIN(Double gA_PID_MIN)
  {
    this.gA_PID_MIN = gA_PID_MIN;
  }
    
  public Double getGA_PGV_DELAY() 
  {
    return gA_PGV_DELAY;
  }
    
  public void setGA_PGV_DELAY(Double gA_PGV_DELAY)
  {
    this.gA_PGV_DELAY = gA_PGV_DELAY;
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
    
