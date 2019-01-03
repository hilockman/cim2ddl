package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*分支线	*
***********************/
public class BranchSegment  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //名称
  private String Name;
  
  //所属线路
  private String ACLineSegment;
  
  //所接线路侧
  private String SubstationSide;
  
  //接入杆塔/电缆头编号
  private Integer TowerID;
  
  //电压等级
  private String VoltageLevel;
  
  //架空/电缆
  private Integer LineType;
  
  //线路型号
  private String LineModel;
  
  //线路长度(千米)
  private Double Length;
  
  //状态
  private Integer Status;
  
  //线路负荷功率(兆瓦)
  private Double LoadP;
  
  //线路负荷功率因数
  private Double LoadFactor;
  
  //线上无功补偿容量(兆乏)
  private Double LoadCap;
  
  //线路热负荷功率(兆瓦)
  private Double HeatingLoad;
  
  //线路冷负荷功率(兆瓦)
  private Double RefrigerationLoad;
  
  //电流限值(安)
  private Double RatedCur;
  
  //功率限值(兆瓦)
  private Double RatedMva;
  
  //单位电阻(欧姆)
  private Double UnitR;
  
  //单位电抗(欧姆)
  private Double UnitX;
  
  //单位电导(西门子)
  private Double UnitG;
  
  //单位电纳(西门子)
  private Double UnitB;
  
  //单位故障率(次/千米.年)
  private Double ri_UnitRerr;
  
  //单位修复时间(小时/次)
  private Double ri_UnitTrep;
  
  //单位计划检修率(次/千米.年)
  private Double ri_UnitRchk;
  
  //单位检修时间(小时/次)
  private Double ri_UnitTchk;
  
  //单位投资费用(万元/千米)
  private Double ei_UnitInvest;
  
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
  
  //分支线故障率(次/年)
  private Double ri_Rerr;
  
  //分支线修复时间(时间/次)
  private Double ri_Trep;
  
  //分支线计划检修率(次/年)
  private Double ri_Rchk;
  
  //分支线检修时间(时间/次)
  private Double ri_Tchk;
  
  //分支线故障定位隔离时间
  private Double ri_Tfloc;
  
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
  
  //分支线出口开断设备
  private Integer BranchBreaking;
  
  //分支线出口开断设备类型
  private Integer BreakingType;
  
  //分支线出口开关故障率(次/年)
  private Double ri_sw_rerr;
  
  //分支线出口开关修复时间(时间/次)
  private Double ri_sw_trep;
  
  //分支线出口开关计划检修率(次/年)
  private Double ri_sw_rchk;
  
  //分支线出口开关检修时间(时间/次)
  private Double ri_sw_tchk;
  
  //分支线出口开关故障定位隔离时间
  private Double ri_sw_tfloc;
  
  //有功(兆瓦)
  private Double P;
  
  //无功(兆乏)
  private Double Q;
  
  //电流(安培)
  private Double A;
  
  //损耗有功(兆瓦)
  private Double LossP;
  
  //损耗无功(兆乏)
  private Double LossQ;
  
  //年均停电电量(兆瓦时/年)
  private Double ro_ens;
  
  //停电综合损失(万元)
  private Double eo_loss;
  
  //N-1通过情况
  private Integer sa_Result;
  
  //N-1形成孤岛
  private Integer sa_Island;
  
  //N-1负荷损失(兆伏安)
  private Double sa_Failure;
  
  //N-1转电节点
  private Integer sa_ShiftNode;
  
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
    
  public String getACLineSegment()
  {
    return ACLineSegment;
  }
    
  public void setACLineSegment(String ACLineSegment)
  {
    this.ACLineSegment = ACLineSegment;
  }
    
  public String getSubstationSide()
  {
    return SubstationSide;
  }
    
  public void setSubstationSide(String SubstationSide)
  {
    this.SubstationSide = SubstationSide;
  }
    
  public Integer getTowerID()
  {
    return TowerID;
  }
    
  public void setTowerID(Integer TowerID)
  {
    this.TowerID = TowerID;
  }
    
  public String getVoltageLevel()
  {
    return VoltageLevel;
  }
    
  public void setVoltageLevel(String VoltageLevel)
  {
    this.VoltageLevel = VoltageLevel;
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
    
  public Integer getStatus()
  {
    return Status;
  }
    
  public void setStatus(Integer Status)
  {
    this.Status = Status;
  }
    
  public Double getLoadP()
  {
    return LoadP;
  }
    
  public void setLoadP(Double LoadP)
  {
    this.LoadP = LoadP;
  }
    
  public Double getLoadFactor()
  {
    return LoadFactor;
  }
    
  public void setLoadFactor(Double LoadFactor)
  {
    this.LoadFactor = LoadFactor;
  }
    
  public Double getLoadCap()
  {
    return LoadCap;
  }
    
  public void setLoadCap(Double LoadCap)
  {
    this.LoadCap = LoadCap;
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
    
  public Integer getBranchBreaking()
  {
    return BranchBreaking;
  }
    
  public void setBranchBreaking(Integer BranchBreaking)
  {
    this.BranchBreaking = BranchBreaking;
  }
    
  public Integer getBreakingType()
  {
    return BreakingType;
  }
    
  public void setBreakingType(Integer BreakingType)
  {
    this.BreakingType = BreakingType;
  }
    
  public Double getri_sw_rerr()
  {
    return ri_sw_rerr;
  }
    
  public void setri_sw_rerr(Double ri_sw_rerr)
  {
    this.ri_sw_rerr = ri_sw_rerr;
  }
    
  public Double getri_sw_trep()
  {
    return ri_sw_trep;
  }
    
  public void setri_sw_trep(Double ri_sw_trep)
  {
    this.ri_sw_trep = ri_sw_trep;
  }
    
  public Double getri_sw_rchk()
  {
    return ri_sw_rchk;
  }
    
  public void setri_sw_rchk(Double ri_sw_rchk)
  {
    this.ri_sw_rchk = ri_sw_rchk;
  }
    
  public Double getri_sw_tchk()
  {
    return ri_sw_tchk;
  }
    
  public void setri_sw_tchk(Double ri_sw_tchk)
  {
    this.ri_sw_tchk = ri_sw_tchk;
  }
    
  public Double getri_sw_tfloc()
  {
    return ri_sw_tfloc;
  }
    
  public void setri_sw_tfloc(Double ri_sw_tfloc)
  {
    this.ri_sw_tfloc = ri_sw_tfloc;
  }
    
  public Double getP()
  {
    return P;
  }
    
  public void setP(Double P)
  {
    this.P = P;
  }
    
  public Double getQ()
  {
    return Q;
  }
    
  public void setQ(Double Q)
  {
    this.Q = Q;
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
    
  public Double getro_ens()
  {
    return ro_ens;
  }
    
  public void setro_ens(Double ro_ens)
  {
    this.ro_ens = ro_ens;
  }
    
  public Double geteo_loss()
  {
    return eo_loss;
  }
    
  public void seteo_loss(Double eo_loss)
  {
    this.eo_loss = eo_loss;
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
    
  public String toString()
  {
    return "BranchSegment ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Name = " + Name
	 + ", ACLineSegment = " + ACLineSegment
	 + ", SubstationSide = " + SubstationSide
	 + ", TowerID = " + TowerID
	 + ", VoltageLevel = " + VoltageLevel
	 + ", LineType = " + LineType
	 + ", LineModel = " + LineModel
	 + ", Length = " + Length
	 + ", Status = " + Status
	 + ", LoadP = " + LoadP
	 + ", LoadFactor = " + LoadFactor
	 + ", LoadCap = " + LoadCap
	 + ", HeatingLoad = " + HeatingLoad
	 + ", RefrigerationLoad = " + RefrigerationLoad
	 + ", RatedCur = " + RatedCur
	 + ", RatedMva = " + RatedMva
	 + ", UnitR = " + UnitR
	 + ", UnitX = " + UnitX
	 + ", UnitG = " + UnitG
	 + ", UnitB = " + UnitB
	 + ", ri_UnitRerr = " + ri_UnitRerr
	 + ", ri_UnitTrep = " + ri_UnitTrep
	 + ", ri_UnitRchk = " + ri_UnitRchk
	 + ", ri_UnitTchk = " + ri_UnitTchk
	 + ", ei_UnitInvest = " + ei_UnitInvest
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
	 + ", BranchBreaking = " + BranchBreaking
	 + ", BreakingType = " + BreakingType
	 + ", ri_sw_rerr = " + ri_sw_rerr
	 + ", ri_sw_trep = " + ri_sw_trep
	 + ", ri_sw_rchk = " + ri_sw_rchk
	 + ", ri_sw_tchk = " + ri_sw_tchk
	 + ", ri_sw_tfloc = " + ri_sw_tfloc
	 + ", P = " + P
	 + ", Q = " + Q
	 + ", A = " + A
	 + ", LossP = " + LossP
	 + ", LossQ = " + LossQ
	 + ", ro_ens = " + ro_ens
	 + ", eo_loss = " + eo_loss
	 + ", sa_Result = " + sa_Result
	 + ", sa_Island = " + sa_Island
	 + ", sa_Failure = " + sa_Failure
	 + ", sa_ShiftNode = " + sa_ShiftNode+"]";
  }
    
}
    
