package com.znd.ei.memdb.bpa.domain;


/**********************
*自动减负荷模型(UV)	*
***********************/
public class BpaSwi_UV
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称
  private String aCBus_Name;
  
  //基准电压(kV)
  private Double aCBus_KV;
  
  //第01级减负荷时的电压(PU)
  private Double uV_Volt01;
  
  //第02级减负荷时的电压(PU)
  private Double uV_Volt02;
  
  //第03级减负荷时的电压(PU)
  private Double uV_Volt03;
  
  //第04级减负荷时的电压(PU)
  private Double uV_Volt04;
  
  //第05级减负荷时的电压(PU)
  private Double uV_Volt05;
  
  //第06级减负荷时的电压(pu)
  private Double uV_Volt06;
  
  //第07级减负荷时的电压(pu)
  private Double uV_Volt07;
  
  //第08级减负荷时的电压(pu)
  private Double uV_Volt08;
  
  //第09级减负荷时的电压(pu)
  private Double uV_Volt09;
  
  //第10级减负荷时的电压(pu)
  private Double uV_Volt10;
  
  //第01级减负荷前的时延(周)
  private Double uV_Delay01;
  
  //第02级减负荷前的时延(周)
  private Double uV_Delay02;
  
  //第03级减负荷前的时延(周)
  private Double uV_Delay03;
  
  //第04级减负荷前的时延(周)
  private Double uV_Delay04;
  
  //第05级减负荷前的时延(周)
  private Double uV_Delay05;
  
  //第06级减负荷前的时延(周)
  private Double uV_Delay06;
  
  //第07级减负荷前的时延(周)
  private Double uV_Delay07;
  
  //第08级减负荷前的时延(周)
  private Double uV_Delay08;
  
  //第09级减负荷前的时延(周)
  private Double uV_Delay09;
  
  //第10级减负荷前的时延(周)
  private Double uV_Delay10;
  
  //第01级初始负荷被减去的值
  private Double uV_Shed01;
  
  //第02级初始负荷被减去的值
  private Double uV_Shed02;
  
  //第03级初始负荷被减去的值
  private Double uV_Shed03;
  
  //第04级初始负荷被减去的值
  private Double uV_Shed04;
  
  //第05级初始负荷被减去的值
  private Double uV_Shed05;
  
  //第06级被减去的负荷值(MW)
  private Double uV_Shed06;
  
  //第07级被减去的负荷值(MW)
  private Double uV_Shed07;
  
  //第08级被减去的负荷值(MW)
  private Double uV_Shed08;
  
  //第09级被减去的负荷值(MW)
  private Double uV_Shed09;
  
  //第10级被减去的负荷值(MW)
  private Double uV_Shed10;
  
  //特别码W,表示以MW为单位减去负荷
  private Integer uV_W;
  
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
    
  public Double getUV_Volt01()
  {
    return uV_Volt01;
  }
    
  public void setUV_Volt01(Double uV_Volt01)
  {
    this.uV_Volt01 = uV_Volt01;
  }
    
  public Double getUV_Volt02()
  {
    return uV_Volt02;
  }
    
  public void setUV_Volt02(Double uV_Volt02)
  {
    this.uV_Volt02 = uV_Volt02;
  }
    
  public Double getUV_Volt03()
  {
    return uV_Volt03;
  }
    
  public void setUV_Volt03(Double uV_Volt03)
  {
    this.uV_Volt03 = uV_Volt03;
  }
    
  public Double getUV_Volt04()
  {
    return uV_Volt04;
  }
    
  public void setUV_Volt04(Double uV_Volt04)
  {
    this.uV_Volt04 = uV_Volt04;
  }
    
  public Double getUV_Volt05()
  {
    return uV_Volt05;
  }
    
  public void setUV_Volt05(Double uV_Volt05)
  {
    this.uV_Volt05 = uV_Volt05;
  }
    
  public Double getUV_Volt06()
  {
    return uV_Volt06;
  }
    
  public void setUV_Volt06(Double uV_Volt06)
  {
    this.uV_Volt06 = uV_Volt06;
  }
    
  public Double getUV_Volt07()
  {
    return uV_Volt07;
  }
    
  public void setUV_Volt07(Double uV_Volt07)
  {
    this.uV_Volt07 = uV_Volt07;
  }
    
  public Double getUV_Volt08()
  {
    return uV_Volt08;
  }
    
  public void setUV_Volt08(Double uV_Volt08)
  {
    this.uV_Volt08 = uV_Volt08;
  }
    
  public Double getUV_Volt09()
  {
    return uV_Volt09;
  }
    
  public void setUV_Volt09(Double uV_Volt09)
  {
    this.uV_Volt09 = uV_Volt09;
  }
    
  public Double getUV_Volt10()
  {
    return uV_Volt10;
  }
    
  public void setUV_Volt10(Double uV_Volt10)
  {
    this.uV_Volt10 = uV_Volt10;
  }
    
  public Double getUV_Delay01()
  {
    return uV_Delay01;
  }
    
  public void setUV_Delay01(Double uV_Delay01)
  {
    this.uV_Delay01 = uV_Delay01;
  }
    
  public Double getUV_Delay02()
  {
    return uV_Delay02;
  }
    
  public void setUV_Delay02(Double uV_Delay02)
  {
    this.uV_Delay02 = uV_Delay02;
  }
    
  public Double getUV_Delay03()
  {
    return uV_Delay03;
  }
    
  public void setUV_Delay03(Double uV_Delay03)
  {
    this.uV_Delay03 = uV_Delay03;
  }
    
  public Double getUV_Delay04()
  {
    return uV_Delay04;
  }
    
  public void setUV_Delay04(Double uV_Delay04)
  {
    this.uV_Delay04 = uV_Delay04;
  }
    
  public Double getUV_Delay05()
  {
    return uV_Delay05;
  }
    
  public void setUV_Delay05(Double uV_Delay05)
  {
    this.uV_Delay05 = uV_Delay05;
  }
    
  public Double getUV_Delay06()
  {
    return uV_Delay06;
  }
    
  public void setUV_Delay06(Double uV_Delay06)
  {
    this.uV_Delay06 = uV_Delay06;
  }
    
  public Double getUV_Delay07()
  {
    return uV_Delay07;
  }
    
  public void setUV_Delay07(Double uV_Delay07)
  {
    this.uV_Delay07 = uV_Delay07;
  }
    
  public Double getUV_Delay08()
  {
    return uV_Delay08;
  }
    
  public void setUV_Delay08(Double uV_Delay08)
  {
    this.uV_Delay08 = uV_Delay08;
  }
    
  public Double getUV_Delay09()
  {
    return uV_Delay09;
  }
    
  public void setUV_Delay09(Double uV_Delay09)
  {
    this.uV_Delay09 = uV_Delay09;
  }
    
  public Double getUV_Delay10()
  {
    return uV_Delay10;
  }
    
  public void setUV_Delay10(Double uV_Delay10)
  {
    this.uV_Delay10 = uV_Delay10;
  }
    
  public Double getUV_Shed01()
  {
    return uV_Shed01;
  }
    
  public void setUV_Shed01(Double uV_Shed01)
  {
    this.uV_Shed01 = uV_Shed01;
  }
    
  public Double getUV_Shed02()
  {
    return uV_Shed02;
  }
    
  public void setUV_Shed02(Double uV_Shed02)
  {
    this.uV_Shed02 = uV_Shed02;
  }
    
  public Double getUV_Shed03()
  {
    return uV_Shed03;
  }
    
  public void setUV_Shed03(Double uV_Shed03)
  {
    this.uV_Shed03 = uV_Shed03;
  }
    
  public Double getUV_Shed04()
  {
    return uV_Shed04;
  }
    
  public void setUV_Shed04(Double uV_Shed04)
  {
    this.uV_Shed04 = uV_Shed04;
  }
    
  public Double getUV_Shed05()
  {
    return uV_Shed05;
  }
    
  public void setUV_Shed05(Double uV_Shed05)
  {
    this.uV_Shed05 = uV_Shed05;
  }
    
  public Double getUV_Shed06()
  {
    return uV_Shed06;
  }
    
  public void setUV_Shed06(Double uV_Shed06)
  {
    this.uV_Shed06 = uV_Shed06;
  }
    
  public Double getUV_Shed07()
  {
    return uV_Shed07;
  }
    
  public void setUV_Shed07(Double uV_Shed07)
  {
    this.uV_Shed07 = uV_Shed07;
  }
    
  public Double getUV_Shed08()
  {
    return uV_Shed08;
  }
    
  public void setUV_Shed08(Double uV_Shed08)
  {
    this.uV_Shed08 = uV_Shed08;
  }
    
  public Double getUV_Shed09()
  {
    return uV_Shed09;
  }
    
  public void setUV_Shed09(Double uV_Shed09)
  {
    this.uV_Shed09 = uV_Shed09;
  }
    
  public Double getUV_Shed10()
  {
    return uV_Shed10;
  }
    
  public void setUV_Shed10(Double uV_Shed10)
  {
    this.uV_Shed10 = uV_Shed10;
  }
    
  public Integer getUV_W()
  {
    return uV_W;
  }
    
  public void setUV_W(Integer uV_W)
  {
    this.uV_W = uV_W;
  }
    
  public String toString()
  {
    return "BpaSwi_UV ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_KV = " + aCBus_KV
	 + ", uV_Volt01 = " + uV_Volt01
	 + ", uV_Volt02 = " + uV_Volt02
	 + ", uV_Volt03 = " + uV_Volt03
	 + ", uV_Volt04 = " + uV_Volt04
	 + ", uV_Volt05 = " + uV_Volt05
	 + ", uV_Volt06 = " + uV_Volt06
	 + ", uV_Volt07 = " + uV_Volt07
	 + ", uV_Volt08 = " + uV_Volt08
	 + ", uV_Volt09 = " + uV_Volt09
	 + ", uV_Volt10 = " + uV_Volt10
	 + ", uV_Delay01 = " + uV_Delay01
	 + ", uV_Delay02 = " + uV_Delay02
	 + ", uV_Delay03 = " + uV_Delay03
	 + ", uV_Delay04 = " + uV_Delay04
	 + ", uV_Delay05 = " + uV_Delay05
	 + ", uV_Delay06 = " + uV_Delay06
	 + ", uV_Delay07 = " + uV_Delay07
	 + ", uV_Delay08 = " + uV_Delay08
	 + ", uV_Delay09 = " + uV_Delay09
	 + ", uV_Delay10 = " + uV_Delay10
	 + ", uV_Shed01 = " + uV_Shed01
	 + ", uV_Shed02 = " + uV_Shed02
	 + ", uV_Shed03 = " + uV_Shed03
	 + ", uV_Shed04 = " + uV_Shed04
	 + ", uV_Shed05 = " + uV_Shed05
	 + ", uV_Shed06 = " + uV_Shed06
	 + ", uV_Shed07 = " + uV_Shed07
	 + ", uV_Shed08 = " + uV_Shed08
	 + ", uV_Shed09 = " + uV_Shed09
	 + ", uV_Shed10 = " + uV_Shed10
	 + ", uV_W = " + uV_W+"]";
  }
    
}
    
