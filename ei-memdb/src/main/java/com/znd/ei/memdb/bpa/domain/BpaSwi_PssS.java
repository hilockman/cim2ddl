package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*PSS模型表(S)	*
***********************/
public class BpaSwi_PssS  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名
  private String ACBus_Name;
  
  //基准电压
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //电压控制增益
  private Double PssS_KQV;
  
  //电压变送器时间常数
  private Double PssS_TQV;
  
  //频率、加速功率和轴滑差控制增益
  private Double PssS_KQS;
  
  //频率、加速功率和轴滑差控制时间常数
  private Double PssS_TQS;
  
  //PSS控制时间常数
  private Double PssS_TQ;
  
  //第一个滞后时间常数
  private Double PssS_TQ1;
  
  //第一个超前时间常数
  private Double PssS_TQ1P;
  
  //第二个滞后时间常数
  private Double PssS_TQ2;
  
  //第二个超前时间常数
  private Double PssS_TQ2P;
  
  //第三个滞后时间常数
  private Double PssS_TQ3;
  
  //第三个超前时间常数
  private Double PssS_TQ3P;
  
  //PSS最大输出(pu)
  private Double PssS_VSmax;
  
  //参考电压值,其意义见框图说明
  private Double PssS_VCutOff;
  
  //用于确定VSMIN值
  private Double PssS_VSlow;
  
  //KQ的基准容量(MVA)
  private Double PssS_KQBase;
  
  //远方母线名
  private String PssS_RBusName;
  
  //远方母线基准电压
  private Double PssS_RBuskV;
  
  //数据库主键
  private String KeyName;
  
  //发电机母线索引
  private Integer BusPtr;
  
  //远方母线母线索引
  private Integer PssS_iRRBus;
  
  //新增记录标记
  private Integer AppendTag;
  
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
    
  public Double getACBus_kV()
  {
    return ACBus_kV;
  }
    
  public void setACBus_kV(Double ACBus_kV)
  {
    this.ACBus_kV = ACBus_kV;
  }
    
  public Integer getGen_ID()
  {
    return Gen_ID;
  }
    
  public void setGen_ID(Integer Gen_ID)
  {
    this.Gen_ID = Gen_ID;
  }
    
  public Double getPssS_KQV()
  {
    return PssS_KQV;
  }
    
  public void setPssS_KQV(Double PssS_KQV)
  {
    this.PssS_KQV = PssS_KQV;
  }
    
  public Double getPssS_TQV()
  {
    return PssS_TQV;
  }
    
  public void setPssS_TQV(Double PssS_TQV)
  {
    this.PssS_TQV = PssS_TQV;
  }
    
  public Double getPssS_KQS()
  {
    return PssS_KQS;
  }
    
  public void setPssS_KQS(Double PssS_KQS)
  {
    this.PssS_KQS = PssS_KQS;
  }
    
  public Double getPssS_TQS()
  {
    return PssS_TQS;
  }
    
  public void setPssS_TQS(Double PssS_TQS)
  {
    this.PssS_TQS = PssS_TQS;
  }
    
  public Double getPssS_TQ()
  {
    return PssS_TQ;
  }
    
  public void setPssS_TQ(Double PssS_TQ)
  {
    this.PssS_TQ = PssS_TQ;
  }
    
  public Double getPssS_TQ1()
  {
    return PssS_TQ1;
  }
    
  public void setPssS_TQ1(Double PssS_TQ1)
  {
    this.PssS_TQ1 = PssS_TQ1;
  }
    
  public Double getPssS_TQ1P()
  {
    return PssS_TQ1P;
  }
    
  public void setPssS_TQ1P(Double PssS_TQ1P)
  {
    this.PssS_TQ1P = PssS_TQ1P;
  }
    
  public Double getPssS_TQ2()
  {
    return PssS_TQ2;
  }
    
  public void setPssS_TQ2(Double PssS_TQ2)
  {
    this.PssS_TQ2 = PssS_TQ2;
  }
    
  public Double getPssS_TQ2P()
  {
    return PssS_TQ2P;
  }
    
  public void setPssS_TQ2P(Double PssS_TQ2P)
  {
    this.PssS_TQ2P = PssS_TQ2P;
  }
    
  public Double getPssS_TQ3()
  {
    return PssS_TQ3;
  }
    
  public void setPssS_TQ3(Double PssS_TQ3)
  {
    this.PssS_TQ3 = PssS_TQ3;
  }
    
  public Double getPssS_TQ3P()
  {
    return PssS_TQ3P;
  }
    
  public void setPssS_TQ3P(Double PssS_TQ3P)
  {
    this.PssS_TQ3P = PssS_TQ3P;
  }
    
  public Double getPssS_VSmax()
  {
    return PssS_VSmax;
  }
    
  public void setPssS_VSmax(Double PssS_VSmax)
  {
    this.PssS_VSmax = PssS_VSmax;
  }
    
  public Double getPssS_VCutOff()
  {
    return PssS_VCutOff;
  }
    
  public void setPssS_VCutOff(Double PssS_VCutOff)
  {
    this.PssS_VCutOff = PssS_VCutOff;
  }
    
  public Double getPssS_VSlow()
  {
    return PssS_VSlow;
  }
    
  public void setPssS_VSlow(Double PssS_VSlow)
  {
    this.PssS_VSlow = PssS_VSlow;
  }
    
  public Double getPssS_KQBase()
  {
    return PssS_KQBase;
  }
    
  public void setPssS_KQBase(Double PssS_KQBase)
  {
    this.PssS_KQBase = PssS_KQBase;
  }
    
  public String getPssS_RBusName()
  {
    return PssS_RBusName;
  }
    
  public void setPssS_RBusName(String PssS_RBusName)
  {
    this.PssS_RBusName = PssS_RBusName;
  }
    
  public Double getPssS_RBuskV()
  {
    return PssS_RBuskV;
  }
    
  public void setPssS_RBuskV(Double PssS_RBuskV)
  {
    this.PssS_RBuskV = PssS_RBuskV;
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
    
  public Integer getPssS_iRRBus()
  {
    return PssS_iRRBus;
  }
    
  public void setPssS_iRRBus(Integer PssS_iRRBus)
  {
    this.PssS_iRRBus = PssS_iRRBus;
  }
    
  public Integer getAppendTag()
  {
    return AppendTag;
  }
    
  public void setAppendTag(Integer AppendTag)
  {
    this.AppendTag = AppendTag;
  }
    
  public String toString()
  {
    return "BpaSwi_PssS ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", PssS_KQV = " + PssS_KQV
	 + ", PssS_TQV = " + PssS_TQV
	 + ", PssS_KQS = " + PssS_KQS
	 + ", PssS_TQS = " + PssS_TQS
	 + ", PssS_TQ = " + PssS_TQ
	 + ", PssS_TQ1 = " + PssS_TQ1
	 + ", PssS_TQ1P = " + PssS_TQ1P
	 + ", PssS_TQ2 = " + PssS_TQ2
	 + ", PssS_TQ2P = " + PssS_TQ2P
	 + ", PssS_TQ3 = " + PssS_TQ3
	 + ", PssS_TQ3P = " + PssS_TQ3P
	 + ", PssS_VSmax = " + PssS_VSmax
	 + ", PssS_VCutOff = " + PssS_VCutOff
	 + ", PssS_VSlow = " + PssS_VSlow
	 + ", PssS_KQBase = " + PssS_KQBase
	 + ", PssS_RBusName = " + PssS_RBusName
	 + ", PssS_RBuskV = " + PssS_RBuskV
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", PssS_iRRBus = " + PssS_iRRBus
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
