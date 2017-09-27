package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*抽样状态下越限调整	*
***********************/
@Entity
public class FStateOvlAd
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
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
    
  public Integer getOvlDevTyp() 
  {
    return ovlDevTyp;
  }
    
  public void setOvlDevTyp(Integer ovlDevTyp)
  {
    this.ovlDevTyp = ovlDevTyp;
  }
    
  public Integer getOvlDevice() 
  {
    return ovlDevice;
  }
    
  public void setOvlDevice(Integer ovlDevice)
  {
    this.ovlDevice = ovlDevice;
  }
    
  public Integer getAdjDevTyp() 
  {
    return adjDevTyp;
  }
    
  public void setAdjDevTyp(Integer adjDevTyp)
  {
    this.adjDevTyp = adjDevTyp;
  }
    
  public Integer getAdjDevice() 
  {
    return adjDevice;
  }
    
  public void setAdjDevice(Integer adjDevice)
  {
    this.adjDevice = adjDevice;
  }
    
  public Double getAdjValue() 
  {
    return adjValue;
  }
    
  public void setAdjValue(Double adjValue)
  {
    this.adjValue = adjValue;
  }
    
}
    
