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
  
  //高电压等级
  private String VoltagelevelH;
  
  //中电压等级
  private String VoltagelevelM;
  
  //低电压等级
  private String VoltagelevelL;
  
  //中性点电压等级
  private String VoltagelevelT;
  
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
  
  //中性点
  private String ConnectivityNodeT;
  
  //故障率(次/年)
  private Double ri_Rerr;
  
  //修复时间(小时/次)
  private Double ri_Trep;
  
  //计划检修率(次/年)
  private Double ri_Rchk;
  
  //检修时间(小时/次)
  private Double ri_Tchk;
  
  //故障定位隔离时间(小时)
  private Double ri_Tfloc;
  
  //投资费用(万元)
  private Double ei_Invest;
  
  //停运率贡献(%)
  private Double ro_RContribution;
  
  //停运时间贡献(%)
  private Double ro_UContribution;
  
  //停电电量贡献(%)
  private Double ro_EnsContribution;
  
  //高压拓扑母线
  private Integer TopoBusH;
  
  //中压拓扑母线
  private Integer TopoBusM;
  
  //低压拓扑母线
  private Integer TopoBusL;
  
  //中性点母线
  private Integer TopoBusT;
  
  //高电压等级索引
  private Integer VoltHPtr;
  
  //中电压等级索引
  private Integer VoltMPtr;
  
  //低电压等级索引
  private Integer VoltLPtr;
  
  //中性点电压等级索引
  private Integer VoltTPtr;
  
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
  
  //中性点索引
  private Integer NodeTPtr;
  
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
    
  public String getVoltagelevelT()
  {
    return VoltagelevelT;
  }
    
  public void setVoltagelevelT(String VoltagelevelT)
  {
    this.VoltagelevelT = VoltagelevelT;
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
    
  public String getConnectivityNodeT()
  {
    return ConnectivityNodeT;
  }
    
  public void setConnectivityNodeT(String ConnectivityNodeT)
  {
    this.ConnectivityNodeT = ConnectivityNodeT;
  }
    
  public Double getri_Rerr()
  {
    return ri_Rerr;
  }
    
  public void setri_Rerr(Double ri_Rerr)
  {
    this.ri_Rerr = ri_Rerr;
  }
    
  public Double getri_Trep()
  {
    return ri_Trep;
  }
    
  public void setri_Trep(Double ri_Trep)
  {
    this.ri_Trep = ri_Trep;
  }
    
  public Double getri_Rchk()
  {
    return ri_Rchk;
  }
    
  public void setri_Rchk(Double ri_Rchk)
  {
    this.ri_Rchk = ri_Rchk;
  }
    
  public Double getri_Tchk()
  {
    return ri_Tchk;
  }
    
  public void setri_Tchk(Double ri_Tchk)
  {
    this.ri_Tchk = ri_Tchk;
  }
    
  public Double getri_Tfloc()
  {
    return ri_Tfloc;
  }
    
  public void setri_Tfloc(Double ri_Tfloc)
  {
    this.ri_Tfloc = ri_Tfloc;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Double getro_RContribution()
  {
    return ro_RContribution;
  }
    
  public void setro_RContribution(Double ro_RContribution)
  {
    this.ro_RContribution = ro_RContribution;
  }
    
  public Double getro_UContribution()
  {
    return ro_UContribution;
  }
    
  public void setro_UContribution(Double ro_UContribution)
  {
    this.ro_UContribution = ro_UContribution;
  }
    
  public Double getro_EnsContribution()
  {
    return ro_EnsContribution;
  }
    
  public void setro_EnsContribution(Double ro_EnsContribution)
  {
    this.ro_EnsContribution = ro_EnsContribution;
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
    
  public Integer getTopoBusT()
  {
    return TopoBusT;
  }
    
  public void setTopoBusT(Integer TopoBusT)
  {
    this.TopoBusT = TopoBusT;
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
    
  public Integer getVoltTPtr()
  {
    return VoltTPtr;
  }
    
  public void setVoltTPtr(Integer VoltTPtr)
  {
    this.VoltTPtr = VoltTPtr;
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
    
  public Integer getNodeTPtr()
  {
    return NodeTPtr;
  }
    
  public void setNodeTPtr(Integer NodeTPtr)
  {
    this.NodeTPtr = NodeTPtr;
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
	 + ", VoltagelevelT = " + VoltagelevelT
	 + ", TransformerWindingH = " + TransformerWindingH
	 + ", TransformerWindingM = " + TransformerWindingM
	 + ", TransformerWindingL = " + TransformerWindingL
	 + ", ConnectivityNodeH = " + ConnectivityNodeH
	 + ", ConnectivityNodeM = " + ConnectivityNodeM
	 + ", ConnectivityNodeL = " + ConnectivityNodeL
	 + ", ConnectivityNodeT = " + ConnectivityNodeT
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ei_Invest = " + ei_Invest
	 + ", ro_RContribution = " + ro_RContribution
	 + ", ro_UContribution = " + ro_UContribution
	 + ", ro_EnsContribution = " + ro_EnsContribution
	 + ", TopoBusH = " + TopoBusH
	 + ", TopoBusM = " + TopoBusM
	 + ", TopoBusL = " + TopoBusL
	 + ", TopoBusT = " + TopoBusT
	 + ", VoltHPtr = " + VoltHPtr
	 + ", VoltMPtr = " + VoltMPtr
	 + ", VoltLPtr = " + VoltLPtr
	 + ", VoltTPtr = " + VoltTPtr
	 + ", WindHPtr = " + WindHPtr
	 + ", WindMPtr = " + WindMPtr
	 + ", WindLPtr = " + WindLPtr
	 + ", NodeHPtr = " + NodeHPtr
	 + ", NodeMPtr = " + NodeMPtr
	 + ", NodeLPtr = " + NodeLPtr
	 + ", NodeTPtr = " + NodeTPtr
	 + ", State = " + State
	 + ", Open = " + Open+"]";
  }
    
}
    
