package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*静态负荷模型表(LA/LB)	*
***********************/
public class BpaSwi_LAB  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称
  private String aCBus_Name;
  
  //基准电压(kV)
  private Double aCBus_kV;
  
  //ZONE,分区名
  private String lAB_Zone;
  
  //区域名
  private String lAB_Area;
  
  //恒定阻抗有功负荷百分数
  private Double lAB_P1;
  
  //恒定阻抗无功负荷百分数
  private Double lAB_Q1;
  
  //恒定电流有功负荷百分数
  private Double lAB_P2;
  
  //恒定电流无功负荷百分数
  private Double lAB_Q2;
  
  //恒定功率有功负荷百分数
  private Double lAB_P3;
  
  //恒定功率无功负荷百分数
  private Double lAB_Q3;
  
  //与频率有关的有功负荷百分数
  private Double lAB_P4;
  
  //与频率有关的无功负荷百分数
  private Double lAB_Q4;
  
  //频率变化1％引起的有功变化
  private Double lAB_LDP;
  
  //频率变化1％引起的无功变化
  private Double lAB_LDQ;
  
  //电压指数相关的有功负荷比例
  private Double lAB_P5;
  
  //电压指数相关的无功负荷比例
  private Double lAB_Q5;
  
  //有功电压指数
  private Double lAB_NP;
  
  //无功电压指数
  private Double lAB_NQ;
  
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
    
  public String getACBus_Name()
  {
    return aCBus_Name;
  }
    
  public void setACBus_Name(String aCBus_Name)
  {
    this.aCBus_Name = aCBus_Name;
  }
    
  public Double getACBus_kV()
  {
    return aCBus_kV;
  }
    
  public void setACBus_kV(Double aCBus_kV)
  {
    this.aCBus_kV = aCBus_kV;
  }
    
  public String getLAB_Zone()
  {
    return lAB_Zone;
  }
    
  public void setLAB_Zone(String lAB_Zone)
  {
    this.lAB_Zone = lAB_Zone;
  }
    
  public String getLAB_Area()
  {
    return lAB_Area;
  }
    
  public void setLAB_Area(String lAB_Area)
  {
    this.lAB_Area = lAB_Area;
  }
    
  public Double getLAB_P1()
  {
    return lAB_P1;
  }
    
  public void setLAB_P1(Double lAB_P1)
  {
    this.lAB_P1 = lAB_P1;
  }
    
  public Double getLAB_Q1()
  {
    return lAB_Q1;
  }
    
  public void setLAB_Q1(Double lAB_Q1)
  {
    this.lAB_Q1 = lAB_Q1;
  }
    
  public Double getLAB_P2()
  {
    return lAB_P2;
  }
    
  public void setLAB_P2(Double lAB_P2)
  {
    this.lAB_P2 = lAB_P2;
  }
    
  public Double getLAB_Q2()
  {
    return lAB_Q2;
  }
    
  public void setLAB_Q2(Double lAB_Q2)
  {
    this.lAB_Q2 = lAB_Q2;
  }
    
  public Double getLAB_P3()
  {
    return lAB_P3;
  }
    
  public void setLAB_P3(Double lAB_P3)
  {
    this.lAB_P3 = lAB_P3;
  }
    
  public Double getLAB_Q3()
  {
    return lAB_Q3;
  }
    
  public void setLAB_Q3(Double lAB_Q3)
  {
    this.lAB_Q3 = lAB_Q3;
  }
    
  public Double getLAB_P4()
  {
    return lAB_P4;
  }
    
  public void setLAB_P4(Double lAB_P4)
  {
    this.lAB_P4 = lAB_P4;
  }
    
  public Double getLAB_Q4()
  {
    return lAB_Q4;
  }
    
  public void setLAB_Q4(Double lAB_Q4)
  {
    this.lAB_Q4 = lAB_Q4;
  }
    
  public Double getLAB_LDP()
  {
    return lAB_LDP;
  }
    
  public void setLAB_LDP(Double lAB_LDP)
  {
    this.lAB_LDP = lAB_LDP;
  }
    
  public Double getLAB_LDQ()
  {
    return lAB_LDQ;
  }
    
  public void setLAB_LDQ(Double lAB_LDQ)
  {
    this.lAB_LDQ = lAB_LDQ;
  }
    
  public Double getLAB_P5()
  {
    return lAB_P5;
  }
    
  public void setLAB_P5(Double lAB_P5)
  {
    this.lAB_P5 = lAB_P5;
  }
    
  public Double getLAB_Q5()
  {
    return lAB_Q5;
  }
    
  public void setLAB_Q5(Double lAB_Q5)
  {
    this.lAB_Q5 = lAB_Q5;
  }
    
  public Double getLAB_NP()
  {
    return lAB_NP;
  }
    
  public void setLAB_NP(Double lAB_NP)
  {
    this.lAB_NP = lAB_NP;
  }
    
  public Double getLAB_NQ()
  {
    return lAB_NQ;
  }
    
  public void setLAB_NQ(Double lAB_NQ)
  {
    this.lAB_NQ = lAB_NQ;
  }
    
  public String toString()
  {
    return "BpaSwi_LAB ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", lAB_Zone = " + lAB_Zone
	 + ", lAB_Area = " + lAB_Area
	 + ", lAB_P1 = " + lAB_P1
	 + ", lAB_Q1 = " + lAB_Q1
	 + ", lAB_P2 = " + lAB_P2
	 + ", lAB_Q2 = " + lAB_Q2
	 + ", lAB_P3 = " + lAB_P3
	 + ", lAB_Q3 = " + lAB_Q3
	 + ", lAB_P4 = " + lAB_P4
	 + ", lAB_Q4 = " + lAB_Q4
	 + ", lAB_LDP = " + lAB_LDP
	 + ", lAB_LDQ = " + lAB_LDQ
	 + ", lAB_P5 = " + lAB_P5
	 + ", lAB_Q5 = " + lAB_Q5
	 + ", lAB_NP = " + lAB_NP
	 + ", lAB_NQ = " + lAB_NQ+"]";
  }
    
}
    
