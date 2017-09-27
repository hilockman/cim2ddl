package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*变换器	*
***********************/
@Entity
public class Converter
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String name;
  
  //交流节点名称
  private String busAC;
  
  //直流节点名称
  private String busDC;
  
  //安排的功率(MW)
  private Double schedPower;
  
  //变换器类型
  private Integer type;
  
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
  
  //交流节点索引
  private Integer aCBusPtr;
  
  //直流节点索引
  private Integer dCBusPtr;
  
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
    
  public String getBusAC() 
  {
    return busAC;
  }
    
  public void setBusAC(String busAC)
  {
    this.busAC = busAC;
  }
    
  public String getBusDC() 
  {
    return busDC;
  }
    
  public void setBusDC(String busDC)
  {
    this.busDC = busDC;
  }
    
  public Double getSchedPower() 
  {
    return schedPower;
  }
    
  public void setSchedPower(Double schedPower)
  {
    this.schedPower = schedPower;
  }
    
  public Integer getType() 
  {
    return type;
  }
    
  public void setType(Integer type)
  {
    this.type = type;
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
    
  public Integer getACBusPtr() 
  {
    return aCBusPtr;
  }
    
  public void setACBusPtr(Integer aCBusPtr)
  {
    this.aCBusPtr = aCBusPtr;
  }
    
  public Integer getDCBusPtr() 
  {
    return dCBusPtr;
  }
    
  public void setDCBusPtr(Integer dCBusPtr)
  {
    this.dCBusPtr = dCBusPtr;
  }
    
  public Integer getOutage() 
  {
    return outage;
  }
    
  public void setOutage(Integer outage)
  {
    this.outage = outage;
  }
    
}
    
