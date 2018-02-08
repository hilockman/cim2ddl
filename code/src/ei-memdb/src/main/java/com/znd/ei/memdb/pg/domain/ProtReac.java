package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*并联电抗器保护	*
***********************/
public class ProtReac  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //并联电抗器名称
  private String Name;
  
  //拓扑母线
  private Integer TopoBus;
  
  //额定电流(A)
  private Double Rate;
  
  //最大短路电流(A)
  private Double IkMax;
  
  //最小短路电流(A)
  private Double IkMin;
  
  //整定:差动保护整定系数
  private Double Kdrel;
  
  //整定:瞬时电流速断保护可靠系数
  private Double Kkrel1;
  
  //整定:过流保护可靠系数
  private Double Kkrel3;
  
  //整定:过流保护返回系数
  private Double Kkres3;
  
  //差动保护整定电流(A)
  private Double Iddz;
  
  //瞬时电流速断整定电流(A)
  private Double Ikdz1;
  
  //过流保护整定电流(A)
  private Double Ikdz3;
  
  //校核:瞬时电流速断灵敏系数
  private Double Ksen1;
  
  //校核:过流保护灵敏系数
  private Double Ksen3;
  
  //设备索引
  private Integer ReacPtr;
  
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
    
  public Double getKdrel()
  {
    return Kdrel;
  }
    
  public void setKdrel(Double Kdrel)
  {
    this.Kdrel = Kdrel;
  }
    
  public Double getKkrel1()
  {
    return Kkrel1;
  }
    
  public void setKkrel1(Double Kkrel1)
  {
    this.Kkrel1 = Kkrel1;
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
    
  public Double getIddz()
  {
    return Iddz;
  }
    
  public void setIddz(Double Iddz)
  {
    this.Iddz = Iddz;
  }
    
  public Double getIkdz1()
  {
    return Ikdz1;
  }
    
  public void setIkdz1(Double Ikdz1)
  {
    this.Ikdz1 = Ikdz1;
  }
    
  public Double getIkdz3()
  {
    return Ikdz3;
  }
    
  public void setIkdz3(Double Ikdz3)
  {
    this.Ikdz3 = Ikdz3;
  }
    
  public Double getKsen1()
  {
    return Ksen1;
  }
    
  public void setKsen1(Double Ksen1)
  {
    this.Ksen1 = Ksen1;
  }
    
  public Double getKsen3()
  {
    return Ksen3;
  }
    
  public void setKsen3(Double Ksen3)
  {
    this.Ksen3 = Ksen3;
  }
    
  public Integer getReacPtr()
  {
    return ReacPtr;
  }
    
  public void setReacPtr(Integer ReacPtr)
  {
    this.ReacPtr = ReacPtr;
  }
    
  public String toString()
  {
    return "ProtReac ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", TopoBus = " + TopoBus
	 + ", Rate = " + Rate
	 + ", IkMax = " + IkMax
	 + ", IkMin = " + IkMin
	 + ", Kdrel = " + Kdrel
	 + ", Kkrel1 = " + Kkrel1
	 + ", Kkrel3 = " + Kkrel3
	 + ", Kkres3 = " + Kkres3
	 + ", Iddz = " + Iddz
	 + ", Ikdz1 = " + Ikdz1
	 + ", Ikdz3 = " + Ikdz3
	 + ", Ksen1 = " + Ksen1
	 + ", Ksen3 = " + Ksen3
	 + ", ReacPtr = " + ReacPtr+"]";
  }
    
}
    
