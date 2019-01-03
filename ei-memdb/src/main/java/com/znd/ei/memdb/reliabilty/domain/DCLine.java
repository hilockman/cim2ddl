package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*直流线路	*
***********************/
public class DCLine  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String Name;
  
  //I侧直流节点名称
  private String DCBusI;
  
  //J侧直流节点名称
  private String DCBusJ;
  
  //长度(千米)
  private Double Length;
  
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
  
  //故障次数(次)
  private Integer FaultFreq;
  
  //I侧直流节点索引
  private Integer DCBusIPtr;
  
  //J侧直流节点索引
  private Integer DCBusJPtr;
  
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
    
  public String getDCBusI()
  {
    return DCBusI;
  }
    
  public void setDCBusI(String DCBusI)
  {
    this.DCBusI = DCBusI;
  }
    
  public String getDCBusJ()
  {
    return DCBusJ;
  }
    
  public void setDCBusJ(String DCBusJ)
  {
    this.DCBusJ = DCBusJ;
  }
    
  public Double getLength()
  {
    return Length;
  }
    
  public void setLength(Double Length)
  {
    this.Length = Length;
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
    
  public Integer getFaultFreq()
  {
    return FaultFreq;
  }
    
  public void setFaultFreq(Integer FaultFreq)
  {
    this.FaultFreq = FaultFreq;
  }
    
  public Integer getDCBusIPtr()
  {
    return DCBusIPtr;
  }
    
  public void setDCBusIPtr(Integer DCBusIPtr)
  {
    this.DCBusIPtr = DCBusIPtr;
  }
    
  public Integer getDCBusJPtr()
  {
    return DCBusJPtr;
  }
    
  public void setDCBusJPtr(Integer DCBusJPtr)
  {
    this.DCBusJPtr = DCBusJPtr;
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
    return "DCLine ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", DCBusI = " + DCBusI
	 + ", DCBusJ = " + DCBusJ
	 + ", Length = " + Length
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
	 + ", FaultFreq = " + FaultFreq
	 + ", DCBusIPtr = " + DCBusIPtr
	 + ", DCBusJPtr = " + DCBusJPtr
	 + ", Outage = " + Outage+"]";
  }
    
}
    
