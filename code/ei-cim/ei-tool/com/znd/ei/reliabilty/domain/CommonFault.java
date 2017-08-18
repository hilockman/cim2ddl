package com.znd.ei.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*共因故障	*
***********************/
@Entity
class CommonFault
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //Id
  private Integer iD;
  
  //共因故障类型
  private Integer commonFaultType;
  
  //共因设备类型
  private Integer commonDeviceType;
  
  //设备类型
  private Integer devType;
  
  //设备名称
  private String devName;
  
  //设备索引
  private Integer devIndex;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public Integer getID() 
  {
    return iD;
  }
    
  public void setID(Integer iD)
  {
    this.iD = iD;
  }
    
  public Integer getCommonFaultType() 
  {
    return commonFaultType;
  }
    
  public void setCommonFaultType(Integer commonFaultType)
  {
    this.commonFaultType = commonFaultType;
  }
    
  public Integer getCommonDeviceType() 
  {
    return commonDeviceType;
  }
    
  public void setCommonDeviceType(Integer commonDeviceType)
  {
    this.commonDeviceType = commonDeviceType;
  }
    
  public Integer getDevType() 
  {
    return devType;
  }
    
  public void setDevType(Integer devType)
  {
    this.devType = devType;
  }
    
  public String getDevName() 
  {
    return devName;
  }
    
  public void setDevName(String devName)
  {
    this.devName = devName;
  }
    
  public Integer getDevIndex() 
  {
    return devIndex;
  }
    
  public void setDevIndex(Integer devIndex)
  {
    this.devIndex = devIndex;
  }
    
}
    
