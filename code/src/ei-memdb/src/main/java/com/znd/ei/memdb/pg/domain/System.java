package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*系统	*
***********************/
public class System  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //系统平衡机厂站
  private String stid;
  
  //系统平衡机发电机
  private String unid;
  
  //基准容量(MW)
  private Double BasePower;
  
  //日期
  private Integer RTDate;
  
  //时间
  private Integer RTTime;
  
  //单永故障比例(<1)
  private Double Sc1Ratio;
  
  //相间短路比例(<1)
  private Double Sc2Ratio;
  
  //三相短路比例(<1)
  private Double Sc3Ratio;
  
  //两相接地比例(<1)
  private Double Sc4Ratio;
  
  //投资总额(万元)
  private Double ei_Invest;
  
  //电力公司售每度电的收益(元/千瓦时)
  private Double ei_Sprice;
  
  //电力公司购网电价(元/千瓦时)
  private Double ei_Pprice;
  
  //名义年利率(<1)
  private Double ei_Iyrate;
  
  //计息周期(次/年)
  private Integer ei_Icycle;
  
  //银行贷款时间(年)
  private Integer ei_Credtime;
  
  //工程建设期(年)
  private Integer ei_Constime;
  
  //设备折旧期(年)
  private Integer ei_Deprectime;
  
  //保留残值(<1)
  private Double ei_Residual;
  
  //所得税税率(<1)
  private Double ei_Taxrate;
  
  //固定资产年维修费(%)
  private Double ei_Repairfee;
  
  //固定资产年保险费(%)
  private Double ei_Insurfee;
  
  //互感器误差系数(0.1)
  private Double Ker;
  
  //燃气转发电系数
  private Double G2EFactor;
  
  //电转热效率
  private Double E2HFactor;
  
  //电转冷效率
  private Double E2CFactor;
  
  //储能效率
  private Double EStorgeEfficiency;
  
  //总统计发电有功(MW)
  private Double TotalGenP;
  
  //总统计发电无功(MVar)
  private Double TotalGenQ;
  
  //总统计负荷有功(MW)
  private Double TotalLoadP;
  
  //总统计负荷无功(MVar)
  private Double TotalLoadQ;
  
  //总统计电容无功(MVar)
  private Double TotalCap;
  
  //总统计电抗无功(MVar)
  private Double TotalReac;
  
  //总运行发电有功(MW)
  private Double RunningGenP;
  
  //总运行发电无功(MVar)
  private Double RunningGenQ;
  
  //总运行负荷有功(MW)
  private Double RunningLoadP;
  
  //总运行负荷无功(MVar)
  private Double RunningLoadQ;
  
  //总运行电容无功(MVar)
  private Double RunningCap;
  
  //总运行电抗无功(MVar)
  private Double RunningReac;
  
  //总网损有功(MW)
  private Double LossP;
  
  //总网损无功(MVar)
  private Double LossQ;
  
  //线损率(%)
  private Double LossRate;
  
  //越限母线指标
  private Double BusOverLoadIndex;
  
  //越限母线数
  private Integer BusOverLoadNum;
  
  //越限线路指标
  private Double LineOverLoadIndex;
  
  //越限线路数
  private Integer LineOverLoadNum;
  
  //负载率大于80%线路数
  private Integer LineLoadRate100;
  
  //负载率(60~80]%线路数
  private Integer LineLoadRate80;
  
  //负载率(40~60]%线路数
  private Integer LineLoadRate60;
  
  //负载率(20~40]%线路数
  private Integer LineLoadRate40;
  
  //负载率小于等于20%线路数
  private Integer LineLoadRate20;
  
  //停运线路数
  private Integer LineLoadRate0;
  
  //越限主变指标
  private Double TranOverLoadIndex;
  
  //越限主变数
  private Integer TranOverLoadNum;
  
  //负载率大于80%主变数
  private Integer TranLoadRate100;
  
  //负载率(60~80]%主变数
  private Integer TranLoadRate80;
  
  //负载率(40~60]%主变数
  private Integer TranLoadRate60;
  
  //负载率(20~40]%主变数
  private Integer TranLoadRate40;
  
  //负载率小于等于20%主变数
  private Integer TranLoadRate20;
  
  //停运主变数
  private Integer TranLoadRate0;
  
  //死岛负荷有功
  private Double DeadIslandLoadP;
  
  //死岛负荷无功
  private Double DeadIslandLoadQ;
  
  //系统用户总数
  private Double ro_Customernum;
  
  //用户年停电次数(次/年)
  private Double ro_Aci;
  
  //用户年停电时间(小时/年)
  private Double ro_Cid;
  
  //系统年均停电次数(次/户.年)
  private Double ro_Saifi;
  
  //系统年均停电时间(小时/户.年)
  private Double ro_Saidi;
  
  //综合平均理论供电可用率
  private Double ro_Asai;
  
  //系统年均停电电量(MWh/年)
  private Double ro_Ens;
  
  //用户年均停电电量(MWh/户.年)
  private Double ro_AEns;
  
  //系统停电平均用户数(户/次)
  private Double ro_Mic;
  
  //系统停电平均持续时间(小时/次)
  private Double ro_Mid;
  
  //用户年故障停电次数(次/年)
  private Double ro_f_Aci;
  
  //用户年故障停电时间(小时/年)
  private Double ro_f_Cid;
  
  //系统年均故障停电次数(次/户.年)
  private Double ro_f_Saifi;
  
  //系统年均故障停电时间(小时/户.年)
  private Double ro_f_Saidi;
  
  //故障平均理论供电可用率
  private Double ro_f_Asai;
  
  //系统年均故障停电电量(MWh/年)
  private Double ro_f_Ens;
  
  //用户年均故障停电电量(MWh/户.年)
  private Double ro_f_AEns;
  
  //系统故障停电平均用户数(户/次)
  private Double ro_f_Mic;
  
  //系统故障停电平均持续时间(小时/次)
  private Double ro_f_Mid;
  
  //用户年预安排停电次数(次/年)
  private Double ro_a_Aci;
  
  //用户年预安排停电时间(小时/年)
  private Double ro_a_Cid;
  
  //系统年均预安排停电次数(次/户.年)
  private Double ro_a_Saifi;
  
  //系统年均预安排停电时间(小时/户.年)
  private Double ro_a_Saidi;
  
  //预安排平均理论供电可用率
  private Double ro_a_Asai;
  
  //系统年均预安排停电电量(MWh/年)
  private Double ro_a_Ens;
  
  //用户年均预安排停电电量(MWh/户.年)
  private Double ro_a_AEns;
  
  //系统预安排停电平均用户数(户/次)
  private Double ro_a_Mic;
  
  //系统预安排停电平均持续时间(小时/次)
  private Double ro_a_Mid;
  
  //供电电量(含线损,万度/年)
  private Double eo_EleSupply;
  
  //购电成本(万元/年)
  private Double eo_EleCost;
  
  //售电收益(万元/年)
  private Double eo_EleIncome;
  
  //最小回报系数
  private Double eo_RCoef;
  
  //线损成本(万元/年)
  private Double eo_LossCost;
  
  //可靠性成本(万元/年)
  private Double eo_ReliCost;
  
  //资金成本(万元/年)
  private Double eo_FundCost;
  
  //(投产还贷期)年最小收入(万元/年)
  private Double eo_Income;
  
  //考虑产电比停电损失(万元/年)
  private Double eo_ReliEVCost;
  
  //(投产还贷期)考虑产电比年最小收入(万元/年)
  private Double eo_EVIncome;
  
  //线路N-1通过率(%)
  private Double sa_LinePassRate;
  
  //线路N-1损失负荷(MW)
  private Double sa_LineLossPower;
  
  //单元设备N-1通过率(%)
  private Double sa_UnitPassRate;
  
  //单元设备N-1损失负荷(MW)
  private Double sa_UnitLossPower;
  
  //组合设备N-1通过率(%)
  private Double sa_CombPassRate;
  
  //组合设备N-1损失负荷(MW)
  private Double sa_CombLossPower;
  
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
    
  public String getDescription()
  {
    return Description;
  }
    
  public void setDescription(String Description)
  {
    this.Description = Description;
  }
    
  public String getstid()
  {
    return stid;
  }
    
  public void setstid(String stid)
  {
    this.stid = stid;
  }
    
  public String getunid()
  {
    return unid;
  }
    
  public void setunid(String unid)
  {
    this.unid = unid;
  }
    
  public Double getBasePower()
  {
    return BasePower;
  }
    
  public void setBasePower(Double BasePower)
  {
    this.BasePower = BasePower;
  }
    
  public Integer getRTDate()
  {
    return RTDate;
  }
    
  public void setRTDate(Integer RTDate)
  {
    this.RTDate = RTDate;
  }
    
  public Integer getRTTime()
  {
    return RTTime;
  }
    
  public void setRTTime(Integer RTTime)
  {
    this.RTTime = RTTime;
  }
    
  public Double getSc1Ratio()
  {
    return Sc1Ratio;
  }
    
  public void setSc1Ratio(Double Sc1Ratio)
  {
    this.Sc1Ratio = Sc1Ratio;
  }
    
  public Double getSc2Ratio()
  {
    return Sc2Ratio;
  }
    
  public void setSc2Ratio(Double Sc2Ratio)
  {
    this.Sc2Ratio = Sc2Ratio;
  }
    
  public Double getSc3Ratio()
  {
    return Sc3Ratio;
  }
    
  public void setSc3Ratio(Double Sc3Ratio)
  {
    this.Sc3Ratio = Sc3Ratio;
  }
    
  public Double getSc4Ratio()
  {
    return Sc4Ratio;
  }
    
  public void setSc4Ratio(Double Sc4Ratio)
  {
    this.Sc4Ratio = Sc4Ratio;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Double getei_Sprice()
  {
    return ei_Sprice;
  }
    
  public void setei_Sprice(Double ei_Sprice)
  {
    this.ei_Sprice = ei_Sprice;
  }
    
  public Double getei_Pprice()
  {
    return ei_Pprice;
  }
    
  public void setei_Pprice(Double ei_Pprice)
  {
    this.ei_Pprice = ei_Pprice;
  }
    
  public Double getei_Iyrate()
  {
    return ei_Iyrate;
  }
    
  public void setei_Iyrate(Double ei_Iyrate)
  {
    this.ei_Iyrate = ei_Iyrate;
  }
    
  public Integer getei_Icycle()
  {
    return ei_Icycle;
  }
    
  public void setei_Icycle(Integer ei_Icycle)
  {
    this.ei_Icycle = ei_Icycle;
  }
    
  public Integer getei_Credtime()
  {
    return ei_Credtime;
  }
    
  public void setei_Credtime(Integer ei_Credtime)
  {
    this.ei_Credtime = ei_Credtime;
  }
    
  public Integer getei_Constime()
  {
    return ei_Constime;
  }
    
  public void setei_Constime(Integer ei_Constime)
  {
    this.ei_Constime = ei_Constime;
  }
    
  public Integer getei_Deprectime()
  {
    return ei_Deprectime;
  }
    
  public void setei_Deprectime(Integer ei_Deprectime)
  {
    this.ei_Deprectime = ei_Deprectime;
  }
    
  public Double getei_Residual()
  {
    return ei_Residual;
  }
    
  public void setei_Residual(Double ei_Residual)
  {
    this.ei_Residual = ei_Residual;
  }
    
  public Double getei_Taxrate()
  {
    return ei_Taxrate;
  }
    
  public void setei_Taxrate(Double ei_Taxrate)
  {
    this.ei_Taxrate = ei_Taxrate;
  }
    
  public Double getei_Repairfee()
  {
    return ei_Repairfee;
  }
    
  public void setei_Repairfee(Double ei_Repairfee)
  {
    this.ei_Repairfee = ei_Repairfee;
  }
    
  public Double getei_Insurfee()
  {
    return ei_Insurfee;
  }
    
  public void setei_Insurfee(Double ei_Insurfee)
  {
    this.ei_Insurfee = ei_Insurfee;
  }
    
  public Double getKer()
  {
    return Ker;
  }
    
  public void setKer(Double Ker)
  {
    this.Ker = Ker;
  }
    
  public Double getG2EFactor()
  {
    return G2EFactor;
  }
    
  public void setG2EFactor(Double G2EFactor)
  {
    this.G2EFactor = G2EFactor;
  }
    
  public Double getE2HFactor()
  {
    return E2HFactor;
  }
    
  public void setE2HFactor(Double E2HFactor)
  {
    this.E2HFactor = E2HFactor;
  }
    
  public Double getE2CFactor()
  {
    return E2CFactor;
  }
    
  public void setE2CFactor(Double E2CFactor)
  {
    this.E2CFactor = E2CFactor;
  }
    
  public Double getEStorgeEfficiency()
  {
    return EStorgeEfficiency;
  }
    
  public void setEStorgeEfficiency(Double EStorgeEfficiency)
  {
    this.EStorgeEfficiency = EStorgeEfficiency;
  }
    
  public Double getTotalGenP()
  {
    return TotalGenP;
  }
    
  public void setTotalGenP(Double TotalGenP)
  {
    this.TotalGenP = TotalGenP;
  }
    
  public Double getTotalGenQ()
  {
    return TotalGenQ;
  }
    
  public void setTotalGenQ(Double TotalGenQ)
  {
    this.TotalGenQ = TotalGenQ;
  }
    
  public Double getTotalLoadP()
  {
    return TotalLoadP;
  }
    
  public void setTotalLoadP(Double TotalLoadP)
  {
    this.TotalLoadP = TotalLoadP;
  }
    
  public Double getTotalLoadQ()
  {
    return TotalLoadQ;
  }
    
  public void setTotalLoadQ(Double TotalLoadQ)
  {
    this.TotalLoadQ = TotalLoadQ;
  }
    
  public Double getTotalCap()
  {
    return TotalCap;
  }
    
  public void setTotalCap(Double TotalCap)
  {
    this.TotalCap = TotalCap;
  }
    
  public Double getTotalReac()
  {
    return TotalReac;
  }
    
  public void setTotalReac(Double TotalReac)
  {
    this.TotalReac = TotalReac;
  }
    
  public Double getRunningGenP()
  {
    return RunningGenP;
  }
    
  public void setRunningGenP(Double RunningGenP)
  {
    this.RunningGenP = RunningGenP;
  }
    
  public Double getRunningGenQ()
  {
    return RunningGenQ;
  }
    
  public void setRunningGenQ(Double RunningGenQ)
  {
    this.RunningGenQ = RunningGenQ;
  }
    
  public Double getRunningLoadP()
  {
    return RunningLoadP;
  }
    
  public void setRunningLoadP(Double RunningLoadP)
  {
    this.RunningLoadP = RunningLoadP;
  }
    
  public Double getRunningLoadQ()
  {
    return RunningLoadQ;
  }
    
  public void setRunningLoadQ(Double RunningLoadQ)
  {
    this.RunningLoadQ = RunningLoadQ;
  }
    
  public Double getRunningCap()
  {
    return RunningCap;
  }
    
  public void setRunningCap(Double RunningCap)
  {
    this.RunningCap = RunningCap;
  }
    
  public Double getRunningReac()
  {
    return RunningReac;
  }
    
  public void setRunningReac(Double RunningReac)
  {
    this.RunningReac = RunningReac;
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
    
  public Double getLossRate()
  {
    return LossRate;
  }
    
  public void setLossRate(Double LossRate)
  {
    this.LossRate = LossRate;
  }
    
  public Double getBusOverLoadIndex()
  {
    return BusOverLoadIndex;
  }
    
  public void setBusOverLoadIndex(Double BusOverLoadIndex)
  {
    this.BusOverLoadIndex = BusOverLoadIndex;
  }
    
  public Integer getBusOverLoadNum()
  {
    return BusOverLoadNum;
  }
    
  public void setBusOverLoadNum(Integer BusOverLoadNum)
  {
    this.BusOverLoadNum = BusOverLoadNum;
  }
    
  public Double getLineOverLoadIndex()
  {
    return LineOverLoadIndex;
  }
    
  public void setLineOverLoadIndex(Double LineOverLoadIndex)
  {
    this.LineOverLoadIndex = LineOverLoadIndex;
  }
    
  public Integer getLineOverLoadNum()
  {
    return LineOverLoadNum;
  }
    
  public void setLineOverLoadNum(Integer LineOverLoadNum)
  {
    this.LineOverLoadNum = LineOverLoadNum;
  }
    
  public Integer getLineLoadRate100()
  {
    return LineLoadRate100;
  }
    
  public void setLineLoadRate100(Integer LineLoadRate100)
  {
    this.LineLoadRate100 = LineLoadRate100;
  }
    
  public Integer getLineLoadRate80()
  {
    return LineLoadRate80;
  }
    
  public void setLineLoadRate80(Integer LineLoadRate80)
  {
    this.LineLoadRate80 = LineLoadRate80;
  }
    
  public Integer getLineLoadRate60()
  {
    return LineLoadRate60;
  }
    
  public void setLineLoadRate60(Integer LineLoadRate60)
  {
    this.LineLoadRate60 = LineLoadRate60;
  }
    
  public Integer getLineLoadRate40()
  {
    return LineLoadRate40;
  }
    
  public void setLineLoadRate40(Integer LineLoadRate40)
  {
    this.LineLoadRate40 = LineLoadRate40;
  }
    
  public Integer getLineLoadRate20()
  {
    return LineLoadRate20;
  }
    
  public void setLineLoadRate20(Integer LineLoadRate20)
  {
    this.LineLoadRate20 = LineLoadRate20;
  }
    
  public Integer getLineLoadRate0()
  {
    return LineLoadRate0;
  }
    
  public void setLineLoadRate0(Integer LineLoadRate0)
  {
    this.LineLoadRate0 = LineLoadRate0;
  }
    
  public Double getTranOverLoadIndex()
  {
    return TranOverLoadIndex;
  }
    
  public void setTranOverLoadIndex(Double TranOverLoadIndex)
  {
    this.TranOverLoadIndex = TranOverLoadIndex;
  }
    
  public Integer getTranOverLoadNum()
  {
    return TranOverLoadNum;
  }
    
  public void setTranOverLoadNum(Integer TranOverLoadNum)
  {
    this.TranOverLoadNum = TranOverLoadNum;
  }
    
  public Integer getTranLoadRate100()
  {
    return TranLoadRate100;
  }
    
  public void setTranLoadRate100(Integer TranLoadRate100)
  {
    this.TranLoadRate100 = TranLoadRate100;
  }
    
  public Integer getTranLoadRate80()
  {
    return TranLoadRate80;
  }
    
  public void setTranLoadRate80(Integer TranLoadRate80)
  {
    this.TranLoadRate80 = TranLoadRate80;
  }
    
  public Integer getTranLoadRate60()
  {
    return TranLoadRate60;
  }
    
  public void setTranLoadRate60(Integer TranLoadRate60)
  {
    this.TranLoadRate60 = TranLoadRate60;
  }
    
  public Integer getTranLoadRate40()
  {
    return TranLoadRate40;
  }
    
  public void setTranLoadRate40(Integer TranLoadRate40)
  {
    this.TranLoadRate40 = TranLoadRate40;
  }
    
  public Integer getTranLoadRate20()
  {
    return TranLoadRate20;
  }
    
  public void setTranLoadRate20(Integer TranLoadRate20)
  {
    this.TranLoadRate20 = TranLoadRate20;
  }
    
  public Integer getTranLoadRate0()
  {
    return TranLoadRate0;
  }
    
  public void setTranLoadRate0(Integer TranLoadRate0)
  {
    this.TranLoadRate0 = TranLoadRate0;
  }
    
  public Double getDeadIslandLoadP()
  {
    return DeadIslandLoadP;
  }
    
  public void setDeadIslandLoadP(Double DeadIslandLoadP)
  {
    this.DeadIslandLoadP = DeadIslandLoadP;
  }
    
  public Double getDeadIslandLoadQ()
  {
    return DeadIslandLoadQ;
  }
    
  public void setDeadIslandLoadQ(Double DeadIslandLoadQ)
  {
    this.DeadIslandLoadQ = DeadIslandLoadQ;
  }
    
  public Double getro_Customernum()
  {
    return ro_Customernum;
  }
    
  public void setro_Customernum(Double ro_Customernum)
  {
    this.ro_Customernum = ro_Customernum;
  }
    
  public Double getro_Aci()
  {
    return ro_Aci;
  }
    
  public void setro_Aci(Double ro_Aci)
  {
    this.ro_Aci = ro_Aci;
  }
    
  public Double getro_Cid()
  {
    return ro_Cid;
  }
    
  public void setro_Cid(Double ro_Cid)
  {
    this.ro_Cid = ro_Cid;
  }
    
  public Double getro_Saifi()
  {
    return ro_Saifi;
  }
    
  public void setro_Saifi(Double ro_Saifi)
  {
    this.ro_Saifi = ro_Saifi;
  }
    
  public Double getro_Saidi()
  {
    return ro_Saidi;
  }
    
  public void setro_Saidi(Double ro_Saidi)
  {
    this.ro_Saidi = ro_Saidi;
  }
    
  public Double getro_Asai()
  {
    return ro_Asai;
  }
    
  public void setro_Asai(Double ro_Asai)
  {
    this.ro_Asai = ro_Asai;
  }
    
  public Double getro_Ens()
  {
    return ro_Ens;
  }
    
  public void setro_Ens(Double ro_Ens)
  {
    this.ro_Ens = ro_Ens;
  }
    
  public Double getro_AEns()
  {
    return ro_AEns;
  }
    
  public void setro_AEns(Double ro_AEns)
  {
    this.ro_AEns = ro_AEns;
  }
    
  public Double getro_Mic()
  {
    return ro_Mic;
  }
    
  public void setro_Mic(Double ro_Mic)
  {
    this.ro_Mic = ro_Mic;
  }
    
  public Double getro_Mid()
  {
    return ro_Mid;
  }
    
  public void setro_Mid(Double ro_Mid)
  {
    this.ro_Mid = ro_Mid;
  }
    
  public Double getro_f_Aci()
  {
    return ro_f_Aci;
  }
    
  public void setro_f_Aci(Double ro_f_Aci)
  {
    this.ro_f_Aci = ro_f_Aci;
  }
    
  public Double getro_f_Cid()
  {
    return ro_f_Cid;
  }
    
  public void setro_f_Cid(Double ro_f_Cid)
  {
    this.ro_f_Cid = ro_f_Cid;
  }
    
  public Double getro_f_Saifi()
  {
    return ro_f_Saifi;
  }
    
  public void setro_f_Saifi(Double ro_f_Saifi)
  {
    this.ro_f_Saifi = ro_f_Saifi;
  }
    
  public Double getro_f_Saidi()
  {
    return ro_f_Saidi;
  }
    
  public void setro_f_Saidi(Double ro_f_Saidi)
  {
    this.ro_f_Saidi = ro_f_Saidi;
  }
    
  public Double getro_f_Asai()
  {
    return ro_f_Asai;
  }
    
  public void setro_f_Asai(Double ro_f_Asai)
  {
    this.ro_f_Asai = ro_f_Asai;
  }
    
  public Double getro_f_Ens()
  {
    return ro_f_Ens;
  }
    
  public void setro_f_Ens(Double ro_f_Ens)
  {
    this.ro_f_Ens = ro_f_Ens;
  }
    
  public Double getro_f_AEns()
  {
    return ro_f_AEns;
  }
    
  public void setro_f_AEns(Double ro_f_AEns)
  {
    this.ro_f_AEns = ro_f_AEns;
  }
    
  public Double getro_f_Mic()
  {
    return ro_f_Mic;
  }
    
  public void setro_f_Mic(Double ro_f_Mic)
  {
    this.ro_f_Mic = ro_f_Mic;
  }
    
  public Double getro_f_Mid()
  {
    return ro_f_Mid;
  }
    
  public void setro_f_Mid(Double ro_f_Mid)
  {
    this.ro_f_Mid = ro_f_Mid;
  }
    
  public Double getro_a_Aci()
  {
    return ro_a_Aci;
  }
    
  public void setro_a_Aci(Double ro_a_Aci)
  {
    this.ro_a_Aci = ro_a_Aci;
  }
    
  public Double getro_a_Cid()
  {
    return ro_a_Cid;
  }
    
  public void setro_a_Cid(Double ro_a_Cid)
  {
    this.ro_a_Cid = ro_a_Cid;
  }
    
  public Double getro_a_Saifi()
  {
    return ro_a_Saifi;
  }
    
  public void setro_a_Saifi(Double ro_a_Saifi)
  {
    this.ro_a_Saifi = ro_a_Saifi;
  }
    
  public Double getro_a_Saidi()
  {
    return ro_a_Saidi;
  }
    
  public void setro_a_Saidi(Double ro_a_Saidi)
  {
    this.ro_a_Saidi = ro_a_Saidi;
  }
    
  public Double getro_a_Asai()
  {
    return ro_a_Asai;
  }
    
  public void setro_a_Asai(Double ro_a_Asai)
  {
    this.ro_a_Asai = ro_a_Asai;
  }
    
  public Double getro_a_Ens()
  {
    return ro_a_Ens;
  }
    
  public void setro_a_Ens(Double ro_a_Ens)
  {
    this.ro_a_Ens = ro_a_Ens;
  }
    
  public Double getro_a_AEns()
  {
    return ro_a_AEns;
  }
    
  public void setro_a_AEns(Double ro_a_AEns)
  {
    this.ro_a_AEns = ro_a_AEns;
  }
    
  public Double getro_a_Mic()
  {
    return ro_a_Mic;
  }
    
  public void setro_a_Mic(Double ro_a_Mic)
  {
    this.ro_a_Mic = ro_a_Mic;
  }
    
  public Double getro_a_Mid()
  {
    return ro_a_Mid;
  }
    
  public void setro_a_Mid(Double ro_a_Mid)
  {
    this.ro_a_Mid = ro_a_Mid;
  }
    
  public Double geteo_EleSupply()
  {
    return eo_EleSupply;
  }
    
  public void seteo_EleSupply(Double eo_EleSupply)
  {
    this.eo_EleSupply = eo_EleSupply;
  }
    
  public Double geteo_EleCost()
  {
    return eo_EleCost;
  }
    
  public void seteo_EleCost(Double eo_EleCost)
  {
    this.eo_EleCost = eo_EleCost;
  }
    
  public Double geteo_EleIncome()
  {
    return eo_EleIncome;
  }
    
  public void seteo_EleIncome(Double eo_EleIncome)
  {
    this.eo_EleIncome = eo_EleIncome;
  }
    
  public Double geteo_RCoef()
  {
    return eo_RCoef;
  }
    
  public void seteo_RCoef(Double eo_RCoef)
  {
    this.eo_RCoef = eo_RCoef;
  }
    
  public Double geteo_LossCost()
  {
    return eo_LossCost;
  }
    
  public void seteo_LossCost(Double eo_LossCost)
  {
    this.eo_LossCost = eo_LossCost;
  }
    
  public Double geteo_ReliCost()
  {
    return eo_ReliCost;
  }
    
  public void seteo_ReliCost(Double eo_ReliCost)
  {
    this.eo_ReliCost = eo_ReliCost;
  }
    
  public Double geteo_FundCost()
  {
    return eo_FundCost;
  }
    
  public void seteo_FundCost(Double eo_FundCost)
  {
    this.eo_FundCost = eo_FundCost;
  }
    
  public Double geteo_Income()
  {
    return eo_Income;
  }
    
  public void seteo_Income(Double eo_Income)
  {
    this.eo_Income = eo_Income;
  }
    
  public Double geteo_ReliEVCost()
  {
    return eo_ReliEVCost;
  }
    
  public void seteo_ReliEVCost(Double eo_ReliEVCost)
  {
    this.eo_ReliEVCost = eo_ReliEVCost;
  }
    
  public Double geteo_EVIncome()
  {
    return eo_EVIncome;
  }
    
  public void seteo_EVIncome(Double eo_EVIncome)
  {
    this.eo_EVIncome = eo_EVIncome;
  }
    
  public Double getsa_LinePassRate()
  {
    return sa_LinePassRate;
  }
    
  public void setsa_LinePassRate(Double sa_LinePassRate)
  {
    this.sa_LinePassRate = sa_LinePassRate;
  }
    
  public Double getsa_LineLossPower()
  {
    return sa_LineLossPower;
  }
    
  public void setsa_LineLossPower(Double sa_LineLossPower)
  {
    this.sa_LineLossPower = sa_LineLossPower;
  }
    
  public Double getsa_UnitPassRate()
  {
    return sa_UnitPassRate;
  }
    
  public void setsa_UnitPassRate(Double sa_UnitPassRate)
  {
    this.sa_UnitPassRate = sa_UnitPassRate;
  }
    
  public Double getsa_UnitLossPower()
  {
    return sa_UnitLossPower;
  }
    
  public void setsa_UnitLossPower(Double sa_UnitLossPower)
  {
    this.sa_UnitLossPower = sa_UnitLossPower;
  }
    
  public Double getsa_CombPassRate()
  {
    return sa_CombPassRate;
  }
    
  public void setsa_CombPassRate(Double sa_CombPassRate)
  {
    this.sa_CombPassRate = sa_CombPassRate;
  }
    
  public Double getsa_CombLossPower()
  {
    return sa_CombLossPower;
  }
    
  public void setsa_CombLossPower(Double sa_CombLossPower)
  {
    this.sa_CombLossPower = sa_CombLossPower;
  }
    
  public String toString()
  {
    return "System ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", stid = " + stid
	 + ", unid = " + unid
	 + ", BasePower = " + BasePower
	 + ", RTDate = " + RTDate
	 + ", RTTime = " + RTTime
	 + ", Sc1Ratio = " + Sc1Ratio
	 + ", Sc2Ratio = " + Sc2Ratio
	 + ", Sc3Ratio = " + Sc3Ratio
	 + ", Sc4Ratio = " + Sc4Ratio
	 + ", ei_Invest = " + ei_Invest
	 + ", ei_Sprice = " + ei_Sprice
	 + ", ei_Pprice = " + ei_Pprice
	 + ", ei_Iyrate = " + ei_Iyrate
	 + ", ei_Icycle = " + ei_Icycle
	 + ", ei_Credtime = " + ei_Credtime
	 + ", ei_Constime = " + ei_Constime
	 + ", ei_Deprectime = " + ei_Deprectime
	 + ", ei_Residual = " + ei_Residual
	 + ", ei_Taxrate = " + ei_Taxrate
	 + ", ei_Repairfee = " + ei_Repairfee
	 + ", ei_Insurfee = " + ei_Insurfee
	 + ", Ker = " + Ker
	 + ", G2EFactor = " + G2EFactor
	 + ", E2HFactor = " + E2HFactor
	 + ", E2CFactor = " + E2CFactor
	 + ", EStorgeEfficiency = " + EStorgeEfficiency
	 + ", TotalGenP = " + TotalGenP
	 + ", TotalGenQ = " + TotalGenQ
	 + ", TotalLoadP = " + TotalLoadP
	 + ", TotalLoadQ = " + TotalLoadQ
	 + ", TotalCap = " + TotalCap
	 + ", TotalReac = " + TotalReac
	 + ", RunningGenP = " + RunningGenP
	 + ", RunningGenQ = " + RunningGenQ
	 + ", RunningLoadP = " + RunningLoadP
	 + ", RunningLoadQ = " + RunningLoadQ
	 + ", RunningCap = " + RunningCap
	 + ", RunningReac = " + RunningReac
	 + ", LossP = " + LossP
	 + ", LossQ = " + LossQ
	 + ", LossRate = " + LossRate
	 + ", BusOverLoadIndex = " + BusOverLoadIndex
	 + ", BusOverLoadNum = " + BusOverLoadNum
	 + ", LineOverLoadIndex = " + LineOverLoadIndex
	 + ", LineOverLoadNum = " + LineOverLoadNum
	 + ", LineLoadRate100 = " + LineLoadRate100
	 + ", LineLoadRate80 = " + LineLoadRate80
	 + ", LineLoadRate60 = " + LineLoadRate60
	 + ", LineLoadRate40 = " + LineLoadRate40
	 + ", LineLoadRate20 = " + LineLoadRate20
	 + ", LineLoadRate0 = " + LineLoadRate0
	 + ", TranOverLoadIndex = " + TranOverLoadIndex
	 + ", TranOverLoadNum = " + TranOverLoadNum
	 + ", TranLoadRate100 = " + TranLoadRate100
	 + ", TranLoadRate80 = " + TranLoadRate80
	 + ", TranLoadRate60 = " + TranLoadRate60
	 + ", TranLoadRate40 = " + TranLoadRate40
	 + ", TranLoadRate20 = " + TranLoadRate20
	 + ", TranLoadRate0 = " + TranLoadRate0
	 + ", DeadIslandLoadP = " + DeadIslandLoadP
	 + ", DeadIslandLoadQ = " + DeadIslandLoadQ
	 + ", ro_Customernum = " + ro_Customernum
	 + ", ro_Aci = " + ro_Aci
	 + ", ro_Cid = " + ro_Cid
	 + ", ro_Saifi = " + ro_Saifi
	 + ", ro_Saidi = " + ro_Saidi
	 + ", ro_Asai = " + ro_Asai
	 + ", ro_Ens = " + ro_Ens
	 + ", ro_AEns = " + ro_AEns
	 + ", ro_Mic = " + ro_Mic
	 + ", ro_Mid = " + ro_Mid
	 + ", ro_f_Aci = " + ro_f_Aci
	 + ", ro_f_Cid = " + ro_f_Cid
	 + ", ro_f_Saifi = " + ro_f_Saifi
	 + ", ro_f_Saidi = " + ro_f_Saidi
	 + ", ro_f_Asai = " + ro_f_Asai
	 + ", ro_f_Ens = " + ro_f_Ens
	 + ", ro_f_AEns = " + ro_f_AEns
	 + ", ro_f_Mic = " + ro_f_Mic
	 + ", ro_f_Mid = " + ro_f_Mid
	 + ", ro_a_Aci = " + ro_a_Aci
	 + ", ro_a_Cid = " + ro_a_Cid
	 + ", ro_a_Saifi = " + ro_a_Saifi
	 + ", ro_a_Saidi = " + ro_a_Saidi
	 + ", ro_a_Asai = " + ro_a_Asai
	 + ", ro_a_Ens = " + ro_a_Ens
	 + ", ro_a_AEns = " + ro_a_AEns
	 + ", ro_a_Mic = " + ro_a_Mic
	 + ", ro_a_Mid = " + ro_a_Mid
	 + ", eo_EleSupply = " + eo_EleSupply
	 + ", eo_EleCost = " + eo_EleCost
	 + ", eo_EleIncome = " + eo_EleIncome
	 + ", eo_RCoef = " + eo_RCoef
	 + ", eo_LossCost = " + eo_LossCost
	 + ", eo_ReliCost = " + eo_ReliCost
	 + ", eo_FundCost = " + eo_FundCost
	 + ", eo_Income = " + eo_Income
	 + ", eo_ReliEVCost = " + eo_ReliEVCost
	 + ", eo_EVIncome = " + eo_EVIncome
	 + ", sa_LinePassRate = " + sa_LinePassRate
	 + ", sa_LineLossPower = " + sa_LineLossPower
	 + ", sa_UnitPassRate = " + sa_UnitPassRate
	 + ", sa_UnitLossPower = " + sa_UnitLossPower
	 + ", sa_CombPassRate = " + sa_CombPassRate
	 + ", sa_CombLossPower = " + sa_CombLossPower+"]";
  }
    
}
    
