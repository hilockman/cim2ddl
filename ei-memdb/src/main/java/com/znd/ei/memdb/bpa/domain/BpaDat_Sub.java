package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*BPA厂站表(BPASub)	*
***********************/
public class BpaDat_Sub  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //厂站名称
  private String Sub_Name;
  
  //厂站别名
  private String Sub_Alias;
  
  //厂站类型
  private Integer Sub_Type;
  
  //厂站发电有功
  private Double Sub_GenP;
  
  //厂站发电无功
  private Double Sub_GenQ;
  
  //厂站负荷有功
  private Double Sub_LoadP;
  
  //厂站负荷无功
  private Double Sub_LoadQ;
  
  //厂站补偿无功
  private Double Sub_ShuntQ;
  
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
    
  public String getSub_Name()
  {
    return Sub_Name;
  }
    
  public void setSub_Name(String Sub_Name)
  {
    this.Sub_Name = Sub_Name;
  }
    
  public String getSub_Alias()
  {
    return Sub_Alias;
  }
    
  public void setSub_Alias(String Sub_Alias)
  {
    this.Sub_Alias = Sub_Alias;
  }
    
  public Integer getSub_Type()
  {
    return Sub_Type;
  }
    
  public void setSub_Type(Integer Sub_Type)
  {
    this.Sub_Type = Sub_Type;
  }
    
  public Double getSub_GenP()
  {
    return Sub_GenP;
  }
    
  public void setSub_GenP(Double Sub_GenP)
  {
    this.Sub_GenP = Sub_GenP;
  }
    
  public Double getSub_GenQ()
  {
    return Sub_GenQ;
  }
    
  public void setSub_GenQ(Double Sub_GenQ)
  {
    this.Sub_GenQ = Sub_GenQ;
  }
    
  public Double getSub_LoadP()
  {
    return Sub_LoadP;
  }
    
  public void setSub_LoadP(Double Sub_LoadP)
  {
    this.Sub_LoadP = Sub_LoadP;
  }
    
  public Double getSub_LoadQ()
  {
    return Sub_LoadQ;
  }
    
  public void setSub_LoadQ(Double Sub_LoadQ)
  {
    this.Sub_LoadQ = Sub_LoadQ;
  }
    
  public Double getSub_ShuntQ()
  {
    return Sub_ShuntQ;
  }
    
  public void setSub_ShuntQ(Double Sub_ShuntQ)
  {
    this.Sub_ShuntQ = Sub_ShuntQ;
  }
    
  public String toString()
  {
    return "BpaDat_Sub ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Sub_Name = " + Sub_Name
	 + ", Sub_Alias = " + Sub_Alias
	 + ", Sub_Type = " + Sub_Type
	 + ", Sub_GenP = " + Sub_GenP
	 + ", Sub_GenQ = " + Sub_GenQ
	 + ", Sub_LoadP = " + Sub_LoadP
	 + ", Sub_LoadQ = " + Sub_LoadQ
	 + ", Sub_ShuntQ = " + Sub_ShuntQ+"]";
  }
    
}
    
