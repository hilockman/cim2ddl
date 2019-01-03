package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*直流直流变换器	*
***********************/
public class DCDCConverter  implements MemIndexable 
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
  
  //I侧电压等级
  private String iVoltageLevel;
  
  //J侧电压等级
  private String zVoltageLevel;
  
  //所属电力电子变压器
  private String ElectronicTransformer;
  
  //隔离器
  private Integer Isolator;
  
  //I侧节点
  private String ConnectivityNodeI;
  
  //J侧节点
  private String ConnectivityNodeJ;
  
  //额定容量(兆瓦)
  private Double RatedPower;
  
  //I侧控制模式
  private Integer ControlModeI;
  
  //I侧控制值(电压标幺,功率兆瓦)
  private Double ControlValueI;
  
  //J侧控制模式
  private Integer ControlModeJ;
  
  //J侧控制值(电压标幺,功率兆瓦)
  private Double ControlValueJ;
  
  //损耗多项式参数(a)
  private Double LossParamA;
  
  //损耗多项式参数(b)
  private Double LossParamB;
  
  //损耗多项式参数(c)
  private Double LossParamC;
  
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
  
  //供电方向
  private Integer ri_Direction;
  
  //投资费用(万元)
  private Double ei_Invest;
  
  //I侧主接线可靠性设备类型
  private Integer MCRTypeI;
  
  //J侧主接线可靠性设备类型
  private Integer MCRTypeJ;
  
  //主接线可靠性源/荷功率
  private Double MCRPower;
  
  //I侧电压(千伏)
  private Double Vi;
  
  //I侧有功(兆瓦)
  private Double Pi;
  
  //I侧电流(安培)
  private Double Ai;
  
  //J侧电压(千伏)
  private Double Vj;
  
  //J侧有功(兆瓦)
  private Double Pj;
  
  //J侧电流(安培)
  private Double Aj;
  
  //损耗(兆瓦)
  private Double Loss;
  
  //停运率贡献(%)
  private Double ro_RContribution;
  
  //停运时间贡献(%)
  private Double ro_UContribution;
  
  //停电电量贡献(%)
  private Double ro_EnsContribution;
  
  //I侧功率计算值(兆瓦)
  private Double CalculatePI;
  
  //J侧功率计算值(兆瓦)
  private Double CalculatePJ;
  
  //I侧电压等级索引
  private Integer VoltITR;
  
  //J侧电压等级索引
  private Integer VoltJTR;
  
  //I侧节点索引
  private Integer NodeIPTR;
  
  //J侧节点索引
  private Integer NodeJPTR;
  
  //I侧拓扑节点
  private Integer TopoBusI;
  
  //J侧拓扑节点
  private Integer TopoBusJ;
  
  //I侧岛
  private Integer IslandI;
  
  //J侧岛
  private Integer IslandJ;
  
  //I侧边设备索引
  private Integer EdgeI;
  
  //J侧边设备索引
  private Integer EdgeJ;
  
  //I侧功率状态
  private Integer PStateI;
  
  //J侧功率状态
  private Integer PStateJ;
  
  //类型
  private Integer Type;
  
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
    
  public String getElectronicTransformer()
  {
    return ElectronicTransformer;
  }
    
  public void setElectronicTransformer(String ElectronicTransformer)
  {
    this.ElectronicTransformer = ElectronicTransformer;
  }
    
  public Integer getIsolator()
  {
    return Isolator;
  }
    
  public void setIsolator(Integer Isolator)
  {
    this.Isolator = Isolator;
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
    
  public Double getRatedPower()
  {
    return RatedPower;
  }
    
  public void setRatedPower(Double RatedPower)
  {
    this.RatedPower = RatedPower;
  }
    
  public Integer getControlModeI()
  {
    return ControlModeI;
  }
    
  public void setControlModeI(Integer ControlModeI)
  {
    this.ControlModeI = ControlModeI;
  }
    
  public Double getControlValueI()
  {
    return ControlValueI;
  }
    
  public void setControlValueI(Double ControlValueI)
  {
    this.ControlValueI = ControlValueI;
  }
    
  public Integer getControlModeJ()
  {
    return ControlModeJ;
  }
    
  public void setControlModeJ(Integer ControlModeJ)
  {
    this.ControlModeJ = ControlModeJ;
  }
    
  public Double getControlValueJ()
  {
    return ControlValueJ;
  }
    
  public void setControlValueJ(Double ControlValueJ)
  {
    this.ControlValueJ = ControlValueJ;
  }
    
  public Double getLossParamA()
  {
    return LossParamA;
  }
    
  public void setLossParamA(Double LossParamA)
  {
    this.LossParamA = LossParamA;
  }
    
  public Double getLossParamB()
  {
    return LossParamB;
  }
    
  public void setLossParamB(Double LossParamB)
  {
    this.LossParamB = LossParamB;
  }
    
  public Double getLossParamC()
  {
    return LossParamC;
  }
    
  public void setLossParamC(Double LossParamC)
  {
    this.LossParamC = LossParamC;
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
    
  public Integer getri_Direction()
  {
    return ri_Direction;
  }
    
  public void setri_Direction(Integer ri_Direction)
  {
    this.ri_Direction = ri_Direction;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Integer getMCRTypeI()
  {
    return MCRTypeI;
  }
    
  public void setMCRTypeI(Integer MCRTypeI)
  {
    this.MCRTypeI = MCRTypeI;
  }
    
  public Integer getMCRTypeJ()
  {
    return MCRTypeJ;
  }
    
  public void setMCRTypeJ(Integer MCRTypeJ)
  {
    this.MCRTypeJ = MCRTypeJ;
  }
    
  public Double getMCRPower()
  {
    return MCRPower;
  }
    
  public void setMCRPower(Double MCRPower)
  {
    this.MCRPower = MCRPower;
  }
    
  public Double getVi()
  {
    return Vi;
  }
    
  public void setVi(Double Vi)
  {
    this.Vi = Vi;
  }
    
  public Double getPi()
  {
    return Pi;
  }
    
  public void setPi(Double Pi)
  {
    this.Pi = Pi;
  }
    
  public Double getAi()
  {
    return Ai;
  }
    
  public void setAi(Double Ai)
  {
    this.Ai = Ai;
  }
    
  public Double getVj()
  {
    return Vj;
  }
    
  public void setVj(Double Vj)
  {
    this.Vj = Vj;
  }
    
  public Double getPj()
  {
    return Pj;
  }
    
  public void setPj(Double Pj)
  {
    this.Pj = Pj;
  }
    
  public Double getAj()
  {
    return Aj;
  }
    
  public void setAj(Double Aj)
  {
    this.Aj = Aj;
  }
    
  public Double getLoss()
  {
    return Loss;
  }
    
  public void setLoss(Double Loss)
  {
    this.Loss = Loss;
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
    
  public Double getCalculatePI()
  {
    return CalculatePI;
  }
    
  public void setCalculatePI(Double CalculatePI)
  {
    this.CalculatePI = CalculatePI;
  }
    
  public Double getCalculatePJ()
  {
    return CalculatePJ;
  }
    
  public void setCalculatePJ(Double CalculatePJ)
  {
    this.CalculatePJ = CalculatePJ;
  }
    
  public Integer getVoltITR()
  {
    return VoltITR;
  }
    
  public void setVoltITR(Integer VoltITR)
  {
    this.VoltITR = VoltITR;
  }
    
  public Integer getVoltJTR()
  {
    return VoltJTR;
  }
    
  public void setVoltJTR(Integer VoltJTR)
  {
    this.VoltJTR = VoltJTR;
  }
    
  public Integer getNodeIPTR()
  {
    return NodeIPTR;
  }
    
  public void setNodeIPTR(Integer NodeIPTR)
  {
    this.NodeIPTR = NodeIPTR;
  }
    
  public Integer getNodeJPTR()
  {
    return NodeJPTR;
  }
    
  public void setNodeJPTR(Integer NodeJPTR)
  {
    this.NodeJPTR = NodeJPTR;
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
    
  public Integer getIslandI()
  {
    return IslandI;
  }
    
  public void setIslandI(Integer IslandI)
  {
    this.IslandI = IslandI;
  }
    
  public Integer getIslandJ()
  {
    return IslandJ;
  }
    
  public void setIslandJ(Integer IslandJ)
  {
    this.IslandJ = IslandJ;
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
    
  public Integer getPStateI()
  {
    return PStateI;
  }
    
  public void setPStateI(Integer PStateI)
  {
    this.PStateI = PStateI;
  }
    
  public Integer getPStateJ()
  {
    return PStateJ;
  }
    
  public void setPStateJ(Integer PStateJ)
  {
    this.PStateJ = PStateJ;
  }
    
  public Integer getType()
  {
    return Type;
  }
    
  public void setType(Integer Type)
  {
    this.Type = Type;
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
    return "DCDCConverter ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Substation = " + Substation
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", iVoltageLevel = " + iVoltageLevel
	 + ", zVoltageLevel = " + zVoltageLevel
	 + ", ElectronicTransformer = " + ElectronicTransformer
	 + ", Isolator = " + Isolator
	 + ", ConnectivityNodeI = " + ConnectivityNodeI
	 + ", ConnectivityNodeJ = " + ConnectivityNodeJ
	 + ", RatedPower = " + RatedPower
	 + ", ControlModeI = " + ControlModeI
	 + ", ControlValueI = " + ControlValueI
	 + ", ControlModeJ = " + ControlModeJ
	 + ", ControlValueJ = " + ControlValueJ
	 + ", LossParamA = " + LossParamA
	 + ", LossParamB = " + LossParamB
	 + ", LossParamC = " + LossParamC
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ri_Direction = " + ri_Direction
	 + ", ei_Invest = " + ei_Invest
	 + ", MCRTypeI = " + MCRTypeI
	 + ", MCRTypeJ = " + MCRTypeJ
	 + ", MCRPower = " + MCRPower
	 + ", Vi = " + Vi
	 + ", Pi = " + Pi
	 + ", Ai = " + Ai
	 + ", Vj = " + Vj
	 + ", Pj = " + Pj
	 + ", Aj = " + Aj
	 + ", Loss = " + Loss
	 + ", ro_RContribution = " + ro_RContribution
	 + ", ro_UContribution = " + ro_UContribution
	 + ", ro_EnsContribution = " + ro_EnsContribution
	 + ", CalculatePI = " + CalculatePI
	 + ", CalculatePJ = " + CalculatePJ
	 + ", VoltITR = " + VoltITR
	 + ", VoltJTR = " + VoltJTR
	 + ", NodeIPTR = " + NodeIPTR
	 + ", NodeJPTR = " + NodeJPTR
	 + ", TopoBusI = " + TopoBusI
	 + ", TopoBusJ = " + TopoBusJ
	 + ", IslandI = " + IslandI
	 + ", IslandJ = " + IslandJ
	 + ", EdgeI = " + EdgeI
	 + ", EdgeJ = " + EdgeJ
	 + ", PStateI = " + PStateI
	 + ", PStateJ = " + PStateJ
	 + ", Type = " + Type
	 + ", Open = " + Open
	 + ", Outage = " + Outage+"]";
  }
    
}
    
