package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*励磁系统继续卡(F+)	*
***********************/
public class BpaSwi_FCA  implements MemIndexable 
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
  
  //调节器最大内部电压(pu)
  private Double FCA_VAMax;
  
  //调节器最小内部电压(pu)
  private Double FCA_VAMin;
  
  //第二级调节器增益
  private Double FCA_KB;
  
  //第二级调节器时间常数
  private Double FCA_T5;
  
  //励磁机自励磁系数(pu)
  private Double FCA_KE;
  
  //励磁机时间常数(秒)
  private Double FCA_TE;
  
  //最大励磁电压处的励磁机饱和系数
  private Double FCA_SE1;
  
  //SE2,75％最大励磁电压处的励磁机饱和系数
  private Double FCA_SE2;
  
  //电压调节器最大输出(pu)
  private Double FCA_VRMax;
  
  //电压调节器最小输出(pu)
  private Double FCA_VRMin;
  
  //换相电抗的整流器负载因子
  private Double FCA_KC;
  
  //去磁因子(pu)
  private Double FCA_KD;
  
  //励磁机励磁电流限制增益(pu)
  private Double FCA_KL1;
  
  //励磁机电流限制(pu)
  private Double FCA_VL1R;
  
  //最大励磁电压(pu)
  private Double FCA_EFDMax;
  
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
    
  public Double getFCA_VAMax()
  {
    return FCA_VAMax;
  }
    
  public void setFCA_VAMax(Double FCA_VAMax)
  {
    this.FCA_VAMax = FCA_VAMax;
  }
    
  public Double getFCA_VAMin()
  {
    return FCA_VAMin;
  }
    
  public void setFCA_VAMin(Double FCA_VAMin)
  {
    this.FCA_VAMin = FCA_VAMin;
  }
    
  public Double getFCA_KB()
  {
    return FCA_KB;
  }
    
  public void setFCA_KB(Double FCA_KB)
  {
    this.FCA_KB = FCA_KB;
  }
    
  public Double getFCA_T5()
  {
    return FCA_T5;
  }
    
  public void setFCA_T5(Double FCA_T5)
  {
    this.FCA_T5 = FCA_T5;
  }
    
  public Double getFCA_KE()
  {
    return FCA_KE;
  }
    
  public void setFCA_KE(Double FCA_KE)
  {
    this.FCA_KE = FCA_KE;
  }
    
  public Double getFCA_TE()
  {
    return FCA_TE;
  }
    
  public void setFCA_TE(Double FCA_TE)
  {
    this.FCA_TE = FCA_TE;
  }
    
  public Double getFCA_SE1()
  {
    return FCA_SE1;
  }
    
  public void setFCA_SE1(Double FCA_SE1)
  {
    this.FCA_SE1 = FCA_SE1;
  }
    
  public Double getFCA_SE2()
  {
    return FCA_SE2;
  }
    
  public void setFCA_SE2(Double FCA_SE2)
  {
    this.FCA_SE2 = FCA_SE2;
  }
    
  public Double getFCA_VRMax()
  {
    return FCA_VRMax;
  }
    
  public void setFCA_VRMax(Double FCA_VRMax)
  {
    this.FCA_VRMax = FCA_VRMax;
  }
    
  public Double getFCA_VRMin()
  {
    return FCA_VRMin;
  }
    
  public void setFCA_VRMin(Double FCA_VRMin)
  {
    this.FCA_VRMin = FCA_VRMin;
  }
    
  public Double getFCA_KC()
  {
    return FCA_KC;
  }
    
  public void setFCA_KC(Double FCA_KC)
  {
    this.FCA_KC = FCA_KC;
  }
    
  public Double getFCA_KD()
  {
    return FCA_KD;
  }
    
  public void setFCA_KD(Double FCA_KD)
  {
    this.FCA_KD = FCA_KD;
  }
    
  public Double getFCA_KL1()
  {
    return FCA_KL1;
  }
    
  public void setFCA_KL1(Double FCA_KL1)
  {
    this.FCA_KL1 = FCA_KL1;
  }
    
  public Double getFCA_VL1R()
  {
    return FCA_VL1R;
  }
    
  public void setFCA_VL1R(Double FCA_VL1R)
  {
    this.FCA_VL1R = FCA_VL1R;
  }
    
  public Double getFCA_EFDMax()
  {
    return FCA_EFDMax;
  }
    
  public void setFCA_EFDMax(Double FCA_EFDMax)
  {
    this.FCA_EFDMax = FCA_EFDMax;
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
    return "BpaSwi_FCA ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", FCA_VAMax = " + FCA_VAMax
	 + ", FCA_VAMin = " + FCA_VAMin
	 + ", FCA_KB = " + FCA_KB
	 + ", FCA_T5 = " + FCA_T5
	 + ", FCA_KE = " + FCA_KE
	 + ", FCA_TE = " + FCA_TE
	 + ", FCA_SE1 = " + FCA_SE1
	 + ", FCA_SE2 = " + FCA_SE2
	 + ", FCA_VRMax = " + FCA_VRMax
	 + ", FCA_VRMin = " + FCA_VRMin
	 + ", FCA_KC = " + FCA_KC
	 + ", FCA_KD = " + FCA_KD
	 + ", FCA_KL1 = " + FCA_KL1
	 + ", FCA_VL1R = " + FCA_VL1R
	 + ", FCA_EFDMax = " + FCA_EFDMax
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
