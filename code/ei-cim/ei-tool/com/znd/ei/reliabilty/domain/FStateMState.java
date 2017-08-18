package com.znd.ei.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*抽样状态下多状态	*
***********************/
@Entity
class FStateMState
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //多状态设备类型
  private Integer mSDevType;
  
  //多状态设备索引
  private Integer mSDevIndex;
  
  //多状态出力状态
  private Double mStatePout;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public Integer getMSDevType() 
  {
    return mSDevType;
  }
    
  public void setMSDevType(Integer mSDevType)
  {
    this.mSDevType = mSDevType;
  }
    
  public Integer getMSDevIndex() 
  {
    return mSDevIndex;
  }
    
  public void setMSDevIndex(Integer mSDevIndex)
  {
    this.mSDevIndex = mSDevIndex;
  }
    
  public Double getMStatePout() 
  {
    return mStatePout;
  }
    
  public void setMStatePout(Double mStatePout)
  {
    this.mStatePout = mStatePout;
  }
    
}
    
