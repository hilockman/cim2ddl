package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*稳定计算控制卡(FF)	*
***********************/
@Entity
public class BpaSwi_FF
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //计算开始时间(周)
  private Double t;
  
  //计算步长(周)
  private Double dT;
  
  //计算终止时间(周)
  private Double eNDT;
  
  //新的步长(周)
  private Double dTC;
  
  //开始改变步长的时刻(周)
  private Integer iSTP;
  
  //两次迭代间最大加速功率误差范围
  private Double tOLI;
  
  //一步内网络方程与微分方程最大交替迭代次数
  private Integer iLIM;
  
  //两次迭代间最大角度误差范围
  private Double dELANG;
  
  //交流积分步长与直流积分步长之比
  private Double dTDV;
  
  //发电机阻尼因子
  private Double dMPMLT;
  
  //系统基准频率
  private Double fRQBSE;
  
  //=1无低电压检查,否则进行检查
  private Integer lOVTEX;
  
  //马达滑差达到1时的处理方法
  private Integer iMBLOK;
  
  //摇摆方程与定子方程与频率的关系
  private Integer mFDEP;
  
  //非零时,所有调速器模型GS都采用外限幅
  private Integer iGSLIM;
  
  //=1：迭代不收敛,停止计算
  private Integer lSOLQIT;
  
  //=1：无最大角度限制,否则机组间角度超过500度停算
  private Integer nOANGLIM;
  
  //=1：所有发电机改为无穷大惯性电机
  private Integer iNFBUS;
  
  //非零时,所有发电机都不考虑次暂态参数
  private Integer nOPP;
  
  //=1：所有发电机改为经典模型
  private Integer nODQ;
  
  //非零时,所有的发电机不考虑饱和
  private Integer nOSAT;
  
  //=1：所有发电机不计调速器
  private Integer nOGV;
  
  //非零时,所有发电机的磁链恒定
  private Integer iEQPC;
  
  //=1：所有发电机不计调压器
  private Integer nOEX;
  
  //非零时,所有的发电机卡MF卡都转换为MG卡
  private Integer mFTOMG;
  
  //=1：不计所有辅助信号
  private Integer nOSC;
  
  //非零时,所有的发电机卡MG卡都转换为MF卡
  private Integer mGTOMF;
  
  //=1：所有负荷为恒定阻抗
  private Integer nOLOAD;
  
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
    
  public Double getT() 
  {
    return t;
  }
    
  public void setT(Double t)
  {
    this.t = t;
  }
    
  public Double getDT() 
  {
    return dT;
  }
    
  public void setDT(Double dT)
  {
    this.dT = dT;
  }
    
  public Double getENDT() 
  {
    return eNDT;
  }
    
  public void setENDT(Double eNDT)
  {
    this.eNDT = eNDT;
  }
    
  public Double getDTC() 
  {
    return dTC;
  }
    
  public void setDTC(Double dTC)
  {
    this.dTC = dTC;
  }
    
  public Integer getISTP() 
  {
    return iSTP;
  }
    
  public void setISTP(Integer iSTP)
  {
    this.iSTP = iSTP;
  }
    
  public Double getTOLI() 
  {
    return tOLI;
  }
    
  public void setTOLI(Double tOLI)
  {
    this.tOLI = tOLI;
  }
    
  public Integer getILIM() 
  {
    return iLIM;
  }
    
  public void setILIM(Integer iLIM)
  {
    this.iLIM = iLIM;
  }
    
  public Double getDELANG() 
  {
    return dELANG;
  }
    
  public void setDELANG(Double dELANG)
  {
    this.dELANG = dELANG;
  }
    
  public Double getDTDV() 
  {
    return dTDV;
  }
    
  public void setDTDV(Double dTDV)
  {
    this.dTDV = dTDV;
  }
    
  public Double getDMPMLT() 
  {
    return dMPMLT;
  }
    
  public void setDMPMLT(Double dMPMLT)
  {
    this.dMPMLT = dMPMLT;
  }
    
  public Double getFRQBSE() 
  {
    return fRQBSE;
  }
    
  public void setFRQBSE(Double fRQBSE)
  {
    this.fRQBSE = fRQBSE;
  }
    
  public Integer getLOVTEX() 
  {
    return lOVTEX;
  }
    
  public void setLOVTEX(Integer lOVTEX)
  {
    this.lOVTEX = lOVTEX;
  }
    
  public Integer getIMBLOK() 
  {
    return iMBLOK;
  }
    
  public void setIMBLOK(Integer iMBLOK)
  {
    this.iMBLOK = iMBLOK;
  }
    
  public Integer getMFDEP() 
  {
    return mFDEP;
  }
    
  public void setMFDEP(Integer mFDEP)
  {
    this.mFDEP = mFDEP;
  }
    
  public Integer getIGSLIM() 
  {
    return iGSLIM;
  }
    
  public void setIGSLIM(Integer iGSLIM)
  {
    this.iGSLIM = iGSLIM;
  }
    
  public Integer getLSOLQIT() 
  {
    return lSOLQIT;
  }
    
  public void setLSOLQIT(Integer lSOLQIT)
  {
    this.lSOLQIT = lSOLQIT;
  }
    
  public Integer getNOANGLIM() 
  {
    return nOANGLIM;
  }
    
  public void setNOANGLIM(Integer nOANGLIM)
  {
    this.nOANGLIM = nOANGLIM;
  }
    
  public Integer getINFBUS() 
  {
    return iNFBUS;
  }
    
  public void setINFBUS(Integer iNFBUS)
  {
    this.iNFBUS = iNFBUS;
  }
    
  public Integer getNOPP() 
  {
    return nOPP;
  }
    
  public void setNOPP(Integer nOPP)
  {
    this.nOPP = nOPP;
  }
    
  public Integer getNODQ() 
  {
    return nODQ;
  }
    
  public void setNODQ(Integer nODQ)
  {
    this.nODQ = nODQ;
  }
    
  public Integer getNOSAT() 
  {
    return nOSAT;
  }
    
  public void setNOSAT(Integer nOSAT)
  {
    this.nOSAT = nOSAT;
  }
    
  public Integer getNOGV() 
  {
    return nOGV;
  }
    
  public void setNOGV(Integer nOGV)
  {
    this.nOGV = nOGV;
  }
    
  public Integer getIEQPC() 
  {
    return iEQPC;
  }
    
  public void setIEQPC(Integer iEQPC)
  {
    this.iEQPC = iEQPC;
  }
    
  public Integer getNOEX() 
  {
    return nOEX;
  }
    
  public void setNOEX(Integer nOEX)
  {
    this.nOEX = nOEX;
  }
    
  public Integer getMFTOMG() 
  {
    return mFTOMG;
  }
    
  public void setMFTOMG(Integer mFTOMG)
  {
    this.mFTOMG = mFTOMG;
  }
    
  public Integer getNOSC() 
  {
    return nOSC;
  }
    
  public void setNOSC(Integer nOSC)
  {
    this.nOSC = nOSC;
  }
    
  public Integer getMGTOMF() 
  {
    return mGTOMF;
  }
    
  public void setMGTOMF(Integer mGTOMF)
  {
    this.mGTOMF = mGTOMF;
  }
    
  public Integer getNOLOAD() 
  {
    return nOLOAD;
  }
    
  public void setNOLOAD(Integer nOLOAD)
  {
    this.nOLOAD = nOLOAD;
  }
    
}
    
