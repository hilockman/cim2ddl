package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*线路零序参数模型(LO)	*
***********************/
public class BpaSwi_LO  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称1
  private String LO_BusI;
  
  //基准电压1(kV)
  private Double LO_kVI;
  
  //母线名称2
  private String LO_BusJ;
  
  //基准电压2(kV)
  private Double LO_kVJ;
  
  //并联线路的回路标志
  private Integer LO_Loop;
  
  //线路零序电阻(pu)
  private Double LO_R0;
  
  //线路零序电抗(pu)
  private Double LO_X0;
  
  //线路BUSA侧零序对地电导(pu)
  private Double LO_Ga0;
  
  //线路BUSA侧零序对地电纳(pu)
  private Double LO_Ba0;
  
  //线路BUSB侧零序对地电导(pu)
  private Double LO_Gb0;
  
  //线路BUSB侧零序对地电纳(pu)
  private Double LO_Bb0;
  
  //线路名称
  private String KeyName;
  
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
    
  public String getLO_BusI()
  {
    return LO_BusI;
  }
    
  public void setLO_BusI(String LO_BusI)
  {
    this.LO_BusI = LO_BusI;
  }
    
  public Double getLO_kVI()
  {
    return LO_kVI;
  }
    
  public void setLO_kVI(Double LO_kVI)
  {
    this.LO_kVI = LO_kVI;
  }
    
  public String getLO_BusJ()
  {
    return LO_BusJ;
  }
    
  public void setLO_BusJ(String LO_BusJ)
  {
    this.LO_BusJ = LO_BusJ;
  }
    
  public Double getLO_kVJ()
  {
    return LO_kVJ;
  }
    
  public void setLO_kVJ(Double LO_kVJ)
  {
    this.LO_kVJ = LO_kVJ;
  }
    
  public Integer getLO_Loop()
  {
    return LO_Loop;
  }
    
  public void setLO_Loop(Integer LO_Loop)
  {
    this.LO_Loop = LO_Loop;
  }
    
  public Double getLO_R0()
  {
    return LO_R0;
  }
    
  public void setLO_R0(Double LO_R0)
  {
    this.LO_R0 = LO_R0;
  }
    
  public Double getLO_X0()
  {
    return LO_X0;
  }
    
  public void setLO_X0(Double LO_X0)
  {
    this.LO_X0 = LO_X0;
  }
    
  public Double getLO_Ga0()
  {
    return LO_Ga0;
  }
    
  public void setLO_Ga0(Double LO_Ga0)
  {
    this.LO_Ga0 = LO_Ga0;
  }
    
  public Double getLO_Ba0()
  {
    return LO_Ba0;
  }
    
  public void setLO_Ba0(Double LO_Ba0)
  {
    this.LO_Ba0 = LO_Ba0;
  }
    
  public Double getLO_Gb0()
  {
    return LO_Gb0;
  }
    
  public void setLO_Gb0(Double LO_Gb0)
  {
    this.LO_Gb0 = LO_Gb0;
  }
    
  public Double getLO_Bb0()
  {
    return LO_Bb0;
  }
    
  public void setLO_Bb0(Double LO_Bb0)
  {
    this.LO_Bb0 = LO_Bb0;
  }
    
  public String getKeyName()
  {
    return KeyName;
  }
    
  public void setKeyName(String KeyName)
  {
    this.KeyName = KeyName;
  }
    
  public String toString()
  {
    return "BpaSwi_LO ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", LO_BusI = " + LO_BusI
	 + ", LO_kVI = " + LO_kVI
	 + ", LO_BusJ = " + LO_BusJ
	 + ", LO_kVJ = " + LO_kVJ
	 + ", LO_Loop = " + LO_Loop
	 + ", LO_R0 = " + LO_R0
	 + ", LO_X0 = " + LO_X0
	 + ", LO_Ga0 = " + LO_Ga0
	 + ", LO_Ba0 = " + LO_Ba0
	 + ", LO_Gb0 = " + LO_Gb0
	 + ", LO_Bb0 = " + LO_Bb0
	 + ", KeyName = " + KeyName+"]";
  }
    
}
    
