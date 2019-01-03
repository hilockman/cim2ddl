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
  
  //线路悬空
  private Integer Vacant;
  
  //架空/电缆
  private Integer LineType;
  
  //线路型号
  private String LineModel;
  
  //自动计算长度
  private Integer AutoLength;
  
  //线路长度(千米)
  private Double Length;
  
  //电流限值(安)
  private Double RatedCur;
  
  //功率限值(兆伏安)
  private Double RatedMva;
  
  //单位电阻(欧姆)
  private Double UnitR;
  
  //单位电抗(欧姆)
  private Double UnitX;
  
  //单位电导(西门子)
  private Double UnitG;
  
  //单位电纳(西门子)
  private Double UnitB;
  
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
  
  //零序电纳(标幺)
  private Double B0;
  
  //起状态
  private Integer iStatus;
  
  //终状态
  private Integer zStatus;
  
  //单位故障率(次/千米.年)
  private Double ri_UnitRerr;
  
  //单位修复时间(小时/次)
  private Double ri_UnitTrep;
  
  //单位计划检修率(次/千米.年)
  private Double ri_UnitRchk;
  
  //单位检修时间(小时/次)
  private Double ri_UnitTchk;
  
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
  
  //转电时间(小时/次)
  private Double ri_TSwitch;
  
  //操作延时(小时/次)
  private Double ri_Tdelay;
  
  //用户数
  private Double ri_Customer;
  
  //供电方向
  private Integer ri_Direction;
  
  //单位投资费用(万元/千米)
  private Double ei_UnitInvest;
  
  //投资费用(万元)
  private Double ei_Invest;
  
  //每次固定停电损失(万元/次)
  private Double ei_ConstLoss;
  
  //单位电能停电损失
  private Double ei_EvalRatio;
  
  //负荷所接线路侧
  private Integer LoadSide;
  
  //线路负荷功率(兆瓦)
  private Double LineLoadP;
  
  //线路负荷功率因数
  private Double LineLoadFactor;
  
  //线上无功补偿容量(兆乏)
  private Double LineCap;
  
  //线上串联补偿(标幺)
  private Double SeriesCap;
  
  //线路热负荷功率(兆瓦)
  private Double HeatingLoad;
  
  //线路冷负荷功率(兆瓦)
  private Double RefrigerationLoad;
  
  //配出负荷故障率(次/年)
  private Double ri_Load_Rerr;
  
  //配出负荷修复时间(小时/次)
  private Double ri_Load_Trep;
  
  //配出负荷计划检修率(次/年)
  private Double ri_Load_Rchk;
  
  //配出负荷检修时间(小时/次)
  private Double ri_Load_Tchk;
  
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
  
  //主接线可靠性设备类型
  private Integer MCRType;
  
  //主接线可靠性源/荷功率
  private Double MCRPower;
  
  //起点有功(兆瓦)
  private Double Pi;
  
  //起点无功(兆乏)
  private Double Qi;
  
  //终点有功(兆瓦)
  private Double Pj;
  
  //终点无功(兆乏)
  private Double Qj;
  
  //电流(安培)
  private Double A;
  
  //损耗有功(兆瓦)
  private Double LossP;
  
  //损耗无功(兆乏)
  private Double LossQ;
  
  //A相短路电流(安培)
  private Double ScIa;
  
  //B相短路电流(安培)
  private Double ScIb;
  
  //C相短路电流(安培)
  private Double ScIc;
  
  //正序短路电流(安培)
  private Double ScI1;
  
  //负序短路电流(安培)
  private Double ScI2;
  
  //零序短路电流(安培)
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
  
  //N-1负荷损失(兆伏安)
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
  
  //分支/主干
  private Integer TrunkLine;
  
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
    
  public Integer getVacant()
  {
    return Vacant;
  }
    
  public void setVacant(Integer Vacant)
  {
    this.Vacant = Vacant;
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
    
  public Integer getAutoLength()
  {
    return AutoLength;
  }
    
  public void setAutoLength(Integer AutoLength)
  {
    this.AutoLength = AutoLength;
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
    
  public Double getUnitR()
  {
    return UnitR;
  }
    
  public void setUnitR(Double UnitR)
  {
    this.UnitR = UnitR;
  }
    
  public Double getUnitX()
  {
    return UnitX;
  }
    
  public void setUnitX(Double UnitX)
  {
    this.UnitX = UnitX;
  }
    
  public Double getUnitG()
  {
    return UnitG;
  }
    
  public void setUnitG(Double UnitG)
  {
    this.UnitG = UnitG;
  }
    
  public Double getUnitB()
  {
    return UnitB;
  }
    
  public void setUnitB(Double UnitB)
  {
    this.UnitB = UnitB;
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
    
  public Integer getiStatus()
  {
    return iStatus;
  }
    
  public void setiStatus(Integer iStatus)
  {
    this.iStatus = iStatus;
  }
    
  public Integer getzStatus()
  {
    return zStatus;
  }
    
  public void setzStatus(Integer zStatus)
  {
    this.zStatus = zStatus;
  }
    
  public Double getri_UnitRerr()
  {
    return ri_UnitRerr;
  }
    
  public void setri_UnitRerr(Double ri_UnitRerr)
  {
    this.ri_UnitRerr = ri_UnitRerr;
  }
    
  public Double getri_UnitTrep()
  {
    return ri_UnitTrep;
  }
    
  public void setri_UnitTrep(Double ri_UnitTrep)
  {
    this.ri_UnitTrep = ri_UnitTrep;
  }
    
  public Double getri_UnitRchk()
  {
    return ri_UnitRchk;
  }
    
  public void setri_UnitRchk(Double ri_UnitRchk)
  {
    this.ri_UnitRchk = ri_UnitRchk;
  }
    
  public Double getri_UnitTchk()
  {
    return ri_UnitTchk;
  }
    
  public void setri_UnitTchk(Double ri_UnitTchk)
  {
    this.ri_UnitTchk = ri_UnitTchk;
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
    
  public Integer getri_Direction()
  {
    return ri_Direction;
  }
    
  public void setri_Direction(Integer ri_Direction)
  {
    this.ri_Direction = ri_Direction;
  }
    
  public Double getei_UnitInvest()
  {
    return ei_UnitInvest;
  }
    
  public void setei_UnitInvest(Double ei_UnitInvest)
  {
    this.ei_UnitInvest = ei_UnitInvest;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Double getei_ConstLoss()
  {
    return ei_ConstLoss;
  }
    
  public void setei_ConstLoss(Double ei_ConstLoss)
  {
    this.ei_ConstLoss = ei_ConstLoss;
  }
    
  public Double getei_EvalRatio()
  {
    return ei_EvalRatio;
  }
    
  public void setei_EvalRatio(Double ei_EvalRatio)
  {
    this.ei_EvalRatio = ei_EvalRatio;
  }
    
  public Integer getLoadSide()
  {
    return LoadSide;
  }
    
  public void setLoadSide(Integer LoadSide)
  {
    this.LoadSide = LoadSide;
  }
    
  public Double getLineLoadP()
  {
    return LineLoadP;
  }
    
  public void setLineLoadP(Double LineLoadP)
  {
    this.LineLoadP = LineLoadP;
  }
    
  public Double getLineLoadFactor()
  {
    return LineLoadFactor;
  }
    
  public void setLineLoadFactor(Double LineLoadFactor)
  {
    this.LineLoadFactor = LineLoadFactor;
  }
    
  public Double getLineCap()
  {
    return LineCap;
  }
    
  public void setLineCap(Double LineCap)
  {
    this.LineCap = LineCap;
  }
    
  public Double getSeriesCap()
  {
    return SeriesCap;
  }
    
  public void setSeriesCap(Double SeriesCap)
  {
    this.SeriesCap = SeriesCap;
  }
    
  public Double getHeatingLoad()
  {
    return HeatingLoad;
  }
    
  public void setHeatingLoad(Double HeatingLoad)
  {
    this.HeatingLoad = HeatingLoad;
  }
    
  public Double getRefrigerationLoad()
  {
    return RefrigerationLoad;
  }
    
  public void setRefrigerationLoad(Double RefrigerationLoad)
  {
    this.RefrigerationLoad = RefrigerationLoad;
  }
    
  public Double getri_Load_Rerr()
  {
    return ri_Load_Rerr;
  }
    
  public void setri_Load_Rerr(Double ri_Load_Rerr)
  {
    this.ri_Load_Rerr = ri_Load_Rerr;
  }
    
  public Double getri_Load_Trep()
  {
    return ri_Load_Trep;
  }
    
  public void setri_Load_Trep(Double ri_Load_Trep)
  {
    this.ri_Load_Trep = ri_Load_Trep;
  }
    
  public Double getri_Load_Rchk()
  {
    return ri_Load_Rchk;
  }
    
  public void setri_Load_Rchk(Double ri_Load_Rchk)
  {
    this.ri_Load_Rchk = ri_Load_Rchk;
  }
    
  public Double getri_Load_Tchk()
  {
    return ri_Load_Tchk;
  }
    
  public void setri_Load_Tchk(Double ri_Load_Tchk)
  {
    this.ri_Load_Tchk = ri_Load_Tchk;
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
    
  public Integer getTrunkLine()
  {
    return TrunkLine;
  }
    
  public void setTrunkLine(Integer TrunkLine)
  {
    this.TrunkLine = TrunkLine;
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
	 + ", Vacant = " + Vacant
	 + ", LineType = " + LineType
	 + ", LineModel = " + LineModel
	 + ", AutoLength = " + AutoLength
	 + ", Length = " + Length
	 + ", RatedCur = " + RatedCur
	 + ", RatedMva = " + RatedMva
	 + ", UnitR = " + UnitR
	 + ", UnitX = " + UnitX
	 + ", UnitG = " + UnitG
	 + ", UnitB = " + UnitB
	 + ", R = " + R
	 + ", X = " + X
	 + ", G = " + G
	 + ", B = " + B
	 + ", R0 = " + R0
	 + ", X0 = " + X0
	 + ", B0 = " + B0
	 + ", iStatus = " + iStatus
	 + ", zStatus = " + zStatus
	 + ", ri_UnitRerr = " + ri_UnitRerr
	 + ", ri_UnitTrep = " + ri_UnitTrep
	 + ", ri_UnitRchk = " + ri_UnitRchk
	 + ", ri_UnitTchk = " + ri_UnitTchk
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ri_TSwitch = " + ri_TSwitch
	 + ", ri_Tdelay = " + ri_Tdelay
	 + ", ri_Customer = " + ri_Customer
	 + ", ri_Direction = " + ri_Direction
	 + ", ei_UnitInvest = " + ei_UnitInvest
	 + ", ei_Invest = " + ei_Invest
	 + ", ei_ConstLoss = " + ei_ConstLoss
	 + ", ei_EvalRatio = " + ei_EvalRatio
	 + ", LoadSide = " + LoadSide
	 + ", LineLoadP = " + LineLoadP
	 + ", LineLoadFactor = " + LineLoadFactor
	 + ", LineCap = " + LineCap
	 + ", SeriesCap = " + SeriesCap
	 + ", HeatingLoad = " + HeatingLoad
	 + ", RefrigerationLoad = " + RefrigerationLoad
	 + ", ri_Load_Rerr = " + ri_Load_Rerr
	 + ", ri_Load_Trep = " + ri_Load_Trep
	 + ", ri_Load_Rchk = " + ri_Load_Rchk
	 + ", ri_Load_Tchk = " + ri_Load_Tchk
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
	 + ", TrunkLine = " + TrunkLine
	 + ", Open = " + Open
	 + ", Outage = " + Outage+"]";
  }
    
}
    
