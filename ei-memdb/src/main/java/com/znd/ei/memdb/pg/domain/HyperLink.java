package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*图形链接	*
***********************/
public class HyperLink  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源ID
  private String ResourceID;
  
  //连接名称
  private String LinkName;
  
  //连接图形
  private String LinkGraph;
  
  //显示外框
  private Integer ShowBound;
  
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
    
  public String getLinkName()
  {
    return LinkName;
  }
    
  public void setLinkName(String LinkName)
  {
    this.LinkName = LinkName;
  }
    
  public String getLinkGraph()
  {
    return LinkGraph;
  }
    
  public void setLinkGraph(String LinkGraph)
  {
    this.LinkGraph = LinkGraph;
  }
    
  public Integer getShowBound()
  {
    return ShowBound;
  }
    
  public void setShowBound(Integer ShowBound)
  {
    this.ShowBound = ShowBound;
  }
    
  public String toString()
  {
    return "HyperLink ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", LinkName = " + LinkName
	 + ", LinkGraph = " + LinkGraph
	 + ", ShowBound = " + ShowBound+"]";
  }
    
}
    
