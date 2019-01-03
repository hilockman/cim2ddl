package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*统一潮流控制器	*
***********************/
public class UPFC  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //交流线路名称
  private String Name;
  
  //串联母线名
  private String SeriesBus;
  
  //并联母线名
  private String ParallelBus;
  
  //容量(兆伏安)
  private Double Capacity;
  
  //故障率(次/年)
  private Double Rerr;
  
  //修复率(次/年)
  private Double Rrep;
  
  //修复时间(小时/次)
  private Double Trep;
  
  //完好概率
  private Double GoodProb;
  
  //故障概率
  private Double FailProb;
  
  //实际值
  private Double IRt;
  
  //下限值
  private Double IMax;
  
  //上限值
  private Double IMin;
  
  //故障率上限值
  private Double RerrMax;
  
  //故障率下限值
  private Double RerrMin;
  
  //串联侧注入功率(兆瓦)
  private Double LinePse;
  
  //串联侧控制功率(兆瓦)
  private Double P;
  
  //故障次数(次)
  private Integer FaultFreq;
  
  //串联母线索引
  private Integer SeriesBusPtr;
  
  //并联母线索引
  private Integer ParallelBusPtr;
  
  //交流线路索引
  private Integer ACLinePtr;
  
  //停运
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
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public String getSeriesBus()
  {
    return SeriesBus;
  }
    
  public void setSeriesBus(String SeriesBus)
  {
    this.SeriesBus = SeriesBus;
  }
    
  public String getParallelBus()
  {
    return ParallelBus;
  }
    
  public void setParallelBus(String ParallelBus)
  {
    this.ParallelBus = ParallelBus;
  }
    
  public Double getCapacity()
  {
    return Capacity;
  }
    
  public void setCapacity(Double Capacity)
  {
    this.Capacity = Capacity;
  }
    
  public Double getRerr()
  {
    return Rerr;
  }
    
  public void setRerr(Double Rerr)
  {
    this.Rerr = Rerr;
  }
    
  public Double getRrep()
  {
    return Rrep;
  }
    
  public void setRrep(Double Rrep)
  {
    this.Rrep = Rrep;
  }
    
  public Double getTrep()
  {
    return Trep;
  }
    
  public void setTrep(Double Trep)
  {
    this.Trep = Trep;
  }
    
  public Double getGoodProb()
  {
    return GoodProb;
  }
    
  public void setGoodProb(Double GoodProb)
  {
    this.GoodProb = GoodProb;
  }
    
  public Double getFailProb()
  {
    return FailProb;
  }
    
  public void setFailProb(Double FailProb)
  {
    this.FailProb = FailProb;
  }
    
  public Double getIRt()
  {
    return IRt;
  }
    
  public void setIRt(Double IRt)
  {
    this.IRt = IRt;
  }
    
  public Double getIMax()
  {
    return IMax;
  }
    
  public void setIMax(Double IMax)
  {
    this.IMax = IMax;
  }
    
  public Double getIMin()
  {
    return IMin;
  }
    
  public void setIMin(Double IMin)
  {
    this.IMin = IMin;
  }
    
  public Double getRerrMax()
  {
    return RerrMax;
  }
    
  public void setRerrMax(Double RerrMax)
  {
    this.RerrMax = RerrMax;
  }
    
  public Double getRerrMin()
  {
    return RerrMin;
  }
    
  public void setRerrMin(Double RerrMin)
  {
    this.RerrMin = RerrMin;
  }
    
  public Double getLinePse()
  {
    return LinePse;
  }
    
  public void setLinePse(Double LinePse)
  {
    this.LinePse = LinePse;
  }
    
  public Double getP()
  {
    return P;
  }
    
  public void setP(Double P)
  {
    this.P = P;
  }
    
  public Integer getFaultFreq()
  {
    return FaultFreq;
  }
    
  public void setFaultFreq(Integer FaultFreq)
  {
    this.FaultFreq = FaultFreq;
  }
    
  public Integer getSeriesBusPtr()
  {
    return SeriesBusPtr;
  }
    
  public void setSeriesBusPtr(Integer SeriesBusPtr)
  {
    this.SeriesBusPtr = SeriesBusPtr;
  }
    
  public Integer getParallelBusPtr()
  {
    return ParallelBusPtr;
  }
    
  public void setParallelBusPtr(Integer ParallelBusPtr)
  {
    this.ParallelBusPtr = ParallelBusPtr;
  }
    
  public Integer getACLinePtr()
  {
    return ACLinePtr;
  }
    
  public void setACLinePtr(Integer ACLinePtr)
  {
    this.ACLinePtr = ACLinePtr;
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
    return "UPFC ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", SeriesBus = " + SeriesBus
	 + ", ParallelBus = " + ParallelBus
	 + ", Capacity = " + Capacity
	 + ", Rerr = " + Rerr
	 + ", Rrep = " + Rrep
	 + ", Trep = " + Trep
	 + ", GoodProb = " + GoodProb
	 + ", FailProb = " + FailProb
	 + ", IRt = " + IRt
	 + ", IMax = " + IMax
	 + ", IMin = " + IMin
	 + ", RerrMax = " + RerrMax
	 + ", RerrMin = " + RerrMin
	 + ", LinePse = " + LinePse
	 + ", P = " + P
	 + ", FaultFreq = " + FaultFreq
	 + ", SeriesBusPtr = " + SeriesBusPtr
	 + ", ParallelBusPtr = " + ParallelBusPtr
	 + ", ACLinePtr = " + ACLinePtr
	 + ", Outage = " + Outage+"]";
  }
    
}
    
