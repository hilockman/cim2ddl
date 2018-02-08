package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*主干线	*
***********************/
public class TrunkSegment  implements MemIndexable 
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
  
  //电压等级
  private String VoltageLevel;
  
  //接线模式
  private Integer ConnectMode;
  
  //所属线路(馈线)
  private String Line;
  
  //架空/电缆
  private Integer LineType;
  
  //线路型号
  private String LineModel;
  
  //自动计算长度
  private Integer AutoLength;
  
  //线路长度(KM)
  private Double Length;
  
  //杆塔/电缆头总数
  private Integer TowerNum;
  
  //起状态
  private Integer iStatus;
  
  //终状态
  private Integer zStatus;
  
  //负荷所接线路侧
  private Integer LoadSide;
  
  //线路负荷功率(MW)
  private Double LineLoadP;
  
  //线路负荷功率因数
  private Double LineLoadFactor;
  
  //线上无功补偿容量(MVar)
  private Double LineCap;
  
  //线上串联补偿(PU)
  private Double SeriesCap;
  
  //线路热负荷功率(MW)
  private Double HeatingLoad;
  
  //线路冷负荷功率(MW)
  private Double RefrigerationLoad;
  
  //电流限值(A)
  private Double RateCur;
  
  //功率限值(MW)
  private Double RateMva;
  
  //单位电阻(欧姆)
  private Double UnitR;
  
  //单位电抗(欧姆)
  private Double UnitX;
  
  //单位电导(西门子)
  private Double UnitG;
  
  //单位电纳(西门子)
  private Double UnitB;
  
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
  
  //单位故障率(次/km.年)
  private Double ri_UnitRerr;
  
  //单位修复时间(小时/次)
  private Double ri_UnitTrep;
  
  //单位计划检修率(次/km.年)
  private Double ri_UnitRchk;
  
  //单位检修时间(小时/次)
  private Double ri_UnitTchk;
  
  //单位投资费用(万元/km)
  private Double ei_UnitInvest;
  
  //故障率(次/年)
  private Double ri_Rerr;
  
  //修复时间(时间/次)
  private Double ri_Trep;
  
  //计划检修率(次/年)
  private Double ri_Rchk;
  
  //检修时间(时间/次)
  private Double ri_Tchk;
  
  //故障定位隔离时间(时间/km)
  private Double ri_Tfloc;
  
  //等效操作成功率
  private Double ri_RSwitch;
  
  //等效操作时间(时间/次)
  private Double ri_TSwitch;
  
  //等效延时时间
  private Double ri_TDelay;
  
  //用户数
  private Double ri_Customer;
  
  //配出负荷故障率(次/年)
  private Double ri_Load_Rerr;
  
  //配出负荷修复时间(小时/次)
  private Double ri_Load_Trep;
  
  //配出负荷计划检修率(次/年)
  private Double ri_Load_Rchk;
  
  //配出负荷检修时间(小时/次)
  private Double ri_Load_Tchk;
  
  //投资费用(万元)
  private Double ei_Invest;
  
  //每次固定停电损失(万元/次)
  private Double ei_ConstLoss;
  
  //单位电能停电损失
  private Double ei_EvalRatio;
  
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
  
  //起节点
  private String ConnectivityNodeI;
  
  //终节点
  private String ConnectivityNodeJ;
  
  //起点有功(MW)
  private Double Pi;
  
  //起点无功(MVar)
  private Double Qi;
  
  //起点电流(安培)
  private Double Ai;
  
  //终点有功(MW)
  private Double Pz;
  
  //终点无功(MVar)
  private Double Qz;
  
  //终点电流(安培)
  private Double Az;
  
  //损耗有功(MW)
  private Double LossP;
  
  //损耗无功(MVar)
  private Double LossQ;
  
  //年均停电电量(MWh/年)
  private Double ro_Ens;
  
  //停电综合损失(万元)
  private Double eo_Loss;
  
  //I侧N-1通过情况
  private Integer sa_ResultI;
  
  //I侧N-1形成孤岛
  private Integer sa_IslandI;
  
  //I侧N-1负荷损失(MVA)
  private Double sa_FailureI;
  
  //I侧N-1转电节点
  private Integer sa_ShiftNodeI;
  
  //Z侧N-1通过情况
  private Integer sa_ResultZ;
  
  //Z侧N-1形成孤岛
  private Integer sa_IslandZ;
  
  //Z侧N-1负荷损失(MVA)
  private Double sa_FailureZ;
  
  //Z侧N-1转电节点
  private Integer sa_ShiftNodeZ;
  
  //起节点索引
  private Integer NodeIPtr;
  
  //终节点索引
  private Integer NodeJPtr;
  
  //供电方向
  private Integer Direction;
  
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
    
  public String getVoltageLevel()
  {
    return VoltageLevel;
  }
    
  public void setVoltageLevel(String VoltageLevel)
  {
    this.VoltageLevel = VoltageLevel;
  }
    
  public Integer getConnectMode()
  {
    return ConnectMode;
  }
    
  public void setConnectMode(Integer ConnectMode)
  {
    this.ConnectMode = ConnectMode;
  }
    
  public String getLine()
  {
    return Line;
  }
    
  public void setLine(String Line)
  {
    this.Line = Line;
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
    
  public Integer getTowerNum()
  {
    return TowerNum;
  }
    
  public void setTowerNum(Integer TowerNum)
  {
    this.TowerNum = TowerNum;
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
    
  public Double getRateCur()
  {
    return RateCur;
  }
    
  public void setRateCur(Double RateCur)
  {
    this.RateCur = RateCur;
  }
    
  public Double getRateMva()
  {
    return RateMva;
  }
    
  public void setRateMva(Double RateMva)
  {
    this.RateMva = RateMva;
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
    
  public Double getei_UnitInvest()
  {
    return ei_UnitInvest;
  }
    
  public void setei_UnitInvest(Double ei_UnitInvest)
  {
    this.ei_UnitInvest = ei_UnitInvest;
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
    
  public Double getri_TDelay()
  {
    return ri_TDelay;
  }
    
  public void setri_TDelay(Double ri_TDelay)
  {
    this.ri_TDelay = ri_TDelay;
  }
    
  public Double getri_Customer()
  {
    return ri_Customer;
  }
    
  public void setri_Customer(Double ri_Customer)
  {
    this.ri_Customer = ri_Customer;
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
    
  public Double getro_Ens()
  {
    return ro_Ens;
  }
    
  public void setro_Ens(Double ro_Ens)
  {
    this.ro_Ens = ro_Ens;
  }
    
  public Double geteo_Loss()
  {
    return eo_Loss;
  }
    
  public void seteo_Loss(Double eo_Loss)
  {
    this.eo_Loss = eo_Loss;
  }
    
  public Integer getsa_ResultI()
  {
    return sa_ResultI;
  }
    
  public void setsa_ResultI(Integer sa_ResultI)
  {
    this.sa_ResultI = sa_ResultI;
  }
    
  public Integer getsa_IslandI()
  {
    return sa_IslandI;
  }
    
  public void setsa_IslandI(Integer sa_IslandI)
  {
    this.sa_IslandI = sa_IslandI;
  }
    
  public Double getsa_FailureI()
  {
    return sa_FailureI;
  }
    
  public void setsa_FailureI(Double sa_FailureI)
  {
    this.sa_FailureI = sa_FailureI;
  }
    
  public Integer getsa_ShiftNodeI()
  {
    return sa_ShiftNodeI;
  }
    
  public void setsa_ShiftNodeI(Integer sa_ShiftNodeI)
  {
    this.sa_ShiftNodeI = sa_ShiftNodeI;
  }
    
  public Integer getsa_ResultZ()
  {
    return sa_ResultZ;
  }
    
  public void setsa_ResultZ(Integer sa_ResultZ)
  {
    this.sa_ResultZ = sa_ResultZ;
  }
    
  public Integer getsa_IslandZ()
  {
    return sa_IslandZ;
  }
    
  public void setsa_IslandZ(Integer sa_IslandZ)
  {
    this.sa_IslandZ = sa_IslandZ;
  }
    
  public Double getsa_FailureZ()
  {
    return sa_FailureZ;
  }
    
  public void setsa_FailureZ(Double sa_FailureZ)
  {
    this.sa_FailureZ = sa_FailureZ;
  }
    
  public Integer getsa_ShiftNodeZ()
  {
    return sa_ShiftNodeZ;
  }
    
  public void setsa_ShiftNodeZ(Integer sa_ShiftNodeZ)
  {
    this.sa_ShiftNodeZ = sa_ShiftNodeZ;
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
    
  public Integer getDirection()
  {
    return Direction;
  }
    
  public void setDirection(Integer Direction)
  {
    this.Direction = Direction;
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
    return "TrunkSegment ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", iSubstation = " + iSubstation
	 + ", zSubstation = " + zSubstation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", ConnectMode = " + ConnectMode
	 + ", Line = " + Line
	 + ", LineType = " + LineType
	 + ", LineModel = " + LineModel
	 + ", AutoLength = " + AutoLength
	 + ", Length = " + Length
	 + ", TowerNum = " + TowerNum
	 + ", iStatus = " + iStatus
	 + ", zStatus = " + zStatus
	 + ", LoadSide = " + LoadSide
	 + ", LineLoadP = " + LineLoadP
	 + ", LineLoadFactor = " + LineLoadFactor
	 + ", LineCap = " + LineCap
	 + ", SeriesCap = " + SeriesCap
	 + ", HeatingLoad = " + HeatingLoad
	 + ", RefrigerationLoad = " + RefrigerationLoad
	 + ", RateCur = " + RateCur
	 + ", RateMva = " + RateMva
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
	 + ", ri_UnitRerr = " + ri_UnitRerr
	 + ", ri_UnitTrep = " + ri_UnitTrep
	 + ", ri_UnitRchk = " + ri_UnitRchk
	 + ", ri_UnitTchk = " + ri_UnitTchk
	 + ", ei_UnitInvest = " + ei_UnitInvest
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ri_RSwitch = " + ri_RSwitch
	 + ", ri_TSwitch = " + ri_TSwitch
	 + ", ri_TDelay = " + ri_TDelay
	 + ", ri_Customer = " + ri_Customer
	 + ", ri_Load_Rerr = " + ri_Load_Rerr
	 + ", ri_Load_Trep = " + ri_Load_Trep
	 + ", ri_Load_Rchk = " + ri_Load_Rchk
	 + ", ri_Load_Tchk = " + ri_Load_Tchk
	 + ", ei_Invest = " + ei_Invest
	 + ", ei_ConstLoss = " + ei_ConstLoss
	 + ", ei_EvalRatio = " + ei_EvalRatio
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
	 + ", ConnectivityNodeI = " + ConnectivityNodeI
	 + ", ConnectivityNodeJ = " + ConnectivityNodeJ
	 + ", Pi = " + Pi
	 + ", Qi = " + Qi
	 + ", Ai = " + Ai
	 + ", Pz = " + Pz
	 + ", Qz = " + Qz
	 + ", Az = " + Az
	 + ", LossP = " + LossP
	 + ", LossQ = " + LossQ
	 + ", ro_Ens = " + ro_Ens
	 + ", eo_Loss = " + eo_Loss
	 + ", sa_ResultI = " + sa_ResultI
	 + ", sa_IslandI = " + sa_IslandI
	 + ", sa_FailureI = " + sa_FailureI
	 + ", sa_ShiftNodeI = " + sa_ShiftNodeI
	 + ", sa_ResultZ = " + sa_ResultZ
	 + ", sa_IslandZ = " + sa_IslandZ
	 + ", sa_FailureZ = " + sa_FailureZ
	 + ", sa_ShiftNodeZ = " + sa_ShiftNodeZ
	 + ", NodeIPtr = " + NodeIPtr
	 + ", NodeJPtr = " + NodeJPtr
	 + ", Direction = " + Direction
	 + ", Open = " + Open+"]";
  }
    
}
    
