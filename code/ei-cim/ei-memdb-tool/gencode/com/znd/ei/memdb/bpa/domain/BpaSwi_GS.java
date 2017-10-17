package com.znd.ei.memdb.bpa.domain;


/**********************
*汽轮机调速模型1表(GS)	*
***********************/
public class BpaSwi_GS
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
  
  //原动机最小输出功率(MW)
  private Double gen_Pmin;
  
  //调差系数
  private Double gS_R;
  
  //控制时间
  private Double gS_T1;
  
  //一般为零
  private Double gS_T2;
  
  //伺服机时间常数
  private Double gS_T3;
  
  //最大的汽门开启速度(每秒标么),必为正数
  private Double gS_VELopen;
  
  //最大的汽门关闭速度(每秒标么),必为正数
  private Double gS_VELclose;
  
  //死区,为相对于系统频率的标么值
  private Double gS_E;
  
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
    
  public Double getGen_Pmin()
  {
    return gen_Pmin;
  }
    
  public void setGen_Pmin(Double gen_Pmin)
  {
    this.gen_Pmin = gen_Pmin;
  }
    
  public Double getGS_R()
  {
    return gS_R;
  }
    
  public void setGS_R(Double gS_R)
  {
    this.gS_R = gS_R;
  }
    
  public Double getGS_T1()
  {
    return gS_T1;
  }
    
  public void setGS_T1(Double gS_T1)
  {
    this.gS_T1 = gS_T1;
  }
    
  public Double getGS_T2()
  {
    return gS_T2;
  }
    
  public void setGS_T2(Double gS_T2)
  {
    this.gS_T2 = gS_T2;
  }
    
  public Double getGS_T3()
  {
    return gS_T3;
  }
    
  public void setGS_T3(Double gS_T3)
  {
    this.gS_T3 = gS_T3;
  }
    
  public Double getGS_VELopen()
  {
    return gS_VELopen;
  }
    
  public void setGS_VELopen(Double gS_VELopen)
  {
    this.gS_VELopen = gS_VELopen;
  }
    
  public Double getGS_VELclose()
  {
    return gS_VELclose;
  }
    
  public void setGS_VELclose(Double gS_VELclose)
  {
    this.gS_VELclose = gS_VELclose;
  }
    
  public Double getGS_E()
  {
    return gS_E;
  }
    
  public void setGS_E(Double gS_E)
  {
    this.gS_E = gS_E;
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
    return "BpaSwi_GS ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"aCBus_Name"=aCBus_Name,
	"aCBus_kV"=aCBus_kV,
	"gen_ID"=gen_ID,
	"gen_Pmax"=gen_Pmax,
	"gen_Pmin"=gen_Pmin,
	"gS_R"=gS_R,
	"gS_T1"=gS_T1,
	"gS_T2"=gS_T2,
	"gS_T3"=gS_T3,
	"gS_VELopen"=gS_VELopen,
	"gS_VELclose"=gS_VELclose,
	"gS_E"=gS_E,
	"keyName"=keyName,
	"busPtr"=busPtr,
	"appendTag"=appendTag+"]"
  }
    
}
    
