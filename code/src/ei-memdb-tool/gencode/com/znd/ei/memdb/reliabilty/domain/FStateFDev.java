package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*抽样状态下故障设备	*
***********************/
public class FStateFDev  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //状态ID
  private Integer FStateId;
  
  //状态序号
  private Integer FStateNo;
  
  //故障设备类型
  private Integer FDevTyp;
  
  //故障设备索引
  private Integer FDevIdx;
  
  //设备故障位置
  private Integer DFltPos;
  
  //设备故障类型
  private Integer DFltTyp;
  
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
    
  public Integer getFDevTyp()
  {
    return FDevTyp;
  }
    
  public void setFDevTyp(Integer FDevTyp)
  {
    this.FDevTyp = FDevTyp;
  }
    
  public Integer getFDevIdx()
  {
    return FDevIdx;
  }
    
  public void setFDevIdx(Integer FDevIdx)
  {
    this.FDevIdx = FDevIdx;
  }
    
  public Integer getDFltPos()
  {
    return DFltPos;
  }
    
  public void setDFltPos(Integer DFltPos)
  {
    this.DFltPos = DFltPos;
  }
    
  public Integer getDFltTyp()
  {
    return DFltTyp;
  }
    
  public void setDFltTyp(Integer DFltTyp)
  {
    this.DFltTyp = DFltTyp;
  }
    
  public String toString()
  {
    return "FStateFDev ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", FStateId = " + FStateId
	 + ", FStateNo = " + FStateNo
	 + ", FDevTyp = " + FDevTyp
	 + ", FDevIdx = " + FDevIdx
	 + ", DFltPos = " + DFltPos
	 + ", DFltTyp = " + DFltTyp+"]";
  }
    
}
    
