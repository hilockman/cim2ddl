package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*直流控制系统模型(DM)	*
***********************/
public class BpaSwi_DM  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //直流母线名称
  private String DCBus_Name;
  
  //直流母线基准电压(kV)
  private Double DCBus_KV;
  
  //MOD,P=恒功率控制,I=恒电流控制
  private Integer DM_MOD;
  
  //整流侧功率定值环节中直流电压测量环节时间常数(秒)
  private Double DM_Tvp;
  
  //阀的过电流能力(标么值,整流侧填写)
  private Double DM_IMAX;
  
  //阀的最小电流(标么值,整流侧填写)
  private Double DM_IMIN;
  
  //直流电流测量环节时间常数(秒)
  private Double DM_Tidmes;
  
  //定电流调节器的比例增益
  private Double DM_Kp_I;
  
  //定电流调节器的积分时间常数(秒)
  private Double DM_Ti_I;
  
  //定电流调节器的输出上限(度)
  private Double DM_Max_I;
  
  //定电流调节器的输出下限(度)
  private Double DM_Min_I;
  
  //逆变侧γ测量环节时间常数(秒)
  private Double DM_TGamMes;
  
  //逆变侧定γ调节器的比例增益
  private Double DM_Kp_Gam;
  
  //逆变侧定γ调节器的积分时间常数(秒)
  private Double DM_Ti_Gam;
  
  //逆变侧定γ调节器的输出上限(度)
  private Double DM_Max_Gam;
  
  //逆变侧定γ调节器的输出上限(度)
  private Double DM_Min_Gam;
  
  //整流侧功率定值环节中直流电压测量环节小时间常数(秒)
  private Double DM_TvpSmpall;
  
  //非空则消去该直流控制系统
  private Integer DM_DISA;
  
  //VDCOL环节电压测量环节时间常数(秒,逆变侧填写)
  private Double DM_TVDCOL;
  
  //VDCOL的x1(标么值,逆变侧填写)
  private Double DM_X1;
  
  //VDCOL的y1(标么值,逆变侧填写)
  private Double DM_Y1;
  
  //VDCOL的x2(标么值,逆变侧填写)
  private Double DM_X2;
  
  //VDCOL的y2(标么值,逆变侧填写)
  private Double DM_Y2;
  
  //VDCOL的斜率1(标么值,逆变侧填写)
  private Double DM_K1;
  
  //VDCOL的斜率2(标么值,逆变侧填写)
  private Double DM_K2;
  
  //VDCOL输出值的下降速率限制(pu/sec.,逆变侧填写)
  private Double DM_DownSL;
  
  //VDCOL输出值的上升速率限制(值大于零,pu/sec.,逆变侧填写)
  private Double DM_UpSL;
  
  //逆变器换相失败的门槛值(度,逆变侧填写)
  private Double DM_GammaMin;
  
  //电流裕度(标么值,逆变侧填写)
  private Double DM_Imargin;
  
  //逆变侧γ角的最大偏差限制(度,逆变侧填写)
  private Double DM_DGamMin;
  
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
    
  public Integer getDM_MOD()
  {
    return DM_MOD;
  }
    
  public void setDM_MOD(Integer DM_MOD)
  {
    this.DM_MOD = DM_MOD;
  }
    
  public Double getDM_Tvp()
  {
    return DM_Tvp;
  }
    
  public void setDM_Tvp(Double DM_Tvp)
  {
    this.DM_Tvp = DM_Tvp;
  }
    
  public Double getDM_IMAX()
  {
    return DM_IMAX;
  }
    
  public void setDM_IMAX(Double DM_IMAX)
  {
    this.DM_IMAX = DM_IMAX;
  }
    
  public Double getDM_IMIN()
  {
    return DM_IMIN;
  }
    
  public void setDM_IMIN(Double DM_IMIN)
  {
    this.DM_IMIN = DM_IMIN;
  }
    
  public Double getDM_Tidmes()
  {
    return DM_Tidmes;
  }
    
  public void setDM_Tidmes(Double DM_Tidmes)
  {
    this.DM_Tidmes = DM_Tidmes;
  }
    
  public Double getDM_Kp_I()
  {
    return DM_Kp_I;
  }
    
  public void setDM_Kp_I(Double DM_Kp_I)
  {
    this.DM_Kp_I = DM_Kp_I;
  }
    
  public Double getDM_Ti_I()
  {
    return DM_Ti_I;
  }
    
  public void setDM_Ti_I(Double DM_Ti_I)
  {
    this.DM_Ti_I = DM_Ti_I;
  }
    
  public Double getDM_Max_I()
  {
    return DM_Max_I;
  }
    
  public void setDM_Max_I(Double DM_Max_I)
  {
    this.DM_Max_I = DM_Max_I;
  }
    
  public Double getDM_Min_I()
  {
    return DM_Min_I;
  }
    
  public void setDM_Min_I(Double DM_Min_I)
  {
    this.DM_Min_I = DM_Min_I;
  }
    
  public Double getDM_TGamMes()
  {
    return DM_TGamMes;
  }
    
  public void setDM_TGamMes(Double DM_TGamMes)
  {
    this.DM_TGamMes = DM_TGamMes;
  }
    
  public Double getDM_Kp_Gam()
  {
    return DM_Kp_Gam;
  }
    
  public void setDM_Kp_Gam(Double DM_Kp_Gam)
  {
    this.DM_Kp_Gam = DM_Kp_Gam;
  }
    
  public Double getDM_Ti_Gam()
  {
    return DM_Ti_Gam;
  }
    
  public void setDM_Ti_Gam(Double DM_Ti_Gam)
  {
    this.DM_Ti_Gam = DM_Ti_Gam;
  }
    
  public Double getDM_Max_Gam()
  {
    return DM_Max_Gam;
  }
    
  public void setDM_Max_Gam(Double DM_Max_Gam)
  {
    this.DM_Max_Gam = DM_Max_Gam;
  }
    
  public Double getDM_Min_Gam()
  {
    return DM_Min_Gam;
  }
    
  public void setDM_Min_Gam(Double DM_Min_Gam)
  {
    this.DM_Min_Gam = DM_Min_Gam;
  }
    
  public Double getDM_TvpSmpall()
  {
    return DM_TvpSmpall;
  }
    
  public void setDM_TvpSmpall(Double DM_TvpSmpall)
  {
    this.DM_TvpSmpall = DM_TvpSmpall;
  }
    
  public Integer getDM_DISA()
  {
    return DM_DISA;
  }
    
  public void setDM_DISA(Integer DM_DISA)
  {
    this.DM_DISA = DM_DISA;
  }
    
  public Double getDM_TVDCOL()
  {
    return DM_TVDCOL;
  }
    
  public void setDM_TVDCOL(Double DM_TVDCOL)
  {
    this.DM_TVDCOL = DM_TVDCOL;
  }
    
  public Double getDM_X1()
  {
    return DM_X1;
  }
    
  public void setDM_X1(Double DM_X1)
  {
    this.DM_X1 = DM_X1;
  }
    
  public Double getDM_Y1()
  {
    return DM_Y1;
  }
    
  public void setDM_Y1(Double DM_Y1)
  {
    this.DM_Y1 = DM_Y1;
  }
    
  public Double getDM_X2()
  {
    return DM_X2;
  }
    
  public void setDM_X2(Double DM_X2)
  {
    this.DM_X2 = DM_X2;
  }
    
  public Double getDM_Y2()
  {
    return DM_Y2;
  }
    
  public void setDM_Y2(Double DM_Y2)
  {
    this.DM_Y2 = DM_Y2;
  }
    
  public Double getDM_K1()
  {
    return DM_K1;
  }
    
  public void setDM_K1(Double DM_K1)
  {
    this.DM_K1 = DM_K1;
  }
    
  public Double getDM_K2()
  {
    return DM_K2;
  }
    
  public void setDM_K2(Double DM_K2)
  {
    this.DM_K2 = DM_K2;
  }
    
  public Double getDM_DownSL()
  {
    return DM_DownSL;
  }
    
  public void setDM_DownSL(Double DM_DownSL)
  {
    this.DM_DownSL = DM_DownSL;
  }
    
  public Double getDM_UpSL()
  {
    return DM_UpSL;
  }
    
  public void setDM_UpSL(Double DM_UpSL)
  {
    this.DM_UpSL = DM_UpSL;
  }
    
  public Double getDM_GammaMin()
  {
    return DM_GammaMin;
  }
    
  public void setDM_GammaMin(Double DM_GammaMin)
  {
    this.DM_GammaMin = DM_GammaMin;
  }
    
  public Double getDM_Imargin()
  {
    return DM_Imargin;
  }
    
  public void setDM_Imargin(Double DM_Imargin)
  {
    this.DM_Imargin = DM_Imargin;
  }
    
  public Double getDM_DGamMin()
  {
    return DM_DGamMin;
  }
    
  public void setDM_DGamMin(Double DM_DGamMin)
  {
    this.DM_DGamMin = DM_DGamMin;
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
    return "BpaSwi_DM ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", DCBus_Name = " + DCBus_Name
	 + ", DCBus_KV = " + DCBus_KV
	 + ", DM_MOD = " + DM_MOD
	 + ", DM_Tvp = " + DM_Tvp
	 + ", DM_IMAX = " + DM_IMAX
	 + ", DM_IMIN = " + DM_IMIN
	 + ", DM_Tidmes = " + DM_Tidmes
	 + ", DM_Kp_I = " + DM_Kp_I
	 + ", DM_Ti_I = " + DM_Ti_I
	 + ", DM_Max_I = " + DM_Max_I
	 + ", DM_Min_I = " + DM_Min_I
	 + ", DM_TGamMes = " + DM_TGamMes
	 + ", DM_Kp_Gam = " + DM_Kp_Gam
	 + ", DM_Ti_Gam = " + DM_Ti_Gam
	 + ", DM_Max_Gam = " + DM_Max_Gam
	 + ", DM_Min_Gam = " + DM_Min_Gam
	 + ", DM_TvpSmpall = " + DM_TvpSmpall
	 + ", DM_DISA = " + DM_DISA
	 + ", DM_TVDCOL = " + DM_TVDCOL
	 + ", DM_X1 = " + DM_X1
	 + ", DM_Y1 = " + DM_Y1
	 + ", DM_X2 = " + DM_X2
	 + ", DM_Y2 = " + DM_Y2
	 + ", DM_K1 = " + DM_K1
	 + ", DM_K2 = " + DM_K2
	 + ", DM_DownSL = " + DM_DownSL
	 + ", DM_UpSL = " + DM_UpSL
	 + ", DM_GammaMin = " + DM_GammaMin
	 + ", DM_Imargin = " + DM_Imargin
	 + ", DM_DGamMin = " + DM_DGamMin
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
