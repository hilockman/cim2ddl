package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*开断故障信息	*
***********************/
public class Trip  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //开断设备数
  private Integer TripDevNum;
  
  //开断设备1类型
  private Integer TrB1Type;
  
  //开断设备1索引
  private Integer TrB1Bran;
  
  //开断设备2类型
  private Integer TrB2Type;
  
  //开断设备2索引
  private Integer TrB2Bran;
  
  //故障类型
  private Integer FaultType;
  
  //失电总负荷
  private Double OutageLoadP;
  
  //是否越限
  private Integer OverLmt;
  
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
    return TripDevNum;
  }
    
  public void setTripDevNum(Integer TripDevNum)
  {
    this.TripDevNum = TripDevNum;
  }
    
  public Integer getTrB1Type()
  {
    return TrB1Type;
  }
    
  public void setTrB1Type(Integer TrB1Type)
  {
    this.TrB1Type = TrB1Type;
  }
    
  public Integer getTrB1Bran()
  {
    return TrB1Bran;
  }
    
  public void setTrB1Bran(Integer TrB1Bran)
  {
    this.TrB1Bran = TrB1Bran;
  }
    
  public Integer getTrB2Type()
  {
    return TrB2Type;
  }
    
  public void setTrB2Type(Integer TrB2Type)
  {
    this.TrB2Type = TrB2Type;
  }
    
  public Integer getTrB2Bran()
  {
    return TrB2Bran;
  }
    
  public void setTrB2Bran(Integer TrB2Bran)
  {
    this.TrB2Bran = TrB2Bran;
  }
    
  public Integer getFaultType()
  {
    return FaultType;
  }
    
  public void setFaultType(Integer FaultType)
  {
    this.FaultType = FaultType;
  }
    
  public Double getOutageLoadP()
  {
    return OutageLoadP;
  }
    
  public void setOutageLoadP(Double OutageLoadP)
  {
    this.OutageLoadP = OutageLoadP;
  }
    
  public Integer getOverLmt()
  {
    return OverLmt;
  }
    
  public void setOverLmt(Integer OverLmt)
  {
    this.OverLmt = OverLmt;
  }
    
  public String toString()
  {
    return "Trip ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", TripDevNum = " + TripDevNum
	 + ", TrB1Type = " + TrB1Type
	 + ", TrB1Bran = " + TrB1Bran
	 + ", TrB2Type = " + TrB2Type
	 + ", TrB2Bran = " + TrB2Bran
	 + ", FaultType = " + FaultType
	 + ", OutageLoadP = " + OutageLoadP
	 + ", OverLmt = " + OverLmt+"]";
  }
    
}
    
