package com.znd.ei.memdb.bpa.domain;


/**********************
*1968年IEEE励磁系统模型表(E)	*
***********************/
public class BpaSwi_Exc68
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称,母线名
  private String aCBus_Name;
  
  //基准电压(kV),基准电压
  private Double aCBus_kV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //TR,调压器输入的滤波器时间常数
  private Double exc68_TR;
  
  //KA,调压器增益
  private Double exc68_KA_BusKV;
  
  //TA,调压器放大器时间常数
  private Double exc68_TR_TRH;
  
  //TA1,调压器放大器时间常数
  private Double exc68_TA1;
  
  //VRMAXMULT,VRMAX乘子
  private Double exc68_VRMinMult_TRMax;
  
  //KE,与自励有关的励磁常数
  private Double exc68_KE;
  
  //TE,励磁机时间常数
  private Double exc68_TE;
  
  //SE.75MAX,75％最大励磁电压时的励磁机饱和系数
  private Double exc68_SE75Max_KI;
  
  //SEMAX,最大励磁电压时的励磁机饱和系数
  private Double exc68_SEMax_KP;
  
  //EFDMIN,最小励磁电压
  private Double exc68_EFDMin;
  
  //EFDMAX,最大励磁电压
  private Double exc68_EFDMax_VBMax;
  
  //KF,调压器稳定回路增益
  private Double exc68_KF;
  
  //TF,调压器稳定回路时间常数
  private Double exc68_TF;
  
  //XL,整流电抗
  private Double exc68_XL;
  
  //TF1,调压器稳定回路时间常数
  private Double exc68_TF1;
  
  //数据库主键
  private String keyName;
  
  //发电机母线索引
  private Integer busPtr;
  
  //新增记录标记
  private Integer appendTag;
  
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
    
  public Integer getGen_ID()
  {
    return gen_ID;
  }
    
  public void setGen_ID(Integer gen_ID)
  {
    this.gen_ID = gen_ID;
  }
    
  public Double getExc68_TR()
  {
    return exc68_TR;
  }
    
  public void setExc68_TR(Double exc68_TR)
  {
    this.exc68_TR = exc68_TR;
  }
    
  public Double getExc68_KA_BusKV()
  {
    return exc68_KA_BusKV;
  }
    
  public void setExc68_KA_BusKV(Double exc68_KA_BusKV)
  {
    this.exc68_KA_BusKV = exc68_KA_BusKV;
  }
    
  public Double getExc68_TR_TRH()
  {
    return exc68_TR_TRH;
  }
    
  public void setExc68_TR_TRH(Double exc68_TR_TRH)
  {
    this.exc68_TR_TRH = exc68_TR_TRH;
  }
    
  public Double getExc68_TA1()
  {
    return exc68_TA1;
  }
    
  public void setExc68_TA1(Double exc68_TA1)
  {
    this.exc68_TA1 = exc68_TA1;
  }
    
  public Double getExc68_VRMinMult_TRMax()
  {
    return exc68_VRMinMult_TRMax;
  }
    
  public void setExc68_VRMinMult_TRMax(Double exc68_VRMinMult_TRMax)
  {
    this.exc68_VRMinMult_TRMax = exc68_VRMinMult_TRMax;
  }
    
  public Double getExc68_KE()
  {
    return exc68_KE;
  }
    
  public void setExc68_KE(Double exc68_KE)
  {
    this.exc68_KE = exc68_KE;
  }
    
  public Double getExc68_TE()
  {
    return exc68_TE;
  }
    
  public void setExc68_TE(Double exc68_TE)
  {
    this.exc68_TE = exc68_TE;
  }
    
  public Double getExc68_SE75Max_KI()
  {
    return exc68_SE75Max_KI;
  }
    
  public void setExc68_SE75Max_KI(Double exc68_SE75Max_KI)
  {
    this.exc68_SE75Max_KI = exc68_SE75Max_KI;
  }
    
  public Double getExc68_SEMax_KP()
  {
    return exc68_SEMax_KP;
  }
    
  public void setExc68_SEMax_KP(Double exc68_SEMax_KP)
  {
    this.exc68_SEMax_KP = exc68_SEMax_KP;
  }
    
  public Double getExc68_EFDMin()
  {
    return exc68_EFDMin;
  }
    
  public void setExc68_EFDMin(Double exc68_EFDMin)
  {
    this.exc68_EFDMin = exc68_EFDMin;
  }
    
  public Double getExc68_EFDMax_VBMax()
  {
    return exc68_EFDMax_VBMax;
  }
    
  public void setExc68_EFDMax_VBMax(Double exc68_EFDMax_VBMax)
  {
    this.exc68_EFDMax_VBMax = exc68_EFDMax_VBMax;
  }
    
  public Double getExc68_KF()
  {
    return exc68_KF;
  }
    
  public void setExc68_KF(Double exc68_KF)
  {
    this.exc68_KF = exc68_KF;
  }
    
  public Double getExc68_TF()
  {
    return exc68_TF;
  }
    
  public void setExc68_TF(Double exc68_TF)
  {
    this.exc68_TF = exc68_TF;
  }
    
  public Double getExc68_XL()
  {
    return exc68_XL;
  }
    
  public void setExc68_XL(Double exc68_XL)
  {
    this.exc68_XL = exc68_XL;
  }
    
  public Double getExc68_TF1()
  {
    return exc68_TF1;
  }
    
  public void setExc68_TF1(Double exc68_TF1)
  {
    this.exc68_TF1 = exc68_TF1;
  }
    
  public String getKeyName()
  {
    return keyName;
  }
    
  public void setKeyName(String keyName)
  {
    this.keyName = keyName;
  }
    
  public Integer getBusPtr()
  {
    return busPtr;
  }
    
  public void setBusPtr(Integer busPtr)
  {
    this.busPtr = busPtr;
  }
    
  public Integer getAppendTag()
  {
    return appendTag;
  }
    
  public void setAppendTag(Integer appendTag)
  {
    this.appendTag = appendTag;
  }
    
  public String toString()
  {
    return "BpaSwi_Exc68 ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"aCBus_Name"=aCBus_Name,
	"aCBus_kV"=aCBus_kV,
	"gen_ID"=gen_ID,
	"exc68_TR"=exc68_TR,
	"exc68_KA_BusKV"=exc68_KA_BusKV,
	"exc68_TR_TRH"=exc68_TR_TRH,
	"exc68_TA1"=exc68_TA1,
	"exc68_VRMinMult_TRMax"=exc68_VRMinMult_TRMax,
	"exc68_KE"=exc68_KE,
	"exc68_TE"=exc68_TE,
	"exc68_SE75Max_KI"=exc68_SE75Max_KI,
	"exc68_SEMax_KP"=exc68_SEMax_KP,
	"exc68_EFDMin"=exc68_EFDMin,
	"exc68_EFDMax_VBMax"=exc68_EFDMax_VBMax,
	"exc68_KF"=exc68_KF,
	"exc68_TF"=exc68_TF,
	"exc68_XL"=exc68_XL,
	"exc68_TF1"=exc68_TF1,
	"keyName"=keyName,
	"busPtr"=busPtr,
	"appendTag"=appendTag+"]"
  }
    
}
    
