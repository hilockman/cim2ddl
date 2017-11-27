package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*1968年IEEE励磁系统模型表(E)	*
***********************/
public class BpaSwi_Exc68  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称,母线名
  private String ACBus_Name;
  
  //基准电压(kV),基准电压
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //TR,调压器输入的滤波器时间常数
  private Double Exc68_TR;
  
  //KA,调压器增益
  private Double Exc68_KA_BusKV;
  
  //TA,调压器放大器时间常数
  private Double Exc68_TR_TRH;
  
  //TA1,调压器放大器时间常数
  private Double Exc68_TA1;
  
  //VRMAXMULT,VRMAX乘子
  private Double Exc68_VRMinMult_TRMax;
  
  //KE,与自励有关的励磁常数
  private Double Exc68_KE;
  
  //TE,励磁机时间常数
  private Double Exc68_TE;
  
  //SE.75MAX,75％最大励磁电压时的励磁机饱和系数
  private Double Exc68_SE75Max_KI;
  
  //SEMAX,最大励磁电压时的励磁机饱和系数
  private Double Exc68_SEMax_KP;
  
  //EFDMIN,最小励磁电压
  private Double Exc68_EFDMin;
  
  //EFDMAX,最大励磁电压
  private Double Exc68_EFDMax_VBMax;
  
  //KF,调压器稳定回路增益
  private Double Exc68_KF;
  
  //TF,调压器稳定回路时间常数
  private Double Exc68_TF;
  
  //XL,整流电抗
  private Double Exc68_XL;
  
  //TF1,调压器稳定回路时间常数
  private Double Exc68_TF1;
  
  //数据库主键
  private String KeyName;
  
  //发电机母线索引
  private Integer BusPtr;
  
  //新增记录标记
  private Integer AppendTag;
  
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
    
  public Integer getGen_ID()
  {
    return Gen_ID;
  }
    
  public void setGen_ID(Integer Gen_ID)
  {
    this.Gen_ID = Gen_ID;
  }
    
  public Double getExc68_TR()
  {
    return Exc68_TR;
  }
    
  public void setExc68_TR(Double Exc68_TR)
  {
    this.Exc68_TR = Exc68_TR;
  }
    
  public Double getExc68_KA_BusKV()
  {
    return Exc68_KA_BusKV;
  }
    
  public void setExc68_KA_BusKV(Double Exc68_KA_BusKV)
  {
    this.Exc68_KA_BusKV = Exc68_KA_BusKV;
  }
    
  public Double getExc68_TR_TRH()
  {
    return Exc68_TR_TRH;
  }
    
  public void setExc68_TR_TRH(Double Exc68_TR_TRH)
  {
    this.Exc68_TR_TRH = Exc68_TR_TRH;
  }
    
  public Double getExc68_TA1()
  {
    return Exc68_TA1;
  }
    
  public void setExc68_TA1(Double Exc68_TA1)
  {
    this.Exc68_TA1 = Exc68_TA1;
  }
    
  public Double getExc68_VRMinMult_TRMax()
  {
    return Exc68_VRMinMult_TRMax;
  }
    
  public void setExc68_VRMinMult_TRMax(Double Exc68_VRMinMult_TRMax)
  {
    this.Exc68_VRMinMult_TRMax = Exc68_VRMinMult_TRMax;
  }
    
  public Double getExc68_KE()
  {
    return Exc68_KE;
  }
    
  public void setExc68_KE(Double Exc68_KE)
  {
    this.Exc68_KE = Exc68_KE;
  }
    
  public Double getExc68_TE()
  {
    return Exc68_TE;
  }
    
  public void setExc68_TE(Double Exc68_TE)
  {
    this.Exc68_TE = Exc68_TE;
  }
    
  public Double getExc68_SE75Max_KI()
  {
    return Exc68_SE75Max_KI;
  }
    
  public void setExc68_SE75Max_KI(Double Exc68_SE75Max_KI)
  {
    this.Exc68_SE75Max_KI = Exc68_SE75Max_KI;
  }
    
  public Double getExc68_SEMax_KP()
  {
    return Exc68_SEMax_KP;
  }
    
  public void setExc68_SEMax_KP(Double Exc68_SEMax_KP)
  {
    this.Exc68_SEMax_KP = Exc68_SEMax_KP;
  }
    
  public Double getExc68_EFDMin()
  {
    return Exc68_EFDMin;
  }
    
  public void setExc68_EFDMin(Double Exc68_EFDMin)
  {
    this.Exc68_EFDMin = Exc68_EFDMin;
  }
    
  public Double getExc68_EFDMax_VBMax()
  {
    return Exc68_EFDMax_VBMax;
  }
    
  public void setExc68_EFDMax_VBMax(Double Exc68_EFDMax_VBMax)
  {
    this.Exc68_EFDMax_VBMax = Exc68_EFDMax_VBMax;
  }
    
  public Double getExc68_KF()
  {
    return Exc68_KF;
  }
    
  public void setExc68_KF(Double Exc68_KF)
  {
    this.Exc68_KF = Exc68_KF;
  }
    
  public Double getExc68_TF()
  {
    return Exc68_TF;
  }
    
  public void setExc68_TF(Double Exc68_TF)
  {
    this.Exc68_TF = Exc68_TF;
  }
    
  public Double getExc68_XL()
  {
    return Exc68_XL;
  }
    
  public void setExc68_XL(Double Exc68_XL)
  {
    this.Exc68_XL = Exc68_XL;
  }
    
  public Double getExc68_TF1()
  {
    return Exc68_TF1;
  }
    
  public void setExc68_TF1(Double Exc68_TF1)
  {
    this.Exc68_TF1 = Exc68_TF1;
  }
    
  public String getKeyName()
  {
    return KeyName;
  }
    
  public void setKeyName(String KeyName)
  {
    this.KeyName = KeyName;
  }
    
  public Integer getBusPtr()
  {
    return BusPtr;
  }
    
  public void setBusPtr(Integer BusPtr)
  {
    this.BusPtr = BusPtr;
  }
    
  public Integer getAppendTag()
  {
    return AppendTag;
  }
    
  public void setAppendTag(Integer AppendTag)
  {
    this.AppendTag = AppendTag;
  }
    
  public String toString()
  {
    return "BpaSwi_Exc68 ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", Exc68_TR = " + Exc68_TR
	 + ", Exc68_KA_BusKV = " + Exc68_KA_BusKV
	 + ", Exc68_TR_TRH = " + Exc68_TR_TRH
	 + ", Exc68_TA1 = " + Exc68_TA1
	 + ", Exc68_VRMinMult_TRMax = " + Exc68_VRMinMult_TRMax
	 + ", Exc68_KE = " + Exc68_KE
	 + ", Exc68_TE = " + Exc68_TE
	 + ", Exc68_SE75Max_KI = " + Exc68_SE75Max_KI
	 + ", Exc68_SEMax_KP = " + Exc68_SEMax_KP
	 + ", Exc68_EFDMin = " + Exc68_EFDMin
	 + ", Exc68_EFDMax_VBMax = " + Exc68_EFDMax_VBMax
	 + ", Exc68_KF = " + Exc68_KF
	 + ", Exc68_TF = " + Exc68_TF
	 + ", Exc68_XL = " + Exc68_XL
	 + ", Exc68_TF1 = " + Exc68_TF1
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
