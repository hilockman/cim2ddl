package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*线路高抗零序参数模型(LOHG)	*
***********************/
@Entity
public class BpaSwi_LOHG
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称1
  private String lO+_BusI;
  
  //基准电压1(kV)
  private Double lO+_kVI;
  
  //母线名称2
  private String lO+_BusJ;
  
  //基准电压2(kV)
  private Double lO+_kVJ;
  
  //并联线路的回路标志
  private Integer lO+_Loop;
  
  //线路前侧高抗对应的等值零序电抗(pu)
  private Double lO+_X0I;
  
  //线路后侧高抗对应的等值零序电抗(pu)
  private Double lO+_X0J;
  
  //线路高抗名称
  private String keyName;
  
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
    
  public String getCardKey() 
  {
    return cardKey;
  }
    
  public void setCardKey(String cardKey)
  {
    this.cardKey = cardKey;
  }
    
  public String getLO+_BusI() 
  {
    return lO+_BusI;
  }
    
  public void setLO+_BusI(String lO+_BusI)
  {
    this.lO+_BusI = lO+_BusI;
  }
    
  public Double getLO+_kVI() 
  {
    return lO+_kVI;
  }
    
  public void setLO+_kVI(Double lO+_kVI)
  {
    this.lO+_kVI = lO+_kVI;
  }
    
  public String getLO+_BusJ() 
  {
    return lO+_BusJ;
  }
    
  public void setLO+_BusJ(String lO+_BusJ)
  {
    this.lO+_BusJ = lO+_BusJ;
  }
    
  public Double getLO+_kVJ() 
  {
    return lO+_kVJ;
  }
    
  public void setLO+_kVJ(Double lO+_kVJ)
  {
    this.lO+_kVJ = lO+_kVJ;
  }
    
  public Integer getLO+_Loop() 
  {
    return lO+_Loop;
  }
    
  public void setLO+_Loop(Integer lO+_Loop)
  {
    this.lO+_Loop = lO+_Loop;
  }
    
  public Double getLO+_X0I() 
  {
    return lO+_X0I;
  }
    
  public void setLO+_X0I(Double lO+_X0I)
  {
    this.lO+_X0I = lO+_X0I;
  }
    
  public Double getLO+_X0J() 
  {
    return lO+_X0J;
  }
    
  public void setLO+_X0J(Double lO+_X0J)
  {
    this.lO+_X0J = lO+_X0J;
  }
    
  public String getKeyName() 
  {
    return keyName;
  }
    
  public void setKeyName(String keyName)
  {
    this.keyName = keyName;
  }
    
}
    
