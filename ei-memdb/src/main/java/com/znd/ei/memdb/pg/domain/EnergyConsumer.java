package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*负荷	*
***********************/
public class EnergyConsumer  implements MemIndexable 
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
  
  //计划有功(兆瓦)
  private Double PlanP;
  
  //计划无功(兆乏)
  private Double PlanQ;
  
  //节点
  private String ConnectivityNode;
  
  //负荷零序电抗(标幺)
  private Double X0;
  
  //负荷用户数
  private Double ri_Customer;
  
  //负荷类型(显示图例)
  private Integer Type;
  
  //负荷容量(兆瓦)
  private Double Capacity;
  
  //马达容量(保护整定,千瓦)
  private Double MotorCapacity;
  
  //负荷静态模型
  private String LoadModel;
  
  //惯性时间常数(秒)
  private Double MotorEmws;
  
  //马达功率占母线功率的百分比(<1)
  private Double MotorPper;
  
  //马达负载率(<1)或初始滑差(0.001~0.2)
  private Double MotorKL;
  
  //马达定子电阻(标幺)
  private Double MotorRs;
  
  //马达定子电抗(标幺)
  private Double MotorXs;
  
  //马达激磁电抗(标幺)
  private Double MotorXm;
  
  //马达转子电阻(标幺)
  private Double MotorRr;
  
  //马达转子电抗(标幺)
  private Double MotorXr;
  
  //马达转矩方程常数A
  private Double MotorA;
  
  //马达转矩方程常数B
  private Double MotorB;
  
  //使用初始滑差
  private Integer MotorUseS0;
  
  //马达滑差=1的处理方式
  private Integer MotorIM;
  
  //低周减载频率(Hz)
  private Double AutoUF_Freq;
  
  //低周减载时间(周)
  private Double AutoUF_Delay;
  
  //低周减载压板
  private Integer AutoUF_Plate;
  
  //低压减载电压(标幺)
  private Double AutoUV_Volt;
  
  //低压减载时间(周)
  private Double AutoUV_Delay;
  
  //低压减载压板
  private Integer AutoUV_Plate;
  
  //负荷直供线路段
  private String LineSegment;
  
  //投资费用(万元)
  private Double ei_Invest;
  
  //每次固定停电损失(万元/次)
  private Double ei_Constloss;
  
  //单位电能停电损失(万元/兆瓦时)
  private Double ei_EvalRatio;
  
  //主接线可靠性设备类型
  private Integer MCRType;
  
  //典型工作日负荷曲线
  private String TWDCurve;
  
  //典型节假日负荷曲线
  private String THDCurve;
  
  //有功(兆瓦)
  private Double P;
  
  //无功(兆乏)
  private Double Q;
  
  //电流(安培)
  private Double A;
  
  //电压(千伏)
  private Double V;
  
  //功角(度)
  private Double D;
  
  //功率因数
  private Double Factor;
  
  //年均综合停电次数(次/年)
  private Double ro_r;
  
  //综合停电平均持续时间(小时/次)
  private Double ro_t;
  
  //年均综合停电时间(小时/年)
  private Double ro_u;
  
  //年均故障停电次数(次/年)
  private Double ro_fr;
  
  //故障停电平均持续时间(小时/次)
  private Double ro_ft;
  
  //年均故障停电时间(小时/年)
  private Double ro_fu;
  
  //年均预安排停电次数(次/年)
  private Double ro_ar;
  
  //预安排停电平均持续时间(小时/次)
  private Double ro_at;
  
  //年均预安排停电时间(小时/年)
  private Double ro_au;
  
  //年均共模停电次数(次/年)
  private Double ro_cmr;
  
  //共模停电平均持续时间(小时/次)
  private Double ro_cmt;
  
  //年均共模停电时间(小时/年)
  private Double ro_cmu;
  
  //年停电电量(兆瓦时/年)
  private Double ro_ens;
  
  //年故障停电电量(兆瓦时/年)
  private Double ro_f_ens;
  
  //年预安排停电电量(兆瓦时/年)
  private Double ro_a_ens;
  
  //年停电损失(万元)
  private Double eo_loss;
  
  //年故障停电损失(万元)
  private Double eo_f_loss;
  
  //年预安排停电损失(万元)
  private Double eo_a_loss;
  
  //停运率贡献(%)
  private Double ro_RContribution;
  
  //停运时间贡献(%)
  private Double ro_UContribution;
  
  //停电电量贡献(%)
  private Double ro_EnsContribution;
  
  //可靠性计算时间(秒)
  private Double RCTime;
  
  //可靠性计算情况
  private Integer RCCase;
  
  //节点索引
  private Integer NodePtr;
  
  //拓扑节点
  private Integer TopoBus;
  
  //岛
  private Integer Island;
  
  //配网设备
  private Integer Distribution;
  
  //负荷归属设备类型
  private Integer ParentType;
  
  //综合状态(着色)
  private Integer State;
  
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
    
  public Double getPlanP()
  {
    return PlanP;
  }
    
  public void setPlanP(Double PlanP)
  {
    this.PlanP = PlanP;
  }
    
  public Double getPlanQ()
  {
    return PlanQ;
  }
    
  public void setPlanQ(Double PlanQ)
  {
    this.PlanQ = PlanQ;
  }
    
  public String getConnectivityNode()
  {
    return ConnectivityNode;
  }
    
  public void setConnectivityNode(String ConnectivityNode)
  {
    this.ConnectivityNode = ConnectivityNode;
  }
    
  public Double getX0()
  {
    return X0;
  }
    
  public void setX0(Double X0)
  {
    this.X0 = X0;
  }
    
  public Double getri_Customer()
  {
    return ri_Customer;
  }
    
  public void setri_Customer(Double ri_Customer)
  {
    this.ri_Customer = ri_Customer;
  }
    
  public Integer getType()
  {
    return Type;
  }
    
  public void setType(Integer Type)
  {
    this.Type = Type;
  }
    
  public Double getCapacity()
  {
    return Capacity;
  }
    
  public void setCapacity(Double Capacity)
  {
    this.Capacity = Capacity;
  }
    
  public Double getMotorCapacity()
  {
    return MotorCapacity;
  }
    
  public void setMotorCapacity(Double MotorCapacity)
  {
    this.MotorCapacity = MotorCapacity;
  }
    
  public String getLoadModel()
  {
    return LoadModel;
  }
    
  public void setLoadModel(String LoadModel)
  {
    this.LoadModel = LoadModel;
  }
    
  public Double getMotorEmws()
  {
    return MotorEmws;
  }
    
  public void setMotorEmws(Double MotorEmws)
  {
    this.MotorEmws = MotorEmws;
  }
    
  public Double getMotorPper()
  {
    return MotorPper;
  }
    
  public void setMotorPper(Double MotorPper)
  {
    this.MotorPper = MotorPper;
  }
    
  public Double getMotorKL()
  {
    return MotorKL;
  }
    
  public void setMotorKL(Double MotorKL)
  {
    this.MotorKL = MotorKL;
  }
    
  public Double getMotorRs()
  {
    return MotorRs;
  }
    
  public void setMotorRs(Double MotorRs)
  {
    this.MotorRs = MotorRs;
  }
    
  public Double getMotorXs()
  {
    return MotorXs;
  }
    
  public void setMotorXs(Double MotorXs)
  {
    this.MotorXs = MotorXs;
  }
    
  public Double getMotorXm()
  {
    return MotorXm;
  }
    
  public void setMotorXm(Double MotorXm)
  {
    this.MotorXm = MotorXm;
  }
    
  public Double getMotorRr()
  {
    return MotorRr;
  }
    
  public void setMotorRr(Double MotorRr)
  {
    this.MotorRr = MotorRr;
  }
    
  public Double getMotorXr()
  {
    return MotorXr;
  }
    
  public void setMotorXr(Double MotorXr)
  {
    this.MotorXr = MotorXr;
  }
    
  public Double getMotorA()
  {
    return MotorA;
  }
    
  public void setMotorA(Double MotorA)
  {
    this.MotorA = MotorA;
  }
    
  public Double getMotorB()
  {
    return MotorB;
  }
    
  public void setMotorB(Double MotorB)
  {
    this.MotorB = MotorB;
  }
    
  public Integer getMotorUseS0()
  {
    return MotorUseS0;
  }
    
  public void setMotorUseS0(Integer MotorUseS0)
  {
    this.MotorUseS0 = MotorUseS0;
  }
    
  public Integer getMotorIM()
  {
    return MotorIM;
  }
    
  public void setMotorIM(Integer MotorIM)
  {
    this.MotorIM = MotorIM;
  }
    
  public Double getAutoUF_Freq()
  {
    return AutoUF_Freq;
  }
    
  public void setAutoUF_Freq(Double AutoUF_Freq)
  {
    this.AutoUF_Freq = AutoUF_Freq;
  }
    
  public Double getAutoUF_Delay()
  {
    return AutoUF_Delay;
  }
    
  public void setAutoUF_Delay(Double AutoUF_Delay)
  {
    this.AutoUF_Delay = AutoUF_Delay;
  }
    
  public Integer getAutoUF_Plate()
  {
    return AutoUF_Plate;
  }
    
  public void setAutoUF_Plate(Integer AutoUF_Plate)
  {
    this.AutoUF_Plate = AutoUF_Plate;
  }
    
  public Double getAutoUV_Volt()
  {
    return AutoUV_Volt;
  }
    
  public void setAutoUV_Volt(Double AutoUV_Volt)
  {
    this.AutoUV_Volt = AutoUV_Volt;
  }
    
  public Double getAutoUV_Delay()
  {
    return AutoUV_Delay;
  }
    
  public void setAutoUV_Delay(Double AutoUV_Delay)
  {
    this.AutoUV_Delay = AutoUV_Delay;
  }
    
  public Integer getAutoUV_Plate()
  {
    return AutoUV_Plate;
  }
    
  public void setAutoUV_Plate(Integer AutoUV_Plate)
  {
    this.AutoUV_Plate = AutoUV_Plate;
  }
    
  public String getLineSegment()
  {
    return LineSegment;
  }
    
  public void setLineSegment(String LineSegment)
  {
    this.LineSegment = LineSegment;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Double getei_Constloss()
  {
    return ei_Constloss;
  }
    
  public void setei_Constloss(Double ei_Constloss)
  {
    this.ei_Constloss = ei_Constloss;
  }
    
  public Double getei_EvalRatio()
  {
    return ei_EvalRatio;
  }
    
  public void setei_EvalRatio(Double ei_EvalRatio)
  {
    this.ei_EvalRatio = ei_EvalRatio;
  }
    
  public Integer getMCRType()
  {
    return MCRType;
  }
    
  public void setMCRType(Integer MCRType)
  {
    this.MCRType = MCRType;
  }
    
  public String getTWDCurve()
  {
    return TWDCurve;
  }
    
  public void setTWDCurve(String TWDCurve)
  {
    this.TWDCurve = TWDCurve;
  }
    
  public String getTHDCurve()
  {
    return THDCurve;
  }
    
  public void setTHDCurve(String THDCurve)
  {
    this.THDCurve = THDCurve;
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
    
  public Double getV()
  {
    return V;
  }
    
  public void setV(Double V)
  {
    this.V = V;
  }
    
  public Double getD()
  {
    return D;
  }
    
  public void setD(Double D)
  {
    this.D = D;
  }
    
  public Double getFactor()
  {
    return Factor;
  }
    
  public void setFactor(Double Factor)
  {
    this.Factor = Factor;
  }
    
  public Double getro_r()
  {
    return ro_r;
  }
    
  public void setro_r(Double ro_r)
  {
    this.ro_r = ro_r;
  }
    
  public Double getro_t()
  {
    return ro_t;
  }
    
  public void setro_t(Double ro_t)
  {
    this.ro_t = ro_t;
  }
    
  public Double getro_u()
  {
    return ro_u;
  }
    
  public void setro_u(Double ro_u)
  {
    this.ro_u = ro_u;
  }
    
  public Double getro_fr()
  {
    return ro_fr;
  }
    
  public void setro_fr(Double ro_fr)
  {
    this.ro_fr = ro_fr;
  }
    
  public Double getro_ft()
  {
    return ro_ft;
  }
    
  public void setro_ft(Double ro_ft)
  {
    this.ro_ft = ro_ft;
  }
    
  public Double getro_fu()
  {
    return ro_fu;
  }
    
  public void setro_fu(Double ro_fu)
  {
    this.ro_fu = ro_fu;
  }
    
  public Double getro_ar()
  {
    return ro_ar;
  }
    
  public void setro_ar(Double ro_ar)
  {
    this.ro_ar = ro_ar;
  }
    
  public Double getro_at()
  {
    return ro_at;
  }
    
  public void setro_at(Double ro_at)
  {
    this.ro_at = ro_at;
  }
    
  public Double getro_au()
  {
    return ro_au;
  }
    
  public void setro_au(Double ro_au)
  {
    this.ro_au = ro_au;
  }
    
  public Double getro_cmr()
  {
    return ro_cmr;
  }
    
  public void setro_cmr(Double ro_cmr)
  {
    this.ro_cmr = ro_cmr;
  }
    
  public Double getro_cmt()
  {
    return ro_cmt;
  }
    
  public void setro_cmt(Double ro_cmt)
  {
    this.ro_cmt = ro_cmt;
  }
    
  public Double getro_cmu()
  {
    return ro_cmu;
  }
    
  public void setro_cmu(Double ro_cmu)
  {
    this.ro_cmu = ro_cmu;
  }
    
  public Double getro_ens()
  {
    return ro_ens;
  }
    
  public void setro_ens(Double ro_ens)
  {
    this.ro_ens = ro_ens;
  }
    
  public Double getro_f_ens()
  {
    return ro_f_ens;
  }
    
  public void setro_f_ens(Double ro_f_ens)
  {
    this.ro_f_ens = ro_f_ens;
  }
    
  public Double getro_a_ens()
  {
    return ro_a_ens;
  }
    
  public void setro_a_ens(Double ro_a_ens)
  {
    this.ro_a_ens = ro_a_ens;
  }
    
  public Double geteo_loss()
  {
    return eo_loss;
  }
    
  public void seteo_loss(Double eo_loss)
  {
    this.eo_loss = eo_loss;
  }
    
  public Double geteo_f_loss()
  {
    return eo_f_loss;
  }
    
  public void seteo_f_loss(Double eo_f_loss)
  {
    this.eo_f_loss = eo_f_loss;
  }
    
  public Double geteo_a_loss()
  {
    return eo_a_loss;
  }
    
  public void seteo_a_loss(Double eo_a_loss)
  {
    this.eo_a_loss = eo_a_loss;
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
    
  public Double getRCTime()
  {
    return RCTime;
  }
    
  public void setRCTime(Double RCTime)
  {
    this.RCTime = RCTime;
  }
    
  public Integer getRCCase()
  {
    return RCCase;
  }
    
  public void setRCCase(Integer RCCase)
  {
    this.RCCase = RCCase;
  }
    
  public Integer getNodePtr()
  {
    return NodePtr;
  }
    
  public void setNodePtr(Integer NodePtr)
  {
    this.NodePtr = NodePtr;
  }
    
  public Integer getTopoBus()
  {
    return TopoBus;
  }
    
  public void setTopoBus(Integer TopoBus)
  {
    this.TopoBus = TopoBus;
  }
    
  public Integer getIsland()
  {
    return Island;
  }
    
  public void setIsland(Integer Island)
  {
    this.Island = Island;
  }
    
  public Integer getDistribution()
  {
    return Distribution;
  }
    
  public void setDistribution(Integer Distribution)
  {
    this.Distribution = Distribution;
  }
    
  public Integer getParentType()
  {
    return ParentType;
  }
    
  public void setParentType(Integer ParentType)
  {
    this.ParentType = ParentType;
  }
    
  public Integer getState()
  {
    return State;
  }
    
  public void setState(Integer State)
  {
    this.State = State;
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
    return "EnergyConsumer ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", PlanP = " + PlanP
	 + ", PlanQ = " + PlanQ
	 + ", ConnectivityNode = " + ConnectivityNode
	 + ", X0 = " + X0
	 + ", ri_Customer = " + ri_Customer
	 + ", Type = " + Type
	 + ", Capacity = " + Capacity
	 + ", MotorCapacity = " + MotorCapacity
	 + ", LoadModel = " + LoadModel
	 + ", MotorEmws = " + MotorEmws
	 + ", MotorPper = " + MotorPper
	 + ", MotorKL = " + MotorKL
	 + ", MotorRs = " + MotorRs
	 + ", MotorXs = " + MotorXs
	 + ", MotorXm = " + MotorXm
	 + ", MotorRr = " + MotorRr
	 + ", MotorXr = " + MotorXr
	 + ", MotorA = " + MotorA
	 + ", MotorB = " + MotorB
	 + ", MotorUseS0 = " + MotorUseS0
	 + ", MotorIM = " + MotorIM
	 + ", AutoUF_Freq = " + AutoUF_Freq
	 + ", AutoUF_Delay = " + AutoUF_Delay
	 + ", AutoUF_Plate = " + AutoUF_Plate
	 + ", AutoUV_Volt = " + AutoUV_Volt
	 + ", AutoUV_Delay = " + AutoUV_Delay
	 + ", AutoUV_Plate = " + AutoUV_Plate
	 + ", LineSegment = " + LineSegment
	 + ", ei_Invest = " + ei_Invest
	 + ", ei_Constloss = " + ei_Constloss
	 + ", ei_EvalRatio = " + ei_EvalRatio
	 + ", MCRType = " + MCRType
	 + ", TWDCurve = " + TWDCurve
	 + ", THDCurve = " + THDCurve
	 + ", P = " + P
	 + ", Q = " + Q
	 + ", A = " + A
	 + ", V = " + V
	 + ", D = " + D
	 + ", Factor = " + Factor
	 + ", ro_r = " + ro_r
	 + ", ro_t = " + ro_t
	 + ", ro_u = " + ro_u
	 + ", ro_fr = " + ro_fr
	 + ", ro_ft = " + ro_ft
	 + ", ro_fu = " + ro_fu
	 + ", ro_ar = " + ro_ar
	 + ", ro_at = " + ro_at
	 + ", ro_au = " + ro_au
	 + ", ro_cmr = " + ro_cmr
	 + ", ro_cmt = " + ro_cmt
	 + ", ro_cmu = " + ro_cmu
	 + ", ro_ens = " + ro_ens
	 + ", ro_f_ens = " + ro_f_ens
	 + ", ro_a_ens = " + ro_a_ens
	 + ", eo_loss = " + eo_loss
	 + ", eo_f_loss = " + eo_f_loss
	 + ", eo_a_loss = " + eo_a_loss
	 + ", ro_RContribution = " + ro_RContribution
	 + ", ro_UContribution = " + ro_UContribution
	 + ", ro_EnsContribution = " + ro_EnsContribution
	 + ", RCTime = " + RCTime
	 + ", RCCase = " + RCCase
	 + ", NodePtr = " + NodePtr
	 + ", TopoBus = " + TopoBus
	 + ", Island = " + Island
	 + ", Distribution = " + Distribution
	 + ", ParentType = " + ParentType
	 + ", State = " + State
	 + ", Outage = " + Outage+"]";
  }
    
}
    
