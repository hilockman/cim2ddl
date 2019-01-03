package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*串联补偿边	*
***********************/
public class EdgeSeriesCompensator  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //厂站
  private String Substation;
  
  //电压等级
  private String VoltageLevel;
  
  //节点
  private String ConnectivityNode;
  
  //名称
  private String Name;
  
  //补偿索引
  private Integer SeriesCompensatorPtr;
  
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
    
  public String getSubstation()
  {
    return Substation;
  }
    
  public void setSubstation(String Substation)
  {
    this.Substation = Substation;
  }
    
  public String getVoltageLevel()
  {
    return VoltageLevel;
  }
    
  public void setVoltageLevel(String VoltageLevel)
  {
    this.VoltageLevel = VoltageLevel;
  }
    
  public String getConnectivityNode()
  {
    return ConnectivityNode;
  }
    
  public void setConnectivityNode(String ConnectivityNode)
  {
    this.ConnectivityNode = ConnectivityNode;
  }
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public Integer getSeriesCompensatorPtr()
  {
    return SeriesCompensatorPtr;
  }
    
  public void setSeriesCompensatorPtr(Integer SeriesCompensatorPtr)
  {
    this.SeriesCompensatorPtr = SeriesCompensatorPtr;
  }
    
  public String toString()
  {
    return "EdgeSeriesCompensator ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", ConnectivityNode = " + ConnectivityNode
	 + ", Name = " + Name
	 + ", SeriesCompensatorPtr = " + SeriesCompensatorPtr+"]";
  }
    
}
    