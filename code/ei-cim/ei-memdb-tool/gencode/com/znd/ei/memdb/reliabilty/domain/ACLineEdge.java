package com.znd.ei.memdb.reliabilty.domain;


/**********************
*交流线路边	*
***********************/
public class ACLineEdge
{
  private Integer id;
  
  private Integer memIndex;
  
  //母线名称
  private String bus;
  
  //母线电压(kV)
  private Double kV;
  
  //线路名称
  private String name;
  
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
    
  public String getBus()
  {
    return bus;
  }
    
  public void setBus(String bus)
  {
    this.bus = bus;
  }
    
  public Double getkV()
  {
    return kV;
  }
    
  public void setkV(Double kV)
  {
    this.kV = kV;
  }
    
  public String getName()
  {
    return name;
  }
    
  public void setName(String name)
  {
    this.name = name;
  }
    
  public Integer getLinePtr()
  {
    return linePtr;
  }
    
  public void setLinePtr(Integer linePtr)
  {
    this.linePtr = linePtr;
  }
    
  public String toString()
  {
    return "ACLineEdge ["+	"id"=id,
	"memIndex"=memIndex,
	"bus"=bus,
	"kV"=kV,
	"name"=name,
	"linePtr"=linePtr+"]"
  }
    
}
    
