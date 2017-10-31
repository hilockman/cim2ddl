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
  private Integer fStateId;
  
  //状态序号
  private Integer fStateNo;
  
  //越限设备类型
  private Integer ovlDevTyp;
  
  //越限设备索引
  private Integer ovlDevice;
  
  //调整设备类型
  private Integer adjDevTyp;
  
  //调整设备索引
  private Integer adjDevice;
  
  //功率调整量(MW)
  private Double adjValue;
  
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
    return fStateId;
  }
    
  public void setFStateId(Integer fStateId)
  {
    this.fStateId = fStateId;
  }
    
  public Integer getFStateNo()
  {
    return fStateNo;
  }
    
  public void setFStateNo(Integer fStateNo)
  {
    this.fStateNo = fStateNo;
  }
    
  public Integer getOvlDevTyp()
  {
    return ovlDevTyp;
  }
    
  public void setOvlDevTyp(Integer ovlDevTyp)
  {
    this.ovlDevTyp = ovlDevTyp;
  }
    
  public Integer getOvlDevice()
  {
    return ovlDevice;
  }
    
  public void setOvlDevice(Integer ovlDevice)
  {
    this.ovlDevice = ovlDevice;
  }
    
  public Integer getAdjDevTyp()
  {
    return adjDevTyp;
  }
    
  public void setAdjDevTyp(Integer adjDevTyp)
  {
    this.adjDevTyp = adjDevTyp;
  }
    
  public Integer getAdjDevice()
  {
    return adjDevice;
  }
    
  public void setAdjDevice(Integer adjDevice)
  {
    this.adjDevice = adjDevice;
  }
    
  public Double getAdjValue()
  {
    return adjValue;
  }
    
  public void setAdjValue(Double adjValue)
  {
    this.adjValue = adjValue;
  }
    
  public String toString()
  {
    return "FStateOvlAd ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", fStateId = " + fStateId
	 + ", fStateNo = " + fStateNo
	 + ", ovlDevTyp = " + ovlDevTyp
	 + ", ovlDevice = " + ovlDevice
	 + ", adjDevTyp = " + adjDevTyp
	 + ", adjDevice = " + adjDevice
	 + ", adjValue = " + adjValue+"]";
  }
    
}
    
