package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*BPA厂站表(BPASub)	*
***********************/
@Entity
public class BpaDat_Sub
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //厂站名称
  private String sub_Name;
  
  //厂站别名
  private String sub_Alias;
  
  //厂站类型
  private Integer sub_Type;
  
  //厂站发电有功
  private Double sub_GenP;
  
  //厂站发电无功
  private Double sub_GenQ;
  
  //厂站负荷有功
  private Double sub_LoadP;
  
  //厂站负荷无功
  private Double sub_LoadQ;
  
  //厂站补偿无功
  private Double sub_ShuntQ;
  
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
    return sub_Name;
  }
    
  public void setSub_Name(String sub_Name)
  {
    this.sub_Name = sub_Name;
  }
    
  public String getSub_Alias() 
  {
    return sub_Alias;
  }
    
  public void setSub_Alias(String sub_Alias)
  {
    this.sub_Alias = sub_Alias;
  }
    
  public Integer getSub_Type() 
  {
    return sub_Type;
  }
    
  public void setSub_Type(Integer sub_Type)
  {
    this.sub_Type = sub_Type;
  }
    
  public Double getSub_GenP() 
  {
    return sub_GenP;
  }
    
  public void setSub_GenP(Double sub_GenP)
  {
    this.sub_GenP = sub_GenP;
  }
    
  public Double getSub_GenQ() 
  {
    return sub_GenQ;
  }
    
  public void setSub_GenQ(Double sub_GenQ)
  {
    this.sub_GenQ = sub_GenQ;
  }
    
  public Double getSub_LoadP() 
  {
    return sub_LoadP;
  }
    
  public void setSub_LoadP(Double sub_LoadP)
  {
    this.sub_LoadP = sub_LoadP;
  }
    
  public Double getSub_LoadQ() 
  {
    return sub_LoadQ;
  }
    
  public void setSub_LoadQ(Double sub_LoadQ)
  {
    this.sub_LoadQ = sub_LoadQ;
  }
    
  public Double getSub_ShuntQ() 
  {
    return sub_ShuntQ;
  }
    
  public void setSub_ShuntQ(Double sub_ShuntQ)
  {
    this.sub_ShuntQ = sub_ShuntQ;
  }
    
}
    
