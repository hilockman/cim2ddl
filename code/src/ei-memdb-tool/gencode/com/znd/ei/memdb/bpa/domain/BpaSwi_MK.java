package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*新感应马达模型(MK)	*
***********************/
public class BpaSwi_MK  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //区域名称
  private String Area_Name;
  
  //马达的惯性时间常数(秒)
  private Double MK_TJ;
  
  //马达功率占母线有功负荷的比例
  private Double MK_Pper;
  
  //马达的负载率或初始滑差
  private Double MK_KL;
  
  //马达的功率因数
  private Double MK_Pmin;
  
  //定子电阻(pu)
  private Double MK_RS;
  
  //定子电抗(pu)
  private Double MK_XS;
  
  //激磁电抗(pu)
  private Double MK_XM;
  
  //转子电阻(pu)
  private Double MK_RR;
  
  //转子电抗(pu)
  private Double MK_XR;
  
  //马达低压释放的电压值
  private Double MK_VI;
  
  //马达低压释放时延(秒)
  private Double MK_TI;
  
  //转矩方程常数
  private Double MK_A;
  
  //转矩方程常数
  private Double MK_B;
  
  //负载率或初始滑差
  private Integer MK_S0;
  
  //马达滑差达到1时的处理方式
  private Integer MK_IM;
  
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
    return CardKey;
  }
    
  public void setCardKey(String CardKey)
  {
    this.CardKey = CardKey;
  }
    
  public String getArea_Name()
  {
    return Area_Name;
  }
    
  public void setArea_Name(String Area_Name)
  {
    this.Area_Name = Area_Name;
  }
    
  public Double getMK_TJ()
  {
    return MK_TJ;
  }
    
  public void setMK_TJ(Double MK_TJ)
  {
    this.MK_TJ = MK_TJ;
  }
    
  public Double getMK_Pper()
  {
    return MK_Pper;
  }
    
  public void setMK_Pper(Double MK_Pper)
  {
    this.MK_Pper = MK_Pper;
  }
    
  public Double getMK_KL()
  {
    return MK_KL;
  }
    
  public void setMK_KL(Double MK_KL)
  {
    this.MK_KL = MK_KL;
  }
    
  public Double getMK_Pmin()
  {
    return MK_Pmin;
  }
    
  public void setMK_Pmin(Double MK_Pmin)
  {
    this.MK_Pmin = MK_Pmin;
  }
    
  public Double getMK_RS()
  {
    return MK_RS;
  }
    
  public void setMK_RS(Double MK_RS)
  {
    this.MK_RS = MK_RS;
  }
    
  public Double getMK_XS()
  {
    return MK_XS;
  }
    
  public void setMK_XS(Double MK_XS)
  {
    this.MK_XS = MK_XS;
  }
    
  public Double getMK_XM()
  {
    return MK_XM;
  }
    
  public void setMK_XM(Double MK_XM)
  {
    this.MK_XM = MK_XM;
  }
    
  public Double getMK_RR()
  {
    return MK_RR;
  }
    
  public void setMK_RR(Double MK_RR)
  {
    this.MK_RR = MK_RR;
  }
    
  public Double getMK_XR()
  {
    return MK_XR;
  }
    
  public void setMK_XR(Double MK_XR)
  {
    this.MK_XR = MK_XR;
  }
    
  public Double getMK_VI()
  {
    return MK_VI;
  }
    
  public void setMK_VI(Double MK_VI)
  {
    this.MK_VI = MK_VI;
  }
    
  public Double getMK_TI()
  {
    return MK_TI;
  }
    
  public void setMK_TI(Double MK_TI)
  {
    this.MK_TI = MK_TI;
  }
    
  public Double getMK_A()
  {
    return MK_A;
  }
    
  public void setMK_A(Double MK_A)
  {
    this.MK_A = MK_A;
  }
    
  public Double getMK_B()
  {
    return MK_B;
  }
    
  public void setMK_B(Double MK_B)
  {
    this.MK_B = MK_B;
  }
    
  public Integer getMK_S0()
  {
    return MK_S0;
  }
    
  public void setMK_S0(Integer MK_S0)
  {
    this.MK_S0 = MK_S0;
  }
    
  public Integer getMK_IM()
  {
    return MK_IM;
  }
    
  public void setMK_IM(Integer MK_IM)
  {
    this.MK_IM = MK_IM;
  }
    
  public String toString()
  {
    return "BpaSwi_MK ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", Area_Name = " + Area_Name
	 + ", MK_TJ = " + MK_TJ
	 + ", MK_Pper = " + MK_Pper
	 + ", MK_KL = " + MK_KL
	 + ", MK_Pmin = " + MK_Pmin
	 + ", MK_RS = " + MK_RS
	 + ", MK_XS = " + MK_XS
	 + ", MK_XM = " + MK_XM
	 + ", MK_RR = " + MK_RR
	 + ", MK_XR = " + MK_XR
	 + ", MK_VI = " + MK_VI
	 + ", MK_TI = " + MK_TI
	 + ", MK_A = " + MK_A
	 + ", MK_B = " + MK_B
	 + ", MK_S0 = " + MK_S0
	 + ", MK_IM = " + MK_IM+"]";
  }
    
}
    
