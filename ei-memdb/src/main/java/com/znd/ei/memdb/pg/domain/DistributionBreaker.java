package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*配电开关	*
***********************/
public class DistributionBreaker  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源ID
  private String ResourceID;
  
  //厂站名称(虚拟)
  private String Substation;
  
  //电压等级
  private String VoltageLevel;
  
  //名称
  private String Name;
  
  //所属容器(厂站、开闭所等)
  private String SubstationEntity;
  
  //起节点
  private String ConnectivityNodeI;
  
  //终节点
  private String ConnectivityNodeZ;
  
  //设备型号
  private String Model;
  
  //开关类型
  private Integer BreakerType;
  
  //停运设备
  private Integer ConstOpen;
  
  //设备运行状态
  private Integer Status;
  
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
  
  //操作成功率
  private Double ri_RSwitch;
  
  //操作时间(小时/次)
  private Double ri_TSwitch;
  
  //延时时间(负荷开关/重合器)
  private Double ri_Tdelay;
  
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
  
  //投资费用(万/台)
  private Double ei_Invest;
  
  //单相接地频率(次/年)
  private Double vd_RScc1;
  
  //相间短路频率(次/年)
  private Double vd_RScc2;
  
  //三相短路频率(次/年)
  private Double vd_RScc3;
  
  //两相接地频率(次/年)
  private Double vd_RScc4;
  
  //电岛
  private Integer Island;
  
  //短路电流(安培)
  private Double scc;
  
  //N-1通过情况
  private Integer sa_Result;
  
  //N-1形成孤岛
  private Integer sa_Island;
  
  //N-1负荷损失(兆伏安)
  private Double sa_Failure;
  
  //N-1设备负荷损失(兆瓦)
  private Double sa_Outages;
  
  //起节点索引
  private Integer NodeIPtr;
  
  //终节点索引
  private Integer NodeJPtr;
  
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
    
  public String getSubstationEntity()
  {
    return SubstationEntity;
  }
    
  public void setSubstationEntity(String SubstationEntity)
  {
    this.SubstationEntity = SubstationEntity;
  }
    
  public String getConnectivityNodeI()
  {
    return ConnectivityNodeI;
  }
    
  public void setConnectivityNodeI(String ConnectivityNodeI)
  {
    this.ConnectivityNodeI = ConnectivityNodeI;
  }
    
  public String getConnectivityNodeZ()
  {
    return ConnectivityNodeZ;
  }
    
  public void setConnectivityNodeZ(String ConnectivityNodeZ)
  {
    this.ConnectivityNodeZ = ConnectivityNodeZ;
  }
    
  public String getModel()
  {
    return Model;
  }
    
  public void setModel(String Model)
  {
    this.Model = Model;
  }
    
  public Integer getBreakerType()
  {
    return BreakerType;
  }
    
  public void setBreakerType(Integer BreakerType)
  {
    this.BreakerType = BreakerType;
  }
    
  public Integer getConstOpen()
  {
    return ConstOpen;
  }
    
  public void setConstOpen(Integer ConstOpen)
  {
    this.ConstOpen = ConstOpen;
  }
    
  public Integer getStatus()
  {
    return Status;
  }
    
  public void setStatus(Integer Status)
  {
    this.Status = Status;
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
    
  public Integer getIsland()
  {
    return Island;
  }
    
  public void setIsland(Integer Island)
  {
    this.Island = Island;
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
    
  public String toString()
  {
    return "DistributionBreaker ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", SubstationEntity = " + SubstationEntity
	 + ", ConnectivityNodeI = " + ConnectivityNodeI
	 + ", ConnectivityNodeZ = " + ConnectivityNodeZ
	 + ", Model = " + Model
	 + ", BreakerType = " + BreakerType
	 + ", ConstOpen = " + ConstOpen
	 + ", Status = " + Status
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ri_RSwitch = " + ri_RSwitch
	 + ", ri_TSwitch = " + ri_TSwitch
	 + ", ri_Tdelay = " + ri_Tdelay
	 + ", ri_Customer = " + ri_Customer
	 + ", ri_Load_Rerr = " + ri_Load_Rerr
	 + ", ri_Load_Trep = " + ri_Load_Trep
	 + ", ri_Load_Rchk = " + ri_Load_Rchk
	 + ", ri_Load_Tchk = " + ri_Load_Tchk
	 + ", ei_Invest = " + ei_Invest
	 + ", vd_RScc1 = " + vd_RScc1
	 + ", vd_RScc2 = " + vd_RScc2
	 + ", vd_RScc3 = " + vd_RScc3
	 + ", vd_RScc4 = " + vd_RScc4
	 + ", Island = " + Island
	 + ", scc = " + scc
	 + ", sa_Result = " + sa_Result
	 + ", sa_Island = " + sa_Island
	 + ", sa_Failure = " + sa_Failure
	 + ", sa_Outages = " + sa_Outages
	 + ", NodeIPtr = " + NodeIPtr
	 + ", NodeJPtr = " + NodeJPtr+"]";
  }
    
}
    
