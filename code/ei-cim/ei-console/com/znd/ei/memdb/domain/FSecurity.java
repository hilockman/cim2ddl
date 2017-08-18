package com.znd.ei.memdb.domain;

/**********************
*安全评价	*
***********************/
class FSecurity
{
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

  //状态索引
  public Integer getFState() {
    return fState;
  }

  public void setFState(Integer fState){
    this.fState = fState;
  }

  //支路故障
  public Integer getLTFault() {
    return lTFault;
  }

  public void setLTFault(Integer lTFault){
    this.lTFault = lTFault;
  }

  //多岛故障
  public Integer getMIsland() {
    return mIsland;
  }

  public void setMIsland(Integer mIsland){
    this.mIsland = mIsland;
  }

  //发电出力损失(MW)
  public Double getLossGenP() {
    return lossGenP;
  }

  public void setLossGenP(Double lossGenP){
    this.lossGenP = lossGenP;
  }

  //Bse文件名
  public String getBseFile() {
    return bseFile;
  }

  public void setBseFile(String bseFile){
    this.bseFile = bseFile;
  }

  //Swi文件名
  public String getSwiFile() {
    return swiFile;
  }

  public void setSwiFile(String swiFile){
    this.swiFile = swiFile;
  }

  //Out文件名
  public String getOutFile() {
    return outFile;
  }

  public void setOutFile(String outFile){
    this.outFile = outFile;
  }

  //安全性评估结果
  public Integer getResult() {
    return result;
  }

  public void setResult(Integer result){
    this.result = result;
  }

  //评估标记位
  public Integer getEstimated() {
    return estimated;
  }

  public void setEstimated(Integer estimated){
    this.estimated = estimated;
  }

}
