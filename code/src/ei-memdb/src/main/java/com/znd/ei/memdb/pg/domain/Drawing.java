package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*图纸信息	*
***********************/
public class Drawing  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源ID
  private String ResourceID;
  
  //图纸名称
  private String Name;
  
  //图纸文件
  private String Path;
  
  //建立日期
  private Integer CreateDate;
  
  //建立时间
  private Integer CreateTime;
  
  //修改日期
  private Integer ModifyDate;
  
  //修改时间
  private Integer ModifyTime;
  
  //图纸创建
  private String Creator;
  
  //图纸修改
  private String Modifier;
  
  //图纸审核
  private String Reviewer;
  
  //图纸批准
  private String Approver;
  
  //所属项目
  private String Project;
  
  //规划设计方案
  private String Scheme;
  
  //图纸版本
  private String Version;
  
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
    
  public String getPath()
  {
    return Path;
  }
    
  public void setPath(String Path)
  {
    this.Path = Path;
  }
    
  public Integer getCreateDate()
  {
    return CreateDate;
  }
    
  public void setCreateDate(Integer CreateDate)
  {
    this.CreateDate = CreateDate;
  }
    
  public Integer getCreateTime()
  {
    return CreateTime;
  }
    
  public void setCreateTime(Integer CreateTime)
  {
    this.CreateTime = CreateTime;
  }
    
  public Integer getModifyDate()
  {
    return ModifyDate;
  }
    
  public void setModifyDate(Integer ModifyDate)
  {
    this.ModifyDate = ModifyDate;
  }
    
  public Integer getModifyTime()
  {
    return ModifyTime;
  }
    
  public void setModifyTime(Integer ModifyTime)
  {
    this.ModifyTime = ModifyTime;
  }
    
  public String getCreator()
  {
    return Creator;
  }
    
  public void setCreator(String Creator)
  {
    this.Creator = Creator;
  }
    
  public String getModifier()
  {
    return Modifier;
  }
    
  public void setModifier(String Modifier)
  {
    this.Modifier = Modifier;
  }
    
  public String getReviewer()
  {
    return Reviewer;
  }
    
  public void setReviewer(String Reviewer)
  {
    this.Reviewer = Reviewer;
  }
    
  public String getApprover()
  {
    return Approver;
  }
    
  public void setApprover(String Approver)
  {
    this.Approver = Approver;
  }
    
  public String getProject()
  {
    return Project;
  }
    
  public void setProject(String Project)
  {
    this.Project = Project;
  }
    
  public String getScheme()
  {
    return Scheme;
  }
    
  public void setScheme(String Scheme)
  {
    this.Scheme = Scheme;
  }
    
  public String getVersion()
  {
    return Version;
  }
    
  public void setVersion(String Version)
  {
    this.Version = Version;
  }
    
  public String toString()
  {
    return "Drawing ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Name = " + Name
	 + ", Path = " + Path
	 + ", CreateDate = " + CreateDate
	 + ", CreateTime = " + CreateTime
	 + ", ModifyDate = " + ModifyDate
	 + ", ModifyTime = " + ModifyTime
	 + ", Creator = " + Creator
	 + ", Modifier = " + Modifier
	 + ", Reviewer = " + Reviewer
	 + ", Approver = " + Approver
	 + ", Project = " + Project
	 + ", Scheme = " + Scheme
	 + ", Version = " + Version+"]";
  }
    
}
    
