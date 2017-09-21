package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*抽样状态下越限设备	*
***********************/
@Entity
public class FStateOvlDev
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //状态索引
  private Integer fState;
  
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
    
  public Integer getFState() 
  {
    return fState;
  }
    
  public void setFState(Integer fState)
  {
    this.fState = fState;
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
    
}
    
