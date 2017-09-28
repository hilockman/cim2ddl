package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*励磁系统继续卡(F+)	*
***********************/
@Entity
public class BpaSwi_FCA
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
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
  
  //调节器最大内部电压(pu)
  private Double f+_VAMax;
  
  //调节器最小内部电压(pu)
  private Double f+_VAMin;
  
  //第二级调节器增益
  private Double f+_KB;
  
  //第二级调节器时间常数
  private Double f+_T5;
  
  //励磁机自励磁系数(pu)
  private Double f+_KE;
  
  //励磁机时间常数(秒)
  private Double f+_TE;
  
  //最大励磁电压处的励磁机饱和系数
  private Double f+_SE1;
  
  //SE2,75％最大励磁电压处的励磁机饱和系数
  private Double f+_SE2;
  
  //电压调节器最大输出(pu)
  private Double f+_VRMax;
  
  //电压调节器最小输出(pu)
  private Double f+_VRMin;
  
  //换相电抗的整流器负载因子
  private Double f+_KC;
  
  //去磁因子(pu)
  private Double f+_KD;
  
  //励磁机励磁电流限制增益(pu)
  private Double f+_KL1;
  
  //励磁机电流限制(pu)
  private Double f+_VL1R;
  
  //最大励磁电压(pu)
  private Double f+_EFDMax;
  
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
    
  public Double getF+_VAMax() 
  {
    return f+_VAMax;
  }
    
  public void setF+_VAMax(Double f+_VAMax)
  {
    this.f+_VAMax = f+_VAMax;
  }
    
  public Double getF+_VAMin() 
  {
    return f+_VAMin;
  }
    
  public void setF+_VAMin(Double f+_VAMin)
  {
    this.f+_VAMin = f+_VAMin;
  }
    
  public Double getF+_KB() 
  {
    return f+_KB;
  }
    
  public void setF+_KB(Double f+_KB)
  {
    this.f+_KB = f+_KB;
  }
    
  public Double getF+_T5() 
  {
    return f+_T5;
  }
    
  public void setF+_T5(Double f+_T5)
  {
    this.f+_T5 = f+_T5;
  }
    
  public Double getF+_KE() 
  {
    return f+_KE;
  }
    
  public void setF+_KE(Double f+_KE)
  {
    this.f+_KE = f+_KE;
  }
    
  public Double getF+_TE() 
  {
    return f+_TE;
  }
    
  public void setF+_TE(Double f+_TE)
  {
    this.f+_TE = f+_TE;
  }
    
  public Double getF+_SE1() 
  {
    return f+_SE1;
  }
    
  public void setF+_SE1(Double f+_SE1)
  {
    this.f+_SE1 = f+_SE1;
  }
    
  public Double getF+_SE2() 
  {
    return f+_SE2;
  }
    
  public void setF+_SE2(Double f+_SE2)
  {
    this.f+_SE2 = f+_SE2;
  }
    
  public Double getF+_VRMax() 
  {
    return f+_VRMax;
  }
    
  public void setF+_VRMax(Double f+_VRMax)
  {
    this.f+_VRMax = f+_VRMax;
  }
    
  public Double getF+_VRMin() 
  {
    return f+_VRMin;
  }
    
  public void setF+_VRMin(Double f+_VRMin)
  {
    this.f+_VRMin = f+_VRMin;
  }
    
  public Double getF+_KC() 
  {
    return f+_KC;
  }
    
  public void setF+_KC(Double f+_KC)
  {
    this.f+_KC = f+_KC;
  }
    
  public Double getF+_KD() 
  {
    return f+_KD;
  }
    
  public void setF+_KD(Double f+_KD)
  {
    this.f+_KD = f+_KD;
  }
    
  public Double getF+_KL1() 
  {
    return f+_KL1;
  }
    
  public void setF+_KL1(Double f+_KL1)
  {
    this.f+_KL1 = f+_KL1;
  }
    
  public Double getF+_VL1R() 
  {
    return f+_VL1R;
  }
    
  public void setF+_VL1R(Double f+_VL1R)
  {
    this.f+_VL1R = f+_VL1R;
  }
    
  public Double getF+_EFDMax() 
  {
    return f+_EFDMax;
  }
    
  public void setF+_EFDMax(Double f+_EFDMax)
  {
    this.f+_EFDMax = f+_EFDMax;
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
    
}
    
