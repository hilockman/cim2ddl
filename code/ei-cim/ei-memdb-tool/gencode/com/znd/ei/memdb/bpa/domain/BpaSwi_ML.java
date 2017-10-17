package com.znd.ei.memdb.bpa.domain;


/**********************
*新感应马达模型(ML)	*
***********************/
public class BpaSwi_ML
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
  
  //马达的惯性时间常数(秒)
  private Double mL_TJ;
  
  //马达功率占母线有功负荷的比例
  private Double mL_Pper;
  
  //马达的负载率或初始滑差
  private Double mL_KL;
  
  //马达的功率因数
  private Double mL_Pmin;
  
  //定子电阻(pu)
  private Double mL_RS;
  
  //定子电抗(pu)
  private Double mL_XS;
  
  //激磁电抗(pu)
  private Double mL_XM;
  
  //转子电阻(pu)
  private Double mL_RR;
  
  //转子电抗(pu)
  private Double mL_XR;
  
  //马达低压释放的电压值
  private Double mL_VI;
  
  //马达低压释放时延(秒)
  private Double mL_TI;
  
  //转矩方程常数
  private Double mL_A;
  
  //转矩方程常数
  private Double mL_B;
  
  //负载率或初始滑差
  private Integer mL_S0;
  
  //马达滑差达到1时的处理方式
  private Integer mL_IM;
  
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
    
  public Double getML_TJ()
  {
    return mL_TJ;
  }
    
  public void setML_TJ(Double mL_TJ)
  {
    this.mL_TJ = mL_TJ;
  }
    
  public Double getML_Pper()
  {
    return mL_Pper;
  }
    
  public void setML_Pper(Double mL_Pper)
  {
    this.mL_Pper = mL_Pper;
  }
    
  public Double getML_KL()
  {
    return mL_KL;
  }
    
  public void setML_KL(Double mL_KL)
  {
    this.mL_KL = mL_KL;
  }
    
  public Double getML_Pmin()
  {
    return mL_Pmin;
  }
    
  public void setML_Pmin(Double mL_Pmin)
  {
    this.mL_Pmin = mL_Pmin;
  }
    
  public Double getML_RS()
  {
    return mL_RS;
  }
    
  public void setML_RS(Double mL_RS)
  {
    this.mL_RS = mL_RS;
  }
    
  public Double getML_XS()
  {
    return mL_XS;
  }
    
  public void setML_XS(Double mL_XS)
  {
    this.mL_XS = mL_XS;
  }
    
  public Double getML_XM()
  {
    return mL_XM;
  }
    
  public void setML_XM(Double mL_XM)
  {
    this.mL_XM = mL_XM;
  }
    
  public Double getML_RR()
  {
    return mL_RR;
  }
    
  public void setML_RR(Double mL_RR)
  {
    this.mL_RR = mL_RR;
  }
    
  public Double getML_XR()
  {
    return mL_XR;
  }
    
  public void setML_XR(Double mL_XR)
  {
    this.mL_XR = mL_XR;
  }
    
  public Double getML_VI()
  {
    return mL_VI;
  }
    
  public void setML_VI(Double mL_VI)
  {
    this.mL_VI = mL_VI;
  }
    
  public Double getML_TI()
  {
    return mL_TI;
  }
    
  public void setML_TI(Double mL_TI)
  {
    this.mL_TI = mL_TI;
  }
    
  public Double getML_A()
  {
    return mL_A;
  }
    
  public void setML_A(Double mL_A)
  {
    this.mL_A = mL_A;
  }
    
  public Double getML_B()
  {
    return mL_B;
  }
    
  public void setML_B(Double mL_B)
  {
    this.mL_B = mL_B;
  }
    
  public Integer getML_S0()
  {
    return mL_S0;
  }
    
  public void setML_S0(Integer mL_S0)
  {
    this.mL_S0 = mL_S0;
  }
    
  public Integer getML_IM()
  {
    return mL_IM;
  }
    
  public void setML_IM(Integer mL_IM)
  {
    this.mL_IM = mL_IM;
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
    return "BpaSwi_ML ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", bus_ID = " + bus_ID
	 + ", mL_TJ = " + mL_TJ
	 + ", mL_Pper = " + mL_Pper
	 + ", mL_KL = " + mL_KL
	 + ", mL_Pmin = " + mL_Pmin
	 + ", mL_RS = " + mL_RS
	 + ", mL_XS = " + mL_XS
	 + ", mL_XM = " + mL_XM
	 + ", mL_RR = " + mL_RR
	 + ", mL_XR = " + mL_XR
	 + ", mL_VI = " + mL_VI
	 + ", mL_TI = " + mL_TI
	 + ", mL_A = " + mL_A
	 + ", mL_B = " + mL_B
	 + ", mL_S0 = " + mL_S0
	 + ", mL_IM = " + mL_IM
	 + ", busPtr = " + busPtr+"]";
  }
    
}
    
