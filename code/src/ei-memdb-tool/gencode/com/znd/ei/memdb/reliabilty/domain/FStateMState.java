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
  private Integer MSDevType;
  
  //多状态设备索引
  private Integer MSDevIndex;
  
  //多状态出力状态
  private Double MStatePout;
  
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
    return MSDevType;
  }
    
  public void setMSDevType(Integer MSDevType)
  {
    this.MSDevType = MSDevType;
  }
    
  public Integer getMSDevIndex()
  {
    return MSDevIndex;
  }
    
  public void setMSDevIndex(Integer MSDevIndex)
  {
    this.MSDevIndex = MSDevIndex;
  }
    
  public Double getMStatePout()
  {
    return MStatePout;
  }
    
  public void setMStatePout(Double MStatePout)
  {
    this.MStatePout = MStatePout;
  }
    
  public String toString()
  {
    return "FStateMState ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", MSDevType = " + MSDevType
	 + ", MSDevIndex = " + MSDevIndex
	 + ", MStatePout = " + MStatePout+"]";
  }
    
}
    
