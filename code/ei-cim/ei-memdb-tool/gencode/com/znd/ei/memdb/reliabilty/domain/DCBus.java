package com.znd.ei.memdb.reliabilty.domain;


/**********************
*直流母线	*
***********************/
public class DCBus
{
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String name;
  
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
    
  public String getName()
  {
    return name;
  }
    
  public void setName(String name)
  {
    this.name = name;
  }
    
  public String toString()
  {
    return "DCBus ["+	"id"=id,
	"memIndex"=memIndex,
	"name"=name+"]"
  }
    
}
    
