package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*新感应马达模型(ML)	*
***********************/
public class BpaSwi_ML  implements MemIndexable 
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
  
  //马达的惯性时间常数(秒)
  private Double ML_TJ;
  
  //马达功率占母线有功负荷的比例
  private Double ML_Pper;
  
  //马达的负载率或初始滑差
  private Double ML_KL;
  
  //马达的功率因数
  private Double ML_Pmin;
  
  //定子电阻(pu)
  private Double ML_RS;
  
  //定子电抗(pu)
  private Double ML_XS;
  
  //激磁电抗(pu)
  private Double ML_XM;
  
  //转子电阻(pu)
  private Double ML_RR;
  
  //转子电抗(pu)
  private Double ML_XR;
  
  //马达低压释放的电压值
  private Double ML_VI;
  
  //马达低压释放时延(秒)
  private Double ML_TI;
  
  //转矩方程常数
  private Double ML_A;
  
  //转矩方程常数
  private Double ML_B;
  
  //负载率或初始滑差
  private Integer ML_S0;
  
  //马达滑差达到1时的处理方式
  private Integer ML_IM;
  
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
    
  public Double getML_TJ()
  {
    return ML_TJ;
  }
    
  public void setML_TJ(Double ML_TJ)
  {
    this.ML_TJ = ML_TJ;
  }
    
  public Double getML_Pper()
  {
    return ML_Pper;
  }
    
  public void setML_Pper(Double ML_Pper)
  {
    this.ML_Pper = ML_Pper;
  }
    
  public Double getML_KL()
  {
    return ML_KL;
  }
    
  public void setML_KL(Double ML_KL)
  {
    this.ML_KL = ML_KL;
  }
    
  public Double getML_Pmin()
  {
    return ML_Pmin;
  }
    
  public void setML_Pmin(Double ML_Pmin)
  {
    this.ML_Pmin = ML_Pmin;
  }
    
  public Double getML_RS()
  {
    return ML_RS;
  }
    
  public void setML_RS(Double ML_RS)
  {
    this.ML_RS = ML_RS;
  }
    
  public Double getML_XS()
  {
    return ML_XS;
  }
    
  public void setML_XS(Double ML_XS)
  {
    this.ML_XS = ML_XS;
  }
    
  public Double getML_XM()
  {
    return ML_XM;
  }
    
  public void setML_XM(Double ML_XM)
  {
    this.ML_XM = ML_XM;
  }
    
  public Double getML_RR()
  {
    return ML_RR;
  }
    
  public void setML_RR(Double ML_RR)
  {
    this.ML_RR = ML_RR;
  }
    
  public Double getML_XR()
  {
    return ML_XR;
  }
    
  public void setML_XR(Double ML_XR)
  {
    this.ML_XR = ML_XR;
  }
    
  public Double getML_VI()
  {
    return ML_VI;
  }
    
  public void setML_VI(Double ML_VI)
  {
    this.ML_VI = ML_VI;
  }
    
  public Double getML_TI()
  {
    return ML_TI;
  }
    
  public void setML_TI(Double ML_TI)
  {
    this.ML_TI = ML_TI;
  }
    
  public Double getML_A()
  {
    return ML_A;
  }
    
  public void setML_A(Double ML_A)
  {
    this.ML_A = ML_A;
  }
    
  public Double getML_B()
  {
    return ML_B;
  }
    
  public void setML_B(Double ML_B)
  {
    this.ML_B = ML_B;
  }
    
  public Integer getML_S0()
  {
    return ML_S0;
  }
    
  public void setML_S0(Integer ML_S0)
  {
    this.ML_S0 = ML_S0;
  }
    
  public Integer getML_IM()
  {
    return ML_IM;
  }
    
  public void setML_IM(Integer ML_IM)
  {
    this.ML_IM = ML_IM;
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
    return "BpaSwi_ML ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Bus_ID = " + Bus_ID
	 + ", ML_TJ = " + ML_TJ
	 + ", ML_Pper = " + ML_Pper
	 + ", ML_KL = " + ML_KL
	 + ", ML_Pmin = " + ML_Pmin
	 + ", ML_RS = " + ML_RS
	 + ", ML_XS = " + ML_XS
	 + ", ML_XM = " + ML_XM
	 + ", ML_RR = " + ML_RR
	 + ", ML_XR = " + ML_XR
	 + ", ML_VI = " + ML_VI
	 + ", ML_TI = " + ML_TI
	 + ", ML_A = " + ML_A
	 + ", ML_B = " + ML_B
	 + ", ML_S0 = " + ML_S0
	 + ", ML_IM = " + ML_IM
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
