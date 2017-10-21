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
  private String cardKey;
  
  //母线名称1
  private String lO_BusI;
  
  //基准电压1(kV)
  private Double lO_kVI;
  
  //母线名称2
  private String lO_BusJ;
  
  //基准电压2(kV)
  private Double lO_kVJ;
  
  //并联线路的回路标志
  private Integer lO_Loop;
  
  //线路零序电阻(pu)
  private Double lO_R0;
  
  //线路零序电抗(pu)
  private Double lO_X0;
  
  //线路BUSA侧零序对地电导(pu)
  private Double lO_Ga0;
  
  //线路BUSA侧零序对地电纳(pu)
  private Double lO_Ba0;
  
  //线路BUSB侧零序对地电导(pu)
  private Double lO_Gb0;
  
  //线路BUSB侧零序对地电纳(pu)
  private Double lO_Bb0;
  
  //线路名称
  private String keyName;
  
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
    
  public String getLO_BusI()
  {
    return lO_BusI;
  }
    
  public void setLO_BusI(String lO_BusI)
  {
    this.lO_BusI = lO_BusI;
  }
    
  public Double getLO_kVI()
  {
    return lO_kVI;
  }
    
  public void setLO_kVI(Double lO_kVI)
  {
    this.lO_kVI = lO_kVI;
  }
    
  public String getLO_BusJ()
  {
    return lO_BusJ;
  }
    
  public void setLO_BusJ(String lO_BusJ)
  {
    this.lO_BusJ = lO_BusJ;
  }
    
  public Double getLO_kVJ()
  {
    return lO_kVJ;
  }
    
  public void setLO_kVJ(Double lO_kVJ)
  {
    this.lO_kVJ = lO_kVJ;
  }
    
  public Integer getLO_Loop()
  {
    return lO_Loop;
  }
    
  public void setLO_Loop(Integer lO_Loop)
  {
    this.lO_Loop = lO_Loop;
  }
    
  public Double getLO_R0()
  {
    return lO_R0;
  }
    
  public void setLO_R0(Double lO_R0)
  {
    this.lO_R0 = lO_R0;
  }
    
  public Double getLO_X0()
  {
    return lO_X0;
  }
    
  public void setLO_X0(Double lO_X0)
  {
    this.lO_X0 = lO_X0;
  }
    
  public Double getLO_Ga0()
  {
    return lO_Ga0;
  }
    
  public void setLO_Ga0(Double lO_Ga0)
  {
    this.lO_Ga0 = lO_Ga0;
  }
    
  public Double getLO_Ba0()
  {
    return lO_Ba0;
  }
    
  public void setLO_Ba0(Double lO_Ba0)
  {
    this.lO_Ba0 = lO_Ba0;
  }
    
  public Double getLO_Gb0()
  {
    return lO_Gb0;
  }
    
  public void setLO_Gb0(Double lO_Gb0)
  {
    this.lO_Gb0 = lO_Gb0;
  }
    
  public Double getLO_Bb0()
  {
    return lO_Bb0;
  }
    
  public void setLO_Bb0(Double lO_Bb0)
  {
    this.lO_Bb0 = lO_Bb0;
  }
    
  public String getKeyName()
  {
    return keyName;
  }
    
  public void setKeyName(String keyName)
  {
    this.keyName = keyName;
  }
    
  public String toString()
  {
    return "BpaSwi_LO ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", lO_BusI = " + lO_BusI
	 + ", lO_kVI = " + lO_kVI
	 + ", lO_BusJ = " + lO_BusJ
	 + ", lO_kVJ = " + lO_kVJ
	 + ", lO_Loop = " + lO_Loop
	 + ", lO_R0 = " + lO_R0
	 + ", lO_X0 = " + lO_X0
	 + ", lO_Ga0 = " + lO_Ga0
	 + ", lO_Ba0 = " + lO_Ba0
	 + ", lO_Gb0 = " + lO_Gb0
	 + ", lO_Bb0 = " + lO_Bb0
	 + ", keyName = " + keyName+"]";
  }
    
}
    
