package com.znd.ei.memdb.bpa.domain;


/**********************
*汽轮机调速模型2表(GL)	*
***********************/
public class BpaSwi_GL
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
  
  //原动机额定输出功率(MW)
  private Double gL_Pe;
  
  //转速放大倍数(系统速度变动率的倒数)
  private Double gL_K;
  
  //系统迟缓率
  private Double gL_E;
  
  //调速器滑阀组时间常数
  private Double gL_Tr;
  
  //中间滑阀组时间常数
  private Double gL_Tb;
  
  //油动机开启时间常数	
  private Double gL_To;
  
  //油动机关闭时间常数
  private Double gL_Tc;
  
  //最大关闭速度,标么
  private Double gL_VELclose;
  
  //最大开启速度,标么
  private Double gL_VELopen;
  
  //最大原动机输出功率,标幺值
  private Double gen_Pmax;
  
  //最小原动机输出功率,标幺值
  private Double gen_Pmin;
  
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
    
  public Double getGL_Pe()
  {
    return gL_Pe;
  }
    
  public void setGL_Pe(Double gL_Pe)
  {
    this.gL_Pe = gL_Pe;
  }
    
  public Double getGL_K()
  {
    return gL_K;
  }
    
  public void setGL_K(Double gL_K)
  {
    this.gL_K = gL_K;
  }
    
  public Double getGL_E()
  {
    return gL_E;
  }
    
  public void setGL_E(Double gL_E)
  {
    this.gL_E = gL_E;
  }
    
  public Double getGL_Tr()
  {
    return gL_Tr;
  }
    
  public void setGL_Tr(Double gL_Tr)
  {
    this.gL_Tr = gL_Tr;
  }
    
  public Double getGL_Tb()
  {
    return gL_Tb;
  }
    
  public void setGL_Tb(Double gL_Tb)
  {
    this.gL_Tb = gL_Tb;
  }
    
  public Double getGL_To()
  {
    return gL_To;
  }
    
  public void setGL_To(Double gL_To)
  {
    this.gL_To = gL_To;
  }
    
  public Double getGL_Tc()
  {
    return gL_Tc;
  }
    
  public void setGL_Tc(Double gL_Tc)
  {
    this.gL_Tc = gL_Tc;
  }
    
  public Double getGL_VELclose()
  {
    return gL_VELclose;
  }
    
  public void setGL_VELclose(Double gL_VELclose)
  {
    this.gL_VELclose = gL_VELclose;
  }
    
  public Double getGL_VELopen()
  {
    return gL_VELopen;
  }
    
  public void setGL_VELopen(Double gL_VELopen)
  {
    this.gL_VELopen = gL_VELopen;
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
    return "BpaSwi_GL ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", gL_Pe = " + gL_Pe
	 + ", gL_K = " + gL_K
	 + ", gL_E = " + gL_E
	 + ", gL_Tr = " + gL_Tr
	 + ", gL_Tb = " + gL_Tb
	 + ", gL_To = " + gL_To
	 + ", gL_Tc = " + gL_Tc
	 + ", gL_VELclose = " + gL_VELclose
	 + ", gL_VELopen = " + gL_VELopen
	 + ", gen_Pmax = " + gen_Pmax
	 + ", gen_Pmin = " + gen_Pmin
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
