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
  private String CardKey;
  
  //母线名称
  private String ACBus_Name;
  
  //基准电压(kV)
  private Double ACBus_kV;
  
  //ZONE,分区名
  private String LAB_Zone;
  
  //区域名
  private String LAB_Area;
  
  //恒定阻抗有功负荷百分数
  private Double LAB_P1;
  
  //恒定阻抗无功负荷百分数
  private Double LAB_Q1;
  
  //恒定电流有功负荷百分数
  private Double LAB_P2;
  
  //恒定电流无功负荷百分数
  private Double LAB_Q2;
  
  //恒定功率有功负荷百分数
  private Double LAB_P3;
  
  //恒定功率无功负荷百分数
  private Double LAB_Q3;
  
  //与频率有关的有功负荷百分数
  private Double LAB_P4;
  
  //与频率有关的无功负荷百分数
  private Double LAB_Q4;
  
  //频率变化1％引起的有功变化
  private Double LAB_LDP;
  
  //频率变化1％引起的无功变化
  private Double LAB_LDQ;
  
  //电压指数相关的有功负荷比例
  private Double LAB_P5;
  
  //电压指数相关的无功负荷比例
  private Double LAB_Q5;
  
  //有功电压指数
  private Double LAB_NP;
  
  //无功电压指数
  private Double LAB_NQ;
  
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
    
  public String getACBus_Name()
  {
    return ACBus_Name;
  }
    
  public void setACBus_Name(String ACBus_Name)
  {
    this.ACBus_Name = ACBus_Name;
  }
    
  public Double getACBus_kV()
  {
    return ACBus_kV;
  }
    
  public void setACBus_kV(Double ACBus_kV)
  {
    this.ACBus_kV = ACBus_kV;
  }
    
  public String getLAB_Zone()
  {
    return LAB_Zone;
  }
    
  public void setLAB_Zone(String LAB_Zone)
  {
    this.LAB_Zone = LAB_Zone;
  }
    
  public String getLAB_Area()
  {
    return LAB_Area;
  }
    
  public void setLAB_Area(String LAB_Area)
  {
    this.LAB_Area = LAB_Area;
  }
    
  public Double getLAB_P1()
  {
    return LAB_P1;
  }
    
  public void setLAB_P1(Double LAB_P1)
  {
    this.LAB_P1 = LAB_P1;
  }
    
  public Double getLAB_Q1()
  {
    return LAB_Q1;
  }
    
  public void setLAB_Q1(Double LAB_Q1)
  {
    this.LAB_Q1 = LAB_Q1;
  }
    
  public Double getLAB_P2()
  {
    return LAB_P2;
  }
    
  public void setLAB_P2(Double LAB_P2)
  {
    this.LAB_P2 = LAB_P2;
  }
    
  public Double getLAB_Q2()
  {
    return LAB_Q2;
  }
    
  public void setLAB_Q2(Double LAB_Q2)
  {
    this.LAB_Q2 = LAB_Q2;
  }
    
  public Double getLAB_P3()
  {
    return LAB_P3;
  }
    
  public void setLAB_P3(Double LAB_P3)
  {
    this.LAB_P3 = LAB_P3;
  }
    
  public Double getLAB_Q3()
  {
    return LAB_Q3;
  }
    
  public void setLAB_Q3(Double LAB_Q3)
  {
    this.LAB_Q3 = LAB_Q3;
  }
    
  public Double getLAB_P4()
  {
    return LAB_P4;
  }
    
  public void setLAB_P4(Double LAB_P4)
  {
    this.LAB_P4 = LAB_P4;
  }
    
  public Double getLAB_Q4()
  {
    return LAB_Q4;
  }
    
  public void setLAB_Q4(Double LAB_Q4)
  {
    this.LAB_Q4 = LAB_Q4;
  }
    
  public Double getLAB_LDP()
  {
    return LAB_LDP;
  }
    
  public void setLAB_LDP(Double LAB_LDP)
  {
    this.LAB_LDP = LAB_LDP;
  }
    
  public Double getLAB_LDQ()
  {
    return LAB_LDQ;
  }
    
  public void setLAB_LDQ(Double LAB_LDQ)
  {
    this.LAB_LDQ = LAB_LDQ;
  }
    
  public Double getLAB_P5()
  {
    return LAB_P5;
  }
    
  public void setLAB_P5(Double LAB_P5)
  {
    this.LAB_P5 = LAB_P5;
  }
    
  public Double getLAB_Q5()
  {
    return LAB_Q5;
  }
    
  public void setLAB_Q5(Double LAB_Q5)
  {
    this.LAB_Q5 = LAB_Q5;
  }
    
  public Double getLAB_NP()
  {
    return LAB_NP;
  }
    
  public void setLAB_NP(Double LAB_NP)
  {
    this.LAB_NP = LAB_NP;
  }
    
  public Double getLAB_NQ()
  {
    return LAB_NQ;
  }
    
  public void setLAB_NQ(Double LAB_NQ)
  {
    this.LAB_NQ = LAB_NQ;
  }
    
  public String toString()
  {
    return "BpaSwi_LAB ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", LAB_Zone = " + LAB_Zone
	 + ", LAB_Area = " + LAB_Area
	 + ", LAB_P1 = " + LAB_P1
	 + ", LAB_Q1 = " + LAB_Q1
	 + ", LAB_P2 = " + LAB_P2
	 + ", LAB_Q2 = " + LAB_Q2
	 + ", LAB_P3 = " + LAB_P3
	 + ", LAB_Q3 = " + LAB_Q3
	 + ", LAB_P4 = " + LAB_P4
	 + ", LAB_Q4 = " + LAB_Q4
	 + ", LAB_LDP = " + LAB_LDP
	 + ", LAB_LDQ = " + LAB_LDQ
	 + ", LAB_P5 = " + LAB_P5
	 + ", LAB_Q5 = " + LAB_Q5
	 + ", LAB_NP = " + LAB_NP
	 + ", LAB_NQ = " + LAB_NQ+"]";
  }
    
}
    
