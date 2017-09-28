package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*电网边-线路	*
***********************/
@Entity
public class BpaDat_EdgeLine
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //母线名称
  private String busName;
  
  //母线电压(kV)
  private Double buskV;
  
  //线路名称
  private String lineName;
  
  //线路索引
  private Integer linePtr;
  
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
    
  public String getLineName() 
  {
    return lineName;
  }
    
  public void setLineName(String lineName)
  {
    this.lineName = lineName;
  }
    
  public Integer getLinePtr() 
  {
    return linePtr;
  }
    
  public void setLinePtr(Integer linePtr)
  {
    this.linePtr = linePtr;
  }
    
}
    
