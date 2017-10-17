package com.znd.ei.memdb.bpa.domain;


/**********************
*线路高抗表(LineHG)	*
***********************/
public class BpaDat_LineHG
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称1
  private String lineHG_BusI;
  
  //基准电压1(kV)
  private Double lineHG_kVI;
  
  //母线名称2
  private String lineHG_BusJ;
  
  //基准电压2(kV)
  private Double lineHG_kVJ;
  
  //并联线路的回路标志
  private Integer lineHG_Loop;
  
  //线路前侧高抗容量(Mvar,填正值)
  private Double lineHG_ShuntI;
  
  //线路后侧高抗容量(Mvar,填正值)
  private Double lineHG_ShuntJ;
  
  //线路高抗名称
  private String keyName;
  
  //Ini母线名称1
  private String iniBusI;
  
  //Ini基准电压1(kV)
  private Double inikVI;
  
  //Ini母线名称2
  private String iniBusJ;
  
  //Ini基准电压2(kV)
  private Double inikVJ;
  
  //Ini并联线路的回路标志
  private Integer iniLoop;
  
  //线路高抗I母线索引
  private Integer iRBus;
  
  //线路高抗Z母线索引
  private Integer zRBus;
  
  //线路高抗别名
  private String alias;
  
  //状态
  private Integer status;
  
  //环网设备
  private Integer inRing;
  
  //所在辐射网
  private Integer radiate;
  
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
    
  public String getLineHG_BusI()
  {
    return lineHG_BusI;
  }
    
  public void setLineHG_BusI(String lineHG_BusI)
  {
    this.lineHG_BusI = lineHG_BusI;
  }
    
  public Double getLineHG_kVI()
  {
    return lineHG_kVI;
  }
    
  public void setLineHG_kVI(Double lineHG_kVI)
  {
    this.lineHG_kVI = lineHG_kVI;
  }
    
  public String getLineHG_BusJ()
  {
    return lineHG_BusJ;
  }
    
  public void setLineHG_BusJ(String lineHG_BusJ)
  {
    this.lineHG_BusJ = lineHG_BusJ;
  }
    
  public Double getLineHG_kVJ()
  {
    return lineHG_kVJ;
  }
    
  public void setLineHG_kVJ(Double lineHG_kVJ)
  {
    this.lineHG_kVJ = lineHG_kVJ;
  }
    
  public Integer getLineHG_Loop()
  {
    return lineHG_Loop;
  }
    
  public void setLineHG_Loop(Integer lineHG_Loop)
  {
    this.lineHG_Loop = lineHG_Loop;
  }
    
  public Double getLineHG_ShuntI()
  {
    return lineHG_ShuntI;
  }
    
  public void setLineHG_ShuntI(Double lineHG_ShuntI)
  {
    this.lineHG_ShuntI = lineHG_ShuntI;
  }
    
  public Double getLineHG_ShuntJ()
  {
    return lineHG_ShuntJ;
  }
    
  public void setLineHG_ShuntJ(Double lineHG_ShuntJ)
  {
    this.lineHG_ShuntJ = lineHG_ShuntJ;
  }
    
  public String getKeyName()
  {
    return keyName;
  }
    
  public void setKeyName(String keyName)
  {
    this.keyName = keyName;
  }
    
  public String getIniBusI()
  {
    return iniBusI;
  }
    
  public void setIniBusI(String iniBusI)
  {
    this.iniBusI = iniBusI;
  }
    
  public Double getInikVI()
  {
    return inikVI;
  }
    
  public void setInikVI(Double inikVI)
  {
    this.inikVI = inikVI;
  }
    
  public String getIniBusJ()
  {
    return iniBusJ;
  }
    
  public void setIniBusJ(String iniBusJ)
  {
    this.iniBusJ = iniBusJ;
  }
    
  public Double getInikVJ()
  {
    return inikVJ;
  }
    
  public void setInikVJ(Double inikVJ)
  {
    this.inikVJ = inikVJ;
  }
    
  public Integer getIniLoop()
  {
    return iniLoop;
  }
    
  public void setIniLoop(Integer iniLoop)
  {
    this.iniLoop = iniLoop;
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
    return alias;
  }
    
  public void setAlias(String alias)
  {
    this.alias = alias;
  }
    
  public Integer getStatus()
  {
    return status;
  }
    
  public void setStatus(Integer status)
  {
    this.status = status;
  }
    
  public Integer getInRing()
  {
    return inRing;
  }
    
  public void setInRing(Integer inRing)
  {
    this.inRing = inRing;
  }
    
  public Integer getRadiate()
  {
    return radiate;
  }
    
  public void setRadiate(Integer radiate)
  {
    this.radiate = radiate;
  }
    
  public String toString()
  {
    return "BpaDat_LineHG ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"lineHG_BusI"=lineHG_BusI,
	"lineHG_kVI"=lineHG_kVI,
	"lineHG_BusJ"=lineHG_BusJ,
	"lineHG_kVJ"=lineHG_kVJ,
	"lineHG_Loop"=lineHG_Loop,
	"lineHG_ShuntI"=lineHG_ShuntI,
	"lineHG_ShuntJ"=lineHG_ShuntJ,
	"keyName"=keyName,
	"iniBusI"=iniBusI,
	"inikVI"=inikVI,
	"iniBusJ"=iniBusJ,
	"inikVJ"=inikVJ,
	"iniLoop"=iniLoop,
	"iRBus"=iRBus,
	"zRBus"=zRBus,
	"alias"=alias,
	"status"=status,
	"inRing"=inRing,
	"radiate"=radiate+"]"
  }
    
}
    
