package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*交流线路段	*
***********************/
public class ACLineSegment  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //ObjectId
  private String ObjectID;
  
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
  
  //起节点
  private String ConnectivityNodeI;
  
  //终节点
  private String ConnectivityNodeJ;
  
  //架空/电缆
  private Integer LineType;
  
  //线路型号
  private String LineModel;
  
  //线路长度(KM)
  private Double Length;
  
  //电流限值(A)
  private Double RatedCur;
  
  //功率限值(MVA)
  private Double RatedMva;
  
  //电阻(PU)
  private Double R;
  
  //电抗(PU)
  private Double X;
  
  //电导(PU)
  private Double G;
  
  //电纳(PU)
  private Double B;
  
  //零序电阻(PU)
  private Double R0;
  
  //零序电抗(PU)
  private Double X0;
  
  //零序电纳(PU)
  private Double B0;
  
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
  
  //切换成功率(≦1)
  private Double ri_RSwitch;
  
  //切换时间(小时/次)
  private Double ri_TSwitch;
  
  //操作延时(小时/次)
  private Double ri_Tdelay;
  
  //用户数
  private Double ri_Customer;
  
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
  
  //低压自动保护整定(PU)
  private Double RATunning;
  
  //低压自动保护时限(周)
  private Double RADelay;
  
  //低压自动保护压板
  private Integer RAPlate;
  
  //低周自动保护整定(Hz)
  private Double RUTunning;
  
  //低周自动保护时限(周)
  private Double RUDelay;
  
  //低周自动保护压板
  private Integer RUPlate;
  
  //主接线可靠性设备类型
  private Integer MCRType;
  
  //主接线可靠性源/荷功率
  private Double MCRPower;
  
  //起点有功(MW)
  private Double Pi;
  
  //起点无功(MVar)
  private Double Qi;
  
  //终点有功(MW)
  private Double Pj;
  
  //终点无功(MVar)
  private Double Qj;
  
  //电流(安培)
  private Double A;
  
  //损耗有功(MW)
  private Double LossP;
  
  //损耗无功(MVar)
  private Double LossQ;
  
  //A相短路电流(A)
  private Double ScIa;
  
  //B相短路电流(A)
  private Double ScIb;
  
  //C相短路电流(A)
  private Double ScIc;
  
  //正序短路电流(A)
  private Double ScI1;
  
  //负序短路电流(A)
  private Double ScI2;
  
  //零序短路电流(A)
  private Double ScI0;
  
  //停运率贡献(%)
  private Double ro_RContribution;
  
  //停运时间贡献(%)
  private Double ro_UContribution;
  
  //停电电量贡献(%)
  private Double ro_ENSContribution;
  
  //N-1通过情况
  private Integer sa_Result;
  
  //N-1形成孤岛
  private Integer sa_Island;
  
  //N-1负荷损失(MVA)
  private Double sa_Failure;
  
  //N-1转电节点
  private Integer sa_ShiftNode;
  
  //起拓扑节点
  private Integer TopoBusI;
  
  //终拓扑节点
  private Integer TopoBusJ;
  
  //岛
  private Integer Island;
  
  //所属线路索引
  private Integer LinePtr;
  
  //起节点索引
  private Integer NodeIPtr;
  
  //终节点索引
  private Integer NodeJPtr;
  
  //起边线路索引
  private Integer EdgeI;
  
  //终边线路索引
  private Integer EdgeJ;
  
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
  
  //供电方向
  private Integer Direction;
  
  //分支/主干
  private Integer TrunkLine;
  
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
    
  public Integer getLineType()
  {
    return LineType;
  }
    
  public void setLineType(Integer LineType)
  {
    this.LineType = LineType;
  }
    
  public String getLineModel()
  {
    return LineModel;
  }
    
  public void setLineModel(String LineModel)
  {
    this.LineModel = LineModel;
  }
    
  public Double getLength()
  {
    return Length;
  }
    
  public void setLength(Double Length)
  {
    this.Length = Length;
  }
    
  public Double getRatedCur()
  {
    return RatedCur;
  }
    
  public void setRatedCur(Double RatedCur)
  {
    this.RatedCur = RatedCur;
  }
    
  public Double getRatedMva()
  {
    return RatedMva;
  }
    
  public void setRatedMva(Double RatedMva)
  {
    this.RatedMva = RatedMva;
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
    
  public Double getB0()
  {
    return B0;
  }
    
  public void setB0(Double B0)
  {
    this.B0 = B0;
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
    
  public Double getri_RSwitch()
  {
    return ri_RSwitch;
  }
    
  public void setri_RSwitch(Double ri_RSwitch)
  {
    this.ri_RSwitch = ri_RSwitch;
  }
    
  public Double getri_TSwitch()
  {
    return ri_TSwitch;
  }
    
  public void setri_TSwitch(Double ri_TSwitch)
  {
    this.ri_TSwitch = ri_TSwitch;
  }
    
  public Double getri_Tdelay()
  {
    return ri_Tdelay;
  }
    
  public void setri_Tdelay(Double ri_Tdelay)
  {
    this.ri_Tdelay = ri_Tdelay;
  }
    
  public Double getri_Customer()
  {
    return ri_Customer;
  }
    
  public void setri_Customer(Double ri_Customer)
  {
    this.ri_Customer = ri_Customer;
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
    
  public Double getQi()
  {
    return Qi;
  }
    
  public void setQi(Double Qi)
  {
    this.Qi = Qi;
  }
    
  public Double getPj()
  {
    return Pj;
  }
    
  public void setPj(Double Pj)
  {
    this.Pj = Pj;
  }
    
  public Double getQj()
  {
    return Qj;
  }
    
  public void setQj(Double Qj)
  {
    this.Qj = Qj;
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
    
  public Double getLossQ()
  {
    return LossQ;
  }
    
  public void setLossQ(Double LossQ)
  {
    this.LossQ = LossQ;
  }
    
  public Double getScIa()
  {
    return ScIa;
  }
    
  public void setScIa(Double ScIa)
  {
    this.ScIa = ScIa;
  }
    
  public Double getScIb()
  {
    return ScIb;
  }
    
  public void setScIb(Double ScIb)
  {
    this.ScIb = ScIb;
  }
    
  public Double getScIc()
  {
    return ScIc;
  }
    
  public void setScIc(Double ScIc)
  {
    this.ScIc = ScIc;
  }
    
  public Double getScI1()
  {
    return ScI1;
  }
    
  public void setScI1(Double ScI1)
  {
    this.ScI1 = ScI1;
  }
    
  public Double getScI2()
  {
    return ScI2;
  }
    
  public void setScI2(Double ScI2)
  {
    this.ScI2 = ScI2;
  }
    
  public Double getScI0()
  {
    return ScI0;
  }
    
  public void setScI0(Double ScI0)
  {
    this.ScI0 = ScI0;
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
    
  public Double getro_ENSContribution()
  {
    return ro_ENSContribution;
  }
    
  public void setro_ENSContribution(Double ro_ENSContribution)
  {
    this.ro_ENSContribution = ro_ENSContribution;
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
    
  public Integer getDirection()
  {
    return Direction;
  }
    
  public void setDirection(Integer Direction)
  {
    this.Direction = Direction;
  }
    
  public Integer getTrunkLine()
  {
    return TrunkLine;
  }
    
  public void setTrunkLine(Integer TrunkLine)
  {
    this.TrunkLine = TrunkLine;
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
    return "ACLineSegment ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", iSubstation = " + iSubstation
	 + ", zSubstation = " + zSubstation
	 + ", iVoltageLevel = " + iVoltageLevel
	 + ", zVoltageLevel = " + zVoltageLevel
	 + ", Line = " + Line
	 + ", ConnectivityNodeI = " + ConnectivityNodeI
	 + ", ConnectivityNodeJ = " + ConnectivityNodeJ
	 + ", LineType = " + LineType
	 + ", LineModel = " + LineModel
	 + ", Length = " + Length
	 + ", RatedCur = " + RatedCur
	 + ", RatedMva = " + RatedMva
	 + ", R = " + R
	 + ", X = " + X
	 + ", G = " + G
	 + ", B = " + B
	 + ", R0 = " + R0
	 + ", X0 = " + X0
	 + ", B0 = " + B0
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ri_RSwitch = " + ri_RSwitch
	 + ", ri_TSwitch = " + ri_TSwitch
	 + ", ri_Tdelay = " + ri_Tdelay
	 + ", ri_Customer = " + ri_Customer
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
	 + ", MCRType = " + MCRType
	 + ", MCRPower = " + MCRPower
	 + ", Pi = " + Pi
	 + ", Qi = " + Qi
	 + ", Pj = " + Pj
	 + ", Qj = " + Qj
	 + ", A = " + A
	 + ", LossP = " + LossP
	 + ", LossQ = " + LossQ
	 + ", ScIa = " + ScIa
	 + ", ScIb = " + ScIb
	 + ", ScIc = " + ScIc
	 + ", ScI1 = " + ScI1
	 + ", ScI2 = " + ScI2
	 + ", ScI0 = " + ScI0
	 + ", ro_RContribution = " + ro_RContribution
	 + ", ro_UContribution = " + ro_UContribution
	 + ", ro_ENSContribution = " + ro_ENSContribution
	 + ", sa_Result = " + sa_Result
	 + ", sa_Island = " + sa_Island
	 + ", sa_Failure = " + sa_Failure
	 + ", sa_ShiftNode = " + sa_ShiftNode
	 + ", TopoBusI = " + TopoBusI
	 + ", TopoBusJ = " + TopoBusJ
	 + ", Island = " + Island
	 + ", LinePtr = " + LinePtr
	 + ", NodeIPtr = " + NodeIPtr
	 + ", NodeJPtr = " + NodeJPtr
	 + ", EdgeI = " + EdgeI
	 + ", EdgeJ = " + EdgeJ
	 + ", Distribution = " + Distribution
	 + ", State = " + State
	 + ", InRing = " + InRing
	 + ", Radiate = " + Radiate
	 + ", Open = " + Open
	 + ", Direction = " + Direction
	 + ", TrunkLine = " + TrunkLine
	 + ", Outage = " + Outage+"]";
  }
    
}
    
