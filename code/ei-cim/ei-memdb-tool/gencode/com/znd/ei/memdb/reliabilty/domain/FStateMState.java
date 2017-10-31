package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*抽样状态下多状态	*
***********************/
public class FStateMState  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
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
    
  public Integer getMemIndex()
  {
    return memIndex;
  }
    
  public void setMemIndex(Integer memIndex)
  {
    this.memIndex = memIndex;
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
    
  public String toString()
  {
    return "FStateMState ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", mSDevType = " + mSDevType
	 + ", mSDevIndex = " + mSDevIndex
	 + ", mStatePout = " + mStatePout+"]";
  }
    
}
    
