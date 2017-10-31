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
  private Integer windNum;
  
  //高压绕组
  private String windH;
  
  //中压绕组
  private String windM;
  
  //低压绕组
  private String windL;
  
  //高压绕组索引
  private Integer iRWindH;
  
  //中压绕组索引
  private Integer iRWindM;
  
  //低压绕组索引
  private Integer iRWindL;
  
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
    return windNum;
  }
    
  public void setWindNum(Integer windNum)
  {
    this.windNum = windNum;
  }
    
  public String getWindH()
  {
    return windH;
  }
    
  public void setWindH(String windH)
  {
    this.windH = windH;
  }
    
  public String getWindM()
  {
    return windM;
  }
    
  public void setWindM(String windM)
  {
    this.windM = windM;
  }
    
  public String getWindL()
  {
    return windL;
  }
    
  public void setWindL(String windL)
  {
    this.windL = windL;
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
    
  public String toString()
  {
    return "BpaDat_Tran ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", windNum = " + windNum
	 + ", windH = " + windH
	 + ", windM = " + windM
	 + ", windL = " + windL
	 + ", iRWindH = " + iRWindH
	 + ", iRWindM = " + iRWindM
	 + ", iRWindL = " + iRWindL+"]";
  }
    
}
    
