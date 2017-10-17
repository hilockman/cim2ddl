package com.znd.ei.memdb.bpa.domain;


/**********************
*GE风机模型表(WINDG_GE)	*
***********************/
public class BpaSwi_WGEGen
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //电机母线名
  private String aCBus_Name;
  
  //电机母线电压(kV)
  private Double aCBus_kV;
  
  //电机识别码
  private Integer gen_ID;
  
  //风电机组类型代码
  private String gE_TYPE;
  
  //风电机组台数
  private Integer nG;
  
  //风电场无功控制节点名称
  private String nAME_CON;
  
  //风电场无功控制节点基准电压
  private Double bASE_CON;
  
  //有功占潮流总出力比例
  private Double pPER;
  
  //无功占潮流总出力比例
  private Double qPER;
  
  //初始风速(m/s)
  private Double v0;
  
  //=0考虑双质量块,否则单质量块
  private Integer nMASS_FLG;
  
  //=0不考虑QDROOP,否则考虑
  private Integer qDROOP_FLG;
  
  //=0风电场无功电压/恒功率因数控制模式
  private Integer wINDCON_FLG;
  
  //=0电气控制采用电压反馈
  private Integer eWVOL_FLG;
  
  //=0不采用APC有功控制功能,否则采用
  private Integer aPCFLG;
  
  //=0APC功能中采用最大输出限制控制功能
  private Integer fFLG;
  
  //=0不采用WINDINERTIA功能
  private Integer iNERTIA;
  
  //=0无功优先标志,否则有功优先(直驱)
  private Integer pQFLG;
  
  //数据库主键
  private String keyName;
  
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
    
  public Double getACBus_kV()
  {
    return aCBus_kV;
  }
    
  public void setACBus_kV(Double aCBus_kV)
  {
    this.aCBus_kV = aCBus_kV;
  }
    
  public Integer getGen_ID()
  {
    return gen_ID;
  }
    
  public void setGen_ID(Integer gen_ID)
  {
    this.gen_ID = gen_ID;
  }
    
  public String getGE_TYPE()
  {
    return gE_TYPE;
  }
    
  public void setGE_TYPE(String gE_TYPE)
  {
    this.gE_TYPE = gE_TYPE;
  }
    
  public Integer getNG()
  {
    return nG;
  }
    
  public void setNG(Integer nG)
  {
    this.nG = nG;
  }
    
  public String getNAME_CON()
  {
    return nAME_CON;
  }
    
  public void setNAME_CON(String nAME_CON)
  {
    this.nAME_CON = nAME_CON;
  }
    
  public Double getBASE_CON()
  {
    return bASE_CON;
  }
    
  public void setBASE_CON(Double bASE_CON)
  {
    this.bASE_CON = bASE_CON;
  }
    
  public Double getPPER()
  {
    return pPER;
  }
    
  public void setPPER(Double pPER)
  {
    this.pPER = pPER;
  }
    
  public Double getQPER()
  {
    return qPER;
  }
    
  public void setQPER(Double qPER)
  {
    this.qPER = qPER;
  }
    
  public Double getV0()
  {
    return v0;
  }
    
  public void setV0(Double v0)
  {
    this.v0 = v0;
  }
    
  public Integer getNMASS_FLG()
  {
    return nMASS_FLG;
  }
    
  public void setNMASS_FLG(Integer nMASS_FLG)
  {
    this.nMASS_FLG = nMASS_FLG;
  }
    
  public Integer getQDROOP_FLG()
  {
    return qDROOP_FLG;
  }
    
  public void setQDROOP_FLG(Integer qDROOP_FLG)
  {
    this.qDROOP_FLG = qDROOP_FLG;
  }
    
  public Integer getWINDCON_FLG()
  {
    return wINDCON_FLG;
  }
    
  public void setWINDCON_FLG(Integer wINDCON_FLG)
  {
    this.wINDCON_FLG = wINDCON_FLG;
  }
    
  public Integer getEWVOL_FLG()
  {
    return eWVOL_FLG;
  }
    
  public void setEWVOL_FLG(Integer eWVOL_FLG)
  {
    this.eWVOL_FLG = eWVOL_FLG;
  }
    
  public Integer getAPCFLG()
  {
    return aPCFLG;
  }
    
  public void setAPCFLG(Integer aPCFLG)
  {
    this.aPCFLG = aPCFLG;
  }
    
  public Integer getFFLG()
  {
    return fFLG;
  }
    
  public void setFFLG(Integer fFLG)
  {
    this.fFLG = fFLG;
  }
    
  public Integer getINERTIA()
  {
    return iNERTIA;
  }
    
  public void setINERTIA(Integer iNERTIA)
  {
    this.iNERTIA = iNERTIA;
  }
    
  public Integer getPQFLG()
  {
    return pQFLG;
  }
    
  public void setPQFLG(Integer pQFLG)
  {
    this.pQFLG = pQFLG;
  }
    
  public String getKeyName()
  {
    return keyName;
  }
    
  public void setKeyName(String keyName)
  {
    this.keyName = keyName;
  }
    
  public Integer getBusPtr()
  {
    return busPtr;
  }
    
  public void setBusPtr(Integer busPtr)
  {
    this.busPtr = busPtr;
  }
    
  public String toString()
  {
    return "BpaSwi_WGEGen ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"aCBus_Name"=aCBus_Name,
	"aCBus_kV"=aCBus_kV,
	"gen_ID"=gen_ID,
	"gE_TYPE"=gE_TYPE,
	"nG"=nG,
	"nAME_CON"=nAME_CON,
	"bASE_CON"=bASE_CON,
	"pPER"=pPER,
	"qPER"=qPER,
	"v0"=v0,
	"nMASS_FLG"=nMASS_FLG,
	"qDROOP_FLG"=qDROOP_FLG,
	"wINDCON_FLG"=wINDCON_FLG,
	"eWVOL_FLG"=eWVOL_FLG,
	"aPCFLG"=aPCFLG,
	"fFLG"=fFLG,
	"iNERTIA"=iNERTIA,
	"pQFLG"=pQFLG,
	"keyName"=keyName,
	"busPtr"=busPtr+"]"
  }
    
}
    
