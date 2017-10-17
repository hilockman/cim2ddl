package com.znd.ei.memdb.bpa.domain;


/**********************
*发电机模型表(MC/MF/MG)	*
***********************/
public class BpaSwi_Gen
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
  
  //发电机动能(MW.秒)
  private Double gen_Emws;
  
  //发电机初始有功功率占母线潮流功率比例
  private Double gen_P;
  
  //发电机初始无功功率占母线潮流功率比例
  private Double gen_Q;
  
  //电机标么参数的基准容量
  private Double gen_MVABase;
  
  //定子电阻(pu)
  private Double gen_Ra;
  
  //直轴暂态电抗Xdp(pu)
  private Double gen_Xdp;
  
  //交流暂态电抗Xqp(pu)
  private Double gen_Xqp;
  
  //直轴不饱和同步电抗Xd(pu)
  private Double gen_Xd;
  
  //交轴不饱和同步电抗Xq(pu)
  private Double gen_Xq;
  
  //直轴暂态开路时间常数Tdop(秒)
  private Double gen_Td0;
  
  //交轴暂态开路时间常数Tqop(秒)
  private Double gen_Tq0;
  
  //定子漏抗(pu)
  private Double gen_XL_XP;
  
  //额定电压时电机饱和系数
  private Double gen_SG10;
  
  //额定电压1.2倍时电机饱和系数
  private Double gen_SG12;
  
  //电机阻尼转距系数百分数
  private Double gen_D;
  
  //饱和a
  private Double gen_A;
  
  //饱和b
  private Double gen_B;
  
  //饱和N
  private Double gen_N;
  
  //容量
  private Double gen_MVA;
  
  //数据库主键
  private String keyName;
  
  //发电机母线索引
  private Integer busPtr;
  
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
    
  public Double getGen_Emws()
  {
    return gen_Emws;
  }
    
  public void setGen_Emws(Double gen_Emws)
  {
    this.gen_Emws = gen_Emws;
  }
    
  public Double getGen_P()
  {
    return gen_P;
  }
    
  public void setGen_P(Double gen_P)
  {
    this.gen_P = gen_P;
  }
    
  public Double getGen_Q()
  {
    return gen_Q;
  }
    
  public void setGen_Q(Double gen_Q)
  {
    this.gen_Q = gen_Q;
  }
    
  public Double getGen_MVABase()
  {
    return gen_MVABase;
  }
    
  public void setGen_MVABase(Double gen_MVABase)
  {
    this.gen_MVABase = gen_MVABase;
  }
    
  public Double getGen_Ra()
  {
    return gen_Ra;
  }
    
  public void setGen_Ra(Double gen_Ra)
  {
    this.gen_Ra = gen_Ra;
  }
    
  public Double getGen_Xdp()
  {
    return gen_Xdp;
  }
    
  public void setGen_Xdp(Double gen_Xdp)
  {
    this.gen_Xdp = gen_Xdp;
  }
    
  public Double getGen_Xqp()
  {
    return gen_Xqp;
  }
    
  public void setGen_Xqp(Double gen_Xqp)
  {
    this.gen_Xqp = gen_Xqp;
  }
    
  public Double getGen_Xd()
  {
    return gen_Xd;
  }
    
  public void setGen_Xd(Double gen_Xd)
  {
    this.gen_Xd = gen_Xd;
  }
    
  public Double getGen_Xq()
  {
    return gen_Xq;
  }
    
  public void setGen_Xq(Double gen_Xq)
  {
    this.gen_Xq = gen_Xq;
  }
    
  public Double getGen_Td0()
  {
    return gen_Td0;
  }
    
  public void setGen_Td0(Double gen_Td0)
  {
    this.gen_Td0 = gen_Td0;
  }
    
  public Double getGen_Tq0()
  {
    return gen_Tq0;
  }
    
  public void setGen_Tq0(Double gen_Tq0)
  {
    this.gen_Tq0 = gen_Tq0;
  }
    
  public Double getGen_XL_XP()
  {
    return gen_XL_XP;
  }
    
  public void setGen_XL_XP(Double gen_XL_XP)
  {
    this.gen_XL_XP = gen_XL_XP;
  }
    
  public Double getGen_SG10()
  {
    return gen_SG10;
  }
    
  public void setGen_SG10(Double gen_SG10)
  {
    this.gen_SG10 = gen_SG10;
  }
    
  public Double getGen_SG12()
  {
    return gen_SG12;
  }
    
  public void setGen_SG12(Double gen_SG12)
  {
    this.gen_SG12 = gen_SG12;
  }
    
  public Double getGen_D()
  {
    return gen_D;
  }
    
  public void setGen_D(Double gen_D)
  {
    this.gen_D = gen_D;
  }
    
  public Double getGen_A()
  {
    return gen_A;
  }
    
  public void setGen_A(Double gen_A)
  {
    this.gen_A = gen_A;
  }
    
  public Double getGen_B()
  {
    return gen_B;
  }
    
  public void setGen_B(Double gen_B)
  {
    this.gen_B = gen_B;
  }
    
  public Double getGen_N()
  {
    return gen_N;
  }
    
  public void setGen_N(Double gen_N)
  {
    this.gen_N = gen_N;
  }
    
  public Double getGen_MVA()
  {
    return gen_MVA;
  }
    
  public void setGen_MVA(Double gen_MVA)
  {
    this.gen_MVA = gen_MVA;
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
    return "BpaSwi_Gen ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", gen_Emws = " + gen_Emws
	 + ", gen_P = " + gen_P
	 + ", gen_Q = " + gen_Q
	 + ", gen_MVABase = " + gen_MVABase
	 + ", gen_Ra = " + gen_Ra
	 + ", gen_Xdp = " + gen_Xdp
	 + ", gen_Xqp = " + gen_Xqp
	 + ", gen_Xd = " + gen_Xd
	 + ", gen_Xq = " + gen_Xq
	 + ", gen_Td0 = " + gen_Td0
	 + ", gen_Tq0 = " + gen_Tq0
	 + ", gen_XL_XP = " + gen_XL_XP
	 + ", gen_SG10 = " + gen_SG10
	 + ", gen_SG12 = " + gen_SG12
	 + ", gen_D = " + gen_D
	 + ", gen_A = " + gen_A
	 + ", gen_B = " + gen_B
	 + ", gen_N = " + gen_N
	 + ", gen_MVA = " + gen_MVA
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
