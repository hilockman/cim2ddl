package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*水轮机调速器和原动机模型表(GH)	*
***********************/
public class BpaSwi_GH  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //发电机名称
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //原动机最大输出功率(MW)
  private Double Gen_Pmax;
  
  //调差系数
  private Double GH_R;
  
  //调速器响应时间
  private Double GH_TG;
  
  //引导阀门时间常数
  private Double GH_TP;
  
  //软反馈时间常数
  private Double GH_Td;
  
  //水锤效应时间常数
  private Double GH_Tw_Half;
  
  //最大水门关闭速度,每秒标么
  private Double GH_VELclose;
  
  //最大水门开启速度,每秒标么
  private Double GH_VELopen;
  
  //软反馈环节系数
  private Double GH_Dd;
  
  //死区,为相对于系统频率的标么值
  private Double GH_E;
  
  //数据库主键
  private String KeyName;
  
  //发电机母线索引
  private Integer BusPtr;
  
  //新增记录标记
  private Integer AppendTag;
  
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
    return CardKey;
  }
    
  public void setCardKey(String CardKey)
  {
    this.CardKey = CardKey;
  }
    
  public String getACBus_Name()
  {
    return ACBus_Name;
  }
    
  public void setACBus_Name(String ACBus_Name)
  {
    this.ACBus_Name = ACBus_Name;
  }
    
  public Double getACBus_kV()
  {
    return ACBus_kV;
  }
    
  public void setACBus_kV(Double ACBus_kV)
  {
    this.ACBus_kV = ACBus_kV;
  }
    
  public Integer getGen_ID()
  {
    return Gen_ID;
  }
    
  public void setGen_ID(Integer Gen_ID)
  {
    this.Gen_ID = Gen_ID;
  }
    
  public Double getGen_Pmax()
  {
    return Gen_Pmax;
  }
    
  public void setGen_Pmax(Double Gen_Pmax)
  {
    this.Gen_Pmax = Gen_Pmax;
  }
    
  public Double getGH_R()
  {
    return GH_R;
  }
    
  public void setGH_R(Double GH_R)
  {
    this.GH_R = GH_R;
  }
    
  public Double getGH_TG()
  {
    return GH_TG;
  }
    
  public void setGH_TG(Double GH_TG)
  {
    this.GH_TG = GH_TG;
  }
    
  public Double getGH_TP()
  {
    return GH_TP;
  }
    
  public void setGH_TP(Double GH_TP)
  {
    this.GH_TP = GH_TP;
  }
    
  public Double getGH_Td()
  {
    return GH_Td;
  }
    
  public void setGH_Td(Double GH_Td)
  {
    this.GH_Td = GH_Td;
  }
    
  public Double getGH_Tw_Half()
  {
    return GH_Tw_Half;
  }
    
  public void setGH_Tw_Half(Double GH_Tw_Half)
  {
    this.GH_Tw_Half = GH_Tw_Half;
  }
    
  public Double getGH_VELclose()
  {
    return GH_VELclose;
  }
    
  public void setGH_VELclose(Double GH_VELclose)
  {
    this.GH_VELclose = GH_VELclose;
  }
    
  public Double getGH_VELopen()
  {
    return GH_VELopen;
  }
    
  public void setGH_VELopen(Double GH_VELopen)
  {
    this.GH_VELopen = GH_VELopen;
  }
    
  public Double getGH_Dd()
  {
    return GH_Dd;
  }
    
  public void setGH_Dd(Double GH_Dd)
  {
    this.GH_Dd = GH_Dd;
  }
    
  public Double getGH_E()
  {
    return GH_E;
  }
    
  public void setGH_E(Double GH_E)
  {
    this.GH_E = GH_E;
  }
    
  public String getKeyName()
  {
    return KeyName;
  }
    
  public void setKeyName(String KeyName)
  {
    this.KeyName = KeyName;
  }
    
  public Integer getBusPtr()
  {
    return BusPtr;
  }
    
  public void setBusPtr(Integer BusPtr)
  {
    this.BusPtr = BusPtr;
  }
    
  public Integer getAppendTag()
  {
    return AppendTag;
  }
    
  public void setAppendTag(Integer AppendTag)
  {
    this.AppendTag = AppendTag;
  }
    
  public String toString()
  {
    return "BpaSwi_GH ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", Gen_Pmax = " + Gen_Pmax
	 + ", GH_R = " + GH_R
	 + ", GH_TG = " + GH_TG
	 + ", GH_TP = " + GH_TP
	 + ", GH_Td = " + GH_Td
	 + ", GH_Tw_Half = " + GH_Tw_Half
	 + ", GH_VELclose = " + GH_VELclose
	 + ", GH_VELopen = " + GH_VELopen
	 + ", GH_Dd = " + GH_Dd
	 + ", GH_E = " + GH_E
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
