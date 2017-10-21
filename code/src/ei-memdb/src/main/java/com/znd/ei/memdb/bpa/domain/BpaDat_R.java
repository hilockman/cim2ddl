package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*带负荷调节变压器控制器表(R)	*
***********************/
public class BpaDat_R  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //所有者
  private String r_Owner;
  
  //母线名称1
  private String r_BusI;
  
  //基准电压1(kV)
  private Double r_kVI;
  
  //可调抽头端标志
  private Integer r_VARTAP;
  
  //母线名称2
  private String r_BusJ;
  
  //基准电压2(kV)
  private Double r_kVJ;
  
  //被控母线名称
  private String r_BusC;
  
  //被控基准电压(kV)
  private Double r_kVC;
  
  //最大抽头位置(kV)
  private Double r_TMax;
  
  //最小抽头位置(kV)
  private Double r_TMin;
  
  //LTC抽头总数
  private Integer r_TNum;
  
  //指定的最大无功功率(Mvar)
  private Double r_ValMax;
  
  //指定的最小无功功率(Mvar)
  private Double r_ValMin;
  
  //有功(MW)
  private Double r_P;
  
  //无功(Mvar)
  private Double r_Q;
  
  //有功损耗(MW)
  private Double r_LossP;
  
  //无功损耗(Mvar)
  private Double r_LossQ;
  
  //调压器名称
  private String keyName;
  
  //变压器I母线索引
  private Integer r_iRBus;
  
  //变压器Z母线索引
  private Integer r_zRBus;
  
  //状态
  private Integer r_Status;
  
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
    
  public String getR_Owner()
  {
    return r_Owner;
  }
    
  public void setR_Owner(String r_Owner)
  {
    this.r_Owner = r_Owner;
  }
    
  public String getR_BusI()
  {
    return r_BusI;
  }
    
  public void setR_BusI(String r_BusI)
  {
    this.r_BusI = r_BusI;
  }
    
  public Double getR_kVI()
  {
    return r_kVI;
  }
    
  public void setR_kVI(Double r_kVI)
  {
    this.r_kVI = r_kVI;
  }
    
  public Integer getR_VARTAP()
  {
    return r_VARTAP;
  }
    
  public void setR_VARTAP(Integer r_VARTAP)
  {
    this.r_VARTAP = r_VARTAP;
  }
    
  public String getR_BusJ()
  {
    return r_BusJ;
  }
    
  public void setR_BusJ(String r_BusJ)
  {
    this.r_BusJ = r_BusJ;
  }
    
  public Double getR_kVJ()
  {
    return r_kVJ;
  }
    
  public void setR_kVJ(Double r_kVJ)
  {
    this.r_kVJ = r_kVJ;
  }
    
  public String getR_BusC()
  {
    return r_BusC;
  }
    
  public void setR_BusC(String r_BusC)
  {
    this.r_BusC = r_BusC;
  }
    
  public Double getR_kVC()
  {
    return r_kVC;
  }
    
  public void setR_kVC(Double r_kVC)
  {
    this.r_kVC = r_kVC;
  }
    
  public Double getR_TMax()
  {
    return r_TMax;
  }
    
  public void setR_TMax(Double r_TMax)
  {
    this.r_TMax = r_TMax;
  }
    
  public Double getR_TMin()
  {
    return r_TMin;
  }
    
  public void setR_TMin(Double r_TMin)
  {
    this.r_TMin = r_TMin;
  }
    
  public Integer getR_TNum()
  {
    return r_TNum;
  }
    
  public void setR_TNum(Integer r_TNum)
  {
    this.r_TNum = r_TNum;
  }
    
  public Double getR_ValMax()
  {
    return r_ValMax;
  }
    
  public void setR_ValMax(Double r_ValMax)
  {
    this.r_ValMax = r_ValMax;
  }
    
  public Double getR_ValMin()
  {
    return r_ValMin;
  }
    
  public void setR_ValMin(Double r_ValMin)
  {
    this.r_ValMin = r_ValMin;
  }
    
  public Double getR_P()
  {
    return r_P;
  }
    
  public void setR_P(Double r_P)
  {
    this.r_P = r_P;
  }
    
  public Double getR_Q()
  {
    return r_Q;
  }
    
  public void setR_Q(Double r_Q)
  {
    this.r_Q = r_Q;
  }
    
  public Double getR_LossP()
  {
    return r_LossP;
  }
    
  public void setR_LossP(Double r_LossP)
  {
    this.r_LossP = r_LossP;
  }
    
  public Double getR_LossQ()
  {
    return r_LossQ;
  }
    
  public void setR_LossQ(Double r_LossQ)
  {
    this.r_LossQ = r_LossQ;
  }
    
  public String getKeyName()
  {
    return keyName;
  }
    
  public void setKeyName(String keyName)
  {
    this.keyName = keyName;
  }
    
  public Integer getR_iRBus()
  {
    return r_iRBus;
  }
    
  public void setR_iRBus(Integer r_iRBus)
  {
    this.r_iRBus = r_iRBus;
  }
    
  public Integer getR_zRBus()
  {
    return r_zRBus;
  }
    
  public void setR_zRBus(Integer r_zRBus)
  {
    this.r_zRBus = r_zRBus;
  }
    
  public Integer getR_Status()
  {
    return r_Status;
  }
    
  public void setR_Status(Integer r_Status)
  {
    this.r_Status = r_Status;
  }
    
  public String toString()
  {
    return "BpaDat_R ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", r_Owner = " + r_Owner
	 + ", r_BusI = " + r_BusI
	 + ", r_kVI = " + r_kVI
	 + ", r_VARTAP = " + r_VARTAP
	 + ", r_BusJ = " + r_BusJ
	 + ", r_kVJ = " + r_kVJ
	 + ", r_BusC = " + r_BusC
	 + ", r_kVC = " + r_kVC
	 + ", r_TMax = " + r_TMax
	 + ", r_TMin = " + r_TMin
	 + ", r_TNum = " + r_TNum
	 + ", r_ValMax = " + r_ValMax
	 + ", r_ValMin = " + r_ValMin
	 + ", r_P = " + r_P
	 + ", r_Q = " + r_Q
	 + ", r_LossP = " + r_LossP
	 + ", r_LossQ = " + r_LossQ
	 + ", keyName = " + keyName
	 + ", r_iRBus = " + r_iRBus
	 + ", r_zRBus = " + r_zRBus
	 + ", r_Status = " + r_Status+"]";
  }
    
}
    
