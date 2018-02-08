package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*点信息	*
***********************/
public class LineVertex  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //图纸ID
  private String Drawing;
  
  //表
  private String GeTable;
  
  //父ID
  private String GeParent;
  
  //点序号
  private Integer Serial;
  
  //点坐标X
  private Double VertexX;
  
  //点坐标Y
  private Double VertexY;
  
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
    
  public String getGeParent()
  {
    return GeParent;
  }
    
  public void setGeParent(String GeParent)
  {
    this.GeParent = GeParent;
  }
    
  public Integer getSerial()
  {
    return Serial;
  }
    
  public void setSerial(Integer Serial)
  {
    this.Serial = Serial;
  }
    
  public Double getVertexX()
  {
    return VertexX;
  }
    
  public void setVertexX(Double VertexX)
  {
    this.VertexX = VertexX;
  }
    
  public Double getVertexY()
  {
    return VertexY;
  }
    
  public void setVertexY(Double VertexY)
  {
    this.VertexY = VertexY;
  }
    
  public String toString()
  {
    return "LineVertex ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Drawing = " + Drawing
	 + ", GeTable = " + GeTable
	 + ", GeParent = " + GeParent
	 + ", Serial = " + Serial
	 + ", VertexX = " + VertexX
	 + ", VertexY = " + VertexY+"]";
  }
    
}
    
