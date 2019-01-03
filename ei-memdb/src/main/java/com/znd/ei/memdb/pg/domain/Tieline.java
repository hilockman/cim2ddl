package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*联络线	*
***********************/
public class Tieline  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String Name;
  
  //起公司
  private String iCompany;
  
  //起分区
  private String iSubcontrolArea;
  
  //起厂站
  private String iSubstation;
  
  //起电压等级
  private String iVoltageLevel;
  
  //终公司
  private String zCompany;
  
  //终分区
  private String zSubcontrolArea;
  
  //终厂站
  private String zSubstation;
  
  //终电压等级
  private String zVoltageLevel;
  
  //量测节点
  private String ConnectivityNode;
  
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
    
  public String getiCompany()
  {
    return iCompany;
  }
    
  public void setiCompany(String iCompany)
  {
    this.iCompany = iCompany;
  }
    
  public String getiSubcontrolArea()
  {
    return iSubcontrolArea;
  }
    
  public void setiSubcontrolArea(String iSubcontrolArea)
  {
    this.iSubcontrolArea = iSubcontrolArea;
  }
    
  public String getiSubstation()
  {
    return iSubstation;
  }
    
  public void setiSubstation(String iSubstation)
  {
    this.iSubstation = iSubstation;
  }
    
  public String getiVoltageLevel()
  {
    return iVoltageLevel;
  }
    
  public void setiVoltageLevel(String iVoltageLevel)
  {
    this.iVoltageLevel = iVoltageLevel;
  }
    
  public String getzCompany()
  {
    return zCompany;
  }
    
  public void setzCompany(String zCompany)
  {
    this.zCompany = zCompany;
  }
    
  public String getzSubcontrolArea()
  {
    return zSubcontrolArea;
  }
    
  public void setzSubcontrolArea(String zSubcontrolArea)
  {
    this.zSubcontrolArea = zSubcontrolArea;
  }
    
  public String getzSubstation()
  {
    return zSubstation;
  }
    
  public void setzSubstation(String zSubstation)
  {
    this.zSubstation = zSubstation;
  }
    
  public String getzVoltageLevel()
  {
    return zVoltageLevel;
  }
    
  public void setzVoltageLevel(String zVoltageLevel)
  {
    this.zVoltageLevel = zVoltageLevel;
  }
    
  public String getConnectivityNode()
  {
    return ConnectivityNode;
  }
    
  public void setConnectivityNode(String ConnectivityNode)
  {
    this.ConnectivityNode = ConnectivityNode;
  }
    
  public String toString()
  {
    return "Tieline ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", iCompany = " + iCompany
	 + ", iSubcontrolArea = " + iSubcontrolArea
	 + ", iSubstation = " + iSubstation
	 + ", iVoltageLevel = " + iVoltageLevel
	 + ", zCompany = " + zCompany
	 + ", zSubcontrolArea = " + zSubcontrolArea
	 + ", zSubstation = " + zSubstation
	 + ", zVoltageLevel = " + zVoltageLevel
	 + ", ConnectivityNode = " + ConnectivityNode+"]";
  }
    
}
    
