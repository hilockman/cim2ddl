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
  private String case_CaseID;
  
  //工程名
  private String case_Project;
  
  //指定的系统基准容量
  private Double case_MVABase;
  
  //所指定的控制语句文件
  private String case_Control;
  
  //所指定的支路数据
  private String case_Branch;
  
  //所指定的母线数据
  private String case_Bus;
  
  //所指定的数据文件
  private String case_Network;
  
  //RX比值检查
  private Integer case_RXCheck;
  
  //潮流结果二进制文件(.BSE)
  private String case_NewBase;
  
  //指定老库文件
  private String case_OldBase;
  
  //生成潮流图二进制结果文件
  private String case_Map;
  
  //区域联络线功率控制选择
  private Integer case_AIControl;
  
  //带负荷调压变压器控制选择
  private Integer case_LTC;
  
  //PQ解耦法
  private Integer case_DecoupledNum;
  
  //改进的牛顿拉夫逊算法
  private Integer case_CurrentNum;
  
  //牛顿拉夫逊算法
  private Integer case_NewtonNum;
  
  //最优潮流法
  private Integer case_OptimNum;
  
  //BusV允许误差,缺省值：0.005
  private Double case_ToleranceBusV;
  
  //AIPower允许误差,缺省值：0.005
  private Double case_ToleranceAIPower;
  
  //TX允许误差,缺省值：0.005
  private Double case_ToleranceTX;
  
  //Q允许误差,缺省值：0.005
  private Double case_ToleranceQ;
  
  //OPCUT允许误差,缺省值：0.0001
  private Double case_ToleranceOpcut;
  
  //输出分类,输出顺序控制语句
  private Integer case_RptSort;
  
  //分析报告输出,指定输出等级
  private Integer case_AnalysisRpt;
  
  //电岛数
  private Integer islandNum;
  
  //总发电有功
  private Double totGenP;
  
  //总发电无功
  private Double totGenQ;
  
  //总负荷有功
  private Double totLoadP;
  
  //总负荷无功
  private Double totLoadQ;
  
  //线路充电无功
  private Double totLineCap;
  
  //总损耗有功
  private Double totLossP;
  
  //总损耗无功
  private Double totLossQ;
  
  //直流换流器损耗
  private Double totDCLoss;
  
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
    return case_CaseID;
  }
    
  public void setCase_CaseID(String case_CaseID)
  {
    this.case_CaseID = case_CaseID;
  }
    
  public String getCase_Project()
  {
    return case_Project;
  }
    
  public void setCase_Project(String case_Project)
  {
    this.case_Project = case_Project;
  }
    
  public Double getCase_MVABase()
  {
    return case_MVABase;
  }
    
  public void setCase_MVABase(Double case_MVABase)
  {
    this.case_MVABase = case_MVABase;
  }
    
  public String getCase_Control()
  {
    return case_Control;
  }
    
  public void setCase_Control(String case_Control)
  {
    this.case_Control = case_Control;
  }
    
  public String getCase_Branch()
  {
    return case_Branch;
  }
    
  public void setCase_Branch(String case_Branch)
  {
    this.case_Branch = case_Branch;
  }
    
  public String getCase_Bus()
  {
    return case_Bus;
  }
    
  public void setCase_Bus(String case_Bus)
  {
    this.case_Bus = case_Bus;
  }
    
  public String getCase_Network()
  {
    return case_Network;
  }
    
  public void setCase_Network(String case_Network)
  {
    this.case_Network = case_Network;
  }
    
  public Integer getCase_RXCheck()
  {
    return case_RXCheck;
  }
    
  public void setCase_RXCheck(Integer case_RXCheck)
  {
    this.case_RXCheck = case_RXCheck;
  }
    
  public String getCase_NewBase()
  {
    return case_NewBase;
  }
    
  public void setCase_NewBase(String case_NewBase)
  {
    this.case_NewBase = case_NewBase;
  }
    
  public String getCase_OldBase()
  {
    return case_OldBase;
  }
    
  public void setCase_OldBase(String case_OldBase)
  {
    this.case_OldBase = case_OldBase;
  }
    
  public String getCase_Map()
  {
    return case_Map;
  }
    
  public void setCase_Map(String case_Map)
  {
    this.case_Map = case_Map;
  }
    
  public Integer getCase_AIControl()
  {
    return case_AIControl;
  }
    
  public void setCase_AIControl(Integer case_AIControl)
  {
    this.case_AIControl = case_AIControl;
  }
    
  public Integer getCase_LTC()
  {
    return case_LTC;
  }
    
  public void setCase_LTC(Integer case_LTC)
  {
    this.case_LTC = case_LTC;
  }
    
  public Integer getCase_DecoupledNum()
  {
    return case_DecoupledNum;
  }
    
  public void setCase_DecoupledNum(Integer case_DecoupledNum)
  {
    this.case_DecoupledNum = case_DecoupledNum;
  }
    
  public Integer getCase_CurrentNum()
  {
    return case_CurrentNum;
  }
    
  public void setCase_CurrentNum(Integer case_CurrentNum)
  {
    this.case_CurrentNum = case_CurrentNum;
  }
    
  public Integer getCase_NewtonNum()
  {
    return case_NewtonNum;
  }
    
  public void setCase_NewtonNum(Integer case_NewtonNum)
  {
    this.case_NewtonNum = case_NewtonNum;
  }
    
  public Integer getCase_OptimNum()
  {
    return case_OptimNum;
  }
    
  public void setCase_OptimNum(Integer case_OptimNum)
  {
    this.case_OptimNum = case_OptimNum;
  }
    
  public Double getCase_ToleranceBusV()
  {
    return case_ToleranceBusV;
  }
    
  public void setCase_ToleranceBusV(Double case_ToleranceBusV)
  {
    this.case_ToleranceBusV = case_ToleranceBusV;
  }
    
  public Double getCase_ToleranceAIPower()
  {
    return case_ToleranceAIPower;
  }
    
  public void setCase_ToleranceAIPower(Double case_ToleranceAIPower)
  {
    this.case_ToleranceAIPower = case_ToleranceAIPower;
  }
    
  public Double getCase_ToleranceTX()
  {
    return case_ToleranceTX;
  }
    
  public void setCase_ToleranceTX(Double case_ToleranceTX)
  {
    this.case_ToleranceTX = case_ToleranceTX;
  }
    
  public Double getCase_ToleranceQ()
  {
    return case_ToleranceQ;
  }
    
  public void setCase_ToleranceQ(Double case_ToleranceQ)
  {
    this.case_ToleranceQ = case_ToleranceQ;
  }
    
  public Double getCase_ToleranceOpcut()
  {
    return case_ToleranceOpcut;
  }
    
  public void setCase_ToleranceOpcut(Double case_ToleranceOpcut)
  {
    this.case_ToleranceOpcut = case_ToleranceOpcut;
  }
    
  public Integer getCase_RptSort()
  {
    return case_RptSort;
  }
    
  public void setCase_RptSort(Integer case_RptSort)
  {
    this.case_RptSort = case_RptSort;
  }
    
  public Integer getCase_AnalysisRpt()
  {
    return case_AnalysisRpt;
  }
    
  public void setCase_AnalysisRpt(Integer case_AnalysisRpt)
  {
    this.case_AnalysisRpt = case_AnalysisRpt;
  }
    
  public Integer getIslandNum()
  {
    return islandNum;
  }
    
  public void setIslandNum(Integer islandNum)
  {
    this.islandNum = islandNum;
  }
    
  public Double getTotGenP()
  {
    return totGenP;
  }
    
  public void setTotGenP(Double totGenP)
  {
    this.totGenP = totGenP;
  }
    
  public Double getTotGenQ()
  {
    return totGenQ;
  }
    
  public void setTotGenQ(Double totGenQ)
  {
    this.totGenQ = totGenQ;
  }
    
  public Double getTotLoadP()
  {
    return totLoadP;
  }
    
  public void setTotLoadP(Double totLoadP)
  {
    this.totLoadP = totLoadP;
  }
    
  public Double getTotLoadQ()
  {
    return totLoadQ;
  }
    
  public void setTotLoadQ(Double totLoadQ)
  {
    this.totLoadQ = totLoadQ;
  }
    
  public Double getTotLineCap()
  {
    return totLineCap;
  }
    
  public void setTotLineCap(Double totLineCap)
  {
    this.totLineCap = totLineCap;
  }
    
  public Double getTotLossP()
  {
    return totLossP;
  }
    
  public void setTotLossP(Double totLossP)
  {
    this.totLossP = totLossP;
  }
    
  public Double getTotLossQ()
  {
    return totLossQ;
  }
    
  public void setTotLossQ(Double totLossQ)
  {
    this.totLossQ = totLossQ;
  }
    
  public Double getTotDCLoss()
  {
    return totDCLoss;
  }
    
  public void setTotDCLoss(Double totDCLoss)
  {
    this.totDCLoss = totDCLoss;
  }
    
  public String toString()
  {
    return "BpaDat_Case ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", case_CaseID = " + case_CaseID
	 + ", case_Project = " + case_Project
	 + ", case_MVABase = " + case_MVABase
	 + ", case_Control = " + case_Control
	 + ", case_Branch = " + case_Branch
	 + ", case_Bus = " + case_Bus
	 + ", case_Network = " + case_Network
	 + ", case_RXCheck = " + case_RXCheck
	 + ", case_NewBase = " + case_NewBase
	 + ", case_OldBase = " + case_OldBase
	 + ", case_Map = " + case_Map
	 + ", case_AIControl = " + case_AIControl
	 + ", case_LTC = " + case_LTC
	 + ", case_DecoupledNum = " + case_DecoupledNum
	 + ", case_CurrentNum = " + case_CurrentNum
	 + ", case_NewtonNum = " + case_NewtonNum
	 + ", case_OptimNum = " + case_OptimNum
	 + ", case_ToleranceBusV = " + case_ToleranceBusV
	 + ", case_ToleranceAIPower = " + case_ToleranceAIPower
	 + ", case_ToleranceTX = " + case_ToleranceTX
	 + ", case_ToleranceQ = " + case_ToleranceQ
	 + ", case_ToleranceOpcut = " + case_ToleranceOpcut
	 + ", case_RptSort = " + case_RptSort
	 + ", case_AnalysisRpt = " + case_AnalysisRpt
	 + ", islandNum = " + islandNum
	 + ", totGenP = " + totGenP
	 + ", totGenQ = " + totGenQ
	 + ", totLoadP = " + totLoadP
	 + ", totLoadQ = " + totLoadQ
	 + ", totLineCap = " + totLineCap
	 + ", totLossP = " + totLossP
	 + ", totLossQ = " + totLossQ
	 + ", totDCLoss = " + totDCLoss+"]";
  }
    
}
    
