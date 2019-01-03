package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*安全评价	*
***********************/
public class FSecurity  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //状态ID
  private Integer FStateId;
  
  //状态序号
  private Integer FStateNo;
  
  //支路故障
  private Integer LTFault;
  
  //多岛故障
  private Integer MIsland;
  
  //发电出力损失(兆瓦)
  private Double LossGenP;
  
  //Bse文件名
  private String BseFile;
  
  //Swi文件名
  private String SwiFile;
  
  //Out文件名
  private String OutFile;
  
  //安全性评估结果
  private Integer Result;
  
  //评估标记位
  private Integer Estimated;
  
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
    
  public Integer getFStateId()
  {
    return FStateId;
  }
    
  public void setFStateId(Integer FStateId)
  {
    this.FStateId = FStateId;
  }
    
  public Integer getFStateNo()
  {
    return FStateNo;
  }
    
  public void setFStateNo(Integer FStateNo)
  {
    this.FStateNo = FStateNo;
  }
    
  public Integer getLTFault()
  {
    return LTFault;
  }
    
  public void setLTFault(Integer LTFault)
  {
    this.LTFault = LTFault;
  }
    
  public Integer getMIsland()
  {
    return MIsland;
  }
    
  public void setMIsland(Integer MIsland)
  {
    this.MIsland = MIsland;
  }
    
  public Double getLossGenP()
  {
    return LossGenP;
  }
    
  public void setLossGenP(Double LossGenP)
  {
    this.LossGenP = LossGenP;
  }
    
  public String getBseFile()
  {
    return BseFile;
  }
    
  public void setBseFile(String BseFile)
  {
    this.BseFile = BseFile;
  }
    
  public String getSwiFile()
  {
    return SwiFile;
  }
    
  public void setSwiFile(String SwiFile)
  {
    this.SwiFile = SwiFile;
  }
    
  public String getOutFile()
  {
    return OutFile;
  }
    
  public void setOutFile(String OutFile)
  {
    this.OutFile = OutFile;
  }
    
  public Integer getResult()
  {
    return Result;
  }
    
  public void setResult(Integer Result)
  {
    this.Result = Result;
  }
    
  public Integer getEstimated()
  {
    return Estimated;
  }
    
  public void setEstimated(Integer Estimated)
  {
    this.Estimated = Estimated;
  }
    
  public String toString()
  {
    return "FSecurity ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", FStateId = " + FStateId
	 + ", FStateNo = " + FStateNo
	 + ", LTFault = " + LTFault
	 + ", MIsland = " + MIsland
	 + ", LossGenP = " + LossGenP
	 + ", BseFile = " + BseFile
	 + ", SwiFile = " + SwiFile
	 + ", OutFile = " + OutFile
	 + ", Result = " + Result
	 + ", Estimated = " + Estimated+"]";
  }
    
}
    
