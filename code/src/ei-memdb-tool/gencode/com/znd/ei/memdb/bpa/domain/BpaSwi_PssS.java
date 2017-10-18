package com.znd.ei.memdb.bpa.domain;


/**********************
*PSS模型表(S)	*
***********************/
public class BpaSwi_PssS
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名
  private String aCBus_Name;
  
  //基准电压
  private Double aCBus_kV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //电压控制增益
  private Double pssS_KQV;
  
  //电压变送器时间常数
  private Double pssS_TQV;
  
  //频率、加速功率和轴滑差控制增益
  private Double pssS_KQS;
  
  //频率、加速功率和轴滑差控制时间常数
  private Double pssS_TQS;
  
  //PSS控制时间常数
  private Double pssS_TQ;
  
  //第一个滞后时间常数
  private Double pssS_TQ1;
  
  //第一个超前时间常数
  private Double pssS_TQ1P;
  
  //第二个滞后时间常数
  private Double pssS_TQ2;
  
  //第二个超前时间常数
  private Double pssS_TQ2P;
  
  //第三个滞后时间常数
  private Double pssS_TQ3;
  
  //第三个超前时间常数
  private Double pssS_TQ3P;
  
  //PSS最大输出(pu)
  private Double pssS_VSmax;
  
  //参考电压值,其意义见框图说明
  private Double pssS_VCutOff;
  
  //用于确定VSMIN值
  private Double pssS_VSlow;
  
  //KQ的基准容量(MVA)
  private Double pssS_KQBase;
  
  //远方母线名
  private String pssS_RBusName;
  
  //远方母线基准电压
  private Double pssS_RBuskV;
  
  //数据库主键
  private String keyName;
  
  //发电机母线索引
  private Integer busPtr;
  
  //远方母线母线索引
  private Integer pssS_iRRBus;
  
  //新增记录标记
  private Integer appendTag;
  
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
    
  public Double getPssS_KQV()
  {
    return pssS_KQV;
  }
    
  public void setPssS_KQV(Double pssS_KQV)
  {
    this.pssS_KQV = pssS_KQV;
  }
    
  public Double getPssS_TQV()
  {
    return pssS_TQV;
  }
    
  public void setPssS_TQV(Double pssS_TQV)
  {
    this.pssS_TQV = pssS_TQV;
  }
    
  public Double getPssS_KQS()
  {
    return pssS_KQS;
  }
    
  public void setPssS_KQS(Double pssS_KQS)
  {
    this.pssS_KQS = pssS_KQS;
  }
    
  public Double getPssS_TQS()
  {
    return pssS_TQS;
  }
    
  public void setPssS_TQS(Double pssS_TQS)
  {
    this.pssS_TQS = pssS_TQS;
  }
    
  public Double getPssS_TQ()
  {
    return pssS_TQ;
  }
    
  public void setPssS_TQ(Double pssS_TQ)
  {
    this.pssS_TQ = pssS_TQ;
  }
    
  public Double getPssS_TQ1()
  {
    return pssS_TQ1;
  }
    
  public void setPssS_TQ1(Double pssS_TQ1)
  {
    this.pssS_TQ1 = pssS_TQ1;
  }
    
  public Double getPssS_TQ1P()
  {
    return pssS_TQ1P;
  }
    
  public void setPssS_TQ1P(Double pssS_TQ1P)
  {
    this.pssS_TQ1P = pssS_TQ1P;
  }
    
  public Double getPssS_TQ2()
  {
    return pssS_TQ2;
  }
    
  public void setPssS_TQ2(Double pssS_TQ2)
  {
    this.pssS_TQ2 = pssS_TQ2;
  }
    
  public Double getPssS_TQ2P()
  {
    return pssS_TQ2P;
  }
    
  public void setPssS_TQ2P(Double pssS_TQ2P)
  {
    this.pssS_TQ2P = pssS_TQ2P;
  }
    
  public Double getPssS_TQ3()
  {
    return pssS_TQ3;
  }
    
  public void setPssS_TQ3(Double pssS_TQ3)
  {
    this.pssS_TQ3 = pssS_TQ3;
  }
    
  public Double getPssS_TQ3P()
  {
    return pssS_TQ3P;
  }
    
  public void setPssS_TQ3P(Double pssS_TQ3P)
  {
    this.pssS_TQ3P = pssS_TQ3P;
  }
    
  public Double getPssS_VSmax()
  {
    return pssS_VSmax;
  }
    
  public void setPssS_VSmax(Double pssS_VSmax)
  {
    this.pssS_VSmax = pssS_VSmax;
  }
    
  public Double getPssS_VCutOff()
  {
    return pssS_VCutOff;
  }
    
  public void setPssS_VCutOff(Double pssS_VCutOff)
  {
    this.pssS_VCutOff = pssS_VCutOff;
  }
    
  public Double getPssS_VSlow()
  {
    return pssS_VSlow;
  }
    
  public void setPssS_VSlow(Double pssS_VSlow)
  {
    this.pssS_VSlow = pssS_VSlow;
  }
    
  public Double getPssS_KQBase()
  {
    return pssS_KQBase;
  }
    
  public void setPssS_KQBase(Double pssS_KQBase)
  {
    this.pssS_KQBase = pssS_KQBase;
  }
    
  public String getPssS_RBusName()
  {
    return pssS_RBusName;
  }
    
  public void setPssS_RBusName(String pssS_RBusName)
  {
    this.pssS_RBusName = pssS_RBusName;
  }
    
  public Double getPssS_RBuskV()
  {
    return pssS_RBuskV;
  }
    
  public void setPssS_RBuskV(Double pssS_RBuskV)
  {
    this.pssS_RBuskV = pssS_RBuskV;
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
    
  public Integer getPssS_iRRBus()
  {
    return pssS_iRRBus;
  }
    
  public void setPssS_iRRBus(Integer pssS_iRRBus)
  {
    this.pssS_iRRBus = pssS_iRRBus;
  }
    
  public Integer getAppendTag()
  {
    return appendTag;
  }
    
  public void setAppendTag(Integer appendTag)
  {
    this.appendTag = appendTag;
  }
    
  public String toString()
  {
    return "BpaSwi_PssS ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", pssS_KQV = " + pssS_KQV
	 + ", pssS_TQV = " + pssS_TQV
	 + ", pssS_KQS = " + pssS_KQS
	 + ", pssS_TQS = " + pssS_TQS
	 + ", pssS_TQ = " + pssS_TQ
	 + ", pssS_TQ1 = " + pssS_TQ1
	 + ", pssS_TQ1P = " + pssS_TQ1P
	 + ", pssS_TQ2 = " + pssS_TQ2
	 + ", pssS_TQ2P = " + pssS_TQ2P
	 + ", pssS_TQ3 = " + pssS_TQ3
	 + ", pssS_TQ3P = " + pssS_TQ3P
	 + ", pssS_VSmax = " + pssS_VSmax
	 + ", pssS_VCutOff = " + pssS_VCutOff
	 + ", pssS_VSlow = " + pssS_VSlow
	 + ", pssS_KQBase = " + pssS_KQBase
	 + ", pssS_RBusName = " + pssS_RBusName
	 + ", pssS_RBuskV = " + pssS_RBuskV
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", pssS_iRRBus = " + pssS_iRRBus
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
