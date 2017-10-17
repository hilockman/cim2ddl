package com.znd.ei.memdb.bpa.domain;


/**********************
*变压器零序模型(XO)	*
***********************/
public class BpaSwi_XO
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称1
  private String xO_BusI;
  
  //基准电压1(kV)
  private Double xO_kVI;
  
  //母线名称2
  private String xO_BusJ;
  
  //基准电压2(kV)
  private Double xO_kVJ;
  
  //并联线路的回路标志
  private Integer xO_Loop;
  
  //变压器零序电抗的接入方式
  private Integer xO_SID;
  
  //变压器零序电阻(pu)
  private Double xO_R0;
  
  //变压器零序电抗(pu)
  private Double xO_X0;
  
  //变压器名称
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
    
  public String getXO_BusI()
  {
    return xO_BusI;
  }
    
  public void setXO_BusI(String xO_BusI)
  {
    this.xO_BusI = xO_BusI;
  }
    
  public Double getXO_kVI()
  {
    return xO_kVI;
  }
    
  public void setXO_kVI(Double xO_kVI)
  {
    this.xO_kVI = xO_kVI;
  }
    
  public String getXO_BusJ()
  {
    return xO_BusJ;
  }
    
  public void setXO_BusJ(String xO_BusJ)
  {
    this.xO_BusJ = xO_BusJ;
  }
    
  public Double getXO_kVJ()
  {
    return xO_kVJ;
  }
    
  public void setXO_kVJ(Double xO_kVJ)
  {
    this.xO_kVJ = xO_kVJ;
  }
    
  public Integer getXO_Loop()
  {
    return xO_Loop;
  }
    
  public void setXO_Loop(Integer xO_Loop)
  {
    this.xO_Loop = xO_Loop;
  }
    
  public Integer getXO_SID()
  {
    return xO_SID;
  }
    
  public void setXO_SID(Integer xO_SID)
  {
    this.xO_SID = xO_SID;
  }
    
  public Double getXO_R0()
  {
    return xO_R0;
  }
    
  public void setXO_R0(Double xO_R0)
  {
    this.xO_R0 = xO_R0;
  }
    
  public Double getXO_X0()
  {
    return xO_X0;
  }
    
  public void setXO_X0(Double xO_X0)
  {
    this.xO_X0 = xO_X0;
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
    return "BpaSwi_XO ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", xO_BusI = " + xO_BusI
	 + ", xO_kVI = " + xO_kVI
	 + ", xO_BusJ = " + xO_BusJ
	 + ", xO_kVJ = " + xO_kVJ
	 + ", xO_Loop = " + xO_Loop
	 + ", xO_SID = " + xO_SID
	 + ", xO_R0 = " + xO_R0
	 + ", xO_X0 = " + xO_X0
	 + ", keyName = " + keyName+"]";
  }
    
}
    
