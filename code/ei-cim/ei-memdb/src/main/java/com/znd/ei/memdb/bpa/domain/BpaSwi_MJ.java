package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*新感应马达模型(MJ)	*
***********************/
@Entity
public class BpaSwi_MJ
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //分区名称
  private String zone_Name;
  
  //马达的惯性时间常数(秒)
  private Double mJ_TJ;
  
  //马达功率占母线有功负荷的比例
  private Double mJ_Pper;
  
  //马达的负载率或初始滑差
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
  
  //负载率或初始滑差
  private Integer mJ_S0;
  
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
    
  public String getCardKey() 
  {
    return cardKey;
  }
    
  public void setCardKey(String cardKey)
  {
    this.cardKey = cardKey;
  }
    
  public String getZone_Name() 
  {
    return zone_Name;
  }
    
  public void setZone_Name(String zone_Name)
  {
    this.zone_Name = zone_Name;
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
    
  public Integer getMJ_S0() 
  {
    return mJ_S0;
  }
    
  public void setMJ_S0(Integer mJ_S0)
  {
    this.mJ_S0 = mJ_S0;
  }
    
  public Integer getMJ_IM() 
  {
    return mJ_IM;
  }
    
  public void setMJ_IM(Integer mJ_IM)
  {
    this.mJ_IM = mJ_IM;
  }
    
}
    
