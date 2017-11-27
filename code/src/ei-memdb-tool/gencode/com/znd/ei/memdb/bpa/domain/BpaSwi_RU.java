package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*低频线路断开保护(RU)	*
***********************/
public class BpaSwi_RU  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称1
  private String RU_BusI;
  
  //基准电压1(kV)
  private Double RU_kVI;
  
  //母线名称2
  private String RU_BusJ;
  
  //基准电压2(kV)
  private Double RU_kVJ;
  
  //并联线路的回路标志
  private Integer RU_Loop;
  
  //母线频率的门槛值(Hz)
  private Double RU_FTrip;
  
  //继电器动作所需时延(周)
  private Double RU_TRelay;
  
  //通讯和开关动作时间(周)
  private Double RU_TTrip;
  
  //传送操作时延(周)
  private Double RU_TDelay;
  
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
    
  public String getRU_BusI()
  {
    return RU_BusI;
  }
    
  public void setRU_BusI(String RU_BusI)
  {
    this.RU_BusI = RU_BusI;
  }
    
  public Double getRU_kVI()
  {
    return RU_kVI;
  }
    
  public void setRU_kVI(Double RU_kVI)
  {
    this.RU_kVI = RU_kVI;
  }
    
  public String getRU_BusJ()
  {
    return RU_BusJ;
  }
    
  public void setRU_BusJ(String RU_BusJ)
  {
    this.RU_BusJ = RU_BusJ;
  }
    
  public Double getRU_kVJ()
  {
    return RU_kVJ;
  }
    
  public void setRU_kVJ(Double RU_kVJ)
  {
    this.RU_kVJ = RU_kVJ;
  }
    
  public Integer getRU_Loop()
  {
    return RU_Loop;
  }
    
  public void setRU_Loop(Integer RU_Loop)
  {
    this.RU_Loop = RU_Loop;
  }
    
  public Double getRU_FTrip()
  {
    return RU_FTrip;
  }
    
  public void setRU_FTrip(Double RU_FTrip)
  {
    this.RU_FTrip = RU_FTrip;
  }
    
  public Double getRU_TRelay()
  {
    return RU_TRelay;
  }
    
  public void setRU_TRelay(Double RU_TRelay)
  {
    this.RU_TRelay = RU_TRelay;
  }
    
  public Double getRU_TTrip()
  {
    return RU_TTrip;
  }
    
  public void setRU_TTrip(Double RU_TTrip)
  {
    this.RU_TTrip = RU_TTrip;
  }
    
  public Double getRU_TDelay()
  {
    return RU_TDelay;
  }
    
  public void setRU_TDelay(Double RU_TDelay)
  {
    this.RU_TDelay = RU_TDelay;
  }
    
  public String toString()
  {
    return "BpaSwi_RU ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", RU_BusI = " + RU_BusI
	 + ", RU_kVI = " + RU_kVI
	 + ", RU_BusJ = " + RU_BusJ
	 + ", RU_kVJ = " + RU_kVJ
	 + ", RU_Loop = " + RU_Loop
	 + ", RU_FTrip = " + RU_FTrip
	 + ", RU_TRelay = " + RU_TRelay
	 + ", RU_TTrip = " + RU_TTrip
	 + ", RU_TDelay = " + RU_TDelay+"]";
  }
    
}
    
