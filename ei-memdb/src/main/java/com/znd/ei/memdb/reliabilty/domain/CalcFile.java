package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*计算文件表	*
***********************/
public class CalcFile  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //工作ID
  private Integer JobId;
  
  //文件名称
  private String Name;
  
  //文件类型
  private String Type;
  
  //任务内容
  private String Content;
  
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
    
  public Integer getJobId()
  {
    return JobId;
  }
    
  public void setJobId(Integer JobId)
  {
    this.JobId = JobId;
  }
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public String getType()
  {
    return Type;
  }
    
  public void setType(String Type)
  {
    this.Type = Type;
  }
    
  public String getContent()
  {
    return Content;
  }
    
  public void setContent(String Content)
  {
    this.Content = Content;
  }
    
  public String toString()
  {
    return "CalcFile ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", JobId = " + JobId
	 + ", Name = " + Name
	 + ", Type = " + Type
	 + ", Content = " + Content+"]";
  }
    
}
    
