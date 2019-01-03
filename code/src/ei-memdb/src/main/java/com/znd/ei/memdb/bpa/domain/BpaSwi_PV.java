package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*光伏模型	*
***********************/
public class BpaSwi_PV  implements MemIndexable 
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
  
  //实际温度(℃)
  private Double T;
  
  //光照强度(W/m1)
  private Double S;
  
  //单体电池标准条件下的开路电压(V)
  private Double Uoc;
  
  //单体电池标准条件下的短路电流(A)
  private Double Isc;
  
  //单体电池标准条件下的最大功率点电压(V)
  private Double Um;
  
  //单体电池标准条件下的最大功率点电流(A)
  private Double Im;
  
  //光伏阵列并联电池组数
  private Integer N1;
  
  //光伏阵列串联电池组数
  private Integer N2;
  
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
    
  public Double getT()
  {
    return T;
  }
    
  public void setT(Double T)
  {
    this.T = T;
  }
    
  public Double getS()
  {
    return S;
  }
    
  public void setS(Double S)
  {
    this.S = S;
  }
    
  public Double getUoc()
  {
    return Uoc;
  }
    
  public void setUoc(Double Uoc)
  {
    this.Uoc = Uoc;
  }
    
  public Double getIsc()
  {
    return Isc;
  }
    
  public void setIsc(Double Isc)
  {
    this.Isc = Isc;
  }
    
  public Double getUm()
  {
    return Um;
  }
    
  public void setUm(Double Um)
  {
    this.Um = Um;
  }
    
  public Double getIm()
  {
    return Im;
  }
    
  public void setIm(Double Im)
  {
    this.Im = Im;
  }
    
  public Integer getN1()
  {
    return N1;
  }
    
  public void setN1(Integer N1)
  {
    this.N1 = N1;
  }
    
  public Integer getN2()
  {
    return N2;
  }
    
  public void setN2(Integer N2)
  {
    this.N2 = N2;
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
    return "BpaSwi_PV ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", T = " + T
	 + ", S = " + S
	 + ", Uoc = " + Uoc
	 + ", Isc = " + Isc
	 + ", Um = " + Um
	 + ", Im = " + Im
	 + ", N1 = " + N1
	 + ", N2 = " + N2
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
