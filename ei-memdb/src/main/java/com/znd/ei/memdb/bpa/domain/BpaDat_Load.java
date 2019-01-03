package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电网-负荷表	*
***********************/
public class BpaDat_Load  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String Name;
  
  //母线名称
  private String Load_Bus;
  
  //基准电压(kV)
  private Double Load_kV;
  
  //有功出力(MW)
  private Double Load_PLoad;
  
  //无功出力(MVar)
  private Double Load_QLoad;
  
  //母线索引
  private Integer Load_ACBusPtr;
  
  //厂用电
  private Integer Load_Aux;
  
  //等值负荷
  private Integer Load_EQ;
  
  //状态
  private Integer Load_Status;
  
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
    
  public String getLoad_Bus()
  {
    return Load_Bus;
  }
    
  public void setLoad_Bus(String Load_Bus)
  {
    this.Load_Bus = Load_Bus;
  }
    
  public Double getLoad_kV()
  {
    return Load_kV;
  }
    
  public void setLoad_kV(Double Load_kV)
  {
    this.Load_kV = Load_kV;
  }
    
  public Double getLoad_PLoad()
  {
    return Load_PLoad;
  }
    
  public void setLoad_PLoad(Double Load_PLoad)
  {
    this.Load_PLoad = Load_PLoad;
  }
    
  public Double getLoad_QLoad()
  {
    return Load_QLoad;
  }
    
  public void setLoad_QLoad(Double Load_QLoad)
  {
    this.Load_QLoad = Load_QLoad;
  }
    
  public Integer getLoad_ACBusPtr()
  {
    return Load_ACBusPtr;
  }
    
  public void setLoad_ACBusPtr(Integer Load_ACBusPtr)
  {
    this.Load_ACBusPtr = Load_ACBusPtr;
  }
    
  public Integer getLoad_Aux()
  {
    return Load_Aux;
  }
    
  public void setLoad_Aux(Integer Load_Aux)
  {
    this.Load_Aux = Load_Aux;
  }
    
  public Integer getLoad_EQ()
  {
    return Load_EQ;
  }
    
  public void setLoad_EQ(Integer Load_EQ)
  {
    this.Load_EQ = Load_EQ;
  }
    
  public Integer getLoad_Status()
  {
    return Load_Status;
  }
    
  public void setLoad_Status(Integer Load_Status)
  {
    this.Load_Status = Load_Status;
  }
    
  public String toString()
  {
    return "BpaDat_Load ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", Load_Bus = " + Load_Bus
	 + ", Load_kV = " + Load_kV
	 + ", Load_PLoad = " + Load_PLoad
	 + ", Load_QLoad = " + Load_QLoad
	 + ", Load_ACBusPtr = " + Load_ACBusPtr
	 + ", Load_Aux = " + Load_Aux
	 + ", Load_EQ = " + Load_EQ
	 + ", Load_Status = " + Load_Status+"]";
  }
    
}
    
