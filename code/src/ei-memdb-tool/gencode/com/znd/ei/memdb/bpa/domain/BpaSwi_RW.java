package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*发电机转速保护(RW)	*
***********************/
public class BpaSwi_RW  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称
  private String ACBus_Name;
  
  //基准电压(kV)	
  private Double ACBus_KV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //发电机立即跳闸的最大转速(pu)
  private Double RW_Wmax;
  
  //发电机立即跳闸的最小转速(pu)
  private Double RW_Wmin;
  
  //发电机转速设定值1(pu)
  private Double RW_Wset1;
  
  //发电机转速设定值2(pu)
  private Double RW_Wset2;
  
  //发电机转速设定值3(pu)
  private Double RW_Wset3;
  
  //发电机转速设定值4(pu)
  private Double RW_Wset4;
  
  //发电机转速设定值5(pu)
  private Double RW_Wset5;
  
  //发电机转速设定值6(pu)
  private Double RW_Wset6;
  
  //发电机转速设定值7(pu)
  private Double RW_Wset7;
  
  //发电机转速设定值8(pu)
  private Double RW_Wset8;
  
  //发电机转速设定值9(pu)
  private Double RW_Wset9;
  
  //发电机转速设定值10(pu)
  private Double RW_Wset10;
  
  //发电机转速设定值1对应的时迟(周)
  private Double RW_Delay1;
  
  //发电机转速设定值2对应的时迟(周)
  private Double RW_Delay2;
  
  //发电机转速设定值3对应的时迟(周)
  private Double RW_Delay3;
  
  //发电机转速设定值4对应的时迟(周)
  private Double RW_Delay4;
  
  //发电机转速设定值5对应的时迟(周)
  private Double RW_Delay5;
  
  //发电机转速设定值6对应的时迟(周)
  private Double RW_Delay6;
  
  //发电机转速设定值7对应的时迟(周)
  private Double RW_Delay7;
  
  //发电机转速设定值8对应的时迟(周)
  private Double RW_Delay8;
  
  //发电机转速设定值9对应的时迟(周)
  private Double RW_Delay9;
  
  //发电机转速设定值10对应的时迟(周)
  private Double RW_Delay10;
  
  //继电器动作时间(周)
  private Double RW_Tbrk;
  
  //发电机母线索引
  private Integer BusPtr;
  
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
    return CardKey;
  }
    
  public void setCardKey(String CardKey)
  {
    this.CardKey = CardKey;
  }
    
  public String getACBus_Name()
  {
    return ACBus_Name;
  }
    
  public void setACBus_Name(String ACBus_Name)
  {
    this.ACBus_Name = ACBus_Name;
  }
    
  public Double getACBus_KV()
  {
    return ACBus_KV;
  }
    
  public void setACBus_KV(Double ACBus_KV)
  {
    this.ACBus_KV = ACBus_KV;
  }
    
  public Integer getGen_ID()
  {
    return Gen_ID;
  }
    
  public void setGen_ID(Integer Gen_ID)
  {
    this.Gen_ID = Gen_ID;
  }
    
  public Double getRW_Wmax()
  {
    return RW_Wmax;
  }
    
  public void setRW_Wmax(Double RW_Wmax)
  {
    this.RW_Wmax = RW_Wmax;
  }
    
  public Double getRW_Wmin()
  {
    return RW_Wmin;
  }
    
  public void setRW_Wmin(Double RW_Wmin)
  {
    this.RW_Wmin = RW_Wmin;
  }
    
  public Double getRW_Wset1()
  {
    return RW_Wset1;
  }
    
  public void setRW_Wset1(Double RW_Wset1)
  {
    this.RW_Wset1 = RW_Wset1;
  }
    
  public Double getRW_Wset2()
  {
    return RW_Wset2;
  }
    
  public void setRW_Wset2(Double RW_Wset2)
  {
    this.RW_Wset2 = RW_Wset2;
  }
    
  public Double getRW_Wset3()
  {
    return RW_Wset3;
  }
    
  public void setRW_Wset3(Double RW_Wset3)
  {
    this.RW_Wset3 = RW_Wset3;
  }
    
  public Double getRW_Wset4()
  {
    return RW_Wset4;
  }
    
  public void setRW_Wset4(Double RW_Wset4)
  {
    this.RW_Wset4 = RW_Wset4;
  }
    
  public Double getRW_Wset5()
  {
    return RW_Wset5;
  }
    
  public void setRW_Wset5(Double RW_Wset5)
  {
    this.RW_Wset5 = RW_Wset5;
  }
    
  public Double getRW_Wset6()
  {
    return RW_Wset6;
  }
    
  public void setRW_Wset6(Double RW_Wset6)
  {
    this.RW_Wset6 = RW_Wset6;
  }
    
  public Double getRW_Wset7()
  {
    return RW_Wset7;
  }
    
  public void setRW_Wset7(Double RW_Wset7)
  {
    this.RW_Wset7 = RW_Wset7;
  }
    
  public Double getRW_Wset8()
  {
    return RW_Wset8;
  }
    
  public void setRW_Wset8(Double RW_Wset8)
  {
    this.RW_Wset8 = RW_Wset8;
  }
    
  public Double getRW_Wset9()
  {
    return RW_Wset9;
  }
    
  public void setRW_Wset9(Double RW_Wset9)
  {
    this.RW_Wset9 = RW_Wset9;
  }
    
  public Double getRW_Wset10()
  {
    return RW_Wset10;
  }
    
  public void setRW_Wset10(Double RW_Wset10)
  {
    this.RW_Wset10 = RW_Wset10;
  }
    
  public Double getRW_Delay1()
  {
    return RW_Delay1;
  }
    
  public void setRW_Delay1(Double RW_Delay1)
  {
    this.RW_Delay1 = RW_Delay1;
  }
    
  public Double getRW_Delay2()
  {
    return RW_Delay2;
  }
    
  public void setRW_Delay2(Double RW_Delay2)
  {
    this.RW_Delay2 = RW_Delay2;
  }
    
  public Double getRW_Delay3()
  {
    return RW_Delay3;
  }
    
  public void setRW_Delay3(Double RW_Delay3)
  {
    this.RW_Delay3 = RW_Delay3;
  }
    
  public Double getRW_Delay4()
  {
    return RW_Delay4;
  }
    
  public void setRW_Delay4(Double RW_Delay4)
  {
    this.RW_Delay4 = RW_Delay4;
  }
    
  public Double getRW_Delay5()
  {
    return RW_Delay5;
  }
    
  public void setRW_Delay5(Double RW_Delay5)
  {
    this.RW_Delay5 = RW_Delay5;
  }
    
  public Double getRW_Delay6()
  {
    return RW_Delay6;
  }
    
  public void setRW_Delay6(Double RW_Delay6)
  {
    this.RW_Delay6 = RW_Delay6;
  }
    
  public Double getRW_Delay7()
  {
    return RW_Delay7;
  }
    
  public void setRW_Delay7(Double RW_Delay7)
  {
    this.RW_Delay7 = RW_Delay7;
  }
    
  public Double getRW_Delay8()
  {
    return RW_Delay8;
  }
    
  public void setRW_Delay8(Double RW_Delay8)
  {
    this.RW_Delay8 = RW_Delay8;
  }
    
  public Double getRW_Delay9()
  {
    return RW_Delay9;
  }
    
  public void setRW_Delay9(Double RW_Delay9)
  {
    this.RW_Delay9 = RW_Delay9;
  }
    
  public Double getRW_Delay10()
  {
    return RW_Delay10;
  }
    
  public void setRW_Delay10(Double RW_Delay10)
  {
    this.RW_Delay10 = RW_Delay10;
  }
    
  public Double getRW_Tbrk()
  {
    return RW_Tbrk;
  }
    
  public void setRW_Tbrk(Double RW_Tbrk)
  {
    this.RW_Tbrk = RW_Tbrk;
  }
    
  public Integer getBusPtr()
  {
    return BusPtr;
  }
    
  public void setBusPtr(Integer BusPtr)
  {
    this.BusPtr = BusPtr;
  }
    
  public String toString()
  {
    return "BpaSwi_RW ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_KV = " + ACBus_KV
	 + ", Gen_ID = " + Gen_ID
	 + ", RW_Wmax = " + RW_Wmax
	 + ", RW_Wmin = " + RW_Wmin
	 + ", RW_Wset1 = " + RW_Wset1
	 + ", RW_Wset2 = " + RW_Wset2
	 + ", RW_Wset3 = " + RW_Wset3
	 + ", RW_Wset4 = " + RW_Wset4
	 + ", RW_Wset5 = " + RW_Wset5
	 + ", RW_Wset6 = " + RW_Wset6
	 + ", RW_Wset7 = " + RW_Wset7
	 + ", RW_Wset8 = " + RW_Wset8
	 + ", RW_Wset9 = " + RW_Wset9
	 + ", RW_Wset10 = " + RW_Wset10
	 + ", RW_Delay1 = " + RW_Delay1
	 + ", RW_Delay2 = " + RW_Delay2
	 + ", RW_Delay3 = " + RW_Delay3
	 + ", RW_Delay4 = " + RW_Delay4
	 + ", RW_Delay5 = " + RW_Delay5
	 + ", RW_Delay6 = " + RW_Delay6
	 + ", RW_Delay7 = " + RW_Delay7
	 + ", RW_Delay8 = " + RW_Delay8
	 + ", RW_Delay9 = " + RW_Delay9
	 + ", RW_Delay10 = " + RW_Delay10
	 + ", RW_Tbrk = " + RW_Tbrk
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
