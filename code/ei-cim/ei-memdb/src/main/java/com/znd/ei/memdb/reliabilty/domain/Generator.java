package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*发电机	*
***********************/
@Entity
public class Generator
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //名称
  private String name;
  
  //母线
  private String busName;
  
  //电压(kV)
  private Double buskV;
  
  //编号
  private Integer genId;
  
  //分区
  private String zone;
  
  //有功(MW)
  private Double p;
  
  //无功(MVar)
  private Double q;
  
  //最大有功(MW)
  private Double pMax;
  
  //最小有功(MW)
  private Double pMin;
  
  //最大无功(MVar)
  private Double qMax;
  
  //最小无功(MVar)
  private Double qMin;
  
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
  
  //多状态模型
  private Integer mSModel;
  
  //多状态状态数
  private Integer mStateNum;
  
  //多状态状态
  private Double mSPout;
  
  //给定有功(MW)
  private Double referenceP;
  
  //给定无功(MVar)
  private Double referenceQ;
  
  //故障次数(次)
  private Integer faultFreq;
  
  //等值电源标记
  private Integer eQGen;
  
  //环辐网编号
  private Integer radial;
  
  //母线索引
  private Integer busPtr;
  
  //可靠性参数类型
  private Integer rParamType;
  
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
    
  public String getName() 
  {
    return name;
  }
    
  public void setName(String name)
  {
    this.name = name;
  }
    
  public String getBusName() 
  {
    return busName;
  }
    
  public void setBusName(String busName)
  {
    this.busName = busName;
  }
    
  public Double getBuskV() 
  {
    return buskV;
  }
    
  public void setBuskV(Double buskV)
  {
    this.buskV = buskV;
  }
    
  public Integer getGenId() 
  {
    return genId;
  }
    
  public void setGenId(Integer genId)
  {
    this.genId = genId;
  }
    
  public String getZone() 
  {
    return zone;
  }
    
  public void setZone(String zone)
  {
    this.zone = zone;
  }
    
  public Double getP() 
  {
    return p;
  }
    
  public void setP(Double p)
  {
    this.p = p;
  }
    
  public Double getQ() 
  {
    return q;
  }
    
  public void setQ(Double q)
  {
    this.q = q;
  }
    
  public Double getPMax() 
  {
    return pMax;
  }
    
  public void setPMax(Double pMax)
  {
    this.pMax = pMax;
  }
    
  public Double getPMin() 
  {
    return pMin;
  }
    
  public void setPMin(Double pMin)
  {
    this.pMin = pMin;
  }
    
  public Double getQMax() 
  {
    return qMax;
  }
    
  public void setQMax(Double qMax)
  {
    this.qMax = qMax;
  }
    
  public Double getQMin() 
  {
    return qMin;
  }
    
  public void setQMin(Double qMin)
  {
    this.qMin = qMin;
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
    
  public Integer getMSModel() 
  {
    return mSModel;
  }
    
  public void setMSModel(Integer mSModel)
  {
    this.mSModel = mSModel;
  }
    
  public Integer getMStateNum() 
  {
    return mStateNum;
  }
    
  public void setMStateNum(Integer mStateNum)
  {
    this.mStateNum = mStateNum;
  }
    
  public Double getMSPout() 
  {
    return mSPout;
  }
    
  public void setMSPout(Double mSPout)
  {
    this.mSPout = mSPout;
  }
    
  public Double getReferenceP() 
  {
    return referenceP;
  }
    
  public void setReferenceP(Double referenceP)
  {
    this.referenceP = referenceP;
  }
    
  public Double getReferenceQ() 
  {
    return referenceQ;
  }
    
  public void setReferenceQ(Double referenceQ)
  {
    this.referenceQ = referenceQ;
  }
    
  public Integer getFaultFreq() 
  {
    return faultFreq;
  }
    
  public void setFaultFreq(Integer faultFreq)
  {
    this.faultFreq = faultFreq;
  }
    
  public Integer getEQGen() 
  {
    return eQGen;
  }
    
  public void setEQGen(Integer eQGen)
  {
    this.eQGen = eQGen;
  }
    
  public Integer getRadial() 
  {
    return radial;
  }
    
  public void setRadial(Integer radial)
  {
    this.radial = radial;
  }
    
  public Integer getBusPtr() 
  {
    return busPtr;
  }
    
  public void setBusPtr(Integer busPtr)
  {
    this.busPtr = busPtr;
  }
    
  public Integer getRParamType() 
  {
    return rParamType;
  }
    
  public void setRParamType(Integer rParamType)
  {
    this.rParamType = rParamType;
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
    
