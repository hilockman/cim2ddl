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
  private String CardKey;
  
  //所有者
  private String R_Owner;
  
  //母线名称1
  private String R_BusI;
  
  //基准电压1(kV)
  private Double R_kVI;
  
  //可调抽头端标志
  private Integer R_VARTAP;
  
  //母线名称2
  private String R_BusJ;
  
  //基准电压2(kV)
  private Double R_kVJ;
  
  //被控母线名称
  private String R_BusC;
  
  //被控基准电压(kV)
  private Double R_kVC;
  
  //最大抽头位置(kV)
  private Double R_TMax;
  
  //最小抽头位置(kV)
  private Double R_TMin;
  
  //LTC抽头总数
  private Integer R_TNum;
  
  //指定的最大无功功率(Mvar)
  private Double R_ValMax;
  
  //指定的最小无功功率(Mvar)
  private Double R_ValMin;
  
  //有功(MW)
  private Double R_P;
  
  //无功(Mvar)
  private Double R_Q;
  
  //有功损耗(MW)
  private Double R_LossP;
  
  //无功损耗(Mvar)
  private Double R_LossQ;
  
  //调压器名称
  private String KeyName;
  
  //变压器I母线索引
  private Integer R_iRBus;
  
  //变压器Z母线索引
  private Integer R_zRBus;
  
  //状态
  private Integer R_Status;
  
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
    
  public String getR_Owner()
  {
    return R_Owner;
  }
    
  public void setR_Owner(String R_Owner)
  {
    this.R_Owner = R_Owner;
  }
    
  public String getR_BusI()
  {
    return R_BusI;
  }
    
  public void setR_BusI(String R_BusI)
  {
    this.R_BusI = R_BusI;
  }
    
  public Double getR_kVI()
  {
    return R_kVI;
  }
    
  public void setR_kVI(Double R_kVI)
  {
    this.R_kVI = R_kVI;
  }
    
  public Integer getR_VARTAP()
  {
    return R_VARTAP;
  }
    
  public void setR_VARTAP(Integer R_VARTAP)
  {
    this.R_VARTAP = R_VARTAP;
  }
    
  public String getR_BusJ()
  {
    return R_BusJ;
  }
    
  public void setR_BusJ(String R_BusJ)
  {
    this.R_BusJ = R_BusJ;
  }
    
  public Double getR_kVJ()
  {
    return R_kVJ;
  }
    
  public void setR_kVJ(Double R_kVJ)
  {
    this.R_kVJ = R_kVJ;
  }
    
  public String getR_BusC()
  {
    return R_BusC;
  }
    
  public void setR_BusC(String R_BusC)
  {
    this.R_BusC = R_BusC;
  }
    
  public Double getR_kVC()
  {
    return R_kVC;
  }
    
  public void setR_kVC(Double R_kVC)
  {
    this.R_kVC = R_kVC;
  }
    
  public Double getR_TMax()
  {
    return R_TMax;
  }
    
  public void setR_TMax(Double R_TMax)
  {
    this.R_TMax = R_TMax;
  }
    
  public Double getR_TMin()
  {
    return R_TMin;
  }
    
  public void setR_TMin(Double R_TMin)
  {
    this.R_TMin = R_TMin;
  }
    
  public Integer getR_TNum()
  {
    return R_TNum;
  }
    
  public void setR_TNum(Integer R_TNum)
  {
    this.R_TNum = R_TNum;
  }
    
  public Double getR_ValMax()
  {
    return R_ValMax;
  }
    
  public void setR_ValMax(Double R_ValMax)
  {
    this.R_ValMax = R_ValMax;
  }
    
  public Double getR_ValMin()
  {
    return R_ValMin;
  }
    
  public void setR_ValMin(Double R_ValMin)
  {
    this.R_ValMin = R_ValMin;
  }
    
  public Double getR_P()
  {
    return R_P;
  }
    
  public void setR_P(Double R_P)
  {
    this.R_P = R_P;
  }
    
  public Double getR_Q()
  {
    return R_Q;
  }
    
  public void setR_Q(Double R_Q)
  {
    this.R_Q = R_Q;
  }
    
  public Double getR_LossP()
  {
    return R_LossP;
  }
    
  public void setR_LossP(Double R_LossP)
  {
    this.R_LossP = R_LossP;
  }
    
  public Double getR_LossQ()
  {
    return R_LossQ;
  }
    
  public void setR_LossQ(Double R_LossQ)
  {
    this.R_LossQ = R_LossQ;
  }
    
  public String getKeyName()
  {
    return KeyName;
  }
    
  public void setKeyName(String KeyName)
  {
    this.KeyName = KeyName;
  }
    
  public Integer getR_iRBus()
  {
    return R_iRBus;
  }
    
  public void setR_iRBus(Integer R_iRBus)
  {
    this.R_iRBus = R_iRBus;
  }
    
  public Integer getR_zRBus()
  {
    return R_zRBus;
  }
    
  public void setR_zRBus(Integer R_zRBus)
  {
    this.R_zRBus = R_zRBus;
  }
    
  public Integer getR_Status()
  {
    return R_Status;
  }
    
  public void setR_Status(Integer R_Status)
  {
    this.R_Status = R_Status;
  }
    
  public String toString()
  {
    return "BpaDat_R ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", R_Owner = " + R_Owner
	 + ", R_BusI = " + R_BusI
	 + ", R_kVI = " + R_kVI
	 + ", R_VARTAP = " + R_VARTAP
	 + ", R_BusJ = " + R_BusJ
	 + ", R_kVJ = " + R_kVJ
	 + ", R_BusC = " + R_BusC
	 + ", R_kVC = " + R_kVC
	 + ", R_TMax = " + R_TMax
	 + ", R_TMin = " + R_TMin
	 + ", R_TNum = " + R_TNum
	 + ", R_ValMax = " + R_ValMax
	 + ", R_ValMin = " + R_ValMin
	 + ", R_P = " + R_P
	 + ", R_Q = " + R_Q
	 + ", R_LossP = " + R_LossP
	 + ", R_LossQ = " + R_LossQ
	 + ", KeyName = " + KeyName
	 + ", R_iRBus = " + R_iRBus
	 + ", R_zRBus = " + R_zRBus
	 + ", R_Status = " + R_Status+"]";
  }
    
}
    
