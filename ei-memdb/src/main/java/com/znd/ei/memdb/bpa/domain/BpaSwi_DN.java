package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*直流控制系统模型(DN)	*
***********************/
public class BpaSwi_DN  implements MemIndexable 
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
  private Integer DN_MOD;
  
  //整流侧功率定值环节中直流电压测量环节时间常数(秒)
  private Double DN_Tvp;
  
  //系统的暂时过电流能力(标么值,整流侧填写)
  private Double DN_IMAX;
  
  //系统的最小电流(标么值,整流侧填写)
  private Double DN_IMIN;
  
  //定电流调节器的比例增益
  private Double DN_P_I;
  
  //定电流调节器的积分时间常数(秒)
  private Double DN_T_I;
  
  //定电压调节器的比例增益
  private Double DN_P_U;
  
  //定电压调节器的积分时间常数(秒)
  private Double DN_T_U;
  
  //逆变侧定γ调节器的比例增益(逆变侧填写)
  private Double DN_P_Gam;
  
  //逆变侧定γ调节器的积分时间常数(秒,逆变侧填写)
  private Double DN_T_Gam;
  
  //限幅回路中交流电压门槛值(标么值)
  private Double DN_VacLow;
  
  //限幅回路中交流电压的延迟时间(秒)
  private Double DN_TVacLow;
  
  //限幅回路中直流电流门槛值(标么值)
  private Double DN_IdLow;
  
  //限幅回路中直流电流的延迟时间(秒)
  private Double DN_TIdLow;
  
  //限幅回路中时间常数(秒)
  private Double DN_Tlim;
  
  //比例增益计算回路中时间常数(秒)
  private Double DN_Tp;
  
  //直流系统短期过电流能力(标么值,整流侧填写)
  private Double DN_Iovl;
  
  //直流系统暂时过电流的容许时间(秒,整流侧填写)
  private Double DN_Timax;
  
  //超过暂时过电流的容许时间后,电流定值由Imax下降到Iovl的时间(秒,整流侧填写)
  private Double DN_Tmaxlim;
  
  //如果非空且非字符'F',则消去该直流控制系统(作为分区负荷)
  private Integer DN_DISA;
  
  //VDCOL环节电压测量环节时间常数(秒,逆变侧填写)
  private Double DN_TVDCOL;
  
  //VDCOL的x1(标么值,逆变侧填写)
  private Double DN_X1;
  
  //VDCOL的y1(标么值,逆变侧填写)
  private Double DN_Y1;
  
  //VDCOL的x2(标么值,逆变侧填写)
  private Double DN_X2;
  
  //VDCOL的y2(标么值,逆变侧填写)
  private Double DN_Y2;
  
  //VDCOL的斜率1(标么值,逆变侧填写)
  private Double DN_K1;
  
  //VDCOL的斜率2(标么值,逆变侧填写)
  private Double DN_K2;
  
  //VDCOL输出值的下降速率限制(pu/sec.,逆变侧填写)
  private Double DN_DownSL;
  
  //VDCOL输出值的上升速率限制(值大于零,pu/sec.,逆变侧填写)
  private Double DN_UpSL;
  
  //作逆变器使用时的最小点燃角(度) 
  private Double DN_AlphaStop;
  
  //逆变器换相失败的门槛值(度)
  private Double DN_GamaaMin;
  
  //整流侧功率定值环节中直流电压测量环节的小时间常数(秒,整流侧填写)
  private Double DN_TvpSmall;
  
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
    
  public Integer getDN_MOD()
  {
    return DN_MOD;
  }
    
  public void setDN_MOD(Integer DN_MOD)
  {
    this.DN_MOD = DN_MOD;
  }
    
  public Double getDN_Tvp()
  {
    return DN_Tvp;
  }
    
  public void setDN_Tvp(Double DN_Tvp)
  {
    this.DN_Tvp = DN_Tvp;
  }
    
  public Double getDN_IMAX()
  {
    return DN_IMAX;
  }
    
  public void setDN_IMAX(Double DN_IMAX)
  {
    this.DN_IMAX = DN_IMAX;
  }
    
  public Double getDN_IMIN()
  {
    return DN_IMIN;
  }
    
  public void setDN_IMIN(Double DN_IMIN)
  {
    this.DN_IMIN = DN_IMIN;
  }
    
  public Double getDN_P_I()
  {
    return DN_P_I;
  }
    
  public void setDN_P_I(Double DN_P_I)
  {
    this.DN_P_I = DN_P_I;
  }
    
  public Double getDN_T_I()
  {
    return DN_T_I;
  }
    
  public void setDN_T_I(Double DN_T_I)
  {
    this.DN_T_I = DN_T_I;
  }
    
  public Double getDN_P_U()
  {
    return DN_P_U;
  }
    
  public void setDN_P_U(Double DN_P_U)
  {
    this.DN_P_U = DN_P_U;
  }
    
  public Double getDN_T_U()
  {
    return DN_T_U;
  }
    
  public void setDN_T_U(Double DN_T_U)
  {
    this.DN_T_U = DN_T_U;
  }
    
  public Double getDN_P_Gam()
  {
    return DN_P_Gam;
  }
    
  public void setDN_P_Gam(Double DN_P_Gam)
  {
    this.DN_P_Gam = DN_P_Gam;
  }
    
  public Double getDN_T_Gam()
  {
    return DN_T_Gam;
  }
    
  public void setDN_T_Gam(Double DN_T_Gam)
  {
    this.DN_T_Gam = DN_T_Gam;
  }
    
  public Double getDN_VacLow()
  {
    return DN_VacLow;
  }
    
  public void setDN_VacLow(Double DN_VacLow)
  {
    this.DN_VacLow = DN_VacLow;
  }
    
  public Double getDN_TVacLow()
  {
    return DN_TVacLow;
  }
    
  public void setDN_TVacLow(Double DN_TVacLow)
  {
    this.DN_TVacLow = DN_TVacLow;
  }
    
  public Double getDN_IdLow()
  {
    return DN_IdLow;
  }
    
  public void setDN_IdLow(Double DN_IdLow)
  {
    this.DN_IdLow = DN_IdLow;
  }
    
  public Double getDN_TIdLow()
  {
    return DN_TIdLow;
  }
    
  public void setDN_TIdLow(Double DN_TIdLow)
  {
    this.DN_TIdLow = DN_TIdLow;
  }
    
  public Double getDN_Tlim()
  {
    return DN_Tlim;
  }
    
  public void setDN_Tlim(Double DN_Tlim)
  {
    this.DN_Tlim = DN_Tlim;
  }
    
  public Double getDN_Tp()
  {
    return DN_Tp;
  }
    
  public void setDN_Tp(Double DN_Tp)
  {
    this.DN_Tp = DN_Tp;
  }
    
  public Double getDN_Iovl()
  {
    return DN_Iovl;
  }
    
  public void setDN_Iovl(Double DN_Iovl)
  {
    this.DN_Iovl = DN_Iovl;
  }
    
  public Double getDN_Timax()
  {
    return DN_Timax;
  }
    
  public void setDN_Timax(Double DN_Timax)
  {
    this.DN_Timax = DN_Timax;
  }
    
  public Double getDN_Tmaxlim()
  {
    return DN_Tmaxlim;
  }
    
  public void setDN_Tmaxlim(Double DN_Tmaxlim)
  {
    this.DN_Tmaxlim = DN_Tmaxlim;
  }
    
  public Integer getDN_DISA()
  {
    return DN_DISA;
  }
    
  public void setDN_DISA(Integer DN_DISA)
  {
    this.DN_DISA = DN_DISA;
  }
    
  public Double getDN_TVDCOL()
  {
    return DN_TVDCOL;
  }
    
  public void setDN_TVDCOL(Double DN_TVDCOL)
  {
    this.DN_TVDCOL = DN_TVDCOL;
  }
    
  public Double getDN_X1()
  {
    return DN_X1;
  }
    
  public void setDN_X1(Double DN_X1)
  {
    this.DN_X1 = DN_X1;
  }
    
  public Double getDN_Y1()
  {
    return DN_Y1;
  }
    
  public void setDN_Y1(Double DN_Y1)
  {
    this.DN_Y1 = DN_Y1;
  }
    
  public Double getDN_X2()
  {
    return DN_X2;
  }
    
  public void setDN_X2(Double DN_X2)
  {
    this.DN_X2 = DN_X2;
  }
    
  public Double getDN_Y2()
  {
    return DN_Y2;
  }
    
  public void setDN_Y2(Double DN_Y2)
  {
    this.DN_Y2 = DN_Y2;
  }
    
  public Double getDN_K1()
  {
    return DN_K1;
  }
    
  public void setDN_K1(Double DN_K1)
  {
    this.DN_K1 = DN_K1;
  }
    
  public Double getDN_K2()
  {
    return DN_K2;
  }
    
  public void setDN_K2(Double DN_K2)
  {
    this.DN_K2 = DN_K2;
  }
    
  public Double getDN_DownSL()
  {
    return DN_DownSL;
  }
    
  public void setDN_DownSL(Double DN_DownSL)
  {
    this.DN_DownSL = DN_DownSL;
  }
    
  public Double getDN_UpSL()
  {
    return DN_UpSL;
  }
    
  public void setDN_UpSL(Double DN_UpSL)
  {
    this.DN_UpSL = DN_UpSL;
  }
    
  public Double getDN_AlphaStop()
  {
    return DN_AlphaStop;
  }
    
  public void setDN_AlphaStop(Double DN_AlphaStop)
  {
    this.DN_AlphaStop = DN_AlphaStop;
  }
    
  public Double getDN_GamaaMin()
  {
    return DN_GamaaMin;
  }
    
  public void setDN_GamaaMin(Double DN_GamaaMin)
  {
    this.DN_GamaaMin = DN_GamaaMin;
  }
    
  public Double getDN_TvpSmall()
  {
    return DN_TvpSmall;
  }
    
  public void setDN_TvpSmall(Double DN_TvpSmall)
  {
    this.DN_TvpSmall = DN_TvpSmall;
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
    return "BpaSwi_DN ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", DCBus_Name = " + DCBus_Name
	 + ", DCBus_KV = " + DCBus_KV
	 + ", DN_MOD = " + DN_MOD
	 + ", DN_Tvp = " + DN_Tvp
	 + ", DN_IMAX = " + DN_IMAX
	 + ", DN_IMIN = " + DN_IMIN
	 + ", DN_P_I = " + DN_P_I
	 + ", DN_T_I = " + DN_T_I
	 + ", DN_P_U = " + DN_P_U
	 + ", DN_T_U = " + DN_T_U
	 + ", DN_P_Gam = " + DN_P_Gam
	 + ", DN_T_Gam = " + DN_T_Gam
	 + ", DN_VacLow = " + DN_VacLow
	 + ", DN_TVacLow = " + DN_TVacLow
	 + ", DN_IdLow = " + DN_IdLow
	 + ", DN_TIdLow = " + DN_TIdLow
	 + ", DN_Tlim = " + DN_Tlim
	 + ", DN_Tp = " + DN_Tp
	 + ", DN_Iovl = " + DN_Iovl
	 + ", DN_Timax = " + DN_Timax
	 + ", DN_Tmaxlim = " + DN_Tmaxlim
	 + ", DN_DISA = " + DN_DISA
	 + ", DN_TVDCOL = " + DN_TVDCOL
	 + ", DN_X1 = " + DN_X1
	 + ", DN_Y1 = " + DN_Y1
	 + ", DN_X2 = " + DN_X2
	 + ", DN_Y2 = " + DN_Y2
	 + ", DN_K1 = " + DN_K1
	 + ", DN_K2 = " + DN_K2
	 + ", DN_DownSL = " + DN_DownSL
	 + ", DN_UpSL = " + DN_UpSL
	 + ", DN_AlphaStop = " + DN_AlphaStop
	 + ", DN_GamaaMin = " + DN_GamaaMin
	 + ", DN_TvpSmall = " + DN_TvpSmall
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
