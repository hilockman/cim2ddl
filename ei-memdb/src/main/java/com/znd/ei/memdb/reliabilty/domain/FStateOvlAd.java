package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*抽样状态下越限调整	*
***********************/
public class FStateOvlAd  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //状态ID
  private Integer FStateId;
  
  //状态序号
  private Integer FStateNo;
  
  //越限设备类型
  private Integer OvlDevTyp;
  
  //越限设备索引
  private Integer OvlDevice;
  
  //调整设备类型
  private Integer AdjDevTyp;
  
  //调整设备索引
  private Integer AdjDevice;
  
  //功率调整量(兆瓦)
  private Double AdjValue;
  
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
    
  public Integer getFStateId()
  {
    return FStateId;
  }
    
  public void setFStateId(Integer FStateId)
  {
    this.FStateId = FStateId;
  }
    
  public Integer getFStateNo()
  {
    return FStateNo;
  }
    
  public void setFStateNo(Integer FStateNo)
  {
    this.FStateNo = FStateNo;
  }
    
  public Integer getOvlDevTyp()
  {
    return OvlDevTyp;
  }
    
  public void setOvlDevTyp(Integer OvlDevTyp)
  {
    this.OvlDevTyp = OvlDevTyp;
  }
    
  public Integer getOvlDevice()
  {
    return OvlDevice;
  }
    
  public void setOvlDevice(Integer OvlDevice)
  {
    this.OvlDevice = OvlDevice;
  }
    
  public Integer getAdjDevTyp()
  {
    return AdjDevTyp;
  }
    
  public void setAdjDevTyp(Integer AdjDevTyp)
  {
    this.AdjDevTyp = AdjDevTyp;
  }
    
  public Integer getAdjDevice()
  {
    return AdjDevice;
  }
    
  public void setAdjDevice(Integer AdjDevice)
  {
    this.AdjDevice = AdjDevice;
  }
    
  public Double getAdjValue()
  {
    return AdjValue;
  }
    
  public void setAdjValue(Double AdjValue)
  {
    this.AdjValue = AdjValue;
  }
    
  public String toString()
  {
    return "FStateOvlAd ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", FStateId = " + FStateId
	 + ", FStateNo = " + FStateNo
	 + ", OvlDevTyp = " + OvlDevTyp
	 + ", OvlDevice = " + OvlDevice
	 + ", AdjDevTyp = " + AdjDevTyp
	 + ", AdjDevice = " + AdjDevice
	 + ", AdjValue = " + AdjValue+"]";
  }
    
}
    
