package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*岛	*
***********************/
public class Island  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //岛平衡设备厂站
  private String SlackSub;
  
  //岛平衡设备名称
  private String SlackDevName;
  
  //岛平衡设备类型
  private Integer SlackDevType;
  
  //岛发电有功(兆瓦)
  private Double GenP;
  
  //岛发电无功(兆乏)
  private Double GenQ;
  
  //岛负荷有功(兆瓦)
  private Double LoadP;
  
  //岛负荷无功(兆乏)
  private Double LoadQ;
  
  //岛并联无功(兆乏)
  private Double ShuntQ;
  
  //岛损耗有功(兆乏)
  private Double LossP;
  
  //岛损耗无功(兆乏)
  private Double LossQ;
  
  //岛内发电机数
  private Integer GenNum;
  
  //岛内负荷
  private Integer LoadNum;
  
  //岛内并补数
  private Integer CapNum;
  
  //岛内串补数
  private Integer SReacNum;
  
  //岛内交流母线数
  private Integer ACBusNum;
  
  //岛内交流线路数
  private Integer ACLineNum;
  
  //岛内主变数
  private Integer TranNum;
  
  //岛内风机数
  private Integer WTNum;
  
  //岛内光伏数
  private Integer PVNum;
  
  //岛内电动汽车数
  private Integer EVNum;
  
  //岛内电化学储能数
  private Integer ECSNum;
  
  //岛内光热发电数
  private Integer STMNum;
  
  //岛内直流母线数
  private Integer DCBusNum;
  
  //岛内直流线路数
  private Integer DCLineNum;
  
  //岛内交直变换器数
  private Integer ADConverterNum;
  
  //岛内直直变换器数
  private Integer DDConverterNum;
  
  //岛内直流FCL数
  private Integer DCFCLNum;
  
  //死岛标志
  private Integer Dead;
  
  //直流电岛
  private Integer DCIsland;
  
  //潮流收敛标志
  private Integer PFConvergency;
  
  //设备索引
  private Integer DevPtr;
  
  //岛类型
  private Integer Type;
  
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
    
  public String getSlackSub()
  {
    return SlackSub;
  }
    
  public void setSlackSub(String SlackSub)
  {
    this.SlackSub = SlackSub;
  }
    
  public String getSlackDevName()
  {
    return SlackDevName;
  }
    
  public void setSlackDevName(String SlackDevName)
  {
    this.SlackDevName = SlackDevName;
  }
    
  public Integer getSlackDevType()
  {
    return SlackDevType;
  }
    
  public void setSlackDevType(Integer SlackDevType)
  {
    this.SlackDevType = SlackDevType;
  }
    
  public Double getGenP()
  {
    return GenP;
  }
    
  public void setGenP(Double GenP)
  {
    this.GenP = GenP;
  }
    
  public Double getGenQ()
  {
    return GenQ;
  }
    
  public void setGenQ(Double GenQ)
  {
    this.GenQ = GenQ;
  }
    
  public Double getLoadP()
  {
    return LoadP;
  }
    
  public void setLoadP(Double LoadP)
  {
    this.LoadP = LoadP;
  }
    
  public Double getLoadQ()
  {
    return LoadQ;
  }
    
  public void setLoadQ(Double LoadQ)
  {
    this.LoadQ = LoadQ;
  }
    
  public Double getShuntQ()
  {
    return ShuntQ;
  }
    
  public void setShuntQ(Double ShuntQ)
  {
    this.ShuntQ = ShuntQ;
  }
    
  public Double getLossP()
  {
    return LossP;
  }
    
  public void setLossP(Double LossP)
  {
    this.LossP = LossP;
  }
    
  public Double getLossQ()
  {
    return LossQ;
  }
    
  public void setLossQ(Double LossQ)
  {
    this.LossQ = LossQ;
  }
    
  public Integer getGenNum()
  {
    return GenNum;
  }
    
  public void setGenNum(Integer GenNum)
  {
    this.GenNum = GenNum;
  }
    
  public Integer getLoadNum()
  {
    return LoadNum;
  }
    
  public void setLoadNum(Integer LoadNum)
  {
    this.LoadNum = LoadNum;
  }
    
  public Integer getCapNum()
  {
    return CapNum;
  }
    
  public void setCapNum(Integer CapNum)
  {
    this.CapNum = CapNum;
  }
    
  public Integer getSReacNum()
  {
    return SReacNum;
  }
    
  public void setSReacNum(Integer SReacNum)
  {
    this.SReacNum = SReacNum;
  }
    
  public Integer getACBusNum()
  {
    return ACBusNum;
  }
    
  public void setACBusNum(Integer ACBusNum)
  {
    this.ACBusNum = ACBusNum;
  }
    
  public Integer getACLineNum()
  {
    return ACLineNum;
  }
    
  public void setACLineNum(Integer ACLineNum)
  {
    this.ACLineNum = ACLineNum;
  }
    
  public Integer getTranNum()
  {
    return TranNum;
  }
    
  public void setTranNum(Integer TranNum)
  {
    this.TranNum = TranNum;
  }
    
  public Integer getWTNum()
  {
    return WTNum;
  }
    
  public void setWTNum(Integer WTNum)
  {
    this.WTNum = WTNum;
  }
    
  public Integer getPVNum()
  {
    return PVNum;
  }
    
  public void setPVNum(Integer PVNum)
  {
    this.PVNum = PVNum;
  }
    
  public Integer getEVNum()
  {
    return EVNum;
  }
    
  public void setEVNum(Integer EVNum)
  {
    this.EVNum = EVNum;
  }
    
  public Integer getECSNum()
  {
    return ECSNum;
  }
    
  public void setECSNum(Integer ECSNum)
  {
    this.ECSNum = ECSNum;
  }
    
  public Integer getSTMNum()
  {
    return STMNum;
  }
    
  public void setSTMNum(Integer STMNum)
  {
    this.STMNum = STMNum;
  }
    
  public Integer getDCBusNum()
  {
    return DCBusNum;
  }
    
  public void setDCBusNum(Integer DCBusNum)
  {
    this.DCBusNum = DCBusNum;
  }
    
  public Integer getDCLineNum()
  {
    return DCLineNum;
  }
    
  public void setDCLineNum(Integer DCLineNum)
  {
    this.DCLineNum = DCLineNum;
  }
    
  public Integer getADConverterNum()
  {
    return ADConverterNum;
  }
    
  public void setADConverterNum(Integer ADConverterNum)
  {
    this.ADConverterNum = ADConverterNum;
  }
    
  public Integer getDDConverterNum()
  {
    return DDConverterNum;
  }
    
  public void setDDConverterNum(Integer DDConverterNum)
  {
    this.DDConverterNum = DDConverterNum;
  }
    
  public Integer getDCFCLNum()
  {
    return DCFCLNum;
  }
    
  public void setDCFCLNum(Integer DCFCLNum)
  {
    this.DCFCLNum = DCFCLNum;
  }
    
  public Integer getDead()
  {
    return Dead;
  }
    
  public void setDead(Integer Dead)
  {
    this.Dead = Dead;
  }
    
  public Integer getDCIsland()
  {
    return DCIsland;
  }
    
  public void setDCIsland(Integer DCIsland)
  {
    this.DCIsland = DCIsland;
  }
    
  public Integer getPFConvergency()
  {
    return PFConvergency;
  }
    
  public void setPFConvergency(Integer PFConvergency)
  {
    this.PFConvergency = PFConvergency;
  }
    
  public Integer getDevPtr()
  {
    return DevPtr;
  }
    
  public void setDevPtr(Integer DevPtr)
  {
    this.DevPtr = DevPtr;
  }
    
  public Integer getType()
  {
    return Type;
  }
    
  public void setType(Integer Type)
  {
    this.Type = Type;
  }
    
  public String toString()
  {
    return "Island ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", SlackSub = " + SlackSub
	 + ", SlackDevName = " + SlackDevName
	 + ", SlackDevType = " + SlackDevType
	 + ", GenP = " + GenP
	 + ", GenQ = " + GenQ
	 + ", LoadP = " + LoadP
	 + ", LoadQ = " + LoadQ
	 + ", ShuntQ = " + ShuntQ
	 + ", LossP = " + LossP
	 + ", LossQ = " + LossQ
	 + ", GenNum = " + GenNum
	 + ", LoadNum = " + LoadNum
	 + ", CapNum = " + CapNum
	 + ", SReacNum = " + SReacNum
	 + ", ACBusNum = " + ACBusNum
	 + ", ACLineNum = " + ACLineNum
	 + ", TranNum = " + TranNum
	 + ", WTNum = " + WTNum
	 + ", PVNum = " + PVNum
	 + ", EVNum = " + EVNum
	 + ", ECSNum = " + ECSNum
	 + ", STMNum = " + STMNum
	 + ", DCBusNum = " + DCBusNum
	 + ", DCLineNum = " + DCLineNum
	 + ", ADConverterNum = " + ADConverterNum
	 + ", DDConverterNum = " + DDConverterNum
	 + ", DCFCLNum = " + DCFCLNum
	 + ", Dead = " + Dead
	 + ", DCIsland = " + DCIsland
	 + ", PFConvergency = " + PFConvergency
	 + ", DevPtr = " + DevPtr
	 + ", Type = " + Type+"]";
  }
    
}
    
