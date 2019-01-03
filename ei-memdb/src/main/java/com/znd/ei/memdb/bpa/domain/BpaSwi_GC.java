package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*调速器和原动机组合模型表(GC)	*
***********************/
public class BpaSwi_GC  implements MemIndexable 
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
  private Double GC_R;
  
  //控制时间
  private Double GC_T1;
  
  //水轮机恢复时间
  private Double GC_T2;
  
  //伺服机时间常数
  private Double GC_T3;
  
  //汽轮机阀时间常数
  private Double GC_T4;
  
  //汽轮机再热器时间常数
  private Double GC_T5;
  
  //再热器前轴容量/总的轴容量
  private Double GC_F;
  
  //转子阻尼的近似值
  private Double GC_DH;
  
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
    
  public Double getGC_R()
  {
    return GC_R;
  }
    
  public void setGC_R(Double GC_R)
  {
    this.GC_R = GC_R;
  }
    
  public Double getGC_T1()
  {
    return GC_T1;
  }
    
  public void setGC_T1(Double GC_T1)
  {
    this.GC_T1 = GC_T1;
  }
    
  public Double getGC_T2()
  {
    return GC_T2;
  }
    
  public void setGC_T2(Double GC_T2)
  {
    this.GC_T2 = GC_T2;
  }
    
  public Double getGC_T3()
  {
    return GC_T3;
  }
    
  public void setGC_T3(Double GC_T3)
  {
    this.GC_T3 = GC_T3;
  }
    
  public Double getGC_T4()
  {
    return GC_T4;
  }
    
  public void setGC_T4(Double GC_T4)
  {
    this.GC_T4 = GC_T4;
  }
    
  public Double getGC_T5()
  {
    return GC_T5;
  }
    
  public void setGC_T5(Double GC_T5)
  {
    this.GC_T5 = GC_T5;
  }
    
  public Double getGC_F()
  {
    return GC_F;
  }
    
  public void setGC_F(Double GC_F)
  {
    this.GC_F = GC_F;
  }
    
  public Double getGC_DH()
  {
    return GC_DH;
  }
    
  public void setGC_DH(Double GC_DH)
  {
    this.GC_DH = GC_DH;
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
    return "BpaSwi_GC ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", Gen_Pmax = " + Gen_Pmax
	 + ", GC_R = " + GC_R
	 + ", GC_T1 = " + GC_T1
	 + ", GC_T2 = " + GC_T2
	 + ", GC_T3 = " + GC_T3
	 + ", GC_T4 = " + GC_T4
	 + ", GC_T5 = " + GC_T5
	 + ", GC_F = " + GC_F
	 + ", GC_DH = " + GC_DH
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
