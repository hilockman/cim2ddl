package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*人工事件	*
***********************/
public class ManualFault  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //设置事件名称(Id)
  private String Name;
  
  //故障设备类型
  private Integer FDevType;
  
  //故障设备名称
  private String FDevName;
  
  //故障设备索引
  private Integer FDevSerno;
  
  //标记状态
  private Integer Proc;
  
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
    
  public Integer getFDevType()
  {
    return FDevType;
  }
    
  public void setFDevType(Integer FDevType)
  {
    this.FDevType = FDevType;
  }
    
  public String getFDevName()
  {
    return FDevName;
  }
    
  public void setFDevName(String FDevName)
  {
    this.FDevName = FDevName;
  }
    
  public Integer getFDevSerno()
  {
    return FDevSerno;
  }
    
  public void setFDevSerno(Integer FDevSerno)
  {
    this.FDevSerno = FDevSerno;
  }
    
  public Integer getProc()
  {
    return Proc;
  }
    
  public void setProc(Integer Proc)
  {
    this.Proc = Proc;
  }
    
  public String toString()
  {
    return "ManualFault ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", FDevType = " + FDevType
	 + ", FDevName = " + FDevName
	 + ", FDevSerno = " + FDevSerno
	 + ", Proc = " + Proc+"]";
  }
    
}
    
