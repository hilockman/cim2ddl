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
  private String Name;
  
  //区域名称
  private String Area;
  
  //分区发电(兆瓦)
  private Double TotalGenP;
  
  //分区负荷(兆瓦)
  private Double TotalLoadP;
  
  //分区事故切负荷(兆瓦)
  private Double FCutLoadP;
  
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
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public String getArea()
  {
    return Area;
  }
    
  public void setArea(String Area)
  {
    this.Area = Area;
  }
    
  public Double getTotalGenP()
  {
    return TotalGenP;
  }
    
  public void setTotalGenP(Double TotalGenP)
  {
    this.TotalGenP = TotalGenP;
  }
    
  public Double getTotalLoadP()
  {
    return TotalLoadP;
  }
    
  public void setTotalLoadP(Double TotalLoadP)
  {
    this.TotalLoadP = TotalLoadP;
  }
    
  public Double getFCutLoadP()
  {
    return FCutLoadP;
  }
    
  public void setFCutLoadP(Double FCutLoadP)
  {
    this.FCutLoadP = FCutLoadP;
  }
    
  public String toString()
  {
    return "Zone ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", Area = " + Area
	 + ", TotalGenP = " + TotalGenP
	 + ", TotalLoadP = " + TotalLoadP
	 + ", FCutLoadP = " + FCutLoadP+"]";
  }
    
}
    
