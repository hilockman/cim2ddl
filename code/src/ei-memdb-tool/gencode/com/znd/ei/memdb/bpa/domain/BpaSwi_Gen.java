package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*发电机模型表(MC/MF/MG)	*
***********************/
public class BpaSwi_Gen  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //电机母线名
  private String ACBus_Name;
  
  //电机母线电压(kV)
  private Double ACBus_kV;
  
  //电机识别码
  private Integer Gen_ID;
  
  //发电机动能(MW.秒)
  private Double Gen_Emws;
  
  //发电机初始有功功率占母线潮流功率比例
  private Double Gen_P;
  
  //发电机初始无功功率占母线潮流功率比例
  private Double Gen_Q;
  
  //电机标么参数的基准容量
  private Double Gen_MVABase;
  
  //定子电阻(pu)
  private Double Gen_Ra;
  
  //直轴暂态电抗Xdp(pu)
  private Double Gen_Xdp;
  
  //交流暂态电抗Xqp(pu)
  private Double Gen_Xqp;
  
  //直轴不饱和同步电抗Xd(pu)
  private Double Gen_Xd;
  
  //交轴不饱和同步电抗Xq(pu)
  private Double Gen_Xq;
  
  //直轴暂态开路时间常数Tdop(秒)
  private Double Gen_Td0;
  
  //交轴暂态开路时间常数Tqop(秒)
  private Double Gen_Tq0;
  
  //定子漏抗(pu)
  private Double Gen_XL_XP;
  
  //额定电压时电机饱和系数
  private Double Gen_SG10;
  
  //额定电压1.2倍时电机饱和系数
  private Double Gen_SG12;
  
  //电机阻尼转距系数百分数
  private Double Gen_D;
  
  //饱和a
  private Double Gen_A;
  
  //饱和b
  private Double Gen_B;
  
  //饱和N
  private Double Gen_N;
  
  //容量
  private Double Gen_MVA;
  
  //数据库主键
  private String KeyName;
  
  //发电机母线索引
  private Integer BusPtr;
  
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
    
  public Double getGen_Emws()
  {
    return Gen_Emws;
  }
    
  public void setGen_Emws(Double Gen_Emws)
  {
    this.Gen_Emws = Gen_Emws;
  }
    
  public Double getGen_P()
  {
    return Gen_P;
  }
    
  public void setGen_P(Double Gen_P)
  {
    this.Gen_P = Gen_P;
  }
    
  public Double getGen_Q()
  {
    return Gen_Q;
  }
    
  public void setGen_Q(Double Gen_Q)
  {
    this.Gen_Q = Gen_Q;
  }
    
  public Double getGen_MVABase()
  {
    return Gen_MVABase;
  }
    
  public void setGen_MVABase(Double Gen_MVABase)
  {
    this.Gen_MVABase = Gen_MVABase;
  }
    
  public Double getGen_Ra()
  {
    return Gen_Ra;
  }
    
  public void setGen_Ra(Double Gen_Ra)
  {
    this.Gen_Ra = Gen_Ra;
  }
    
  public Double getGen_Xdp()
  {
    return Gen_Xdp;
  }
    
  public void setGen_Xdp(Double Gen_Xdp)
  {
    this.Gen_Xdp = Gen_Xdp;
  }
    
  public Double getGen_Xqp()
  {
    return Gen_Xqp;
  }
    
  public void setGen_Xqp(Double Gen_Xqp)
  {
    this.Gen_Xqp = Gen_Xqp;
  }
    
  public Double getGen_Xd()
  {
    return Gen_Xd;
  }
    
  public void setGen_Xd(Double Gen_Xd)
  {
    this.Gen_Xd = Gen_Xd;
  }
    
  public Double getGen_Xq()
  {
    return Gen_Xq;
  }
    
  public void setGen_Xq(Double Gen_Xq)
  {
    this.Gen_Xq = Gen_Xq;
  }
    
  public Double getGen_Td0()
  {
    return Gen_Td0;
  }
    
  public void setGen_Td0(Double Gen_Td0)
  {
    this.Gen_Td0 = Gen_Td0;
  }
    
  public Double getGen_Tq0()
  {
    return Gen_Tq0;
  }
    
  public void setGen_Tq0(Double Gen_Tq0)
  {
    this.Gen_Tq0 = Gen_Tq0;
  }
    
  public Double getGen_XL_XP()
  {
    return Gen_XL_XP;
  }
    
  public void setGen_XL_XP(Double Gen_XL_XP)
  {
    this.Gen_XL_XP = Gen_XL_XP;
  }
    
  public Double getGen_SG10()
  {
    return Gen_SG10;
  }
    
  public void setGen_SG10(Double Gen_SG10)
  {
    this.Gen_SG10 = Gen_SG10;
  }
    
  public Double getGen_SG12()
  {
    return Gen_SG12;
  }
    
  public void setGen_SG12(Double Gen_SG12)
  {
    this.Gen_SG12 = Gen_SG12;
  }
    
  public Double getGen_D()
  {
    return Gen_D;
  }
    
  public void setGen_D(Double Gen_D)
  {
    this.Gen_D = Gen_D;
  }
    
  public Double getGen_A()
  {
    return Gen_A;
  }
    
  public void setGen_A(Double Gen_A)
  {
    this.Gen_A = Gen_A;
  }
    
  public Double getGen_B()
  {
    return Gen_B;
  }
    
  public void setGen_B(Double Gen_B)
  {
    this.Gen_B = Gen_B;
  }
    
  public Double getGen_N()
  {
    return Gen_N;
  }
    
  public void setGen_N(Double Gen_N)
  {
    this.Gen_N = Gen_N;
  }
    
  public Double getGen_MVA()
  {
    return Gen_MVA;
  }
    
  public void setGen_MVA(Double Gen_MVA)
  {
    this.Gen_MVA = Gen_MVA;
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
    return "BpaSwi_Gen ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", Gen_Emws = " + Gen_Emws
	 + ", Gen_P = " + Gen_P
	 + ", Gen_Q = " + Gen_Q
	 + ", Gen_MVABase = " + Gen_MVABase
	 + ", Gen_Ra = " + Gen_Ra
	 + ", Gen_Xdp = " + Gen_Xdp
	 + ", Gen_Xqp = " + Gen_Xqp
	 + ", Gen_Xd = " + Gen_Xd
	 + ", Gen_Xq = " + Gen_Xq
	 + ", Gen_Td0 = " + Gen_Td0
	 + ", Gen_Tq0 = " + Gen_Tq0
	 + ", Gen_XL_XP = " + Gen_XL_XP
	 + ", Gen_SG10 = " + Gen_SG10
	 + ", Gen_SG12 = " + Gen_SG12
	 + ", Gen_D = " + Gen_D
	 + ", Gen_A = " + Gen_A
	 + ", Gen_B = " + Gen_B
	 + ", Gen_N = " + Gen_N
	 + ", Gen_MVA = " + Gen_MVA
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
