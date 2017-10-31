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
  private Integer fStateId;
  
  //状态序号
  private Integer fStateNo;
  
  //越限设备类型
  private Integer devTyp;
  
  //越限设备索引
  private Integer devIdx;
  
  //越限值(MW)
  private Double ovLmtP;
  
  //额定值(MW)
  private Double rated;
  
  //消限值(MW)
  private Double adLmtP;
  
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
    
  public Integer getDevTyp()
  {
    return devTyp;
  }
    
  public void setDevTyp(Integer devTyp)
  {
    this.devTyp = devTyp;
  }
    
  public Integer getDevIdx()
  {
    return devIdx;
  }
    
  public void setDevIdx(Integer devIdx)
  {
    this.devIdx = devIdx;
  }
    
  public Double getOvLmtP()
  {
    return ovLmtP;
  }
    
  public void setOvLmtP(Double ovLmtP)
  {
    this.ovLmtP = ovLmtP;
  }
    
  public Double getRated()
  {
    return rated;
  }
    
  public void setRated(Double rated)
  {
    this.rated = rated;
  }
    
  public Double getAdLmtP()
  {
    return adLmtP;
  }
    
  public void setAdLmtP(Double adLmtP)
  {
    this.adLmtP = adLmtP;
  }
    
  public String toString()
  {
    return "FStateOvlDev ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", fStateId = " + fStateId
	 + ", fStateNo = " + fStateNo
	 + ", devTyp = " + devTyp
	 + ", devIdx = " + devIdx
	 + ", ovLmtP = " + ovLmtP
	 + ", rated = " + rated
	 + ", adLmtP = " + adLmtP+"]";
  }
    
}
    
