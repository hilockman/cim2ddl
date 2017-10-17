package com.znd.ei.memdb.bpa.domain;


/**********************
*单再热器汽轮机模型表(TD)	*
***********************/
public class BpaSwi_TD
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
  private Double tD_TCH;
  
  //高压缸功率比例
  private Double tD_FHP;
  
  //再热器时间常数
  private Double tD_TRH;
  
  //中压缸功率比例
  private Double tD_FIP;
  
  //交叉管时间常数
  private Double tD_TCO;
  
  //低压缸功率比例或比例的一半
  private Double tD_FLP_1;
  
  //低压缸功率比例或比例的一半
  private Double tD_FLP_2;
  
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
    
  public Double getTD_TCH()
  {
    return tD_TCH;
  }
    
  public void setTD_TCH(Double tD_TCH)
  {
    this.tD_TCH = tD_TCH;
  }
    
  public Double getTD_FHP()
  {
    return tD_FHP;
  }
    
  public void setTD_FHP(Double tD_FHP)
  {
    this.tD_FHP = tD_FHP;
  }
    
  public Double getTD_TRH()
  {
    return tD_TRH;
  }
    
  public void setTD_TRH(Double tD_TRH)
  {
    this.tD_TRH = tD_TRH;
  }
    
  public Double getTD_FIP()
  {
    return tD_FIP;
  }
    
  public void setTD_FIP(Double tD_FIP)
  {
    this.tD_FIP = tD_FIP;
  }
    
  public Double getTD_TCO()
  {
    return tD_TCO;
  }
    
  public void setTD_TCO(Double tD_TCO)
  {
    this.tD_TCO = tD_TCO;
  }
    
  public Double getTD_FLP_1()
  {
    return tD_FLP_1;
  }
    
  public void setTD_FLP_1(Double tD_FLP_1)
  {
    this.tD_FLP_1 = tD_FLP_1;
  }
    
  public Double getTD_FLP_2()
  {
    return tD_FLP_2;
  }
    
  public void setTD_FLP_2(Double tD_FLP_2)
  {
    this.tD_FLP_2 = tD_FLP_2;
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
    return "BpaSwi_TD ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"aCBus_Name"=aCBus_Name,
	"aCBus_kV"=aCBus_kV,
	"gen_ID"=gen_ID,
	"tD_TCH"=tD_TCH,
	"tD_FHP"=tD_FHP,
	"tD_TRH"=tD_TRH,
	"tD_FIP"=tD_FIP,
	"tD_TCO"=tD_TCO,
	"tD_FLP_1"=tD_FLP_1,
	"tD_FLP_2"=tD_FLP_2,
	"keyName"=keyName,
	"busPtr"=busPtr,
	"appendTag"=appendTag+"]"
  }
    
}
    
