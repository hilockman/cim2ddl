package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*分区	*
***********************/
public class Zone  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
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
    
  public Integer getMemIndex()
  {
    return memIndex;
  }
    
  public void setMemIndex(Integer memIndex)
  {
    this.memIndex = memIndex;
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
    
  public String toString()
  {
    return "Zone ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", name = " + name
	 + ", area = " + area
	 + ", totalGenP = " + totalGenP
	 + ", totalLoadP = " + totalLoadP
	 + ", fCutLoadP = " + fCutLoadP+"]";
  }
    
}
    
