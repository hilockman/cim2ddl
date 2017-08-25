package com.znd.ei.memdb.domain;

/**********************
*抽样状态下越限调整	*
***********************/
class FStateOvlAd
{
  //状态索引
  private Integer fState;

  //越限设备类型
  private Integer ovlDevTyp;

  //越限设备索引
  private Integer ovlDevice;

  //调整设备类型
  private Integer adjDevTyp;

  //调整设备索引
  private Integer adjDevice;

  //功率调整量(MW)
  private Double adjValue;

  //状态索引
  public Integer getFState( ){
    return fState;
  }

  public void setFState(Integer fState){
    this.fState = fState;
  }

  //越限设备类型
  public Integer getOvlDevTyp( ){
    return ovlDevTyp;
  }

  public void setOvlDevTyp(Integer ovlDevTyp){
    this.ovlDevTyp = ovlDevTyp;
  }

  //越限设备索引
  public Integer getOvlDevice( ){
    return ovlDevice;
  }

  public void setOvlDevice(Integer ovlDevice){
    this.ovlDevice = ovlDevice;
  }

  //调整设备类型
  public Integer getAdjDevTyp( ){
    return adjDevTyp;
  }

  public void setAdjDevTyp(Integer adjDevTyp){
    this.adjDevTyp = adjDevTyp;
  }

  //调整设备索引
  public Integer getAdjDevice( ){
    return adjDevice;
  }

  public void setAdjDevice(Integer adjDevice){
    this.adjDevice = adjDevice;
  }

  //功率调整量(MW)
  public Double getAdjValue( ){
    return adjValue;
  }

  public void setAdjValue(Double adjValue){
    this.adjValue = adjValue;
  }

}
