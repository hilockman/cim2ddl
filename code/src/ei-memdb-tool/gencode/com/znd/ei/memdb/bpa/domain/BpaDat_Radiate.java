package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*辐射网络	*
***********************/
public class BpaDat_Radiate  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //电源母线名称
  private String BoundBusName;
  
  //电源母线电压(kV)
  private Double BoundBuskV;
  
  //网内发电有功(MW)
  private Double GenP;
  
  //网内负荷有功(MW)
  private Double LoadP;
  
  //网内负荷无功(MVar)
  private Double LoadQ;
  
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
    return BoundBusName;
  }
    
  public void setBoundBusName(String BoundBusName)
  {
    this.BoundBusName = BoundBusName;
  }
    
  public Double getBoundBuskV()
  {
    return BoundBuskV;
  }
    
  public void setBoundBuskV(Double BoundBuskV)
  {
    this.BoundBuskV = BoundBuskV;
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
    
  public Double getLoadQ()
  {
    return LoadQ;
  }
    
  public void setLoadQ(Double LoadQ)
  {
    this.LoadQ = LoadQ;
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
	 + ", BoundBusName = " + BoundBusName
	 + ", BoundBuskV = " + BoundBuskV
	 + ", GenP = " + GenP
	 + ", LoadP = " + LoadP
	 + ", LoadQ = " + LoadQ
	 + ", iRBoundBus = " + iRBoundBus+"]";
  }
    
}
    
