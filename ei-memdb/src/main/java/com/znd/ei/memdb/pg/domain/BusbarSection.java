package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*母线	*
***********************/
public class BusbarSection  implements MemIndexable 
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
  
  //节点
  private String ConnectivityNode;
  
  //电压(千伏)
  private Double V;
  
  //功角(度)
  private Double D;
  
  //频率(赫兹)
  private Double F;
  
  //电压下限(千伏)
  private Double VLimitL;
  
  //电压上限(千伏)
  private Double VLimitH;
  
  //母线负荷有功(兆瓦)
  private Double LoadP;
  
  //母线负荷无功(兆乏)
  private Double LoadQ;
  
  //母线发电有功(兆瓦)
  private Double GenP;
  
  //母线发电无功(兆乏)
  private Double GenQ;
  
  //母线补偿无功(兆乏)
  private Double ShuntQ;
  
  //给定电压(千伏)
  private Double ReferenceV;
  
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
  
  //配出负荷故障率(次/年)
  private Double ri_load_rerr;
  
  //配出负荷修复时间(小时/次)
  private Double ri_load_trep;
  
  //配出负荷计划检修率(次/年)
  private Double ri_load_rchk;
  
  //配出负荷检修时间(小时/次)
  private Double ri_load_tchk;
  
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
  
  //A相短路电压(千伏)
  private Double ScVa;
  
  //B相短路电压(千伏)
  private Double ScVb;
  
  //C相短路电压(千伏)
  private Double ScVc;
  
  //正序短路电压(千伏)
  private Double ScV1;
  
  //负序短路电压(千伏)
  private Double ScV2;
  
  //零序短路电压(千伏)
  private Double ScV0;
  
  //停运率贡献(%)
  private Double ro_rContribution;
  
  //停运时间贡献(%)
  private Double ro_uContribution;
  
  //停电电量贡献(%)
  private Double ro_ensContribution;
  
  //母线有功总加(兆瓦)
  private Double ErrP;
  
  //母线无功总加(兆乏)
  private Double ErrQ;
  
  //旁路母线
  private Integer Bypass;
  
  //节点索引
  private Integer NodePtr;
  
  //拓扑节点
  private Integer TopoBus;
  
  //岛
  private Integer Island;
  
  //虚拟设备
  private Integer Psedo;
  
  //母线归属设备类型
  private Integer ParentType;
  
  //运行状态
  private Integer State;
  
  //环网标记
  private Integer InRing;
  
  //辐射网号
  private Integer Radiate;
  
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
    
  public String getConnectivityNode()
  {
    return ConnectivityNode;
  }
    
  public void setConnectivityNode(String ConnectivityNode)
  {
    this.ConnectivityNode = ConnectivityNode;
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
    
  public Double getF()
  {
    return F;
  }
    
  public void setF(Double F)
  {
    this.F = F;
  }
    
  public Double getVLimitL()
  {
    return VLimitL;
  }
    
  public void setVLimitL(Double VLimitL)
  {
    this.VLimitL = VLimitL;
  }
    
  public Double getVLimitH()
  {
    return VLimitH;
  }
    
  public void setVLimitH(Double VLimitH)
  {
    this.VLimitH = VLimitH;
  }
    
  public Double getLoadP()
  {
    return LoadP;
  }
    
  public void setLoadP(Double LoadP)
  {
    this.LoadP = LoadP;
  }
    
  public Double getLoadQ()
  {
    return LoadQ;
  }
    
  public void setLoadQ(Double LoadQ)
  {
    this.LoadQ = LoadQ;
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
    
  public Double getShuntQ()
  {
    return ShuntQ;
  }
    
  public void setShuntQ(Double ShuntQ)
  {
    this.ShuntQ = ShuntQ;
  }
    
  public Double getReferenceV()
  {
    return ReferenceV;
  }
    
  public void setReferenceV(Double ReferenceV)
  {
    this.ReferenceV = ReferenceV;
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
    
  public Double getri_load_rerr()
  {
    return ri_load_rerr;
  }
    
  public void setri_load_rerr(Double ri_load_rerr)
  {
    this.ri_load_rerr = ri_load_rerr;
  }
    
  public Double getri_load_trep()
  {
    return ri_load_trep;
  }
    
  public void setri_load_trep(Double ri_load_trep)
  {
    this.ri_load_trep = ri_load_trep;
  }
    
  public Double getri_load_rchk()
  {
    return ri_load_rchk;
  }
    
  public void setri_load_rchk(Double ri_load_rchk)
  {
    this.ri_load_rchk = ri_load_rchk;
  }
    
  public Double getri_load_tchk()
  {
    return ri_load_tchk;
  }
    
  public void setri_load_tchk(Double ri_load_tchk)
  {
    this.ri_load_tchk = ri_load_tchk;
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
    
  public Double getScV1()
  {
    return ScV1;
  }
    
  public void setScV1(Double ScV1)
  {
    this.ScV1 = ScV1;
  }
    
  public Double getScV2()
  {
    return ScV2;
  }
    
  public void setScV2(Double ScV2)
  {
    this.ScV2 = ScV2;
  }
    
  public Double getScV0()
  {
    return ScV0;
  }
    
  public void setScV0(Double ScV0)
  {
    this.ScV0 = ScV0;
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
    
  public Double getErrP()
  {
    return ErrP;
  }
    
  public void setErrP(Double ErrP)
  {
    this.ErrP = ErrP;
  }
    
  public Double getErrQ()
  {
    return ErrQ;
  }
    
  public void setErrQ(Double ErrQ)
  {
    this.ErrQ = ErrQ;
  }
    
  public Integer getBypass()
  {
    return Bypass;
  }
    
  public void setBypass(Integer Bypass)
  {
    this.Bypass = Bypass;
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
    
  public Integer getPsedo()
  {
    return Psedo;
  }
    
  public void setPsedo(Integer Psedo)
  {
    this.Psedo = Psedo;
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
    
  public String toString()
  {
    return "BusbarSection ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", ConnectivityNode = " + ConnectivityNode
	 + ", V = " + V
	 + ", D = " + D
	 + ", F = " + F
	 + ", VLimitL = " + VLimitL
	 + ", VLimitH = " + VLimitH
	 + ", LoadP = " + LoadP
	 + ", LoadQ = " + LoadQ
	 + ", GenP = " + GenP
	 + ", GenQ = " + GenQ
	 + ", ShuntQ = " + ShuntQ
	 + ", ReferenceV = " + ReferenceV
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ri_load_rerr = " + ri_load_rerr
	 + ", ri_load_trep = " + ri_load_trep
	 + ", ri_load_rchk = " + ri_load_rchk
	 + ", ri_load_tchk = " + ri_load_tchk
	 + ", ei_Invest = " + ei_Invest
	 + ", vd_RScc1 = " + vd_RScc1
	 + ", vd_RScc2 = " + vd_RScc2
	 + ", vd_RScc3 = " + vd_RScc3
	 + ", vd_RScc4 = " + vd_RScc4
	 + ", ScIa = " + ScIa
	 + ", ScIb = " + ScIb
	 + ", ScIc = " + ScIc
	 + ", ScI1 = " + ScI1
	 + ", ScI2 = " + ScI2
	 + ", ScI0 = " + ScI0
	 + ", ScVa = " + ScVa
	 + ", ScVb = " + ScVb
	 + ", ScVc = " + ScVc
	 + ", ScV1 = " + ScV1
	 + ", ScV2 = " + ScV2
	 + ", ScV0 = " + ScV0
	 + ", ro_rContribution = " + ro_rContribution
	 + ", ro_uContribution = " + ro_uContribution
	 + ", ro_ensContribution = " + ro_ensContribution
	 + ", ErrP = " + ErrP
	 + ", ErrQ = " + ErrQ
	 + ", Bypass = " + Bypass
	 + ", NodePtr = " + NodePtr
	 + ", TopoBus = " + TopoBus
	 + ", Island = " + Island
	 + ", Psedo = " + Psedo
	 + ", ParentType = " + ParentType
	 + ", State = " + State
	 + ", InRing = " + InRing
	 + ", Radiate = " + Radiate
	 + ", Open = " + Open+"]";
  }
    
}
    
