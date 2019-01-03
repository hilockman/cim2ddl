package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电网-变压器表	*
***********************/
public class BpaDat_Tran  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //绕组数
  private Integer WindNum;
  
  //高压绕组
  private String WindH;
  
  //中压绕组
  private String WindM;
  
  //低压绕组
  private String WindL;
  
  //高压绕组索引
  private Integer iRWindH;
  
  //中压绕组索引
  private Integer iRWindM;
  
  //低压绕组索引
  private Integer iRWindL;
  
  //状态
  private Integer Status;
  
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
    
  public Integer getWindNum()
  {
    return WindNum;
  }
    
  public void setWindNum(Integer WindNum)
  {
    this.WindNum = WindNum;
  }
    
  public String getWindH()
  {
    return WindH;
  }
    
  public void setWindH(String WindH)
  {
    this.WindH = WindH;
  }
    
  public String getWindM()
  {
    return WindM;
  }
    
  public void setWindM(String WindM)
  {
    this.WindM = WindM;
  }
    
  public String getWindL()
  {
    return WindL;
  }
    
  public void setWindL(String WindL)
  {
    this.WindL = WindL;
  }
    
  public Integer getiRWindH()
  {
    return iRWindH;
  }
    
  public void setiRWindH(Integer iRWindH)
  {
    this.iRWindH = iRWindH;
  }
    
  public Integer getiRWindM()
  {
    return iRWindM;
  }
    
  public void setiRWindM(Integer iRWindM)
  {
    this.iRWindM = iRWindM;
  }
    
  public Integer getiRWindL()
  {
    return iRWindL;
  }
    
  public void setiRWindL(Integer iRWindL)
  {
    this.iRWindL = iRWindL;
  }
    
  public Integer getStatus()
  {
    return Status;
  }
    
  public void setStatus(Integer Status)
  {
    this.Status = Status;
  }
    
  public String toString()
  {
    return "BpaDat_Tran ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", WindNum = " + WindNum
	 + ", WindH = " + WindH
	 + ", WindM = " + WindM
	 + ", WindL = " + WindL
	 + ", iRWindH = " + iRWindH
	 + ", iRWindM = " + iRWindM
	 + ", iRWindL = " + iRWindL
	 + ", Status = " + Status+"]";
  }
    
}
    
