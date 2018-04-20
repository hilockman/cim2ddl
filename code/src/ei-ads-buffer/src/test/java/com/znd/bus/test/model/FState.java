package com.znd.bus.test.model;


/**********************
*抽样状态	*
***********************/
public class FState 
{
  private Integer id;
  
  //状态ID
  private Integer FStateID;
  

  //持续时间
  private Double Durition;
  
 
  
  public Integer getId()
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
      
  public Integer getFStateID()
  {
    return FStateID;
  }
    
  public void setFStateID(Integer FStateID)
  {
    this.FStateID = FStateID;
  }
    


  public Double getDurition()
  {
    return Durition;
  }
    
  public void setDurition(Double Durition)
  {
    this.Durition = Durition;
  }

@Override
public String toString() {
	return "FState [id=" + id + ", FStateID=" + FStateID + ", Durition="
			+ Durition + "]";
}
    
 
 
}
    
