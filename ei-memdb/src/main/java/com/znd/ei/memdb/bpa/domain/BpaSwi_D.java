package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*直流控制系统模型(D)	*
***********************/
public class BpaSwi_D  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //直流母线名称
  private String DCBus_Name;
  
  //直流母线基准电压(kV)
  private Double DCBus_KV;
  
  //电流测量环节时间常数(秒)
  private Double D_Tc;
  
  //电压测量环节时间常数(秒)
  private Double D_Tv;
  
  //电流调节器时间常数1(秒)
  private Double D_T1;
  
  //电流调节器时间常数2(秒)
  private Double D_T2;
  
  //电流调节器时间常数3(秒)
  private Double D_T3;
  
  //电流调节器增益
  private Double D_Ka;
  
  //控制方式,P＝定功率控制,I＝定电流控制
  private Integer D_MOD;
  
  //阀的过电流能力(pu)
  private Double D_IMAX;
  
  //电流余裕值(pu),逆变侧必须在0.05-0.3之间
  private Double D_IMARGIN;
  
  //作逆变器使用时的最小点燃角(度)
  private Double D_ALPHASTOP;
  
  //换相电压时间常数(秒),缺省0.01秒
  private Double D_TD;
  
  //电流限制起始处的额定端电压(pu),缺省0.25pu
  private Double D_VLIM;
  
  //非空则消去该直流控制系统
  private Integer D_DISA;
  
  //余裕开关单元关键码
  private Integer D_MSU;
  
  //数据库主键
  private String KeyName;
  
  //直流母线索引
  private Integer BusPtr;
  
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
    
  public String getDCBus_Name()
  {
    return DCBus_Name;
  }
    
  public void setDCBus_Name(String DCBus_Name)
  {
    this.DCBus_Name = DCBus_Name;
  }
    
  public Double getDCBus_KV()
  {
    return DCBus_KV;
  }
    
  public void setDCBus_KV(Double DCBus_KV)
  {
    this.DCBus_KV = DCBus_KV;
  }
    
  public Double getD_Tc()
  {
    return D_Tc;
  }
    
  public void setD_Tc(Double D_Tc)
  {
    this.D_Tc = D_Tc;
  }
    
  public Double getD_Tv()
  {
    return D_Tv;
  }
    
  public void setD_Tv(Double D_Tv)
  {
    this.D_Tv = D_Tv;
  }
    
  public Double getD_T1()
  {
    return D_T1;
  }
    
  public void setD_T1(Double D_T1)
  {
    this.D_T1 = D_T1;
  }
    
  public Double getD_T2()
  {
    return D_T2;
  }
    
  public void setD_T2(Double D_T2)
  {
    this.D_T2 = D_T2;
  }
    
  public Double getD_T3()
  {
    return D_T3;
  }
    
  public void setD_T3(Double D_T3)
  {
    this.D_T3 = D_T3;
  }
    
  public Double getD_Ka()
  {
    return D_Ka;
  }
    
  public void setD_Ka(Double D_Ka)
  {
    this.D_Ka = D_Ka;
  }
    
  public Integer getD_MOD()
  {
    return D_MOD;
  }
    
  public void setD_MOD(Integer D_MOD)
  {
    this.D_MOD = D_MOD;
  }
    
  public Double getD_IMAX()
  {
    return D_IMAX;
  }
    
  public void setD_IMAX(Double D_IMAX)
  {
    this.D_IMAX = D_IMAX;
  }
    
  public Double getD_IMARGIN()
  {
    return D_IMARGIN;
  }
    
  public void setD_IMARGIN(Double D_IMARGIN)
  {
    this.D_IMARGIN = D_IMARGIN;
  }
    
  public Double getD_ALPHASTOP()
  {
    return D_ALPHASTOP;
  }
    
  public void setD_ALPHASTOP(Double D_ALPHASTOP)
  {
    this.D_ALPHASTOP = D_ALPHASTOP;
  }
    
  public Double getD_TD()
  {
    return D_TD;
  }
    
  public void setD_TD(Double D_TD)
  {
    this.D_TD = D_TD;
  }
    
  public Double getD_VLIM()
  {
    return D_VLIM;
  }
    
  public void setD_VLIM(Double D_VLIM)
  {
    this.D_VLIM = D_VLIM;
  }
    
  public Integer getD_DISA()
  {
    return D_DISA;
  }
    
  public void setD_DISA(Integer D_DISA)
  {
    this.D_DISA = D_DISA;
  }
    
  public Integer getD_MSU()
  {
    return D_MSU;
  }
    
  public void setD_MSU(Integer D_MSU)
  {
    this.D_MSU = D_MSU;
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
    
  public String toString()
  {
    return "BpaSwi_D ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", DCBus_Name = " + DCBus_Name
	 + ", DCBus_KV = " + DCBus_KV
	 + ", D_Tc = " + D_Tc
	 + ", D_Tv = " + D_Tv
	 + ", D_T1 = " + D_T1
	 + ", D_T2 = " + D_T2
	 + ", D_T3 = " + D_T3
	 + ", D_Ka = " + D_Ka
	 + ", D_MOD = " + D_MOD
	 + ", D_IMAX = " + D_IMAX
	 + ", D_IMARGIN = " + D_IMARGIN
	 + ", D_ALPHASTOP = " + D_ALPHASTOP
	 + ", D_TD = " + D_TD
	 + ", D_VLIM = " + D_VLIM
	 + ", D_DISA = " + D_DISA
	 + ", D_MSU = " + D_MSU
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
