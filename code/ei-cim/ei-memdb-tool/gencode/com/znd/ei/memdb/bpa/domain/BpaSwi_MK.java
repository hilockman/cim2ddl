package com.znd.ei.memdb.bpa.domain;


/**********************
*新感应马达模型(MK)	*
***********************/
public class BpaSwi_MK
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //区域名称
  private String area_Name;
  
  //马达的惯性时间常数(秒)
  private Double mK_TJ;
  
  //马达功率占母线有功负荷的比例
  private Double mK_Pper;
  
  //马达的负载率或初始滑差
  private Double mK_KL;
  
  //马达的功率因数
  private Double mK_Pmin;
  
  //定子电阻(pu)
  private Double mK_RS;
  
  //定子电抗(pu)
  private Double mK_XS;
  
  //激磁电抗(pu)
  private Double mK_XM;
  
  //转子电阻(pu)
  private Double mK_RR;
  
  //转子电抗(pu)
  private Double mK_XR;
  
  //马达低压释放的电压值
  private Double mK_VI;
  
  //马达低压释放时延(秒)
  private Double mK_TI;
  
  //转矩方程常数
  private Double mK_A;
  
  //转矩方程常数
  private Double mK_B;
  
  //负载率或初始滑差
  private Integer mK_S0;
  
  //马达滑差达到1时的处理方式
  private Integer mK_IM;
  
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
    
  public String getCardKey()
  {
    return cardKey;
  }
    
  public void setCardKey(String cardKey)
  {
    this.cardKey = cardKey;
  }
    
  public String getArea_Name()
  {
    return area_Name;
  }
    
  public void setArea_Name(String area_Name)
  {
    this.area_Name = area_Name;
  }
    
  public Double getMK_TJ()
  {
    return mK_TJ;
  }
    
  public void setMK_TJ(Double mK_TJ)
  {
    this.mK_TJ = mK_TJ;
  }
    
  public Double getMK_Pper()
  {
    return mK_Pper;
  }
    
  public void setMK_Pper(Double mK_Pper)
  {
    this.mK_Pper = mK_Pper;
  }
    
  public Double getMK_KL()
  {
    return mK_KL;
  }
    
  public void setMK_KL(Double mK_KL)
  {
    this.mK_KL = mK_KL;
  }
    
  public Double getMK_Pmin()
  {
    return mK_Pmin;
  }
    
  public void setMK_Pmin(Double mK_Pmin)
  {
    this.mK_Pmin = mK_Pmin;
  }
    
  public Double getMK_RS()
  {
    return mK_RS;
  }
    
  public void setMK_RS(Double mK_RS)
  {
    this.mK_RS = mK_RS;
  }
    
  public Double getMK_XS()
  {
    return mK_XS;
  }
    
  public void setMK_XS(Double mK_XS)
  {
    this.mK_XS = mK_XS;
  }
    
  public Double getMK_XM()
  {
    return mK_XM;
  }
    
  public void setMK_XM(Double mK_XM)
  {
    this.mK_XM = mK_XM;
  }
    
  public Double getMK_RR()
  {
    return mK_RR;
  }
    
  public void setMK_RR(Double mK_RR)
  {
    this.mK_RR = mK_RR;
  }
    
  public Double getMK_XR()
  {
    return mK_XR;
  }
    
  public void setMK_XR(Double mK_XR)
  {
    this.mK_XR = mK_XR;
  }
    
  public Double getMK_VI()
  {
    return mK_VI;
  }
    
  public void setMK_VI(Double mK_VI)
  {
    this.mK_VI = mK_VI;
  }
    
  public Double getMK_TI()
  {
    return mK_TI;
  }
    
  public void setMK_TI(Double mK_TI)
  {
    this.mK_TI = mK_TI;
  }
    
  public Double getMK_A()
  {
    return mK_A;
  }
    
  public void setMK_A(Double mK_A)
  {
    this.mK_A = mK_A;
  }
    
  public Double getMK_B()
  {
    return mK_B;
  }
    
  public void setMK_B(Double mK_B)
  {
    this.mK_B = mK_B;
  }
    
  public Integer getMK_S0()
  {
    return mK_S0;
  }
    
  public void setMK_S0(Integer mK_S0)
  {
    this.mK_S0 = mK_S0;
  }
    
  public Integer getMK_IM()
  {
    return mK_IM;
  }
    
  public void setMK_IM(Integer mK_IM)
  {
    this.mK_IM = mK_IM;
  }
    
  public String toString()
  {
    return "BpaSwi_MK ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"area_Name"=area_Name,
	"mK_TJ"=mK_TJ,
	"mK_Pper"=mK_Pper,
	"mK_KL"=mK_KL,
	"mK_Pmin"=mK_Pmin,
	"mK_RS"=mK_RS,
	"mK_XS"=mK_XS,
	"mK_XM"=mK_XM,
	"mK_RR"=mK_RR,
	"mK_XR"=mK_XR,
	"mK_VI"=mK_VI,
	"mK_TI"=mK_TI,
	"mK_A"=mK_A,
	"mK_B"=mK_B,
	"mK_S0"=mK_S0,
	"mK_IM"=mK_IM+"]"
  }
    
}
    
