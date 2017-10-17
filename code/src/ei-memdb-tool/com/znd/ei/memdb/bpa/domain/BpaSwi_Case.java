package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*稳定计算控制卡(CASE)	*
***********************/
@Entity
public class BpaSwi_Case
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //潮流方式名
  private String pFCASE;
  
  //写求解文件的步长
  private Integer iTSKP;
  
  //NOPRNT,为1时打印全部输入数据
  private Integer nOPRNT;
  
  //输出文件摇摆曲线显示开关
  private Integer dSW;
  
  //采用新减负荷卡减负荷标记
  private Integer iWSCC;
  
  //对零序卡进行检查标志
  private Integer zSW;
  
  //不对称故障时发电机X2与Xdp之比
  private Double x2FAC;
  
  //发电机Xdpp与Xdp之比
  private Double xFACT;
  
  //隐级机的Tdopp(秒)
  private Double tDODPS;
  
  //隐级机的Tdopp(秒)
  private Double tQODPS;
  
  //凸级水轮机的Tqopp(秒)
  private Double tDODPH;
  
  //凸级水轮机的Tdopp(秒)
  private Double tQODPH;
  
  //负序负荷导纳(pu)
  private Double cFACL2;
  
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
    
  public String getPFCASE() 
  {
    return pFCASE;
  }
    
  public void setPFCASE(String pFCASE)
  {
    this.pFCASE = pFCASE;
  }
    
  public Integer getITSKP() 
  {
    return iTSKP;
  }
    
  public void setITSKP(Integer iTSKP)
  {
    this.iTSKP = iTSKP;
  }
    
  public Integer getNOPRNT() 
  {
    return nOPRNT;
  }
    
  public void setNOPRNT(Integer nOPRNT)
  {
    this.nOPRNT = nOPRNT;
  }
    
  public Integer getDSW() 
  {
    return dSW;
  }
    
  public void setDSW(Integer dSW)
  {
    this.dSW = dSW;
  }
    
  public Integer getIWSCC() 
  {
    return iWSCC;
  }
    
  public void setIWSCC(Integer iWSCC)
  {
    this.iWSCC = iWSCC;
  }
    
  public Integer getZSW() 
  {
    return zSW;
  }
    
  public void setZSW(Integer zSW)
  {
    this.zSW = zSW;
  }
    
  public Double getX2FAC() 
  {
    return x2FAC;
  }
    
  public void setX2FAC(Double x2FAC)
  {
    this.x2FAC = x2FAC;
  }
    
  public Double getXFACT() 
  {
    return xFACT;
  }
    
  public void setXFACT(Double xFACT)
  {
    this.xFACT = xFACT;
  }
    
  public Double getTDODPS() 
  {
    return tDODPS;
  }
    
  public void setTDODPS(Double tDODPS)
  {
    this.tDODPS = tDODPS;
  }
    
  public Double getTQODPS() 
  {
    return tQODPS;
  }
    
  public void setTQODPS(Double tQODPS)
  {
    this.tQODPS = tQODPS;
  }
    
  public Double getTDODPH() 
  {
    return tDODPH;
  }
    
  public void setTDODPH(Double tDODPH)
  {
    this.tDODPH = tDODPH;
  }
    
  public Double getTQODPH() 
  {
    return tQODPH;
  }
    
  public void setTQODPH(Double tQODPH)
  {
    this.tQODPH = tQODPH;
  }
    
  public Double getCFACL2() 
  {
    return cFACL2;
  }
    
  public void setCFACL2(Double cFACL2)
  {
    this.cFACL2 = cFACL2;
  }
    
}
    
