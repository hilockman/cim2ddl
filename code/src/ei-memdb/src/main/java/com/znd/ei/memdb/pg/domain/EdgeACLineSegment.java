package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*交流线路边	*
***********************/
public class EdgeACLineSegment  implements MemIndexable 
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
  
  //交流线路段索引
  private Integer ACLineSegmentPtr;
  
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
    
  public Integer getACLineSegmentPtr()
  {
    return ACLineSegmentPtr;
  }
    
  public void setACLineSegmentPtr(Integer ACLineSegmentPtr)
  {
    this.ACLineSegmentPtr = ACLineSegmentPtr;
  }
    
  public String toString()
  {
    return "EdgeACLineSegment ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", ConnectivityNode = " + ConnectivityNode
	 + ", Name = " + Name
	 + ", ACLineSegmentPtr = " + ACLineSegmentPtr+"]";
  }
    
}
    
