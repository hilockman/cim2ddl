package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*停运发电	*
***********************/
public class CopGen  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //设备索引
  private Integer SerialNo;
  
  //发电机容量(兆瓦)
  private Double Capacity;
  
  //折算系数
  private Double Alpha;
  
  //发电机折算容量1(兆瓦)
  private Double S1Capacity;
  
  //发电机折算容量2(兆瓦)
  private Double S2Capacity;
  
  //故障率(次/天)
  private Double Rerr;
  
  //修复时间(天/次)
  private Double Trep;
  
  //修复率(次/天)
  private Double Rrep;
  
  //停运率(次/天)
  private Double Rout;
  
  //三状态
  private Integer ThreeState;
  
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
    
  public Integer getSerialNo()
  {
    return SerialNo;
  }
    
  public void setSerialNo(Integer SerialNo)
  {
    this.SerialNo = SerialNo;
  }
    
  public Double getCapacity()
  {
    return Capacity;
  }
    
  public void setCapacity(Double Capacity)
  {
    this.Capacity = Capacity;
  }
    
  public Double getAlpha()
  {
    return Alpha;
  }
    
  public void setAlpha(Double Alpha)
  {
    this.Alpha = Alpha;
  }
    
  public Double getS1Capacity()
  {
    return S1Capacity;
  }
    
  public void setS1Capacity(Double S1Capacity)
  {
    this.S1Capacity = S1Capacity;
  }
    
  public Double getS2Capacity()
  {
    return S2Capacity;
  }
    
  public void setS2Capacity(Double S2Capacity)
  {
    this.S2Capacity = S2Capacity;
  }
    
  public Double getRerr()
  {
    return Rerr;
  }
    
  public void setRerr(Double Rerr)
  {
    this.Rerr = Rerr;
  }
    
  public Double getTrep()
  {
    return Trep;
  }
    
  public void setTrep(Double Trep)
  {
    this.Trep = Trep;
  }
    
  public Double getRrep()
  {
    return Rrep;
  }
    
  public void setRrep(Double Rrep)
  {
    this.Rrep = Rrep;
  }
    
  public Double getRout()
  {
    return Rout;
  }
    
  public void setRout(Double Rout)
  {
    this.Rout = Rout;
  }
    
  public Integer getThreeState()
  {
    return ThreeState;
  }
    
  public void setThreeState(Integer ThreeState)
  {
    this.ThreeState = ThreeState;
  }
    
  public String toString()
  {
    return "CopGen ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", SerialNo = " + SerialNo
	 + ", Capacity = " + Capacity
	 + ", Alpha = " + Alpha
	 + ", S1Capacity = " + S1Capacity
	 + ", S2Capacity = " + S2Capacity
	 + ", Rerr = " + Rerr
	 + ", Trep = " + Trep
	 + ", Rrep = " + Rrep
	 + ", Rout = " + Rout
	 + ", ThreeState = " + ThreeState+"]";
  }
    
}
    
