package com.znd.ei.memdb.bpa.domain;


/**********************
*电网-发电机表	*
***********************/
public class BpaDat_Gen
{
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String name;
  
  //母线名称
  private String gen_Bus;
  
  //基准电压(kV)
  private Double gen_kV;
  
  //电机识别码
  private Integer gen_ID;
  
  //有功出力(MW)
  private Double gen_PGen;
  
  //无功出力(MVar)
  private Double gen_QGen;
  
  //最大有功出力(MW)
  private Double gen_PMax;
  
  //最小有功出力(MW)
  private Double gen_PMin;
  
  //最大无功出力(MVar)
  private Double gen_QMax;
  
  //最小无功出力(MVar)
  private Double gen_QMin;
  
  //安排的电压,PV值(pu)
  private Double gen_VHold;
  
  //母线索引
  private Integer gen_ACBusPtr;
  
  //风电机组
  private Integer gen_WingGen;
  
  //等值电源
  private Integer gen_EQ;
  
  //状态
  private Integer gen_Status;
  
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
    return name;
  }
    
  public void setName(String name)
  {
    this.name = name;
  }
    
  public String getGen_Bus()
  {
    return gen_Bus;
  }
    
  public void setGen_Bus(String gen_Bus)
  {
    this.gen_Bus = gen_Bus;
  }
    
  public Double getGen_kV()
  {
    return gen_kV;
  }
    
  public void setGen_kV(Double gen_kV)
  {
    this.gen_kV = gen_kV;
  }
    
  public Integer getGen_ID()
  {
    return gen_ID;
  }
    
  public void setGen_ID(Integer gen_ID)
  {
    this.gen_ID = gen_ID;
  }
    
  public Double getGen_PGen()
  {
    return gen_PGen;
  }
    
  public void setGen_PGen(Double gen_PGen)
  {
    this.gen_PGen = gen_PGen;
  }
    
  public Double getGen_QGen()
  {
    return gen_QGen;
  }
    
  public void setGen_QGen(Double gen_QGen)
  {
    this.gen_QGen = gen_QGen;
  }
    
  public Double getGen_PMax()
  {
    return gen_PMax;
  }
    
  public void setGen_PMax(Double gen_PMax)
  {
    this.gen_PMax = gen_PMax;
  }
    
  public Double getGen_PMin()
  {
    return gen_PMin;
  }
    
  public void setGen_PMin(Double gen_PMin)
  {
    this.gen_PMin = gen_PMin;
  }
    
  public Double getGen_QMax()
  {
    return gen_QMax;
  }
    
  public void setGen_QMax(Double gen_QMax)
  {
    this.gen_QMax = gen_QMax;
  }
    
  public Double getGen_QMin()
  {
    return gen_QMin;
  }
    
  public void setGen_QMin(Double gen_QMin)
  {
    this.gen_QMin = gen_QMin;
  }
    
  public Double getGen_VHold()
  {
    return gen_VHold;
  }
    
  public void setGen_VHold(Double gen_VHold)
  {
    this.gen_VHold = gen_VHold;
  }
    
  public Integer getGen_ACBusPtr()
  {
    return gen_ACBusPtr;
  }
    
  public void setGen_ACBusPtr(Integer gen_ACBusPtr)
  {
    this.gen_ACBusPtr = gen_ACBusPtr;
  }
    
  public Integer getGen_WingGen()
  {
    return gen_WingGen;
  }
    
  public void setGen_WingGen(Integer gen_WingGen)
  {
    this.gen_WingGen = gen_WingGen;
  }
    
  public Integer getGen_EQ()
  {
    return gen_EQ;
  }
    
  public void setGen_EQ(Integer gen_EQ)
  {
    this.gen_EQ = gen_EQ;
  }
    
  public Integer getGen_Status()
  {
    return gen_Status;
  }
    
  public void setGen_Status(Integer gen_Status)
  {
    this.gen_Status = gen_Status;
  }
    
  public String toString()
  {
    return "BpaDat_Gen ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", name = " + name
	 + ", gen_Bus = " + gen_Bus
	 + ", gen_kV = " + gen_kV
	 + ", gen_ID = " + gen_ID
	 + ", gen_PGen = " + gen_PGen
	 + ", gen_QGen = " + gen_QGen
	 + ", gen_PMax = " + gen_PMax
	 + ", gen_PMin = " + gen_PMin
	 + ", gen_QMax = " + gen_QMax
	 + ", gen_QMin = " + gen_QMin
	 + ", gen_VHold = " + gen_VHold
	 + ", gen_ACBusPtr = " + gen_ACBusPtr
	 + ", gen_WingGen = " + gen_WingGen
	 + ", gen_EQ = " + gen_EQ
	 + ", gen_Status = " + gen_Status+"]";
  }
    
}
    
