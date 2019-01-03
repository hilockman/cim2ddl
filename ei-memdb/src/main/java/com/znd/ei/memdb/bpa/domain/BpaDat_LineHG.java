package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*线路高抗表(LineHG)	*
***********************/
public class BpaDat_LineHG  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称1
  private String LineHG_BusI;
  
  //基准电压1(kV)
  private Double LineHG_kVI;
  
  //母线名称2
  private String LineHG_BusJ;
  
  //基准电压2(kV)
  private Double LineHG_kVJ;
  
  //并联线路的回路标志
  private Integer LineHG_Loop;
  
  //线路前侧高抗容量(Mvar,填正值)
  private Double LineHG_ShuntI;
  
  //线路后侧高抗容量(Mvar,填正值)
  private Double LineHG_ShuntJ;
  
  //线路高抗名称
  private String KeyName;
  
  //Ini母线名称1
  private String IniBusI;
  
  //Ini基准电压1(kV)
  private Double InikVI;
  
  //Ini母线名称2
  private String IniBusJ;
  
  //Ini基准电压2(kV)
  private Double InikVJ;
  
  //Ini并联线路的回路标志
  private Integer IniLoop;
  
  //线路高抗I母线索引
  private Integer iRBus;
  
  //线路高抗Z母线索引
  private Integer zRBus;
  
  //线路高抗别名
  private String Alias;
  
  //状态
  private Integer Status;
  
  //环网设备
  private Integer InRing;
  
  //所在辐射网
  private Integer Radiate;
  
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
    
  public String getLineHG_BusI()
  {
    return LineHG_BusI;
  }
    
  public void setLineHG_BusI(String LineHG_BusI)
  {
    this.LineHG_BusI = LineHG_BusI;
  }
    
  public Double getLineHG_kVI()
  {
    return LineHG_kVI;
  }
    
  public void setLineHG_kVI(Double LineHG_kVI)
  {
    this.LineHG_kVI = LineHG_kVI;
  }
    
  public String getLineHG_BusJ()
  {
    return LineHG_BusJ;
  }
    
  public void setLineHG_BusJ(String LineHG_BusJ)
  {
    this.LineHG_BusJ = LineHG_BusJ;
  }
    
  public Double getLineHG_kVJ()
  {
    return LineHG_kVJ;
  }
    
  public void setLineHG_kVJ(Double LineHG_kVJ)
  {
    this.LineHG_kVJ = LineHG_kVJ;
  }
    
  public Integer getLineHG_Loop()
  {
    return LineHG_Loop;
  }
    
  public void setLineHG_Loop(Integer LineHG_Loop)
  {
    this.LineHG_Loop = LineHG_Loop;
  }
    
  public Double getLineHG_ShuntI()
  {
    return LineHG_ShuntI;
  }
    
  public void setLineHG_ShuntI(Double LineHG_ShuntI)
  {
    this.LineHG_ShuntI = LineHG_ShuntI;
  }
    
  public Double getLineHG_ShuntJ()
  {
    return LineHG_ShuntJ;
  }
    
  public void setLineHG_ShuntJ(Double LineHG_ShuntJ)
  {
    this.LineHG_ShuntJ = LineHG_ShuntJ;
  }
    
  public String getKeyName()
  {
    return KeyName;
  }
    
  public void setKeyName(String KeyName)
  {
    this.KeyName = KeyName;
  }
    
  public String getIniBusI()
  {
    return IniBusI;
  }
    
  public void setIniBusI(String IniBusI)
  {
    this.IniBusI = IniBusI;
  }
    
  public Double getInikVI()
  {
    return InikVI;
  }
    
  public void setInikVI(Double InikVI)
  {
    this.InikVI = InikVI;
  }
    
  public String getIniBusJ()
  {
    return IniBusJ;
  }
    
  public void setIniBusJ(String IniBusJ)
  {
    this.IniBusJ = IniBusJ;
  }
    
  public Double getInikVJ()
  {
    return InikVJ;
  }
    
  public void setInikVJ(Double InikVJ)
  {
    this.InikVJ = InikVJ;
  }
    
  public Integer getIniLoop()
  {
    return IniLoop;
  }
    
  public void setIniLoop(Integer IniLoop)
  {
    this.IniLoop = IniLoop;
  }
    
  public Integer getiRBus()
  {
    return iRBus;
  }
    
  public void setiRBus(Integer iRBus)
  {
    this.iRBus = iRBus;
  }
    
  public Integer getzRBus()
  {
    return zRBus;
  }
    
  public void setzRBus(Integer zRBus)
  {
    this.zRBus = zRBus;
  }
    
  public String getAlias()
  {
    return Alias;
  }
    
  public void setAlias(String Alias)
  {
    this.Alias = Alias;
  }
    
  public Integer getStatus()
  {
    return Status;
  }
    
  public void setStatus(Integer Status)
  {
    this.Status = Status;
  }
    
  public Integer getInRing()
  {
    return InRing;
  }
    
  public void setInRing(Integer InRing)
  {
    this.InRing = InRing;
  }
    
  public Integer getRadiate()
  {
    return Radiate;
  }
    
  public void setRadiate(Integer Radiate)
  {
    this.Radiate = Radiate;
  }
    
  public String toString()
  {
    return "BpaDat_LineHG ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", LineHG_BusI = " + LineHG_BusI
	 + ", LineHG_kVI = " + LineHG_kVI
	 + ", LineHG_BusJ = " + LineHG_BusJ
	 + ", LineHG_kVJ = " + LineHG_kVJ
	 + ", LineHG_Loop = " + LineHG_Loop
	 + ", LineHG_ShuntI = " + LineHG_ShuntI
	 + ", LineHG_ShuntJ = " + LineHG_ShuntJ
	 + ", KeyName = " + KeyName
	 + ", IniBusI = " + IniBusI
	 + ", InikVI = " + InikVI
	 + ", IniBusJ = " + IniBusJ
	 + ", InikVJ = " + InikVJ
	 + ", IniLoop = " + IniLoop
	 + ", iRBus = " + iRBus
	 + ", zRBus = " + zRBus
	 + ", Alias = " + Alias
	 + ", Status = " + Status
	 + ", InRing = " + InRing
	 + ", Radiate = " + Radiate+"]";
  }
    
}
    
