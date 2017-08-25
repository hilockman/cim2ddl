package com.znd.ei.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*抽样状态下故障设备	*
***********************/
@Entity
public class FStateFDev
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //状态索引
  private Integer fState;
  
  //故障设备类型
  private Integer fDevTyp;
  
  //故障设备索引
  private Integer fDevIdx;
  
  //设备故障位置
  private Integer dFltPos;
  
  //设备故障类型
  private Integer dFltTyp;
  
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
    
  public Integer getFDevTyp() 
  {
    return fDevTyp;
  }
    
  public void setFDevTyp(Integer fDevTyp)
  {
    this.fDevTyp = fDevTyp;
  }
    
  public Integer getFDevIdx() 
  {
    return fDevIdx;
  }
    
  public void setFDevIdx(Integer fDevIdx)
  {
    this.fDevIdx = fDevIdx;
  }
    
  public Integer getDFltPos() 
  {
    return dFltPos;
  }
    
  public void setDFltPos(Integer dFltPos)
  {
    this.dFltPos = dFltPos;
  }
    
  public Integer getDFltTyp() 
  {
    return dFltTyp;
  }
    
  public void setDFltTyp(Integer dFltTyp)
  {
    this.dFltTyp = dFltTyp;
  }
    
}
    
