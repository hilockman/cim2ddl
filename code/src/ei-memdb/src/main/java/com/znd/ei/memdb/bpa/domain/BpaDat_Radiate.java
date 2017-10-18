package com.znd.ei.memdb.bpa.domain;


/**********************
*辐射网络	*
***********************/
public class BpaDat_Radiate
{
  private Integer id;
  
  private Integer memIndex;
  
  //电源母线名称
  private String boundBusName;
  
  //电源母线电压(kV)
  private Double boundBuskV;
  
  //网内发电有功(MW)
  private Double genP;
  
  //网内负荷有功(MW)
  private Double loadP;
  
  //网内负荷无功(MVar)
  private Double loadQ;
  
  //电源母线索引
  private Integer iRBoundBus;
  
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
    
  public String getBoundBusName()
  {
    return boundBusName;
  }
    
  public void setBoundBusName(String boundBusName)
  {
    this.boundBusName = boundBusName;
  }
    
  public Double getBoundBuskV()
  {
    return boundBuskV;
  }
    
  public void setBoundBuskV(Double boundBuskV)
  {
    this.boundBuskV = boundBuskV;
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
    
  public Double getLoadQ()
  {
    return loadQ;
  }
    
  public void setLoadQ(Double loadQ)
  {
    this.loadQ = loadQ;
  }
    
  public Integer getiRBoundBus()
  {
    return iRBoundBus;
  }
    
  public void setiRBoundBus(Integer iRBoundBus)
  {
    this.iRBoundBus = iRBoundBus;
  }
    
  public String toString()
  {
    return "BpaDat_Radiate ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", boundBusName = " + boundBusName
	 + ", boundBuskV = " + boundBuskV
	 + ", genP = " + genP
	 + ", loadP = " + loadP
	 + ", loadQ = " + loadQ
	 + ", iRBoundBus = " + iRBoundBus+"]";
  }
    
}
    
