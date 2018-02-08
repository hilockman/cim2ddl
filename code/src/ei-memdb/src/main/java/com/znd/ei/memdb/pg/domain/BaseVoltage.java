package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*基准电压	*
***********************/
public class BaseVoltage  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //名称
  private String Name;
  
  //计算基准值(kV)
  private Double nominalVoltage;
  
  //电压最小值(kV)
  private Double lowVLimit;
  
  //电压最大值(kV)
  private Double higVhLimit;
  
  //短路电流限值(kA)
  private Double scALimit;
  
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
    
  public String getResourceID()
  {
    return ResourceID;
  }
    
  public void setResourceID(String ResourceID)
  {
    this.ResourceID = ResourceID;
  }
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public Double getnominalVoltage()
  {
    return nominalVoltage;
  }
    
  public void setnominalVoltage(Double nominalVoltage)
  {
    this.nominalVoltage = nominalVoltage;
  }
    
  public Double getlowVLimit()
  {
    return lowVLimit;
  }
    
  public void setlowVLimit(Double lowVLimit)
  {
    this.lowVLimit = lowVLimit;
  }
    
  public Double gethigVhLimit()
  {
    return higVhLimit;
  }
    
  public void sethigVhLimit(Double higVhLimit)
  {
    this.higVhLimit = higVhLimit;
  }
    
  public Double getscALimit()
  {
    return scALimit;
  }
    
  public void setscALimit(Double scALimit)
  {
    this.scALimit = scALimit;
  }
    
  public String toString()
  {
    return "BaseVoltage ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Name = " + Name
	 + ", nominalVoltage = " + nominalVoltage
	 + ", lowVLimit = " + lowVLimit
	 + ", higVhLimit = " + higVhLimit
	 + ", scALimit = " + scALimit+"]";
  }
    
}
    
