package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*变压器零序模型(XO)	*
***********************/
public class BpaSwi_XO  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称1
  private String XO_BusI;
  
  //基准电压1(kV)
  private Double XO_kVI;
  
  //母线名称2
  private String XO_BusJ;
  
  //基准电压2(kV)
  private Double XO_kVJ;
  
  //并联线路的回路标志
  private Integer XO_Loop;
  
  //变压器零序电抗的接入方式
  private Integer XO_SID;
  
  //变压器零序电阻(pu)
  private Double XO_R0;
  
  //变压器零序电抗(pu)
  private Double XO_X0;
  
  //变压器名称
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
    
  public String getXO_BusI()
  {
    return XO_BusI;
  }
    
  public void setXO_BusI(String XO_BusI)
  {
    this.XO_BusI = XO_BusI;
  }
    
  public Double getXO_kVI()
  {
    return XO_kVI;
  }
    
  public void setXO_kVI(Double XO_kVI)
  {
    this.XO_kVI = XO_kVI;
  }
    
  public String getXO_BusJ()
  {
    return XO_BusJ;
  }
    
  public void setXO_BusJ(String XO_BusJ)
  {
    this.XO_BusJ = XO_BusJ;
  }
    
  public Double getXO_kVJ()
  {
    return XO_kVJ;
  }
    
  public void setXO_kVJ(Double XO_kVJ)
  {
    this.XO_kVJ = XO_kVJ;
  }
    
  public Integer getXO_Loop()
  {
    return XO_Loop;
  }
    
  public void setXO_Loop(Integer XO_Loop)
  {
    this.XO_Loop = XO_Loop;
  }
    
  public Integer getXO_SID()
  {
    return XO_SID;
  }
    
  public void setXO_SID(Integer XO_SID)
  {
    this.XO_SID = XO_SID;
  }
    
  public Double getXO_R0()
  {
    return XO_R0;
  }
    
  public void setXO_R0(Double XO_R0)
  {
    this.XO_R0 = XO_R0;
  }
    
  public Double getXO_X0()
  {
    return XO_X0;
  }
    
  public void setXO_X0(Double XO_X0)
  {
    this.XO_X0 = XO_X0;
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
    return "BpaSwi_XO ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", XO_BusI = " + XO_BusI
	 + ", XO_kVI = " + XO_kVI
	 + ", XO_BusJ = " + XO_BusJ
	 + ", XO_kVJ = " + XO_kVJ
	 + ", XO_Loop = " + XO_Loop
	 + ", XO_SID = " + XO_SID
	 + ", XO_R0 = " + XO_R0
	 + ", XO_X0 = " + XO_X0
	 + ", KeyName = " + KeyName+"]";
  }
    
}
    
