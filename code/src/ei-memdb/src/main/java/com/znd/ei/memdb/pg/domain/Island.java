package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*岛	*
***********************/
public class Island  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //岛平衡机厂站
  private String SlackSub;
  
  //岛平衡机名称
  private String SlackGen;
  
  //发电机索引
  private Integer GenPtr;
  
  //岛发电有功(MW)
  private Double UnitP;
  
  //岛发电无功(MVar)
  private Double UnitQ;
  
  //岛负荷有功(MW)
  private Double LoadP;
  
  //岛负荷无功(MVar)
  private Double LoadQ;
  
  //岛并联无功(MVar)
  private Double ShuntQ;
  
  //岛损耗有功(MVar)
  private Double LossP;
  
  //岛损耗无功(MVar)
  private Double LossQ;
  
  //岛内发电机数
  private Integer UnitNum;
  
  //岛内负荷
  private Integer LoadNum;
  
  //岛内补偿数
  private Integer CapNum;
  
  //岛内母线数
  private Integer BusNum;
  
  //岛内线路数
  private Integer LineNum;
  
  //岛内主变数
  private Integer TranNum;
  
  //死岛标志
  private Integer Dead;
  
  //潮流收敛标志
  private Integer PFConvergency;
  
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
    
  public String getSlackSub()
  {
    return SlackSub;
  }
    
  public void setSlackSub(String SlackSub)
  {
    this.SlackSub = SlackSub;
  }
    
  public String getSlackGen()
  {
    return SlackGen;
  }
    
  public void setSlackGen(String SlackGen)
  {
    this.SlackGen = SlackGen;
  }
    
  public Integer getGenPtr()
  {
    return GenPtr;
  }
    
  public void setGenPtr(Integer GenPtr)
  {
    this.GenPtr = GenPtr;
  }
    
  public Double getUnitP()
  {
    return UnitP;
  }
    
  public void setUnitP(Double UnitP)
  {
    this.UnitP = UnitP;
  }
    
  public Double getUnitQ()
  {
    return UnitQ;
  }
    
  public void setUnitQ(Double UnitQ)
  {
    this.UnitQ = UnitQ;
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
    
  public Double getShuntQ()
  {
    return ShuntQ;
  }
    
  public void setShuntQ(Double ShuntQ)
  {
    this.ShuntQ = ShuntQ;
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
    
  public Integer getUnitNum()
  {
    return UnitNum;
  }
    
  public void setUnitNum(Integer UnitNum)
  {
    this.UnitNum = UnitNum;
  }
    
  public Integer getLoadNum()
  {
    return LoadNum;
  }
    
  public void setLoadNum(Integer LoadNum)
  {
    this.LoadNum = LoadNum;
  }
    
  public Integer getCapNum()
  {
    return CapNum;
  }
    
  public void setCapNum(Integer CapNum)
  {
    this.CapNum = CapNum;
  }
    
  public Integer getBusNum()
  {
    return BusNum;
  }
    
  public void setBusNum(Integer BusNum)
  {
    this.BusNum = BusNum;
  }
    
  public Integer getLineNum()
  {
    return LineNum;
  }
    
  public void setLineNum(Integer LineNum)
  {
    this.LineNum = LineNum;
  }
    
  public Integer getTranNum()
  {
    return TranNum;
  }
    
  public void setTranNum(Integer TranNum)
  {
    this.TranNum = TranNum;
  }
    
  public Integer getDead()
  {
    return Dead;
  }
    
  public void setDead(Integer Dead)
  {
    this.Dead = Dead;
  }
    
  public Integer getPFConvergency()
  {
    return PFConvergency;
  }
    
  public void setPFConvergency(Integer PFConvergency)
  {
    this.PFConvergency = PFConvergency;
  }
    
  public String toString()
  {
    return "Island ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", SlackSub = " + SlackSub
	 + ", SlackGen = " + SlackGen
	 + ", GenPtr = " + GenPtr
	 + ", UnitP = " + UnitP
	 + ", UnitQ = " + UnitQ
	 + ", LoadP = " + LoadP
	 + ", LoadQ = " + LoadQ
	 + ", ShuntQ = " + ShuntQ
	 + ", LossP = " + LossP
	 + ", LossQ = " + LossQ
	 + ", UnitNum = " + UnitNum
	 + ", LoadNum = " + LoadNum
	 + ", CapNum = " + CapNum
	 + ", BusNum = " + BusNum
	 + ", LineNum = " + LineNum
	 + ", TranNum = " + TranNum
	 + ", Dead = " + Dead
	 + ", PFConvergency = " + PFConvergency+"]";
  }
    
}
    
