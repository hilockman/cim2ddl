package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*开断故障信息	*
***********************/
@Entity
public class Trip
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //开断设备数
  private Integer tripDevNum;
  
  //开断设备1类型
  private Integer trB1Type;
  
  //开断设备1索引
  private Integer trB1Bran;
  
  //开断设备2类型
  private Integer trB2Type;
  
  //开断设备2索引
  private Integer trB2Bran;
  
  //故障类型
  private Integer faultType;
  
  //失电总负荷
  private Double outageLoadP;
  
  //是否越限
  private Integer overLmt;
  
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
    
  public Integer getTripDevNum() 
  {
    return tripDevNum;
  }
    
  public void setTripDevNum(Integer tripDevNum)
  {
    this.tripDevNum = tripDevNum;
  }
    
  public Integer getTrB1Type() 
  {
    return trB1Type;
  }
    
  public void setTrB1Type(Integer trB1Type)
  {
    this.trB1Type = trB1Type;
  }
    
  public Integer getTrB1Bran() 
  {
    return trB1Bran;
  }
    
  public void setTrB1Bran(Integer trB1Bran)
  {
    this.trB1Bran = trB1Bran;
  }
    
  public Integer getTrB2Type() 
  {
    return trB2Type;
  }
    
  public void setTrB2Type(Integer trB2Type)
  {
    this.trB2Type = trB2Type;
  }
    
  public Integer getTrB2Bran() 
  {
    return trB2Bran;
  }
    
  public void setTrB2Bran(Integer trB2Bran)
  {
    this.trB2Bran = trB2Bran;
  }
    
  public Integer getFaultType() 
  {
    return faultType;
  }
    
  public void setFaultType(Integer faultType)
  {
    this.faultType = faultType;
  }
    
  public Double getOutageLoadP() 
  {
    return outageLoadP;
  }
    
  public void setOutageLoadP(Double outageLoadP)
  {
    this.outageLoadP = outageLoadP;
  }
    
  public Integer getOverLmt() 
  {
    return overLmt;
  }
    
  public void setOverLmt(Integer overLmt)
  {
    this.overLmt = overLmt;
  }
    
}
    
