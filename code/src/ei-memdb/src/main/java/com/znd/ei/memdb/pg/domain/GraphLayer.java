package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*图层信息	*
***********************/
public class GraphLayer  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //图纸ID
  private String Drawing;
  
  //层名称
  private String GeName;
  
  //颜色
  private Integer GeColor;
  
  //线型
  private String GeLineStyle;
  
  //线宽
  private Double GeLineWidth;
  
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
    
  public String getDrawing()
  {
    return Drawing;
  }
    
  public void setDrawing(String Drawing)
  {
    this.Drawing = Drawing;
  }
    
  public String getGeName()
  {
    return GeName;
  }
    
  public void setGeName(String GeName)
  {
    this.GeName = GeName;
  }
    
  public Integer getGeColor()
  {
    return GeColor;
  }
    
  public void setGeColor(Integer GeColor)
  {
    this.GeColor = GeColor;
  }
    
  public String getGeLineStyle()
  {
    return GeLineStyle;
  }
    
  public void setGeLineStyle(String GeLineStyle)
  {
    this.GeLineStyle = GeLineStyle;
  }
    
  public Double getGeLineWidth()
  {
    return GeLineWidth;
  }
    
  public void setGeLineWidth(Double GeLineWidth)
  {
    this.GeLineWidth = GeLineWidth;
  }
    
  public String toString()
  {
    return "GraphLayer ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Drawing = " + Drawing
	 + ", GeName = " + GeName
	 + ", GeColor = " + GeColor
	 + ", GeLineStyle = " + GeLineStyle
	 + ", GeLineWidth = " + GeLineWidth+"]";
  }
    
}
    
