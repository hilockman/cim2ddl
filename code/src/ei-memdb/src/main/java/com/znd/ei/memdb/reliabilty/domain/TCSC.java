package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*可控串联补偿装置	*
***********************/
public class TCSC  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //交流线路名称
  private String name;
  
  //安装母线名
  private String installBus;
  
  //串联电抗值(pu)
  private Double x;
  
  //故障率(次/年)
  private Double rerr;
  
  //修复率(次/年)
  private Double rrep;
  
  //修复时间(小时/次)
  private Double trep;
  
  //完好概率
  private Double goodProb;
  
  //故障概率
  private Double failProb;
  
  //实际值
  private Double iRt;
  
  //下限值
  private Double iMax;
  
  //上限值
  private Double iMin;
  
  //故障率上限值
  private Double rerrMax;
  
  //故障率下限值
  private Double rerrMin;
  
  //故障次数(次)
  private Integer faultFreq;
  
  //安装母线索引
  private Integer instBusPtr;
  
  //交流线路索引
  private Integer aCLinePtr;
  
  //停运
  private Integer outage;
  
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
    return name;
  }
    
  public void setName(String name)
  {
    this.name = name;
  }
    
  public String getInstallBus()
  {
    return installBus;
  }
    
  public void setInstallBus(String installBus)
  {
    this.installBus = installBus;
  }
    
  public Double getX()
  {
    return x;
  }
    
  public void setX(Double x)
  {
    this.x = x;
  }
    
  public Double getRerr()
  {
    return rerr;
  }
    
  public void setRerr(Double rerr)
  {
    this.rerr = rerr;
  }
    
  public Double getRrep()
  {
    return rrep;
  }
    
  public void setRrep(Double rrep)
  {
    this.rrep = rrep;
  }
    
  public Double getTrep()
  {
    return trep;
  }
    
  public void setTrep(Double trep)
  {
    this.trep = trep;
  }
    
  public Double getGoodProb()
  {
    return goodProb;
  }
    
  public void setGoodProb(Double goodProb)
  {
    this.goodProb = goodProb;
  }
    
  public Double getFailProb()
  {
    return failProb;
  }
    
  public void setFailProb(Double failProb)
  {
    this.failProb = failProb;
  }
    
  public Double getIRt()
  {
    return iRt;
  }
    
  public void setIRt(Double iRt)
  {
    this.iRt = iRt;
  }
    
  public Double getIMax()
  {
    return iMax;
  }
    
  public void setIMax(Double iMax)
  {
    this.iMax = iMax;
  }
    
  public Double getIMin()
  {
    return iMin;
  }
    
  public void setIMin(Double iMin)
  {
    this.iMin = iMin;
  }
    
  public Double getRerrMax()
  {
    return rerrMax;
  }
    
  public void setRerrMax(Double rerrMax)
  {
    this.rerrMax = rerrMax;
  }
    
  public Double getRerrMin()
  {
    return rerrMin;
  }
    
  public void setRerrMin(Double rerrMin)
  {
    this.rerrMin = rerrMin;
  }
    
  public Integer getFaultFreq()
  {
    return faultFreq;
  }
    
  public void setFaultFreq(Integer faultFreq)
  {
    this.faultFreq = faultFreq;
  }
    
  public Integer getInstBusPtr()
  {
    return instBusPtr;
  }
    
  public void setInstBusPtr(Integer instBusPtr)
  {
    this.instBusPtr = instBusPtr;
  }
    
  public Integer getACLinePtr()
  {
    return aCLinePtr;
  }
    
  public void setACLinePtr(Integer aCLinePtr)
  {
    this.aCLinePtr = aCLinePtr;
  }
    
  public Integer getOutage()
  {
    return outage;
  }
    
  public void setOutage(Integer outage)
  {
    this.outage = outage;
  }
    
  public String toString()
  {
    return "TCSC ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", name = " + name
	 + ", installBus = " + installBus
	 + ", x = " + x
	 + ", rerr = " + rerr
	 + ", rrep = " + rrep
	 + ", trep = " + trep
	 + ", goodProb = " + goodProb
	 + ", failProb = " + failProb
	 + ", iRt = " + iRt
	 + ", iMax = " + iMax
	 + ", iMin = " + iMin
	 + ", rerrMax = " + rerrMax
	 + ", rerrMin = " + rerrMin
	 + ", faultFreq = " + faultFreq
	 + ", instBusPtr = " + instBusPtr
	 + ", aCLinePtr = " + aCLinePtr
	 + ", outage = " + outage+"]";
  }
    
}
    
