package com.znd.ei.memdb.bpa.domain;


/**********************
*小支路清除信息表(ZIL)	*
***********************/
public class BpaDat_ZIL
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称1
  private String zIL_BusI;
  
  //基准电压1(kV)
  private Double zIL_kVI;
  
  //母线名称2
  private String zIL_BusJ;
  
  //基准电压2(kV)
  private Double zIL_kVJ;
  
  //并联线路的回路标志
  private Integer zIL_Loop;
  
  //电阻(pu)
  private Double zIL_R;
  
  //电抗(pu)
  private Double zIL_X;
  
  //合并母线名称
  private String zIL_MBus;
  
  //合并基准电压(kV)
  private Double zIL_MkV;
  
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
    
  public String getZIL_BusI()
  {
    return zIL_BusI;
  }
    
  public void setZIL_BusI(String zIL_BusI)
  {
    this.zIL_BusI = zIL_BusI;
  }
    
  public Double getZIL_kVI()
  {
    return zIL_kVI;
  }
    
  public void setZIL_kVI(Double zIL_kVI)
  {
    this.zIL_kVI = zIL_kVI;
  }
    
  public String getZIL_BusJ()
  {
    return zIL_BusJ;
  }
    
  public void setZIL_BusJ(String zIL_BusJ)
  {
    this.zIL_BusJ = zIL_BusJ;
  }
    
  public Double getZIL_kVJ()
  {
    return zIL_kVJ;
  }
    
  public void setZIL_kVJ(Double zIL_kVJ)
  {
    this.zIL_kVJ = zIL_kVJ;
  }
    
  public Integer getZIL_Loop()
  {
    return zIL_Loop;
  }
    
  public void setZIL_Loop(Integer zIL_Loop)
  {
    this.zIL_Loop = zIL_Loop;
  }
    
  public Double getZIL_R()
  {
    return zIL_R;
  }
    
  public void setZIL_R(Double zIL_R)
  {
    this.zIL_R = zIL_R;
  }
    
  public Double getZIL_X()
  {
    return zIL_X;
  }
    
  public void setZIL_X(Double zIL_X)
  {
    this.zIL_X = zIL_X;
  }
    
  public String getZIL_MBus()
  {
    return zIL_MBus;
  }
    
  public void setZIL_MBus(String zIL_MBus)
  {
    this.zIL_MBus = zIL_MBus;
  }
    
  public Double getZIL_MkV()
  {
    return zIL_MkV;
  }
    
  public void setZIL_MkV(Double zIL_MkV)
  {
    this.zIL_MkV = zIL_MkV;
  }
    
  public String toString()
  {
    return "BpaDat_ZIL ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", zIL_BusI = " + zIL_BusI
	 + ", zIL_kVI = " + zIL_kVI
	 + ", zIL_BusJ = " + zIL_BusJ
	 + ", zIL_kVJ = " + zIL_kVJ
	 + ", zIL_Loop = " + zIL_Loop
	 + ", zIL_R = " + zIL_R
	 + ", zIL_X = " + zIL_X
	 + ", zIL_MBus = " + zIL_MBus
	 + ", zIL_MkV = " + zIL_MkV+"]";
  }
    
}
    
