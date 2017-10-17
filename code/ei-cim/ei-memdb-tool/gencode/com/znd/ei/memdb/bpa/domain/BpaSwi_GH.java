package com.znd.ei.memdb.bpa.domain;


/**********************
*水轮机调速器和原动机模型表(GH)	*
***********************/
public class BpaSwi_GH
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
  private Double gH_R;
  
  //调速器响应时间
  private Double gH_TG;
  
  //引导阀门时间常数
  private Double gH_TP;
  
  //软反馈时间常数
  private Double gH_Td;
  
  //水锤效应时间常数
  private Double gH_Tw_Half;
  
  //最大水门关闭速度,每秒标么
  private Double gH_VELclose;
  
  //最大水门开启速度,每秒标么
  private Double gH_VELopen;
  
  //软反馈环节系数
  private Double gH_Dd;
  
  //死区,为相对于系统频率的标么值
  private Double gH_E;
  
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
    
  public Double getGH_R()
  {
    return gH_R;
  }
    
  public void setGH_R(Double gH_R)
  {
    this.gH_R = gH_R;
  }
    
  public Double getGH_TG()
  {
    return gH_TG;
  }
    
  public void setGH_TG(Double gH_TG)
  {
    this.gH_TG = gH_TG;
  }
    
  public Double getGH_TP()
  {
    return gH_TP;
  }
    
  public void setGH_TP(Double gH_TP)
  {
    this.gH_TP = gH_TP;
  }
    
  public Double getGH_Td()
  {
    return gH_Td;
  }
    
  public void setGH_Td(Double gH_Td)
  {
    this.gH_Td = gH_Td;
  }
    
  public Double getGH_Tw_Half()
  {
    return gH_Tw_Half;
  }
    
  public void setGH_Tw_Half(Double gH_Tw_Half)
  {
    this.gH_Tw_Half = gH_Tw_Half;
  }
    
  public Double getGH_VELclose()
  {
    return gH_VELclose;
  }
    
  public void setGH_VELclose(Double gH_VELclose)
  {
    this.gH_VELclose = gH_VELclose;
  }
    
  public Double getGH_VELopen()
  {
    return gH_VELopen;
  }
    
  public void setGH_VELopen(Double gH_VELopen)
  {
    this.gH_VELopen = gH_VELopen;
  }
    
  public Double getGH_Dd()
  {
    return gH_Dd;
  }
    
  public void setGH_Dd(Double gH_Dd)
  {
    this.gH_Dd = gH_Dd;
  }
    
  public Double getGH_E()
  {
    return gH_E;
  }
    
  public void setGH_E(Double gH_E)
  {
    this.gH_E = gH_E;
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
    return "BpaSwi_GH ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", gen_Pmax = " + gen_Pmax
	 + ", gH_R = " + gH_R
	 + ", gH_TG = " + gH_TG
	 + ", gH_TP = " + gH_TP
	 + ", gH_Td = " + gH_Td
	 + ", gH_Tw_Half = " + gH_Tw_Half
	 + ", gH_VELclose = " + gH_VELclose
	 + ", gH_VELopen = " + gH_VELopen
	 + ", gH_Dd = " + gH_Dd
	 + ", gH_E = " + gH_E
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
