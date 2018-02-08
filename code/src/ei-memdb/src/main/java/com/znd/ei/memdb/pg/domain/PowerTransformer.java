package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*变压器	*
***********************/
public class PowerTransformer  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //ObjectId
  private String ObjectID;
  
  //厂站
  private String Substation;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //绕组数
  private Integer WindNum;
  
  //高压电压等级
  private String VoltagelevelH;
  
  //中压电压等级
  private String VoltagelevelM;
  
  //低压电压等级
  private String VoltagelevelL;
  
  //高压绕组
  private String TransformerWindingH;
  
  //中压绕组
  private String TransformerWindingM;
  
  //低压绕组
  private String TransformerWindingL;
  
  //高压节点
  private String ConnectivityNodeH;
  
  //中压节点
  private String ConnectivityNodeM;
  
  //低压节点
  private String ConnectivityNodeL;
  
  //高压拓扑母线
  private Integer TopoBusH;
  
  //中压拓扑母线
  private Integer TopoBusM;
  
  //低压拓扑母线
  private Integer TopoBusL;
  
  //高电压等级索引
  private Integer VoltHPtr;
  
  //中电压等级索引
  private Integer VoltMPtr;
  
  //低电压等级索引
  private Integer VoltLPtr;
  
  //高压绕组索引
  private Integer WindHPtr;
  
  //中压绕组索引
  private Integer WindMPtr;
  
  //低压绕组索引
  private Integer WindLPtr;
  
  //高压节点索引
  private Integer NodeHPtr;
  
  //中压节点索引
  private Integer NodeMPtr;
  
  //低压节点索引
  private Integer NodeLPtr;
  
  //综合状态(着色)
  private Integer State;
  
  //拓扑状态
  private Integer Open;
  
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
    
  public String getObjectID()
  {
    return ObjectID;
  }
    
  public void setObjectID(String ObjectID)
  {
    this.ObjectID = ObjectID;
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
    
  public Integer getWindNum()
  {
    return WindNum;
  }
    
  public void setWindNum(Integer WindNum)
  {
    this.WindNum = WindNum;
  }
    
  public String getVoltagelevelH()
  {
    return VoltagelevelH;
  }
    
  public void setVoltagelevelH(String VoltagelevelH)
  {
    this.VoltagelevelH = VoltagelevelH;
  }
    
  public String getVoltagelevelM()
  {
    return VoltagelevelM;
  }
    
  public void setVoltagelevelM(String VoltagelevelM)
  {
    this.VoltagelevelM = VoltagelevelM;
  }
    
  public String getVoltagelevelL()
  {
    return VoltagelevelL;
  }
    
  public void setVoltagelevelL(String VoltagelevelL)
  {
    this.VoltagelevelL = VoltagelevelL;
  }
    
  public String getTransformerWindingH()
  {
    return TransformerWindingH;
  }
    
  public void setTransformerWindingH(String TransformerWindingH)
  {
    this.TransformerWindingH = TransformerWindingH;
  }
    
  public String getTransformerWindingM()
  {
    return TransformerWindingM;
  }
    
  public void setTransformerWindingM(String TransformerWindingM)
  {
    this.TransformerWindingM = TransformerWindingM;
  }
    
  public String getTransformerWindingL()
  {
    return TransformerWindingL;
  }
    
  public void setTransformerWindingL(String TransformerWindingL)
  {
    this.TransformerWindingL = TransformerWindingL;
  }
    
  public String getConnectivityNodeH()
  {
    return ConnectivityNodeH;
  }
    
  public void setConnectivityNodeH(String ConnectivityNodeH)
  {
    this.ConnectivityNodeH = ConnectivityNodeH;
  }
    
  public String getConnectivityNodeM()
  {
    return ConnectivityNodeM;
  }
    
  public void setConnectivityNodeM(String ConnectivityNodeM)
  {
    this.ConnectivityNodeM = ConnectivityNodeM;
  }
    
  public String getConnectivityNodeL()
  {
    return ConnectivityNodeL;
  }
    
  public void setConnectivityNodeL(String ConnectivityNodeL)
  {
    this.ConnectivityNodeL = ConnectivityNodeL;
  }
    
  public Integer getTopoBusH()
  {
    return TopoBusH;
  }
    
  public void setTopoBusH(Integer TopoBusH)
  {
    this.TopoBusH = TopoBusH;
  }
    
  public Integer getTopoBusM()
  {
    return TopoBusM;
  }
    
  public void setTopoBusM(Integer TopoBusM)
  {
    this.TopoBusM = TopoBusM;
  }
    
  public Integer getTopoBusL()
  {
    return TopoBusL;
  }
    
  public void setTopoBusL(Integer TopoBusL)
  {
    this.TopoBusL = TopoBusL;
  }
    
  public Integer getVoltHPtr()
  {
    return VoltHPtr;
  }
    
  public void setVoltHPtr(Integer VoltHPtr)
  {
    this.VoltHPtr = VoltHPtr;
  }
    
  public Integer getVoltMPtr()
  {
    return VoltMPtr;
  }
    
  public void setVoltMPtr(Integer VoltMPtr)
  {
    this.VoltMPtr = VoltMPtr;
  }
    
  public Integer getVoltLPtr()
  {
    return VoltLPtr;
  }
    
  public void setVoltLPtr(Integer VoltLPtr)
  {
    this.VoltLPtr = VoltLPtr;
  }
    
  public Integer getWindHPtr()
  {
    return WindHPtr;
  }
    
  public void setWindHPtr(Integer WindHPtr)
  {
    this.WindHPtr = WindHPtr;
  }
    
  public Integer getWindMPtr()
  {
    return WindMPtr;
  }
    
  public void setWindMPtr(Integer WindMPtr)
  {
    this.WindMPtr = WindMPtr;
  }
    
  public Integer getWindLPtr()
  {
    return WindLPtr;
  }
    
  public void setWindLPtr(Integer WindLPtr)
  {
    this.WindLPtr = WindLPtr;
  }
    
  public Integer getNodeHPtr()
  {
    return NodeHPtr;
  }
    
  public void setNodeHPtr(Integer NodeHPtr)
  {
    this.NodeHPtr = NodeHPtr;
  }
    
  public Integer getNodeMPtr()
  {
    return NodeMPtr;
  }
    
  public void setNodeMPtr(Integer NodeMPtr)
  {
    this.NodeMPtr = NodeMPtr;
  }
    
  public Integer getNodeLPtr()
  {
    return NodeLPtr;
  }
    
  public void setNodeLPtr(Integer NodeLPtr)
  {
    this.NodeLPtr = NodeLPtr;
  }
    
  public Integer getState()
  {
    return State;
  }
    
  public void setState(Integer State)
  {
    this.State = State;
  }
    
  public Integer getOpen()
  {
    return Open;
  }
    
  public void setOpen(Integer Open)
  {
    this.Open = Open;
  }
    
  public String toString()
  {
    return "PowerTransformer ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Substation = " + Substation
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", WindNum = " + WindNum
	 + ", VoltagelevelH = " + VoltagelevelH
	 + ", VoltagelevelM = " + VoltagelevelM
	 + ", VoltagelevelL = " + VoltagelevelL
	 + ", TransformerWindingH = " + TransformerWindingH
	 + ", TransformerWindingM = " + TransformerWindingM
	 + ", TransformerWindingL = " + TransformerWindingL
	 + ", ConnectivityNodeH = " + ConnectivityNodeH
	 + ", ConnectivityNodeM = " + ConnectivityNodeM
	 + ", ConnectivityNodeL = " + ConnectivityNodeL
	 + ", TopoBusH = " + TopoBusH
	 + ", TopoBusM = " + TopoBusM
	 + ", TopoBusL = " + TopoBusL
	 + ", VoltHPtr = " + VoltHPtr
	 + ", VoltMPtr = " + VoltMPtr
	 + ", VoltLPtr = " + VoltLPtr
	 + ", WindHPtr = " + WindHPtr
	 + ", WindMPtr = " + WindMPtr
	 + ", WindLPtr = " + WindLPtr
	 + ", NodeHPtr = " + NodeHPtr
	 + ", NodeMPtr = " + NodeMPtr
	 + ", NodeLPtr = " + NodeLPtr
	 + ", State = " + State
	 + ", Open = " + Open+"]";
  }
    
}
    
