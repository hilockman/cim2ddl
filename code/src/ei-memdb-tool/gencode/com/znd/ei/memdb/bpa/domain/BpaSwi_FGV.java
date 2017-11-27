package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*发电机机械功率周期波动表(FGV)	*
***********************/
public class BpaSwi_FGV  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //发电机名称
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_KV;
  
  //发电机识别码ID
  private Integer Gen_ID;
  
  //第一个波动的幅值,百分数或有名值
  private Double FGV_AMP1;
  
  //第一个波动的频率(弧度/秒)
  private Double FGV_FREQ1;
  
  //第一个波动的初始相位(弧度)
  private Double FGV_ANGL01;
  
  //第一个波动的起始时间(周)
  private Double FGV_TBEGIN1;
  
  //第一个波动的结束时间(周)
  private Double FGV_TEND1;
  
  //第二个波动的幅值,百分数或有名值
  private Double FGV_AMP2;
  
  //第二个波动的频率(弧度/秒)
  private Double FGV_FREQ2;
  
  //第二个波动的初始相位(弧度)
  private Double FGV_ANGL02;
  
  //第二个波动的起始时间(周)
  private Double FGV_TBEGIN2;
  
  //第二个波动的结束时间(周)
  private Double FGV_TEND2;
  
  //空格表示前两个波动的幅值都是发电机机械功率初值的百分数;W,为有名值
  private Integer FGV_CMW;
  
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
    
  public Double getFGV_AMP1()
  {
    return FGV_AMP1;
  }
    
  public void setFGV_AMP1(Double FGV_AMP1)
  {
    this.FGV_AMP1 = FGV_AMP1;
  }
    
  public Double getFGV_FREQ1()
  {
    return FGV_FREQ1;
  }
    
  public void setFGV_FREQ1(Double FGV_FREQ1)
  {
    this.FGV_FREQ1 = FGV_FREQ1;
  }
    
  public Double getFGV_ANGL01()
  {
    return FGV_ANGL01;
  }
    
  public void setFGV_ANGL01(Double FGV_ANGL01)
  {
    this.FGV_ANGL01 = FGV_ANGL01;
  }
    
  public Double getFGV_TBEGIN1()
  {
    return FGV_TBEGIN1;
  }
    
  public void setFGV_TBEGIN1(Double FGV_TBEGIN1)
  {
    this.FGV_TBEGIN1 = FGV_TBEGIN1;
  }
    
  public Double getFGV_TEND1()
  {
    return FGV_TEND1;
  }
    
  public void setFGV_TEND1(Double FGV_TEND1)
  {
    this.FGV_TEND1 = FGV_TEND1;
  }
    
  public Double getFGV_AMP2()
  {
    return FGV_AMP2;
  }
    
  public void setFGV_AMP2(Double FGV_AMP2)
  {
    this.FGV_AMP2 = FGV_AMP2;
  }
    
  public Double getFGV_FREQ2()
  {
    return FGV_FREQ2;
  }
    
  public void setFGV_FREQ2(Double FGV_FREQ2)
  {
    this.FGV_FREQ2 = FGV_FREQ2;
  }
    
  public Double getFGV_ANGL02()
  {
    return FGV_ANGL02;
  }
    
  public void setFGV_ANGL02(Double FGV_ANGL02)
  {
    this.FGV_ANGL02 = FGV_ANGL02;
  }
    
  public Double getFGV_TBEGIN2()
  {
    return FGV_TBEGIN2;
  }
    
  public void setFGV_TBEGIN2(Double FGV_TBEGIN2)
  {
    this.FGV_TBEGIN2 = FGV_TBEGIN2;
  }
    
  public Double getFGV_TEND2()
  {
    return FGV_TEND2;
  }
    
  public void setFGV_TEND2(Double FGV_TEND2)
  {
    this.FGV_TEND2 = FGV_TEND2;
  }
    
  public Integer getFGV_CMW()
  {
    return FGV_CMW;
  }
    
  public void setFGV_CMW(Integer FGV_CMW)
  {
    this.FGV_CMW = FGV_CMW;
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
    return "BpaSwi_FGV ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_KV = " + ACBus_KV
	 + ", Gen_ID = " + Gen_ID
	 + ", FGV_AMP1 = " + FGV_AMP1
	 + ", FGV_FREQ1 = " + FGV_FREQ1
	 + ", FGV_ANGL01 = " + FGV_ANGL01
	 + ", FGV_TBEGIN1 = " + FGV_TBEGIN1
	 + ", FGV_TEND1 = " + FGV_TEND1
	 + ", FGV_AMP2 = " + FGV_AMP2
	 + ", FGV_FREQ2 = " + FGV_FREQ2
	 + ", FGV_ANGL02 = " + FGV_ANGL02
	 + ", FGV_TBEGIN2 = " + FGV_TBEGIN2
	 + ", FGV_TEND2 = " + FGV_TEND2
	 + ", FGV_CMW = " + FGV_CMW
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
