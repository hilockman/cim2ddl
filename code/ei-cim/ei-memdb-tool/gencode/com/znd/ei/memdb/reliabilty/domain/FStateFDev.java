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
  private Integer fStateId;
  
  //状态序号
  private Integer fStateNo;
  
  //故障设备类型
  private Integer fDevTyp;
  
  //故障设备索引
  private Integer fDevIdx;
  
  //设备故障位置
  private Integer dFltPos;
  
  //设备故障类型
  private Integer dFltTyp;
  
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
    return fStateId;
  }
    
  public void setFStateId(Integer fStateId)
  {
    this.fStateId = fStateId;
  }
    
  public Integer getFStateNo()
  {
    return fStateNo;
  }
    
  public void setFStateNo(Integer fStateNo)
  {
    this.fStateNo = fStateNo;
  }
    
  public Integer getFDevTyp()
  {
    return fDevTyp;
  }
    
  public void setFDevTyp(Integer fDevTyp)
  {
    this.fDevTyp = fDevTyp;
  }
    
  public Integer getFDevIdx()
  {
    return fDevIdx;
  }
    
  public void setFDevIdx(Integer fDevIdx)
  {
    this.fDevIdx = fDevIdx;
  }
    
  public Integer getDFltPos()
  {
    return dFltPos;
  }
    
  public void setDFltPos(Integer dFltPos)
  {
    this.dFltPos = dFltPos;
  }
    
  public Integer getDFltTyp()
  {
    return dFltTyp;
  }
    
  public void setDFltTyp(Integer dFltTyp)
  {
    this.dFltTyp = dFltTyp;
  }
    
  public String toString()
  {
    return "FStateFDev ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", fStateId = " + fStateId
	 + ", fStateNo = " + fStateNo
	 + ", fDevTyp = " + fDevTyp
	 + ", fDevIdx = " + fDevIdx
	 + ", dFltPos = " + dFltPos
	 + ", dFltTyp = " + dFltTyp+"]";
  }
    
}
    
