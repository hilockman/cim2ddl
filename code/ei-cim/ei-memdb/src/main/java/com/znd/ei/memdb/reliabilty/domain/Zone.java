package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*分区	*
***********************/
@Entity
public class Zone
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //分区名称
  private String name;
  
  //区域名称
  private String area;
  
  //分区发电(MW)
  private Double totalGenP;
  
  //分区负荷(MW)
  private Double totalLoadP;
  
  //分区事故切负荷(MW)
  private Double fCutLoadP;
  
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
    
  public String getArea() 
  {
    return area;
  }
    
  public void setArea(String area)
  {
    this.area = area;
  }
    
  public Double getTotalGenP() 
  {
    return totalGenP;
  }
    
  public void setTotalGenP(Double totalGenP)
  {
    this.totalGenP = totalGenP;
  }
    
  public Double getTotalLoadP() 
  {
    return totalLoadP;
  }
    
  public void setTotalLoadP(Double totalLoadP)
  {
    this.totalLoadP = totalLoadP;
  }
    
  public Double getFCutLoadP() 
  {
    return fCutLoadP;
  }
    
  public void setFCutLoadP(Double fCutLoadP)
  {
    this.fCutLoadP = fCutLoadP;
  }
    
}
    
