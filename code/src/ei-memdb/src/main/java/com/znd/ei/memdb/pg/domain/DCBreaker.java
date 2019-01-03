package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*直流断路器	*
***********************/
public class DCBreaker  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //ObjectId
  private String ObjectID;
  
  //厂站
  private String Substation;
  
  //电压等级
  private String VoltageLevel;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //运行状态
  private Integer Status;
  
  //起节点
  private String ConnectivityNodeI;
  
  //终节点
  private String ConnectivityNodeJ;
  
  //故障率(次/台.年)
  private Double ri_Rerr;
  
  //修复时间(小时/次)
  private Double ri_Trep;
  
  //计划检修率(次/台.年)
  private Double ri_Rchk;
  
  //检修时间(小时/次)
  private Double ri_Tchk;
  
  //故障定位隔离时间(小时)
  private Double ri_Tfloc;
  
  //操作时间(小时/次)
  private Double ri_TSwitch;
  
  //投资费用(万元)
  private Double ei_Invest;
  
  //有功(兆瓦)
  private Double P;
  
  //电流(安培)
  private Double A;
  
  //停运率贡献(%)
  private Double ro_RContribution;
  
  //停运时间贡献(%)
  private Double ro_UContribution;
  
  //停电电量贡献(%)
  private Double ro_EnsContribution;
  
  //起节点索引
  private Integer NodeIPtr;
  
  //终节点索引
  private Integer NodeJPtr;
  
  //岛
  private Integer Island;
  
  //I侧边设备索引
  private Integer EdgeI;
  
  //J侧边设备索引
  private Integer EdgeJ;
  
  //控制设备类型
  private Integer JointDeviceType;
  
  //控制设备索引
  private Integer JointDeviceIndex;
  
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
    
  public String getVoltageLevel()
  {
    return VoltageLevel;
  }
    
  public void setVoltageLevel(String VoltageLevel)
  {
    this.VoltageLevel = VoltageLevel;
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
    
  public Integer getStatus()
  {
    return Status;
  }
    
  public void setStatus(Integer Status)
  {
    this.Status = Status;
  }
    
  public String getConnectivityNodeI()
  {
    return ConnectivityNodeI;
  }
    
  public void setConnectivityNodeI(String ConnectivityNodeI)
  {
    this.ConnectivityNodeI = ConnectivityNodeI;
  }
    
  public String getConnectivityNodeJ()
  {
    return ConnectivityNodeJ;
  }
    
  public void setConnectivityNodeJ(String ConnectivityNodeJ)
  {
    this.ConnectivityNodeJ = ConnectivityNodeJ;
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
    
  public Double getri_TSwitch()
  {
    return ri_TSwitch;
  }
    
  public void setri_TSwitch(Double ri_TSwitch)
  {
    this.ri_TSwitch = ri_TSwitch;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Double getP()
  {
    return P;
  }
    
  public void setP(Double P)
  {
    this.P = P;
  }
    
  public Double getA()
  {
    return A;
  }
    
  public void setA(Double A)
  {
    this.A = A;
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
    
  public Integer getNodeIPtr()
  {
    return NodeIPtr;
  }
    
  public void setNodeIPtr(Integer NodeIPtr)
  {
    this.NodeIPtr = NodeIPtr;
  }
    
  public Integer getNodeJPtr()
  {
    return NodeJPtr;
  }
    
  public void setNodeJPtr(Integer NodeJPtr)
  {
    this.NodeJPtr = NodeJPtr;
  }
    
  public Integer getIsland()
  {
    return Island;
  }
    
  public void setIsland(Integer Island)
  {
    this.Island = Island;
  }
    
  public Integer getEdgeI()
  {
    return EdgeI;
  }
    
  public void setEdgeI(Integer EdgeI)
  {
    this.EdgeI = EdgeI;
  }
    
  public Integer getEdgeJ()
  {
    return EdgeJ;
  }
    
  public void setEdgeJ(Integer EdgeJ)
  {
    this.EdgeJ = EdgeJ;
  }
    
  public Integer getJointDeviceType()
  {
    return JointDeviceType;
  }
    
  public void setJointDeviceType(Integer JointDeviceType)
  {
    this.JointDeviceType = JointDeviceType;
  }
    
  public Integer getJointDeviceIndex()
  {
    return JointDeviceIndex;
  }
    
  public void setJointDeviceIndex(Integer JointDeviceIndex)
  {
    this.JointDeviceIndex = JointDeviceIndex;
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
    return "DCBreaker ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", Status = " + Status
	 + ", ConnectivityNodeI = " + ConnectivityNodeI
	 + ", ConnectivityNodeJ = " + ConnectivityNodeJ
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ri_TSwitch = " + ri_TSwitch
	 + ", ei_Invest = " + ei_Invest
	 + ", P = " + P
	 + ", A = " + A
	 + ", ro_RContribution = " + ro_RContribution
	 + ", ro_UContribution = " + ro_UContribution
	 + ", ro_EnsContribution = " + ro_EnsContribution
	 + ", NodeIPtr = " + NodeIPtr
	 + ", NodeJPtr = " + NodeJPtr
	 + ", Island = " + Island
	 + ", EdgeI = " + EdgeI
	 + ", EdgeJ = " + EdgeJ
	 + ", JointDeviceType = " + JointDeviceType
	 + ", JointDeviceIndex = " + JointDeviceIndex
	 + ", Outage = " + Outage+"]";
  }
    
}
    
