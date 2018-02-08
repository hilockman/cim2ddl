package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电动汽车充(换)电站	*
***********************/
public class EVStation  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源ID
  private String ResourceID;
  
  //电压等级
  private String VoltageLevel;
  
  //名称
  private String Name;
  
  //充/换电站类型
  private Integer StationType;
  
  //地块类型
  private Integer LandType;
  
  //服务群体
  private Integer ServiceGroup;
  
  //额定容量(kVA)
  private Double RateCapacity;
  
  //设计日均访问次数(辆)
  private Integer RatedDailyVisitor;
  
  //受控
  private Integer UnderControl;
  
  //节点
  private String ConnectivityNode;
  
  //所属容器(厂站、开闭所等)
  private String SubstationEntity;
  
  //充电桩型号
  private String PileModel;
  
  //充电桩台数
  private Integer PileNumber;
  
  //电池库存数
  private Integer BatteryStock;
  
  //平均电池容量(kWh)
  private Double BatteryCapacity;
  
  //平均充电功率(kW)
  private Double BatteryPower;
  
  //充电效率
  private Double ChargeEfficiency;
  
  //充电功率因数
  private Double ChargeFactor;
  
  //设备费用(万元/台.块)
  private Double ei_Invest;
  
  //配套设备费用(万元)
  private Double ei_AuxInvest;
  
  //购地费用(万元)
  private Double ei_LandInvest;
  
  //每次固定停电损失(万元/次)
  private Double ei_constloss;
  
  //单位电能停电损失
  private Double ei_evalratio;
  
  //负荷(MW)
  private Double LoadP;
  
  //负荷功率因数
  private Double LoadFactor;
  
  //电压(kV)
  private Double v;
  
  //功角(度)
  private Double d;
  
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
  
  //最大总充电负荷
  private Double MaxChargeLoad;
  
  //平均负载率
  private Double AverageLoadRatio;
  
  //日均实际服务车次
  private Integer DailyChargeNumber;
  
  //日均服务率
  private Double DailyServiceRatio;
  
  //日均充电能量
  private Double DailyChargeEnergy;
  
  //日均能量供给率
  private Double DailyEnergySupply;
  
  //功率越限概率
  private Double ro_rOverLimit;
  
  //最大功率越限幅度
  private Double ro_tOverLimit;
  
  //电岛
  private Integer Island;
  
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
    
  public Integer getStationType()
  {
    return StationType;
  }
    
  public void setStationType(Integer StationType)
  {
    this.StationType = StationType;
  }
    
  public Integer getLandType()
  {
    return LandType;
  }
    
  public void setLandType(Integer LandType)
  {
    this.LandType = LandType;
  }
    
  public Integer getServiceGroup()
  {
    return ServiceGroup;
  }
    
  public void setServiceGroup(Integer ServiceGroup)
  {
    this.ServiceGroup = ServiceGroup;
  }
    
  public Double getRateCapacity()
  {
    return RateCapacity;
  }
    
  public void setRateCapacity(Double RateCapacity)
  {
    this.RateCapacity = RateCapacity;
  }
    
  public Integer getRatedDailyVisitor()
  {
    return RatedDailyVisitor;
  }
    
  public void setRatedDailyVisitor(Integer RatedDailyVisitor)
  {
    this.RatedDailyVisitor = RatedDailyVisitor;
  }
    
  public Integer getUnderControl()
  {
    return UnderControl;
  }
    
  public void setUnderControl(Integer UnderControl)
  {
    this.UnderControl = UnderControl;
  }
    
  public String getConnectivityNode()
  {
    return ConnectivityNode;
  }
    
  public void setConnectivityNode(String ConnectivityNode)
  {
    this.ConnectivityNode = ConnectivityNode;
  }
    
  public String getSubstationEntity()
  {
    return SubstationEntity;
  }
    
  public void setSubstationEntity(String SubstationEntity)
  {
    this.SubstationEntity = SubstationEntity;
  }
    
  public String getPileModel()
  {
    return PileModel;
  }
    
  public void setPileModel(String PileModel)
  {
    this.PileModel = PileModel;
  }
    
  public Integer getPileNumber()
  {
    return PileNumber;
  }
    
  public void setPileNumber(Integer PileNumber)
  {
    this.PileNumber = PileNumber;
  }
    
  public Integer getBatteryStock()
  {
    return BatteryStock;
  }
    
  public void setBatteryStock(Integer BatteryStock)
  {
    this.BatteryStock = BatteryStock;
  }
    
  public Double getBatteryCapacity()
  {
    return BatteryCapacity;
  }
    
  public void setBatteryCapacity(Double BatteryCapacity)
  {
    this.BatteryCapacity = BatteryCapacity;
  }
    
  public Double getBatteryPower()
  {
    return BatteryPower;
  }
    
  public void setBatteryPower(Double BatteryPower)
  {
    this.BatteryPower = BatteryPower;
  }
    
  public Double getChargeEfficiency()
  {
    return ChargeEfficiency;
  }
    
  public void setChargeEfficiency(Double ChargeEfficiency)
  {
    this.ChargeEfficiency = ChargeEfficiency;
  }
    
  public Double getChargeFactor()
  {
    return ChargeFactor;
  }
    
  public void setChargeFactor(Double ChargeFactor)
  {
    this.ChargeFactor = ChargeFactor;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Double getei_AuxInvest()
  {
    return ei_AuxInvest;
  }
    
  public void setei_AuxInvest(Double ei_AuxInvest)
  {
    this.ei_AuxInvest = ei_AuxInvest;
  }
    
  public Double getei_LandInvest()
  {
    return ei_LandInvest;
  }
    
  public void setei_LandInvest(Double ei_LandInvest)
  {
    this.ei_LandInvest = ei_LandInvest;
  }
    
  public Double getei_constloss()
  {
    return ei_constloss;
  }
    
  public void setei_constloss(Double ei_constloss)
  {
    this.ei_constloss = ei_constloss;
  }
    
  public Double getei_evalratio()
  {
    return ei_evalratio;
  }
    
  public void setei_evalratio(Double ei_evalratio)
  {
    this.ei_evalratio = ei_evalratio;
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
    
  public Double getv()
  {
    return v;
  }
    
  public void setv(Double v)
  {
    this.v = v;
  }
    
  public Double getd()
  {
    return d;
  }
    
  public void setd(Double d)
  {
    this.d = d;
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
    
  public Double getMaxChargeLoad()
  {
    return MaxChargeLoad;
  }
    
  public void setMaxChargeLoad(Double MaxChargeLoad)
  {
    this.MaxChargeLoad = MaxChargeLoad;
  }
    
  public Double getAverageLoadRatio()
  {
    return AverageLoadRatio;
  }
    
  public void setAverageLoadRatio(Double AverageLoadRatio)
  {
    this.AverageLoadRatio = AverageLoadRatio;
  }
    
  public Integer getDailyChargeNumber()
  {
    return DailyChargeNumber;
  }
    
  public void setDailyChargeNumber(Integer DailyChargeNumber)
  {
    this.DailyChargeNumber = DailyChargeNumber;
  }
    
  public Double getDailyServiceRatio()
  {
    return DailyServiceRatio;
  }
    
  public void setDailyServiceRatio(Double DailyServiceRatio)
  {
    this.DailyServiceRatio = DailyServiceRatio;
  }
    
  public Double getDailyChargeEnergy()
  {
    return DailyChargeEnergy;
  }
    
  public void setDailyChargeEnergy(Double DailyChargeEnergy)
  {
    this.DailyChargeEnergy = DailyChargeEnergy;
  }
    
  public Double getDailyEnergySupply()
  {
    return DailyEnergySupply;
  }
    
  public void setDailyEnergySupply(Double DailyEnergySupply)
  {
    this.DailyEnergySupply = DailyEnergySupply;
  }
    
  public Double getro_rOverLimit()
  {
    return ro_rOverLimit;
  }
    
  public void setro_rOverLimit(Double ro_rOverLimit)
  {
    this.ro_rOverLimit = ro_rOverLimit;
  }
    
  public Double getro_tOverLimit()
  {
    return ro_tOverLimit;
  }
    
  public void setro_tOverLimit(Double ro_tOverLimit)
  {
    this.ro_tOverLimit = ro_tOverLimit;
  }
    
  public Integer getIsland()
  {
    return Island;
  }
    
  public void setIsland(Integer Island)
  {
    this.Island = Island;
  }
    
  public String toString()
  {
    return "EVStation ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", StationType = " + StationType
	 + ", LandType = " + LandType
	 + ", ServiceGroup = " + ServiceGroup
	 + ", RateCapacity = " + RateCapacity
	 + ", RatedDailyVisitor = " + RatedDailyVisitor
	 + ", UnderControl = " + UnderControl
	 + ", ConnectivityNode = " + ConnectivityNode
	 + ", SubstationEntity = " + SubstationEntity
	 + ", PileModel = " + PileModel
	 + ", PileNumber = " + PileNumber
	 + ", BatteryStock = " + BatteryStock
	 + ", BatteryCapacity = " + BatteryCapacity
	 + ", BatteryPower = " + BatteryPower
	 + ", ChargeEfficiency = " + ChargeEfficiency
	 + ", ChargeFactor = " + ChargeFactor
	 + ", ei_Invest = " + ei_Invest
	 + ", ei_AuxInvest = " + ei_AuxInvest
	 + ", ei_LandInvest = " + ei_LandInvest
	 + ", ei_constloss = " + ei_constloss
	 + ", ei_evalratio = " + ei_evalratio
	 + ", LoadP = " + LoadP
	 + ", LoadFactor = " + LoadFactor
	 + ", v = " + v
	 + ", d = " + d
	 + ", eo_loss = " + eo_loss
	 + ", scc = " + scc
	 + ", sa_Result = " + sa_Result
	 + ", sa_Island = " + sa_Island
	 + ", sa_Failure = " + sa_Failure
	 + ", sa_Outages = " + sa_Outages
	 + ", MaxChargeLoad = " + MaxChargeLoad
	 + ", AverageLoadRatio = " + AverageLoadRatio
	 + ", DailyChargeNumber = " + DailyChargeNumber
	 + ", DailyServiceRatio = " + DailyServiceRatio
	 + ", DailyChargeEnergy = " + DailyChargeEnergy
	 + ", DailyEnergySupply = " + DailyEnergySupply
	 + ", ro_rOverLimit = " + ro_rOverLimit
	 + ", ro_tOverLimit = " + ro_tOverLimit
	 + ", Island = " + Island+"]";
  }
    
}
    
