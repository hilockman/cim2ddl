package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*线路	*
***********************/
public class Line  implements MemIndexable 
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
  
  //电压等级
  private String VoltageLevel;
  
  //所属分区
  private String SubcontrolArea;
  
  //投资费用(万元/千米)
  private Double ei_Invest;
  
  //线路长度(千米)
  private Double LineLength;
  
  //负荷总加有功(兆瓦)
  private Double LoadP;
  
  //负荷总加无功(兆乏)
  private Double LoadQ;
  
  //损耗有功(兆瓦)
  private Double LossP;
  
  //损耗无功(兆乏)
  private Double LossQ;
  
  //线路用户总数
  private Double ro_customernum;
  
  //用户年停电次数(次/年)
  private Double ro_aci;
  
  //用户年电时间(户.小时/年)
  private Double ro_cid;
  
  //线路年均停电次数(次/年)
  private Double ro_saifi;
  
  //线路年停电时间(小时/年)
  private Double ro_saidi;
  
  //综合平均理论供电可用率
  private Double ro_asai;
  
  //线路年均停电电量(兆瓦时/年)
  private Double ro_ens;
  
  //用户年均停电电量(兆瓦时/户.年)
  private Double ro_aens;
  
  //线路停电平均用户数(户/次)
  private Double ro_mic;
  
  //线路停电平均持续时间(小时/次)
  private Double ro_mid;
  
  //用户年均故障停电次数(次/年)
  private Double ro_f_aci;
  
  //用户年均故障停电时间(小时/年)
  private Double ro_f_cid;
  
  //线路年均故障停电次数(次/户.年)
  private Double ro_f_saifi;
  
  //线路年故障停电时间(小时/户.年)
  private Double ro_f_saidi;
  
  //故障平均理论供电可用率
  private Double ro_f_asai;
  
  //线路年均故障停电电量(兆瓦时/年)
  private Double ro_f_ens;
  
  //用户年均故障停电电量(兆瓦时/户.年)
  private Double ro_f_aens;
  
  //线路故障停电平均用户数(户/次)
  private Double ro_f_mic;
  
  //线路故障停电平均持续时间(小时/次)
  private Double ro_f_mid;
  
  //用户年均预安排停电次数(次/年)
  private Double ro_a_aci;
  
  //用户年均预安排停电时间(小时/年)
  private Double ro_a_cid;
  
  //线路年均预安排停电次数(次/户.年)
  private Double ro_a_saifi;
  
  //线路年预安排停电时间(小时/户.年)
  private Double ro_a_saidi;
  
  //预安排平均理论供电可用率
  private Double ro_a_asai;
  
  //线路年均预安排停电电量(兆瓦时/年)
  private Double ro_a_ens;
  
  //用户年均预安排停电电量(兆瓦时/户.年)
  private Double ro_a_aens;
  
  //线路预安排停电平均用户数(户/次)
  private Double ro_a_mic;
  
  //线路预安排停电平均持续时间(小时/次)
  private Double ro_a_mid;
  
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
    
  public String getVoltageLevel()
  {
    return VoltageLevel;
  }
    
  public void setVoltageLevel(String VoltageLevel)
  {
    this.VoltageLevel = VoltageLevel;
  }
    
  public String getSubcontrolArea()
  {
    return SubcontrolArea;
  }
    
  public void setSubcontrolArea(String SubcontrolArea)
  {
    this.SubcontrolArea = SubcontrolArea;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Double getLineLength()
  {
    return LineLength;
  }
    
  public void setLineLength(Double LineLength)
  {
    this.LineLength = LineLength;
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
    return "Line ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", VoltageLevel = " + VoltageLevel
	 + ", SubcontrolArea = " + SubcontrolArea
	 + ", ei_Invest = " + ei_Invest
	 + ", LineLength = " + LineLength
	 + ", LoadP = " + LoadP
	 + ", LoadQ = " + LoadQ
	 + ", LossP = " + LossP
	 + ", LossQ = " + LossQ
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
	 + ", Open = " + Open+"]";
  }
    
}
    
