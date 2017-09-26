package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*共因故障	*
***********************/
@Entity
public class CommonFault
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //共因故障名称(Id)
  private String name;
  
  //共因故障类型
  private Integer commonFaultType;
  
  //共因设备类型
  private Integer commonDeviceType;
  
  //设备类型
  private Integer devType;
  
  //设备名称
  private String devName;
  
  //设备索引
  private Integer devSerNo;
  
  //标记状态
  private Integer proc;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public String getName() 
  {
    return name;
  }
    
  public void setName(String name)
  {
    this.name = name;
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
    
  public Integer getDevSerNo() 
  {
    return devSerNo;
  }
    
  public void setDevSerNo(Integer devSerNo)
  {
    this.devSerNo = devSerNo;
  }
    
  public Integer getProc() 
  {
    return proc;
  }
    
  public void setProc(Integer proc)
  {
    this.proc = proc;
  }
    
}
    
