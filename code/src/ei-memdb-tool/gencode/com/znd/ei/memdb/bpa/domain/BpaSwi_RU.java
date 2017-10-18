package com.znd.ei.memdb.bpa.domain;


/**********************
*低频线路断开保护(RU)	*
***********************/
public class BpaSwi_RU
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称1
  private String rU_BusI;
  
  //基准电压1(kV)
  private Double rU_kVI;
  
  //母线名称2
  private String rU_BusJ;
  
  //基准电压2(kV)
  private Double rU_kVJ;
  
  //并联线路的回路标志
  private Integer rU_Loop;
  
  //母线频率的门槛值(Hz)
  private Double rU_FTrip;
  
  //继电器动作所需时延(周)
  private Double rU_TRelay;
  
  //通讯和开关动作时间(周)
  private Double rU_TTrip;
  
  //传送操作时延(周)
  private Double rU_TDelay;
  
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
    
  public String getRU_BusI()
  {
    return rU_BusI;
  }
    
  public void setRU_BusI(String rU_BusI)
  {
    this.rU_BusI = rU_BusI;
  }
    
  public Double getRU_kVI()
  {
    return rU_kVI;
  }
    
  public void setRU_kVI(Double rU_kVI)
  {
    this.rU_kVI = rU_kVI;
  }
    
  public String getRU_BusJ()
  {
    return rU_BusJ;
  }
    
  public void setRU_BusJ(String rU_BusJ)
  {
    this.rU_BusJ = rU_BusJ;
  }
    
  public Double getRU_kVJ()
  {
    return rU_kVJ;
  }
    
  public void setRU_kVJ(Double rU_kVJ)
  {
    this.rU_kVJ = rU_kVJ;
  }
    
  public Integer getRU_Loop()
  {
    return rU_Loop;
  }
    
  public void setRU_Loop(Integer rU_Loop)
  {
    this.rU_Loop = rU_Loop;
  }
    
  public Double getRU_FTrip()
  {
    return rU_FTrip;
  }
    
  public void setRU_FTrip(Double rU_FTrip)
  {
    this.rU_FTrip = rU_FTrip;
  }
    
  public Double getRU_TRelay()
  {
    return rU_TRelay;
  }
    
  public void setRU_TRelay(Double rU_TRelay)
  {
    this.rU_TRelay = rU_TRelay;
  }
    
  public Double getRU_TTrip()
  {
    return rU_TTrip;
  }
    
  public void setRU_TTrip(Double rU_TTrip)
  {
    this.rU_TTrip = rU_TTrip;
  }
    
  public Double getRU_TDelay()
  {
    return rU_TDelay;
  }
    
  public void setRU_TDelay(Double rU_TDelay)
  {
    this.rU_TDelay = rU_TDelay;
  }
    
  public String toString()
  {
    return "BpaSwi_RU ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", rU_BusI = " + rU_BusI
	 + ", rU_kVI = " + rU_kVI
	 + ", rU_BusJ = " + rU_BusJ
	 + ", rU_kVJ = " + rU_kVJ
	 + ", rU_Loop = " + rU_Loop
	 + ", rU_FTrip = " + rU_FTrip
	 + ", rU_TRelay = " + rU_TRelay
	 + ", rU_TTrip = " + rU_TTrip
	 + ", rU_TDelay = " + rU_TDelay+"]";
  }
    
}
    
