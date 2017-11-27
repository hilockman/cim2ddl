package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*共因故障	*
***********************/
public class CommonFault  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //共因故障名称(Id)
  private String Name;
  
  //共因故障类型
  private Integer CommonFaultType;
  
  //共因设备类型
  private Integer CommonDeviceType;
  
  //设备类型
  private Integer DevType;
  
  //设备名称
  private String DevName;
  
  //设备索引
  private Integer DevSerNo;
  
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
    
  public Integer getCommonFaultType()
  {
    return CommonFaultType;
  }
    
  public void setCommonFaultType(Integer CommonFaultType)
  {
    this.CommonFaultType = CommonFaultType;
  }
    
  public Integer getCommonDeviceType()
  {
    return CommonDeviceType;
  }
    
  public void setCommonDeviceType(Integer CommonDeviceType)
  {
    this.CommonDeviceType = CommonDeviceType;
  }
    
  public Integer getDevType()
  {
    return DevType;
  }
    
  public void setDevType(Integer DevType)
  {
    this.DevType = DevType;
  }
    
  public String getDevName()
  {
    return DevName;
  }
    
  public void setDevName(String DevName)
  {
    this.DevName = DevName;
  }
    
  public Integer getDevSerNo()
  {
    return DevSerNo;
  }
    
  public void setDevSerNo(Integer DevSerNo)
  {
    this.DevSerNo = DevSerNo;
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
    return "CommonFault ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", CommonFaultType = " + CommonFaultType
	 + ", CommonDeviceType = " + CommonDeviceType
	 + ", DevType = " + DevType
	 + ", DevName = " + DevName
	 + ", DevSerNo = " + DevSerNo
	 + ", Proc = " + Proc+"]";
  }
    
}
    
