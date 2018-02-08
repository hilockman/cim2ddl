package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电力公司	*
***********************/
public class Company  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //ObjectId
  private String ObjectID;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //系统平衡机厂站
  private String stid;
  
  //系统平衡机发电机
  private String unid;
  
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
  
  //网损有功(MW)
  private Double LossP;
  
  //网损无功(MVar)
  private Double LossQ;
  
  //交换功率有功(MW)
  private Double TieP;
  
  //交换功率无功(MVar)
  private Double TieQ;
  
  //投资总额(万元)
  private Double ei_Invest;
  
  //电力公司售每度电的收益(元/千瓦时)
  private Double ei_sprice;
  
  //电力公司购网电价(元/千瓦时)
  private Double ei_pprice;
  
  //名义年利率(<1)
  private Double ei_iyrate;
  
  //计息周期(次/年)
  private Integer ei_icycle;
  
  //银行贷款时间(年)
  private Integer ei_credtime;
  
  //工程建设期(年)
  private Integer ei_constime;
  
  //设备折旧期(年)
  private Integer ei_deprectime;
  
  //保留残值(<1)
  private Double ei_residual;
  
  //所得税税率(<1)
  private Double ei_taxrate;
  
  //固定资产年维修费(<1)
  private Double ei_repairfee;
  
  //固定资产年保险费(<1)
  private Double ei_insurfee;
  
  //公司用户总数
  private Double ro_customernum;
  
  //用户年停电次数(次/年)
  private Double ro_aci;
  
  //用户年停电时间(小时/年)
  private Double ro_cid;
  
  //公司年均停电次数(次/户.年)
  private Double ro_saifi;
  
  //公司年均停电时间(小时/户.年)
  private Double ro_saidi;
  
  //综合平均理论供电可用率
  private Double ro_asai;
  
  //公司年均停电电量(MWh/年)
  private Double ro_ens;
  
  //用户年均停电电量(MWh/户.年)
  private Double ro_aens;
  
  //公司停电平均用户数(户/次)
  private Double ro_mic;
  
  //公司停电平均持续时间(小时/次)
  private Double ro_mid;
  
  //用户年故障停电次数(次/年)
  private Double ro_f_aci;
  
  //用户年故障停电时间(小时/年)
  private Double ro_f_cid;
  
  //公司年均故障停电次数(次/户.年)
  private Double ro_f_saifi;
  
  //公司年均故障停电时间(小时/户.年)
  private Double ro_f_saidi;
  
  //故障平均理论供电可用率
  private Double ro_f_asai;
  
  //公司年均故障停电电量(MWh/年)
  private Double ro_f_ens;
  
  //用户年均故障停电电量(MWh/户.年)
  private Double ro_f_aens;
  
  //公司故障停电平均用户数(户/次)
  private Double ro_f_mic;
  
  //公司故障停电平均持续时间(小时/次)
  private Double ro_f_mid;
  
  //用户年预安排停电次数(次/年)
  private Double ro_a_aci;
  
  //用户年预安排停电时间(小时/年)
  private Double ro_a_cid;
  
  //公司年均预安排停电次数(次/户.年)
  private Double ro_a_saifi;
  
  //公司年均预安排停电时间(小时/户.年)
  private Double ro_a_saidi;
  
  //预安排平均理论供电可用率
  private Double ro_a_asai;
  
  //公司年均预安排停电电量(MWh/年)
  private Double ro_a_ens;
  
  //用户年均预安排停电电量(MWh/户.年)
  private Double ro_a_aens;
  
  //公司预安排停电平均用户数(户/次)
  private Double ro_a_mic;
  
  //公司预安排停电平均持续时间(小时/次)
  private Double ro_a_mid;
  
  //供电电量(含线损,万度/年)
  private Double eo_elesupply;
  
  //购电成本(万元/年)
  private Double eo_elecost;
  
  //售电收益(万元/年)
  private Double eo_eleincome;
  
  //最小回报系数
  private Double eo_rcoef;
  
  //线损成本(万元/年)
  private Double eo_losscost;
  
  //可靠性成本(万元/年)
  private Double eo_relicost;
  
  //资金成本(万元/年)
  private Double eo_fundcost;
  
  //(投产还贷期)年最小收入(万元/年)
  private Double eo_income;
  
  //考虑产电比停电损失(万元/年)
  private Double eo_relievcost;
  
  //(投产还贷期)考虑产电比年最小收入(万元/年)
  private Double eo_evincome;
  
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
    
  public Double getTieP()
  {
    return TieP;
  }
    
  public void setTieP(Double TieP)
  {
    this.TieP = TieP;
  }
    
  public Double getTieQ()
  {
    return TieQ;
  }
    
  public void setTieQ(Double TieQ)
  {
    this.TieQ = TieQ;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Double getei_sprice()
  {
    return ei_sprice;
  }
    
  public void setei_sprice(Double ei_sprice)
  {
    this.ei_sprice = ei_sprice;
  }
    
  public Double getei_pprice()
  {
    return ei_pprice;
  }
    
  public void setei_pprice(Double ei_pprice)
  {
    this.ei_pprice = ei_pprice;
  }
    
  public Double getei_iyrate()
  {
    return ei_iyrate;
  }
    
  public void setei_iyrate(Double ei_iyrate)
  {
    this.ei_iyrate = ei_iyrate;
  }
    
  public Integer getei_icycle()
  {
    return ei_icycle;
  }
    
  public void setei_icycle(Integer ei_icycle)
  {
    this.ei_icycle = ei_icycle;
  }
    
  public Integer getei_credtime()
  {
    return ei_credtime;
  }
    
  public void setei_credtime(Integer ei_credtime)
  {
    this.ei_credtime = ei_credtime;
  }
    
  public Integer getei_constime()
  {
    return ei_constime;
  }
    
  public void setei_constime(Integer ei_constime)
  {
    this.ei_constime = ei_constime;
  }
    
  public Integer getei_deprectime()
  {
    return ei_deprectime;
  }
    
  public void setei_deprectime(Integer ei_deprectime)
  {
    this.ei_deprectime = ei_deprectime;
  }
    
  public Double getei_residual()
  {
    return ei_residual;
  }
    
  public void setei_residual(Double ei_residual)
  {
    this.ei_residual = ei_residual;
  }
    
  public Double getei_taxrate()
  {
    return ei_taxrate;
  }
    
  public void setei_taxrate(Double ei_taxrate)
  {
    this.ei_taxrate = ei_taxrate;
  }
    
  public Double getei_repairfee()
  {
    return ei_repairfee;
  }
    
  public void setei_repairfee(Double ei_repairfee)
  {
    this.ei_repairfee = ei_repairfee;
  }
    
  public Double getei_insurfee()
  {
    return ei_insurfee;
  }
    
  public void setei_insurfee(Double ei_insurfee)
  {
    this.ei_insurfee = ei_insurfee;
  }
    
  public Double getro_customernum()
  {
    return ro_customernum;
  }
    
  public void setro_customernum(Double ro_customernum)
  {
    this.ro_customernum = ro_customernum;
  }
    
  public Double getro_aci()
  {
    return ro_aci;
  }
    
  public void setro_aci(Double ro_aci)
  {
    this.ro_aci = ro_aci;
  }
    
  public Double getro_cid()
  {
    return ro_cid;
  }
    
  public void setro_cid(Double ro_cid)
  {
    this.ro_cid = ro_cid;
  }
    
  public Double getro_saifi()
  {
    return ro_saifi;
  }
    
  public void setro_saifi(Double ro_saifi)
  {
    this.ro_saifi = ro_saifi;
  }
    
  public Double getro_saidi()
  {
    return ro_saidi;
  }
    
  public void setro_saidi(Double ro_saidi)
  {
    this.ro_saidi = ro_saidi;
  }
    
  public Double getro_asai()
  {
    return ro_asai;
  }
    
  public void setro_asai(Double ro_asai)
  {
    this.ro_asai = ro_asai;
  }
    
  public Double getro_ens()
  {
    return ro_ens;
  }
    
  public void setro_ens(Double ro_ens)
  {
    this.ro_ens = ro_ens;
  }
    
  public Double getro_aens()
  {
    return ro_aens;
  }
    
  public void setro_aens(Double ro_aens)
  {
    this.ro_aens = ro_aens;
  }
    
  public Double getro_mic()
  {
    return ro_mic;
  }
    
  public void setro_mic(Double ro_mic)
  {
    this.ro_mic = ro_mic;
  }
    
  public Double getro_mid()
  {
    return ro_mid;
  }
    
  public void setro_mid(Double ro_mid)
  {
    this.ro_mid = ro_mid;
  }
    
  public Double getro_f_aci()
  {
    return ro_f_aci;
  }
    
  public void setro_f_aci(Double ro_f_aci)
  {
    this.ro_f_aci = ro_f_aci;
  }
    
  public Double getro_f_cid()
  {
    return ro_f_cid;
  }
    
  public void setro_f_cid(Double ro_f_cid)
  {
    this.ro_f_cid = ro_f_cid;
  }
    
  public Double getro_f_saifi()
  {
    return ro_f_saifi;
  }
    
  public void setro_f_saifi(Double ro_f_saifi)
  {
    this.ro_f_saifi = ro_f_saifi;
  }
    
  public Double getro_f_saidi()
  {
    return ro_f_saidi;
  }
    
  public void setro_f_saidi(Double ro_f_saidi)
  {
    this.ro_f_saidi = ro_f_saidi;
  }
    
  public Double getro_f_asai()
  {
    return ro_f_asai;
  }
    
  public void setro_f_asai(Double ro_f_asai)
  {
    this.ro_f_asai = ro_f_asai;
  }
    
  public Double getro_f_ens()
  {
    return ro_f_ens;
  }
    
  public void setro_f_ens(Double ro_f_ens)
  {
    this.ro_f_ens = ro_f_ens;
  }
    
  public Double getro_f_aens()
  {
    return ro_f_aens;
  }
    
  public void setro_f_aens(Double ro_f_aens)
  {
    this.ro_f_aens = ro_f_aens;
  }
    
  public Double getro_f_mic()
  {
    return ro_f_mic;
  }
    
  public void setro_f_mic(Double ro_f_mic)
  {
    this.ro_f_mic = ro_f_mic;
  }
    
  public Double getro_f_mid()
  {
    return ro_f_mid;
  }
    
  public void setro_f_mid(Double ro_f_mid)
  {
    this.ro_f_mid = ro_f_mid;
  }
    
  public Double getro_a_aci()
  {
    return ro_a_aci;
  }
    
  public void setro_a_aci(Double ro_a_aci)
  {
    this.ro_a_aci = ro_a_aci;
  }
    
  public Double getro_a_cid()
  {
    return ro_a_cid;
  }
    
  public void setro_a_cid(Double ro_a_cid)
  {
    this.ro_a_cid = ro_a_cid;
  }
    
  public Double getro_a_saifi()
  {
    return ro_a_saifi;
  }
    
  public void setro_a_saifi(Double ro_a_saifi)
  {
    this.ro_a_saifi = ro_a_saifi;
  }
    
  public Double getro_a_saidi()
  {
    return ro_a_saidi;
  }
    
  public void setro_a_saidi(Double ro_a_saidi)
  {
    this.ro_a_saidi = ro_a_saidi;
  }
    
  public Double getro_a_asai()
  {
    return ro_a_asai;
  }
    
  public void setro_a_asai(Double ro_a_asai)
  {
    this.ro_a_asai = ro_a_asai;
  }
    
  public Double getro_a_ens()
  {
    return ro_a_ens;
  }
    
  public void setro_a_ens(Double ro_a_ens)
  {
    this.ro_a_ens = ro_a_ens;
  }
    
  public Double getro_a_aens()
  {
    return ro_a_aens;
  }
    
  public void setro_a_aens(Double ro_a_aens)
  {
    this.ro_a_aens = ro_a_aens;
  }
    
  public Double getro_a_mic()
  {
    return ro_a_mic;
  }
    
  public void setro_a_mic(Double ro_a_mic)
  {
    this.ro_a_mic = ro_a_mic;
  }
    
  public Double getro_a_mid()
  {
    return ro_a_mid;
  }
    
  public void setro_a_mid(Double ro_a_mid)
  {
    this.ro_a_mid = ro_a_mid;
  }
    
  public Double geteo_elesupply()
  {
    return eo_elesupply;
  }
    
  public void seteo_elesupply(Double eo_elesupply)
  {
    this.eo_elesupply = eo_elesupply;
  }
    
  public Double geteo_elecost()
  {
    return eo_elecost;
  }
    
  public void seteo_elecost(Double eo_elecost)
  {
    this.eo_elecost = eo_elecost;
  }
    
  public Double geteo_eleincome()
  {
    return eo_eleincome;
  }
    
  public void seteo_eleincome(Double eo_eleincome)
  {
    this.eo_eleincome = eo_eleincome;
  }
    
  public Double geteo_rcoef()
  {
    return eo_rcoef;
  }
    
  public void seteo_rcoef(Double eo_rcoef)
  {
    this.eo_rcoef = eo_rcoef;
  }
    
  public Double geteo_losscost()
  {
    return eo_losscost;
  }
    
  public void seteo_losscost(Double eo_losscost)
  {
    this.eo_losscost = eo_losscost;
  }
    
  public Double geteo_relicost()
  {
    return eo_relicost;
  }
    
  public void seteo_relicost(Double eo_relicost)
  {
    this.eo_relicost = eo_relicost;
  }
    
  public Double geteo_fundcost()
  {
    return eo_fundcost;
  }
    
  public void seteo_fundcost(Double eo_fundcost)
  {
    this.eo_fundcost = eo_fundcost;
  }
    
  public Double geteo_income()
  {
    return eo_income;
  }
    
  public void seteo_income(Double eo_income)
  {
    this.eo_income = eo_income;
  }
    
  public Double geteo_relievcost()
  {
    return eo_relievcost;
  }
    
  public void seteo_relievcost(Double eo_relievcost)
  {
    this.eo_relievcost = eo_relievcost;
  }
    
  public Double geteo_evincome()
  {
    return eo_evincome;
  }
    
  public void seteo_evincome(Double eo_evincome)
  {
    this.eo_evincome = eo_evincome;
  }
    
  public String toString()
  {
    return "Company ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", stid = " + stid
	 + ", unid = " + unid
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
	 + ", TieP = " + TieP
	 + ", TieQ = " + TieQ
	 + ", ei_Invest = " + ei_Invest
	 + ", ei_sprice = " + ei_sprice
	 + ", ei_pprice = " + ei_pprice
	 + ", ei_iyrate = " + ei_iyrate
	 + ", ei_icycle = " + ei_icycle
	 + ", ei_credtime = " + ei_credtime
	 + ", ei_constime = " + ei_constime
	 + ", ei_deprectime = " + ei_deprectime
	 + ", ei_residual = " + ei_residual
	 + ", ei_taxrate = " + ei_taxrate
	 + ", ei_repairfee = " + ei_repairfee
	 + ", ei_insurfee = " + ei_insurfee
	 + ", ro_customernum = " + ro_customernum
	 + ", ro_aci = " + ro_aci
	 + ", ro_cid = " + ro_cid
	 + ", ro_saifi = " + ro_saifi
	 + ", ro_saidi = " + ro_saidi
	 + ", ro_asai = " + ro_asai
	 + ", ro_ens = " + ro_ens
	 + ", ro_aens = " + ro_aens
	 + ", ro_mic = " + ro_mic
	 + ", ro_mid = " + ro_mid
	 + ", ro_f_aci = " + ro_f_aci
	 + ", ro_f_cid = " + ro_f_cid
	 + ", ro_f_saifi = " + ro_f_saifi
	 + ", ro_f_saidi = " + ro_f_saidi
	 + ", ro_f_asai = " + ro_f_asai
	 + ", ro_f_ens = " + ro_f_ens
	 + ", ro_f_aens = " + ro_f_aens
	 + ", ro_f_mic = " + ro_f_mic
	 + ", ro_f_mid = " + ro_f_mid
	 + ", ro_a_aci = " + ro_a_aci
	 + ", ro_a_cid = " + ro_a_cid
	 + ", ro_a_saifi = " + ro_a_saifi
	 + ", ro_a_saidi = " + ro_a_saidi
	 + ", ro_a_asai = " + ro_a_asai
	 + ", ro_a_ens = " + ro_a_ens
	 + ", ro_a_aens = " + ro_a_aens
	 + ", ro_a_mic = " + ro_a_mic
	 + ", ro_a_mid = " + ro_a_mid
	 + ", eo_elesupply = " + eo_elesupply
	 + ", eo_elecost = " + eo_elecost
	 + ", eo_eleincome = " + eo_eleincome
	 + ", eo_rcoef = " + eo_rcoef
	 + ", eo_losscost = " + eo_losscost
	 + ", eo_relicost = " + eo_relicost
	 + ", eo_fundcost = " + eo_fundcost
	 + ", eo_income = " + eo_income
	 + ", eo_relievcost = " + eo_relievcost
	 + ", eo_evincome = " + eo_evincome+"]";
  }
    
}
    
