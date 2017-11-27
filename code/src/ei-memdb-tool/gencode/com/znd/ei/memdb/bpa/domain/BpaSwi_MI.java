package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*感应马达模型(MI)	*
***********************/
public class BpaSwi_MI  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称
  private String ACBus_Name;
  
  //基准电压(kV)
  private Double ACBus_kV;
  
  //BusID识别码ID
  private Integer Bus_ID;
  
  //马达的动能(兆瓦秒)
  private Double MI_Emws;
  
  //马达功率占母线有功负荷的比例
  private Double MI_P;
  
  //马达的基准功率值(MVA)
  private Double MI_MVA;
  
  //定子电阻(pu)
  private Double MI_RS;
  
  //定子电抗(pu)
  private Double MI_XS;
  
  //激磁电抗(pu)
  private Double MI_XM;
  
  //转子电阻(pu)
  private Double MI_RR;
  
  //转子电抗(pu)
  private Double MI_XR;
  
  //马达低压释放的电压值
  private Double MI_VI;
  
  //马达低压释放时延(秒)
  private Double MI_TI;
  
  //转矩方程常数
  private Double MI_A;
  
  //转矩方程常数
  private Double MI_B;
  
  //马达滑差达到1时的处理方式
  private Integer MI_IM;
  
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
    
  public Integer getBus_ID()
  {
    return Bus_ID;
  }
    
  public void setBus_ID(Integer Bus_ID)
  {
    this.Bus_ID = Bus_ID;
  }
    
  public Double getMI_Emws()
  {
    return MI_Emws;
  }
    
  public void setMI_Emws(Double MI_Emws)
  {
    this.MI_Emws = MI_Emws;
  }
    
  public Double getMI_P()
  {
    return MI_P;
  }
    
  public void setMI_P(Double MI_P)
  {
    this.MI_P = MI_P;
  }
    
  public Double getMI_MVA()
  {
    return MI_MVA;
  }
    
  public void setMI_MVA(Double MI_MVA)
  {
    this.MI_MVA = MI_MVA;
  }
    
  public Double getMI_RS()
  {
    return MI_RS;
  }
    
  public void setMI_RS(Double MI_RS)
  {
    this.MI_RS = MI_RS;
  }
    
  public Double getMI_XS()
  {
    return MI_XS;
  }
    
  public void setMI_XS(Double MI_XS)
  {
    this.MI_XS = MI_XS;
  }
    
  public Double getMI_XM()
  {
    return MI_XM;
  }
    
  public void setMI_XM(Double MI_XM)
  {
    this.MI_XM = MI_XM;
  }
    
  public Double getMI_RR()
  {
    return MI_RR;
  }
    
  public void setMI_RR(Double MI_RR)
  {
    this.MI_RR = MI_RR;
  }
    
  public Double getMI_XR()
  {
    return MI_XR;
  }
    
  public void setMI_XR(Double MI_XR)
  {
    this.MI_XR = MI_XR;
  }
    
  public Double getMI_VI()
  {
    return MI_VI;
  }
    
  public void setMI_VI(Double MI_VI)
  {
    this.MI_VI = MI_VI;
  }
    
  public Double getMI_TI()
  {
    return MI_TI;
  }
    
  public void setMI_TI(Double MI_TI)
  {
    this.MI_TI = MI_TI;
  }
    
  public Double getMI_A()
  {
    return MI_A;
  }
    
  public void setMI_A(Double MI_A)
  {
    this.MI_A = MI_A;
  }
    
  public Double getMI_B()
  {
    return MI_B;
  }
    
  public void setMI_B(Double MI_B)
  {
    this.MI_B = MI_B;
  }
    
  public Integer getMI_IM()
  {
    return MI_IM;
  }
    
  public void setMI_IM(Integer MI_IM)
  {
    this.MI_IM = MI_IM;
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
    return "BpaSwi_MI ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Bus_ID = " + Bus_ID
	 + ", MI_Emws = " + MI_Emws
	 + ", MI_P = " + MI_P
	 + ", MI_MVA = " + MI_MVA
	 + ", MI_RS = " + MI_RS
	 + ", MI_XS = " + MI_XS
	 + ", MI_XM = " + MI_XM
	 + ", MI_RR = " + MI_RR
	 + ", MI_XR = " + MI_XR
	 + ", MI_VI = " + MI_VI
	 + ", MI_TI = " + MI_TI
	 + ", MI_A = " + MI_A
	 + ", MI_B = " + MI_B
	 + ", MI_IM = " + MI_IM
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
