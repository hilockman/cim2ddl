package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*停运发电	*
***********************/
@Entity
public class CopGen
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //设备索引
  private Integer serialNo;
  
  //发电机容量(MW)
  private Double capacity;
  
  //折算系数
  private Double alpha;
  
  //发电机折算容量1(MW)
  private Double s1Capacity;
  
  //发电机折算容量2(MW)
  private Double s2Capacity;
  
  //故障率(次/天)
  private Double rerr;
  
  //修复时间(天/次)
  private Double trep;
  
  //修复率(次/天)
  private Double rrep;
  
  //停运率(次/天)
  private Double rout;
  
  //三状态
  private Integer threeState;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public Integer getSerialNo() 
  {
    return serialNo;
  }
    
  public void setSerialNo(Integer serialNo)
  {
    this.serialNo = serialNo;
  }
    
  public Double getCapacity() 
  {
    return capacity;
  }
    
  public void setCapacity(Double capacity)
  {
    this.capacity = capacity;
  }
    
  public Double getAlpha() 
  {
    return alpha;
  }
    
  public void setAlpha(Double alpha)
  {
    this.alpha = alpha;
  }
    
  public Double getS1Capacity() 
  {
    return s1Capacity;
  }
    
  public void setS1Capacity(Double s1Capacity)
  {
    this.s1Capacity = s1Capacity;
  }
    
  public Double getS2Capacity() 
  {
    return s2Capacity;
  }
    
  public void setS2Capacity(Double s2Capacity)
  {
    this.s2Capacity = s2Capacity;
  }
    
  public Double getRerr() 
  {
    return rerr;
  }
    
  public void setRerr(Double rerr)
  {
    this.rerr = rerr;
  }
    
  public Double getTrep() 
  {
    return trep;
  }
    
  public void setTrep(Double trep)
  {
    this.trep = trep;
  }
    
  public Double getRrep() 
  {
    return rrep;
  }
    
  public void setRrep(Double rrep)
  {
    this.rrep = rrep;
  }
    
  public Double getRout() 
  {
    return rout;
  }
    
  public void setRout(Double rout)
  {
    this.rout = rout;
  }
    
  public Integer getThreeState() 
  {
    return threeState;
  }
    
  public void setThreeState(Integer threeState)
  {
    this.threeState = threeState;
  }
    
}
    
