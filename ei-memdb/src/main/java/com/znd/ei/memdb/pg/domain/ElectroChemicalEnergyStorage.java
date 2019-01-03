package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电化学储能	*
***********************/
public class ElectroChemicalEnergyStorage  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //ObjectId
  private String ObjectID;
  
  //变电站
  private String Substation;
  
  //电压等级
  private String VoltageLevel;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //节点
  private String ConnectivityNode;
  
  //负荷类型
  private Integer Type;
  
  //额定容量(安时)
  private Double RatedCapacity;
  
  //额定功率(兆瓦)
  private Double RatedPower;
  
  //计划有功(兆瓦)
  private Double PlanP;
  
  //计划无功(兆乏)
  private Double PlanQ;
  
  //额定开路电压(千伏)
  private Double RatedVoc;
  
  //循环寿命(时)
  private Double LifeCycle;
  
  //充电效率(%)
  private Double Effc;
  
  //放电效率(%)
  private Double Effd;
  
  //故障率(次/台.年)
  private Double ri_Rerr;
  
  //修复时间(小时/次)
  private Double ri_Trep;
  
  //计划检修率(次/台.年)
  private Double ri_Rchk;
  
  //检修时间(小时/次)
  private Double ri_Tchk;
  
  //故障定位隔离时间(小时)
  private Double ri_Tfloc;
  
  //设备费用(万元)
  private Double ei_Invest;
  
  //典型工作模式曲线
  private String WorkModeCurve;
  
  //典型容量变化曲线
  private String CapacityCurve;
  
  //有功(兆瓦)
  private Double P;
  
  //无功(兆乏)
  private Double Q;
  
  //电流(安培)
  private Double A;
  
  //端电压(千伏)
  private Double V;
  
  //短路电流(安培)
  private Double SccA;
  
  //N-1通过情况
  private Integer sa_Result;
  
  //N-1形成孤岛
  private Integer sa_Island;
  
  //N-1负荷损失(兆伏安)
  private Double sa_Failure;
  
  //N-1设备负荷损失(兆瓦)
  private Double sa_Outages;
  
  //节点索引
  private Integer NodePtr;
  
  //拓扑节点
  private Integer TopoBus;
  
  //岛
  private Integer Island;
  
  //计算状态
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
    
  public Double getRatedCapacity()
  {
    return RatedCapacity;
  }
    
  public void setRatedCapacity(Double RatedCapacity)
  {
    this.RatedCapacity = RatedCapacity;
  }
    
  public Double getRatedPower()
  {
    return RatedPower;
  }
    
  public void setRatedPower(Double RatedPower)
  {
    this.RatedPower = RatedPower;
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
    
  public Double getRatedVoc()
  {
    return RatedVoc;
  }
    
  public void setRatedVoc(Double RatedVoc)
  {
    this.RatedVoc = RatedVoc;
  }
    
  public Double getLifeCycle()
  {
    return LifeCycle;
  }
    
  public void setLifeCycle(Double LifeCycle)
  {
    this.LifeCycle = LifeCycle;
  }
    
  public Double getEffc()
  {
    return Effc;
  }
    
  public void setEffc(Double Effc)
  {
    this.Effc = Effc;
  }
    
  public Double getEffd()
  {
    return Effd;
  }
    
  public void setEffd(Double Effd)
  {
    this.Effd = Effd;
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
    
  public String getWorkModeCurve()
  {
    return WorkModeCurve;
  }
    
  public void setWorkModeCurve(String WorkModeCurve)
  {
    this.WorkModeCurve = WorkModeCurve;
  }
    
  public String getCapacityCurve()
  {
    return CapacityCurve;
  }
    
  public void setCapacityCurve(String CapacityCurve)
  {
    this.CapacityCurve = CapacityCurve;
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
    
  public Double getSccA()
  {
    return SccA;
  }
    
  public void setSccA(Double SccA)
  {
    this.SccA = SccA;
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
    return "ElectroChemicalEnergyStorage ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", ConnectivityNode = " + ConnectivityNode
	 + ", Type = " + Type
	 + ", RatedCapacity = " + RatedCapacity
	 + ", RatedPower = " + RatedPower
	 + ", PlanP = " + PlanP
	 + ", PlanQ = " + PlanQ
	 + ", RatedVoc = " + RatedVoc
	 + ", LifeCycle = " + LifeCycle
	 + ", Effc = " + Effc
	 + ", Effd = " + Effd
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ei_Invest = " + ei_Invest
	 + ", WorkModeCurve = " + WorkModeCurve
	 + ", CapacityCurve = " + CapacityCurve
	 + ", P = " + P
	 + ", Q = " + Q
	 + ", A = " + A
	 + ", V = " + V
	 + ", SccA = " + SccA
	 + ", sa_Result = " + sa_Result
	 + ", sa_Island = " + sa_Island
	 + ", sa_Failure = " + sa_Failure
	 + ", sa_Outages = " + sa_Outages
	 + ", NodePtr = " + NodePtr
	 + ", TopoBus = " + TopoBus
	 + ", Island = " + Island
	 + ", Outage = " + Outage+"]";
  }
    
}
    
