package com.znd.ei.memdb.reliabilty.domain;


/**********************
*人工事件	*
***********************/
public class ManualFault
{
  private Integer id;
  
  private Integer memIndex;
  
  //设置事件名称(Id)
  private String name;
  
  //故障设备类型
  private Integer fDevType;
  
  //故障设备名称
  private String fDevName;
  
  //故障设备索引
  private Integer fDevSerno;
  
  //标记状态
  private Integer proc;
  
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
    
  public Integer getFDevType()
  {
    return fDevType;
  }
    
  public void setFDevType(Integer fDevType)
  {
    this.fDevType = fDevType;
  }
    
  public String getFDevName()
  {
    return fDevName;
  }
    
  public void setFDevName(String fDevName)
  {
    this.fDevName = fDevName;
  }
    
  public Integer getFDevSerno()
  {
    return fDevSerno;
  }
    
  public void setFDevSerno(Integer fDevSerno)
  {
    this.fDevSerno = fDevSerno;
  }
    
  public Integer getProc()
  {
    return proc;
  }
    
  public void setProc(Integer proc)
  {
    this.proc = proc;
  }
    
  public String toString()
  {
    return "ManualFault ["+	"id"=id,
	"memIndex"=memIndex,
	"name"=name,
	"fDevType"=fDevType,
	"fDevName"=fDevName,
	"fDevSerno"=fDevSerno,
	"proc"=proc+"]"
  }
    
}
    
