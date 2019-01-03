package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*修改调速器频率参考信息表(IGV)	*
***********************/
public class BpaSwi_IGV  implements MemIndexable 
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
  
  //频率变化的起始时刻(周)
  private Double IGV_Tstart;
  
  //第1个点对应的时刻(周)
  private Double IGV_T1;
  
  //第1个点对应的频率变化量(Hz)
  private Double IGV_FREQ1;
  
  //第2个点对应的时刻(周)
  private Double IGV_T2;
  
  //第2个点对应的频率变化量(Hz)
  private Double IGV_FREQ2;
  
  //第3个点对应的时刻(周)
  private Double IGV_T3;
  
  //第3个点对应的频率变化量(Hz)
  private Double IGV_FREQ3;
  
  //第4个点对应的时刻(周)
  private Double IGV_T4;
  
  //第4个点对应的频率变化量(Hz)
  private Double IGV_FREQ4;
  
  //第5个点对应的时刻(周)
  private Double IGV_T5;
  
  //第5个点对应的频率变化量(Hz)
  private Double IGV_FREQ5;
  
  //第6个点对应的时刻(周)
  private Double IGV_T6;
  
  //第6个点对应的频率变化量(Hz)
  private Double IGV_FREQ6;
  
  //第7个点对应的时刻(周)
  private Double IGV_T7;
  
  //第7个点对应的频率变化量(Hz)
  private Double IGV_FREQ7;
  
  //第8个点对应的时刻(周)
  private Double IGV_T8;
  
  //第8个点对应的频率变化量(Hz)
  private Double IGV_FREQ8;
  
  //第9个点对应的时刻(周)
  private Double IGV_T9;
  
  //第9个点对应的频率变化量(Hz)
  private Double IGV_FREQ9;
  
  //第10个点对应的时刻(周)
  private Double IGV_T10;
  
  //第10个点对应的频率变化量(Hz)
  private Double IGV_FREQ10;
  
  //第11个点对应的时刻(周)
  private Double IGV_T11;
  
  //第11个点对应的频率变化量(Hz)
  private Double IGV_FREQ11;
  
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
    
  public Double getIGV_Tstart()
  {
    return IGV_Tstart;
  }
    
  public void setIGV_Tstart(Double IGV_Tstart)
  {
    this.IGV_Tstart = IGV_Tstart;
  }
    
  public Double getIGV_T1()
  {
    return IGV_T1;
  }
    
  public void setIGV_T1(Double IGV_T1)
  {
    this.IGV_T1 = IGV_T1;
  }
    
  public Double getIGV_FREQ1()
  {
    return IGV_FREQ1;
  }
    
  public void setIGV_FREQ1(Double IGV_FREQ1)
  {
    this.IGV_FREQ1 = IGV_FREQ1;
  }
    
  public Double getIGV_T2()
  {
    return IGV_T2;
  }
    
  public void setIGV_T2(Double IGV_T2)
  {
    this.IGV_T2 = IGV_T2;
  }
    
  public Double getIGV_FREQ2()
  {
    return IGV_FREQ2;
  }
    
  public void setIGV_FREQ2(Double IGV_FREQ2)
  {
    this.IGV_FREQ2 = IGV_FREQ2;
  }
    
  public Double getIGV_T3()
  {
    return IGV_T3;
  }
    
  public void setIGV_T3(Double IGV_T3)
  {
    this.IGV_T3 = IGV_T3;
  }
    
  public Double getIGV_FREQ3()
  {
    return IGV_FREQ3;
  }
    
  public void setIGV_FREQ3(Double IGV_FREQ3)
  {
    this.IGV_FREQ3 = IGV_FREQ3;
  }
    
  public Double getIGV_T4()
  {
    return IGV_T4;
  }
    
  public void setIGV_T4(Double IGV_T4)
  {
    this.IGV_T4 = IGV_T4;
  }
    
  public Double getIGV_FREQ4()
  {
    return IGV_FREQ4;
  }
    
  public void setIGV_FREQ4(Double IGV_FREQ4)
  {
    this.IGV_FREQ4 = IGV_FREQ4;
  }
    
  public Double getIGV_T5()
  {
    return IGV_T5;
  }
    
  public void setIGV_T5(Double IGV_T5)
  {
    this.IGV_T5 = IGV_T5;
  }
    
  public Double getIGV_FREQ5()
  {
    return IGV_FREQ5;
  }
    
  public void setIGV_FREQ5(Double IGV_FREQ5)
  {
    this.IGV_FREQ5 = IGV_FREQ5;
  }
    
  public Double getIGV_T6()
  {
    return IGV_T6;
  }
    
  public void setIGV_T6(Double IGV_T6)
  {
    this.IGV_T6 = IGV_T6;
  }
    
  public Double getIGV_FREQ6()
  {
    return IGV_FREQ6;
  }
    
  public void setIGV_FREQ6(Double IGV_FREQ6)
  {
    this.IGV_FREQ6 = IGV_FREQ6;
  }
    
  public Double getIGV_T7()
  {
    return IGV_T7;
  }
    
  public void setIGV_T7(Double IGV_T7)
  {
    this.IGV_T7 = IGV_T7;
  }
    
  public Double getIGV_FREQ7()
  {
    return IGV_FREQ7;
  }
    
  public void setIGV_FREQ7(Double IGV_FREQ7)
  {
    this.IGV_FREQ7 = IGV_FREQ7;
  }
    
  public Double getIGV_T8()
  {
    return IGV_T8;
  }
    
  public void setIGV_T8(Double IGV_T8)
  {
    this.IGV_T8 = IGV_T8;
  }
    
  public Double getIGV_FREQ8()
  {
    return IGV_FREQ8;
  }
    
  public void setIGV_FREQ8(Double IGV_FREQ8)
  {
    this.IGV_FREQ8 = IGV_FREQ8;
  }
    
  public Double getIGV_T9()
  {
    return IGV_T9;
  }
    
  public void setIGV_T9(Double IGV_T9)
  {
    this.IGV_T9 = IGV_T9;
  }
    
  public Double getIGV_FREQ9()
  {
    return IGV_FREQ9;
  }
    
  public void setIGV_FREQ9(Double IGV_FREQ9)
  {
    this.IGV_FREQ9 = IGV_FREQ9;
  }
    
  public Double getIGV_T10()
  {
    return IGV_T10;
  }
    
  public void setIGV_T10(Double IGV_T10)
  {
    this.IGV_T10 = IGV_T10;
  }
    
  public Double getIGV_FREQ10()
  {
    return IGV_FREQ10;
  }
    
  public void setIGV_FREQ10(Double IGV_FREQ10)
  {
    this.IGV_FREQ10 = IGV_FREQ10;
  }
    
  public Double getIGV_T11()
  {
    return IGV_T11;
  }
    
  public void setIGV_T11(Double IGV_T11)
  {
    this.IGV_T11 = IGV_T11;
  }
    
  public Double getIGV_FREQ11()
  {
    return IGV_FREQ11;
  }
    
  public void setIGV_FREQ11(Double IGV_FREQ11)
  {
    this.IGV_FREQ11 = IGV_FREQ11;
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
    return "BpaSwi_IGV ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_KV = " + ACBus_KV
	 + ", Gen_ID = " + Gen_ID
	 + ", IGV_Tstart = " + IGV_Tstart
	 + ", IGV_T1 = " + IGV_T1
	 + ", IGV_FREQ1 = " + IGV_FREQ1
	 + ", IGV_T2 = " + IGV_T2
	 + ", IGV_FREQ2 = " + IGV_FREQ2
	 + ", IGV_T3 = " + IGV_T3
	 + ", IGV_FREQ3 = " + IGV_FREQ3
	 + ", IGV_T4 = " + IGV_T4
	 + ", IGV_FREQ4 = " + IGV_FREQ4
	 + ", IGV_T5 = " + IGV_T5
	 + ", IGV_FREQ5 = " + IGV_FREQ5
	 + ", IGV_T6 = " + IGV_T6
	 + ", IGV_FREQ6 = " + IGV_FREQ6
	 + ", IGV_T7 = " + IGV_T7
	 + ", IGV_FREQ7 = " + IGV_FREQ7
	 + ", IGV_T8 = " + IGV_T8
	 + ", IGV_FREQ8 = " + IGV_FREQ8
	 + ", IGV_T9 = " + IGV_T9
	 + ", IGV_FREQ9 = " + IGV_FREQ9
	 + ", IGV_T10 = " + IGV_T10
	 + ", IGV_FREQ10 = " + IGV_FREQ10
	 + ", IGV_T11 = " + IGV_T11
	 + ", IGV_FREQ11 = " + IGV_FREQ11
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
