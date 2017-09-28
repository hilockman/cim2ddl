package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*电网-负荷表	*
***********************/
@Entity
public class BpaDat_Load
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String name;
  
  //母线名称
  private String load_Bus;
  
  //基准电压(kV)
  private Double load_kV;
  
  //有功出力(MW)
  private Double load_PLoad;
  
  //无功出力(MVar)
  private Double load_QLoad;
  
  //母线索引
  private Integer load_ACBusPtr;
  
  //厂用电
  private Integer load_Aux;
  
  //等值负荷
  private Integer load_EQ;
  
  //状态
  private Integer load_Status;
  
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
    
  public String getLoad_Bus() 
  {
    return load_Bus;
  }
    
  public void setLoad_Bus(String load_Bus)
  {
    this.load_Bus = load_Bus;
  }
    
  public Double getLoad_kV() 
  {
    return load_kV;
  }
    
  public void setLoad_kV(Double load_kV)
  {
    this.load_kV = load_kV;
  }
    
  public Double getLoad_PLoad() 
  {
    return load_PLoad;
  }
    
  public void setLoad_PLoad(Double load_PLoad)
  {
    this.load_PLoad = load_PLoad;
  }
    
  public Double getLoad_QLoad() 
  {
    return load_QLoad;
  }
    
  public void setLoad_QLoad(Double load_QLoad)
  {
    this.load_QLoad = load_QLoad;
  }
    
  public Integer getLoad_ACBusPtr() 
  {
    return load_ACBusPtr;
  }
    
  public void setLoad_ACBusPtr(Integer load_ACBusPtr)
  {
    this.load_ACBusPtr = load_ACBusPtr;
  }
    
  public Integer getLoad_Aux() 
  {
    return load_Aux;
  }
    
  public void setLoad_Aux(Integer load_Aux)
  {
    this.load_Aux = load_Aux;
  }
    
  public Integer getLoad_EQ() 
  {
    return load_EQ;
  }
    
  public void setLoad_EQ(Integer load_EQ)
  {
    this.load_EQ = load_EQ;
  }
    
  public Integer getLoad_Status() 
  {
    return load_Status;
  }
    
  public void setLoad_Status(Integer load_Status)
  {
    this.load_Status = load_Status;
  }
    
}
    
