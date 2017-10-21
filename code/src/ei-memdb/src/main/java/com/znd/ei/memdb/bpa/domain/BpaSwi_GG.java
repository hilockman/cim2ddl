package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*调速器和原动机组合模型表(GG)	*
***********************/
public class BpaSwi_GG  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //发电机名称
  private String aCBus_Name;
  
  //发电机基准电压(kV)
  private Double aCBus_kV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //原动机最大输出功率(MW)
  private Double gen_Pmax;
  
  //调差系数
  private Double gG_R;
  
  //控制时间
  private Double gG_T1;
  
  //水轮机恢复时间
  private Double gG_T2;
  
  //伺服机时间常数
  private Double gG_T3;
  
  //汽轮机阀时间常数
  private Double gG_T4;
  
  //水轮机1/2倍水锤效应时间常数/汽轮机再热器时间常数
  private Double gG_T5;
  
  //水轮机F=－2;对汽轮机F=再热器前轴容量/总的轴容量
  private Double gG_F;
  
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
    
  public Double getGen_Pmax()
  {
    return gen_Pmax;
  }
    
  public void setGen_Pmax(Double gen_Pmax)
  {
    this.gen_Pmax = gen_Pmax;
  }
    
  public Double getGG_R()
  {
    return gG_R;
  }
    
  public void setGG_R(Double gG_R)
  {
    this.gG_R = gG_R;
  }
    
  public Double getGG_T1()
  {
    return gG_T1;
  }
    
  public void setGG_T1(Double gG_T1)
  {
    this.gG_T1 = gG_T1;
  }
    
  public Double getGG_T2()
  {
    return gG_T2;
  }
    
  public void setGG_T2(Double gG_T2)
  {
    this.gG_T2 = gG_T2;
  }
    
  public Double getGG_T3()
  {
    return gG_T3;
  }
    
  public void setGG_T3(Double gG_T3)
  {
    this.gG_T3 = gG_T3;
  }
    
  public Double getGG_T4()
  {
    return gG_T4;
  }
    
  public void setGG_T4(Double gG_T4)
  {
    this.gG_T4 = gG_T4;
  }
    
  public Double getGG_T5()
  {
    return gG_T5;
  }
    
  public void setGG_T5(Double gG_T5)
  {
    this.gG_T5 = gG_T5;
  }
    
  public Double getGG_F()
  {
    return gG_F;
  }
    
  public void setGG_F(Double gG_F)
  {
    this.gG_F = gG_F;
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
    return "BpaSwi_GG ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", gen_Pmax = " + gen_Pmax
	 + ", gG_R = " + gG_R
	 + ", gG_T1 = " + gG_T1
	 + ", gG_T2 = " + gG_T2
	 + ", gG_T3 = " + gG_T3
	 + ", gG_T4 = " + gG_T4
	 + ", gG_T5 = " + gG_T5
	 + ", gG_F = " + gG_F
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
