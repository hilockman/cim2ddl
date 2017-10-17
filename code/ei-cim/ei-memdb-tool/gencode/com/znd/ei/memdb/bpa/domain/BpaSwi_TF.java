package com.znd.ei.memdb.bpa.domain;


/**********************
*双再热器汽轮机模型表(TF)	*
***********************/
public class BpaSwi_TF
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
  private Double tF_TCH;
  
  //超高压缸功率比例
  private Double tF_FVHP;
  
  //第一再热器时间常数
  private Double tF_TRH1;
  
  //高压缸功率比例
  private Double tF_FHP;
  
  //第二再热器时间常数
  private Double tF_TRH2;
  
  //中压缸功率比例或比例一半
  private Double tF_FIP_1;
  
  //中压缸功率比例或比例一半
  private Double tF_FIP_2;
  
  //交叉管时间常数
  private Double tF_TCO;
  
  //低压缸功率比例或比例一半
  private Double tF_FLP_1;
  
  //低压缸功率比例或比例一半
  private Double tF_FLP_2;
  
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
    
  public Double getTF_TCH()
  {
    return tF_TCH;
  }
    
  public void setTF_TCH(Double tF_TCH)
  {
    this.tF_TCH = tF_TCH;
  }
    
  public Double getTF_FVHP()
  {
    return tF_FVHP;
  }
    
  public void setTF_FVHP(Double tF_FVHP)
  {
    this.tF_FVHP = tF_FVHP;
  }
    
  public Double getTF_TRH1()
  {
    return tF_TRH1;
  }
    
  public void setTF_TRH1(Double tF_TRH1)
  {
    this.tF_TRH1 = tF_TRH1;
  }
    
  public Double getTF_FHP()
  {
    return tF_FHP;
  }
    
  public void setTF_FHP(Double tF_FHP)
  {
    this.tF_FHP = tF_FHP;
  }
    
  public Double getTF_TRH2()
  {
    return tF_TRH2;
  }
    
  public void setTF_TRH2(Double tF_TRH2)
  {
    this.tF_TRH2 = tF_TRH2;
  }
    
  public Double getTF_FIP_1()
  {
    return tF_FIP_1;
  }
    
  public void setTF_FIP_1(Double tF_FIP_1)
  {
    this.tF_FIP_1 = tF_FIP_1;
  }
    
  public Double getTF_FIP_2()
  {
    return tF_FIP_2;
  }
    
  public void setTF_FIP_2(Double tF_FIP_2)
  {
    this.tF_FIP_2 = tF_FIP_2;
  }
    
  public Double getTF_TCO()
  {
    return tF_TCO;
  }
    
  public void setTF_TCO(Double tF_TCO)
  {
    this.tF_TCO = tF_TCO;
  }
    
  public Double getTF_FLP_1()
  {
    return tF_FLP_1;
  }
    
  public void setTF_FLP_1(Double tF_FLP_1)
  {
    this.tF_FLP_1 = tF_FLP_1;
  }
    
  public Double getTF_FLP_2()
  {
    return tF_FLP_2;
  }
    
  public void setTF_FLP_2(Double tF_FLP_2)
  {
    this.tF_FLP_2 = tF_FLP_2;
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
    return "BpaSwi_TF ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"aCBus_Name"=aCBus_Name,
	"aCBus_kV"=aCBus_kV,
	"gen_ID"=gen_ID,
	"tF_TCH"=tF_TCH,
	"tF_FVHP"=tF_FVHP,
	"tF_TRH1"=tF_TRH1,
	"tF_FHP"=tF_FHP,
	"tF_TRH2"=tF_TRH2,
	"tF_FIP_1"=tF_FIP_1,
	"tF_FIP_2"=tF_FIP_2,
	"tF_TCO"=tF_TCO,
	"tF_FLP_1"=tF_FLP_1,
	"tF_FLP_2"=tF_FLP_2,
	"keyName"=keyName,
	"busPtr"=busPtr,
	"appendTag"=appendTag+"]"
  }
    
}
    
