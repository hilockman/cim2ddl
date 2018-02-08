package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*发电机	*
***********************/
public class SynchronousMachine  implements MemIndexable 
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
  
  //计划有功(MW)
  private Double Planp;
  
  //计划无功(MVar)
  private Double Planq;
  
  //PV值(PU)
  private Double PV;
  
  //节点
  private String ConnectivityNode;
  
  //发电机类型
  private Integer Type;
  
  //最大有功(MW)
  private Double PMax;
  
  //最小有功(MW)
  private Double PMin;
  
  //最大无功(MVar)
  private Double QMax;
  
  //最小无功(MVar)
  private Double QMin;
  
  //视在功率(MVA)
  private Double Mvarate;
  
  //厂用电恒功率比例(<1)
  private Double AuxPca;
  
  //厂用电变功率比例(<1)
  private Double AuxPva;
  
  //厂用电功率因数
  private Double AuxFactor;
  
  //零序电抗(PU)
  private Double X0;
  
  //直轴次暂态电抗(PU)
  private Double Xdpp;
  
  //BPA模型发电机母线
  private String BPAGenBus;
  
  //BPA模型发电机电压
  private Double BPAGenVolt;
  
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
  
  //主接线可靠性设备类型
  private Integer MCRType;
  
  //主接线可靠性源/荷功率
  private Double MCRPower;
  
  //发电机典型发电曲线
  private String TDCurve;
  
  //有功(MW)
  private Double P;
  
  //无功(MVar)
  private Double Q;
  
  //电流(A)
  private Double A;
  
  //机端电压(kV)
  private Double V;
  
  //机端相角(度)
  private Double D;
  
  //功率因数
  private Double Factor;
  
  //A相短路电流(A)
  private Double ScIa;
  
  //B相短路电流(A)
  private Double ScIb;
  
  //C相短路电流(A)
  private Double ScIc;
  
  //A相短路电压(kV)
  private Double ScVa;
  
  //B相短路电压(kV)
  private Double ScVb;
  
  //C相短路电压(kV)
  private Double ScVc;
  
  //停运率贡献(%)
  private Double ro_rContribution;
  
  //停运时间贡献(%)
  private Double ro_uContribution;
  
  //停电电量贡献(%)
  private Double ro_ensContribution;
  
  //节点索引
  private Integer NodePtr;
  
  //拓扑节点
  private Integer TopoBus;
  
  //岛
  private Integer Island;
  
  //配网设备
  private Integer Distribution;
  
  //综合状态(着色)
  private Integer State;
  
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
    
  public Double getPlanp()
  {
    return Planp;
  }
    
  public void setPlanp(Double Planp)
  {
    this.Planp = Planp;
  }
    
  public Double getPlanq()
  {
    return Planq;
  }
    
  public void setPlanq(Double Planq)
  {
    this.Planq = Planq;
  }
    
  public Double getPV()
  {
    return PV;
  }
    
  public void setPV(Double PV)
  {
    this.PV = PV;
  }
    
  public String getConnectivityNode()
  {
    return ConnectivityNode;
  }
    
  public void setConnectivityNode(String ConnectivityNode)
  {
    this.ConnectivityNode = ConnectivityNode;
  }
    
  public Integer getType()
  {
    return Type;
  }
    
  public void setType(Integer Type)
  {
    this.Type = Type;
  }
    
  public Double getPMax()
  {
    return PMax;
  }
    
  public void setPMax(Double PMax)
  {
    this.PMax = PMax;
  }
    
  public Double getPMin()
  {
    return PMin;
  }
    
  public void setPMin(Double PMin)
  {
    this.PMin = PMin;
  }
    
  public Double getQMax()
  {
    return QMax;
  }
    
  public void setQMax(Double QMax)
  {
    this.QMax = QMax;
  }
    
  public Double getQMin()
  {
    return QMin;
  }
    
  public void setQMin(Double QMin)
  {
    this.QMin = QMin;
  }
    
  public Double getMvarate()
  {
    return Mvarate;
  }
    
  public void setMvarate(Double Mvarate)
  {
    this.Mvarate = Mvarate;
  }
    
  public Double getAuxPca()
  {
    return AuxPca;
  }
    
  public void setAuxPca(Double AuxPca)
  {
    this.AuxPca = AuxPca;
  }
    
  public Double getAuxPva()
  {
    return AuxPva;
  }
    
  public void setAuxPva(Double AuxPva)
  {
    this.AuxPva = AuxPva;
  }
    
  public Double getAuxFactor()
  {
    return AuxFactor;
  }
    
  public void setAuxFactor(Double AuxFactor)
  {
    this.AuxFactor = AuxFactor;
  }
    
  public Double getX0()
  {
    return X0;
  }
    
  public void setX0(Double X0)
  {
    this.X0 = X0;
  }
    
  public Double getXdpp()
  {
    return Xdpp;
  }
    
  public void setXdpp(Double Xdpp)
  {
    this.Xdpp = Xdpp;
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
    
  public String getTDCurve()
  {
    return TDCurve;
  }
    
  public void setTDCurve(String TDCurve)
  {
    this.TDCurve = TDCurve;
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
    
  public Double getScVa()
  {
    return ScVa;
  }
    
  public void setScVa(Double ScVa)
  {
    this.ScVa = ScVa;
  }
    
  public Double getScVb()
  {
    return ScVb;
  }
    
  public void setScVb(Double ScVb)
  {
    this.ScVb = ScVb;
  }
    
  public Double getScVc()
  {
    return ScVc;
  }
    
  public void setScVc(Double ScVc)
  {
    this.ScVc = ScVc;
  }
    
  public Double getro_rContribution()
  {
    return ro_rContribution;
  }
    
  public void setro_rContribution(Double ro_rContribution)
  {
    this.ro_rContribution = ro_rContribution;
  }
    
  public Double getro_uContribution()
  {
    return ro_uContribution;
  }
    
  public void setro_uContribution(Double ro_uContribution)
  {
    this.ro_uContribution = ro_uContribution;
  }
    
  public Double getro_ensContribution()
  {
    return ro_ensContribution;
  }
    
  public void setro_ensContribution(Double ro_ensContribution)
  {
    this.ro_ensContribution = ro_ensContribution;
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
    return "SynchronousMachine ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", Planp = " + Planp
	 + ", Planq = " + Planq
	 + ", PV = " + PV
	 + ", ConnectivityNode = " + ConnectivityNode
	 + ", Type = " + Type
	 + ", PMax = " + PMax
	 + ", PMin = " + PMin
	 + ", QMax = " + QMax
	 + ", QMin = " + QMin
	 + ", Mvarate = " + Mvarate
	 + ", AuxPca = " + AuxPca
	 + ", AuxPva = " + AuxPva
	 + ", AuxFactor = " + AuxFactor
	 + ", X0 = " + X0
	 + ", Xdpp = " + Xdpp
	 + ", BPAGenBus = " + BPAGenBus
	 + ", BPAGenVolt = " + BPAGenVolt
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ei_Invest = " + ei_Invest
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
	 + ", MCRType = " + MCRType
	 + ", MCRPower = " + MCRPower
	 + ", TDCurve = " + TDCurve
	 + ", P = " + P
	 + ", Q = " + Q
	 + ", A = " + A
	 + ", V = " + V
	 + ", D = " + D
	 + ", Factor = " + Factor
	 + ", ScIa = " + ScIa
	 + ", ScIb = " + ScIb
	 + ", ScIc = " + ScIc
	 + ", ScVa = " + ScVa
	 + ", ScVb = " + ScVb
	 + ", ScVc = " + ScVc
	 + ", ro_rContribution = " + ro_rContribution
	 + ", ro_uContribution = " + ro_uContribution
	 + ", ro_ensContribution = " + ro_ensContribution
	 + ", NodePtr = " + NodePtr
	 + ", TopoBus = " + TopoBus
	 + ", Island = " + Island
	 + ", Distribution = " + Distribution
	 + ", State = " + State
	 + ", Open = " + Open
	 + ", Outage = " + Outage+"]";
  }
    
}
    
