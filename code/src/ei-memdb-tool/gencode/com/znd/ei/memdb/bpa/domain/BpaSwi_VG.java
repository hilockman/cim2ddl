package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*静止无功发生器(STATCOM)	*
***********************/
public class BpaSwi_VG  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称
  private String ACBus_Name;
  
  //母线基准电压(kV)
  private Double ACBus_KV;
  
  //额定容量
  private Double MvaBase;
  
  //滤波器和测量回路的时间常数(秒)
  private Double T1;
  
  //第一级超前时间常数(秒)
  private Double T2;
  
  //第一级滞后时间常数(秒)
  private Double T3;
  
  //第二级超前时间常数(秒)
  private Double T4;
  
  //第二级滞后时间常数(秒)
  private Double T5;
  
  //比例环节时间常数(秒)
  private Double TP;
  
  //STATCOM响应延迟(秒)
  private Double TS;
  
  //比例环节放大倍数
  private Double KP;
  
  //积分环节的放大倍数
  private Double KI;
  
  //STATCOM的V-I特性曲线的斜率
  private Double KD;
  
  //STATCOM与系统之间的等值电抗(pu)
  private Double XT;
  
  //电压限幅环节的上限(pu)
  private Double VMAX;
  
  //电压限幅环节的下限(pu)
  private Double VMIN;
  
  //最大容性电流(pu)
  private Double ICMAX;
  
  //最大感性电流(pu)
  private Double ILMAX;
  
  //与系统相连的节点电压低于此值
  private Double VSTANDBY;
  
  //被控母线名
  private String CON_NAME;
  
  //被控母线基准电压
  private Double CON_KV;
  
  //数据库主键
  private String KeyName;
  
  //母线索引
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
    
  public String getACBus_Name()
  {
    return ACBus_Name;
  }
    
  public void setACBus_Name(String ACBus_Name)
  {
    this.ACBus_Name = ACBus_Name;
  }
    
  public Double getACBus_KV()
  {
    return ACBus_KV;
  }
    
  public void setACBus_KV(Double ACBus_KV)
  {
    this.ACBus_KV = ACBus_KV;
  }
    
  public Double getMvaBase()
  {
    return MvaBase;
  }
    
  public void setMvaBase(Double MvaBase)
  {
    this.MvaBase = MvaBase;
  }
    
  public Double getT1()
  {
    return T1;
  }
    
  public void setT1(Double T1)
  {
    this.T1 = T1;
  }
    
  public Double getT2()
  {
    return T2;
  }
    
  public void setT2(Double T2)
  {
    this.T2 = T2;
  }
    
  public Double getT3()
  {
    return T3;
  }
    
  public void setT3(Double T3)
  {
    this.T3 = T3;
  }
    
  public Double getT4()
  {
    return T4;
  }
    
  public void setT4(Double T4)
  {
    this.T4 = T4;
  }
    
  public Double getT5()
  {
    return T5;
  }
    
  public void setT5(Double T5)
  {
    this.T5 = T5;
  }
    
  public Double getTP()
  {
    return TP;
  }
    
  public void setTP(Double TP)
  {
    this.TP = TP;
  }
    
  public Double getTS()
  {
    return TS;
  }
    
  public void setTS(Double TS)
  {
    this.TS = TS;
  }
    
  public Double getKP()
  {
    return KP;
  }
    
  public void setKP(Double KP)
  {
    this.KP = KP;
  }
    
  public Double getKI()
  {
    return KI;
  }
    
  public void setKI(Double KI)
  {
    this.KI = KI;
  }
    
  public Double getKD()
  {
    return KD;
  }
    
  public void setKD(Double KD)
  {
    this.KD = KD;
  }
    
  public Double getXT()
  {
    return XT;
  }
    
  public void setXT(Double XT)
  {
    this.XT = XT;
  }
    
  public Double getVMAX()
  {
    return VMAX;
  }
    
  public void setVMAX(Double VMAX)
  {
    this.VMAX = VMAX;
  }
    
  public Double getVMIN()
  {
    return VMIN;
  }
    
  public void setVMIN(Double VMIN)
  {
    this.VMIN = VMIN;
  }
    
  public Double getICMAX()
  {
    return ICMAX;
  }
    
  public void setICMAX(Double ICMAX)
  {
    this.ICMAX = ICMAX;
  }
    
  public Double getILMAX()
  {
    return ILMAX;
  }
    
  public void setILMAX(Double ILMAX)
  {
    this.ILMAX = ILMAX;
  }
    
  public Double getVSTANDBY()
  {
    return VSTANDBY;
  }
    
  public void setVSTANDBY(Double VSTANDBY)
  {
    this.VSTANDBY = VSTANDBY;
  }
    
  public String getCON_NAME()
  {
    return CON_NAME;
  }
    
  public void setCON_NAME(String CON_NAME)
  {
    this.CON_NAME = CON_NAME;
  }
    
  public Double getCON_KV()
  {
    return CON_KV;
  }
    
  public void setCON_KV(Double CON_KV)
  {
    this.CON_KV = CON_KV;
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
    return "BpaSwi_VG ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_KV = " + ACBus_KV
	 + ", MvaBase = " + MvaBase
	 + ", T1 = " + T1
	 + ", T2 = " + T2
	 + ", T3 = " + T3
	 + ", T4 = " + T4
	 + ", T5 = " + T5
	 + ", TP = " + TP
	 + ", TS = " + TS
	 + ", KP = " + KP
	 + ", KI = " + KI
	 + ", KD = " + KD
	 + ", XT = " + XT
	 + ", VMAX = " + VMAX
	 + ", VMIN = " + VMIN
	 + ", ICMAX = " + ICMAX
	 + ", ILMAX = " + ILMAX
	 + ", VSTANDBY = " + VSTANDBY
	 + ", CON_NAME = " + CON_NAME
	 + ", CON_KV = " + CON_KV
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
