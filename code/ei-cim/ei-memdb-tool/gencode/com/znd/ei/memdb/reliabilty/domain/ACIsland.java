package com.znd.ei.memdb.reliabilty.domain;


/**********************
*交流电岛	*
***********************/
public class ACIsland
{
  private Integer id;
  
  private Integer memIndex;
  
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
    
  public Integer getMemIndex()
  {
    return memIndex;
  }
    
  public void setMemIndex(Integer memIndex)
  {
    this.memIndex = memIndex;
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
    
  public String toString()
  {
    return "ACIsland ["+	"id"=id,
	"memIndex"=memIndex,
	"genP"=genP,
	"loadP"=loadP,
	"busNum"=busNum,
	"swingBus"=swingBus,
	"dead"=dead+"]"
  }
    
}
    
