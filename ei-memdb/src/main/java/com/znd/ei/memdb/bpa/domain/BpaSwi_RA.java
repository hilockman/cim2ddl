package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*低压线路断开保护(RA)	*
***********************/
public class BpaSwi_RA  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线名称1
  private String RA_BusI;
  
  //基准电压1(kV)
  private Double RA_kVI;
  
  //母线名称2
  private String RA_BusJ;
  
  //基准电压2(kV)
  private Double RA_kVJ;
  
  //并联线路的回路标志
  private Integer RA_Loop;
  
  //控制母线名称1
  private String RA_CBus1;
  
  //控制母线基准电压1(kV)
  private Double RA_CkV1;
  
  //母线1低电压限制值(pu)
  private Double RA_V1;
  
  //母线1低电压时间延迟(周)
  private Double RA_T1;
  
  //控制母线名称2
  private String RA_CBus2;
  
  //控制母线基准电压2(kV)
  private Double RA_CkV2;
  
  //母线2低电压限制值(pu)
  private Double RA_V2;
  
  //母线2低电压时间延迟(周)
  private Double RA_T2;
  
  //线路名称
  private String KeyName;
  
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
    
  public String getRA_BusI()
  {
    return RA_BusI;
  }
    
  public void setRA_BusI(String RA_BusI)
  {
    this.RA_BusI = RA_BusI;
  }
    
  public Double getRA_kVI()
  {
    return RA_kVI;
  }
    
  public void setRA_kVI(Double RA_kVI)
  {
    this.RA_kVI = RA_kVI;
  }
    
  public String getRA_BusJ()
  {
    return RA_BusJ;
  }
    
  public void setRA_BusJ(String RA_BusJ)
  {
    this.RA_BusJ = RA_BusJ;
  }
    
  public Double getRA_kVJ()
  {
    return RA_kVJ;
  }
    
  public void setRA_kVJ(Double RA_kVJ)
  {
    this.RA_kVJ = RA_kVJ;
  }
    
  public Integer getRA_Loop()
  {
    return RA_Loop;
  }
    
  public void setRA_Loop(Integer RA_Loop)
  {
    this.RA_Loop = RA_Loop;
  }
    
  public String getRA_CBus1()
  {
    return RA_CBus1;
  }
    
  public void setRA_CBus1(String RA_CBus1)
  {
    this.RA_CBus1 = RA_CBus1;
  }
    
  public Double getRA_CkV1()
  {
    return RA_CkV1;
  }
    
  public void setRA_CkV1(Double RA_CkV1)
  {
    this.RA_CkV1 = RA_CkV1;
  }
    
  public Double getRA_V1()
  {
    return RA_V1;
  }
    
  public void setRA_V1(Double RA_V1)
  {
    this.RA_V1 = RA_V1;
  }
    
  public Double getRA_T1()
  {
    return RA_T1;
  }
    
  public void setRA_T1(Double RA_T1)
  {
    this.RA_T1 = RA_T1;
  }
    
  public String getRA_CBus2()
  {
    return RA_CBus2;
  }
    
  public void setRA_CBus2(String RA_CBus2)
  {
    this.RA_CBus2 = RA_CBus2;
  }
    
  public Double getRA_CkV2()
  {
    return RA_CkV2;
  }
    
  public void setRA_CkV2(Double RA_CkV2)
  {
    this.RA_CkV2 = RA_CkV2;
  }
    
  public Double getRA_V2()
  {
    return RA_V2;
  }
    
  public void setRA_V2(Double RA_V2)
  {
    this.RA_V2 = RA_V2;
  }
    
  public Double getRA_T2()
  {
    return RA_T2;
  }
    
  public void setRA_T2(Double RA_T2)
  {
    this.RA_T2 = RA_T2;
  }
    
  public String getKeyName()
  {
    return KeyName;
  }
    
  public void setKeyName(String KeyName)
  {
    this.KeyName = KeyName;
  }
    
  public String toString()
  {
    return "BpaSwi_RA ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", RA_BusI = " + RA_BusI
	 + ", RA_kVI = " + RA_kVI
	 + ", RA_BusJ = " + RA_BusJ
	 + ", RA_kVJ = " + RA_kVJ
	 + ", RA_Loop = " + RA_Loop
	 + ", RA_CBus1 = " + RA_CBus1
	 + ", RA_CkV1 = " + RA_CkV1
	 + ", RA_V1 = " + RA_V1
	 + ", RA_T1 = " + RA_T1
	 + ", RA_CBus2 = " + RA_CBus2
	 + ", RA_CkV2 = " + RA_CkV2
	 + ", RA_V2 = " + RA_V2
	 + ", RA_T2 = " + RA_T2
	 + ", KeyName = " + KeyName+"]";
  }
    
}
    
