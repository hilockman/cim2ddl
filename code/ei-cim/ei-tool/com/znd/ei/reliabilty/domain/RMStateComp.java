package com.znd.ei.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*多状态可靠性设备	*
***********************/
@Entity
class RMStateComp
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //类型
  private Integer type;
  
  //设备索引
  private Integer index;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public Integer getType() 
  {
    return type;
  }
    
  public void setType(Integer type)
  {
    this.type = type;
  }
    
  public Integer getIndex() 
  {
    return index;
  }
    
  public void setIndex(Integer index)
  {
    this.index = index;
  }
    
}
    
