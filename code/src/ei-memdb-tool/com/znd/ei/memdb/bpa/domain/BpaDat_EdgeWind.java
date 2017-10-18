package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*电网边-变压器绕组	*
***********************/
@Entity
public class BpaDat_EdgeWind
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //母线名称
  private String busName;
  
  //母线电压(kV)
  private Double buskV;
  
  //绕组名称
  private String windName;
  
  //绕组索引
  private Integer windPtr;
  
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
    
  public String getBusName() 
  {
    return busName;
  }
    
  public void setBusName(String busName)
  {
    this.busName = busName;
  }
    
  public Double getBuskV() 
  {
    return buskV;
  }
    
  public void setBuskV(Double buskV)
  {
    this.buskV = buskV;
  }
    
  public String getWindName() 
  {
    return windName;
  }
    
  public void setWindName(String windName)
  {
    this.windName = windName;
  }
    
  public Integer getWindPtr() 
  {
    return windPtr;
  }
    
  public void setWindPtr(Integer windPtr)
  {
    this.windPtr = windPtr;
  }
    
}
    