package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电网-发电机表	*
***********************/
public class BpaDat_Gen  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String Name;
  
  //母线名称
  private String Gen_Bus;
  
  //基准电压(kV)
  private Double Gen_kV;
  
  //电机识别码
  private Integer Gen_ID;
  
  //有功出力(MW)
  private Double Gen_PGen;
  
  //无功出力(MVar)
  private Double Gen_QGen;
  
  //最大有功出力(MW)
  private Double Gen_PMax;
  
  //最小有功出力(MW)
  private Double Gen_PMin;
  
  //最大无功出力(MVar)
  private Double Gen_QMax;
  
  //最小无功出力(MVar)
  private Double Gen_QMin;
  
  //安排的电压,PV值(pu)
  private Double Gen_VHold;
  
  //母线索引
  private Integer Gen_ACBusPtr;
  
  //风电机组
  private Integer Gen_WingGen;
  
  //等值电源
  private Integer Gen_EQ;
  
  //状态
  private Integer Gen_Status;
  
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
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public String getGen_Bus()
  {
    return Gen_Bus;
  }
    
  public void setGen_Bus(String Gen_Bus)
  {
    this.Gen_Bus = Gen_Bus;
  }
    
  public Double getGen_kV()
  {
    return Gen_kV;
  }
    
  public void setGen_kV(Double Gen_kV)
  {
    this.Gen_kV = Gen_kV;
  }
    
  public Integer getGen_ID()
  {
    return Gen_ID;
  }
    
  public void setGen_ID(Integer Gen_ID)
  {
    this.Gen_ID = Gen_ID;
  }
    
  public Double getGen_PGen()
  {
    return Gen_PGen;
  }
    
  public void setGen_PGen(Double Gen_PGen)
  {
    this.Gen_PGen = Gen_PGen;
  }
    
  public Double getGen_QGen()
  {
    return Gen_QGen;
  }
    
  public void setGen_QGen(Double Gen_QGen)
  {
    this.Gen_QGen = Gen_QGen;
  }
    
  public Double getGen_PMax()
  {
    return Gen_PMax;
  }
    
  public void setGen_PMax(Double Gen_PMax)
  {
    this.Gen_PMax = Gen_PMax;
  }
    
  public Double getGen_PMin()
  {
    return Gen_PMin;
  }
    
  public void setGen_PMin(Double Gen_PMin)
  {
    this.Gen_PMin = Gen_PMin;
  }
    
  public Double getGen_QMax()
  {
    return Gen_QMax;
  }
    
  public void setGen_QMax(Double Gen_QMax)
  {
    this.Gen_QMax = Gen_QMax;
  }
    
  public Double getGen_QMin()
  {
    return Gen_QMin;
  }
    
  public void setGen_QMin(Double Gen_QMin)
  {
    this.Gen_QMin = Gen_QMin;
  }
    
  public Double getGen_VHold()
  {
    return Gen_VHold;
  }
    
  public void setGen_VHold(Double Gen_VHold)
  {
    this.Gen_VHold = Gen_VHold;
  }
    
  public Integer getGen_ACBusPtr()
  {
    return Gen_ACBusPtr;
  }
    
  public void setGen_ACBusPtr(Integer Gen_ACBusPtr)
  {
    this.Gen_ACBusPtr = Gen_ACBusPtr;
  }
    
  public Integer getGen_WingGen()
  {
    return Gen_WingGen;
  }
    
  public void setGen_WingGen(Integer Gen_WingGen)
  {
    this.Gen_WingGen = Gen_WingGen;
  }
    
  public Integer getGen_EQ()
  {
    return Gen_EQ;
  }
    
  public void setGen_EQ(Integer Gen_EQ)
  {
    this.Gen_EQ = Gen_EQ;
  }
    
  public Integer getGen_Status()
  {
    return Gen_Status;
  }
    
  public void setGen_Status(Integer Gen_Status)
  {
    this.Gen_Status = Gen_Status;
  }
    
  public String toString()
  {
    return "BpaDat_Gen ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", Gen_Bus = " + Gen_Bus
	 + ", Gen_kV = " + Gen_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", Gen_PGen = " + Gen_PGen
	 + ", Gen_QGen = " + Gen_QGen
	 + ", Gen_PMax = " + Gen_PMax
	 + ", Gen_PMin = " + Gen_PMin
	 + ", Gen_QMax = " + Gen_QMax
	 + ", Gen_QMin = " + Gen_QMin
	 + ", Gen_VHold = " + Gen_VHold
	 + ", Gen_ACBusPtr = " + Gen_ACBusPtr
	 + ", Gen_WingGen = " + Gen_WingGen
	 + ", Gen_EQ = " + Gen_EQ
	 + ", Gen_Status = " + Gen_Status+"]";
  }
    
}
    
