package com.znd.ei.memdb.bpa.domain;


/**********************
*修改调速器频率参考信息表(IGV)	*
***********************/
public class BpaSwi_IGV
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
  
  //频率变化的起始时刻(周)
  private Double iGV_Tstart;
  
  //第1个点对应的时刻(周)
  private Double iGV_T1;
  
  //第1个点对应的频率变化量(Hz)
  private Double iGV_FREQ1;
  
  //第2个点对应的时刻(周)
  private Double iGV_T2;
  
  //第2个点对应的频率变化量(Hz)
  private Double iGV_FREQ2;
  
  //第3个点对应的时刻(周)
  private Double iGV_T3;
  
  //第3个点对应的频率变化量(Hz)
  private Double iGV_FREQ3;
  
  //第4个点对应的时刻(周)
  private Double iGV_T4;
  
  //第4个点对应的频率变化量(Hz)
  private Double iGV_FREQ4;
  
  //第5个点对应的时刻(周)
  private Double iGV_T5;
  
  //第5个点对应的频率变化量(Hz)
  private Double iGV_FREQ5;
  
  //第6个点对应的时刻(周)
  private Double iGV_T6;
  
  //第6个点对应的频率变化量(Hz)
  private Double iGV_FREQ6;
  
  //第7个点对应的时刻(周)
  private Double iGV_T7;
  
  //第7个点对应的频率变化量(Hz)
  private Double iGV_FREQ7;
  
  //第8个点对应的时刻(周)
  private Double iGV_T8;
  
  //第8个点对应的频率变化量(Hz)
  private Double iGV_FREQ8;
  
  //第9个点对应的时刻(周)
  private Double iGV_T9;
  
  //第9个点对应的频率变化量(Hz)
  private Double iGV_FREQ9;
  
  //第10个点对应的时刻(周)
  private Double iGV_T10;
  
  //第10个点对应的频率变化量(Hz)
  private Double iGV_FREQ10;
  
  //第11个点对应的时刻(周)
  private Double iGV_T11;
  
  //第11个点对应的频率变化量(Hz)
  private Double iGV_FREQ11;
  
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
    
  public Double getIGV_Tstart()
  {
    return iGV_Tstart;
  }
    
  public void setIGV_Tstart(Double iGV_Tstart)
  {
    this.iGV_Tstart = iGV_Tstart;
  }
    
  public Double getIGV_T1()
  {
    return iGV_T1;
  }
    
  public void setIGV_T1(Double iGV_T1)
  {
    this.iGV_T1 = iGV_T1;
  }
    
  public Double getIGV_FREQ1()
  {
    return iGV_FREQ1;
  }
    
  public void setIGV_FREQ1(Double iGV_FREQ1)
  {
    this.iGV_FREQ1 = iGV_FREQ1;
  }
    
  public Double getIGV_T2()
  {
    return iGV_T2;
  }
    
  public void setIGV_T2(Double iGV_T2)
  {
    this.iGV_T2 = iGV_T2;
  }
    
  public Double getIGV_FREQ2()
  {
    return iGV_FREQ2;
  }
    
  public void setIGV_FREQ2(Double iGV_FREQ2)
  {
    this.iGV_FREQ2 = iGV_FREQ2;
  }
    
  public Double getIGV_T3()
  {
    return iGV_T3;
  }
    
  public void setIGV_T3(Double iGV_T3)
  {
    this.iGV_T3 = iGV_T3;
  }
    
  public Double getIGV_FREQ3()
  {
    return iGV_FREQ3;
  }
    
  public void setIGV_FREQ3(Double iGV_FREQ3)
  {
    this.iGV_FREQ3 = iGV_FREQ3;
  }
    
  public Double getIGV_T4()
  {
    return iGV_T4;
  }
    
  public void setIGV_T4(Double iGV_T4)
  {
    this.iGV_T4 = iGV_T4;
  }
    
  public Double getIGV_FREQ4()
  {
    return iGV_FREQ4;
  }
    
  public void setIGV_FREQ4(Double iGV_FREQ4)
  {
    this.iGV_FREQ4 = iGV_FREQ4;
  }
    
  public Double getIGV_T5()
  {
    return iGV_T5;
  }
    
  public void setIGV_T5(Double iGV_T5)
  {
    this.iGV_T5 = iGV_T5;
  }
    
  public Double getIGV_FREQ5()
  {
    return iGV_FREQ5;
  }
    
  public void setIGV_FREQ5(Double iGV_FREQ5)
  {
    this.iGV_FREQ5 = iGV_FREQ5;
  }
    
  public Double getIGV_T6()
  {
    return iGV_T6;
  }
    
  public void setIGV_T6(Double iGV_T6)
  {
    this.iGV_T6 = iGV_T6;
  }
    
  public Double getIGV_FREQ6()
  {
    return iGV_FREQ6;
  }
    
  public void setIGV_FREQ6(Double iGV_FREQ6)
  {
    this.iGV_FREQ6 = iGV_FREQ6;
  }
    
  public Double getIGV_T7()
  {
    return iGV_T7;
  }
    
  public void setIGV_T7(Double iGV_T7)
  {
    this.iGV_T7 = iGV_T7;
  }
    
  public Double getIGV_FREQ7()
  {
    return iGV_FREQ7;
  }
    
  public void setIGV_FREQ7(Double iGV_FREQ7)
  {
    this.iGV_FREQ7 = iGV_FREQ7;
  }
    
  public Double getIGV_T8()
  {
    return iGV_T8;
  }
    
  public void setIGV_T8(Double iGV_T8)
  {
    this.iGV_T8 = iGV_T8;
  }
    
  public Double getIGV_FREQ8()
  {
    return iGV_FREQ8;
  }
    
  public void setIGV_FREQ8(Double iGV_FREQ8)
  {
    this.iGV_FREQ8 = iGV_FREQ8;
  }
    
  public Double getIGV_T9()
  {
    return iGV_T9;
  }
    
  public void setIGV_T9(Double iGV_T9)
  {
    this.iGV_T9 = iGV_T9;
  }
    
  public Double getIGV_FREQ9()
  {
    return iGV_FREQ9;
  }
    
  public void setIGV_FREQ9(Double iGV_FREQ9)
  {
    this.iGV_FREQ9 = iGV_FREQ9;
  }
    
  public Double getIGV_T10()
  {
    return iGV_T10;
  }
    
  public void setIGV_T10(Double iGV_T10)
  {
    this.iGV_T10 = iGV_T10;
  }
    
  public Double getIGV_FREQ10()
  {
    return iGV_FREQ10;
  }
    
  public void setIGV_FREQ10(Double iGV_FREQ10)
  {
    this.iGV_FREQ10 = iGV_FREQ10;
  }
    
  public Double getIGV_T11()
  {
    return iGV_T11;
  }
    
  public void setIGV_T11(Double iGV_T11)
  {
    this.iGV_T11 = iGV_T11;
  }
    
  public Double getIGV_FREQ11()
  {
    return iGV_FREQ11;
  }
    
  public void setIGV_FREQ11(Double iGV_FREQ11)
  {
    this.iGV_FREQ11 = iGV_FREQ11;
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
    return "BpaSwi_IGV ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"aCBus_Name"=aCBus_Name,
	"aCBus_KV"=aCBus_KV,
	"gen_ID"=gen_ID,
	"iGV_Tstart"=iGV_Tstart,
	"iGV_T1"=iGV_T1,
	"iGV_FREQ1"=iGV_FREQ1,
	"iGV_T2"=iGV_T2,
	"iGV_FREQ2"=iGV_FREQ2,
	"iGV_T3"=iGV_T3,
	"iGV_FREQ3"=iGV_FREQ3,
	"iGV_T4"=iGV_T4,
	"iGV_FREQ4"=iGV_FREQ4,
	"iGV_T5"=iGV_T5,
	"iGV_FREQ5"=iGV_FREQ5,
	"iGV_T6"=iGV_T6,
	"iGV_FREQ6"=iGV_FREQ6,
	"iGV_T7"=iGV_T7,
	"iGV_FREQ7"=iGV_FREQ7,
	"iGV_T8"=iGV_T8,
	"iGV_FREQ8"=iGV_FREQ8,
	"iGV_T9"=iGV_T9,
	"iGV_FREQ9"=iGV_FREQ9,
	"iGV_T10"=iGV_T10,
	"iGV_FREQ10"=iGV_FREQ10,
	"iGV_T11"=iGV_T11,
	"iGV_FREQ11"=iGV_FREQ11,
	"keyName"=keyName,
	"busPtr"=busPtr+"]"
  }
    
}
    
