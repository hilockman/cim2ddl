package com.znd.ei.memdb.bpa.domain;


/**********************
*自动减负荷模型(UF)	*
***********************/
public class BpaSwi_UF
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称
  private String aCBus_Name;
  
  //基准电压(kV)
  private Double aCBus_KV;
  
  //第01级减负荷时的频率(Hz)
  private Double uF_Freq01;
  
  //第02级减负荷时的频率(Hz)
  private Double uF_Freq02;
  
  //第03级减负荷时的频率(Hz)
  private Double uF_Freq03;
  
  //第04级减负荷时的频率(Hz)
  private Double uF_Freq04;
  
  //第05级减负荷时的频率(Hz)
  private Double uF_Freq05;
  
  //第06级减负荷时的频率(Hz)
  private Double uF_Freq06;
  
  //第07级减负荷时的频率(Hz)
  private Double uF_Freq07;
  
  //第08级减负荷时的频率(Hz)
  private Double uF_Freq08;
  
  //第09级减负荷时的频率(Hz)
  private Double uF_Freq09;
  
  //第10级减负荷时的频率(Hz)
  private Double uF_Freq10;
  
  //第01级减负荷前的时延(周)
  private Double uF_Delay01;
  
  //第02级减负荷前的时延(周)
  private Double uF_Delay02;
  
  //第03级减负荷前的时延(周)
  private Double uF_Delay03;
  
  //第04级减负荷前的时延(周)
  private Double uF_Delay04;
  
  //第05级减负荷前的时延(周)
  private Double uF_Delay05;
  
  //第06级减负荷前的时延(周)
  private Double uF_Delay06;
  
  //第07级减负荷前的时延(周)
  private Double uF_Delay07;
  
  //第08级减负荷前的时延(周)
  private Double uF_Delay08;
  
  //第09级减负荷前的时延(周)
  private Double uF_Delay09;
  
  //第10级减负荷前的时延(周)
  private Double uF_Delay10;
  
  //第01级初始负荷被减去的值
  private Double uF_Shed01;
  
  //第02级初始负荷被减去的值
  private Double uF_Shed02;
  
  //第03级初始负荷被减去的值
  private Double uF_Shed03;
  
  //第04级初始负荷被减去的值
  private Double uF_Shed04;
  
  //第05级初始负荷被减去的值
  private Double uF_Shed05;
  
  //第06级被减去的负荷值(MW)
  private Double uF_Shed06;
  
  //第07级被减去的负荷值(MW)
  private Double uF_Shed07;
  
  //第08级被减去的负荷值(MW)
  private Double uF_Shed08;
  
  //第09级被减去的负荷值(MW)
  private Double uF_Shed09;
  
  //第10级被减去的负荷值(MW)
  private Double uF_Shed10;
  
  //特别码W,表示以MW为单位减去负荷
  private Integer uF_W;
  
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
    
  public Double getUF_Freq01()
  {
    return uF_Freq01;
  }
    
  public void setUF_Freq01(Double uF_Freq01)
  {
    this.uF_Freq01 = uF_Freq01;
  }
    
  public Double getUF_Freq02()
  {
    return uF_Freq02;
  }
    
  public void setUF_Freq02(Double uF_Freq02)
  {
    this.uF_Freq02 = uF_Freq02;
  }
    
  public Double getUF_Freq03()
  {
    return uF_Freq03;
  }
    
  public void setUF_Freq03(Double uF_Freq03)
  {
    this.uF_Freq03 = uF_Freq03;
  }
    
  public Double getUF_Freq04()
  {
    return uF_Freq04;
  }
    
  public void setUF_Freq04(Double uF_Freq04)
  {
    this.uF_Freq04 = uF_Freq04;
  }
    
  public Double getUF_Freq05()
  {
    return uF_Freq05;
  }
    
  public void setUF_Freq05(Double uF_Freq05)
  {
    this.uF_Freq05 = uF_Freq05;
  }
    
  public Double getUF_Freq06()
  {
    return uF_Freq06;
  }
    
  public void setUF_Freq06(Double uF_Freq06)
  {
    this.uF_Freq06 = uF_Freq06;
  }
    
  public Double getUF_Freq07()
  {
    return uF_Freq07;
  }
    
  public void setUF_Freq07(Double uF_Freq07)
  {
    this.uF_Freq07 = uF_Freq07;
  }
    
  public Double getUF_Freq08()
  {
    return uF_Freq08;
  }
    
  public void setUF_Freq08(Double uF_Freq08)
  {
    this.uF_Freq08 = uF_Freq08;
  }
    
  public Double getUF_Freq09()
  {
    return uF_Freq09;
  }
    
  public void setUF_Freq09(Double uF_Freq09)
  {
    this.uF_Freq09 = uF_Freq09;
  }
    
  public Double getUF_Freq10()
  {
    return uF_Freq10;
  }
    
  public void setUF_Freq10(Double uF_Freq10)
  {
    this.uF_Freq10 = uF_Freq10;
  }
    
  public Double getUF_Delay01()
  {
    return uF_Delay01;
  }
    
  public void setUF_Delay01(Double uF_Delay01)
  {
    this.uF_Delay01 = uF_Delay01;
  }
    
  public Double getUF_Delay02()
  {
    return uF_Delay02;
  }
    
  public void setUF_Delay02(Double uF_Delay02)
  {
    this.uF_Delay02 = uF_Delay02;
  }
    
  public Double getUF_Delay03()
  {
    return uF_Delay03;
  }
    
  public void setUF_Delay03(Double uF_Delay03)
  {
    this.uF_Delay03 = uF_Delay03;
  }
    
  public Double getUF_Delay04()
  {
    return uF_Delay04;
  }
    
  public void setUF_Delay04(Double uF_Delay04)
  {
    this.uF_Delay04 = uF_Delay04;
  }
    
  public Double getUF_Delay05()
  {
    return uF_Delay05;
  }
    
  public void setUF_Delay05(Double uF_Delay05)
  {
    this.uF_Delay05 = uF_Delay05;
  }
    
  public Double getUF_Delay06()
  {
    return uF_Delay06;
  }
    
  public void setUF_Delay06(Double uF_Delay06)
  {
    this.uF_Delay06 = uF_Delay06;
  }
    
  public Double getUF_Delay07()
  {
    return uF_Delay07;
  }
    
  public void setUF_Delay07(Double uF_Delay07)
  {
    this.uF_Delay07 = uF_Delay07;
  }
    
  public Double getUF_Delay08()
  {
    return uF_Delay08;
  }
    
  public void setUF_Delay08(Double uF_Delay08)
  {
    this.uF_Delay08 = uF_Delay08;
  }
    
  public Double getUF_Delay09()
  {
    return uF_Delay09;
  }
    
  public void setUF_Delay09(Double uF_Delay09)
  {
    this.uF_Delay09 = uF_Delay09;
  }
    
  public Double getUF_Delay10()
  {
    return uF_Delay10;
  }
    
  public void setUF_Delay10(Double uF_Delay10)
  {
    this.uF_Delay10 = uF_Delay10;
  }
    
  public Double getUF_Shed01()
  {
    return uF_Shed01;
  }
    
  public void setUF_Shed01(Double uF_Shed01)
  {
    this.uF_Shed01 = uF_Shed01;
  }
    
  public Double getUF_Shed02()
  {
    return uF_Shed02;
  }
    
  public void setUF_Shed02(Double uF_Shed02)
  {
    this.uF_Shed02 = uF_Shed02;
  }
    
  public Double getUF_Shed03()
  {
    return uF_Shed03;
  }
    
  public void setUF_Shed03(Double uF_Shed03)
  {
    this.uF_Shed03 = uF_Shed03;
  }
    
  public Double getUF_Shed04()
  {
    return uF_Shed04;
  }
    
  public void setUF_Shed04(Double uF_Shed04)
  {
    this.uF_Shed04 = uF_Shed04;
  }
    
  public Double getUF_Shed05()
  {
    return uF_Shed05;
  }
    
  public void setUF_Shed05(Double uF_Shed05)
  {
    this.uF_Shed05 = uF_Shed05;
  }
    
  public Double getUF_Shed06()
  {
    return uF_Shed06;
  }
    
  public void setUF_Shed06(Double uF_Shed06)
  {
    this.uF_Shed06 = uF_Shed06;
  }
    
  public Double getUF_Shed07()
  {
    return uF_Shed07;
  }
    
  public void setUF_Shed07(Double uF_Shed07)
  {
    this.uF_Shed07 = uF_Shed07;
  }
    
  public Double getUF_Shed08()
  {
    return uF_Shed08;
  }
    
  public void setUF_Shed08(Double uF_Shed08)
  {
    this.uF_Shed08 = uF_Shed08;
  }
    
  public Double getUF_Shed09()
  {
    return uF_Shed09;
  }
    
  public void setUF_Shed09(Double uF_Shed09)
  {
    this.uF_Shed09 = uF_Shed09;
  }
    
  public Double getUF_Shed10()
  {
    return uF_Shed10;
  }
    
  public void setUF_Shed10(Double uF_Shed10)
  {
    this.uF_Shed10 = uF_Shed10;
  }
    
  public Integer getUF_W()
  {
    return uF_W;
  }
    
  public void setUF_W(Integer uF_W)
  {
    this.uF_W = uF_W;
  }
    
  public String toString()
  {
    return "BpaSwi_UF ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_KV = " + aCBus_KV
	 + ", uF_Freq01 = " + uF_Freq01
	 + ", uF_Freq02 = " + uF_Freq02
	 + ", uF_Freq03 = " + uF_Freq03
	 + ", uF_Freq04 = " + uF_Freq04
	 + ", uF_Freq05 = " + uF_Freq05
	 + ", uF_Freq06 = " + uF_Freq06
	 + ", uF_Freq07 = " + uF_Freq07
	 + ", uF_Freq08 = " + uF_Freq08
	 + ", uF_Freq09 = " + uF_Freq09
	 + ", uF_Freq10 = " + uF_Freq10
	 + ", uF_Delay01 = " + uF_Delay01
	 + ", uF_Delay02 = " + uF_Delay02
	 + ", uF_Delay03 = " + uF_Delay03
	 + ", uF_Delay04 = " + uF_Delay04
	 + ", uF_Delay05 = " + uF_Delay05
	 + ", uF_Delay06 = " + uF_Delay06
	 + ", uF_Delay07 = " + uF_Delay07
	 + ", uF_Delay08 = " + uF_Delay08
	 + ", uF_Delay09 = " + uF_Delay09
	 + ", uF_Delay10 = " + uF_Delay10
	 + ", uF_Shed01 = " + uF_Shed01
	 + ", uF_Shed02 = " + uF_Shed02
	 + ", uF_Shed03 = " + uF_Shed03
	 + ", uF_Shed04 = " + uF_Shed04
	 + ", uF_Shed05 = " + uF_Shed05
	 + ", uF_Shed06 = " + uF_Shed06
	 + ", uF_Shed07 = " + uF_Shed07
	 + ", uF_Shed08 = " + uF_Shed08
	 + ", uF_Shed09 = " + uF_Shed09
	 + ", uF_Shed10 = " + uF_Shed10
	 + ", uF_W = " + uF_W+"]";
  }
    
}
    
