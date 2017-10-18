package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*发电负荷调整表(P)	*
***********************/
@Entity
public class BpaDat_P
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //所有者代码
  private String p_Zone;
  
  //负荷有功修改因子
  private Double p_LoadPFactor;
  
  //负荷无功修改因子
  private Double p_LoadQFactor;
  
  //发电出力有功修改因子
  private Double p_GenPFactor;
  
  //发电出力无功修改因子
  private Double p_GenQFactor;
  
  //状态
  private Integer p_Status;
  
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
    
  public String getCardKey() 
  {
    return cardKey;
  }
    
  public void setCardKey(String cardKey)
  {
    this.cardKey = cardKey;
  }
    
  public String getP_Zone() 
  {
    return p_Zone;
  }
    
  public void setP_Zone(String p_Zone)
  {
    this.p_Zone = p_Zone;
  }
    
  public Double getP_LoadPFactor() 
  {
    return p_LoadPFactor;
  }
    
  public void setP_LoadPFactor(Double p_LoadPFactor)
  {
    this.p_LoadPFactor = p_LoadPFactor;
  }
    
  public Double getP_LoadQFactor() 
  {
    return p_LoadQFactor;
  }
    
  public void setP_LoadQFactor(Double p_LoadQFactor)
  {
    this.p_LoadQFactor = p_LoadQFactor;
  }
    
  public Double getP_GenPFactor() 
  {
    return p_GenPFactor;
  }
    
  public void setP_GenPFactor(Double p_GenPFactor)
  {
    this.p_GenPFactor = p_GenPFactor;
  }
    
  public Double getP_GenQFactor() 
  {
    return p_GenQFactor;
  }
    
  public void setP_GenQFactor(Double p_GenQFactor)
  {
    this.p_GenQFactor = p_GenQFactor;
  }
    
  public Integer getP_Status() 
  {
    return p_Status;
  }
    
  public void setP_Status(Integer p_Status)
  {
    this.p_Status = p_Status;
  }
    
}
    
