package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*厂站实体	*
***********************/
public class SubstationEntity  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源ID
  private String ResourceID;
  
  //电压等级(电源站)
  private String VoltageLevel;
  
  //名称
  private String Name;
  
  //最高电压等级
  private String HighVoltageLevel;
  
  //节点(物理)
  private String ConnectivityNode;
  
  //厂站类型
  private Integer SubstationType;
  
  //变电站容量构成
  private String Component;
  
  //容量(MVA)
  private Double MvaCapacity;
  
  //发电有功(MW)
  private Double GenP;
  
  //发电无功(MVar)
  private Double GenQ;
  
  //计划电压(PU)
  private Double PlanVAmp;
  
  //负荷(MW)
  private Double LoadP;
  
  //负荷功率因数
  private Double LoadFactor;
  
  //无功补偿(MVar)
  private Double Shuntcap;
  
  //热负荷功率(MW)
  private Double HeatingLoad;
  
  //冷负荷功率(MW)
  private Double RefrigerationLoad;
  
  //自动生成变压器
  private Integer AutoFormTran;
  
  //等值正序电抗(PU)(电源站)
  private Double EqX;
  
  //等值零序电抗(PU)(电源站)
  private Double EqX0;
  
  //BPA模型发电机母线
  private String BPAGenBus;
  
  //BPA模型发电机电压
  private Double BPAGenVolt;
  
  //间隔总数(电源站)
  private Integer TotalBay;
  
  //空闲间隔数(电源站)
  private Integer FreeBay;
  
  //出线间隔总数(电源站)
  private Integer TotalOutline;
  
  //已出线间隔数(电源站)
  private Integer InuseOutline;
  
  //故障率(次/台.年)
  private Double ri_Rerr;
  
  //修复时间(小时/次)
  private Double ri_Trep;
  
  //计划检修率(次/台.年)
  private Double ri_Rchk;
  
  //检修时间(小时/次)
  private Double ri_Tchk;
  
  //故障定位隔离时间(小时/次)
  private Double ri_Tfloc;
  
  //用户数
  private Double ri_Customer;
  
  //配出负荷故障率(次/台.年)
  private Double ri_Load_Rerr;
  
  //配出负荷修复时间(小时/次)
  private Double ri_Load_Trep;
  
  //配出负荷计划检修率(次/台.年)
  private Double ri_Load_Rchk;
  
  //配出负荷检修时间(小时/次)
  private Double ri_Load_Tchk;
  
  //理想通讯条件下故障定位决策时间
  private Double IdealFaultIndicatorTime;
  
  //投资费用(万元/台)
  private Double ei_Invest;
  
  //每次固定停电损失(万元/次)
  private Double ei_ConstLoss;
  
  //单位电能停电损失
  private Double ei_EvalRatio;
  
  //转速保护整定1(PU)
  private Double RW_Tuning1;
  
  //转速保护整定2(PU)
  private Double RW_Tuning2;
  
  //转速保护延时1(周)
  private Double RW_Delay1;
  
  //转速保护延时2(周)
  private Double RW_Delay2;
  
  //转速保护压板
  private Integer RW_Plate;
  
  //电压保护整定1(PU)
  private Double RE_Tuning1;
  
  //电压保护整定2(PU)
  private Double RE_Tuning2;
  
  //电压保护延时1(周)
  private Double RE_Delay1;
  
  //电压保护延时2(周)
  private Double RE_Delay2;
  
  //电压保护压板
  private Integer RE_Plate;
  
  //电岛
  private Integer Island;
  
  //下网有功(MW)
  private Double P;
  
  //下网无功(MVar)
  private Double Q;
  
  //电压(kV)
  private Double V;
  
  //功角(度)
  private Double D;
  
  //停电综合损失(万元)
  private Double eo_loss;
  
  //短路电流(A)
  private Double scc;
  
  //N-1通过情况
  private Integer sa_Result;
  
  //N-1形成孤岛
  private Integer sa_Island;
  
  //N-1负荷损失(MVA)
  private Double sa_Failure;
  
  //N-1设备负荷损失(MW)
  private Double sa_Outages;
  
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
    
  public String getHighVoltageLevel()
  {
    return HighVoltageLevel;
  }
    
  public void setHighVoltageLevel(String HighVoltageLevel)
  {
    this.HighVoltageLevel = HighVoltageLevel;
  }
    
  public String getConnectivityNode()
  {
    return ConnectivityNode;
  }
    
  public void setConnectivityNode(String ConnectivityNode)
  {
    this.ConnectivityNode = ConnectivityNode;
  }
    
  public Integer getSubstationType()
  {
    return SubstationType;
  }
    
  public void setSubstationType(Integer SubstationType)
  {
    this.SubstationType = SubstationType;
  }
    
  public String getComponent()
  {
    return Component;
  }
    
  public void setComponent(String Component)
  {
    this.Component = Component;
  }
    
  public Double getMvaCapacity()
  {
    return MvaCapacity;
  }
    
  public void setMvaCapacity(Double MvaCapacity)
  {
    this.MvaCapacity = MvaCapacity;
  }
    
  public Double getGenP()
  {
    return GenP;
  }
    
  public void setGenP(Double GenP)
  {
    this.GenP = GenP;
  }
    
  public Double getGenQ()
  {
    return GenQ;
  }
    
  public void setGenQ(Double GenQ)
  {
    this.GenQ = GenQ;
  }
    
  public Double getPlanVAmp()
  {
    return PlanVAmp;
  }
    
  public void setPlanVAmp(Double PlanVAmp)
  {
    this.PlanVAmp = PlanVAmp;
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
    
  public Double getShuntcap()
  {
    return Shuntcap;
  }
    
  public void setShuntcap(Double Shuntcap)
  {
    this.Shuntcap = Shuntcap;
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
    
  public Integer getAutoFormTran()
  {
    return AutoFormTran;
  }
    
  public void setAutoFormTran(Integer AutoFormTran)
  {
    this.AutoFormTran = AutoFormTran;
  }
    
  public Double getEqX()
  {
    return EqX;
  }
    
  public void setEqX(Double EqX)
  {
    this.EqX = EqX;
  }
    
  public Double getEqX0()
  {
    return EqX0;
  }
    
  public void setEqX0(Double EqX0)
  {
    this.EqX0 = EqX0;
  }
    
  public String getBPAGenBus()
  {
    return BPAGenBus;
  }
    
  public void setBPAGenBus(String BPAGenBus)
  {
    this.BPAGenBus = BPAGenBus;
  }
    
  public Double getBPAGenVolt()
  {
    return BPAGenVolt;
  }
    
  public void setBPAGenVolt(Double BPAGenVolt)
  {
    this.BPAGenVolt = BPAGenVolt;
  }
    
  public Integer getTotalBay()
  {
    return TotalBay;
  }
    
  public void setTotalBay(Integer TotalBay)
  {
    this.TotalBay = TotalBay;
  }
    
  public Integer getFreeBay()
  {
    return FreeBay;
  }
    
  public void setFreeBay(Integer FreeBay)
  {
    this.FreeBay = FreeBay;
  }
    
  public Integer getTotalOutline()
  {
    return TotalOutline;
  }
    
  public void setTotalOutline(Integer TotalOutline)
  {
    this.TotalOutline = TotalOutline;
  }
    
  public Integer getInuseOutline()
  {
    return InuseOutline;
  }
    
  public void setInuseOutline(Integer InuseOutline)
  {
    this.InuseOutline = InuseOutline;
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
    
  public Double getIdealFaultIndicatorTime()
  {
    return IdealFaultIndicatorTime;
  }
    
  public void setIdealFaultIndicatorTime(Double IdealFaultIndicatorTime)
  {
    this.IdealFaultIndicatorTime = IdealFaultIndicatorTime;
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
    
  public Double getRW_Tuning1()
  {
    return RW_Tuning1;
  }
    
  public void setRW_Tuning1(Double RW_Tuning1)
  {
    this.RW_Tuning1 = RW_Tuning1;
  }
    
  public Double getRW_Tuning2()
  {
    return RW_Tuning2;
  }
    
  public void setRW_Tuning2(Double RW_Tuning2)
  {
    this.RW_Tuning2 = RW_Tuning2;
  }
    
  public Double getRW_Delay1()
  {
    return RW_Delay1;
  }
    
  public void setRW_Delay1(Double RW_Delay1)
  {
    this.RW_Delay1 = RW_Delay1;
  }
    
  public Double getRW_Delay2()
  {
    return RW_Delay2;
  }
    
  public void setRW_Delay2(Double RW_Delay2)
  {
    this.RW_Delay2 = RW_Delay2;
  }
    
  public Integer getRW_Plate()
  {
    return RW_Plate;
  }
    
  public void setRW_Plate(Integer RW_Plate)
  {
    this.RW_Plate = RW_Plate;
  }
    
  public Double getRE_Tuning1()
  {
    return RE_Tuning1;
  }
    
  public void setRE_Tuning1(Double RE_Tuning1)
  {
    this.RE_Tuning1 = RE_Tuning1;
  }
    
  public Double getRE_Tuning2()
  {
    return RE_Tuning2;
  }
    
  public void setRE_Tuning2(Double RE_Tuning2)
  {
    this.RE_Tuning2 = RE_Tuning2;
  }
    
  public Double getRE_Delay1()
  {
    return RE_Delay1;
  }
    
  public void setRE_Delay1(Double RE_Delay1)
  {
    this.RE_Delay1 = RE_Delay1;
  }
    
  public Double getRE_Delay2()
  {
    return RE_Delay2;
  }
    
  public void setRE_Delay2(Double RE_Delay2)
  {
    this.RE_Delay2 = RE_Delay2;
  }
    
  public Integer getRE_Plate()
  {
    return RE_Plate;
  }
    
  public void setRE_Plate(Integer RE_Plate)
  {
    this.RE_Plate = RE_Plate;
  }
    
  public Integer getIsland()
  {
    return Island;
  }
    
  public void setIsland(Integer Island)
  {
    this.Island = Island;
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
    
  public Double geteo_loss()
  {
    return eo_loss;
  }
    
  public void seteo_loss(Double eo_loss)
  {
    this.eo_loss = eo_loss;
  }
    
  public Double getscc()
  {
    return scc;
  }
    
  public void setscc(Double scc)
  {
    this.scc = scc;
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
    
  public Double getsa_Outages()
  {
    return sa_Outages;
  }
    
  public void setsa_Outages(Double sa_Outages)
  {
    this.sa_Outages = sa_Outages;
  }
    
  public String toString()
  {
    return "SubstationEntity ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", HighVoltageLevel = " + HighVoltageLevel
	 + ", ConnectivityNode = " + ConnectivityNode
	 + ", SubstationType = " + SubstationType
	 + ", Component = " + Component
	 + ", MvaCapacity = " + MvaCapacity
	 + ", GenP = " + GenP
	 + ", GenQ = " + GenQ
	 + ", PlanVAmp = " + PlanVAmp
	 + ", LoadP = " + LoadP
	 + ", LoadFactor = " + LoadFactor
	 + ", Shuntcap = " + Shuntcap
	 + ", HeatingLoad = " + HeatingLoad
	 + ", RefrigerationLoad = " + RefrigerationLoad
	 + ", AutoFormTran = " + AutoFormTran
	 + ", EqX = " + EqX
	 + ", EqX0 = " + EqX0
	 + ", BPAGenBus = " + BPAGenBus
	 + ", BPAGenVolt = " + BPAGenVolt
	 + ", TotalBay = " + TotalBay
	 + ", FreeBay = " + FreeBay
	 + ", TotalOutline = " + TotalOutline
	 + ", InuseOutline = " + InuseOutline
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
	 + ", IdealFaultIndicatorTime = " + IdealFaultIndicatorTime
	 + ", ei_Invest = " + ei_Invest
	 + ", ei_ConstLoss = " + ei_ConstLoss
	 + ", ei_EvalRatio = " + ei_EvalRatio
	 + ", RW_Tuning1 = " + RW_Tuning1
	 + ", RW_Tuning2 = " + RW_Tuning2
	 + ", RW_Delay1 = " + RW_Delay1
	 + ", RW_Delay2 = " + RW_Delay2
	 + ", RW_Plate = " + RW_Plate
	 + ", RE_Tuning1 = " + RE_Tuning1
	 + ", RE_Tuning2 = " + RE_Tuning2
	 + ", RE_Delay1 = " + RE_Delay1
	 + ", RE_Delay2 = " + RE_Delay2
	 + ", RE_Plate = " + RE_Plate
	 + ", Island = " + Island
	 + ", P = " + P
	 + ", Q = " + Q
	 + ", V = " + V
	 + ", D = " + D
	 + ", eo_loss = " + eo_loss
	 + ", scc = " + scc
	 + ", sa_Result = " + sa_Result
	 + ", sa_Island = " + sa_Island
	 + ", sa_Failure = " + sa_Failure
	 + ", sa_Outages = " + sa_Outages+"]";
  }
    
}
    
