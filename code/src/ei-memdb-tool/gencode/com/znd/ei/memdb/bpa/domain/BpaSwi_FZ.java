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
  private String CardKey;
  
  //母线名
  private String ACBus_Name;
  
  //基准电压
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //励磁电压处的励磁机饱和系数/电流回路增益系数(D、L)
  private Double FZ_SE1_KI;
  
  //励磁电压75％处的励磁机饱和系数/电势回路增益系数(D、L)
  private Double FZ_SE2_KP;
  
  //励磁机最小输出电压(J)/稳定反馈增益改变处的励磁电压/电压回路像角差(L)
  private Double FZ_EFDMin_EFDN_DP;
  
  //励磁电压(A、B、E)/换向电抗后励磁电压(C、F、H)/最大励磁电压(D、L)
  private Double FZ_EFD1_VE1_EFDMax;
  
  //励磁控制系统稳定器增益/内反馈回路常数(L)
  private Double FZ_KF_KG;
  
  //励磁控制系统时间常数/内反馈回路最大电压(L)
  private Double FZ_TF_VGMax;
  
  //换相电抗的整流器负载因子
  private Double FZ_KC;
  
  //去磁因子(C、F、H)/电势源电抗(L)
  private Double FZ_KD_XL;
  
  //第二极调节器增益(F)/励磁机低电压限制(H)
  private Double FZ_KB_VLV;
  
  //励磁机励磁电流限制增益(F)/励磁机低电压限制信号增益(H)
  private Double FZ_KL_KLV;
  
  //励磁机励磁电流反馈增益(F)/励磁控制系统稳定器增益(上段)(H)
  private Double FZ_KH_KN;
  
  //励磁机励磁电流限制(F)/联接调节器和变换器励磁功率的常数(H)
  private Double FZ_VLR_KR;
  
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
    
  public Double getFZ_SE1_KI()
  {
    return FZ_SE1_KI;
  }
    
  public void setFZ_SE1_KI(Double FZ_SE1_KI)
  {
    this.FZ_SE1_KI = FZ_SE1_KI;
  }
    
  public Double getFZ_SE2_KP()
  {
    return FZ_SE2_KP;
  }
    
  public void setFZ_SE2_KP(Double FZ_SE2_KP)
  {
    this.FZ_SE2_KP = FZ_SE2_KP;
  }
    
  public Double getFZ_EFDMin_EFDN_DP()
  {
    return FZ_EFDMin_EFDN_DP;
  }
    
  public void setFZ_EFDMin_EFDN_DP(Double FZ_EFDMin_EFDN_DP)
  {
    this.FZ_EFDMin_EFDN_DP = FZ_EFDMin_EFDN_DP;
  }
    
  public Double getFZ_EFD1_VE1_EFDMax()
  {
    return FZ_EFD1_VE1_EFDMax;
  }
    
  public void setFZ_EFD1_VE1_EFDMax(Double FZ_EFD1_VE1_EFDMax)
  {
    this.FZ_EFD1_VE1_EFDMax = FZ_EFD1_VE1_EFDMax;
  }
    
  public Double getFZ_KF_KG()
  {
    return FZ_KF_KG;
  }
    
  public void setFZ_KF_KG(Double FZ_KF_KG)
  {
    this.FZ_KF_KG = FZ_KF_KG;
  }
    
  public Double getFZ_TF_VGMax()
  {
    return FZ_TF_VGMax;
  }
    
  public void setFZ_TF_VGMax(Double FZ_TF_VGMax)
  {
    this.FZ_TF_VGMax = FZ_TF_VGMax;
  }
    
  public Double getFZ_KC()
  {
    return FZ_KC;
  }
    
  public void setFZ_KC(Double FZ_KC)
  {
    this.FZ_KC = FZ_KC;
  }
    
  public Double getFZ_KD_XL()
  {
    return FZ_KD_XL;
  }
    
  public void setFZ_KD_XL(Double FZ_KD_XL)
  {
    this.FZ_KD_XL = FZ_KD_XL;
  }
    
  public Double getFZ_KB_VLV()
  {
    return FZ_KB_VLV;
  }
    
  public void setFZ_KB_VLV(Double FZ_KB_VLV)
  {
    this.FZ_KB_VLV = FZ_KB_VLV;
  }
    
  public Double getFZ_KL_KLV()
  {
    return FZ_KL_KLV;
  }
    
  public void setFZ_KL_KLV(Double FZ_KL_KLV)
  {
    this.FZ_KL_KLV = FZ_KL_KLV;
  }
    
  public Double getFZ_KH_KN()
  {
    return FZ_KH_KN;
  }
    
  public void setFZ_KH_KN(Double FZ_KH_KN)
  {
    this.FZ_KH_KN = FZ_KH_KN;
  }
    
  public Double getFZ_VLR_KR()
  {
    return FZ_VLR_KR;
  }
    
  public void setFZ_VLR_KR(Double FZ_VLR_KR)
  {
    this.FZ_VLR_KR = FZ_VLR_KR;
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
    return "BpaSwi_FZ ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", FZ_SE1_KI = " + FZ_SE1_KI
	 + ", FZ_SE2_KP = " + FZ_SE2_KP
	 + ", FZ_EFDMin_EFDN_DP = " + FZ_EFDMin_EFDN_DP
	 + ", FZ_EFD1_VE1_EFDMax = " + FZ_EFD1_VE1_EFDMax
	 + ", FZ_KF_KG = " + FZ_KF_KG
	 + ", FZ_TF_VGMax = " + FZ_TF_VGMax
	 + ", FZ_KC = " + FZ_KC
	 + ", FZ_KD_XL = " + FZ_KD_XL
	 + ", FZ_KB_VLV = " + FZ_KB_VLV
	 + ", FZ_KL_KLV = " + FZ_KL_KLV
	 + ", FZ_KH_KN = " + FZ_KH_KN
	 + ", FZ_VLR_KR = " + FZ_VLR_KR
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
