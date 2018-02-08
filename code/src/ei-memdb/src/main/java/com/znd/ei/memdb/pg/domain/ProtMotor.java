package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电动机保护	*
***********************/
public class ProtMotor  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //电动机名称
  private String Name;
  
  //拓扑母线
  private Integer TopoBus;
  
  //额定电流(A)
  private Double Rate;
  
  //最大短路电流(A)
  private Double IkMax;
  
  //最小短路电流(A)
  private Double IkMin;
  
  //整定:电动机启动电流倍数
  private Double Kst;
  
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
  
  //校核:纵差保护灵敏系数
  private Double Kdsen;
  
  //校核:过流保护灵敏系数
  private Double Kksen;
  
  //设备索引
  private Integer LoadPtr;
  
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
    
  public Double getKst()
  {
    return Kst;
  }
    
  public void setKst(Double Kst)
  {
    this.Kst = Kst;
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
    
  public Double getKdsen()
  {
    return Kdsen;
  }
    
  public void setKdsen(Double Kdsen)
  {
    this.Kdsen = Kdsen;
  }
    
  public Double getKksen()
  {
    return Kksen;
  }
    
  public void setKksen(Double Kksen)
  {
    this.Kksen = Kksen;
  }
    
  public Integer getLoadPtr()
  {
    return LoadPtr;
  }
    
  public void setLoadPtr(Integer LoadPtr)
  {
    this.LoadPtr = LoadPtr;
  }
    
  public String toString()
  {
    return "ProtMotor ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", TopoBus = " + TopoBus
	 + ", Rate = " + Rate
	 + ", IkMax = " + IkMax
	 + ", IkMin = " + IkMin
	 + ", Kst = " + Kst
	 + ", Kdrel = " + Kdrel
	 + ", Kkrel = " + Kkrel
	 + ", Kkres = " + Kkres
	 + ", Kap = " + Kap
	 + ", Kss = " + Kss
	 + ", IunbMax = " + IunbMax
	 + ", Iddz = " + Iddz
	 + ", Ikdz = " + Ikdz
	 + ", Kdsen = " + Kdsen
	 + ", Kksen = " + Kksen
	 + ", LoadPtr = " + LoadPtr+"]";
  }
    
}
    
