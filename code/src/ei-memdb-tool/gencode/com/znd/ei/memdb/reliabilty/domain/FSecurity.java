package com.znd.ei.memdb.reliabilty.domain;


/**********************
*安全评价	*
***********************/
public class FSecurity
{
  private Integer id;
  
  private Integer memIndex;
  
  //状态索引
  private Integer fState;
  
  //支路故障
  private Integer lTFault;
  
  //多岛故障
  private Integer mIsland;
  
  //发电出力损失(MW)
  private Double lossGenP;
  
  //Bse文件名
  private String bseFile;
  
  //Swi文件名
  private String swiFile;
  
  //Out文件名
  private String outFile;
  
  //安全性评估结果
  private Integer result;
  
  //评估标记位
  private Integer estimated;
  
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
    
  public Integer getFState()
  {
    return fState;
  }
    
  public void setFState(Integer fState)
  {
    this.fState = fState;
  }
    
  public Integer getLTFault()
  {
    return lTFault;
  }
    
  public void setLTFault(Integer lTFault)
  {
    this.lTFault = lTFault;
  }
    
  public Integer getMIsland()
  {
    return mIsland;
  }
    
  public void setMIsland(Integer mIsland)
  {
    this.mIsland = mIsland;
  }
    
  public Double getLossGenP()
  {
    return lossGenP;
  }
    
  public void setLossGenP(Double lossGenP)
  {
    this.lossGenP = lossGenP;
  }
    
  public String getBseFile()
  {
    return bseFile;
  }
    
  public void setBseFile(String bseFile)
  {
    this.bseFile = bseFile;
  }
    
  public String getSwiFile()
  {
    return swiFile;
  }
    
  public void setSwiFile(String swiFile)
  {
    this.swiFile = swiFile;
  }
    
  public String getOutFile()
  {
    return outFile;
  }
    
  public void setOutFile(String outFile)
  {
    this.outFile = outFile;
  }
    
  public Integer getResult()
  {
    return result;
  }
    
  public void setResult(Integer result)
  {
    this.result = result;
  }
    
  public Integer getEstimated()
  {
    return estimated;
  }
    
  public void setEstimated(Integer estimated)
  {
    this.estimated = estimated;
  }
    
  public String toString()
  {
    return "FSecurity ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", fState = " + fState
	 + ", lTFault = " + lTFault
	 + ", mIsland = " + mIsland
	 + ", lossGenP = " + lossGenP
	 + ", bseFile = " + bseFile
	 + ", swiFile = " + swiFile
	 + ", outFile = " + outFile
	 + ", result = " + result
	 + ", estimated = " + estimated+"]";
  }
    
}
    
