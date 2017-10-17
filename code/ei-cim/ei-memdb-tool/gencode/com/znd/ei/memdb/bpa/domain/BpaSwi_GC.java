package com.znd.ei.memdb.bpa.domain;


/**********************
*调速器和原动机组合模型表(GC)	*
***********************/
public class BpaSwi_GC
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
  private Double gC_R;
  
  //控制时间
  private Double gC_T1;
  
  //水轮机恢复时间
  private Double gC_T2;
  
  //伺服机时间常数
  private Double gC_T3;
  
  //汽轮机阀时间常数
  private Double gC_T4;
  
  //汽轮机再热器时间常数
  private Double gC_T5;
  
  //再热器前轴容量/总的轴容量
  private Double gC_F;
  
  //转子阻尼的近似值
  private Double gC_DH;
  
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
    
  public Double getGC_R()
  {
    return gC_R;
  }
    
  public void setGC_R(Double gC_R)
  {
    this.gC_R = gC_R;
  }
    
  public Double getGC_T1()
  {
    return gC_T1;
  }
    
  public void setGC_T1(Double gC_T1)
  {
    this.gC_T1 = gC_T1;
  }
    
  public Double getGC_T2()
  {
    return gC_T2;
  }
    
  public void setGC_T2(Double gC_T2)
  {
    this.gC_T2 = gC_T2;
  }
    
  public Double getGC_T3()
  {
    return gC_T3;
  }
    
  public void setGC_T3(Double gC_T3)
  {
    this.gC_T3 = gC_T3;
  }
    
  public Double getGC_T4()
  {
    return gC_T4;
  }
    
  public void setGC_T4(Double gC_T4)
  {
    this.gC_T4 = gC_T4;
  }
    
  public Double getGC_T5()
  {
    return gC_T5;
  }
    
  public void setGC_T5(Double gC_T5)
  {
    this.gC_T5 = gC_T5;
  }
    
  public Double getGC_F()
  {
    return gC_F;
  }
    
  public void setGC_F(Double gC_F)
  {
    this.gC_F = gC_F;
  }
    
  public Double getGC_DH()
  {
    return gC_DH;
  }
    
  public void setGC_DH(Double gC_DH)
  {
    this.gC_DH = gC_DH;
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
    return "BpaSwi_GC ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"aCBus_Name"=aCBus_Name,
	"aCBus_kV"=aCBus_kV,
	"gen_ID"=gen_ID,
	"gen_Pmax"=gen_Pmax,
	"gC_R"=gC_R,
	"gC_T1"=gC_T1,
	"gC_T2"=gC_T2,
	"gC_T3"=gC_T3,
	"gC_T4"=gC_T4,
	"gC_T5"=gC_T5,
	"gC_F"=gC_F,
	"gC_DH"=gC_DH,
	"keyName"=keyName,
	"busPtr"=busPtr,
	"appendTag"=appendTag+"]"
  }
    
}
    
