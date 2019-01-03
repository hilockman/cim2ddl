package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*直流线路段	*
***********************/
public class DCLineSegment  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //起厂站
  private String iSubstation;
  
  //终厂站
  private String zSubstation;
  
  //起电压等级
  private String iVoltageLevel;
  
  //终电压等级
  private String zVoltageLevel;
  
  //所属线路
  private String Line;
  
  //起直流节点
  private String ConnectivityNodeI;
  
  //终直流节点
  private String ConnectivityNodeJ;
  
  //线路类型
  private String Type;
  
  //线路长度(千米)
  private Double Length;
  
  //电流限值(安)
  private Double aLimit;
  
  //电阻(标幺)
  private Double R;
  
  //电感(标幺)
  private Double L;
  
  //电容(标幺)
  private Double C;
  
  //触发角(度)
  private Double Alpha;
  
  //关断角(度)
  private Double Gamma;
  
  //控制功率(兆瓦)
  private Double SchedP;
  
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
  
  //主接线可靠性设备类型
  private Integer MCRType;
  
  //主接线可靠性源/荷功率
  private Double MCRPower;
  
  //起点有功(兆瓦)
  private Double Pi;
  
  //终点有功(兆瓦)
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
  
  //所属线路索引
  private Integer LinePtr;
  
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
  
  //起边线路索引
  private Integer EdgeI;
  
  //终边线路索引
  private Integer EdgeJ;
  
  //综合状态(着色)
  private Integer State;
  
  //拓扑状态
  private Integer Open;
  
  //计算状态
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
    
  public String getiSubstation()
  {
    return iSubstation;
  }
    
  public void setiSubstation(String iSubstation)
  {
    this.iSubstation = iSubstation;
  }
    
  public String getzSubstation()
  {
    return zSubstation;
  }
    
  public void setzSubstation(String zSubstation)
  {
    this.zSubstation = zSubstation;
  }
    
  public String getiVoltageLevel()
  {
    return iVoltageLevel;
  }
    
  public void setiVoltageLevel(String iVoltageLevel)
  {
    this.iVoltageLevel = iVoltageLevel;
  }
    
  public String getzVoltageLevel()
  {
    return zVoltageLevel;
  }
    
  public void setzVoltageLevel(String zVoltageLevel)
  {
    this.zVoltageLevel = zVoltageLevel;
  }
    
  public String getLine()
  {
    return Line;
  }
    
  public void setLine(String Line)
  {
    this.Line = Line;
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
    
  public String getType()
  {
    return Type;
  }
    
  public void setType(String Type)
  {
    this.Type = Type;
  }
    
  public Double getLength()
  {
    return Length;
  }
    
  public void setLength(Double Length)
  {
    this.Length = Length;
  }
    
  public Double getaLimit()
  {
    return aLimit;
  }
    
  public void setaLimit(Double aLimit)
  {
    this.aLimit = aLimit;
  }
    
  public Double getR()
  {
    return R;
  }
    
  public void setR(Double R)
  {
    this.R = R;
  }
    
  public Double getL()
  {
    return L;
  }
    
  public void setL(Double L)
  {
    this.L = L;
  }
    
  public Double getC()
  {
    return C;
  }
    
  public void setC(Double C)
  {
    this.C = C;
  }
    
  public Double getAlpha()
  {
    return Alpha;
  }
    
  public void setAlpha(Double Alpha)
  {
    this.Alpha = Alpha;
  }
    
  public Double getGamma()
  {
    return Gamma;
  }
    
  public void setGamma(Double Gamma)
  {
    this.Gamma = Gamma;
  }
    
  public Double getSchedP()
  {
    return SchedP;
  }
    
  public void setSchedP(Double SchedP)
  {
    this.SchedP = SchedP;
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
    
  public Integer getMCRType()
  {
    return MCRType;
  }
    
  public void setMCRType(Integer MCRType)
  {
    this.MCRType = MCRType;
  }
    
  public Double getMCRPower()
  {
    return MCRPower;
  }
    
  public void setMCRPower(Double MCRPower)
  {
    this.MCRPower = MCRPower;
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
    
  public Integer getLinePtr()
  {
    return LinePtr;
  }
    
  public void setLinePtr(Integer LinePtr)
  {
    this.LinePtr = LinePtr;
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
    return "DCLineSegment ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", iSubstation = " + iSubstation
	 + ", zSubstation = " + zSubstation
	 + ", iVoltageLevel = " + iVoltageLevel
	 + ", zVoltageLevel = " + zVoltageLevel
	 + ", Line = " + Line
	 + ", ConnectivityNodeI = " + ConnectivityNodeI
	 + ", ConnectivityNodeJ = " + ConnectivityNodeJ
	 + ", Type = " + Type
	 + ", Length = " + Length
	 + ", aLimit = " + aLimit
	 + ", R = " + R
	 + ", L = " + L
	 + ", C = " + C
	 + ", Alpha = " + Alpha
	 + ", Gamma = " + Gamma
	 + ", SchedP = " + SchedP
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ei_Invest = " + ei_Invest
	 + ", MCRType = " + MCRType
	 + ", MCRPower = " + MCRPower
	 + ", Pi = " + Pi
	 + ", Pj = " + Pj
	 + ", A = " + A
	 + ", LossP = " + LossP
	 + ", ro_RContribution = " + ro_RContribution
	 + ", ro_UContribution = " + ro_UContribution
	 + ", ro_EnsContribution = " + ro_EnsContribution
	 + ", LinePtr = " + LinePtr
	 + ", NodeIPtr = " + NodeIPtr
	 + ", NodeJPtr = " + NodeJPtr
	 + ", TopoBusI = " + TopoBusI
	 + ", TopoBusJ = " + TopoBusJ
	 + ", Island = " + Island
	 + ", EdgeI = " + EdgeI
	 + ", EdgeJ = " + EdgeJ
	 + ", State = " + State
	 + ", Open = " + Open
	 + ", Outage = " + Outage+"]";
  }
    
}
    
