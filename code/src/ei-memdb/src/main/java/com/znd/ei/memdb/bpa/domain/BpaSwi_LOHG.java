package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*线路高抗零序参数模型(LOHG)	*
***********************/
public class BpaSwi_LOHG  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称1
  private String LOHG_BusI;
  
  //基准电压1(kV)
  private Double LOHG_kVI;
  
  //母线名称2
  private String LOHG_BusJ;
  
  //基准电压2(kV)
  private Double LOHG_kVJ;
  
  //并联线路的回路标志
  private Integer LOHG_Loop;
  
  //线路前侧高抗对应的等值零序电抗(pu)
  private Double LOHG_X0I;
  
  //线路后侧高抗对应的等值零序电抗(pu)
  private Double LOHG_X0J;
  
  //线路高抗名称
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
    
  public String getLOHG_BusI()
  {
    return LOHG_BusI;
  }
    
  public void setLOHG_BusI(String LOHG_BusI)
  {
    this.LOHG_BusI = LOHG_BusI;
  }
    
  public Double getLOHG_kVI()
  {
    return LOHG_kVI;
  }
    
  public void setLOHG_kVI(Double LOHG_kVI)
  {
    this.LOHG_kVI = LOHG_kVI;
  }
    
  public String getLOHG_BusJ()
  {
    return LOHG_BusJ;
  }
    
  public void setLOHG_BusJ(String LOHG_BusJ)
  {
    this.LOHG_BusJ = LOHG_BusJ;
  }
    
  public Double getLOHG_kVJ()
  {
    return LOHG_kVJ;
  }
    
  public void setLOHG_kVJ(Double LOHG_kVJ)
  {
    this.LOHG_kVJ = LOHG_kVJ;
  }
    
  public Integer getLOHG_Loop()
  {
    return LOHG_Loop;
  }
    
  public void setLOHG_Loop(Integer LOHG_Loop)
  {
    this.LOHG_Loop = LOHG_Loop;
  }
    
  public Double getLOHG_X0I()
  {
    return LOHG_X0I;
  }
    
  public void setLOHG_X0I(Double LOHG_X0I)
  {
    this.LOHG_X0I = LOHG_X0I;
  }
    
  public Double getLOHG_X0J()
  {
    return LOHG_X0J;
  }
    
  public void setLOHG_X0J(Double LOHG_X0J)
  {
    this.LOHG_X0J = LOHG_X0J;
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
    return "BpaSwi_LOHG ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", LOHG_BusI = " + LOHG_BusI
	 + ", LOHG_kVI = " + LOHG_kVI
	 + ", LOHG_BusJ = " + LOHG_BusJ
	 + ", LOHG_kVJ = " + LOHG_kVJ
	 + ", LOHG_Loop = " + LOHG_Loop
	 + ", LOHG_X0I = " + LOHG_X0I
	 + ", LOHG_X0J = " + LOHG_X0J
	 + ", KeyName = " + KeyName+"]";
  }
    
}
    
