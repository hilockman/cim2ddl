package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*区域交换功率控制表(I)	*
***********************/
@Entity
public class BpaDat_I
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //区域1名称
  private String i_Area1;
  
  //区域2名称
  private String i_Area2;
  
  //区域1向区域2的输出功率
  private Double i_OutP;
  
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
    
  public String getI_Area1() 
  {
    return i_Area1;
  }
    
  public void setI_Area1(String i_Area1)
  {
    this.i_Area1 = i_Area1;
  }
    
  public String getI_Area2() 
  {
    return i_Area2;
  }
    
  public void setI_Area2(String i_Area2)
  {
    this.i_Area2 = i_Area2;
  }
    
  public Double getI_OutP() 
  {
    return i_OutP;
  }
    
  public void setI_OutP(Double i_OutP)
  {
    this.i_OutP = i_OutP;
  }
    
}
    
