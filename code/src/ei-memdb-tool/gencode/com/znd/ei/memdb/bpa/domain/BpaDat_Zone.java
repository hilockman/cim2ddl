package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*分区表(ZONE)	*
***********************/
public class BpaDat_Zone  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //分区名称
  private String Zone_Name;
  
  //区域名称
  private String Zone_Area;
  
  //卡类型
  private String CardKey;
  
  //线路零序电导相对于正序电导的倍数	
  private Double LOZ_KG0;
  
  //线路零序电纳相对于正序电纳的倍数
  private Double LOZ_KB0;
  
  //线路对地支路零序电导相对于对地支路正序电导的倍数
  private Double LOZ_KGC0;
  
  //线路对地支路零序电纳相对于对地支路正序电纳的倍数
  private Double LOZ_KBC0;
  
  //电压等级限制最小值	
  private Double LOZ_VMIN;
  
  //电压等级限制最大值	
  private Double LOZ_VMAX;
  
  //马达的惯性时间常数(秒)
  private Double MJ_TJ;
  
  //马达功率占母线有功负荷的比例
  private Double MJ_Pper;
  
  //马达的负载率
  private Double MJ_KL;
  
  //马达的功率因数
  private Double MJ_Pmin;
  
  //定子电阻(pu)
  private Double MJ_RS;
  
  //定子电抗(pu)
  private Double MJ_XS;
  
  //激磁电抗(pu)
  private Double MJ_XM;
  
  //转子电阻(pu)
  private Double MJ_RR;
  
  //转子电抗(pu)
  private Double MJ_XR;
  
  //马达低压释放的电压值
  private Double MJ_VI;
  
  //马达低压释放时延(秒)
  private Double MJ_TI;
  
  //转矩方程常数
  private Double MJ_A;
  
  //转矩方程常数
  private Double MJ_B;
  
  //马达滑差达到1时的处理方式
  private Integer MJ_IM;
  
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
    
  public String getZone_Name()
  {
    return Zone_Name;
  }
    
  public void setZone_Name(String Zone_Name)
  {
    this.Zone_Name = Zone_Name;
  }
    
  public String getZone_Area()
  {
    return Zone_Area;
  }
    
  public void setZone_Area(String Zone_Area)
  {
    this.Zone_Area = Zone_Area;
  }
    
  public String getCardKey()
  {
    return CardKey;
  }
    
  public void setCardKey(String CardKey)
  {
    this.CardKey = CardKey;
  }
    
  public Double getLOZ_KG0()
  {
    return LOZ_KG0;
  }
    
  public void setLOZ_KG0(Double LOZ_KG0)
  {
    this.LOZ_KG0 = LOZ_KG0;
  }
    
  public Double getLOZ_KB0()
  {
    return LOZ_KB0;
  }
    
  public void setLOZ_KB0(Double LOZ_KB0)
  {
    this.LOZ_KB0 = LOZ_KB0;
  }
    
  public Double getLOZ_KGC0()
  {
    return LOZ_KGC0;
  }
    
  public void setLOZ_KGC0(Double LOZ_KGC0)
  {
    this.LOZ_KGC0 = LOZ_KGC0;
  }
    
  public Double getLOZ_KBC0()
  {
    return LOZ_KBC0;
  }
    
  public void setLOZ_KBC0(Double LOZ_KBC0)
  {
    this.LOZ_KBC0 = LOZ_KBC0;
  }
    
  public Double getLOZ_VMIN()
  {
    return LOZ_VMIN;
  }
    
  public void setLOZ_VMIN(Double LOZ_VMIN)
  {
    this.LOZ_VMIN = LOZ_VMIN;
  }
    
  public Double getLOZ_VMAX()
  {
    return LOZ_VMAX;
  }
    
  public void setLOZ_VMAX(Double LOZ_VMAX)
  {
    this.LOZ_VMAX = LOZ_VMAX;
  }
    
  public Double getMJ_TJ()
  {
    return MJ_TJ;
  }
    
  public void setMJ_TJ(Double MJ_TJ)
  {
    this.MJ_TJ = MJ_TJ;
  }
    
  public Double getMJ_Pper()
  {
    return MJ_Pper;
  }
    
  public void setMJ_Pper(Double MJ_Pper)
  {
    this.MJ_Pper = MJ_Pper;
  }
    
  public Double getMJ_KL()
  {
    return MJ_KL;
  }
    
  public void setMJ_KL(Double MJ_KL)
  {
    this.MJ_KL = MJ_KL;
  }
    
  public Double getMJ_Pmin()
  {
    return MJ_Pmin;
  }
    
  public void setMJ_Pmin(Double MJ_Pmin)
  {
    this.MJ_Pmin = MJ_Pmin;
  }
    
  public Double getMJ_RS()
  {
    return MJ_RS;
  }
    
  public void setMJ_RS(Double MJ_RS)
  {
    this.MJ_RS = MJ_RS;
  }
    
  public Double getMJ_XS()
  {
    return MJ_XS;
  }
    
  public void setMJ_XS(Double MJ_XS)
  {
    this.MJ_XS = MJ_XS;
  }
    
  public Double getMJ_XM()
  {
    return MJ_XM;
  }
    
  public void setMJ_XM(Double MJ_XM)
  {
    this.MJ_XM = MJ_XM;
  }
    
  public Double getMJ_RR()
  {
    return MJ_RR;
  }
    
  public void setMJ_RR(Double MJ_RR)
  {
    this.MJ_RR = MJ_RR;
  }
    
  public Double getMJ_XR()
  {
    return MJ_XR;
  }
    
  public void setMJ_XR(Double MJ_XR)
  {
    this.MJ_XR = MJ_XR;
  }
    
  public Double getMJ_VI()
  {
    return MJ_VI;
  }
    
  public void setMJ_VI(Double MJ_VI)
  {
    this.MJ_VI = MJ_VI;
  }
    
  public Double getMJ_TI()
  {
    return MJ_TI;
  }
    
  public void setMJ_TI(Double MJ_TI)
  {
    this.MJ_TI = MJ_TI;
  }
    
  public Double getMJ_A()
  {
    return MJ_A;
  }
    
  public void setMJ_A(Double MJ_A)
  {
    this.MJ_A = MJ_A;
  }
    
  public Double getMJ_B()
  {
    return MJ_B;
  }
    
  public void setMJ_B(Double MJ_B)
  {
    this.MJ_B = MJ_B;
  }
    
  public Integer getMJ_IM()
  {
    return MJ_IM;
  }
    
  public void setMJ_IM(Integer MJ_IM)
  {
    this.MJ_IM = MJ_IM;
  }
    
  public String toString()
  {
    return "BpaDat_Zone ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Zone_Name = " + Zone_Name
	 + ", Zone_Area = " + Zone_Area
	 + ", CardKey = " + CardKey
	 + ", LOZ_KG0 = " + LOZ_KG0
	 + ", LOZ_KB0 = " + LOZ_KB0
	 + ", LOZ_KGC0 = " + LOZ_KGC0
	 + ", LOZ_KBC0 = " + LOZ_KBC0
	 + ", LOZ_VMIN = " + LOZ_VMIN
	 + ", LOZ_VMAX = " + LOZ_VMAX
	 + ", MJ_TJ = " + MJ_TJ
	 + ", MJ_Pper = " + MJ_Pper
	 + ", MJ_KL = " + MJ_KL
	 + ", MJ_Pmin = " + MJ_Pmin
	 + ", MJ_RS = " + MJ_RS
	 + ", MJ_XS = " + MJ_XS
	 + ", MJ_XM = " + MJ_XM
	 + ", MJ_RR = " + MJ_RR
	 + ", MJ_XR = " + MJ_XR
	 + ", MJ_VI = " + MJ_VI
	 + ", MJ_TI = " + MJ_TI
	 + ", MJ_A = " + MJ_A
	 + ", MJ_B = " + MJ_B
	 + ", MJ_IM = " + MJ_IM+"]";
  }
    
}
    
