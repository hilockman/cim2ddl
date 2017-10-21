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
  private String cardKey;
  
  //母线名称
  private String aCBus_Name;
  
  //基准电压(kV)
  private Double aCBus_kV;
  
  //BusID识别码ID
  private Integer bus_ID;
  
  //马达的动能(兆瓦秒)
  private Double mI_Emws;
  
  //马达功率占母线有功负荷的比例
  private Double mI_P;
  
  //马达的基准功率值(MVA)
  private Double mI_MVA;
  
  //定子电阻(pu)
  private Double mI_RS;
  
  //定子电抗(pu)
  private Double mI_XS;
  
  //激磁电抗(pu)
  private Double mI_XM;
  
  //转子电阻(pu)
  private Double mI_RR;
  
  //转子电抗(pu)
  private Double mI_XR;
  
  //马达低压释放的电压值
  private Double mI_VI;
  
  //马达低压释放时延(秒)
  private Double mI_TI;
  
  //转矩方程常数
  private Double mI_A;
  
  //转矩方程常数
  private Double mI_B;
  
  //马达滑差达到1时的处理方式
  private Integer mI_IM;
  
  //母线索引
  private Integer busPtr;
  
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
    
  public Integer getBus_ID()
  {
    return bus_ID;
  }
    
  public void setBus_ID(Integer bus_ID)
  {
    this.bus_ID = bus_ID;
  }
    
  public Double getMI_Emws()
  {
    return mI_Emws;
  }
    
  public void setMI_Emws(Double mI_Emws)
  {
    this.mI_Emws = mI_Emws;
  }
    
  public Double getMI_P()
  {
    return mI_P;
  }
    
  public void setMI_P(Double mI_P)
  {
    this.mI_P = mI_P;
  }
    
  public Double getMI_MVA()
  {
    return mI_MVA;
  }
    
  public void setMI_MVA(Double mI_MVA)
  {
    this.mI_MVA = mI_MVA;
  }
    
  public Double getMI_RS()
  {
    return mI_RS;
  }
    
  public void setMI_RS(Double mI_RS)
  {
    this.mI_RS = mI_RS;
  }
    
  public Double getMI_XS()
  {
    return mI_XS;
  }
    
  public void setMI_XS(Double mI_XS)
  {
    this.mI_XS = mI_XS;
  }
    
  public Double getMI_XM()
  {
    return mI_XM;
  }
    
  public void setMI_XM(Double mI_XM)
  {
    this.mI_XM = mI_XM;
  }
    
  public Double getMI_RR()
  {
    return mI_RR;
  }
    
  public void setMI_RR(Double mI_RR)
  {
    this.mI_RR = mI_RR;
  }
    
  public Double getMI_XR()
  {
    return mI_XR;
  }
    
  public void setMI_XR(Double mI_XR)
  {
    this.mI_XR = mI_XR;
  }
    
  public Double getMI_VI()
  {
    return mI_VI;
  }
    
  public void setMI_VI(Double mI_VI)
  {
    this.mI_VI = mI_VI;
  }
    
  public Double getMI_TI()
  {
    return mI_TI;
  }
    
  public void setMI_TI(Double mI_TI)
  {
    this.mI_TI = mI_TI;
  }
    
  public Double getMI_A()
  {
    return mI_A;
  }
    
  public void setMI_A(Double mI_A)
  {
    this.mI_A = mI_A;
  }
    
  public Double getMI_B()
  {
    return mI_B;
  }
    
  public void setMI_B(Double mI_B)
  {
    this.mI_B = mI_B;
  }
    
  public Integer getMI_IM()
  {
    return mI_IM;
  }
    
  public void setMI_IM(Integer mI_IM)
  {
    this.mI_IM = mI_IM;
  }
    
  public Integer getBusPtr()
  {
    return busPtr;
  }
    
  public void setBusPtr(Integer busPtr)
  {
    this.busPtr = busPtr;
  }
    
  public String toString()
  {
    return "BpaSwi_MI ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", bus_ID = " + bus_ID
	 + ", mI_Emws = " + mI_Emws
	 + ", mI_P = " + mI_P
	 + ", mI_MVA = " + mI_MVA
	 + ", mI_RS = " + mI_RS
	 + ", mI_XS = " + mI_XS
	 + ", mI_XM = " + mI_XM
	 + ", mI_RR = " + mI_RR
	 + ", mI_XR = " + mI_XR
	 + ", mI_VI = " + mI_VI
	 + ", mI_TI = " + mI_TI
	 + ", mI_A = " + mI_A
	 + ", mI_B = " + mI_B
	 + ", mI_IM = " + mI_IM
	 + ", busPtr = " + busPtr+"]";
  }
    
}
    
