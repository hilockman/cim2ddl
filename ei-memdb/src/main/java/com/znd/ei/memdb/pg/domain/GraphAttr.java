package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*图形信息	*
***********************/
public class GraphAttr  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //图纸ID
  private String Drawing;
  
  //表
  private String GeTable;
  
  //关键字
  private String KeyField;
  
  //父ID
  private String GeParentID;
  
  //可见
  private Integer GeVisible;
  
  //层
  private String GeLayer;
  
  //字体名称
  private String GeFont;
  
  //颜色
  private Integer GeColor;
  
  //线型
  private Integer GeLineStyle;
  
  //线宽
  private Double GeLineWidth;
  
  //大小
  private Double GeSize;
  
  //小数位数
  private Integer FloatPoint;
  
  //位置坐标X
  private Double LocationX;
  
  //位置坐标Y
  private Double LocationY;
  
  //横轴法向量X
  private Double HAxisX;
  
  //横轴法向量Y
  private Double HAxisY;
  
  //纵轴法向量X
  private Double LAxisX;
  
  //纵轴法向量Y
  private Double LAxisY;
  
  //Color(R)
  private Integer ColorR;
  
  //Color(G)
  private Integer ColorG;
  
  //Color(B)
  private Integer ColorB;
  
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
    
  public String getGeTable()
  {
    return GeTable;
  }
    
  public void setGeTable(String GeTable)
  {
    this.GeTable = GeTable;
  }
    
  public String getKeyField()
  {
    return KeyField;
  }
    
  public void setKeyField(String KeyField)
  {
    this.KeyField = KeyField;
  }
    
  public String getGeParentID()
  {
    return GeParentID;
  }
    
  public void setGeParentID(String GeParentID)
  {
    this.GeParentID = GeParentID;
  }
    
  public Integer getGeVisible()
  {
    return GeVisible;
  }
    
  public void setGeVisible(Integer GeVisible)
  {
    this.GeVisible = GeVisible;
  }
    
  public String getGeLayer()
  {
    return GeLayer;
  }
    
  public void setGeLayer(String GeLayer)
  {
    this.GeLayer = GeLayer;
  }
    
  public String getGeFont()
  {
    return GeFont;
  }
    
  public void setGeFont(String GeFont)
  {
    this.GeFont = GeFont;
  }
    
  public Integer getGeColor()
  {
    return GeColor;
  }
    
  public void setGeColor(Integer GeColor)
  {
    this.GeColor = GeColor;
  }
    
  public Integer getGeLineStyle()
  {
    return GeLineStyle;
  }
    
  public void setGeLineStyle(Integer GeLineStyle)
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
    
  public Double getGeSize()
  {
    return GeSize;
  }
    
  public void setGeSize(Double GeSize)
  {
    this.GeSize = GeSize;
  }
    
  public Integer getFloatPoint()
  {
    return FloatPoint;
  }
    
  public void setFloatPoint(Integer FloatPoint)
  {
    this.FloatPoint = FloatPoint;
  }
    
  public Double getLocationX()
  {
    return LocationX;
  }
    
  public void setLocationX(Double LocationX)
  {
    this.LocationX = LocationX;
  }
    
  public Double getLocationY()
  {
    return LocationY;
  }
    
  public void setLocationY(Double LocationY)
  {
    this.LocationY = LocationY;
  }
    
  public Double getHAxisX()
  {
    return HAxisX;
  }
    
  public void setHAxisX(Double HAxisX)
  {
    this.HAxisX = HAxisX;
  }
    
  public Double getHAxisY()
  {
    return HAxisY;
  }
    
  public void setHAxisY(Double HAxisY)
  {
    this.HAxisY = HAxisY;
  }
    
  public Double getLAxisX()
  {
    return LAxisX;
  }
    
  public void setLAxisX(Double LAxisX)
  {
    this.LAxisX = LAxisX;
  }
    
  public Double getLAxisY()
  {
    return LAxisY;
  }
    
  public void setLAxisY(Double LAxisY)
  {
    this.LAxisY = LAxisY;
  }
    
  public Integer getColorR()
  {
    return ColorR;
  }
    
  public void setColorR(Integer ColorR)
  {
    this.ColorR = ColorR;
  }
    
  public Integer getColorG()
  {
    return ColorG;
  }
    
  public void setColorG(Integer ColorG)
  {
    this.ColorG = ColorG;
  }
    
  public Integer getColorB()
  {
    return ColorB;
  }
    
  public void setColorB(Integer ColorB)
  {
    this.ColorB = ColorB;
  }
    
  public String toString()
  {
    return "GraphAttr ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Drawing = " + Drawing
	 + ", GeTable = " + GeTable
	 + ", KeyField = " + KeyField
	 + ", GeParentID = " + GeParentID
	 + ", GeVisible = " + GeVisible
	 + ", GeLayer = " + GeLayer
	 + ", GeFont = " + GeFont
	 + ", GeColor = " + GeColor
	 + ", GeLineStyle = " + GeLineStyle
	 + ", GeLineWidth = " + GeLineWidth
	 + ", GeSize = " + GeSize
	 + ", FloatPoint = " + FloatPoint
	 + ", LocationX = " + LocationX
	 + ", LocationY = " + LocationY
	 + ", HAxisX = " + HAxisX
	 + ", HAxisY = " + HAxisY
	 + ", LAxisX = " + LAxisX
	 + ", LAxisY = " + LAxisY
	 + ", ColorR = " + ColorR
	 + ", ColorG = " + ColorG
	 + ", ColorB = " + ColorB+"]";
  }
    
}
    
