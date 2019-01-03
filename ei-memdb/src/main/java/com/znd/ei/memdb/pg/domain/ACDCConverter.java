package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*交流直流变换器	*
***********************/
public class ACDCConverter  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //厂站
  private String Substation;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //交流电压等级
  private String VoltagelevelAC;
  
  //直流电压等级
  private String VoltagelevelDC;
  
  //所属电力电子变压器
  private String ElectronicTransformer;
  
  //隔离器
  private Integer Isolator;
  
  //交流节点
  private String ConnectivityNodeAC;
  
  //直流节点
  private String ConnectivityNodeDC;
  
  //额定容量(兆瓦)
  private Double RatedPower;
  
  //最小无功(兆乏)
  private Double MinQ;
  
  //最大无功(兆乏)
  private Double MaxQ;
  
  //直流侧控制模式
  private Integer DCControlMode;
  
  //直流侧控制值(电压标幺,功率兆瓦)
  private Double DCControlValue;
  
  //交流侧电压控制值(标幺)
  private Double ControlVac;
  
  //损耗多项式参数(a)
  private Double LossParamA;
  
  //损耗多项式参数(b)
  private Double LossParamB;
  
  //损耗多项式参数(c)
  private Double LossParamC;
  
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
  
  //供电方向
  private Integer ri_Direction;
  
  //投资费用(万元)
  private Double ei_Invest;
  
  //交流主接线可靠性设备类型
  private Integer MCRTypeAC;
  
  //直流主接线可靠性设备类型
  private Integer MCRTypeDC;
  
  //主接线可靠性源/荷功率
  private Double MCRPower;
  
  //交流电压(千伏)
  private Double Vac;
  
  //交流有功(兆瓦)
  private Double Pac;
  
  //交流无功(兆乏)
  private Double Qac;
  
  //交流电流(安培)
  private Double Aac;
  
  //直流电压(千伏)
  private Double Vdc;
  
  //直流有功(兆瓦)
  private Double Pdc;
  
  //直流电流(安培)
  private Double Adc;
  
  //损耗(兆瓦)
  private Double Loss;
  
  //停运率贡献(%)
  private Double ro_RContribution;
  
  //停运时间贡献(%)
  private Double ro_UContribution;
  
  //停电电量贡献(%)
  private Double ro_EnsContribution;
  
  //交流侧有功计算值(兆瓦)
  private Double CalculatePac;
  
  //交流侧无功计算值(兆乏)
  private Double CalculateQac;
  
  //交流电压等级索引
  private Integer VoltACPTR;
  
  //直流电压等级索引
  private Integer VoltDCPTR;
  
  //交流节点索引
  private Integer NodeACPTR;
  
  //直流节点索引
  private Integer NodeDCPTR;
  
  //交流拓扑节点
  private Integer TopoBusAC;
  
  //直流拓扑节点
  private Integer TopoBusDC;
  
  //交流侧电岛
  private Integer IslandAC;
  
  //直流侧电岛
  private Integer IslandDC;
  
  //交流边设备索引
  private Integer EdgeAC;
  
  //直流边设备索引
  private Integer EdgeDC;
  
  //交流侧功率状态
  private Integer PStateAC;
  
  //直流侧功率状态
  private Integer PStateDC;
  
  //类型
  private Integer Type;
  
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
    
  public String getSubstation()
  {
    return Substation;
  }
    
  public void setSubstation(String Substation)
  {
    this.Substation = Substation;
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
    
  public String getVoltagelevelAC()
  {
    return VoltagelevelAC;
  }
    
  public void setVoltagelevelAC(String VoltagelevelAC)
  {
    this.VoltagelevelAC = VoltagelevelAC;
  }
    
  public String getVoltagelevelDC()
  {
    return VoltagelevelDC;
  }
    
  public void setVoltagelevelDC(String VoltagelevelDC)
  {
    this.VoltagelevelDC = VoltagelevelDC;
  }
    
  public String getElectronicTransformer()
  {
    return ElectronicTransformer;
  }
    
  public void setElectronicTransformer(String ElectronicTransformer)
  {
    this.ElectronicTransformer = ElectronicTransformer;
  }
    
  public Integer getIsolator()
  {
    return Isolator;
  }
    
  public void setIsolator(Integer Isolator)
  {
    this.Isolator = Isolator;
  }
    
  public String getConnectivityNodeAC()
  {
    return ConnectivityNodeAC;
  }
    
  public void setConnectivityNodeAC(String ConnectivityNodeAC)
  {
    this.ConnectivityNodeAC = ConnectivityNodeAC;
  }
    
  public String getConnectivityNodeDC()
  {
    return ConnectivityNodeDC;
  }
    
  public void setConnectivityNodeDC(String ConnectivityNodeDC)
  {
    this.ConnectivityNodeDC = ConnectivityNodeDC;
  }
    
  public Double getRatedPower()
  {
    return RatedPower;
  }
    
  public void setRatedPower(Double RatedPower)
  {
    this.RatedPower = RatedPower;
  }
    
  public Double getMinQ()
  {
    return MinQ;
  }
    
  public void setMinQ(Double MinQ)
  {
    this.MinQ = MinQ;
  }
    
  public Double getMaxQ()
  {
    return MaxQ;
  }
    
  public void setMaxQ(Double MaxQ)
  {
    this.MaxQ = MaxQ;
  }
    
  public Integer getDCControlMode()
  {
    return DCControlMode;
  }
    
  public void setDCControlMode(Integer DCControlMode)
  {
    this.DCControlMode = DCControlMode;
  }
    
  public Double getDCControlValue()
  {
    return DCControlValue;
  }
    
  public void setDCControlValue(Double DCControlValue)
  {
    this.DCControlValue = DCControlValue;
  }
    
  public Double getControlVac()
  {
    return ControlVac;
  }
    
  public void setControlVac(Double ControlVac)
  {
    this.ControlVac = ControlVac;
  }
    
  public Double getLossParamA()
  {
    return LossParamA;
  }
    
  public void setLossParamA(Double LossParamA)
  {
    this.LossParamA = LossParamA;
  }
    
  public Double getLossParamB()
  {
    return LossParamB;
  }
    
  public void setLossParamB(Double LossParamB)
  {
    this.LossParamB = LossParamB;
  }
    
  public Double getLossParamC()
  {
    return LossParamC;
  }
    
  public void setLossParamC(Double LossParamC)
  {
    this.LossParamC = LossParamC;
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
    
  public Integer getri_Direction()
  {
    return ri_Direction;
  }
    
  public void setri_Direction(Integer ri_Direction)
  {
    this.ri_Direction = ri_Direction;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Integer getMCRTypeAC()
  {
    return MCRTypeAC;
  }
    
  public void setMCRTypeAC(Integer MCRTypeAC)
  {
    this.MCRTypeAC = MCRTypeAC;
  }
    
  public Integer getMCRTypeDC()
  {
    return MCRTypeDC;
  }
    
  public void setMCRTypeDC(Integer MCRTypeDC)
  {
    this.MCRTypeDC = MCRTypeDC;
  }
    
  public Double getMCRPower()
  {
    return MCRPower;
  }
    
  public void setMCRPower(Double MCRPower)
  {
    this.MCRPower = MCRPower;
  }
    
  public Double getVac()
  {
    return Vac;
  }
    
  public void setVac(Double Vac)
  {
    this.Vac = Vac;
  }
    
  public Double getPac()
  {
    return Pac;
  }
    
  public void setPac(Double Pac)
  {
    this.Pac = Pac;
  }
    
  public Double getQac()
  {
    return Qac;
  }
    
  public void setQac(Double Qac)
  {
    this.Qac = Qac;
  }
    
  public Double getAac()
  {
    return Aac;
  }
    
  public void setAac(Double Aac)
  {
    this.Aac = Aac;
  }
    
  public Double getVdc()
  {
    return Vdc;
  }
    
  public void setVdc(Double Vdc)
  {
    this.Vdc = Vdc;
  }
    
  public Double getPdc()
  {
    return Pdc;
  }
    
  public void setPdc(Double Pdc)
  {
    this.Pdc = Pdc;
  }
    
  public Double getAdc()
  {
    return Adc;
  }
    
  public void setAdc(Double Adc)
  {
    this.Adc = Adc;
  }
    
  public Double getLoss()
  {
    return Loss;
  }
    
  public void setLoss(Double Loss)
  {
    this.Loss = Loss;
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
    
  public Double getCalculatePac()
  {
    return CalculatePac;
  }
    
  public void setCalculatePac(Double CalculatePac)
  {
    this.CalculatePac = CalculatePac;
  }
    
  public Double getCalculateQac()
  {
    return CalculateQac;
  }
    
  public void setCalculateQac(Double CalculateQac)
  {
    this.CalculateQac = CalculateQac;
  }
    
  public Integer getVoltACPTR()
  {
    return VoltACPTR;
  }
    
  public void setVoltACPTR(Integer VoltACPTR)
  {
    this.VoltACPTR = VoltACPTR;
  }
    
  public Integer getVoltDCPTR()
  {
    return VoltDCPTR;
  }
    
  public void setVoltDCPTR(Integer VoltDCPTR)
  {
    this.VoltDCPTR = VoltDCPTR;
  }
    
  public Integer getNodeACPTR()
  {
    return NodeACPTR;
  }
    
  public void setNodeACPTR(Integer NodeACPTR)
  {
    this.NodeACPTR = NodeACPTR;
  }
    
  public Integer getNodeDCPTR()
  {
    return NodeDCPTR;
  }
    
  public void setNodeDCPTR(Integer NodeDCPTR)
  {
    this.NodeDCPTR = NodeDCPTR;
  }
    
  public Integer getTopoBusAC()
  {
    return TopoBusAC;
  }
    
  public void setTopoBusAC(Integer TopoBusAC)
  {
    this.TopoBusAC = TopoBusAC;
  }
    
  public Integer getTopoBusDC()
  {
    return TopoBusDC;
  }
    
  public void setTopoBusDC(Integer TopoBusDC)
  {
    this.TopoBusDC = TopoBusDC;
  }
    
  public Integer getIslandAC()
  {
    return IslandAC;
  }
    
  public void setIslandAC(Integer IslandAC)
  {
    this.IslandAC = IslandAC;
  }
    
  public Integer getIslandDC()
  {
    return IslandDC;
  }
    
  public void setIslandDC(Integer IslandDC)
  {
    this.IslandDC = IslandDC;
  }
    
  public Integer getEdgeAC()
  {
    return EdgeAC;
  }
    
  public void setEdgeAC(Integer EdgeAC)
  {
    this.EdgeAC = EdgeAC;
  }
    
  public Integer getEdgeDC()
  {
    return EdgeDC;
  }
    
  public void setEdgeDC(Integer EdgeDC)
  {
    this.EdgeDC = EdgeDC;
  }
    
  public Integer getPStateAC()
  {
    return PStateAC;
  }
    
  public void setPStateAC(Integer PStateAC)
  {
    this.PStateAC = PStateAC;
  }
    
  public Integer getPStateDC()
  {
    return PStateDC;
  }
    
  public void setPStateDC(Integer PStateDC)
  {
    this.PStateDC = PStateDC;
  }
    
  public Integer getType()
  {
    return Type;
  }
    
  public void setType(Integer Type)
  {
    this.Type = Type;
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
    return "ACDCConverter ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Substation = " + Substation
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", VoltagelevelAC = " + VoltagelevelAC
	 + ", VoltagelevelDC = " + VoltagelevelDC
	 + ", ElectronicTransformer = " + ElectronicTransformer
	 + ", Isolator = " + Isolator
	 + ", ConnectivityNodeAC = " + ConnectivityNodeAC
	 + ", ConnectivityNodeDC = " + ConnectivityNodeDC
	 + ", RatedPower = " + RatedPower
	 + ", MinQ = " + MinQ
	 + ", MaxQ = " + MaxQ
	 + ", DCControlMode = " + DCControlMode
	 + ", DCControlValue = " + DCControlValue
	 + ", ControlVac = " + ControlVac
	 + ", LossParamA = " + LossParamA
	 + ", LossParamB = " + LossParamB
	 + ", LossParamC = " + LossParamC
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ri_Direction = " + ri_Direction
	 + ", ei_Invest = " + ei_Invest
	 + ", MCRTypeAC = " + MCRTypeAC
	 + ", MCRTypeDC = " + MCRTypeDC
	 + ", MCRPower = " + MCRPower
	 + ", Vac = " + Vac
	 + ", Pac = " + Pac
	 + ", Qac = " + Qac
	 + ", Aac = " + Aac
	 + ", Vdc = " + Vdc
	 + ", Pdc = " + Pdc
	 + ", Adc = " + Adc
	 + ", Loss = " + Loss
	 + ", ro_RContribution = " + ro_RContribution
	 + ", ro_UContribution = " + ro_UContribution
	 + ", ro_EnsContribution = " + ro_EnsContribution
	 + ", CalculatePac = " + CalculatePac
	 + ", CalculateQac = " + CalculateQac
	 + ", VoltACPTR = " + VoltACPTR
	 + ", VoltDCPTR = " + VoltDCPTR
	 + ", NodeACPTR = " + NodeACPTR
	 + ", NodeDCPTR = " + NodeDCPTR
	 + ", TopoBusAC = " + TopoBusAC
	 + ", TopoBusDC = " + TopoBusDC
	 + ", IslandAC = " + IslandAC
	 + ", IslandDC = " + IslandDC
	 + ", EdgeAC = " + EdgeAC
	 + ", EdgeDC = " + EdgeDC
	 + ", PStateAC = " + PStateAC
	 + ", PStateDC = " + PStateDC
	 + ", Type = " + Type
	 + ", Open = " + Open
	 + ", Outage = " + Outage+"]";
  }
    
}
    
