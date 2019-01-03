package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*直流短路电流限制器	*
***********************/
public class DCShortCircuitLimit  implements MemIndexable 
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
  
  //起节点
  private String ConnectivityNodeI;
  
  //终节点
  private String ConnectivityNodeJ;
  
  //等效电阻(标幺)
  private Double R;
  
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
  
  //投资费用(万元)
  private Double ei_Invest;
  
  //I侧有功(兆瓦)
  private Double Pi;
  
  //J侧有功(兆瓦)
  private Double Pj;
  
  //电流(安培)
  private Double A;
  
  //损耗有功(兆瓦)
  private Double LossP;
  
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
  
  //起拓扑节点
  private Integer TopoBusI;
  
  //终拓扑节点
  private Integer TopoBusJ;
  
  //岛
  private Integer Island;
  
  //I侧边设备索引
  private Integer EdgeI;
  
  //J侧边设备索引
  private Integer EdgeJ;
  
  //中间信息
  private Integer Proc;
  
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
    
  public Double getR()
  {
    return R;
  }
    
  public void setR(Double R)
  {
    this.R = R;
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
    
  public Double getPi()
  {
    return Pi;
  }
    
  public void setPi(Double Pi)
  {
    this.Pi = Pi;
  }
    
  public Double getPj()
  {
    return Pj;
  }
    
  public void setPj(Double Pj)
  {
    this.Pj = Pj;
  }
    
  public Double getA()
  {
    return A;
  }
    
  public void setA(Double A)
  {
    this.A = A;
  }
    
  public Double getLossP()
  {
    return LossP;
  }
    
  public void setLossP(Double LossP)
  {
    this.LossP = LossP;
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
    
  public Integer getTopoBusI()
  {
    return TopoBusI;
  }
    
  public void setTopoBusI(Integer TopoBusI)
  {
    this.TopoBusI = TopoBusI;
  }
    
  public Integer getTopoBusJ()
  {
    return TopoBusJ;
  }
    
  public void setTopoBusJ(Integer TopoBusJ)
  {
    this.TopoBusJ = TopoBusJ;
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
    
  public Integer getProc()
  {
    return Proc;
  }
    
  public void setProc(Integer Proc)
  {
    this.Proc = Proc;
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
    return "DCShortCircuitLimit ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", ConnectivityNodeI = " + ConnectivityNodeI
	 + ", ConnectivityNodeJ = " + ConnectivityNodeJ
	 + ", R = " + R
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ei_Invest = " + ei_Invest
	 + ", Pi = " + Pi
	 + ", Pj = " + Pj
	 + ", A = " + A
	 + ", LossP = " + LossP
	 + ", ro_RContribution = " + ro_RContribution
	 + ", ro_UContribution = " + ro_UContribution
	 + ", ro_EnsContribution = " + ro_EnsContribution
	 + ", NodeIPtr = " + NodeIPtr
	 + ", NodeJPtr = " + NodeJPtr
	 + ", TopoBusI = " + TopoBusI
	 + ", TopoBusJ = " + TopoBusJ
	 + ", Island = " + Island
	 + ", EdgeI = " + EdgeI
	 + ", EdgeJ = " + EdgeJ
	 + ", Proc = " + Proc
	 + ", Open = " + Open
	 + ", Outage = " + Outage+"]";
  }
    
}
    
