package com.znd.ei.memdb.domain;

/**********************
*两状态可靠性设备	*
***********************/
class R2StateComp
{
  //类型
  private Integer type;

  //设备索引
  private Integer index;

  //类型
  public Integer getType() {
    return type;
  }

  public void setType(Integer type){
    this.type = type;
  }

  //设备索引
  public Integer getIndex() {
    return index;
  }

  public void setIndex(Integer index){
    this.index = index;
  }

}
