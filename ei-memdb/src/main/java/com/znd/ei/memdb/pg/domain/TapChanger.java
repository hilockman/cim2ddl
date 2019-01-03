package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*分接头	*
***********************/
public class TapChanger  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //最小档位
  private Integer TapMin;
  
  //最大档位
  private Integer TapMax;
  
  //正常档位
  private Integer TapNom;
  
  //中间档位
  private Integer TapNeutral;
  
  //档距
  private Double TapStep;
  
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
    
  public String getResourceID()
  {
    return ResourceID;
  }
    
  public void setResourceID(String ResourceID)
  {
    this.ResourceID = ResourceID;
  }
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public String getDescription()
  {
    return Description;
  }
    
  public void setDescription(String Description)
  {
    this.Description = Description;
  }
    
  public Integer getTapMin()
  {
    return TapMin;
  }
    
  public void setTapMin(Integer TapMin)
  {
    this.TapMin = TapMin;
  }
    
  public Integer getTapMax()
  {
    return TapMax;
  }
    
  public void setTapMax(Integer TapMax)
  {
    this.TapMax = TapMax;
  }
    
  public Integer getTapNom()
  {
    return TapNom;
  }
    
  public void setTapNom(Integer TapNom)
  {
    this.TapNom = TapNom;
  }
    
  public Integer getTapNeutral()
  {
    return TapNeutral;
  }
    
  public void setTapNeutral(Integer TapNeutral)
  {
    this.TapNeutral = TapNeutral;
  }
    
  public Double getTapStep()
  {
    return TapStep;
  }
    
  public void setTapStep(Double TapStep)
  {
    this.TapStep = TapStep;
  }
    
  public String toString()
  {
    return "TapChanger ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", TapMin = " + TapMin
	 + ", TapMax = " + TapMax
	 + ", TapNom = " + TapNom
	 + ", TapNeutral = " + TapNeutral
	 + ", TapStep = " + TapStep+"]";
  }
    
}
    
