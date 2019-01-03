package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*金风风机模型表(WINDG_GW)	*
***********************/
public class BpaSwi_WGWGen  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //电机母线名
  private String ACBus_Name;
  
  //电机母线电压(kV)
  private Double ACBus_kV;
  
  //电机识别码
  private Integer Gen_ID;
  
  //风电机组类型代码
  private String GW_TYPE;
  
  //风电机组台数
  private Integer NG;
  
  //有功占潮流总出力比例
  private Double PPER;
  
  //无功占潮流总出力比例
  private Double QPER;
  
  //低电压穿越,有功电流设定值(A,缺省200)
  private Double IP_CUR;
  
  //低电压穿越恢复,有功电流设定值(A,缺省400)
  private Double IP_RETURN;
  
  //低电压穿越恢复,维持上述电流时间(周,缺省0)
  private Double IP_RET_TIME;
  
  //低电压穿越恢复,有功电流上升速率(A/s,缺省1500)
  private Double IP_RATE;
  
  //无功调整变化率(pu,电压降低倍数,额定电流基准,缺省0)
  private Double Q_RATE;
  
  //最大电流限制(A)
  private Double IMAX;
  
  //数据库主键
  private String KeyName;
  
  //发电机母线索引
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
    
  public String getGW_TYPE()
  {
    return GW_TYPE;
  }
    
  public void setGW_TYPE(String GW_TYPE)
  {
    this.GW_TYPE = GW_TYPE;
  }
    
  public Integer getNG()
  {
    return NG;
  }
    
  public void setNG(Integer NG)
  {
    this.NG = NG;
  }
    
  public Double getPPER()
  {
    return PPER;
  }
    
  public void setPPER(Double PPER)
  {
    this.PPER = PPER;
  }
    
  public Double getQPER()
  {
    return QPER;
  }
    
  public void setQPER(Double QPER)
  {
    this.QPER = QPER;
  }
    
  public Double getIP_CUR()
  {
    return IP_CUR;
  }
    
  public void setIP_CUR(Double IP_CUR)
  {
    this.IP_CUR = IP_CUR;
  }
    
  public Double getIP_RETURN()
  {
    return IP_RETURN;
  }
    
  public void setIP_RETURN(Double IP_RETURN)
  {
    this.IP_RETURN = IP_RETURN;
  }
    
  public Double getIP_RET_TIME()
  {
    return IP_RET_TIME;
  }
    
  public void setIP_RET_TIME(Double IP_RET_TIME)
  {
    this.IP_RET_TIME = IP_RET_TIME;
  }
    
  public Double getIP_RATE()
  {
    return IP_RATE;
  }
    
  public void setIP_RATE(Double IP_RATE)
  {
    this.IP_RATE = IP_RATE;
  }
    
  public Double getQ_RATE()
  {
    return Q_RATE;
  }
    
  public void setQ_RATE(Double Q_RATE)
  {
    this.Q_RATE = Q_RATE;
  }
    
  public Double getIMAX()
  {
    return IMAX;
  }
    
  public void setIMAX(Double IMAX)
  {
    this.IMAX = IMAX;
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
    return "BpaSwi_WGWGen ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", GW_TYPE = " + GW_TYPE
	 + ", NG = " + NG
	 + ", PPER = " + PPER
	 + ", QPER = " + QPER
	 + ", IP_CUR = " + IP_CUR
	 + ", IP_RETURN = " + IP_RETURN
	 + ", IP_RET_TIME = " + IP_RET_TIME
	 + ", IP_RATE = " + IP_RATE
	 + ", Q_RATE = " + Q_RATE
	 + ", IMAX = " + IMAX
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
