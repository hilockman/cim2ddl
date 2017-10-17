package com.znd.ei.memdb.bpa.domain;


/**********************
*电网边-高抗	*
***********************/
public class BpaDat_EdgeLineHG
{
  private Integer id;
  
  private Integer memIndex;
  
  //母线名称
  private String busName;
  
  //母线电压(kV)
  private Double buskV;
  
  //高抗名称
  private String lineHGName;
  
  //高抗索引
  private Integer lineHGPtr;
  
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
    
  public String getLineHGName()
  {
    return lineHGName;
  }
    
  public void setLineHGName(String lineHGName)
  {
    this.lineHGName = lineHGName;
  }
    
  public Integer getLineHGPtr()
  {
    return lineHGPtr;
  }
    
  public void setLineHGPtr(Integer lineHGPtr)
  {
    this.lineHGPtr = lineHGPtr;
  }
    
  public String toString()
  {
    return "BpaDat_EdgeLineHG ["+	"id"=id,
	"memIndex"=memIndex,
	"busName"=busName,
	"buskV"=buskV,
	"lineHGName"=lineHGName,
	"lineHGPtr"=lineHGPtr+"]"
  }
    
}
    
