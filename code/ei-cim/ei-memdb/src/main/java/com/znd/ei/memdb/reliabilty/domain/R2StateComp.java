package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*两状态可靠性设备	*
***********************/
@Entity
public class R2StateComp
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
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
    
}
    
