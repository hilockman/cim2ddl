package com.znd.ei.memdb.bpa.domain;


/**********************
*水轮机模型表(TW)	*
***********************/
public class BpaSwi_TW
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
  
  //汽轮机K1=1.0;水轮机K1=-2.0(必须)
  private Double tW_K1;
  
  //水锤效应时间常数(秒)
  private Double tW_Tw_Half;
  
  //K3=3.0(必须)
  private Double tW_K3;
  
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
    
  public Double getTW_K1()
  {
    return tW_K1;
  }
    
  public void setTW_K1(Double tW_K1)
  {
    this.tW_K1 = tW_K1;
  }
    
  public Double getTW_Tw_Half()
  {
    return tW_Tw_Half;
  }
    
  public void setTW_Tw_Half(Double tW_Tw_Half)
  {
    this.tW_Tw_Half = tW_Tw_Half;
  }
    
  public Double getTW_K3()
  {
    return tW_K3;
  }
    
  public void setTW_K3(Double tW_K3)
  {
    this.tW_K3 = tW_K3;
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
    return "BpaSwi_TW ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"aCBus_Name"=aCBus_Name,
	"aCBus_kV"=aCBus_kV,
	"gen_ID"=gen_ID,
	"tW_K1"=tW_K1,
	"tW_Tw_Half"=tW_Tw_Half,
	"tW_K3"=tW_K3,
	"keyName"=keyName,
	"busPtr"=busPtr,
	"appendTag"=appendTag+"]"
  }
    
}
    
