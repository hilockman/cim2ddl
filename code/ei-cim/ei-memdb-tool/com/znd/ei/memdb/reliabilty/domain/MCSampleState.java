package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*蒙特卡罗抽样状态	*
***********************/
@Entity
public class MCSampleState
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //状态索引
  private Integer fState;
  
  //损失负荷状态
  private Integer outLoad;
  
  //多状态场景
  private Integer mState;
  
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
    
  public Integer getFState() 
  {
    return fState;
  }
    
  public void setFState(Integer fState)
  {
    this.fState = fState;
  }
    
  public Integer getOutLoad() 
  {
    return outLoad;
  }
    
  public void setOutLoad(Integer outLoad)
  {
    this.outLoad = outLoad;
  }
    
  public Integer getMState() 
  {
    return mState;
  }
    
  public void setMState(Integer mState)
  {
    this.mState = mState;
  }
    
}
    
