package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*发电机电压保护(RE)	*
***********************/
public class BpaSwi_RE  implements MemIndexable 
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
  
  //电压设定值1(pu)
  private Double RE_VOL1;
  
  //电压设定值2(pu)
  private Double RE_VOL2;
  
  //电压设定值3(pu)
  private Double RE_VOL3;
  
  //电压设定值4(pu)
  private Double RE_VOL4;
  
  //电压设定值5(pu)
  private Double RE_VOL5;
  
  //电压设定值6(pu)
  private Double RE_VOL6;
  
  //电压设定值7(pu)
  private Double RE_VOL7;
  
  //电压设定值8(pu)
  private Double RE_VOL8;
  
  //电压设定值9(pu)
  private Double RE_VOL9;
  
  //电压设定值10(pu)
  private Double RE_VOL10;
  
  //时迟1(周)
  private Double RE_TIME1;
  
  //时迟2(周)
  private Double RE_TIME2;
  
  //时迟3(周)
  private Double RE_TIME3;
  
  //时迟4(周)
  private Double RE_TIME4;
  
  //时迟5(周)
  private Double RE_TIME5;
  
  //时迟6(周)
  private Double RE_TIME6;
  
  //时迟7(周)
  private Double RE_TIME7;
  
  //时迟8(周)
  private Double RE_TIME8;
  
  //时迟9(周)
  private Double RE_TIME9;
  
  //时迟10(周)
  private Double RE_TIME10;
  
  //继电器动作时间(周)
  private Double RE_TBRK;
  
  //控制母线名称
  private String RE_NAME_CON;
  
  //控制母线基准电压
  private Double RE_KV_CON;
  
  //数据库主键
  private String KeyName;
  
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
    
  public Double getRE_VOL1()
  {
    return RE_VOL1;
  }
    
  public void setRE_VOL1(Double RE_VOL1)
  {
    this.RE_VOL1 = RE_VOL1;
  }
    
  public Double getRE_VOL2()
  {
    return RE_VOL2;
  }
    
  public void setRE_VOL2(Double RE_VOL2)
  {
    this.RE_VOL2 = RE_VOL2;
  }
    
  public Double getRE_VOL3()
  {
    return RE_VOL3;
  }
    
  public void setRE_VOL3(Double RE_VOL3)
  {
    this.RE_VOL3 = RE_VOL3;
  }
    
  public Double getRE_VOL4()
  {
    return RE_VOL4;
  }
    
  public void setRE_VOL4(Double RE_VOL4)
  {
    this.RE_VOL4 = RE_VOL4;
  }
    
  public Double getRE_VOL5()
  {
    return RE_VOL5;
  }
    
  public void setRE_VOL5(Double RE_VOL5)
  {
    this.RE_VOL5 = RE_VOL5;
  }
    
  public Double getRE_VOL6()
  {
    return RE_VOL6;
  }
    
  public void setRE_VOL6(Double RE_VOL6)
  {
    this.RE_VOL6 = RE_VOL6;
  }
    
  public Double getRE_VOL7()
  {
    return RE_VOL7;
  }
    
  public void setRE_VOL7(Double RE_VOL7)
  {
    this.RE_VOL7 = RE_VOL7;
  }
    
  public Double getRE_VOL8()
  {
    return RE_VOL8;
  }
    
  public void setRE_VOL8(Double RE_VOL8)
  {
    this.RE_VOL8 = RE_VOL8;
  }
    
  public Double getRE_VOL9()
  {
    return RE_VOL9;
  }
    
  public void setRE_VOL9(Double RE_VOL9)
  {
    this.RE_VOL9 = RE_VOL9;
  }
    
  public Double getRE_VOL10()
  {
    return RE_VOL10;
  }
    
  public void setRE_VOL10(Double RE_VOL10)
  {
    this.RE_VOL10 = RE_VOL10;
  }
    
  public Double getRE_TIME1()
  {
    return RE_TIME1;
  }
    
  public void setRE_TIME1(Double RE_TIME1)
  {
    this.RE_TIME1 = RE_TIME1;
  }
    
  public Double getRE_TIME2()
  {
    return RE_TIME2;
  }
    
  public void setRE_TIME2(Double RE_TIME2)
  {
    this.RE_TIME2 = RE_TIME2;
  }
    
  public Double getRE_TIME3()
  {
    return RE_TIME3;
  }
    
  public void setRE_TIME3(Double RE_TIME3)
  {
    this.RE_TIME3 = RE_TIME3;
  }
    
  public Double getRE_TIME4()
  {
    return RE_TIME4;
  }
    
  public void setRE_TIME4(Double RE_TIME4)
  {
    this.RE_TIME4 = RE_TIME4;
  }
    
  public Double getRE_TIME5()
  {
    return RE_TIME5;
  }
    
  public void setRE_TIME5(Double RE_TIME5)
  {
    this.RE_TIME5 = RE_TIME5;
  }
    
  public Double getRE_TIME6()
  {
    return RE_TIME6;
  }
    
  public void setRE_TIME6(Double RE_TIME6)
  {
    this.RE_TIME6 = RE_TIME6;
  }
    
  public Double getRE_TIME7()
  {
    return RE_TIME7;
  }
    
  public void setRE_TIME7(Double RE_TIME7)
  {
    this.RE_TIME7 = RE_TIME7;
  }
    
  public Double getRE_TIME8()
  {
    return RE_TIME8;
  }
    
  public void setRE_TIME8(Double RE_TIME8)
  {
    this.RE_TIME8 = RE_TIME8;
  }
    
  public Double getRE_TIME9()
  {
    return RE_TIME9;
  }
    
  public void setRE_TIME9(Double RE_TIME9)
  {
    this.RE_TIME9 = RE_TIME9;
  }
    
  public Double getRE_TIME10()
  {
    return RE_TIME10;
  }
    
  public void setRE_TIME10(Double RE_TIME10)
  {
    this.RE_TIME10 = RE_TIME10;
  }
    
  public Double getRE_TBRK()
  {
    return RE_TBRK;
  }
    
  public void setRE_TBRK(Double RE_TBRK)
  {
    this.RE_TBRK = RE_TBRK;
  }
    
  public String getRE_NAME_CON()
  {
    return RE_NAME_CON;
  }
    
  public void setRE_NAME_CON(String RE_NAME_CON)
  {
    this.RE_NAME_CON = RE_NAME_CON;
  }
    
  public Double getRE_KV_CON()
  {
    return RE_KV_CON;
  }
    
  public void setRE_KV_CON(Double RE_KV_CON)
  {
    this.RE_KV_CON = RE_KV_CON;
  }
    
  public String getKeyName()
  {
    return KeyName;
  }
    
  public void setKeyName(String KeyName)
  {
    this.KeyName = KeyName;
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
    return "BpaSwi_RE ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_KV = " + ACBus_KV
	 + ", Gen_ID = " + Gen_ID
	 + ", RE_VOL1 = " + RE_VOL1
	 + ", RE_VOL2 = " + RE_VOL2
	 + ", RE_VOL3 = " + RE_VOL3
	 + ", RE_VOL4 = " + RE_VOL4
	 + ", RE_VOL5 = " + RE_VOL5
	 + ", RE_VOL6 = " + RE_VOL6
	 + ", RE_VOL7 = " + RE_VOL7
	 + ", RE_VOL8 = " + RE_VOL8
	 + ", RE_VOL9 = " + RE_VOL9
	 + ", RE_VOL10 = " + RE_VOL10
	 + ", RE_TIME1 = " + RE_TIME1
	 + ", RE_TIME2 = " + RE_TIME2
	 + ", RE_TIME3 = " + RE_TIME3
	 + ", RE_TIME4 = " + RE_TIME4
	 + ", RE_TIME5 = " + RE_TIME5
	 + ", RE_TIME6 = " + RE_TIME6
	 + ", RE_TIME7 = " + RE_TIME7
	 + ", RE_TIME8 = " + RE_TIME8
	 + ", RE_TIME9 = " + RE_TIME9
	 + ", RE_TIME10 = " + RE_TIME10
	 + ", RE_TBRK = " + RE_TBRK
	 + ", RE_NAME_CON = " + RE_NAME_CON
	 + ", RE_KV_CON = " + RE_KV_CON
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
