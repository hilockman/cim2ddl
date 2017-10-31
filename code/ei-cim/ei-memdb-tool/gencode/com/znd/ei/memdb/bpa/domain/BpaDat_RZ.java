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
  private String cardKey;
  
  //所有者
  private String rZ_Owner;
  
  //母线名称1
  private String rZ_BusI;
  
  //基准电压1(kV)
  private Double rZ_kVI;
  
  //母线名称2
  private String rZ_BusJ;
  
  //基准电压2(kV)
  private Double rZ_kVJ;
  
  //并联线路的回路标志
  private Integer rZ_Loop;
  
  //分段串连而成的线路的段号
  private Integer rZ_Section;
  
  //控制方式
  private Integer rZ_Mode;
  
  //线路有功潮流最大值(MW)
  private Double rZ_Pcmax;
  
  //线路有功潮流最小值(MW)
  private Double rZ_Pcmin;
  
  //线路额定电流值(A)
  private Double rZ_In;
  
  //线路电抗最大(pu)
  private Double rZ_Xijmax;
  
  //线路电抗最小(pu)
  private Double rZ_Xijmin;
  
  //串补名称
  private String keyName;
  
  //线路电抗I母线索引
  private Integer iRBus;
  
  //线路电抗Z母线索引
  private Integer zRBus;
  
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
    
  public String getRZ_Owner()
  {
    return rZ_Owner;
  }
    
  public void setRZ_Owner(String rZ_Owner)
  {
    this.rZ_Owner = rZ_Owner;
  }
    
  public String getRZ_BusI()
  {
    return rZ_BusI;
  }
    
  public void setRZ_BusI(String rZ_BusI)
  {
    this.rZ_BusI = rZ_BusI;
  }
    
  public Double getRZ_kVI()
  {
    return rZ_kVI;
  }
    
  public void setRZ_kVI(Double rZ_kVI)
  {
    this.rZ_kVI = rZ_kVI;
  }
    
  public String getRZ_BusJ()
  {
    return rZ_BusJ;
  }
    
  public void setRZ_BusJ(String rZ_BusJ)
  {
    this.rZ_BusJ = rZ_BusJ;
  }
    
  public Double getRZ_kVJ()
  {
    return rZ_kVJ;
  }
    
  public void setRZ_kVJ(Double rZ_kVJ)
  {
    this.rZ_kVJ = rZ_kVJ;
  }
    
  public Integer getRZ_Loop()
  {
    return rZ_Loop;
  }
    
  public void setRZ_Loop(Integer rZ_Loop)
  {
    this.rZ_Loop = rZ_Loop;
  }
    
  public Integer getRZ_Section()
  {
    return rZ_Section;
  }
    
  public void setRZ_Section(Integer rZ_Section)
  {
    this.rZ_Section = rZ_Section;
  }
    
  public Integer getRZ_Mode()
  {
    return rZ_Mode;
  }
    
  public void setRZ_Mode(Integer rZ_Mode)
  {
    this.rZ_Mode = rZ_Mode;
  }
    
  public Double getRZ_Pcmax()
  {
    return rZ_Pcmax;
  }
    
  public void setRZ_Pcmax(Double rZ_Pcmax)
  {
    this.rZ_Pcmax = rZ_Pcmax;
  }
    
  public Double getRZ_Pcmin()
  {
    return rZ_Pcmin;
  }
    
  public void setRZ_Pcmin(Double rZ_Pcmin)
  {
    this.rZ_Pcmin = rZ_Pcmin;
  }
    
  public Double getRZ_In()
  {
    return rZ_In;
  }
    
  public void setRZ_In(Double rZ_In)
  {
    this.rZ_In = rZ_In;
  }
    
  public Double getRZ_Xijmax()
  {
    return rZ_Xijmax;
  }
    
  public void setRZ_Xijmax(Double rZ_Xijmax)
  {
    this.rZ_Xijmax = rZ_Xijmax;
  }
    
  public Double getRZ_Xijmin()
  {
    return rZ_Xijmin;
  }
    
  public void setRZ_Xijmin(Double rZ_Xijmin)
  {
    this.rZ_Xijmin = rZ_Xijmin;
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
    return status;
  }
    
  public void setStatus(Integer status)
  {
    this.status = status;
  }
    
  public String toString()
  {
    return "BpaDat_RZ ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", rZ_Owner = " + rZ_Owner
	 + ", rZ_BusI = " + rZ_BusI
	 + ", rZ_kVI = " + rZ_kVI
	 + ", rZ_BusJ = " + rZ_BusJ
	 + ", rZ_kVJ = " + rZ_kVJ
	 + ", rZ_Loop = " + rZ_Loop
	 + ", rZ_Section = " + rZ_Section
	 + ", rZ_Mode = " + rZ_Mode
	 + ", rZ_Pcmax = " + rZ_Pcmax
	 + ", rZ_Pcmin = " + rZ_Pcmin
	 + ", rZ_In = " + rZ_In
	 + ", rZ_Xijmax = " + rZ_Xijmax
	 + ", rZ_Xijmin = " + rZ_Xijmin
	 + ", keyName = " + keyName
	 + ", iRBus = " + iRBus
	 + ", zRBus = " + zRBus
	 + ", status = " + status+"]";
  }
    
}
    
