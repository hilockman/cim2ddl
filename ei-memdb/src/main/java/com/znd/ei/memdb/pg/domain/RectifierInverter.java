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
  
  //交流电压等级
  private String VoltagelevelAC;
  
  //直流电压等级
  private String VoltagelevelDC;
  
  //节点1
  private String ConnectivityNodeAC;
  
  //节点2
  private String ConnectivityNodeDCP;
  
  //节点3
  private String ConnectivityNodeDCN;
  
  //桥数
  private Integer Bridges;
  
  //交流有功(兆瓦)
  private Double P;
  
  //交流无功(兆乏)
  private Double Q;
  
  //交流电压等级索引
  private Integer VoltACPTR;
  
  //直流电压等级索引
  private Integer VoltDCPTR;
  
  //交流节点索引
  private Integer NodeACPTR;
  
  //直流正极节点索引
  private Integer NodeDCPPTR;
  
  //直流负极节点索引
  private Integer NodeDCNPTR;
  
  //交流拓扑节点
  private Integer TopoBusAC;
  
  //直流正极拓扑节点
  private Integer TopoBusDCP;
  
  //直流负极拓扑节点
  private Integer TopoBusDCN;
  
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
    
  public String getVoltagelevelAC()
  {
    return VoltagelevelAC;
  }
    
  public void setVoltagelevelAC(String VoltagelevelAC)
  {
    this.VoltagelevelAC = VoltagelevelAC;
  }
    
  public String getVoltagelevelDC()
  {
    return VoltagelevelDC;
  }
    
  public void setVoltagelevelDC(String VoltagelevelDC)
  {
    this.VoltagelevelDC = VoltagelevelDC;
  }
    
  public String getConnectivityNodeAC()
  {
    return ConnectivityNodeAC;
  }
    
  public void setConnectivityNodeAC(String ConnectivityNodeAC)
  {
    this.ConnectivityNodeAC = ConnectivityNodeAC;
  }
    
  public String getConnectivityNodeDCP()
  {
    return ConnectivityNodeDCP;
  }
    
  public void setConnectivityNodeDCP(String ConnectivityNodeDCP)
  {
    this.ConnectivityNodeDCP = ConnectivityNodeDCP;
  }
    
  public String getConnectivityNodeDCN()
  {
    return ConnectivityNodeDCN;
  }
    
  public void setConnectivityNodeDCN(String ConnectivityNodeDCN)
  {
    this.ConnectivityNodeDCN = ConnectivityNodeDCN;
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
    
  public Integer getVoltACPTR()
  {
    return VoltACPTR;
  }
    
  public void setVoltACPTR(Integer VoltACPTR)
  {
    this.VoltACPTR = VoltACPTR;
  }
    
  public Integer getVoltDCPTR()
  {
    return VoltDCPTR;
  }
    
  public void setVoltDCPTR(Integer VoltDCPTR)
  {
    this.VoltDCPTR = VoltDCPTR;
  }
    
  public Integer getNodeACPTR()
  {
    return NodeACPTR;
  }
    
  public void setNodeACPTR(Integer NodeACPTR)
  {
    this.NodeACPTR = NodeACPTR;
  }
    
  public Integer getNodeDCPPTR()
  {
    return NodeDCPPTR;
  }
    
  public void setNodeDCPPTR(Integer NodeDCPPTR)
  {
    this.NodeDCPPTR = NodeDCPPTR;
  }
    
  public Integer getNodeDCNPTR()
  {
    return NodeDCNPTR;
  }
    
  public void setNodeDCNPTR(Integer NodeDCNPTR)
  {
    this.NodeDCNPTR = NodeDCNPTR;
  }
    
  public Integer getTopoBusAC()
  {
    return TopoBusAC;
  }
    
  public void setTopoBusAC(Integer TopoBusAC)
  {
    this.TopoBusAC = TopoBusAC;
  }
    
  public Integer getTopoBusDCP()
  {
    return TopoBusDCP;
  }
    
  public void setTopoBusDCP(Integer TopoBusDCP)
  {
    this.TopoBusDCP = TopoBusDCP;
  }
    
  public Integer getTopoBusDCN()
  {
    return TopoBusDCN;
  }
    
  public void setTopoBusDCN(Integer TopoBusDCN)
  {
    this.TopoBusDCN = TopoBusDCN;
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
	 + ", VoltagelevelAC = " + VoltagelevelAC
	 + ", VoltagelevelDC = " + VoltagelevelDC
	 + ", ConnectivityNodeAC = " + ConnectivityNodeAC
	 + ", ConnectivityNodeDCP = " + ConnectivityNodeDCP
	 + ", ConnectivityNodeDCN = " + ConnectivityNodeDCN
	 + ", Bridges = " + Bridges
	 + ", P = " + P
	 + ", Q = " + Q
	 + ", VoltACPTR = " + VoltACPTR
	 + ", VoltDCPTR = " + VoltDCPTR
	 + ", NodeACPTR = " + NodeACPTR
	 + ", NodeDCPPTR = " + NodeDCPPTR
	 + ", NodeDCNPTR = " + NodeDCNPTR
	 + ", TopoBusAC = " + TopoBusAC
	 + ", TopoBusDCP = " + TopoBusDCP
	 + ", TopoBusDCN = " + TopoBusDCN
	 + ", Island = " + Island
	 + ", Open = " + Open
	 + ", Outage = " + Outage+"]";
  }
    
}
    
