package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*新感应马达模型(MJ)	*
***********************/
public class BpaSwi_MJ  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //分区名称
  private String Zone_Name;
  
  //马达的惯性时间常数(秒)
  private Double MJ_TJ;
  
  //马达功率占母线有功负荷的比例
  private Double MJ_Pper;
  
  //马达的负载率或初始滑差
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
  
  //负载率或初始滑差
  private Integer MJ_S0;
  
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
    
  public String getCardKey()
  {
    return CardKey;
  }
    
  public void setCardKey(String CardKey)
  {
    this.CardKey = CardKey;
  }
    
  public String getZone_Name()
  {
    return Zone_Name;
  }
    
  public void setZone_Name(String Zone_Name)
  {
    this.Zone_Name = Zone_Name;
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
    
  public Integer getMJ_S0()
  {
    return MJ_S0;
  }
    
  public void setMJ_S0(Integer MJ_S0)
  {
    this.MJ_S0 = MJ_S0;
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
    return "BpaSwi_MJ ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", Zone_Name = " + Zone_Name
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
	 + ", MJ_S0 = " + MJ_S0
	 + ", MJ_IM = " + MJ_IM+"]";
  }
    
}
    
