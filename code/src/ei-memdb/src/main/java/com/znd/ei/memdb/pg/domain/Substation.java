package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*厂站	*
***********************/
public class Substation  implements MemIndexable 
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
  
  //所属电力公司
  private String Company;
  
  //所属电力分区
  private String SubcontrolArea;
  
  //厂站类型
  private Integer st_type;
  
  //变电容量(MVA)
  private Double Capacity;
  
  //投资总额(万元)
  private Double ei_Invest;
  
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
  
  //发电功率因数
  private Double GenFatctor;
  
  //负荷功率因数
  private Double LoadFatctor;
  
  //N-1通过情况
  private Integer sa_Result;
  
  //N-1形成孤岛
  private Integer sa_Island;
  
  //N-1负荷损失(MVA)
  private Double sa_Failure;
  
  //N-1设备负荷损失(MW)
  private Double sa_Outages;
  
  //电压等级记录范围
  private Integer VoltageLevelRange;
  
  //变压器记录范围
  private Integer PowerTransformerRange;
  
  //变压器绕组记录范围
  private Integer TransformerWindingRange;
  
  //整流逆变器记录范围
  private Integer RectifierInverterRange;
  
  //配网厂站
  private Integer Distribution;
  
  //厂站归属设备类型
  private Integer ParentType;
  
  //枢纽站标记
  private Integer IsHub;
  
  //不参与优化标记
  private Integer NOptimize;
  
  //辅助信息
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
    
  public String getCompany()
  {
    return Company;
  }
    
  public void setCompany(String Company)
  {
    this.Company = Company;
  }
    
  public String getSubcontrolArea()
  {
    return SubcontrolArea;
  }
    
  public void setSubcontrolArea(String SubcontrolArea)
  {
    this.SubcontrolArea = SubcontrolArea;
  }
    
  public Integer getst_type()
  {
    return st_type;
  }
    
  public void setst_type(Integer st_type)
  {
    this.st_type = st_type;
  }
    
  public Double getCapacity()
  {
    return Capacity;
  }
    
  public void setCapacity(Double Capacity)
  {
    this.Capacity = Capacity;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
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
    
  public Integer getVoltageLevelRange()
  {
    return VoltageLevelRange;
  }
    
  public void setVoltageLevelRange(Integer VoltageLevelRange)
  {
    this.VoltageLevelRange = VoltageLevelRange;
  }
    
  public Integer getPowerTransformerRange()
  {
    return PowerTransformerRange;
  }
    
  public void setPowerTransformerRange(Integer PowerTransformerRange)
  {
    this.PowerTransformerRange = PowerTransformerRange;
  }
    
  public Integer getTransformerWindingRange()
  {
    return TransformerWindingRange;
  }
    
  public void setTransformerWindingRange(Integer TransformerWindingRange)
  {
    this.TransformerWindingRange = TransformerWindingRange;
  }
    
  public Integer getRectifierInverterRange()
  {
    return RectifierInverterRange;
  }
    
  public void setRectifierInverterRange(Integer RectifierInverterRange)
  {
    this.RectifierInverterRange = RectifierInverterRange;
  }
    
  public Integer getDistribution()
  {
    return Distribution;
  }
    
  public void setDistribution(Integer Distribution)
  {
    this.Distribution = Distribution;
  }
    
  public Integer getParentType()
  {
    return ParentType;
  }
    
  public void setParentType(Integer ParentType)
  {
    this.ParentType = ParentType;
  }
    
  public Integer getIsHub()
  {
    return IsHub;
  }
    
  public void setIsHub(Integer IsHub)
  {
    this.IsHub = IsHub;
  }
    
  public Integer getNOptimize()
  {
    return NOptimize;
  }
    
  public void setNOptimize(Integer NOptimize)
  {
    this.NOptimize = NOptimize;
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
    return "Substation ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", Company = " + Company
	 + ", SubcontrolArea = " + SubcontrolArea
	 + ", st_type = " + st_type
	 + ", Capacity = " + Capacity
	 + ", ei_Invest = " + ei_Invest
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
	 + ", GenFatctor = " + GenFatctor
	 + ", LoadFatctor = " + LoadFatctor
	 + ", sa_Result = " + sa_Result
	 + ", sa_Island = " + sa_Island
	 + ", sa_Failure = " + sa_Failure
	 + ", sa_Outages = " + sa_Outages
	 + ", VoltageLevelRange = " + VoltageLevelRange
	 + ", PowerTransformerRange = " + PowerTransformerRange
	 + ", TransformerWindingRange = " + TransformerWindingRange
	 + ", RectifierInverterRange = " + RectifierInverterRange
	 + ", Distribution = " + Distribution
	 + ", ParentType = " + ParentType
	 + ", IsHub = " + IsHub
	 + ", NOptimize = " + NOptimize
	 + ", Outage = " + Outage+"]";
  }
    
}
    
