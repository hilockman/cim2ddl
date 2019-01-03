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
  private String CardKey;
  
  //所有者
  private String DCLine_Owner;
  
  //整流侧母线名称
  private String DCLine_BusR;
  
  //整流侧基准电压(kV)
  private Double DCLine_kVR;
  
  //区域联络线测点标志
  private Integer DCLine_Meter;
  
  //逆变侧母线名称
  private String DCLine_BusI;
  
  //逆变侧基准电压(kV)
  private Double DCLine_kVI;
  
  //直流线路额定电流(安培)
  private Double DCLine_AMP;
  
  //直流线路电阻(欧姆)
  private Double DCLine_R;
  
  //直流线路电感(毫亨)
  private Double DCLine_L;
  
  //直流线路电容(微阀)
  private Double DCLine_C;
  
  //所安排的直流功率的控制点
  private Integer DCLine_CONTROL;
  
  //所安排的直流功率(MW)
  private Double DCLine_DCPOWER;
  
  //给定直流线路整流侧的直流电压(kV)
  private Double DCLine_RVOLT;
  
  //整流侧的正常触发角(度)
  private Double DCLine_ROPER;
  
  //逆变侧的正常关断角(度)
  private Double DCLine_ISTOP;
  
  //线路长度
  private Double DCLine_Miles;
  
  //线路整流侧功率(MW)
  private Double DCLine_Pr;
  
  //线路逆变侧功率(MW)
  private Double DCLine_Pi;
  
  //线路有功损耗(MW)
  private Double DCLine_Lossp;
  
  //直流线路名称
  private String KeyName;
  
  //直流线路整流侧母线索引
  private Integer iRBus;
  
  //直流线路逆变侧母线索引
  private Integer iIBus;
  
  //直流线路别名
  private String Alias;
  
  //状态
  private Integer Status;
  
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
    
  public String getDCLine_Owner()
  {
    return DCLine_Owner;
  }
    
  public void setDCLine_Owner(String DCLine_Owner)
  {
    this.DCLine_Owner = DCLine_Owner;
  }
    
  public String getDCLine_BusR()
  {
    return DCLine_BusR;
  }
    
  public void setDCLine_BusR(String DCLine_BusR)
  {
    this.DCLine_BusR = DCLine_BusR;
  }
    
  public Double getDCLine_kVR()
  {
    return DCLine_kVR;
  }
    
  public void setDCLine_kVR(Double DCLine_kVR)
  {
    this.DCLine_kVR = DCLine_kVR;
  }
    
  public Integer getDCLine_Meter()
  {
    return DCLine_Meter;
  }
    
  public void setDCLine_Meter(Integer DCLine_Meter)
  {
    this.DCLine_Meter = DCLine_Meter;
  }
    
  public String getDCLine_BusI()
  {
    return DCLine_BusI;
  }
    
  public void setDCLine_BusI(String DCLine_BusI)
  {
    this.DCLine_BusI = DCLine_BusI;
  }
    
  public Double getDCLine_kVI()
  {
    return DCLine_kVI;
  }
    
  public void setDCLine_kVI(Double DCLine_kVI)
  {
    this.DCLine_kVI = DCLine_kVI;
  }
    
  public Double getDCLine_AMP()
  {
    return DCLine_AMP;
  }
    
  public void setDCLine_AMP(Double DCLine_AMP)
  {
    this.DCLine_AMP = DCLine_AMP;
  }
    
  public Double getDCLine_R()
  {
    return DCLine_R;
  }
    
  public void setDCLine_R(Double DCLine_R)
  {
    this.DCLine_R = DCLine_R;
  }
    
  public Double getDCLine_L()
  {
    return DCLine_L;
  }
    
  public void setDCLine_L(Double DCLine_L)
  {
    this.DCLine_L = DCLine_L;
  }
    
  public Double getDCLine_C()
  {
    return DCLine_C;
  }
    
  public void setDCLine_C(Double DCLine_C)
  {
    this.DCLine_C = DCLine_C;
  }
    
  public Integer getDCLine_CONTROL()
  {
    return DCLine_CONTROL;
  }
    
  public void setDCLine_CONTROL(Integer DCLine_CONTROL)
  {
    this.DCLine_CONTROL = DCLine_CONTROL;
  }
    
  public Double getDCLine_DCPOWER()
  {
    return DCLine_DCPOWER;
  }
    
  public void setDCLine_DCPOWER(Double DCLine_DCPOWER)
  {
    this.DCLine_DCPOWER = DCLine_DCPOWER;
  }
    
  public Double getDCLine_RVOLT()
  {
    return DCLine_RVOLT;
  }
    
  public void setDCLine_RVOLT(Double DCLine_RVOLT)
  {
    this.DCLine_RVOLT = DCLine_RVOLT;
  }
    
  public Double getDCLine_ROPER()
  {
    return DCLine_ROPER;
  }
    
  public void setDCLine_ROPER(Double DCLine_ROPER)
  {
    this.DCLine_ROPER = DCLine_ROPER;
  }
    
  public Double getDCLine_ISTOP()
  {
    return DCLine_ISTOP;
  }
    
  public void setDCLine_ISTOP(Double DCLine_ISTOP)
  {
    this.DCLine_ISTOP = DCLine_ISTOP;
  }
    
  public Double getDCLine_Miles()
  {
    return DCLine_Miles;
  }
    
  public void setDCLine_Miles(Double DCLine_Miles)
  {
    this.DCLine_Miles = DCLine_Miles;
  }
    
  public Double getDCLine_Pr()
  {
    return DCLine_Pr;
  }
    
  public void setDCLine_Pr(Double DCLine_Pr)
  {
    this.DCLine_Pr = DCLine_Pr;
  }
    
  public Double getDCLine_Pi()
  {
    return DCLine_Pi;
  }
    
  public void setDCLine_Pi(Double DCLine_Pi)
  {
    this.DCLine_Pi = DCLine_Pi;
  }
    
  public Double getDCLine_Lossp()
  {
    return DCLine_Lossp;
  }
    
  public void setDCLine_Lossp(Double DCLine_Lossp)
  {
    this.DCLine_Lossp = DCLine_Lossp;
  }
    
  public String getKeyName()
  {
    return KeyName;
  }
    
  public void setKeyName(String KeyName)
  {
    this.KeyName = KeyName;
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
    return Alias;
  }
    
  public void setAlias(String Alias)
  {
    this.Alias = Alias;
  }
    
  public Integer getStatus()
  {
    return Status;
  }
    
  public void setStatus(Integer Status)
  {
    this.Status = Status;
  }
    
  public String toString()
  {
    return "BpaDat_DCLine ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", DCLine_Owner = " + DCLine_Owner
	 + ", DCLine_BusR = " + DCLine_BusR
	 + ", DCLine_kVR = " + DCLine_kVR
	 + ", DCLine_Meter = " + DCLine_Meter
	 + ", DCLine_BusI = " + DCLine_BusI
	 + ", DCLine_kVI = " + DCLine_kVI
	 + ", DCLine_AMP = " + DCLine_AMP
	 + ", DCLine_R = " + DCLine_R
	 + ", DCLine_L = " + DCLine_L
	 + ", DCLine_C = " + DCLine_C
	 + ", DCLine_CONTROL = " + DCLine_CONTROL
	 + ", DCLine_DCPOWER = " + DCLine_DCPOWER
	 + ", DCLine_RVOLT = " + DCLine_RVOLT
	 + ", DCLine_ROPER = " + DCLine_ROPER
	 + ", DCLine_ISTOP = " + DCLine_ISTOP
	 + ", DCLine_Miles = " + DCLine_Miles
	 + ", DCLine_Pr = " + DCLine_Pr
	 + ", DCLine_Pi = " + DCLine_Pi
	 + ", DCLine_Lossp = " + DCLine_Lossp
	 + ", KeyName = " + KeyName
	 + ", iRBus = " + iRBus
	 + ", iIBus = " + iIBus
	 + ", Alias = " + Alias
	 + ", Status = " + Status+"]";
  }
    
}
    
