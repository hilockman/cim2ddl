package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*区域交换功率控制表(I)	*
***********************/
public class BpaDat_I  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //区域1名称
  private String I_Area1;
  
  //区域2名称
  private String I_Area2;
  
  //区域1向区域2的输出功率
  private Double I_OutP;
  
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
    return CardKey;
  }
    
  public void setCardKey(String CardKey)
  {
    this.CardKey = CardKey;
  }
    
  public String getI_Area1()
  {
    return I_Area1;
  }
    
  public void setI_Area1(String I_Area1)
  {
    this.I_Area1 = I_Area1;
  }
    
  public String getI_Area2()
  {
    return I_Area2;
  }
    
  public void setI_Area2(String I_Area2)
  {
    this.I_Area2 = I_Area2;
  }
    
  public Double getI_OutP()
  {
    return I_OutP;
  }
    
  public void setI_OutP(Double I_OutP)
  {
    this.I_OutP = I_OutP;
  }
    
  public String toString()
  {
    return "BpaDat_I ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", I_Area1 = " + I_Area1
	 + ", I_Area2 = " + I_Area2
	 + ", I_OutP = " + I_OutP+"]";
  }
    
}
    
