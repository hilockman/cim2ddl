package com.znd.ei.memdb.bpa.domain;


/**********************
*发电机阻尼模型表(M)	*
***********************/
public class BpaSwi_Damp
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //电机母线名
  private String aCBus_Name;
  
  //电机母线电压(kV)
  private Double aCBus_kV;
  
  //电机识别码
  private Integer damp_ID;
  
  //电机额定容量
  private Double damp_MVA;
  
  //电机功率因数
  private Double damp_PF;
  
  //直轴次暂态电抗Xdpp(pu)
  private Double damp_Xdpp;
  
  //交轴次暂态电抗Xqpp(pu)
  private Double damp_Xqpp;
  
  //直轴次暂态时间常数Td0pp(秒)
  private Double damp_Td0pp;
  
  //交轴次暂态时间常数Tq0pp(秒)
  private Double damp_Tq0pp;
  
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
    
  public Integer getDamp_ID()
  {
    return damp_ID;
  }
    
  public void setDamp_ID(Integer damp_ID)
  {
    this.damp_ID = damp_ID;
  }
    
  public Double getDamp_MVA()
  {
    return damp_MVA;
  }
    
  public void setDamp_MVA(Double damp_MVA)
  {
    this.damp_MVA = damp_MVA;
  }
    
  public Double getDamp_PF()
  {
    return damp_PF;
  }
    
  public void setDamp_PF(Double damp_PF)
  {
    this.damp_PF = damp_PF;
  }
    
  public Double getDamp_Xdpp()
  {
    return damp_Xdpp;
  }
    
  public void setDamp_Xdpp(Double damp_Xdpp)
  {
    this.damp_Xdpp = damp_Xdpp;
  }
    
  public Double getDamp_Xqpp()
  {
    return damp_Xqpp;
  }
    
  public void setDamp_Xqpp(Double damp_Xqpp)
  {
    this.damp_Xqpp = damp_Xqpp;
  }
    
  public Double getDamp_Td0pp()
  {
    return damp_Td0pp;
  }
    
  public void setDamp_Td0pp(Double damp_Td0pp)
  {
    this.damp_Td0pp = damp_Td0pp;
  }
    
  public Double getDamp_Tq0pp()
  {
    return damp_Tq0pp;
  }
    
  public void setDamp_Tq0pp(Double damp_Tq0pp)
  {
    this.damp_Tq0pp = damp_Tq0pp;
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
    return "BpaSwi_Damp ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", damp_ID = " + damp_ID
	 + ", damp_MVA = " + damp_MVA
	 + ", damp_PF = " + damp_PF
	 + ", damp_Xdpp = " + damp_Xdpp
	 + ", damp_Xqpp = " + damp_Xqpp
	 + ", damp_Td0pp = " + damp_Td0pp
	 + ", damp_Tq0pp = " + damp_Tq0pp
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
