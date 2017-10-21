package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*直流线路表(DCLine)	*
***********************/
public class BpaDat_DCLine  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //所有者
  private String dCLine_Owner;
  
  //整流侧母线名称
  private String dCLine_BusR;
  
  //整流侧基准电压(kV)
  private Double dCLine_kVR;
  
  //区域联络线测点标志
  private Integer dCLine_Meter;
  
  //逆变侧母线名称
  private String dCLine_BusI;
  
  //逆变侧基准电压(kV)
  private Double dCLine_kVI;
  
  //直流线路额定电流(安培)
  private Double dCLine_AMP;
  
  //直流线路电阻(欧姆)
  private Double dCLine_R;
  
  //直流线路电感(毫亨)
  private Double dCLine_L;
  
  //直流线路电容(微阀)
  private Double dCLine_C;
  
  //所安排的直流功率的控制点
  private Integer dCLine_CONTROL;
  
  //所安排的直流功率(MW)
  private Double dCLine_DCPOWER;
  
  //给定直流线路整流侧的直流电压(kV)
  private Double dCLine_RVOLT;
  
  //整流侧的正常触发角(度)
  private Double dCLine_ROPER;
  
  //逆变侧的正常关断角(度)
  private Double dCLine_ISTOP;
  
  //线路整流侧功率(MW)
  private Double dCLine_Pr;
  
  //线路逆变侧功率(MW)
  private Double dCLine_Pi;
  
  //线路有功损耗(MW)
  private Double dCLine_Lossp;
  
  //直流线路名称
  private String keyName;
  
  //直流线路整流侧母线索引
  private Integer iRBus;
  
  //直流线路逆变侧母线索引
  private Integer iIBus;
  
  //直流线路别名
  private String alias;
  
  //状态
  private Integer status;
  
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
    
  public String getDCLine_Owner()
  {
    return dCLine_Owner;
  }
    
  public void setDCLine_Owner(String dCLine_Owner)
  {
    this.dCLine_Owner = dCLine_Owner;
  }
    
  public String getDCLine_BusR()
  {
    return dCLine_BusR;
  }
    
  public void setDCLine_BusR(String dCLine_BusR)
  {
    this.dCLine_BusR = dCLine_BusR;
  }
    
  public Double getDCLine_kVR()
  {
    return dCLine_kVR;
  }
    
  public void setDCLine_kVR(Double dCLine_kVR)
  {
    this.dCLine_kVR = dCLine_kVR;
  }
    
  public Integer getDCLine_Meter()
  {
    return dCLine_Meter;
  }
    
  public void setDCLine_Meter(Integer dCLine_Meter)
  {
    this.dCLine_Meter = dCLine_Meter;
  }
    
  public String getDCLine_BusI()
  {
    return dCLine_BusI;
  }
    
  public void setDCLine_BusI(String dCLine_BusI)
  {
    this.dCLine_BusI = dCLine_BusI;
  }
    
  public Double getDCLine_kVI()
  {
    return dCLine_kVI;
  }
    
  public void setDCLine_kVI(Double dCLine_kVI)
  {
    this.dCLine_kVI = dCLine_kVI;
  }
    
  public Double getDCLine_AMP()
  {
    return dCLine_AMP;
  }
    
  public void setDCLine_AMP(Double dCLine_AMP)
  {
    this.dCLine_AMP = dCLine_AMP;
  }
    
  public Double getDCLine_R()
  {
    return dCLine_R;
  }
    
  public void setDCLine_R(Double dCLine_R)
  {
    this.dCLine_R = dCLine_R;
  }
    
  public Double getDCLine_L()
  {
    return dCLine_L;
  }
    
  public void setDCLine_L(Double dCLine_L)
  {
    this.dCLine_L = dCLine_L;
  }
    
  public Double getDCLine_C()
  {
    return dCLine_C;
  }
    
  public void setDCLine_C(Double dCLine_C)
  {
    this.dCLine_C = dCLine_C;
  }
    
  public Integer getDCLine_CONTROL()
  {
    return dCLine_CONTROL;
  }
    
  public void setDCLine_CONTROL(Integer dCLine_CONTROL)
  {
    this.dCLine_CONTROL = dCLine_CONTROL;
  }
    
  public Double getDCLine_DCPOWER()
  {
    return dCLine_DCPOWER;
  }
    
  public void setDCLine_DCPOWER(Double dCLine_DCPOWER)
  {
    this.dCLine_DCPOWER = dCLine_DCPOWER;
  }
    
  public Double getDCLine_RVOLT()
  {
    return dCLine_RVOLT;
  }
    
  public void setDCLine_RVOLT(Double dCLine_RVOLT)
  {
    this.dCLine_RVOLT = dCLine_RVOLT;
  }
    
  public Double getDCLine_ROPER()
  {
    return dCLine_ROPER;
  }
    
  public void setDCLine_ROPER(Double dCLine_ROPER)
  {
    this.dCLine_ROPER = dCLine_ROPER;
  }
    
  public Double getDCLine_ISTOP()
  {
    return dCLine_ISTOP;
  }
    
  public void setDCLine_ISTOP(Double dCLine_ISTOP)
  {
    this.dCLine_ISTOP = dCLine_ISTOP;
  }
    
  public Double getDCLine_Pr()
  {
    return dCLine_Pr;
  }
    
  public void setDCLine_Pr(Double dCLine_Pr)
  {
    this.dCLine_Pr = dCLine_Pr;
  }
    
  public Double getDCLine_Pi()
  {
    return dCLine_Pi;
  }
    
  public void setDCLine_Pi(Double dCLine_Pi)
  {
    this.dCLine_Pi = dCLine_Pi;
  }
    
  public Double getDCLine_Lossp()
  {
    return dCLine_Lossp;
  }
    
  public void setDCLine_Lossp(Double dCLine_Lossp)
  {
    this.dCLine_Lossp = dCLine_Lossp;
  }
    
  public String getKeyName()
  {
    return keyName;
  }
    
  public void setKeyName(String keyName)
  {
    this.keyName = keyName;
  }
    
  public Integer getiRBus()
  {
    return iRBus;
  }
    
  public void setiRBus(Integer iRBus)
  {
    this.iRBus = iRBus;
  }
    
  public Integer getiIBus()
  {
    return iIBus;
  }
    
  public void setiIBus(Integer iIBus)
  {
    this.iIBus = iIBus;
  }
    
  public String getAlias()
  {
    return alias;
  }
    
  public void setAlias(String alias)
  {
    this.alias = alias;
  }
    
  public Integer getStatus()
  {
    return status;
  }
    
  public void setStatus(Integer status)
  {
    this.status = status;
  }
    
  public String toString()
  {
    return "BpaDat_DCLine ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", dCLine_Owner = " + dCLine_Owner
	 + ", dCLine_BusR = " + dCLine_BusR
	 + ", dCLine_kVR = " + dCLine_kVR
	 + ", dCLine_Meter = " + dCLine_Meter
	 + ", dCLine_BusI = " + dCLine_BusI
	 + ", dCLine_kVI = " + dCLine_kVI
	 + ", dCLine_AMP = " + dCLine_AMP
	 + ", dCLine_R = " + dCLine_R
	 + ", dCLine_L = " + dCLine_L
	 + ", dCLine_C = " + dCLine_C
	 + ", dCLine_CONTROL = " + dCLine_CONTROL
	 + ", dCLine_DCPOWER = " + dCLine_DCPOWER
	 + ", dCLine_RVOLT = " + dCLine_RVOLT
	 + ", dCLine_ROPER = " + dCLine_ROPER
	 + ", dCLine_ISTOP = " + dCLine_ISTOP
	 + ", dCLine_Pr = " + dCLine_Pr
	 + ", dCLine_Pi = " + dCLine_Pi
	 + ", dCLine_Lossp = " + dCLine_Lossp
	 + ", keyName = " + keyName
	 + ", iRBus = " + iRBus
	 + ", iIBus = " + iIBus
	 + ", alias = " + alias
	 + ", status = " + status+"]";
  }
    
}
    
