package com.znd.ei.memdb.bpa.domain;


/**********************
*无再热器汽轮机模型表(TA)	*
***********************/
public class BpaSwi_TA
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
  
  //蒸汽容积时间常数(秒)
  private Double tA_TCH;
  
  //汽轮机K1=1.0;水轮机K1=-2.0(必须)
  private Double tA_K1;
  
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
    
  public Double getTA_TCH()
  {
    return tA_TCH;
  }
    
  public void setTA_TCH(Double tA_TCH)
  {
    this.tA_TCH = tA_TCH;
  }
    
  public Double getTA_K1()
  {
    return tA_K1;
  }
    
  public void setTA_K1(Double tA_K1)
  {
    this.tA_K1 = tA_K1;
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
    return "BpaSwi_TA ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"aCBus_Name"=aCBus_Name,
	"aCBus_kV"=aCBus_kV,
	"gen_ID"=gen_ID,
	"tA_TCH"=tA_TCH,
	"tA_K1"=tA_K1,
	"keyName"=keyName,
	"busPtr"=busPtr,
	"appendTag"=appendTag+"]"
  }
    
}
    
