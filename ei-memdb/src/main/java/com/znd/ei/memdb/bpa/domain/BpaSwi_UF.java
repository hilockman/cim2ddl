package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*自动减负荷模型(UF)	*
***********************/
public class BpaSwi_UF  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称
  private String ACBus_Name;
  
  //基准电压(kV)
  private Double ACBus_KV;
  
  //第01级减负荷时的频率(Hz)
  private Double UF_Freq01;
  
  //第02级减负荷时的频率(Hz)
  private Double UF_Freq02;
  
  //第03级减负荷时的频率(Hz)
  private Double UF_Freq03;
  
  //第04级减负荷时的频率(Hz)
  private Double UF_Freq04;
  
  //第05级减负荷时的频率(Hz)
  private Double UF_Freq05;
  
  //第06级减负荷时的频率(Hz)
  private Double UF_Freq06;
  
  //第07级减负荷时的频率(Hz)
  private Double UF_Freq07;
  
  //第08级减负荷时的频率(Hz)
  private Double UF_Freq08;
  
  //第09级减负荷时的频率(Hz)
  private Double UF_Freq09;
  
  //第10级减负荷时的频率(Hz)
  private Double UF_Freq10;
  
  //第01级减负荷前的时延(周)
  private Double UF_Delay01;
  
  //第02级减负荷前的时延(周)
  private Double UF_Delay02;
  
  //第03级减负荷前的时延(周)
  private Double UF_Delay03;
  
  //第04级减负荷前的时延(周)
  private Double UF_Delay04;
  
  //第05级减负荷前的时延(周)
  private Double UF_Delay05;
  
  //第06级减负荷前的时延(周)
  private Double UF_Delay06;
  
  //第07级减负荷前的时延(周)
  private Double UF_Delay07;
  
  //第08级减负荷前的时延(周)
  private Double UF_Delay08;
  
  //第09级减负荷前的时延(周)
  private Double UF_Delay09;
  
  //第10级减负荷前的时延(周)
  private Double UF_Delay10;
  
  //第01级初始负荷被减去的值
  private Double UF_Shed01;
  
  //第02级初始负荷被减去的值
  private Double UF_Shed02;
  
  //第03级初始负荷被减去的值
  private Double UF_Shed03;
  
  //第04级初始负荷被减去的值
  private Double UF_Shed04;
  
  //第05级初始负荷被减去的值
  private Double UF_Shed05;
  
  //第06级被减去的负荷值(MW)
  private Double UF_Shed06;
  
  //第07级被减去的负荷值(MW)
  private Double UF_Shed07;
  
  //第08级被减去的负荷值(MW)
  private Double UF_Shed08;
  
  //第09级被减去的负荷值(MW)
  private Double UF_Shed09;
  
  //第10级被减去的负荷值(MW)
  private Double UF_Shed10;
  
  //特别码W,表示以MW为单位减去负荷
  private Integer UF_W;
  
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
    
  public Double getUF_Freq01()
  {
    return UF_Freq01;
  }
    
  public void setUF_Freq01(Double UF_Freq01)
  {
    this.UF_Freq01 = UF_Freq01;
  }
    
  public Double getUF_Freq02()
  {
    return UF_Freq02;
  }
    
  public void setUF_Freq02(Double UF_Freq02)
  {
    this.UF_Freq02 = UF_Freq02;
  }
    
  public Double getUF_Freq03()
  {
    return UF_Freq03;
  }
    
  public void setUF_Freq03(Double UF_Freq03)
  {
    this.UF_Freq03 = UF_Freq03;
  }
    
  public Double getUF_Freq04()
  {
    return UF_Freq04;
  }
    
  public void setUF_Freq04(Double UF_Freq04)
  {
    this.UF_Freq04 = UF_Freq04;
  }
    
  public Double getUF_Freq05()
  {
    return UF_Freq05;
  }
    
  public void setUF_Freq05(Double UF_Freq05)
  {
    this.UF_Freq05 = UF_Freq05;
  }
    
  public Double getUF_Freq06()
  {
    return UF_Freq06;
  }
    
  public void setUF_Freq06(Double UF_Freq06)
  {
    this.UF_Freq06 = UF_Freq06;
  }
    
  public Double getUF_Freq07()
  {
    return UF_Freq07;
  }
    
  public void setUF_Freq07(Double UF_Freq07)
  {
    this.UF_Freq07 = UF_Freq07;
  }
    
  public Double getUF_Freq08()
  {
    return UF_Freq08;
  }
    
  public void setUF_Freq08(Double UF_Freq08)
  {
    this.UF_Freq08 = UF_Freq08;
  }
    
  public Double getUF_Freq09()
  {
    return UF_Freq09;
  }
    
  public void setUF_Freq09(Double UF_Freq09)
  {
    this.UF_Freq09 = UF_Freq09;
  }
    
  public Double getUF_Freq10()
  {
    return UF_Freq10;
  }
    
  public void setUF_Freq10(Double UF_Freq10)
  {
    this.UF_Freq10 = UF_Freq10;
  }
    
  public Double getUF_Delay01()
  {
    return UF_Delay01;
  }
    
  public void setUF_Delay01(Double UF_Delay01)
  {
    this.UF_Delay01 = UF_Delay01;
  }
    
  public Double getUF_Delay02()
  {
    return UF_Delay02;
  }
    
  public void setUF_Delay02(Double UF_Delay02)
  {
    this.UF_Delay02 = UF_Delay02;
  }
    
  public Double getUF_Delay03()
  {
    return UF_Delay03;
  }
    
  public void setUF_Delay03(Double UF_Delay03)
  {
    this.UF_Delay03 = UF_Delay03;
  }
    
  public Double getUF_Delay04()
  {
    return UF_Delay04;
  }
    
  public void setUF_Delay04(Double UF_Delay04)
  {
    this.UF_Delay04 = UF_Delay04;
  }
    
  public Double getUF_Delay05()
  {
    return UF_Delay05;
  }
    
  public void setUF_Delay05(Double UF_Delay05)
  {
    this.UF_Delay05 = UF_Delay05;
  }
    
  public Double getUF_Delay06()
  {
    return UF_Delay06;
  }
    
  public void setUF_Delay06(Double UF_Delay06)
  {
    this.UF_Delay06 = UF_Delay06;
  }
    
  public Double getUF_Delay07()
  {
    return UF_Delay07;
  }
    
  public void setUF_Delay07(Double UF_Delay07)
  {
    this.UF_Delay07 = UF_Delay07;
  }
    
  public Double getUF_Delay08()
  {
    return UF_Delay08;
  }
    
  public void setUF_Delay08(Double UF_Delay08)
  {
    this.UF_Delay08 = UF_Delay08;
  }
    
  public Double getUF_Delay09()
  {
    return UF_Delay09;
  }
    
  public void setUF_Delay09(Double UF_Delay09)
  {
    this.UF_Delay09 = UF_Delay09;
  }
    
  public Double getUF_Delay10()
  {
    return UF_Delay10;
  }
    
  public void setUF_Delay10(Double UF_Delay10)
  {
    this.UF_Delay10 = UF_Delay10;
  }
    
  public Double getUF_Shed01()
  {
    return UF_Shed01;
  }
    
  public void setUF_Shed01(Double UF_Shed01)
  {
    this.UF_Shed01 = UF_Shed01;
  }
    
  public Double getUF_Shed02()
  {
    return UF_Shed02;
  }
    
  public void setUF_Shed02(Double UF_Shed02)
  {
    this.UF_Shed02 = UF_Shed02;
  }
    
  public Double getUF_Shed03()
  {
    return UF_Shed03;
  }
    
  public void setUF_Shed03(Double UF_Shed03)
  {
    this.UF_Shed03 = UF_Shed03;
  }
    
  public Double getUF_Shed04()
  {
    return UF_Shed04;
  }
    
  public void setUF_Shed04(Double UF_Shed04)
  {
    this.UF_Shed04 = UF_Shed04;
  }
    
  public Double getUF_Shed05()
  {
    return UF_Shed05;
  }
    
  public void setUF_Shed05(Double UF_Shed05)
  {
    this.UF_Shed05 = UF_Shed05;
  }
    
  public Double getUF_Shed06()
  {
    return UF_Shed06;
  }
    
  public void setUF_Shed06(Double UF_Shed06)
  {
    this.UF_Shed06 = UF_Shed06;
  }
    
  public Double getUF_Shed07()
  {
    return UF_Shed07;
  }
    
  public void setUF_Shed07(Double UF_Shed07)
  {
    this.UF_Shed07 = UF_Shed07;
  }
    
  public Double getUF_Shed08()
  {
    return UF_Shed08;
  }
    
  public void setUF_Shed08(Double UF_Shed08)
  {
    this.UF_Shed08 = UF_Shed08;
  }
    
  public Double getUF_Shed09()
  {
    return UF_Shed09;
  }
    
  public void setUF_Shed09(Double UF_Shed09)
  {
    this.UF_Shed09 = UF_Shed09;
  }
    
  public Double getUF_Shed10()
  {
    return UF_Shed10;
  }
    
  public void setUF_Shed10(Double UF_Shed10)
  {
    this.UF_Shed10 = UF_Shed10;
  }
    
  public Integer getUF_W()
  {
    return UF_W;
  }
    
  public void setUF_W(Integer UF_W)
  {
    this.UF_W = UF_W;
  }
    
  public String toString()
  {
    return "BpaSwi_UF ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_KV = " + ACBus_KV
	 + ", UF_Freq01 = " + UF_Freq01
	 + ", UF_Freq02 = " + UF_Freq02
	 + ", UF_Freq03 = " + UF_Freq03
	 + ", UF_Freq04 = " + UF_Freq04
	 + ", UF_Freq05 = " + UF_Freq05
	 + ", UF_Freq06 = " + UF_Freq06
	 + ", UF_Freq07 = " + UF_Freq07
	 + ", UF_Freq08 = " + UF_Freq08
	 + ", UF_Freq09 = " + UF_Freq09
	 + ", UF_Freq10 = " + UF_Freq10
	 + ", UF_Delay01 = " + UF_Delay01
	 + ", UF_Delay02 = " + UF_Delay02
	 + ", UF_Delay03 = " + UF_Delay03
	 + ", UF_Delay04 = " + UF_Delay04
	 + ", UF_Delay05 = " + UF_Delay05
	 + ", UF_Delay06 = " + UF_Delay06
	 + ", UF_Delay07 = " + UF_Delay07
	 + ", UF_Delay08 = " + UF_Delay08
	 + ", UF_Delay09 = " + UF_Delay09
	 + ", UF_Delay10 = " + UF_Delay10
	 + ", UF_Shed01 = " + UF_Shed01
	 + ", UF_Shed02 = " + UF_Shed02
	 + ", UF_Shed03 = " + UF_Shed03
	 + ", UF_Shed04 = " + UF_Shed04
	 + ", UF_Shed05 = " + UF_Shed05
	 + ", UF_Shed06 = " + UF_Shed06
	 + ", UF_Shed07 = " + UF_Shed07
	 + ", UF_Shed08 = " + UF_Shed08
	 + ", UF_Shed09 = " + UF_Shed09
	 + ", UF_Shed10 = " + UF_Shed10
	 + ", UF_W = " + UF_W+"]";
  }
    
}
    
