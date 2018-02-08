package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*母线保护	*
***********************/
public class ProtBus  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //母线名称
  private String Name;
  
  //拓扑母线
  private Integer TopoBus;
  
  //支路最大短路电流(A)
  private Double IbrankMax;
  
  //支路最大负荷电流(A)
  private Double IbraneMax;
  
  //最小短路电流(A)
  private Double IkMin;
  
  //整定:不平衡电流可靠系数
  private Double Kunbrel;
  
  //整定:二次断线可靠系数
  private Double Kbrkrel;
  
  //整定:外部短路故障整定不平衡电流(A)
  private Integer Faultunb;
  
  //外部短路计算不平衡电流(A)
  private Double Ikop;
  
  //最大负荷计算不平衡电流(A)
  private Double Ilop;
  
  //躲避二次断线差动保护整定电流(A)
  private Double Ioop;
  
  //过流保护整定电流(A)
  private Double Ikdz;
  
  //校核:差动保护灵敏系数
  private Double Ksen;
  
  //母线索引
  private Integer BusPtr;
  
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
    
  public Double getIbrankMax()
  {
    return IbrankMax;
  }
    
  public void setIbrankMax(Double IbrankMax)
  {
    this.IbrankMax = IbrankMax;
  }
    
  public Double getIbraneMax()
  {
    return IbraneMax;
  }
    
  public void setIbraneMax(Double IbraneMax)
  {
    this.IbraneMax = IbraneMax;
  }
    
  public Double getIkMin()
  {
    return IkMin;
  }
    
  public void setIkMin(Double IkMin)
  {
    this.IkMin = IkMin;
  }
    
  public Double getKunbrel()
  {
    return Kunbrel;
  }
    
  public void setKunbrel(Double Kunbrel)
  {
    this.Kunbrel = Kunbrel;
  }
    
  public Double getKbrkrel()
  {
    return Kbrkrel;
  }
    
  public void setKbrkrel(Double Kbrkrel)
  {
    this.Kbrkrel = Kbrkrel;
  }
    
  public Integer getFaultunb()
  {
    return Faultunb;
  }
    
  public void setFaultunb(Integer Faultunb)
  {
    this.Faultunb = Faultunb;
  }
    
  public Double getIkop()
  {
    return Ikop;
  }
    
  public void setIkop(Double Ikop)
  {
    this.Ikop = Ikop;
  }
    
  public Double getIlop()
  {
    return Ilop;
  }
    
  public void setIlop(Double Ilop)
  {
    this.Ilop = Ilop;
  }
    
  public Double getIoop()
  {
    return Ioop;
  }
    
  public void setIoop(Double Ioop)
  {
    this.Ioop = Ioop;
  }
    
  public Double getIkdz()
  {
    return Ikdz;
  }
    
  public void setIkdz(Double Ikdz)
  {
    this.Ikdz = Ikdz;
  }
    
  public Double getKsen()
  {
    return Ksen;
  }
    
  public void setKsen(Double Ksen)
  {
    this.Ksen = Ksen;
  }
    
  public Integer getBusPtr()
  {
    return BusPtr;
  }
    
  public void setBusPtr(Integer BusPtr)
  {
    this.BusPtr = BusPtr;
  }
    
  public String toString()
  {
    return "ProtBus ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", TopoBus = " + TopoBus
	 + ", IbrankMax = " + IbrankMax
	 + ", IbraneMax = " + IbraneMax
	 + ", IkMin = " + IkMin
	 + ", Kunbrel = " + Kunbrel
	 + ", Kbrkrel = " + Kbrkrel
	 + ", Faultunb = " + Faultunb
	 + ", Ikop = " + Ikop
	 + ", Ilop = " + Ilop
	 + ", Ioop = " + Ioop
	 + ", Ikdz = " + Ikdz
	 + ", Ksen = " + Ksen
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
