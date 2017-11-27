package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*抽样状态下越限设备	*
***********************/
public class FStateOvlDev  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //状态ID
  private Integer FStateId;
  
  //状态序号
  private Integer FStateNo;
  
  //越限设备类型
  private Integer DevTyp;
  
  //越限设备索引
  private Integer DevIdx;
  
  //越限值(MW)
  private Double OvLmtP;
  
  //额定值(MW)
  private Double Rated;
  
  //消限值(MW)
  private Double AdLmtP;
  
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
    
  public Integer getDevTyp()
  {
    return DevTyp;
  }
    
  public void setDevTyp(Integer DevTyp)
  {
    this.DevTyp = DevTyp;
  }
    
  public Integer getDevIdx()
  {
    return DevIdx;
  }
    
  public void setDevIdx(Integer DevIdx)
  {
    this.DevIdx = DevIdx;
  }
    
  public Double getOvLmtP()
  {
    return OvLmtP;
  }
    
  public void setOvLmtP(Double OvLmtP)
  {
    this.OvLmtP = OvLmtP;
  }
    
  public Double getRated()
  {
    return Rated;
  }
    
  public void setRated(Double Rated)
  {
    this.Rated = Rated;
  }
    
  public Double getAdLmtP()
  {
    return AdLmtP;
  }
    
  public void setAdLmtP(Double AdLmtP)
  {
    this.AdLmtP = AdLmtP;
  }
    
  public String toString()
  {
    return "FStateOvlDev ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", FStateId = " + FStateId
	 + ", FStateNo = " + FStateNo
	 + ", DevTyp = " + DevTyp
	 + ", DevIdx = " + DevIdx
	 + ", OvLmtP = " + OvLmtP
	 + ", Rated = " + Rated
	 + ", AdLmtP = " + AdLmtP+"]";
  }
    
}
    
