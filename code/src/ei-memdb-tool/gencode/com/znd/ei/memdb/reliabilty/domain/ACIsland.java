package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*交流电岛	*
***********************/
public class ACIsland  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //岛发电(MW)
  private Double GenP;
  
  //岛负荷(MW)
  private Double LoadP;
  
  //岛内母线数
  private Integer BusNum;
  
  //平衡节点
  private Integer SwingBus;
  
  //死岛
  private Integer Dead;
  
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
    return GenP;
  }
    
  public void setGenP(Double GenP)
  {
    this.GenP = GenP;
  }
    
  public Double getLoadP()
  {
    return LoadP;
  }
    
  public void setLoadP(Double LoadP)
  {
    this.LoadP = LoadP;
  }
    
  public Integer getBusNum()
  {
    return BusNum;
  }
    
  public void setBusNum(Integer BusNum)
  {
    this.BusNum = BusNum;
  }
    
  public Integer getSwingBus()
  {
    return SwingBus;
  }
    
  public void setSwingBus(Integer SwingBus)
  {
    this.SwingBus = SwingBus;
  }
    
  public Integer getDead()
  {
    return Dead;
  }
    
  public void setDead(Integer Dead)
  {
    this.Dead = Dead;
  }
    
  public String toString()
  {
    return "ACIsland ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", GenP = " + GenP
	 + ", LoadP = " + LoadP
	 + ", BusNum = " + BusNum
	 + ", SwingBus = " + SwingBus
	 + ", Dead = " + Dead+"]";
  }
    
}
    
