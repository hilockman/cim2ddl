package com.znd.ei.memdb.reliabilty.domain;


/**********************
*蒙特卡罗抽样状态	*
***********************/
public class MCSampleState
{
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
    
  public String toString()
  {
    return "MCSampleState ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", fState = " + fState
	 + ", outLoad = " + outLoad
	 + ", mState = " + mState+"]";
  }
    
}
    
