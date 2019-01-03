package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*自动减负荷模型(UV)	*
***********************/
public class BpaSwi_UV  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称
  private String ACBus_Name;
  
  //基准电压(kV)
  private Double ACBus_KV;
  
  //第01级减负荷时的电压(PU)
  private Double UV_Volt01;
  
  //第02级减负荷时的电压(PU)
  private Double UV_Volt02;
  
  //第03级减负荷时的电压(PU)
  private Double UV_Volt03;
  
  //第04级减负荷时的电压(PU)
  private Double UV_Volt04;
  
  //第05级减负荷时的电压(PU)
  private Double UV_Volt05;
  
  //第06级减负荷时的电压(pu)
  private Double UV_Volt06;
  
  //第07级减负荷时的电压(pu)
  private Double UV_Volt07;
  
  //第08级减负荷时的电压(pu)
  private Double UV_Volt08;
  
  //第09级减负荷时的电压(pu)
  private Double UV_Volt09;
  
  //第10级减负荷时的电压(pu)
  private Double UV_Volt10;
  
  //第01级减负荷前的时延(周)
  private Double UV_Delay01;
  
  //第02级减负荷前的时延(周)
  private Double UV_Delay02;
  
  //第03级减负荷前的时延(周)
  private Double UV_Delay03;
  
  //第04级减负荷前的时延(周)
  private Double UV_Delay04;
  
  //第05级减负荷前的时延(周)
  private Double UV_Delay05;
  
  //第06级减负荷前的时延(周)
  private Double UV_Delay06;
  
  //第07级减负荷前的时延(周)
  private Double UV_Delay07;
  
  //第08级减负荷前的时延(周)
  private Double UV_Delay08;
  
  //第09级减负荷前的时延(周)
  private Double UV_Delay09;
  
  //第10级减负荷前的时延(周)
  private Double UV_Delay10;
  
  //第01级初始负荷被减去的值
  private Double UV_Shed01;
  
  //第02级初始负荷被减去的值
  private Double UV_Shed02;
  
  //第03级初始负荷被减去的值
  private Double UV_Shed03;
  
  //第04级初始负荷被减去的值
  private Double UV_Shed04;
  
  //第05级初始负荷被减去的值
  private Double UV_Shed05;
  
  //第06级被减去的负荷值(MW)
  private Double UV_Shed06;
  
  //第07级被减去的负荷值(MW)
  private Double UV_Shed07;
  
  //第08级被减去的负荷值(MW)
  private Double UV_Shed08;
  
  //第09级被减去的负荷值(MW)
  private Double UV_Shed09;
  
  //第10级被减去的负荷值(MW)
  private Double UV_Shed10;
  
  //特别码W,表示以MW为单位减去负荷
  private Integer UV_W;
  
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
    
  public Double getUV_Volt01()
  {
    return UV_Volt01;
  }
    
  public void setUV_Volt01(Double UV_Volt01)
  {
    this.UV_Volt01 = UV_Volt01;
  }
    
  public Double getUV_Volt02()
  {
    return UV_Volt02;
  }
    
  public void setUV_Volt02(Double UV_Volt02)
  {
    this.UV_Volt02 = UV_Volt02;
  }
    
  public Double getUV_Volt03()
  {
    return UV_Volt03;
  }
    
  public void setUV_Volt03(Double UV_Volt03)
  {
    this.UV_Volt03 = UV_Volt03;
  }
    
  public Double getUV_Volt04()
  {
    return UV_Volt04;
  }
    
  public void setUV_Volt04(Double UV_Volt04)
  {
    this.UV_Volt04 = UV_Volt04;
  }
    
  public Double getUV_Volt05()
  {
    return UV_Volt05;
  }
    
  public void setUV_Volt05(Double UV_Volt05)
  {
    this.UV_Volt05 = UV_Volt05;
  }
    
  public Double getUV_Volt06()
  {
    return UV_Volt06;
  }
    
  public void setUV_Volt06(Double UV_Volt06)
  {
    this.UV_Volt06 = UV_Volt06;
  }
    
  public Double getUV_Volt07()
  {
    return UV_Volt07;
  }
    
  public void setUV_Volt07(Double UV_Volt07)
  {
    this.UV_Volt07 = UV_Volt07;
  }
    
  public Double getUV_Volt08()
  {
    return UV_Volt08;
  }
    
  public void setUV_Volt08(Double UV_Volt08)
  {
    this.UV_Volt08 = UV_Volt08;
  }
    
  public Double getUV_Volt09()
  {
    return UV_Volt09;
  }
    
  public void setUV_Volt09(Double UV_Volt09)
  {
    this.UV_Volt09 = UV_Volt09;
  }
    
  public Double getUV_Volt10()
  {
    return UV_Volt10;
  }
    
  public void setUV_Volt10(Double UV_Volt10)
  {
    this.UV_Volt10 = UV_Volt10;
  }
    
  public Double getUV_Delay01()
  {
    return UV_Delay01;
  }
    
  public void setUV_Delay01(Double UV_Delay01)
  {
    this.UV_Delay01 = UV_Delay01;
  }
    
  public Double getUV_Delay02()
  {
    return UV_Delay02;
  }
    
  public void setUV_Delay02(Double UV_Delay02)
  {
    this.UV_Delay02 = UV_Delay02;
  }
    
  public Double getUV_Delay03()
  {
    return UV_Delay03;
  }
    
  public void setUV_Delay03(Double UV_Delay03)
  {
    this.UV_Delay03 = UV_Delay03;
  }
    
  public Double getUV_Delay04()
  {
    return UV_Delay04;
  }
    
  public void setUV_Delay04(Double UV_Delay04)
  {
    this.UV_Delay04 = UV_Delay04;
  }
    
  public Double getUV_Delay05()
  {
    return UV_Delay05;
  }
    
  public void setUV_Delay05(Double UV_Delay05)
  {
    this.UV_Delay05 = UV_Delay05;
  }
    
  public Double getUV_Delay06()
  {
    return UV_Delay06;
  }
    
  public void setUV_Delay06(Double UV_Delay06)
  {
    this.UV_Delay06 = UV_Delay06;
  }
    
  public Double getUV_Delay07()
  {
    return UV_Delay07;
  }
    
  public void setUV_Delay07(Double UV_Delay07)
  {
    this.UV_Delay07 = UV_Delay07;
  }
    
  public Double getUV_Delay08()
  {
    return UV_Delay08;
  }
    
  public void setUV_Delay08(Double UV_Delay08)
  {
    this.UV_Delay08 = UV_Delay08;
  }
    
  public Double getUV_Delay09()
  {
    return UV_Delay09;
  }
    
  public void setUV_Delay09(Double UV_Delay09)
  {
    this.UV_Delay09 = UV_Delay09;
  }
    
  public Double getUV_Delay10()
  {
    return UV_Delay10;
  }
    
  public void setUV_Delay10(Double UV_Delay10)
  {
    this.UV_Delay10 = UV_Delay10;
  }
    
  public Double getUV_Shed01()
  {
    return UV_Shed01;
  }
    
  public void setUV_Shed01(Double UV_Shed01)
  {
    this.UV_Shed01 = UV_Shed01;
  }
    
  public Double getUV_Shed02()
  {
    return UV_Shed02;
  }
    
  public void setUV_Shed02(Double UV_Shed02)
  {
    this.UV_Shed02 = UV_Shed02;
  }
    
  public Double getUV_Shed03()
  {
    return UV_Shed03;
  }
    
  public void setUV_Shed03(Double UV_Shed03)
  {
    this.UV_Shed03 = UV_Shed03;
  }
    
  public Double getUV_Shed04()
  {
    return UV_Shed04;
  }
    
  public void setUV_Shed04(Double UV_Shed04)
  {
    this.UV_Shed04 = UV_Shed04;
  }
    
  public Double getUV_Shed05()
  {
    return UV_Shed05;
  }
    
  public void setUV_Shed05(Double UV_Shed05)
  {
    this.UV_Shed05 = UV_Shed05;
  }
    
  public Double getUV_Shed06()
  {
    return UV_Shed06;
  }
    
  public void setUV_Shed06(Double UV_Shed06)
  {
    this.UV_Shed06 = UV_Shed06;
  }
    
  public Double getUV_Shed07()
  {
    return UV_Shed07;
  }
    
  public void setUV_Shed07(Double UV_Shed07)
  {
    this.UV_Shed07 = UV_Shed07;
  }
    
  public Double getUV_Shed08()
  {
    return UV_Shed08;
  }
    
  public void setUV_Shed08(Double UV_Shed08)
  {
    this.UV_Shed08 = UV_Shed08;
  }
    
  public Double getUV_Shed09()
  {
    return UV_Shed09;
  }
    
  public void setUV_Shed09(Double UV_Shed09)
  {
    this.UV_Shed09 = UV_Shed09;
  }
    
  public Double getUV_Shed10()
  {
    return UV_Shed10;
  }
    
  public void setUV_Shed10(Double UV_Shed10)
  {
    this.UV_Shed10 = UV_Shed10;
  }
    
  public Integer getUV_W()
  {
    return UV_W;
  }
    
  public void setUV_W(Integer UV_W)
  {
    this.UV_W = UV_W;
  }
    
  public String toString()
  {
    return "BpaSwi_UV ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_KV = " + ACBus_KV
	 + ", UV_Volt01 = " + UV_Volt01
	 + ", UV_Volt02 = " + UV_Volt02
	 + ", UV_Volt03 = " + UV_Volt03
	 + ", UV_Volt04 = " + UV_Volt04
	 + ", UV_Volt05 = " + UV_Volt05
	 + ", UV_Volt06 = " + UV_Volt06
	 + ", UV_Volt07 = " + UV_Volt07
	 + ", UV_Volt08 = " + UV_Volt08
	 + ", UV_Volt09 = " + UV_Volt09
	 + ", UV_Volt10 = " + UV_Volt10
	 + ", UV_Delay01 = " + UV_Delay01
	 + ", UV_Delay02 = " + UV_Delay02
	 + ", UV_Delay03 = " + UV_Delay03
	 + ", UV_Delay04 = " + UV_Delay04
	 + ", UV_Delay05 = " + UV_Delay05
	 + ", UV_Delay06 = " + UV_Delay06
	 + ", UV_Delay07 = " + UV_Delay07
	 + ", UV_Delay08 = " + UV_Delay08
	 + ", UV_Delay09 = " + UV_Delay09
	 + ", UV_Delay10 = " + UV_Delay10
	 + ", UV_Shed01 = " + UV_Shed01
	 + ", UV_Shed02 = " + UV_Shed02
	 + ", UV_Shed03 = " + UV_Shed03
	 + ", UV_Shed04 = " + UV_Shed04
	 + ", UV_Shed05 = " + UV_Shed05
	 + ", UV_Shed06 = " + UV_Shed06
	 + ", UV_Shed07 = " + UV_Shed07
	 + ", UV_Shed08 = " + UV_Shed08
	 + ", UV_Shed09 = " + UV_Shed09
	 + ", UV_Shed10 = " + UV_Shed10
	 + ", UV_W = " + UV_W+"]";
  }
    
}
    
