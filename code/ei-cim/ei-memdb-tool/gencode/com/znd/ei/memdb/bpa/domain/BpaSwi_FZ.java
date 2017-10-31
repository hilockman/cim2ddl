package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*励磁系统继续卡(FZ)	*
***********************/
public class BpaSwi_FZ  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名
  private String aCBus_Name;
  
  //基准电压
  private Double aCBus_kV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //励磁电压处的励磁机饱和系数/电流回路增益系数(D、L)
  private Double fZ_SE1_KI;
  
  //励磁电压75％处的励磁机饱和系数/电势回路增益系数(D、L)
  private Double fZ_SE2_KP;
  
  //励磁机最小输出电压(J)/稳定反馈增益改变处的励磁电压/电压回路像角差(L)
  private Double fZ_EFDMin_EFDN_DP;
  
  //励磁电压(A、B、E)/换向电抗后励磁电压(C、F、H)/最大励磁电压(D、L)
  private Double fZ_EFD1_VE1_EFDMax;
  
  //励磁控制系统稳定器增益/内反馈回路常数(L)
  private Double fZ_KF_KG;
  
  //励磁控制系统时间常数/内反馈回路最大电压(L)
  private Double fZ_TF_VGMax;
  
  //换相电抗的整流器负载因子
  private Double fZ_KC;
  
  //去磁因子(C、F、H)/电势源电抗(L)
  private Double fZ_KD_XL;
  
  //第二极调节器增益(F)/励磁机低电压限制(H)
  private Double fZ_KB_VLV;
  
  //励磁机励磁电流限制增益(F)/励磁机低电压限制信号增益(H)
  private Double fZ_KL_KLV;
  
  //励磁机励磁电流反馈增益(F)/励磁控制系统稳定器增益(上段)(H)
  private Double fZ_KH_KN;
  
  //励磁机励磁电流限制(F)/联接调节器和变换器励磁功率的常数(H)
  private Double fZ_VLR_KR;
  
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
    
  public Double getFZ_SE1_KI()
  {
    return fZ_SE1_KI;
  }
    
  public void setFZ_SE1_KI(Double fZ_SE1_KI)
  {
    this.fZ_SE1_KI = fZ_SE1_KI;
  }
    
  public Double getFZ_SE2_KP()
  {
    return fZ_SE2_KP;
  }
    
  public void setFZ_SE2_KP(Double fZ_SE2_KP)
  {
    this.fZ_SE2_KP = fZ_SE2_KP;
  }
    
  public Double getFZ_EFDMin_EFDN_DP()
  {
    return fZ_EFDMin_EFDN_DP;
  }
    
  public void setFZ_EFDMin_EFDN_DP(Double fZ_EFDMin_EFDN_DP)
  {
    this.fZ_EFDMin_EFDN_DP = fZ_EFDMin_EFDN_DP;
  }
    
  public Double getFZ_EFD1_VE1_EFDMax()
  {
    return fZ_EFD1_VE1_EFDMax;
  }
    
  public void setFZ_EFD1_VE1_EFDMax(Double fZ_EFD1_VE1_EFDMax)
  {
    this.fZ_EFD1_VE1_EFDMax = fZ_EFD1_VE1_EFDMax;
  }
    
  public Double getFZ_KF_KG()
  {
    return fZ_KF_KG;
  }
    
  public void setFZ_KF_KG(Double fZ_KF_KG)
  {
    this.fZ_KF_KG = fZ_KF_KG;
  }
    
  public Double getFZ_TF_VGMax()
  {
    return fZ_TF_VGMax;
  }
    
  public void setFZ_TF_VGMax(Double fZ_TF_VGMax)
  {
    this.fZ_TF_VGMax = fZ_TF_VGMax;
  }
    
  public Double getFZ_KC()
  {
    return fZ_KC;
  }
    
  public void setFZ_KC(Double fZ_KC)
  {
    this.fZ_KC = fZ_KC;
  }
    
  public Double getFZ_KD_XL()
  {
    return fZ_KD_XL;
  }
    
  public void setFZ_KD_XL(Double fZ_KD_XL)
  {
    this.fZ_KD_XL = fZ_KD_XL;
  }
    
  public Double getFZ_KB_VLV()
  {
    return fZ_KB_VLV;
  }
    
  public void setFZ_KB_VLV(Double fZ_KB_VLV)
  {
    this.fZ_KB_VLV = fZ_KB_VLV;
  }
    
  public Double getFZ_KL_KLV()
  {
    return fZ_KL_KLV;
  }
    
  public void setFZ_KL_KLV(Double fZ_KL_KLV)
  {
    this.fZ_KL_KLV = fZ_KL_KLV;
  }
    
  public Double getFZ_KH_KN()
  {
    return fZ_KH_KN;
  }
    
  public void setFZ_KH_KN(Double fZ_KH_KN)
  {
    this.fZ_KH_KN = fZ_KH_KN;
  }
    
  public Double getFZ_VLR_KR()
  {
    return fZ_VLR_KR;
  }
    
  public void setFZ_VLR_KR(Double fZ_VLR_KR)
  {
    this.fZ_VLR_KR = fZ_VLR_KR;
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
    return "BpaSwi_FZ ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", fZ_SE1_KI = " + fZ_SE1_KI
	 + ", fZ_SE2_KP = " + fZ_SE2_KP
	 + ", fZ_EFDMin_EFDN_DP = " + fZ_EFDMin_EFDN_DP
	 + ", fZ_EFD1_VE1_EFDMax = " + fZ_EFD1_VE1_EFDMax
	 + ", fZ_KF_KG = " + fZ_KF_KG
	 + ", fZ_TF_VGMax = " + fZ_TF_VGMax
	 + ", fZ_KC = " + fZ_KC
	 + ", fZ_KD_XL = " + fZ_KD_XL
	 + ", fZ_KB_VLV = " + fZ_KB_VLV
	 + ", fZ_KL_KLV = " + fZ_KL_KLV
	 + ", fZ_KH_KN = " + fZ_KH_KN
	 + ", fZ_VLR_KR = " + fZ_VLR_KR
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
