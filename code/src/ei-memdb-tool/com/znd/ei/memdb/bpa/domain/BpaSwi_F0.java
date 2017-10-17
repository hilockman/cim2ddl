package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*监视曲线控制卡(F0)	*
***********************/
@Entity
public class BpaSwi_F0
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //稳定曲线显示选择
  private Integer iG;
  
  //发电机最大相对角显示选择
  private Integer iA;
  
  //发电机1母线名称
  private String genBusName1;
  
  //发电机1母线电压
  private Double genBusBase1;
  
  //发电机1识别码
  private Integer genID1;
  
  //发电机2母线名称
  private String genBusName2;
  
  //发电机2母线电压
  private Double genBusBase2;
  
  //发电机2识别码
  private Integer genID2;
  
  //相对角Y轴坐标的最大值
  private Double aMAX;
  
  //相对角Y轴坐标的最小值
  private Double aMIN;
  
  //母线电压显示选择
  private Integer iV;
  
  //显示电压变化曲线的母线名称
  private String vBUSNAME;
  
  //显示电压变化曲线的母线电压
  private Double vBUSVOLT;
  
  //母线频率显示选择
  private Integer iF;
  
  //显示频率变化曲线的母线名称
  private String fBUSNAME;
  
  //显示频率变化曲线的母线电压
  private Double fBUSVOLT;
  
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
    
  public Integer getIG() 
  {
    return iG;
  }
    
  public void setIG(Integer iG)
  {
    this.iG = iG;
  }
    
  public Integer getIA() 
  {
    return iA;
  }
    
  public void setIA(Integer iA)
  {
    this.iA = iA;
  }
    
  public String getGenBusName1() 
  {
    return genBusName1;
  }
    
  public void setGenBusName1(String genBusName1)
  {
    this.genBusName1 = genBusName1;
  }
    
  public Double getGenBusBase1() 
  {
    return genBusBase1;
  }
    
  public void setGenBusBase1(Double genBusBase1)
  {
    this.genBusBase1 = genBusBase1;
  }
    
  public Integer getGenID1() 
  {
    return genID1;
  }
    
  public void setGenID1(Integer genID1)
  {
    this.genID1 = genID1;
  }
    
  public String getGenBusName2() 
  {
    return genBusName2;
  }
    
  public void setGenBusName2(String genBusName2)
  {
    this.genBusName2 = genBusName2;
  }
    
  public Double getGenBusBase2() 
  {
    return genBusBase2;
  }
    
  public void setGenBusBase2(Double genBusBase2)
  {
    this.genBusBase2 = genBusBase2;
  }
    
  public Integer getGenID2() 
  {
    return genID2;
  }
    
  public void setGenID2(Integer genID2)
  {
    this.genID2 = genID2;
  }
    
  public Double getAMAX() 
  {
    return aMAX;
  }
    
  public void setAMAX(Double aMAX)
  {
    this.aMAX = aMAX;
  }
    
  public Double getAMIN() 
  {
    return aMIN;
  }
    
  public void setAMIN(Double aMIN)
  {
    this.aMIN = aMIN;
  }
    
  public Integer getIV() 
  {
    return iV;
  }
    
  public void setIV(Integer iV)
  {
    this.iV = iV;
  }
    
  public String getVBUSNAME() 
  {
    return vBUSNAME;
  }
    
  public void setVBUSNAME(String vBUSNAME)
  {
    this.vBUSNAME = vBUSNAME;
  }
    
  public Double getVBUSVOLT() 
  {
    return vBUSVOLT;
  }
    
  public void setVBUSVOLT(Double vBUSVOLT)
  {
    this.vBUSVOLT = vBUSVOLT;
  }
    
  public Integer getIF() 
  {
    return iF;
  }
    
  public void setIF(Integer iF)
  {
    this.iF = iF;
  }
    
  public String getFBUSNAME() 
  {
    return fBUSNAME;
  }
    
  public void setFBUSNAME(String fBUSNAME)
  {
    this.fBUSNAME = fBUSNAME;
  }
    
  public Double getFBUSVOLT() 
  {
    return fBUSVOLT;
  }
    
  public void setFBUSVOLT(Double fBUSVOLT)
  {
    this.fBUSVOLT = fBUSVOLT;
  }
    
}
    
