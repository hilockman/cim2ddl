package com.znd.ei.memdb.bpa.domain;


/**********************
*分区表(ZONE)	*
***********************/
public class BpaDat_Zone
{
  private Integer id;
  
  private Integer memIndex;
  
  //分区名称
  private String zone_Name;
  
  //区域名称
  private String zone_Area;
  
  //卡类型
  private String cardKey;
  
  //线路零序电导相对于正序电导的倍数	
  private Double lOZ_KG0;
  
  //线路零序电纳相对于正序电纳的倍数
  private Double lOZ_KB0;
  
  //线路对地支路零序电导相对于对地支路正序电导的倍数
  private Double lOZ_KGC0;
  
  //线路对地支路零序电纳相对于对地支路正序电纳的倍数
  private Double lOZ_KBC0;
  
  //电压等级限制最小值	
  private Double lOZ_VMIN;
  
  //电压等级限制最大值	
  private Double lOZ_VMAX;
  
  //马达的惯性时间常数(秒)
  private Double mJ_TJ;
  
  //马达功率占母线有功负荷的比例
  private Double mJ_Pper;
  
  //马达的负载率
  private Double mJ_KL;
  
  //马达的功率因数
  private Double mJ_Pmin;
  
  //定子电阻(pu)
  private Double mJ_RS;
  
  //定子电抗(pu)
  private Double mJ_XS;
  
  //激磁电抗(pu)
  private Double mJ_XM;
  
  //转子电阻(pu)
  private Double mJ_RR;
  
  //转子电抗(pu)
  private Double mJ_XR;
  
  //马达低压释放的电压值
  private Double mJ_VI;
  
  //马达低压释放时延(秒)
  private Double mJ_TI;
  
  //转矩方程常数
  private Double mJ_A;
  
  //转矩方程常数
  private Double mJ_B;
  
  //马达滑差达到1时的处理方式
  private Integer mJ_IM;
  
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
    return zone_Name;
  }
    
  public void setZone_Name(String zone_Name)
  {
    this.zone_Name = zone_Name;
  }
    
  public String getZone_Area()
  {
    return zone_Area;
  }
    
  public void setZone_Area(String zone_Area)
  {
    this.zone_Area = zone_Area;
  }
    
  public String getCardKey()
  {
    return cardKey;
  }
    
  public void setCardKey(String cardKey)
  {
    this.cardKey = cardKey;
  }
    
  public Double getLOZ_KG0()
  {
    return lOZ_KG0;
  }
    
  public void setLOZ_KG0(Double lOZ_KG0)
  {
    this.lOZ_KG0 = lOZ_KG0;
  }
    
  public Double getLOZ_KB0()
  {
    return lOZ_KB0;
  }
    
  public void setLOZ_KB0(Double lOZ_KB0)
  {
    this.lOZ_KB0 = lOZ_KB0;
  }
    
  public Double getLOZ_KGC0()
  {
    return lOZ_KGC0;
  }
    
  public void setLOZ_KGC0(Double lOZ_KGC0)
  {
    this.lOZ_KGC0 = lOZ_KGC0;
  }
    
  public Double getLOZ_KBC0()
  {
    return lOZ_KBC0;
  }
    
  public void setLOZ_KBC0(Double lOZ_KBC0)
  {
    this.lOZ_KBC0 = lOZ_KBC0;
  }
    
  public Double getLOZ_VMIN()
  {
    return lOZ_VMIN;
  }
    
  public void setLOZ_VMIN(Double lOZ_VMIN)
  {
    this.lOZ_VMIN = lOZ_VMIN;
  }
    
  public Double getLOZ_VMAX()
  {
    return lOZ_VMAX;
  }
    
  public void setLOZ_VMAX(Double lOZ_VMAX)
  {
    this.lOZ_VMAX = lOZ_VMAX;
  }
    
  public Double getMJ_TJ()
  {
    return mJ_TJ;
  }
    
  public void setMJ_TJ(Double mJ_TJ)
  {
    this.mJ_TJ = mJ_TJ;
  }
    
  public Double getMJ_Pper()
  {
    return mJ_Pper;
  }
    
  public void setMJ_Pper(Double mJ_Pper)
  {
    this.mJ_Pper = mJ_Pper;
  }
    
  public Double getMJ_KL()
  {
    return mJ_KL;
  }
    
  public void setMJ_KL(Double mJ_KL)
  {
    this.mJ_KL = mJ_KL;
  }
    
  public Double getMJ_Pmin()
  {
    return mJ_Pmin;
  }
    
  public void setMJ_Pmin(Double mJ_Pmin)
  {
    this.mJ_Pmin = mJ_Pmin;
  }
    
  public Double getMJ_RS()
  {
    return mJ_RS;
  }
    
  public void setMJ_RS(Double mJ_RS)
  {
    this.mJ_RS = mJ_RS;
  }
    
  public Double getMJ_XS()
  {
    return mJ_XS;
  }
    
  public void setMJ_XS(Double mJ_XS)
  {
    this.mJ_XS = mJ_XS;
  }
    
  public Double getMJ_XM()
  {
    return mJ_XM;
  }
    
  public void setMJ_XM(Double mJ_XM)
  {
    this.mJ_XM = mJ_XM;
  }
    
  public Double getMJ_RR()
  {
    return mJ_RR;
  }
    
  public void setMJ_RR(Double mJ_RR)
  {
    this.mJ_RR = mJ_RR;
  }
    
  public Double getMJ_XR()
  {
    return mJ_XR;
  }
    
  public void setMJ_XR(Double mJ_XR)
  {
    this.mJ_XR = mJ_XR;
  }
    
  public Double getMJ_VI()
  {
    return mJ_VI;
  }
    
  public void setMJ_VI(Double mJ_VI)
  {
    this.mJ_VI = mJ_VI;
  }
    
  public Double getMJ_TI()
  {
    return mJ_TI;
  }
    
  public void setMJ_TI(Double mJ_TI)
  {
    this.mJ_TI = mJ_TI;
  }
    
  public Double getMJ_A()
  {
    return mJ_A;
  }
    
  public void setMJ_A(Double mJ_A)
  {
    this.mJ_A = mJ_A;
  }
    
  public Double getMJ_B()
  {
    return mJ_B;
  }
    
  public void setMJ_B(Double mJ_B)
  {
    this.mJ_B = mJ_B;
  }
    
  public Integer getMJ_IM()
  {
    return mJ_IM;
  }
    
  public void setMJ_IM(Integer mJ_IM)
  {
    this.mJ_IM = mJ_IM;
  }
    
  public String toString()
  {
    return "BpaDat_Zone ["+	"id"=id,
	"memIndex"=memIndex,
	"zone_Name"=zone_Name,
	"zone_Area"=zone_Area,
	"cardKey"=cardKey,
	"lOZ_KG0"=lOZ_KG0,
	"lOZ_KB0"=lOZ_KB0,
	"lOZ_KGC0"=lOZ_KGC0,
	"lOZ_KBC0"=lOZ_KBC0,
	"lOZ_VMIN"=lOZ_VMIN,
	"lOZ_VMAX"=lOZ_VMAX,
	"mJ_TJ"=mJ_TJ,
	"mJ_Pper"=mJ_Pper,
	"mJ_KL"=mJ_KL,
	"mJ_Pmin"=mJ_Pmin,
	"mJ_RS"=mJ_RS,
	"mJ_XS"=mJ_XS,
	"mJ_XM"=mJ_XM,
	"mJ_RR"=mJ_RR,
	"mJ_XR"=mJ_XR,
	"mJ_VI"=mJ_VI,
	"mJ_TI"=mJ_TI,
	"mJ_A"=mJ_A,
	"mJ_B"=mJ_B,
	"mJ_IM"=mJ_IM+"]"
  }
    
}
    
