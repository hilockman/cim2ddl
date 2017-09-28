package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*发电机电压保护(RE)	*
***********************/
@Entity
public class BpaSwi_RE
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称
  private String aCBus_Name;
  
  //基准电压(kV)	
  private Double aCBus_KV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //电压设定值1(pu)
  private Double rE_VOL1;
  
  //电压设定值2(pu)
  private Double rE_VOL2;
  
  //电压设定值3(pu)
  private Double rE_VOL3;
  
  //电压设定值4(pu)
  private Double rE_VOL4;
  
  //电压设定值5(pu)
  private Double rE_VOL5;
  
  //电压设定值6(pu)
  private Double rE_VOL6;
  
  //电压设定值7(pu)
  private Double rE_VOL7;
  
  //电压设定值8(pu)
  private Double rE_VOL8;
  
  //电压设定值9(pu)
  private Double rE_VOL9;
  
  //电压设定值10(pu)
  private Double rE_VOL10;
  
  //时迟1(周)
  private Double rE_TIME1;
  
  //时迟2(周)
  private Double rE_TIME2;
  
  //时迟3(周)
  private Double rE_TIME3;
  
  //时迟4(周)
  private Double rE_TIME4;
  
  //时迟5(周)
  private Double rE_TIME5;
  
  //时迟6(周)
  private Double rE_TIME6;
  
  //时迟7(周)
  private Double rE_TIME7;
  
  //时迟8(周)
  private Double rE_TIME8;
  
  //时迟9(周)
  private Double rE_TIME9;
  
  //时迟10(周)
  private Double rE_TIME10;
  
  //继电器动作时间(周)
  private Double rE_TBRK;
  
  //控制母线名称
  private String rE_NAME_CON;
  
  //控制母线基准电压
  private Double rE_KV_CON;
  
  //发电机母线索引
  private Integer busPtr;
  
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
    
  public String getACBus_Name() 
  {
    return aCBus_Name;
  }
    
  public void setACBus_Name(String aCBus_Name)
  {
    this.aCBus_Name = aCBus_Name;
  }
    
  public Double getACBus_KV() 
  {
    return aCBus_KV;
  }
    
  public void setACBus_KV(Double aCBus_KV)
  {
    this.aCBus_KV = aCBus_KV;
  }
    
  public Integer getGen_ID() 
  {
    return gen_ID;
  }
    
  public void setGen_ID(Integer gen_ID)
  {
    this.gen_ID = gen_ID;
  }
    
  public Double getRE_VOL1() 
  {
    return rE_VOL1;
  }
    
  public void setRE_VOL1(Double rE_VOL1)
  {
    this.rE_VOL1 = rE_VOL1;
  }
    
  public Double getRE_VOL2() 
  {
    return rE_VOL2;
  }
    
  public void setRE_VOL2(Double rE_VOL2)
  {
    this.rE_VOL2 = rE_VOL2;
  }
    
  public Double getRE_VOL3() 
  {
    return rE_VOL3;
  }
    
  public void setRE_VOL3(Double rE_VOL3)
  {
    this.rE_VOL3 = rE_VOL3;
  }
    
  public Double getRE_VOL4() 
  {
    return rE_VOL4;
  }
    
  public void setRE_VOL4(Double rE_VOL4)
  {
    this.rE_VOL4 = rE_VOL4;
  }
    
  public Double getRE_VOL5() 
  {
    return rE_VOL5;
  }
    
  public void setRE_VOL5(Double rE_VOL5)
  {
    this.rE_VOL5 = rE_VOL5;
  }
    
  public Double getRE_VOL6() 
  {
    return rE_VOL6;
  }
    
  public void setRE_VOL6(Double rE_VOL6)
  {
    this.rE_VOL6 = rE_VOL6;
  }
    
  public Double getRE_VOL7() 
  {
    return rE_VOL7;
  }
    
  public void setRE_VOL7(Double rE_VOL7)
  {
    this.rE_VOL7 = rE_VOL7;
  }
    
  public Double getRE_VOL8() 
  {
    return rE_VOL8;
  }
    
  public void setRE_VOL8(Double rE_VOL8)
  {
    this.rE_VOL8 = rE_VOL8;
  }
    
  public Double getRE_VOL9() 
  {
    return rE_VOL9;
  }
    
  public void setRE_VOL9(Double rE_VOL9)
  {
    this.rE_VOL9 = rE_VOL9;
  }
    
  public Double getRE_VOL10() 
  {
    return rE_VOL10;
  }
    
  public void setRE_VOL10(Double rE_VOL10)
  {
    this.rE_VOL10 = rE_VOL10;
  }
    
  public Double getRE_TIME1() 
  {
    return rE_TIME1;
  }
    
  public void setRE_TIME1(Double rE_TIME1)
  {
    this.rE_TIME1 = rE_TIME1;
  }
    
  public Double getRE_TIME2() 
  {
    return rE_TIME2;
  }
    
  public void setRE_TIME2(Double rE_TIME2)
  {
    this.rE_TIME2 = rE_TIME2;
  }
    
  public Double getRE_TIME3() 
  {
    return rE_TIME3;
  }
    
  public void setRE_TIME3(Double rE_TIME3)
  {
    this.rE_TIME3 = rE_TIME3;
  }
    
  public Double getRE_TIME4() 
  {
    return rE_TIME4;
  }
    
  public void setRE_TIME4(Double rE_TIME4)
  {
    this.rE_TIME4 = rE_TIME4;
  }
    
  public Double getRE_TIME5() 
  {
    return rE_TIME5;
  }
    
  public void setRE_TIME5(Double rE_TIME5)
  {
    this.rE_TIME5 = rE_TIME5;
  }
    
  public Double getRE_TIME6() 
  {
    return rE_TIME6;
  }
    
  public void setRE_TIME6(Double rE_TIME6)
  {
    this.rE_TIME6 = rE_TIME6;
  }
    
  public Double getRE_TIME7() 
  {
    return rE_TIME7;
  }
    
  public void setRE_TIME7(Double rE_TIME7)
  {
    this.rE_TIME7 = rE_TIME7;
  }
    
  public Double getRE_TIME8() 
  {
    return rE_TIME8;
  }
    
  public void setRE_TIME8(Double rE_TIME8)
  {
    this.rE_TIME8 = rE_TIME8;
  }
    
  public Double getRE_TIME9() 
  {
    return rE_TIME9;
  }
    
  public void setRE_TIME9(Double rE_TIME9)
  {
    this.rE_TIME9 = rE_TIME9;
  }
    
  public Double getRE_TIME10() 
  {
    return rE_TIME10;
  }
    
  public void setRE_TIME10(Double rE_TIME10)
  {
    this.rE_TIME10 = rE_TIME10;
  }
    
  public Double getRE_TBRK() 
  {
    return rE_TBRK;
  }
    
  public void setRE_TBRK(Double rE_TBRK)
  {
    this.rE_TBRK = rE_TBRK;
  }
    
  public String getRE_NAME_CON() 
  {
    return rE_NAME_CON;
  }
    
  public void setRE_NAME_CON(String rE_NAME_CON)
  {
    this.rE_NAME_CON = rE_NAME_CON;
  }
    
  public Double getRE_KV_CON() 
  {
    return rE_KV_CON;
  }
    
  public void setRE_KV_CON(Double rE_KV_CON)
  {
    this.rE_KV_CON = rE_KV_CON;
  }
    
  public Integer getBusPtr() 
  {
    return busPtr;
  }
    
  public void setBusPtr(Integer busPtr)
  {
    this.busPtr = busPtr;
  }
    
}
    
