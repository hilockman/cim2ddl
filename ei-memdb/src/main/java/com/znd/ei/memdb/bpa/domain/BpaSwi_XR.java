package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*对地支路零序模型(XR)	*
***********************/
public class BpaSwi_XR  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称
  private String ACBus_Name;
  
  //基准电压(kV)
  private Double ACBus_kV;
  
  //对地支路零序电阻(PU)
  private Double XR_R0;
  
  //对地支路零序电抗(PU)
  private Double XR_X0;
  
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
    
  public String getACBus_Name()
  {
    return ACBus_Name;
  }
    
  public void setACBus_Name(String ACBus_Name)
  {
    this.ACBus_Name = ACBus_Name;
  }
    
  public Double getACBus_kV()
  {
    return ACBus_kV;
  }
    
  public void setACBus_kV(Double ACBus_kV)
  {
    this.ACBus_kV = ACBus_kV;
  }
    
  public Double getXR_R0()
  {
    return XR_R0;
  }
    
  public void setXR_R0(Double XR_R0)
  {
    this.XR_R0 = XR_R0;
  }
    
  public Double getXR_X0()
  {
    return XR_X0;
  }
    
  public void setXR_X0(Double XR_X0)
  {
    this.XR_X0 = XR_X0;
  }
    
  public String toString()
  {
    return "BpaSwi_XR ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", XR_R0 = " + XR_R0
	 + ", XR_X0 = " + XR_X0+"]";
  }
    
}
    
