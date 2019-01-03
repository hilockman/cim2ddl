package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*串联补偿	*
***********************/
public class SeriesCompensator  implements MemIndexable 
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
  
  //起节点
  private String ConnectivityNodeI;
  
  //终节点
  private String ConnectivityNodeJ;
  
  //电阻(标幺)
  private Double r;
  
  //电抗(标幺)
  private Double x;
  
  //零序电抗(标幺)
  private Double x0;
  
  //额定电流(安培)
  private Double Rate;
  
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
  
  //I侧有功(兆瓦)
  private Double Pi;
  
  //I侧无功(兆乏)
  private Double Qi;
  
  //Z侧有功(兆瓦)
  private Double Pz;
  
  //Z侧无功(兆乏)
  private Double Qz;
  
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
  
  //起边设备索引
  private Integer EdgeI;
  
  //终边设备索引
  private Integer EdgeJ;
  
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
    
  public Double getr()
  {
    return r;
  }
    
  public void setr(Double r)
  {
    this.r = r;
  }
    
  public Double getx()
  {
    return x;
  }
    
  public void setx(Double x)
  {
    this.x = x;
  }
    
  public Double getx0()
  {
    return x0;
  }
    
  public void setx0(Double x0)
  {
    this.x0 = x0;
  }
    
  public Double getRate()
  {
    return Rate;
  }
    
  public void setRate(Double Rate)
  {
    this.Rate = Rate;
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
    return "SeriesCompensator ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", ConnectivityNodeI = " + ConnectivityNodeI
	 + ", ConnectivityNodeJ = " + ConnectivityNodeJ
	 + ", r = " + r
	 + ", x = " + x
	 + ", x0 = " + x0
	 + ", Rate = " + Rate
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ei_Invest = " + ei_Invest
	 + ", Pi = " + Pi
	 + ", Qi = " + Qi
	 + ", Pz = " + Pz
	 + ", Qz = " + Qz
	 + ", A = " + A
	 + ", LossP = " + LossP
	 + ", LossQ = " + LossQ
	 + ", ScIa = " + ScIa
	 + ", ScIb = " + ScIb
	 + ", ScIc = " + ScIc
	 + ", ScI1 = " + ScI1
	 + ", ScI2 = " + ScI2
	 + ", ScI0 = " + ScI0
	 + ", NodeIPtr = " + NodeIPtr
	 + ", NodeJPtr = " + NodeJPtr
	 + ", TopoBusI = " + TopoBusI
	 + ", TopoBusJ = " + TopoBusJ
	 + ", Island = " + Island
	 + ", EdgeI = " + EdgeI
	 + ", EdgeJ = " + EdgeJ
	 + ", Distribution = " + Distribution
	 + ", State = " + State
	 + ", Open = " + Open
	 + ", Outage = " + Outage+"]";
  }
    
}
    
