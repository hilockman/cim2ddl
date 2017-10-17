package com.znd.ei.memdb.bpa.domain;


/**********************
*锅炉的主汽压力变化模型表(GX)	*
***********************/
public class BpaSwi_GX
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
  
  //过热器容积时间常数
  private Double gX_TSH;
  
  //汽包蓄热容积时间常数
  private Double gX_TD;
  
  //锅炉燃料释放的时间常数
  private Double gX_TW;
  
  //过热器及主汽管道流量系数
  private Double gX_K;
  
  //延时
  private Double gX_Tdelay;
  
  //输出限幅环节的最大值
  private Double gX_Limit_MAX;
  
  //输出限幅环节最小值
  private Double gX_Limit_MIN;
  
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
    
  public Double getGX_TSH()
  {
    return gX_TSH;
  }
    
  public void setGX_TSH(Double gX_TSH)
  {
    this.gX_TSH = gX_TSH;
  }
    
  public Double getGX_TD()
  {
    return gX_TD;
  }
    
  public void setGX_TD(Double gX_TD)
  {
    this.gX_TD = gX_TD;
  }
    
  public Double getGX_TW()
  {
    return gX_TW;
  }
    
  public void setGX_TW(Double gX_TW)
  {
    this.gX_TW = gX_TW;
  }
    
  public Double getGX_K()
  {
    return gX_K;
  }
    
  public void setGX_K(Double gX_K)
  {
    this.gX_K = gX_K;
  }
    
  public Double getGX_Tdelay()
  {
    return gX_Tdelay;
  }
    
  public void setGX_Tdelay(Double gX_Tdelay)
  {
    this.gX_Tdelay = gX_Tdelay;
  }
    
  public Double getGX_Limit_MAX()
  {
    return gX_Limit_MAX;
  }
    
  public void setGX_Limit_MAX(Double gX_Limit_MAX)
  {
    this.gX_Limit_MAX = gX_Limit_MAX;
  }
    
  public Double getGX_Limit_MIN()
  {
    return gX_Limit_MIN;
  }
    
  public void setGX_Limit_MIN(Double gX_Limit_MIN)
  {
    this.gX_Limit_MIN = gX_Limit_MIN;
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
    return "BpaSwi_GX ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_KV = " + aCBus_KV
	 + ", gen_ID = " + gen_ID
	 + ", gX_TSH = " + gX_TSH
	 + ", gX_TD = " + gX_TD
	 + ", gX_TW = " + gX_TW
	 + ", gX_K = " + gX_K
	 + ", gX_Tdelay = " + gX_Tdelay
	 + ", gX_Limit_MAX = " + gX_Limit_MAX
	 + ", gX_Limit_MIN = " + gX_Limit_MIN
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr+"]";
  }
    
}
    
