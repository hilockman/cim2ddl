package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*小支路清除信息表(ZIL)	*
***********************/
public class BpaDat_ZIL  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称1
  private String ZIL_BusI;
  
  //基准电压1(kV)
  private Double ZIL_kVI;
  
  //母线名称2
  private String ZIL_BusJ;
  
  //基准电压2(kV)
  private Double ZIL_kVJ;
  
  //并联线路的回路标志
  private Integer ZIL_Loop;
  
  //电阻(pu)
  private Double ZIL_R;
  
  //电抗(pu)
  private Double ZIL_X;
  
  //合并母线名称
  private String ZIL_MBus;
  
  //合并基准电压(kV)
  private Double ZIL_MkV;
  
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
    
  public String getZIL_BusI()
  {
    return ZIL_BusI;
  }
    
  public void setZIL_BusI(String ZIL_BusI)
  {
    this.ZIL_BusI = ZIL_BusI;
  }
    
  public Double getZIL_kVI()
  {
    return ZIL_kVI;
  }
    
  public void setZIL_kVI(Double ZIL_kVI)
  {
    this.ZIL_kVI = ZIL_kVI;
  }
    
  public String getZIL_BusJ()
  {
    return ZIL_BusJ;
  }
    
  public void setZIL_BusJ(String ZIL_BusJ)
  {
    this.ZIL_BusJ = ZIL_BusJ;
  }
    
  public Double getZIL_kVJ()
  {
    return ZIL_kVJ;
  }
    
  public void setZIL_kVJ(Double ZIL_kVJ)
  {
    this.ZIL_kVJ = ZIL_kVJ;
  }
    
  public Integer getZIL_Loop()
  {
    return ZIL_Loop;
  }
    
  public void setZIL_Loop(Integer ZIL_Loop)
  {
    this.ZIL_Loop = ZIL_Loop;
  }
    
  public Double getZIL_R()
  {
    return ZIL_R;
  }
    
  public void setZIL_R(Double ZIL_R)
  {
    this.ZIL_R = ZIL_R;
  }
    
  public Double getZIL_X()
  {
    return ZIL_X;
  }
    
  public void setZIL_X(Double ZIL_X)
  {
    this.ZIL_X = ZIL_X;
  }
    
  public String getZIL_MBus()
  {
    return ZIL_MBus;
  }
    
  public void setZIL_MBus(String ZIL_MBus)
  {
    this.ZIL_MBus = ZIL_MBus;
  }
    
  public Double getZIL_MkV()
  {
    return ZIL_MkV;
  }
    
  public void setZIL_MkV(Double ZIL_MkV)
  {
    this.ZIL_MkV = ZIL_MkV;
  }
    
  public String toString()
  {
    return "BpaDat_ZIL ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ZIL_BusI = " + ZIL_BusI
	 + ", ZIL_kVI = " + ZIL_kVI
	 + ", ZIL_BusJ = " + ZIL_BusJ
	 + ", ZIL_kVJ = " + ZIL_kVJ
	 + ", ZIL_Loop = " + ZIL_Loop
	 + ", ZIL_R = " + ZIL_R
	 + ", ZIL_X = " + ZIL_X
	 + ", ZIL_MBus = " + ZIL_MBus
	 + ", ZIL_MkV = " + ZIL_MkV+"]";
  }
    
}
    
