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
  private Integer type;
  
  //设备索引
  private Integer serialNo;
  
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
    return type;
  }
    
  public void setType(Integer type)
  {
    this.type = type;
  }
    
  public Integer getSerialNo()
  {
    return serialNo;
  }
    
  public void setSerialNo(Integer serialNo)
  {
    this.serialNo = serialNo;
  }
    
  public String toString()
  {
    return "RMStateComp ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", type = " + type
	 + ", serialNo = " + serialNo+"]";
  }
    
}
    
