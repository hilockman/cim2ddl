package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*汽轮机调速模型2表(GL)	*
***********************/
public class BpaSwi_GL  implements MemIndexable 
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
  
  //原动机额定输出功率(MW)
  private Double GL_Pe;
  
  //转速放大倍数(系统速度变动率的倒数)
  private Double GL_K;
  
  //系统迟缓率
  private Double GL_E;
  
  //调速器滑阀组时间常数
  private Double GL_Tr;
  
  //中间滑阀组时间常数
  private Double GL_Tb;
  
  //油动机开启时间常数	
  private Double GL_To;
  
  //油动机关闭时间常数
  private Double GL_Tc;
  
  //最大关闭速度,标么
  private Double GL_VELclose;
  
  //最大开启速度,标么
  private Double GL_VELopen;
  
  //最大原动机输出功率,标幺值
  private Double Gen_Pmax;
  
  //最小原动机输出功率,标幺值
  private Double Gen_Pmin;
  
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
    
  public Double getGL_Pe()
  {
    return GL_Pe;
  }
    
  public void setGL_Pe(Double GL_Pe)
  {
    this.GL_Pe = GL_Pe;
  }
    
  public Double getGL_K()
  {
    return GL_K;
  }
    
  public void setGL_K(Double GL_K)
  {
    this.GL_K = GL_K;
  }
    
  public Double getGL_E()
  {
    return GL_E;
  }
    
  public void setGL_E(Double GL_E)
  {
    this.GL_E = GL_E;
  }
    
  public Double getGL_Tr()
  {
    return GL_Tr;
  }
    
  public void setGL_Tr(Double GL_Tr)
  {
    this.GL_Tr = GL_Tr;
  }
    
  public Double getGL_Tb()
  {
    return GL_Tb;
  }
    
  public void setGL_Tb(Double GL_Tb)
  {
    this.GL_Tb = GL_Tb;
  }
    
  public Double getGL_To()
  {
    return GL_To;
  }
    
  public void setGL_To(Double GL_To)
  {
    this.GL_To = GL_To;
  }
    
  public Double getGL_Tc()
  {
    return GL_Tc;
  }
    
  public void setGL_Tc(Double GL_Tc)
  {
    this.GL_Tc = GL_Tc;
  }
    
  public Double getGL_VELclose()
  {
    return GL_VELclose;
  }
    
  public void setGL_VELclose(Double GL_VELclose)
  {
    this.GL_VELclose = GL_VELclose;
  }
    
  public Double getGL_VELopen()
  {
    return GL_VELopen;
  }
    
  public void setGL_VELopen(Double GL_VELopen)
  {
    this.GL_VELopen = GL_VELopen;
  }
    
  public Double getGen_Pmax()
  {
    return Gen_Pmax;
  }
    
  public void setGen_Pmax(Double Gen_Pmax)
  {
    this.Gen_Pmax = Gen_Pmax;
  }
    
  public Double getGen_Pmin()
  {
    return Gen_Pmin;
  }
    
  public void setGen_Pmin(Double Gen_Pmin)
  {
    this.Gen_Pmin = Gen_Pmin;
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
    return "BpaSwi_GL ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", GL_Pe = " + GL_Pe
	 + ", GL_K = " + GL_K
	 + ", GL_E = " + GL_E
	 + ", GL_Tr = " + GL_Tr
	 + ", GL_Tb = " + GL_Tb
	 + ", GL_To = " + GL_To
	 + ", GL_Tc = " + GL_Tc
	 + ", GL_VELclose = " + GL_VELclose
	 + ", GL_VELopen = " + GL_VELopen
	 + ", Gen_Pmax = " + Gen_Pmax
	 + ", Gen_Pmin = " + Gen_Pmin
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
