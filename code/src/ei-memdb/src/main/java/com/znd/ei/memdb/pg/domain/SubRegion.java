package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*供电分区	*
***********************/
public class SubRegion  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //分区类型
  private Integer RegionType;
  
  //总发电有功(MW)
  private Double TotalGenP;
  
  //总发电无功(MVar)
  private Double TotalGenQ;
  
  //总负荷有功(MW)
  private Double TotalLoadP;
  
  //总负荷无功(MVar)
  private Double TotalLoadQ;
  
  //总电容无功(MVar)
  private Double TotalCap;
  
  //总电抗无功(MVar)
  private Double TotalReac;
  
  //总网损有功(MW)
  private Double TotalLossP;
  
  //总网损无功(MVar)
  private Double TotalLossQ;
  
  //发电功率因数
  private Double GenFatctor;
  
  //负荷功率因数
  private Double LoadFatctor;
  
  //分区用户总数
  private Double ro_customernum;
  
  //用户年停电次数(次/年)
  private Double ro_aci;
  
  //用户年停电时间(小时/年)
  private Double ro_cid;
  
  //分区年均停电次数(次/户.年)
  private Double ro_saifi;
  
  //分区年均停电时间(小时/户.年)
  private Double ro_saidi;
  
  //综合平均理论供电可用率
  private Double ro_asai;
  
  //分区年均停电电量(MWh/年)
  private Double ro_ens;
  
  //用户年均停电电量(MWh/户.年)
  private Double ro_aens;
  
  //分区停电平均用户数(户/次)
  private Double ro_mic;
  
  //分区停电平均持续时间(小时/次)
  private Double ro_mid;
  
  //用户年故障停电次数(次/年)
  private Double ro_f_aci;
  
  //用户年故障停电时间(小时/年)
  private Double ro_f_cid;
  
  //分区年均故障停电次数(次/户.年)
  private Double ro_f_saifi;
  
  //分区年均故障停电时间(小时/户.年)
  private Double ro_f_saidi;
  
  //故障平均理论供电可用率
  private Double ro_f_asai;
  
  //分区年均故障停电电量(MWh/年)
  private Double ro_f_ens;
  
  //用户年均故障停电电量(MWh/户.年)
  private Double ro_f_aens;
  
  //分区故障停电平均用户数(户/次)
  private Double ro_f_mic;
  
  //分区故障停电平均持续时间(小时/次)
  private Double ro_f_mid;
  
  //用户年故障综合停电次数(次/年)
  private Double ro_c_aci;
  
  //用户年故障综合停电时间(小时/年)
  private Double ro_c_cid;
  
  //分区年均故障综合停电次数(次/户.年)
  private Double ro_c_saifi;
  
  //分区年均故障综合停电时间(小时/户.年)
  private Double ro_c_saidi;
  
  //故障综合平均理论供电可用率
  private Double ro_c_asai;
  
  //分区年均故障综合停电电量(MWh/年)
  private Double ro_c_ens;
  
  //用户年均故障综合停电电量(MWh/户.年)
  private Double ro_c_aens;
  
  //分区故障综合停电平均用户数(户/次)
  private Double ro_c_mic;
  
  //分区故障综合停电平均持续时间(小时/次)
  private Double ro_c_mid;
  
  //用户年预安排停电次数(次/年)
  private Double ro_a_aci;
  
  //用户年预安排停电时间(小时/年)
  private Double ro_a_cid;
  
  //分区年均预安排停电次数(次/户.年)
  private Double ro_a_saifi;
  
  //分区年均预安排停电时间(小时/户.年)
  private Double ro_a_saidi;
  
  //预安排平均理论供电可用率
  private Double ro_a_asai;
  
  //分区年均预安排停电电量(MWh/年)
  private Double ro_a_ens;
  
  //用户年均预安排停电电量(MWh/户.年)
  private Double ro_a_aens;
  
  //分区预安排停电平均用户数(户/次)
  private Double ro_a_mic;
  
  //分区预安排停电平均持续时间(小时/次)
  private Double ro_a_mid;
  
  //最小回报系数
  private Double eo_rcoef;
  
  //线损成本(万元)
  private Double eo_losscost;
  
  //可靠性成本(万元)
  private Double eo_relicost;
  
  //资金成本(万元)
  private Double eo_fundcost;
  
  //(投产还贷期)年最小收入(万元)
  private Double eo_income;
  
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
    
  public Integer getRegionType()
  {
    return RegionType;
  }
    
  public void setRegionType(Integer RegionType)
  {
    this.RegionType = RegionType;
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
    
  public Double getTotalLossP()
  {
    return TotalLossP;
  }
    
  public void setTotalLossP(Double TotalLossP)
  {
    this.TotalLossP = TotalLossP;
  }
    
  public Double getTotalLossQ()
  {
    return TotalLossQ;
  }
    
  public void setTotalLossQ(Double TotalLossQ)
  {
    this.TotalLossQ = TotalLossQ;
  }
    
  public Double getGenFatctor()
  {
    return GenFatctor;
  }
    
  public void setGenFatctor(Double GenFatctor)
  {
    this.GenFatctor = GenFatctor;
  }
    
  public Double getLoadFatctor()
  {
    return LoadFatctor;
  }
    
  public void setLoadFatctor(Double LoadFatctor)
  {
    this.LoadFatctor = LoadFatctor;
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
    
  public Double getro_c_aci()
  {
    return ro_c_aci;
  }
    
  public void setro_c_aci(Double ro_c_aci)
  {
    this.ro_c_aci = ro_c_aci;
  }
    
  public Double getro_c_cid()
  {
    return ro_c_cid;
  }
    
  public void setro_c_cid(Double ro_c_cid)
  {
    this.ro_c_cid = ro_c_cid;
  }
    
  public Double getro_c_saifi()
  {
    return ro_c_saifi;
  }
    
  public void setro_c_saifi(Double ro_c_saifi)
  {
    this.ro_c_saifi = ro_c_saifi;
  }
    
  public Double getro_c_saidi()
  {
    return ro_c_saidi;
  }
    
  public void setro_c_saidi(Double ro_c_saidi)
  {
    this.ro_c_saidi = ro_c_saidi;
  }
    
  public Double getro_c_asai()
  {
    return ro_c_asai;
  }
    
  public void setro_c_asai(Double ro_c_asai)
  {
    this.ro_c_asai = ro_c_asai;
  }
    
  public Double getro_c_ens()
  {
    return ro_c_ens;
  }
    
  public void setro_c_ens(Double ro_c_ens)
  {
    this.ro_c_ens = ro_c_ens;
  }
    
  public Double getro_c_aens()
  {
    return ro_c_aens;
  }
    
  public void setro_c_aens(Double ro_c_aens)
  {
    this.ro_c_aens = ro_c_aens;
  }
    
  public Double getro_c_mic()
  {
    return ro_c_mic;
  }
    
  public void setro_c_mic(Double ro_c_mic)
  {
    this.ro_c_mic = ro_c_mic;
  }
    
  public Double getro_c_mid()
  {
    return ro_c_mid;
  }
    
  public void setro_c_mid(Double ro_c_mid)
  {
    this.ro_c_mid = ro_c_mid;
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
    
  public String toString()
  {
    return "SubRegion ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", RegionType = " + RegionType
	 + ", TotalGenP = " + TotalGenP
	 + ", TotalGenQ = " + TotalGenQ
	 + ", TotalLoadP = " + TotalLoadP
	 + ", TotalLoadQ = " + TotalLoadQ
	 + ", TotalCap = " + TotalCap
	 + ", TotalReac = " + TotalReac
	 + ", TotalLossP = " + TotalLossP
	 + ", TotalLossQ = " + TotalLossQ
	 + ", GenFatctor = " + GenFatctor
	 + ", LoadFatctor = " + LoadFatctor
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
	 + ", ro_c_aci = " + ro_c_aci
	 + ", ro_c_cid = " + ro_c_cid
	 + ", ro_c_saifi = " + ro_c_saifi
	 + ", ro_c_saidi = " + ro_c_saidi
	 + ", ro_c_asai = " + ro_c_asai
	 + ", ro_c_ens = " + ro_c_ens
	 + ", ro_c_aens = " + ro_c_aens
	 + ", ro_c_mic = " + ro_c_mic
	 + ", ro_c_mid = " + ro_c_mid
	 + ", ro_a_aci = " + ro_a_aci
	 + ", ro_a_cid = " + ro_a_cid
	 + ", ro_a_saifi = " + ro_a_saifi
	 + ", ro_a_saidi = " + ro_a_saidi
	 + ", ro_a_asai = " + ro_a_asai
	 + ", ro_a_ens = " + ro_a_ens
	 + ", ro_a_aens = " + ro_a_aens
	 + ", ro_a_mic = " + ro_a_mic
	 + ", ro_a_mid = " + ro_a_mid
	 + ", eo_rcoef = " + eo_rcoef
	 + ", eo_losscost = " + eo_losscost
	 + ", eo_relicost = " + eo_relicost
	 + ", eo_fundcost = " + eo_fundcost
	 + ", eo_income = " + eo_income+"]";
  }
    
}
    
