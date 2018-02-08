package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*整流逆变器	*
***********************/
public class RectifierInverter  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //厂站
  private String Substation;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //电压等级1
  private String Voltagelevel1;
  
  //电压等级2
  private String Voltagelevel2;
  
  //电压等级3
  private String Voltagelevel3;
  
  //节点1
  private String ConnectivityNode1;
  
  //节点2
  private String ConnectivityNode2;
  
  //节点3
  private String ConnectivityNode3;
  
  //桥数
  private Integer Bridges;
  
  //交流有功(MW)
  private Double P;
  
  //交流无功(MVar)
  private Double Q;
  
  //电压等级索引1
  private Integer Volt1PTR;
  
  //电压等级索引2
  private Integer Volt2PTR;
  
  //电压等级索引3
  private Integer Volt3PTR;
  
  //节点索引1
  private Integer Node1PTR;
  
  //节点索引2
  private Integer Node2PTR;
  
  //节点索引3
  private Integer Node3PTR;
  
  //拓扑节点1
  private Integer TopoBus1;
  
  //拓扑节点2
  private Integer TopoBus2;
  
  //拓扑节点3
  private Integer TopoBus3;
  
  //岛
  private Integer Island;
  
  //拓扑状态
  private Integer Open;
  
  //设备状态
  private Integer Outage;
  
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
    
  public String getSubstation()
  {
    return Substation;
  }
    
  public void setSubstation(String Substation)
  {
    this.Substation = Substation;
  }
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public String getDescription()
  {
    return Description;
  }
    
  public void setDescription(String Description)
  {
    this.Description = Description;
  }
    
  public String getVoltagelevel1()
  {
    return Voltagelevel1;
  }
    
  public void setVoltagelevel1(String Voltagelevel1)
  {
    this.Voltagelevel1 = Voltagelevel1;
  }
    
  public String getVoltagelevel2()
  {
    return Voltagelevel2;
  }
    
  public void setVoltagelevel2(String Voltagelevel2)
  {
    this.Voltagelevel2 = Voltagelevel2;
  }
    
  public String getVoltagelevel3()
  {
    return Voltagelevel3;
  }
    
  public void setVoltagelevel3(String Voltagelevel3)
  {
    this.Voltagelevel3 = Voltagelevel3;
  }
    
  public String getConnectivityNode1()
  {
    return ConnectivityNode1;
  }
    
  public void setConnectivityNode1(String ConnectivityNode1)
  {
    this.ConnectivityNode1 = ConnectivityNode1;
  }
    
  public String getConnectivityNode2()
  {
    return ConnectivityNode2;
  }
    
  public void setConnectivityNode2(String ConnectivityNode2)
  {
    this.ConnectivityNode2 = ConnectivityNode2;
  }
    
  public String getConnectivityNode3()
  {
    return ConnectivityNode3;
  }
    
  public void setConnectivityNode3(String ConnectivityNode3)
  {
    this.ConnectivityNode3 = ConnectivityNode3;
  }
    
  public Integer getBridges()
  {
    return Bridges;
  }
    
  public void setBridges(Integer Bridges)
  {
    this.Bridges = Bridges;
  }
    
  public Double getP()
  {
    return P;
  }
    
  public void setP(Double P)
  {
    this.P = P;
  }
    
  public Double getQ()
  {
    return Q;
  }
    
  public void setQ(Double Q)
  {
    this.Q = Q;
  }
    
  public Integer getVolt1PTR()
  {
    return Volt1PTR;
  }
    
  public void setVolt1PTR(Integer Volt1PTR)
  {
    this.Volt1PTR = Volt1PTR;
  }
    
  public Integer getVolt2PTR()
  {
    return Volt2PTR;
  }
    
  public void setVolt2PTR(Integer Volt2PTR)
  {
    this.Volt2PTR = Volt2PTR;
  }
    
  public Integer getVolt3PTR()
  {
    return Volt3PTR;
  }
    
  public void setVolt3PTR(Integer Volt3PTR)
  {
    this.Volt3PTR = Volt3PTR;
  }
    
  public Integer getNode1PTR()
  {
    return Node1PTR;
  }
    
  public void setNode1PTR(Integer Node1PTR)
  {
    this.Node1PTR = Node1PTR;
  }
    
  public Integer getNode2PTR()
  {
    return Node2PTR;
  }
    
  public void setNode2PTR(Integer Node2PTR)
  {
    this.Node2PTR = Node2PTR;
  }
    
  public Integer getNode3PTR()
  {
    return Node3PTR;
  }
    
  public void setNode3PTR(Integer Node3PTR)
  {
    this.Node3PTR = Node3PTR;
  }
    
  public Integer getTopoBus1()
  {
    return TopoBus1;
  }
    
  public void setTopoBus1(Integer TopoBus1)
  {
    this.TopoBus1 = TopoBus1;
  }
    
  public Integer getTopoBus2()
  {
    return TopoBus2;
  }
    
  public void setTopoBus2(Integer TopoBus2)
  {
    this.TopoBus2 = TopoBus2;
  }
    
  public Integer getTopoBus3()
  {
    return TopoBus3;
  }
    
  public void setTopoBus3(Integer TopoBus3)
  {
    this.TopoBus3 = TopoBus3;
  }
    
  public Integer getIsland()
  {
    return Island;
  }
    
  public void setIsland(Integer Island)
  {
    this.Island = Island;
  }
    
  public Integer getOpen()
  {
    return Open;
  }
    
  public void setOpen(Integer Open)
  {
    this.Open = Open;
  }
    
  public Integer getOutage()
  {
    return Outage;
  }
    
  public void setOutage(Integer Outage)
  {
    this.Outage = Outage;
  }
    
  public String toString()
  {
    return "RectifierInverter ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Substation = " + Substation
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", Voltagelevel1 = " + Voltagelevel1
	 + ", Voltagelevel2 = " + Voltagelevel2
	 + ", Voltagelevel3 = " + Voltagelevel3
	 + ", ConnectivityNode1 = " + ConnectivityNode1
	 + ", ConnectivityNode2 = " + ConnectivityNode2
	 + ", ConnectivityNode3 = " + ConnectivityNode3
	 + ", Bridges = " + Bridges
	 + ", P = " + P
	 + ", Q = " + Q
	 + ", Volt1PTR = " + Volt1PTR
	 + ", Volt2PTR = " + Volt2PTR
	 + ", Volt3PTR = " + Volt3PTR
	 + ", Node1PTR = " + Node1PTR
	 + ", Node2PTR = " + Node2PTR
	 + ", Node3PTR = " + Node3PTR
	 + ", TopoBus1 = " + TopoBus1
	 + ", TopoBus2 = " + TopoBus2
	 + ", TopoBus3 = " + TopoBus3
	 + ", Island = " + Island
	 + ", Open = " + Open
	 + ", Outage = " + Outage+"]";
  }
    
}
    
