package com.znd.ei.memdb.bpa.domain;


/**********************
*对地支路零序模型(XR)	*
***********************/
public class BpaSwi_XR
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称
  private String aCBus_Name;
  
  //基准电压(kV)
  private Double aCBus_kV;
  
  //对地支路零序电阻(PU)
  private Double xR_R0;
  
  //对地支路零序电抗(PU)
  private Double xR_X0;
  
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
    
  public Double getXR_R0()
  {
    return xR_R0;
  }
    
  public void setXR_R0(Double xR_R0)
  {
    this.xR_R0 = xR_R0;
  }
    
  public Double getXR_X0()
  {
    return xR_X0;
  }
    
  public void setXR_X0(Double xR_X0)
  {
    this.xR_X0 = xR_X0;
  }
    
  public String toString()
  {
    return "BpaSwi_XR ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"aCBus_Name"=aCBus_Name,
	"aCBus_kV"=aCBus_kV,
	"xR_R0"=xR_R0,
	"xR_X0"=xR_X0+"]"
  }
    
}
    
