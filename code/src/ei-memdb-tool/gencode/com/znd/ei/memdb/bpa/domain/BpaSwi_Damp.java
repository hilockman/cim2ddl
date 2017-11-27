package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*发电机阻尼模型表(M)	*
***********************/
public class BpaSwi_Damp  implements MemIndexable 
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
  private Integer Damp_ID;
  
  //电机额定容量
  private Double Damp_MVA;
  
  //电机功率因数
  private Double Damp_PF;
  
  //直轴次暂态电抗Xdpp(pu)
  private Double Damp_Xdpp;
  
  //交轴次暂态电抗Xqpp(pu)
  private Double Damp_Xqpp;
  
  //直轴次暂态时间常数Td0pp(秒)
  private Double Damp_Td0pp;
  
  //交轴次暂态时间常数Tq0pp(秒)
  private Double Damp_Tq0pp;
  
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
    
  public Integer getDamp_ID()
  {
    return Damp_ID;
  }
    
  public void setDamp_ID(Integer Damp_ID)
  {
    this.Damp_ID = Damp_ID;
  }
    
  public Double getDamp_MVA()
  {
    return Damp_MVA;
  }
    
  public void setDamp_MVA(Double Damp_MVA)
  {
    this.Damp_MVA = Damp_MVA;
  }
    
  public Double getDamp_PF()
  {
    return Damp_PF;
  }
    
  public void setDamp_PF(Double Damp_PF)
  {
    this.Damp_PF = Damp_PF;
  }
    
  public Double getDamp_Xdpp()
  {
    return Damp_Xdpp;
  }
    
  public void setDamp_Xdpp(Double Damp_Xdpp)
  {
    this.Damp_Xdpp = Damp_Xdpp;
  }
    
  public Double getDamp_Xqpp()
  {
    return Damp_Xqpp;
  }
    
  public void setDamp_Xqpp(Double Damp_Xqpp)
  {
    this.Damp_Xqpp = Damp_Xqpp;
  }
    
  public Double getDamp_Td0pp()
  {
    return Damp_Td0pp;
  }
    
  public void setDamp_Td0pp(Double Damp_Td0pp)
  {
    this.Damp_Td0pp = Damp_Td0pp;
  }
    
  public Double getDamp_Tq0pp()
  {
    return Damp_Tq0pp;
  }
    
  public void setDamp_Tq0pp(Double Damp_Tq0pp)
  {
    this.Damp_Tq0pp = Damp_Tq0pp;
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
    return "BpaSwi_Damp ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Damp_ID = " + Damp_ID
	 + ", Damp_MVA = " + Damp_MVA
	 + ", Damp_PF = " + Damp_PF
	 + ", Damp_Xdpp = " + Damp_Xdpp
	 + ", Damp_Xqpp = " + Damp_Xqpp
	 + ", Damp_Td0pp = " + Damp_Td0pp
	 + ", Damp_Tq0pp = " + Damp_Tq0pp
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
