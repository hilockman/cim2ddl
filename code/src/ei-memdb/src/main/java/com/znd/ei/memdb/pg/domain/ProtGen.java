package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*发电机保护	*
***********************/
public class ProtGen  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //发电机名称
  private String Name;
  
  //拓扑母线
  private Integer TopoBus;
  
  //额定电流(A)
  private Double Rate;
  
  //最大短路电流(A)
  private Double IkMax;
  
  //设备近端故障最小短路电流(A)
  private Double IkminNear;
  
  //设备远端故障最小短路电流(A)
  private Double IkminFar;
  
  //整定:纵差保护可靠系数
  private Double Kdrel;
  
  //整定:过流保护可靠系数
  private Double Kkrel;
  
  //整定:过流保护返回系数
  private Double Kkres;
  
  //整定:非周期分量影响系数
  private Double Kap;
  
  //整定:电流互感器同型系数
  private Double Kss;
  
  //纵差最大不平衡电流(A)
  private Double IunbMax;
  
  //纵差保护整定电流(A)
  private Double Iddz;
  
  //过流保护整定电流(A)
  private Double Ikdz;
  
  //校核:过流保护近后备灵敏系数
  private Double KksenNear;
  
  //校核:过流保护远后备灵敏系数
  private Double KksenFar;
  
  //发电机索引
  private Integer GenPtr;
  
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
    
  public Double getIkminNear()
  {
    return IkminNear;
  }
    
  public void setIkminNear(Double IkminNear)
  {
    this.IkminNear = IkminNear;
  }
    
  public Double getIkminFar()
  {
    return IkminFar;
  }
    
  public void setIkminFar(Double IkminFar)
  {
    this.IkminFar = IkminFar;
  }
    
  public Double getKdrel()
  {
    return Kdrel;
  }
    
  public void setKdrel(Double Kdrel)
  {
    this.Kdrel = Kdrel;
  }
    
  public Double getKkrel()
  {
    return Kkrel;
  }
    
  public void setKkrel(Double Kkrel)
  {
    this.Kkrel = Kkrel;
  }
    
  public Double getKkres()
  {
    return Kkres;
  }
    
  public void setKkres(Double Kkres)
  {
    this.Kkres = Kkres;
  }
    
  public Double getKap()
  {
    return Kap;
  }
    
  public void setKap(Double Kap)
  {
    this.Kap = Kap;
  }
    
  public Double getKss()
  {
    return Kss;
  }
    
  public void setKss(Double Kss)
  {
    this.Kss = Kss;
  }
    
  public Double getIunbMax()
  {
    return IunbMax;
  }
    
  public void setIunbMax(Double IunbMax)
  {
    this.IunbMax = IunbMax;
  }
    
  public Double getIddz()
  {
    return Iddz;
  }
    
  public void setIddz(Double Iddz)
  {
    this.Iddz = Iddz;
  }
    
  public Double getIkdz()
  {
    return Ikdz;
  }
    
  public void setIkdz(Double Ikdz)
  {
    this.Ikdz = Ikdz;
  }
    
  public Double getKksenNear()
  {
    return KksenNear;
  }
    
  public void setKksenNear(Double KksenNear)
  {
    this.KksenNear = KksenNear;
  }
    
  public Double getKksenFar()
  {
    return KksenFar;
  }
    
  public void setKksenFar(Double KksenFar)
  {
    this.KksenFar = KksenFar;
  }
    
  public Integer getGenPtr()
  {
    return GenPtr;
  }
    
  public void setGenPtr(Integer GenPtr)
  {
    this.GenPtr = GenPtr;
  }
    
  public String toString()
  {
    return "ProtGen ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", TopoBus = " + TopoBus
	 + ", Rate = " + Rate
	 + ", IkMax = " + IkMax
	 + ", IkminNear = " + IkminNear
	 + ", IkminFar = " + IkminFar
	 + ", Kdrel = " + Kdrel
	 + ", Kkrel = " + Kkrel
	 + ", Kkres = " + Kkres
	 + ", Kap = " + Kap
	 + ", Kss = " + Kss
	 + ", IunbMax = " + IunbMax
	 + ", Iddz = " + Iddz
	 + ", Ikdz = " + Ikdz
	 + ", KksenNear = " + KksenNear
	 + ", KksenFar = " + KksenFar
	 + ", GenPtr = " + GenPtr+"]";
  }
    
}
    
