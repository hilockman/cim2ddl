package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*直流控制系统模型(DA)	*
***********************/
public class BpaSwi_DA  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //直流母线名称
  private String DCBus_Name;
  
  //直流母线基准电压(kV)
  private Double DCBus_KV;
  
  //最大触发角控制增益
  private Double DA_G_Amax;
  
  //最大触发角控制时间常数(秒)
  private Double DA_T_Amax;
  
  //熄弧角参考值
  private Double DA_GammaRef;
  
  //熄弧角最小值
  private Double DA_GammaMin;
  
  //定电压控制比例增益
  private Double DA_Kp_vca;
  
  //定电压控制积分时间常数(秒)
  private Double DA_Ti_vca;
  
  //整流侧最小触发角控制增益1
  private Double DA_K1_ra;
  
  //整流侧最小触发角控制增益2
  private Double DA_K2_ra;
  
  //整流侧最小触发角控制电压阈值1
  private Double DA_Cdl;
  
  //整流侧最小触发角控制电压阈值2
  private Double DA_D1;
  
  //整流侧最小触发角控制角度下降速率
  private Double DA_Decr;
  
  //逆变侧Gamma0启动延时时间(秒)
  private Double DA_T_ga;
  
  //直流重启动控制移相延时时间(秒)
  private Double DA_Td_ret;
  
  //直流重启动控制移相持续时间(秒)
  private Double DA_Th_ret;
  
  //直流重启动控制重启指令延时时间(秒)
  private Double DA_Th_res;
  
  //非空则消去该直流控制系统
  private Integer DA_DISA;
  
  //调试文件标志,非空则输出调试文件
  private Integer DA_DBG;
  
  //控制方式,1=恒定功率,0=恒定电流
  private String DA_MOD;
  
  //主控站,1=主控站,0=受控站
  private String DA_LEAD;
  
  //运行标志,1=运行状态,0=停运状态
  private String DA_OPN;
  
  //协调控制标志,1=双极协调,0=独立运行
  private String DA_BC_ON;
  
  //VDCOL启动电压
  private Double DA_Udlow;
  
  //VDCOL退出电压
  private Double DA_Udhigh;
  
  //VDCOL电压上升滤波时间常数
  private Double DA_Udtup;
  
  //VDCOL电压下降滤波时间常数
  private Double DA_Udtdn;
  
  //VDCOL最小插值电流指令
  private Double DA_Iomin_vdcl;
  
  //VDCOL最小电流指令
  private Double DA_Iomin;
  
  //定电流控制电流滤波时间常数(秒)
  private Double DA_Id_t;
  
  //定电流控制总增益
  private Double DA_Gain;
  
  //定电流控制比例增益
  private Double DA_Kp;
  
  //定电流控制积分时间常数(秒)
  private Double DA_Ti;
  
  //换相失败预测增益
  private Double DA_G_cf;
  
  //换相失败预测启动电压阈值
  private Double DA_K_cf;
  
  //换相失败预测输出角度下降时间常数(秒)
  private Double DA_T_dn_cf;
  
  //DA卡续卡标志
  private Integer DA_A;
  
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
    
  public Double getDA_G_Amax()
  {
    return DA_G_Amax;
  }
    
  public void setDA_G_Amax(Double DA_G_Amax)
  {
    this.DA_G_Amax = DA_G_Amax;
  }
    
  public Double getDA_T_Amax()
  {
    return DA_T_Amax;
  }
    
  public void setDA_T_Amax(Double DA_T_Amax)
  {
    this.DA_T_Amax = DA_T_Amax;
  }
    
  public Double getDA_GammaRef()
  {
    return DA_GammaRef;
  }
    
  public void setDA_GammaRef(Double DA_GammaRef)
  {
    this.DA_GammaRef = DA_GammaRef;
  }
    
  public Double getDA_GammaMin()
  {
    return DA_GammaMin;
  }
    
  public void setDA_GammaMin(Double DA_GammaMin)
  {
    this.DA_GammaMin = DA_GammaMin;
  }
    
  public Double getDA_Kp_vca()
  {
    return DA_Kp_vca;
  }
    
  public void setDA_Kp_vca(Double DA_Kp_vca)
  {
    this.DA_Kp_vca = DA_Kp_vca;
  }
    
  public Double getDA_Ti_vca()
  {
    return DA_Ti_vca;
  }
    
  public void setDA_Ti_vca(Double DA_Ti_vca)
  {
    this.DA_Ti_vca = DA_Ti_vca;
  }
    
  public Double getDA_K1_ra()
  {
    return DA_K1_ra;
  }
    
  public void setDA_K1_ra(Double DA_K1_ra)
  {
    this.DA_K1_ra = DA_K1_ra;
  }
    
  public Double getDA_K2_ra()
  {
    return DA_K2_ra;
  }
    
  public void setDA_K2_ra(Double DA_K2_ra)
  {
    this.DA_K2_ra = DA_K2_ra;
  }
    
  public Double getDA_Cdl()
  {
    return DA_Cdl;
  }
    
  public void setDA_Cdl(Double DA_Cdl)
  {
    this.DA_Cdl = DA_Cdl;
  }
    
  public Double getDA_D1()
  {
    return DA_D1;
  }
    
  public void setDA_D1(Double DA_D1)
  {
    this.DA_D1 = DA_D1;
  }
    
  public Double getDA_Decr()
  {
    return DA_Decr;
  }
    
  public void setDA_Decr(Double DA_Decr)
  {
    this.DA_Decr = DA_Decr;
  }
    
  public Double getDA_T_ga()
  {
    return DA_T_ga;
  }
    
  public void setDA_T_ga(Double DA_T_ga)
  {
    this.DA_T_ga = DA_T_ga;
  }
    
  public Double getDA_Td_ret()
  {
    return DA_Td_ret;
  }
    
  public void setDA_Td_ret(Double DA_Td_ret)
  {
    this.DA_Td_ret = DA_Td_ret;
  }
    
  public Double getDA_Th_ret()
  {
    return DA_Th_ret;
  }
    
  public void setDA_Th_ret(Double DA_Th_ret)
  {
    this.DA_Th_ret = DA_Th_ret;
  }
    
  public Double getDA_Th_res()
  {
    return DA_Th_res;
  }
    
  public void setDA_Th_res(Double DA_Th_res)
  {
    this.DA_Th_res = DA_Th_res;
  }
    
  public Integer getDA_DISA()
  {
    return DA_DISA;
  }
    
  public void setDA_DISA(Integer DA_DISA)
  {
    this.DA_DISA = DA_DISA;
  }
    
  public Integer getDA_DBG()
  {
    return DA_DBG;
  }
    
  public void setDA_DBG(Integer DA_DBG)
  {
    this.DA_DBG = DA_DBG;
  }
    
  public String getDA_MOD()
  {
    return DA_MOD;
  }
    
  public void setDA_MOD(String DA_MOD)
  {
    this.DA_MOD = DA_MOD;
  }
    
  public String getDA_LEAD()
  {
    return DA_LEAD;
  }
    
  public void setDA_LEAD(String DA_LEAD)
  {
    this.DA_LEAD = DA_LEAD;
  }
    
  public String getDA_OPN()
  {
    return DA_OPN;
  }
    
  public void setDA_OPN(String DA_OPN)
  {
    this.DA_OPN = DA_OPN;
  }
    
  public String getDA_BC_ON()
  {
    return DA_BC_ON;
  }
    
  public void setDA_BC_ON(String DA_BC_ON)
  {
    this.DA_BC_ON = DA_BC_ON;
  }
    
  public Double getDA_Udlow()
  {
    return DA_Udlow;
  }
    
  public void setDA_Udlow(Double DA_Udlow)
  {
    this.DA_Udlow = DA_Udlow;
  }
    
  public Double getDA_Udhigh()
  {
    return DA_Udhigh;
  }
    
  public void setDA_Udhigh(Double DA_Udhigh)
  {
    this.DA_Udhigh = DA_Udhigh;
  }
    
  public Double getDA_Udtup()
  {
    return DA_Udtup;
  }
    
  public void setDA_Udtup(Double DA_Udtup)
  {
    this.DA_Udtup = DA_Udtup;
  }
    
  public Double getDA_Udtdn()
  {
    return DA_Udtdn;
  }
    
  public void setDA_Udtdn(Double DA_Udtdn)
  {
    this.DA_Udtdn = DA_Udtdn;
  }
    
  public Double getDA_Iomin_vdcl()
  {
    return DA_Iomin_vdcl;
  }
    
  public void setDA_Iomin_vdcl(Double DA_Iomin_vdcl)
  {
    this.DA_Iomin_vdcl = DA_Iomin_vdcl;
  }
    
  public Double getDA_Iomin()
  {
    return DA_Iomin;
  }
    
  public void setDA_Iomin(Double DA_Iomin)
  {
    this.DA_Iomin = DA_Iomin;
  }
    
  public Double getDA_Id_t()
  {
    return DA_Id_t;
  }
    
  public void setDA_Id_t(Double DA_Id_t)
  {
    this.DA_Id_t = DA_Id_t;
  }
    
  public Double getDA_Gain()
  {
    return DA_Gain;
  }
    
  public void setDA_Gain(Double DA_Gain)
  {
    this.DA_Gain = DA_Gain;
  }
    
  public Double getDA_Kp()
  {
    return DA_Kp;
  }
    
  public void setDA_Kp(Double DA_Kp)
  {
    this.DA_Kp = DA_Kp;
  }
    
  public Double getDA_Ti()
  {
    return DA_Ti;
  }
    
  public void setDA_Ti(Double DA_Ti)
  {
    this.DA_Ti = DA_Ti;
  }
    
  public Double getDA_G_cf()
  {
    return DA_G_cf;
  }
    
  public void setDA_G_cf(Double DA_G_cf)
  {
    this.DA_G_cf = DA_G_cf;
  }
    
  public Double getDA_K_cf()
  {
    return DA_K_cf;
  }
    
  public void setDA_K_cf(Double DA_K_cf)
  {
    this.DA_K_cf = DA_K_cf;
  }
    
  public Double getDA_T_dn_cf()
  {
    return DA_T_dn_cf;
  }
    
  public void setDA_T_dn_cf(Double DA_T_dn_cf)
  {
    this.DA_T_dn_cf = DA_T_dn_cf;
  }
    
  public Integer getDA_A()
  {
    return DA_A;
  }
    
  public void setDA_A(Integer DA_A)
  {
    this.DA_A = DA_A;
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
    return "BpaSwi_DA ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", DCBus_Name = " + DCBus_Name
	 + ", DCBus_KV = " + DCBus_KV
	 + ", DA_G_Amax = " + DA_G_Amax
	 + ", DA_T_Amax = " + DA_T_Amax
	 + ", DA_GammaRef = " + DA_GammaRef
	 + ", DA_GammaMin = " + DA_GammaMin
	 + ", DA_Kp_vca = " + DA_Kp_vca
	 + ", DA_Ti_vca = " + DA_Ti_vca
	 + ", DA_K1_ra = " + DA_K1_ra
	 + ", DA_K2_ra = " + DA_K2_ra
	 + ", DA_Cdl = " + DA_Cdl
	 + ", DA_D1 = " + DA_D1
	 + ", DA_Decr = " + DA_Decr
	 + ", DA_T_ga = " + DA_T_ga
	 + ", DA_Td_ret = " + DA_Td_ret
	 + ", DA_Th_ret = " + DA_Th_ret
	 + ", DA_Th_res = " + DA_Th_res
	 + ", DA_DISA = " + DA_DISA
	 + ", DA_DBG = " + DA_DBG
	 + ", DA_MOD = " + DA_MOD
	 + ", DA_LEAD = " + DA_LEAD
	 + ", DA_OPN = " + DA_OPN
	 + ", DA_BC_ON = " + DA_BC_ON
	 + ", DA_Udlow = " + DA_Udlow
	 + ", DA_Udhigh = " + DA_Udhigh
	 + ", DA_Udtup = " + DA_Udtup
	 + ", DA_Udtdn = " + DA_Udtdn
	 + ", DA_Iomin_vdcl = " + DA_Iomin_vdcl
	 + ", DA_Iomin = " + DA_Iomin
	 + ", DA_Id_t = " + DA_Id_t
	 + ", DA_Gain = " + DA_Gain
	 + ", DA_Kp = " + DA_Kp
	 + ", DA_Ti = " + DA_Ti
	 + ", DA_G_cf = " + DA_G_cf
	 + ", DA_K_cf = " + DA_K_cf
	 + ", DA_T_dn_cf = " + DA_T_dn_cf
	 + ", DA_A = " + DA_A
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
