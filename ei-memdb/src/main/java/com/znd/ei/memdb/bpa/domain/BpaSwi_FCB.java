package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*励磁系统继续卡(F#)	*
***********************/
public class BpaSwi_FCB  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名
  private String ACBus_Name;
  
  //基准电压
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //IPID
  private Integer FCB_IPID;
  
  //并联PID环节的比例环节系数
  private Double FCB_KP;
  
  //并联PID环节的积分环节系数
  private Double FCB_KI;
  
  //并联PID环节的微分环节系数
  private Double FCB_KD;
  
  //并联PID环节的微分环节时间常数(秒)
  private Double FCB_TD;
  
  //并联PID环节的积分环节限幅最大值
  private Double FCB_INTMAX;
  
  //并联PID环节的积分环节限幅最小值
  private Double FCB_INTMIN;
  
  //并联PID环节的微分环节限幅最大值
  private Double FCB_DEVMAX;
  
  //并联PID环节的微分环节限幅最小值
  private Double FCB_DEVMIN;
  
  //串联PID环节的限幅最大值
  private Double FCB_VAlMax;
  
  //串联PID环节的限幅最小值
  private Double FCB_VAlMin;
  
  //FU、FV励磁模型是否含有可控硅整流器输出的修订
  private Integer FCB_IFUFV;
  
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
    
  public Integer getFCB_IPID()
  {
    return FCB_IPID;
  }
    
  public void setFCB_IPID(Integer FCB_IPID)
  {
    this.FCB_IPID = FCB_IPID;
  }
    
  public Double getFCB_KP()
  {
    return FCB_KP;
  }
    
  public void setFCB_KP(Double FCB_KP)
  {
    this.FCB_KP = FCB_KP;
  }
    
  public Double getFCB_KI()
  {
    return FCB_KI;
  }
    
  public void setFCB_KI(Double FCB_KI)
  {
    this.FCB_KI = FCB_KI;
  }
    
  public Double getFCB_KD()
  {
    return FCB_KD;
  }
    
  public void setFCB_KD(Double FCB_KD)
  {
    this.FCB_KD = FCB_KD;
  }
    
  public Double getFCB_TD()
  {
    return FCB_TD;
  }
    
  public void setFCB_TD(Double FCB_TD)
  {
    this.FCB_TD = FCB_TD;
  }
    
  public Double getFCB_INTMAX()
  {
    return FCB_INTMAX;
  }
    
  public void setFCB_INTMAX(Double FCB_INTMAX)
  {
    this.FCB_INTMAX = FCB_INTMAX;
  }
    
  public Double getFCB_INTMIN()
  {
    return FCB_INTMIN;
  }
    
  public void setFCB_INTMIN(Double FCB_INTMIN)
  {
    this.FCB_INTMIN = FCB_INTMIN;
  }
    
  public Double getFCB_DEVMAX()
  {
    return FCB_DEVMAX;
  }
    
  public void setFCB_DEVMAX(Double FCB_DEVMAX)
  {
    this.FCB_DEVMAX = FCB_DEVMAX;
  }
    
  public Double getFCB_DEVMIN()
  {
    return FCB_DEVMIN;
  }
    
  public void setFCB_DEVMIN(Double FCB_DEVMIN)
  {
    this.FCB_DEVMIN = FCB_DEVMIN;
  }
    
  public Double getFCB_VAlMax()
  {
    return FCB_VAlMax;
  }
    
  public void setFCB_VAlMax(Double FCB_VAlMax)
  {
    this.FCB_VAlMax = FCB_VAlMax;
  }
    
  public Double getFCB_VAlMin()
  {
    return FCB_VAlMin;
  }
    
  public void setFCB_VAlMin(Double FCB_VAlMin)
  {
    this.FCB_VAlMin = FCB_VAlMin;
  }
    
  public Integer getFCB_IFUFV()
  {
    return FCB_IFUFV;
  }
    
  public void setFCB_IFUFV(Integer FCB_IFUFV)
  {
    this.FCB_IFUFV = FCB_IFUFV;
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
    return "BpaSwi_FCB ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", FCB_IPID = " + FCB_IPID
	 + ", FCB_KP = " + FCB_KP
	 + ", FCB_KI = " + FCB_KI
	 + ", FCB_KD = " + FCB_KD
	 + ", FCB_TD = " + FCB_TD
	 + ", FCB_INTMAX = " + FCB_INTMAX
	 + ", FCB_INTMIN = " + FCB_INTMIN
	 + ", FCB_DEVMAX = " + FCB_DEVMAX
	 + ", FCB_DEVMIN = " + FCB_DEVMIN
	 + ", FCB_VAlMax = " + FCB_VAlMax
	 + ", FCB_VAlMin = " + FCB_VAlMin
	 + ", FCB_IFUFV = " + FCB_IFUFV
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
