package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*并联电容器保护	*
***********************/
public class ProtCap  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //并联电容器名称
  private String Name;
  
  //拓扑母线
  private Integer TopoBus;
  
  //额定电流(A)
  private Double Rate;
  
  //最大短路电流(A)
  private Double IkMax;
  
  //最小短路电流(A)
  private Double IkMin;
  
  //整定:延时电流速断保护可靠系数
  private Double Kkrel2;
  
  //整定:过流保护可靠系数
  private Double Kkrel3;
  
  //整定:过流保护返回系数
  private Double Kkres3;
  
  //延时电流速断整定电流(A)
  private Double Ikdz2;
  
  //过流保护整定电流(A)
  private Double Ikdz3;
  
  //校核:延时电流速断灵敏系数
  private Double Ksen2;
  
  //校核:过流保护灵敏系数
  private Double Ksen3;
  
  //并联电容器索引
  private Integer CapPtr;
  
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
    
  public Double getRate()
  {
    return Rate;
  }
    
  public void setRate(Double Rate)
  {
    this.Rate = Rate;
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
    
  public Double getKkrel2()
  {
    return Kkrel2;
  }
    
  public void setKkrel2(Double Kkrel2)
  {
    this.Kkrel2 = Kkrel2;
  }
    
  public Double getKkrel3()
  {
    return Kkrel3;
  }
    
  public void setKkrel3(Double Kkrel3)
  {
    this.Kkrel3 = Kkrel3;
  }
    
  public Double getKkres3()
  {
    return Kkres3;
  }
    
  public void setKkres3(Double Kkres3)
  {
    this.Kkres3 = Kkres3;
  }
    
  public Double getIkdz2()
  {
    return Ikdz2;
  }
    
  public void setIkdz2(Double Ikdz2)
  {
    this.Ikdz2 = Ikdz2;
  }
    
  public Double getIkdz3()
  {
    return Ikdz3;
  }
    
  public void setIkdz3(Double Ikdz3)
  {
    this.Ikdz3 = Ikdz3;
  }
    
  public Double getKsen2()
  {
    return Ksen2;
  }
    
  public void setKsen2(Double Ksen2)
  {
    this.Ksen2 = Ksen2;
  }
    
  public Double getKsen3()
  {
    return Ksen3;
  }
    
  public void setKsen3(Double Ksen3)
  {
    this.Ksen3 = Ksen3;
  }
    
  public Integer getCapPtr()
  {
    return CapPtr;
  }
    
  public void setCapPtr(Integer CapPtr)
  {
    this.CapPtr = CapPtr;
  }
    
  public String toString()
  {
    return "ProtCap ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", TopoBus = " + TopoBus
	 + ", Rate = " + Rate
	 + ", IkMax = " + IkMax
	 + ", IkMin = " + IkMin
	 + ", Kkrel2 = " + Kkrel2
	 + ", Kkrel3 = " + Kkrel3
	 + ", Kkres3 = " + Kkres3
	 + ", Ikdz2 = " + Ikdz2
	 + ", Ikdz3 = " + Ikdz3
	 + ", Ksen2 = " + Ksen2
	 + ", Ksen3 = " + Ksen3
	 + ", CapPtr = " + CapPtr+"]";
  }
    
}
    
