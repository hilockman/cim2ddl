package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*发电机等值负荷(LN)	*
***********************/
public class BpaSwi_GenLn  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //等值发电机名称
  private String aCBus_Name;
  
  //等值发电机电压
  private Double aCBus_kV;
  
  //等值发电机母线索引
  private Integer busPtr;
  
  //直流母线
  private Integer dCBus;
  
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
    
  public String getACBus_Name()
  {
    return aCBus_Name;
  }
    
  public void setACBus_Name(String aCBus_Name)
  {
    this.aCBus_Name = aCBus_Name;
  }
    
  public Double getACBus_kV()
  {
    return aCBus_kV;
  }
    
  public void setACBus_kV(Double aCBus_kV)
  {
    this.aCBus_kV = aCBus_kV;
  }
    
  public Integer getBusPtr()
  {
    return busPtr;
  }
    
  public void setBusPtr(Integer busPtr)
  {
    this.busPtr = busPtr;
  }
    
  public Integer getDCBus()
  {
    return dCBus;
  }
    
  public void setDCBus(Integer dCBus)
  {
    this.dCBus = dCBus;
  }
    
  public String toString()
  {
    return "BpaSwi_GenLn ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", busPtr = " + busPtr
	 + ", dCBus = " + dCBus+"]";
  }
    
}
    
