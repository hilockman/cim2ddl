package com.znd.ei.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*交流电岛	*
***********************/
@Entity
public class ACIsland
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //岛发电(MW)
  private Double genP;
  
  //岛负荷(MW)
  private Double loadP;
  
  //岛内母线数
  private Integer busNum;
  
  //平衡节点
  private Integer swingBus;
  
  //死岛
  private Integer dead;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public Double getGenP() 
  {
    return genP;
  }
    
  public void setGenP(Double genP)
  {
    this.genP = genP;
  }
    
  public Double getLoadP() 
  {
    return loadP;
  }
    
  public void setLoadP(Double loadP)
  {
    this.loadP = loadP;
  }
    
  public Integer getBusNum() 
  {
    return busNum;
  }
    
  public void setBusNum(Integer busNum)
  {
    this.busNum = busNum;
  }
    
  public Integer getSwingBus() 
  {
    return swingBus;
  }
    
  public void setSwingBus(Integer swingBus)
  {
    this.swingBus = swingBus;
  }
    
  public Integer getDead() 
  {
    return dead;
  }
    
  public void setDead(Integer dead)
  {
    this.dead = dead;
  }
    
}
    
