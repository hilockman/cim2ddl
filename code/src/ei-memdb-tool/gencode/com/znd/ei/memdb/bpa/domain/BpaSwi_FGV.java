package com.znd.ei.memdb.bpa.domain;


/**********************
*发电机机械功率周期波动表(FGV)	*
***********************/
public class BpaSwi_FGV
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //发电机名称
  private String aCBus_Name;
  
  //发电机基准电压(kV)
  private Double aCBus_KV;
  
  //发电机识别码ID
  private Integer gen_ID;
  
  //第一个波动的幅值,百分数或有名值
  private Double fGV_AMP1;
  
  //第一个波动的频率(弧度/秒)
  private Double fGV_FREQ1;
  
  //第一个波动的初始相位(弧度)
  private Double fGV_ANGL01;
  
  //第一个波动的起始时间(周)
  private Double fGV_TBEGIN1;
  
  //第一个波动的结束时间(周)
  private Double fGV_TEND1;
  
  //第二个波动的幅值,百分数或有名值
  private Double fGV_AMP2;
  
  //第二个波动的频率(弧度/秒)
  private Double fGV_FREQ2;
  
  //第二个波动的初始相位(弧度)
  private Double fGV_ANGL02;
  
  //第二个波动的起始时间(周)
  private Double fGV_TBEGIN2;
  
  //第二个波动的结束时间(周)
  private Double fGV_TEND2;
  
  //空格表示前两个波动的幅值都是发电机机械功率初值的百分数;W,为有名值
  private Integer fGV_CMW;
  
  //数据库主键
  private String keyName;
  
  //发电机母线索引
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
    
  public Double getACBus_KV()
  {
    return aCBus_KV;
  }
    
  public void setACBus_KV(Double aCBus_KV)
  {
    this.aCBus_KV = aCBus_KV;
  }
    
  public Integer getGen_ID()
  {
    return gen_ID;
  }
    
  public void setGen_ID(Integer gen_ID)
  {
    this.gen_ID = gen_ID;
  }
    
  public Double getFGV_AMP1()
  {
    return fGV_AMP1;
  }
    
  public void setFGV_AMP1(Double fGV_AMP1)
  {
    this.fGV_AMP1 = fGV_AMP1;
  }
    
  public Double getFGV_FREQ1()
  {
    return fGV_FREQ1;
  }
    
  public void setFGV_FREQ1(Double fGV_FREQ1)
  {
    this.fGV_FREQ1 = fGV_FREQ1;
  }
    
  public Double getFGV_ANGL01()
  {
    return fGV_ANGL01;
  }
    
  public void setFGV_ANGL01(Double fGV_ANGL01)
  {
    this.fGV_ANGL01 = fGV_ANGL01;
  }
    
  public Double getFGV_TBEGIN1()
  {
    return fGV_TBEGIN1;
  }
    
  public void setFGV_TBEGIN1(Double fGV_TBEGIN1)
  {
    this.fGV_TBEGIN1 = fGV_TBEGIN1;
  }
    
  public Double getFGV_TEND1()
  {
    return fGV_TEND1;
  }
    
  public void setFGV_TEND1(Double fGV_TEND1)
  {
    this.fGV_TEND1 = fGV_TEND1;
  }
    
  public Double getFGV_AMP2()
  {
    return fGV_AMP2;
  }
    
  public void setFGV_AMP2(Double fGV_AMP2)
  {
    this.fGV_AMP2 = fGV_AMP2;
  }
    
  public Double getFGV_FREQ2()
  {
    return fGV_FREQ2;
  }
    
  public void setFGV_FREQ2(Double fGV_FREQ2)
  {
    this.fGV_FREQ2 = fGV_FREQ2;
  }
    
  public Double getFGV_ANGL02()
  {
    return fGV_ANGL02;
  }
    
  public void setFGV_ANGL02(Double fGV_ANGL02)
  {
    this.fGV_ANGL02 = fGV_ANGL02;
  }
    
  public Double getFGV_TBEGIN2()
  {
    return fGV_TBEGIN2;
  }
    
  public void setFGV_TBEGIN2(Double fGV_TBEGIN2)
  {
    this.fGV_TBEGIN2 = fGV_TBEGIN2;
  }
    
  public Double getFGV_TEND2()
  {
    return fGV_TEND2;
  }
    
  public void setFGV_TEND2(Double fGV_TEND2)
  {
    this.fGV_TEND2 = fGV_TEND2;
  }
    
  public Integer getFGV_CMW()
  {
    return fGV_CMW;
  }
    
  public void setFGV_CMW(Integer fGV_CMW)
  {
    this.fGV_CMW = fGV_CMW;
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
    
  public String toString()
  {
    return "BpaSwi_FGV ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_KV = " + aCBus_KV
	 + ", gen_ID = " + gen_ID
	 + ", fGV_AMP1 = " + fGV_AMP1
	 + ", fGV_FREQ1 = " + fGV_FREQ1
	 + ", fGV_ANGL01 = " + fGV_ANGL01
	 + ", fGV_TBEGIN1 = " + fGV_TBEGIN1
	 + ", fGV_TEND1 = " + fGV_TEND1
	 + ", fGV_AMP2 = " + fGV_AMP2
	 + ", fGV_FREQ2 = " + fGV_FREQ2
	 + ", fGV_ANGL02 = " + fGV_ANGL02
	 + ", fGV_TBEGIN2 = " + fGV_TBEGIN2
	 + ", fGV_TEND2 = " + fGV_TEND2
	 + ", fGV_CMW = " + fGV_CMW
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr+"]";
  }
    
}
    
