package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*线路串补表(RZ)	*
***********************/
public class BpaDat_RZ  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //所有者
  private String RZ_Owner;
  
  //母线名称1
  private String RZ_BusI;
  
  //基准电压1(kV)
  private Double RZ_kVI;
  
  //母线名称2
  private String RZ_BusJ;
  
  //基准电压2(kV)
  private Double RZ_kVJ;
  
  //并联线路的回路标志
  private Integer RZ_Loop;
  
  //分段串连而成的线路的段号
  private Integer RZ_Section;
  
  //控制方式
  private Integer RZ_Mode;
  
  //线路有功潮流最大值(MW)
  private Double RZ_Pcmax;
  
  //线路有功潮流最小值(MW)
  private Double RZ_Pcmin;
  
  //线路额定电流值(A)
  private Double RZ_In;
  
  //线路电抗最大(pu)
  private Double RZ_Xijmax;
  
  //线路电抗最小(pu)
  private Double RZ_Xijmin;
  
  //串补名称
  private String KeyName;
  
  //线路电抗I母线索引
  private Integer iRBus;
  
  //线路电抗Z母线索引
  private Integer zRBus;
  
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
    
  public String getRZ_Owner()
  {
    return RZ_Owner;
  }
    
  public void setRZ_Owner(String RZ_Owner)
  {
    this.RZ_Owner = RZ_Owner;
  }
    
  public String getRZ_BusI()
  {
    return RZ_BusI;
  }
    
  public void setRZ_BusI(String RZ_BusI)
  {
    this.RZ_BusI = RZ_BusI;
  }
    
  public Double getRZ_kVI()
  {
    return RZ_kVI;
  }
    
  public void setRZ_kVI(Double RZ_kVI)
  {
    this.RZ_kVI = RZ_kVI;
  }
    
  public String getRZ_BusJ()
  {
    return RZ_BusJ;
  }
    
  public void setRZ_BusJ(String RZ_BusJ)
  {
    this.RZ_BusJ = RZ_BusJ;
  }
    
  public Double getRZ_kVJ()
  {
    return RZ_kVJ;
  }
    
  public void setRZ_kVJ(Double RZ_kVJ)
  {
    this.RZ_kVJ = RZ_kVJ;
  }
    
  public Integer getRZ_Loop()
  {
    return RZ_Loop;
  }
    
  public void setRZ_Loop(Integer RZ_Loop)
  {
    this.RZ_Loop = RZ_Loop;
  }
    
  public Integer getRZ_Section()
  {
    return RZ_Section;
  }
    
  public void setRZ_Section(Integer RZ_Section)
  {
    this.RZ_Section = RZ_Section;
  }
    
  public Integer getRZ_Mode()
  {
    return RZ_Mode;
  }
    
  public void setRZ_Mode(Integer RZ_Mode)
  {
    this.RZ_Mode = RZ_Mode;
  }
    
  public Double getRZ_Pcmax()
  {
    return RZ_Pcmax;
  }
    
  public void setRZ_Pcmax(Double RZ_Pcmax)
  {
    this.RZ_Pcmax = RZ_Pcmax;
  }
    
  public Double getRZ_Pcmin()
  {
    return RZ_Pcmin;
  }
    
  public void setRZ_Pcmin(Double RZ_Pcmin)
  {
    this.RZ_Pcmin = RZ_Pcmin;
  }
    
  public Double getRZ_In()
  {
    return RZ_In;
  }
    
  public void setRZ_In(Double RZ_In)
  {
    this.RZ_In = RZ_In;
  }
    
  public Double getRZ_Xijmax()
  {
    return RZ_Xijmax;
  }
    
  public void setRZ_Xijmax(Double RZ_Xijmax)
  {
    this.RZ_Xijmax = RZ_Xijmax;
  }
    
  public Double getRZ_Xijmin()
  {
    return RZ_Xijmin;
  }
    
  public void setRZ_Xijmin(Double RZ_Xijmin)
  {
    this.RZ_Xijmin = RZ_Xijmin;
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
    
  public Integer getzRBus()
  {
    return zRBus;
  }
    
  public void setzRBus(Integer zRBus)
  {
    this.zRBus = zRBus;
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
    return "BpaDat_RZ ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", RZ_Owner = " + RZ_Owner
	 + ", RZ_BusI = " + RZ_BusI
	 + ", RZ_kVI = " + RZ_kVI
	 + ", RZ_BusJ = " + RZ_BusJ
	 + ", RZ_kVJ = " + RZ_kVJ
	 + ", RZ_Loop = " + RZ_Loop
	 + ", RZ_Section = " + RZ_Section
	 + ", RZ_Mode = " + RZ_Mode
	 + ", RZ_Pcmax = " + RZ_Pcmax
	 + ", RZ_Pcmin = " + RZ_Pcmin
	 + ", RZ_In = " + RZ_In
	 + ", RZ_Xijmax = " + RZ_Xijmax
	 + ", RZ_Xijmin = " + RZ_Xijmin
	 + ", KeyName = " + KeyName
	 + ", iRBus = " + iRBus
	 + ", zRBus = " + zRBus
	 + ", Status = " + Status+"]";
  }
    
}
    
