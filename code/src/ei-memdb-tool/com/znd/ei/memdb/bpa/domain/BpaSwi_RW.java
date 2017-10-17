package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*发电机转速保护(RW)	*
***********************/
@Entity
public class BpaSwi_RW
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
  
  //发电机立即跳闸的最大转速(pu)
  private Double rW_Wmax;
  
  //发电机立即跳闸的最小转速(pu)
  private Double rW_Wmin;
  
  //发电机转速设定值1(pu)
  private Double rW_Wset1;
  
  //发电机转速设定值2(pu)
  private Double rW_Wset2;
  
  //发电机转速设定值3(pu)
  private Double rW_Wset3;
  
  //发电机转速设定值4(pu)
  private Double rW_Wset4;
  
  //发电机转速设定值5(pu)
  private Double rW_Wset5;
  
  //发电机转速设定值6(pu)
  private Double rW_Wset6;
  
  //发电机转速设定值7(pu)
  private Double rW_Wset7;
  
  //发电机转速设定值8(pu)
  private Double rW_Wset8;
  
  //发电机转速设定值9(pu)
  private Double rW_Wset9;
  
  //发电机转速设定值10(pu)
  private Double rW_Wset10;
  
  //发电机转速设定值1对应的时迟(周)
  private Double rW_Delay1;
  
  //发电机转速设定值2对应的时迟(周)
  private Double rW_Delay2;
  
  //发电机转速设定值3对应的时迟(周)
  private Double rW_Delay3;
  
  //发电机转速设定值4对应的时迟(周)
  private Double rW_Delay4;
  
  //发电机转速设定值5对应的时迟(周)
  private Double rW_Delay5;
  
  //发电机转速设定值6对应的时迟(周)
  private Double rW_Delay6;
  
  //发电机转速设定值7对应的时迟(周)
  private Double rW_Delay7;
  
  //发电机转速设定值8对应的时迟(周)
  private Double rW_Delay8;
  
  //发电机转速设定值9对应的时迟(周)
  private Double rW_Delay9;
  
  //发电机转速设定值10对应的时迟(周)
  private Double rW_Delay10;
  
  //继电器动作时间(周)
  private Double rW_Tbrk;
  
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
    
  public Double getRW_Wmax() 
  {
    return rW_Wmax;
  }
    
  public void setRW_Wmax(Double rW_Wmax)
  {
    this.rW_Wmax = rW_Wmax;
  }
    
  public Double getRW_Wmin() 
  {
    return rW_Wmin;
  }
    
  public void setRW_Wmin(Double rW_Wmin)
  {
    this.rW_Wmin = rW_Wmin;
  }
    
  public Double getRW_Wset1() 
  {
    return rW_Wset1;
  }
    
  public void setRW_Wset1(Double rW_Wset1)
  {
    this.rW_Wset1 = rW_Wset1;
  }
    
  public Double getRW_Wset2() 
  {
    return rW_Wset2;
  }
    
  public void setRW_Wset2(Double rW_Wset2)
  {
    this.rW_Wset2 = rW_Wset2;
  }
    
  public Double getRW_Wset3() 
  {
    return rW_Wset3;
  }
    
  public void setRW_Wset3(Double rW_Wset3)
  {
    this.rW_Wset3 = rW_Wset3;
  }
    
  public Double getRW_Wset4() 
  {
    return rW_Wset4;
  }
    
  public void setRW_Wset4(Double rW_Wset4)
  {
    this.rW_Wset4 = rW_Wset4;
  }
    
  public Double getRW_Wset5() 
  {
    return rW_Wset5;
  }
    
  public void setRW_Wset5(Double rW_Wset5)
  {
    this.rW_Wset5 = rW_Wset5;
  }
    
  public Double getRW_Wset6() 
  {
    return rW_Wset6;
  }
    
  public void setRW_Wset6(Double rW_Wset6)
  {
    this.rW_Wset6 = rW_Wset6;
  }
    
  public Double getRW_Wset7() 
  {
    return rW_Wset7;
  }
    
  public void setRW_Wset7(Double rW_Wset7)
  {
    this.rW_Wset7 = rW_Wset7;
  }
    
  public Double getRW_Wset8() 
  {
    return rW_Wset8;
  }
    
  public void setRW_Wset8(Double rW_Wset8)
  {
    this.rW_Wset8 = rW_Wset8;
  }
    
  public Double getRW_Wset9() 
  {
    return rW_Wset9;
  }
    
  public void setRW_Wset9(Double rW_Wset9)
  {
    this.rW_Wset9 = rW_Wset9;
  }
    
  public Double getRW_Wset10() 
  {
    return rW_Wset10;
  }
    
  public void setRW_Wset10(Double rW_Wset10)
  {
    this.rW_Wset10 = rW_Wset10;
  }
    
  public Double getRW_Delay1() 
  {
    return rW_Delay1;
  }
    
  public void setRW_Delay1(Double rW_Delay1)
  {
    this.rW_Delay1 = rW_Delay1;
  }
    
  public Double getRW_Delay2() 
  {
    return rW_Delay2;
  }
    
  public void setRW_Delay2(Double rW_Delay2)
  {
    this.rW_Delay2 = rW_Delay2;
  }
    
  public Double getRW_Delay3() 
  {
    return rW_Delay3;
  }
    
  public void setRW_Delay3(Double rW_Delay3)
  {
    this.rW_Delay3 = rW_Delay3;
  }
    
  public Double getRW_Delay4() 
  {
    return rW_Delay4;
  }
    
  public void setRW_Delay4(Double rW_Delay4)
  {
    this.rW_Delay4 = rW_Delay4;
  }
    
  public Double getRW_Delay5() 
  {
    return rW_Delay5;
  }
    
  public void setRW_Delay5(Double rW_Delay5)
  {
    this.rW_Delay5 = rW_Delay5;
  }
    
  public Double getRW_Delay6() 
  {
    return rW_Delay6;
  }
    
  public void setRW_Delay6(Double rW_Delay6)
  {
    this.rW_Delay6 = rW_Delay6;
  }
    
  public Double getRW_Delay7() 
  {
    return rW_Delay7;
  }
    
  public void setRW_Delay7(Double rW_Delay7)
  {
    this.rW_Delay7 = rW_Delay7;
  }
    
  public Double getRW_Delay8() 
  {
    return rW_Delay8;
  }
    
  public void setRW_Delay8(Double rW_Delay8)
  {
    this.rW_Delay8 = rW_Delay8;
  }
    
  public Double getRW_Delay9() 
  {
    return rW_Delay9;
  }
    
  public void setRW_Delay9(Double rW_Delay9)
  {
    this.rW_Delay9 = rW_Delay9;
  }
    
  public Double getRW_Delay10() 
  {
    return rW_Delay10;
  }
    
  public void setRW_Delay10(Double rW_Delay10)
  {
    this.rW_Delay10 = rW_Delay10;
  }
    
  public Double getRW_Tbrk() 
  {
    return rW_Tbrk;
  }
    
  public void setRW_Tbrk(Double rW_Tbrk)
  {
    this.rW_Tbrk = rW_Tbrk;
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
    
