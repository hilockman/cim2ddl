package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*变压器绕组	*
***********************/
public class TransformerWinding  implements MemIndexable 
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
  
  //起电压等级
  private String iVoltageLevel;
  
  //终电压等级
  private String zVoltageLevel;
  
  //所属变压器
  private String PowerTransformer;
  
  //起变压器分接头类型
  private String iTapchanger;
  
  //终变压器分接头类型
  private String zTapchanger;
  
  //起节点
  private String ConnectivityNodeI;
  
  //终节点
  private String ConnectivityNodeJ;
  
  //容量(兆伏安)
  private Double RatedMva;
  
  //起点铭牌电压(千伏)
  private Double iRatedkV;
  
  //终点铭牌电压(千伏)
  private Double zRatedkV;
  
  //电阻(标幺)
  private Double R;
  
  //电抗(标幺)
  private Double X;
  
  //电导(标幺)
  private Double G;
  
  //电纳(标幺)
  private Double B;
  
  //零序电阻(标幺)
  private Double R0;
  
  //零序电抗(标幺)
  private Double X0;
  
  //起变压器档位
  private Integer iTap;
  
  //终变压器档位
  private Integer zTap;
  
  //变压器运行状态
  private Integer TranStatus;
  
  //中性点接地状态
  private Integer NeutralStatus;
  
  //变压器绕组类型
  private Integer WindingType;
  
  //自动调压
  private Integer WindingAVR;
  
  //自耦变
  private Integer CoupledTran;
  
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
  
  //供电方向
  private Integer ri_Direction;
  
  //投资费用(万元)
  private Double ei_Invest;
  
  //单相接地频率(次/年)
  private Double vd_RScc1;
  
  //相间短路频率(次/年)
  private Double vd_RScc2;
  
  //三相短路频率(次/年)
  private Double vd_RScc3;
  
  //两相接地频率(次/年)
  private Double vd_RScc4;
  
  //低压自动保护整定(标幺)
  private Double RATunning;
  
  //低压自动保护时限(周)
  private Double RADelay;
  
  //低压自动保护压板
  private Integer RAPlate;
  
  //低周自动保护整定(频率)
  private Double RUTunning;
  
  //低周自动保护时限(周)
  private Double RUDelay;
  
  //低周自动保护压板
  private Integer RUPlate;
  
  //起主接线可靠性设备类型
  private Integer MCRTypeI;
  
  //终主接线可靠性设备类型
  private Integer MCRTypeJ;
  
  //主接线可靠性源/荷功率
  private Double MCRPower;
  
  //I侧有功(兆瓦)
  private Double Pi;
  
  //I侧无功(兆乏)
  private Double Qi;
  
  //I侧电流(安培)
  private Double Ai;
  
  //Z侧有功(兆瓦)
  private Double Pz;
  
  //Z侧无功(兆乏)
  private Double Qz;
  
  //Z侧电流(安培)
  private Double Az;
  
  //损耗有功(兆瓦)
  private Double LossP;
  
  //损耗无功(兆乏)
  private Double LossQ;
  
  //I侧A相短路电流(安培)
  private Double ScIaI;
  
  //I侧B相短路电流(安培)
  private Double ScIbI;
  
  //I侧C相短路电流(安培)
  private Double ScIcI;
  
  //I侧正序短路电流(安培)
  private Double ScI1I;
  
  //I侧负序短路电流(安培)
  private Double ScI2I;
  
  //I侧零序短路电流(安培)
  private Double ScI0I;
  
  //J侧A相短路电流(安培)
  private Double ScIaJ;
  
  //J侧B相短路电流(安培)
  private Double ScIbJ;
  
  //J侧C相短路电流(安培)
  private Double ScIcJ;
  
  //J侧正序短路电流(安培)
  private Double ScI1J;
  
  //J侧负序短路电流(安培)
  private Double ScI2J;
  
  //J侧零序短路电流(安培)
  private Double ScI0J;
  
  //停运率贡献(%)
  private Double ro_RContribution;
  
  //停运时间贡献(%)
  private Double ro_UContribution;
  
  //停电电量贡献(%)
  private Double ro_EnsContribution;
  
  //N-1通过情况
  private Integer sa_Result;
  
  //N-1形成孤岛
  private Integer sa_Island;
  
  //N-1负荷损失(兆伏安)
  private Double sa_Failure;
  
  //N-1转电节点
  private Integer sa_ShiftNode;
  
  //变压器索引
  private Integer TranPtr;
  
  //起电压等级索引
  private Integer VoltIPtr;
  
  //终电压等级索引
  private Integer VoltJPtr;
  
  //起变压器分接头索引
  private Integer TapChangerIPtr;
  
  //终变压器分接头索引
  private Integer TapChangerJPtr;
  
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
  
  //起边变压器索引
  private Integer EdgeI;
  
  //终边变压器索引
  private Integer EdgeJ;
  
  //变压器中性点位置
  private Integer TranMidSide;
  
  //配网设备
  private Integer Distribution;
  
  //综合状态(着色)
  private Integer State;
  
  //环网标记
  private Integer InRing;
  
  //辐射网号
  private Integer Radiate;
  
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
    
  public String getPowerTransformer()
  {
    return PowerTransformer;
  }
    
  public void setPowerTransformer(String PowerTransformer)
  {
    this.PowerTransformer = PowerTransformer;
  }
    
  public String getiTapchanger()
  {
    return iTapchanger;
  }
    
  public void setiTapchanger(String iTapchanger)
  {
    this.iTapchanger = iTapchanger;
  }
    
  public String getzTapchanger()
  {
    return zTapchanger;
  }
    
  public void setzTapchanger(String zTapchanger)
  {
    this.zTapchanger = zTapchanger;
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
    
  public Double getRatedMva()
  {
    return RatedMva;
  }
    
  public void setRatedMva(Double RatedMva)
  {
    this.RatedMva = RatedMva;
  }
    
  public Double getiRatedkV()
  {
    return iRatedkV;
  }
    
  public void setiRatedkV(Double iRatedkV)
  {
    this.iRatedkV = iRatedkV;
  }
    
  public Double getzRatedkV()
  {
    return zRatedkV;
  }
    
  public void setzRatedkV(Double zRatedkV)
  {
    this.zRatedkV = zRatedkV;
  }
    
  public Double getR()
  {
    return R;
  }
    
  public void setR(Double R)
  {
    this.R = R;
  }
    
  public Double getX()
  {
    return X;
  }
    
  public void setX(Double X)
  {
    this.X = X;
  }
    
  public Double getG()
  {
    return G;
  }
    
  public void setG(Double G)
  {
    this.G = G;
  }
    
  public Double getB()
  {
    return B;
  }
    
  public void setB(Double B)
  {
    this.B = B;
  }
    
  public Double getR0()
  {
    return R0;
  }
    
  public void setR0(Double R0)
  {
    this.R0 = R0;
  }
    
  public Double getX0()
  {
    return X0;
  }
    
  public void setX0(Double X0)
  {
    this.X0 = X0;
  }
    
  public Integer getiTap()
  {
    return iTap;
  }
    
  public void setiTap(Integer iTap)
  {
    this.iTap = iTap;
  }
    
  public Integer getzTap()
  {
    return zTap;
  }
    
  public void setzTap(Integer zTap)
  {
    this.zTap = zTap;
  }
    
  public Integer getTranStatus()
  {
    return TranStatus;
  }
    
  public void setTranStatus(Integer TranStatus)
  {
    this.TranStatus = TranStatus;
  }
    
  public Integer getNeutralStatus()
  {
    return NeutralStatus;
  }
    
  public void setNeutralStatus(Integer NeutralStatus)
  {
    this.NeutralStatus = NeutralStatus;
  }
    
  public Integer getWindingType()
  {
    return WindingType;
  }
    
  public void setWindingType(Integer WindingType)
  {
    this.WindingType = WindingType;
  }
    
  public Integer getWindingAVR()
  {
    return WindingAVR;
  }
    
  public void setWindingAVR(Integer WindingAVR)
  {
    this.WindingAVR = WindingAVR;
  }
    
  public Integer getCoupledTran()
  {
    return CoupledTran;
  }
    
  public void setCoupledTran(Integer CoupledTran)
  {
    this.CoupledTran = CoupledTran;
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
    
  public Double getvd_RScc1()
  {
    return vd_RScc1;
  }
    
  public void setvd_RScc1(Double vd_RScc1)
  {
    this.vd_RScc1 = vd_RScc1;
  }
    
  public Double getvd_RScc2()
  {
    return vd_RScc2;
  }
    
  public void setvd_RScc2(Double vd_RScc2)
  {
    this.vd_RScc2 = vd_RScc2;
  }
    
  public Double getvd_RScc3()
  {
    return vd_RScc3;
  }
    
  public void setvd_RScc3(Double vd_RScc3)
  {
    this.vd_RScc3 = vd_RScc3;
  }
    
  public Double getvd_RScc4()
  {
    return vd_RScc4;
  }
    
  public void setvd_RScc4(Double vd_RScc4)
  {
    this.vd_RScc4 = vd_RScc4;
  }
    
  public Double getRATunning()
  {
    return RATunning;
  }
    
  public void setRATunning(Double RATunning)
  {
    this.RATunning = RATunning;
  }
    
  public Double getRADelay()
  {
    return RADelay;
  }
    
  public void setRADelay(Double RADelay)
  {
    this.RADelay = RADelay;
  }
    
  public Integer getRAPlate()
  {
    return RAPlate;
  }
    
  public void setRAPlate(Integer RAPlate)
  {
    this.RAPlate = RAPlate;
  }
    
  public Double getRUTunning()
  {
    return RUTunning;
  }
    
  public void setRUTunning(Double RUTunning)
  {
    this.RUTunning = RUTunning;
  }
    
  public Double getRUDelay()
  {
    return RUDelay;
  }
    
  public void setRUDelay(Double RUDelay)
  {
    this.RUDelay = RUDelay;
  }
    
  public Integer getRUPlate()
  {
    return RUPlate;
  }
    
  public void setRUPlate(Integer RUPlate)
  {
    this.RUPlate = RUPlate;
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
    
  public Double getPi()
  {
    return Pi;
  }
    
  public void setPi(Double Pi)
  {
    this.Pi = Pi;
  }
    
  public Double getQi()
  {
    return Qi;
  }
    
  public void setQi(Double Qi)
  {
    this.Qi = Qi;
  }
    
  public Double getAi()
  {
    return Ai;
  }
    
  public void setAi(Double Ai)
  {
    this.Ai = Ai;
  }
    
  public Double getPz()
  {
    return Pz;
  }
    
  public void setPz(Double Pz)
  {
    this.Pz = Pz;
  }
    
  public Double getQz()
  {
    return Qz;
  }
    
  public void setQz(Double Qz)
  {
    this.Qz = Qz;
  }
    
  public Double getAz()
  {
    return Az;
  }
    
  public void setAz(Double Az)
  {
    this.Az = Az;
  }
    
  public Double getLossP()
  {
    return LossP;
  }
    
  public void setLossP(Double LossP)
  {
    this.LossP = LossP;
  }
    
  public Double getLossQ()
  {
    return LossQ;
  }
    
  public void setLossQ(Double LossQ)
  {
    this.LossQ = LossQ;
  }
    
  public Double getScIaI()
  {
    return ScIaI;
  }
    
  public void setScIaI(Double ScIaI)
  {
    this.ScIaI = ScIaI;
  }
    
  public Double getScIbI()
  {
    return ScIbI;
  }
    
  public void setScIbI(Double ScIbI)
  {
    this.ScIbI = ScIbI;
  }
    
  public Double getScIcI()
  {
    return ScIcI;
  }
    
  public void setScIcI(Double ScIcI)
  {
    this.ScIcI = ScIcI;
  }
    
  public Double getScI1I()
  {
    return ScI1I;
  }
    
  public void setScI1I(Double ScI1I)
  {
    this.ScI1I = ScI1I;
  }
    
  public Double getScI2I()
  {
    return ScI2I;
  }
    
  public void setScI2I(Double ScI2I)
  {
    this.ScI2I = ScI2I;
  }
    
  public Double getScI0I()
  {
    return ScI0I;
  }
    
  public void setScI0I(Double ScI0I)
  {
    this.ScI0I = ScI0I;
  }
    
  public Double getScIaJ()
  {
    return ScIaJ;
  }
    
  public void setScIaJ(Double ScIaJ)
  {
    this.ScIaJ = ScIaJ;
  }
    
  public Double getScIbJ()
  {
    return ScIbJ;
  }
    
  public void setScIbJ(Double ScIbJ)
  {
    this.ScIbJ = ScIbJ;
  }
    
  public Double getScIcJ()
  {
    return ScIcJ;
  }
    
  public void setScIcJ(Double ScIcJ)
  {
    this.ScIcJ = ScIcJ;
  }
    
  public Double getScI1J()
  {
    return ScI1J;
  }
    
  public void setScI1J(Double ScI1J)
  {
    this.ScI1J = ScI1J;
  }
    
  public Double getScI2J()
  {
    return ScI2J;
  }
    
  public void setScI2J(Double ScI2J)
  {
    this.ScI2J = ScI2J;
  }
    
  public Double getScI0J()
  {
    return ScI0J;
  }
    
  public void setScI0J(Double ScI0J)
  {
    this.ScI0J = ScI0J;
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
    
  public Integer getsa_Result()
  {
    return sa_Result;
  }
    
  public void setsa_Result(Integer sa_Result)
  {
    this.sa_Result = sa_Result;
  }
    
  public Integer getsa_Island()
  {
    return sa_Island;
  }
    
  public void setsa_Island(Integer sa_Island)
  {
    this.sa_Island = sa_Island;
  }
    
  public Double getsa_Failure()
  {
    return sa_Failure;
  }
    
  public void setsa_Failure(Double sa_Failure)
  {
    this.sa_Failure = sa_Failure;
  }
    
  public Integer getsa_ShiftNode()
  {
    return sa_ShiftNode;
  }
    
  public void setsa_ShiftNode(Integer sa_ShiftNode)
  {
    this.sa_ShiftNode = sa_ShiftNode;
  }
    
  public Integer getTranPtr()
  {
    return TranPtr;
  }
    
  public void setTranPtr(Integer TranPtr)
  {
    this.TranPtr = TranPtr;
  }
    
  public Integer getVoltIPtr()
  {
    return VoltIPtr;
  }
    
  public void setVoltIPtr(Integer VoltIPtr)
  {
    this.VoltIPtr = VoltIPtr;
  }
    
  public Integer getVoltJPtr()
  {
    return VoltJPtr;
  }
    
  public void setVoltJPtr(Integer VoltJPtr)
  {
    this.VoltJPtr = VoltJPtr;
  }
    
  public Integer getTapChangerIPtr()
  {
    return TapChangerIPtr;
  }
    
  public void setTapChangerIPtr(Integer TapChangerIPtr)
  {
    this.TapChangerIPtr = TapChangerIPtr;
  }
    
  public Integer getTapChangerJPtr()
  {
    return TapChangerJPtr;
  }
    
  public void setTapChangerJPtr(Integer TapChangerJPtr)
  {
    this.TapChangerJPtr = TapChangerJPtr;
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
    
  public Integer getTranMidSide()
  {
    return TranMidSide;
  }
    
  public void setTranMidSide(Integer TranMidSide)
  {
    this.TranMidSide = TranMidSide;
  }
    
  public Integer getDistribution()
  {
    return Distribution;
  }
    
  public void setDistribution(Integer Distribution)
  {
    this.Distribution = Distribution;
  }
    
  public Integer getState()
  {
    return State;
  }
    
  public void setState(Integer State)
  {
    this.State = State;
  }
    
  public Integer getInRing()
  {
    return InRing;
  }
    
  public void setInRing(Integer InRing)
  {
    this.InRing = InRing;
  }
    
  public Integer getRadiate()
  {
    return Radiate;
  }
    
  public void setRadiate(Integer Radiate)
  {
    this.Radiate = Radiate;
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
    return "TransformerWinding ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Substation = " + Substation
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", iVoltageLevel = " + iVoltageLevel
	 + ", zVoltageLevel = " + zVoltageLevel
	 + ", PowerTransformer = " + PowerTransformer
	 + ", iTapchanger = " + iTapchanger
	 + ", zTapchanger = " + zTapchanger
	 + ", ConnectivityNodeI = " + ConnectivityNodeI
	 + ", ConnectivityNodeJ = " + ConnectivityNodeJ
	 + ", RatedMva = " + RatedMva
	 + ", iRatedkV = " + iRatedkV
	 + ", zRatedkV = " + zRatedkV
	 + ", R = " + R
	 + ", X = " + X
	 + ", G = " + G
	 + ", B = " + B
	 + ", R0 = " + R0
	 + ", X0 = " + X0
	 + ", iTap = " + iTap
	 + ", zTap = " + zTap
	 + ", TranStatus = " + TranStatus
	 + ", NeutralStatus = " + NeutralStatus
	 + ", WindingType = " + WindingType
	 + ", WindingAVR = " + WindingAVR
	 + ", CoupledTran = " + CoupledTran
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ri_Direction = " + ri_Direction
	 + ", ei_Invest = " + ei_Invest
	 + ", vd_RScc1 = " + vd_RScc1
	 + ", vd_RScc2 = " + vd_RScc2
	 + ", vd_RScc3 = " + vd_RScc3
	 + ", vd_RScc4 = " + vd_RScc4
	 + ", RATunning = " + RATunning
	 + ", RADelay = " + RADelay
	 + ", RAPlate = " + RAPlate
	 + ", RUTunning = " + RUTunning
	 + ", RUDelay = " + RUDelay
	 + ", RUPlate = " + RUPlate
	 + ", MCRTypeI = " + MCRTypeI
	 + ", MCRTypeJ = " + MCRTypeJ
	 + ", MCRPower = " + MCRPower
	 + ", Pi = " + Pi
	 + ", Qi = " + Qi
	 + ", Ai = " + Ai
	 + ", Pz = " + Pz
	 + ", Qz = " + Qz
	 + ", Az = " + Az
	 + ", LossP = " + LossP
	 + ", LossQ = " + LossQ
	 + ", ScIaI = " + ScIaI
	 + ", ScIbI = " + ScIbI
	 + ", ScIcI = " + ScIcI
	 + ", ScI1I = " + ScI1I
	 + ", ScI2I = " + ScI2I
	 + ", ScI0I = " + ScI0I
	 + ", ScIaJ = " + ScIaJ
	 + ", ScIbJ = " + ScIbJ
	 + ", ScIcJ = " + ScIcJ
	 + ", ScI1J = " + ScI1J
	 + ", ScI2J = " + ScI2J
	 + ", ScI0J = " + ScI0J
	 + ", ro_RContribution = " + ro_RContribution
	 + ", ro_UContribution = " + ro_UContribution
	 + ", ro_EnsContribution = " + ro_EnsContribution
	 + ", sa_Result = " + sa_Result
	 + ", sa_Island = " + sa_Island
	 + ", sa_Failure = " + sa_Failure
	 + ", sa_ShiftNode = " + sa_ShiftNode
	 + ", TranPtr = " + TranPtr
	 + ", VoltIPtr = " + VoltIPtr
	 + ", VoltJPtr = " + VoltJPtr
	 + ", TapChangerIPtr = " + TapChangerIPtr
	 + ", TapChangerJPtr = " + TapChangerJPtr
	 + ", NodeIPtr = " + NodeIPtr
	 + ", NodeJPtr = " + NodeJPtr
	 + ", TopoBusI = " + TopoBusI
	 + ", TopoBusJ = " + TopoBusJ
	 + ", Island = " + Island
	 + ", EdgeI = " + EdgeI
	 + ", EdgeJ = " + EdgeJ
	 + ", TranMidSide = " + TranMidSide
	 + ", Distribution = " + Distribution
	 + ", State = " + State
	 + ", InRing = " + InRing
	 + ", Radiate = " + Radiate
	 + ", Open = " + Open
	 + ", Outage = " + Outage+"]";
  }
    
}
    
