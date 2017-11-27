package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*潮流控制语句	*
***********************/
public class BpaDat_Case  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //潮流方式名
  private String Case_CaseID;
  
  //工程名
  private String Case_Project;
  
  //指定的系统基准容量
  private Double Case_MVABase;
  
  //所指定的控制语句文件
  private String Case_Control;
  
  //所指定的支路数据
  private String Case_Branch;
  
  //所指定的母线数据
  private String Case_Bus;
  
  //所指定的数据文件
  private String Case_Network;
  
  //RX比值检查
  private Integer Case_RXCheck;
  
  //潮流结果二进制文件(.BSE)
  private String Case_NewBase;
  
  //指定老库文件
  private String Case_OldBase;
  
  //生成潮流图二进制结果文件
  private String Case_Map;
  
  //区域联络线功率控制选择
  private Integer Case_AIControl;
  
  //带负荷调压变压器控制选择
  private Integer Case_LTC;
  
  //PQ解耦法
  private Integer Case_DecoupledNum;
  
  //改进的牛顿拉夫逊算法
  private Integer Case_CurrentNum;
  
  //牛顿拉夫逊算法
  private Integer Case_NewtonNum;
  
  //最优潮流法
  private Integer Case_OptimNum;
  
  //BusV允许误差,缺省值：0.005
  private Double Case_ToleranceBusV;
  
  //AIPower允许误差,缺省值：0.005
  private Double Case_ToleranceAIPower;
  
  //TX允许误差,缺省值：0.005
  private Double Case_ToleranceTX;
  
  //Q允许误差,缺省值：0.005
  private Double Case_ToleranceQ;
  
  //OPCUT允许误差,缺省值：0.0001
  private Double Case_ToleranceOpcut;
  
  //输出分类,输出顺序控制语句
  private Integer Case_RptSort;
  
  //分析报告输出,指定输出等级
  private Integer Case_AnalysisRpt;
  
  //电岛数
  private Integer IslandNum;
  
  //总发电有功
  private Double TotGenP;
  
  //总发电无功
  private Double TotGenQ;
  
  //总负荷有功
  private Double TotLoadP;
  
  //总负荷无功
  private Double TotLoadQ;
  
  //线路充电无功
  private Double TotLineCap;
  
  //总损耗有功
  private Double TotLossP;
  
  //总损耗无功
  private Double TotLossQ;
  
  //直流换流器损耗
  private Double TotDCLoss;
  
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
    
  public String getCase_CaseID()
  {
    return Case_CaseID;
  }
    
  public void setCase_CaseID(String Case_CaseID)
  {
    this.Case_CaseID = Case_CaseID;
  }
    
  public String getCase_Project()
  {
    return Case_Project;
  }
    
  public void setCase_Project(String Case_Project)
  {
    this.Case_Project = Case_Project;
  }
    
  public Double getCase_MVABase()
  {
    return Case_MVABase;
  }
    
  public void setCase_MVABase(Double Case_MVABase)
  {
    this.Case_MVABase = Case_MVABase;
  }
    
  public String getCase_Control()
  {
    return Case_Control;
  }
    
  public void setCase_Control(String Case_Control)
  {
    this.Case_Control = Case_Control;
  }
    
  public String getCase_Branch()
  {
    return Case_Branch;
  }
    
  public void setCase_Branch(String Case_Branch)
  {
    this.Case_Branch = Case_Branch;
  }
    
  public String getCase_Bus()
  {
    return Case_Bus;
  }
    
  public void setCase_Bus(String Case_Bus)
  {
    this.Case_Bus = Case_Bus;
  }
    
  public String getCase_Network()
  {
    return Case_Network;
  }
    
  public void setCase_Network(String Case_Network)
  {
    this.Case_Network = Case_Network;
  }
    
  public Integer getCase_RXCheck()
  {
    return Case_RXCheck;
  }
    
  public void setCase_RXCheck(Integer Case_RXCheck)
  {
    this.Case_RXCheck = Case_RXCheck;
  }
    
  public String getCase_NewBase()
  {
    return Case_NewBase;
  }
    
  public void setCase_NewBase(String Case_NewBase)
  {
    this.Case_NewBase = Case_NewBase;
  }
    
  public String getCase_OldBase()
  {
    return Case_OldBase;
  }
    
  public void setCase_OldBase(String Case_OldBase)
  {
    this.Case_OldBase = Case_OldBase;
  }
    
  public String getCase_Map()
  {
    return Case_Map;
  }
    
  public void setCase_Map(String Case_Map)
  {
    this.Case_Map = Case_Map;
  }
    
  public Integer getCase_AIControl()
  {
    return Case_AIControl;
  }
    
  public void setCase_AIControl(Integer Case_AIControl)
  {
    this.Case_AIControl = Case_AIControl;
  }
    
  public Integer getCase_LTC()
  {
    return Case_LTC;
  }
    
  public void setCase_LTC(Integer Case_LTC)
  {
    this.Case_LTC = Case_LTC;
  }
    
  public Integer getCase_DecoupledNum()
  {
    return Case_DecoupledNum;
  }
    
  public void setCase_DecoupledNum(Integer Case_DecoupledNum)
  {
    this.Case_DecoupledNum = Case_DecoupledNum;
  }
    
  public Integer getCase_CurrentNum()
  {
    return Case_CurrentNum;
  }
    
  public void setCase_CurrentNum(Integer Case_CurrentNum)
  {
    this.Case_CurrentNum = Case_CurrentNum;
  }
    
  public Integer getCase_NewtonNum()
  {
    return Case_NewtonNum;
  }
    
  public void setCase_NewtonNum(Integer Case_NewtonNum)
  {
    this.Case_NewtonNum = Case_NewtonNum;
  }
    
  public Integer getCase_OptimNum()
  {
    return Case_OptimNum;
  }
    
  public void setCase_OptimNum(Integer Case_OptimNum)
  {
    this.Case_OptimNum = Case_OptimNum;
  }
    
  public Double getCase_ToleranceBusV()
  {
    return Case_ToleranceBusV;
  }
    
  public void setCase_ToleranceBusV(Double Case_ToleranceBusV)
  {
    this.Case_ToleranceBusV = Case_ToleranceBusV;
  }
    
  public Double getCase_ToleranceAIPower()
  {
    return Case_ToleranceAIPower;
  }
    
  public void setCase_ToleranceAIPower(Double Case_ToleranceAIPower)
  {
    this.Case_ToleranceAIPower = Case_ToleranceAIPower;
  }
    
  public Double getCase_ToleranceTX()
  {
    return Case_ToleranceTX;
  }
    
  public void setCase_ToleranceTX(Double Case_ToleranceTX)
  {
    this.Case_ToleranceTX = Case_ToleranceTX;
  }
    
  public Double getCase_ToleranceQ()
  {
    return Case_ToleranceQ;
  }
    
  public void setCase_ToleranceQ(Double Case_ToleranceQ)
  {
    this.Case_ToleranceQ = Case_ToleranceQ;
  }
    
  public Double getCase_ToleranceOpcut()
  {
    return Case_ToleranceOpcut;
  }
    
  public void setCase_ToleranceOpcut(Double Case_ToleranceOpcut)
  {
    this.Case_ToleranceOpcut = Case_ToleranceOpcut;
  }
    
  public Integer getCase_RptSort()
  {
    return Case_RptSort;
  }
    
  public void setCase_RptSort(Integer Case_RptSort)
  {
    this.Case_RptSort = Case_RptSort;
  }
    
  public Integer getCase_AnalysisRpt()
  {
    return Case_AnalysisRpt;
  }
    
  public void setCase_AnalysisRpt(Integer Case_AnalysisRpt)
  {
    this.Case_AnalysisRpt = Case_AnalysisRpt;
  }
    
  public Integer getIslandNum()
  {
    return IslandNum;
  }
    
  public void setIslandNum(Integer IslandNum)
  {
    this.IslandNum = IslandNum;
  }
    
  public Double getTotGenP()
  {
    return TotGenP;
  }
    
  public void setTotGenP(Double TotGenP)
  {
    this.TotGenP = TotGenP;
  }
    
  public Double getTotGenQ()
  {
    return TotGenQ;
  }
    
  public void setTotGenQ(Double TotGenQ)
  {
    this.TotGenQ = TotGenQ;
  }
    
  public Double getTotLoadP()
  {
    return TotLoadP;
  }
    
  public void setTotLoadP(Double TotLoadP)
  {
    this.TotLoadP = TotLoadP;
  }
    
  public Double getTotLoadQ()
  {
    return TotLoadQ;
  }
    
  public void setTotLoadQ(Double TotLoadQ)
  {
    this.TotLoadQ = TotLoadQ;
  }
    
  public Double getTotLineCap()
  {
    return TotLineCap;
  }
    
  public void setTotLineCap(Double TotLineCap)
  {
    this.TotLineCap = TotLineCap;
  }
    
  public Double getTotLossP()
  {
    return TotLossP;
  }
    
  public void setTotLossP(Double TotLossP)
  {
    this.TotLossP = TotLossP;
  }
    
  public Double getTotLossQ()
  {
    return TotLossQ;
  }
    
  public void setTotLossQ(Double TotLossQ)
  {
    this.TotLossQ = TotLossQ;
  }
    
  public Double getTotDCLoss()
  {
    return TotDCLoss;
  }
    
  public void setTotDCLoss(Double TotDCLoss)
  {
    this.TotDCLoss = TotDCLoss;
  }
    
  public String toString()
  {
    return "BpaDat_Case ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Case_CaseID = " + Case_CaseID
	 + ", Case_Project = " + Case_Project
	 + ", Case_MVABase = " + Case_MVABase
	 + ", Case_Control = " + Case_Control
	 + ", Case_Branch = " + Case_Branch
	 + ", Case_Bus = " + Case_Bus
	 + ", Case_Network = " + Case_Network
	 + ", Case_RXCheck = " + Case_RXCheck
	 + ", Case_NewBase = " + Case_NewBase
	 + ", Case_OldBase = " + Case_OldBase
	 + ", Case_Map = " + Case_Map
	 + ", Case_AIControl = " + Case_AIControl
	 + ", Case_LTC = " + Case_LTC
	 + ", Case_DecoupledNum = " + Case_DecoupledNum
	 + ", Case_CurrentNum = " + Case_CurrentNum
	 + ", Case_NewtonNum = " + Case_NewtonNum
	 + ", Case_OptimNum = " + Case_OptimNum
	 + ", Case_ToleranceBusV = " + Case_ToleranceBusV
	 + ", Case_ToleranceAIPower = " + Case_ToleranceAIPower
	 + ", Case_ToleranceTX = " + Case_ToleranceTX
	 + ", Case_ToleranceQ = " + Case_ToleranceQ
	 + ", Case_ToleranceOpcut = " + Case_ToleranceOpcut
	 + ", Case_RptSort = " + Case_RptSort
	 + ", Case_AnalysisRpt = " + Case_AnalysisRpt
	 + ", IslandNum = " + IslandNum
	 + ", TotGenP = " + TotGenP
	 + ", TotGenQ = " + TotGenQ
	 + ", TotLoadP = " + TotLoadP
	 + ", TotLoadQ = " + TotLoadQ
	 + ", TotLineCap = " + TotLineCap
	 + ", TotLossP = " + TotLossP
	 + ", TotLossQ = " + TotLossQ
	 + ", TotDCLoss = " + TotDCLoss+"]";
  }
    
}
    
