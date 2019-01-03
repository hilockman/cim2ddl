package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*多状态可靠性设备	*
***********************/
public class RMStateComp  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //类型
  private Integer Type;
  
  //设备索引
  private Integer SerialNo;
  
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
    
  public Integer getType()
  {
    return Type;
  }
    
  public void setType(Integer Type)
  {
    this.Type = Type;
  }
    
  public Integer getSerialNo()
  {
    return SerialNo;
  }
    
  public void setSerialNo(Integer SerialNo)
  {
    this.SerialNo = SerialNo;
  }
    
  public String toString()
  {
    return "RMStateComp ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Type = " + Type
	 + ", SerialNo = " + SerialNo+"]";
  }
    
}
    
