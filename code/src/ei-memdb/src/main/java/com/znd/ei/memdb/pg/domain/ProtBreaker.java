package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*母联(分段)断路器保护	*
***********************/
public class ProtBreaker  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //母联断路器名称
  private String Name;
  
  //拓扑母线
  private Integer TopoBus;
  
  //线路最大额定电流(A)
  private Double ILineMax;
  
  //变压器最大额定电流(A)
  private Double ITranMax;
  
  //低压断路器(以变压器卷为判断原则)
  private Integer LowVBreaker;
  
  //最大短路电流(A)
  private Double IkMax;
  
  //最小短路电流(A)
  private Double IkMin;
  
  //整定:过流Ⅰ段配合系数
  private Double Kkp1;
  
  //整定:过流Ⅰ段灵敏系数
  private Double Kklm1;
  
  //整定:过流Ⅱ段配合系数
  private Double Kkp2;
  
  //整定:合环保护可靠系数
  private Double Kkr;
  
  //过流Ⅰ段保护整定电流(A)
  private Double Ikdz1;
  
  //过流Ⅱ段保护整定电流(A)
  private Double Ikdz2;
  
  //合环保护整定电流(A)
  private Double Irdz;
  
  //校核:过流Ⅰ段灵敏系数
  private Double Ksen1;
  
  //校核:过流Ⅱ段灵敏系数
  private Double Ksen2;
  
  //设备索引
  private Integer BreakerPtr;
  
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
    
  public Integer getTopoBus()
  {
    return TopoBus;
  }
    
  public void setTopoBus(Integer TopoBus)
  {
    this.TopoBus = TopoBus;
  }
    
  public Double getILineMax()
  {
    return ILineMax;
  }
    
  public void setILineMax(Double ILineMax)
  {
    this.ILineMax = ILineMax;
  }
    
  public Double getITranMax()
  {
    return ITranMax;
  }
    
  public void setITranMax(Double ITranMax)
  {
    this.ITranMax = ITranMax;
  }
    
  public Integer getLowVBreaker()
  {
    return LowVBreaker;
  }
    
  public void setLowVBreaker(Integer LowVBreaker)
  {
    this.LowVBreaker = LowVBreaker;
  }
    
  public Double getIkMax()
  {
    return IkMax;
  }
    
  public void setIkMax(Double IkMax)
  {
    this.IkMax = IkMax;
  }
    
  public Double getIkMin()
  {
    return IkMin;
  }
    
  public void setIkMin(Double IkMin)
  {
    this.IkMin = IkMin;
  }
    
  public Double getKkp1()
  {
    return Kkp1;
  }
    
  public void setKkp1(Double Kkp1)
  {
    this.Kkp1 = Kkp1;
  }
    
  public Double getKklm1()
  {
    return Kklm1;
  }
    
  public void setKklm1(Double Kklm1)
  {
    this.Kklm1 = Kklm1;
  }
    
  public Double getKkp2()
  {
    return Kkp2;
  }
    
  public void setKkp2(Double Kkp2)
  {
    this.Kkp2 = Kkp2;
  }
    
  public Double getKkr()
  {
    return Kkr;
  }
    
  public void setKkr(Double Kkr)
  {
    this.Kkr = Kkr;
  }
    
  public Double getIkdz1()
  {
    return Ikdz1;
  }
    
  public void setIkdz1(Double Ikdz1)
  {
    this.Ikdz1 = Ikdz1;
  }
    
  public Double getIkdz2()
  {
    return Ikdz2;
  }
    
  public void setIkdz2(Double Ikdz2)
  {
    this.Ikdz2 = Ikdz2;
  }
    
  public Double getIrdz()
  {
    return Irdz;
  }
    
  public void setIrdz(Double Irdz)
  {
    this.Irdz = Irdz;
  }
    
  public Double getKsen1()
  {
    return Ksen1;
  }
    
  public void setKsen1(Double Ksen1)
  {
    this.Ksen1 = Ksen1;
  }
    
  public Double getKsen2()
  {
    return Ksen2;
  }
    
  public void setKsen2(Double Ksen2)
  {
    this.Ksen2 = Ksen2;
  }
    
  public Integer getBreakerPtr()
  {
    return BreakerPtr;
  }
    
  public void setBreakerPtr(Integer BreakerPtr)
  {
    this.BreakerPtr = BreakerPtr;
  }
    
  public String toString()
  {
    return "ProtBreaker ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", TopoBus = " + TopoBus
	 + ", ILineMax = " + ILineMax
	 + ", ITranMax = " + ITranMax
	 + ", LowVBreaker = " + LowVBreaker
	 + ", IkMax = " + IkMax
	 + ", IkMin = " + IkMin
	 + ", Kkp1 = " + Kkp1
	 + ", Kklm1 = " + Kklm1
	 + ", Kkp2 = " + Kkp2
	 + ", Kkr = " + Kkr
	 + ", Ikdz1 = " + Ikdz1
	 + ", Ikdz2 = " + Ikdz2
	 + ", Irdz = " + Irdz
	 + ", Ksen1 = " + Ksen1
	 + ", Ksen2 = " + Ksen2
	 + ", BreakerPtr = " + BreakerPtr+"]";
  }
    
}
    
