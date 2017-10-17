package com.znd.ei.memdb.bpa.domain;


/**********************
*低压线路断开保护(RA)	*
***********************/
public class BpaSwi_RA
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称1
  private String rA_BusI;
  
  //基准电压1(kV)
  private Double rA_kVI;
  
  //母线名称2
  private String rA_BusJ;
  
  //基准电压2(kV)
  private Double rA_kVJ;
  
  //并联线路的回路标志
  private Integer rA_Loop;
  
  //控制母线名称1
  private String rA_CBus1;
  
  //控制母线基准电压1(kV)
  private Double rA_CkV1;
  
  //母线1低电压限制值(pu)
  private Double rA_V1;
  
  //母线1低电压时间延迟(周)
  private Double rA_T1;
  
  //控制母线名称2
  private String rA_CBus2;
  
  //控制母线基准电压2(kV)
  private Double rA_CkV2;
  
  //母线2低电压限制值(pu)
  private Double rA_V2;
  
  //母线2低电压时间延迟(周)
  private Double rA_T2;
  
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
    
  public String getRA_BusI()
  {
    return rA_BusI;
  }
    
  public void setRA_BusI(String rA_BusI)
  {
    this.rA_BusI = rA_BusI;
  }
    
  public Double getRA_kVI()
  {
    return rA_kVI;
  }
    
  public void setRA_kVI(Double rA_kVI)
  {
    this.rA_kVI = rA_kVI;
  }
    
  public String getRA_BusJ()
  {
    return rA_BusJ;
  }
    
  public void setRA_BusJ(String rA_BusJ)
  {
    this.rA_BusJ = rA_BusJ;
  }
    
  public Double getRA_kVJ()
  {
    return rA_kVJ;
  }
    
  public void setRA_kVJ(Double rA_kVJ)
  {
    this.rA_kVJ = rA_kVJ;
  }
    
  public Integer getRA_Loop()
  {
    return rA_Loop;
  }
    
  public void setRA_Loop(Integer rA_Loop)
  {
    this.rA_Loop = rA_Loop;
  }
    
  public String getRA_CBus1()
  {
    return rA_CBus1;
  }
    
  public void setRA_CBus1(String rA_CBus1)
  {
    this.rA_CBus1 = rA_CBus1;
  }
    
  public Double getRA_CkV1()
  {
    return rA_CkV1;
  }
    
  public void setRA_CkV1(Double rA_CkV1)
  {
    this.rA_CkV1 = rA_CkV1;
  }
    
  public Double getRA_V1()
  {
    return rA_V1;
  }
    
  public void setRA_V1(Double rA_V1)
  {
    this.rA_V1 = rA_V1;
  }
    
  public Double getRA_T1()
  {
    return rA_T1;
  }
    
  public void setRA_T1(Double rA_T1)
  {
    this.rA_T1 = rA_T1;
  }
    
  public String getRA_CBus2()
  {
    return rA_CBus2;
  }
    
  public void setRA_CBus2(String rA_CBus2)
  {
    this.rA_CBus2 = rA_CBus2;
  }
    
  public Double getRA_CkV2()
  {
    return rA_CkV2;
  }
    
  public void setRA_CkV2(Double rA_CkV2)
  {
    this.rA_CkV2 = rA_CkV2;
  }
    
  public Double getRA_V2()
  {
    return rA_V2;
  }
    
  public void setRA_V2(Double rA_V2)
  {
    this.rA_V2 = rA_V2;
  }
    
  public Double getRA_T2()
  {
    return rA_T2;
  }
    
  public void setRA_T2(Double rA_T2)
  {
    this.rA_T2 = rA_T2;
  }
    
  public String toString()
  {
    return "BpaSwi_RA ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", rA_BusI = " + rA_BusI
	 + ", rA_kVI = " + rA_kVI
	 + ", rA_BusJ = " + rA_BusJ
	 + ", rA_kVJ = " + rA_kVJ
	 + ", rA_Loop = " + rA_Loop
	 + ", rA_CBus1 = " + rA_CBus1
	 + ", rA_CkV1 = " + rA_CkV1
	 + ", rA_V1 = " + rA_V1
	 + ", rA_T1 = " + rA_T1
	 + ", rA_CBus2 = " + rA_CBus2
	 + ", rA_CkV2 = " + rA_CkV2
	 + ", rA_V2 = " + rA_V2
	 + ", rA_T2 = " + rA_T2+"]";
  }
    
}
    
