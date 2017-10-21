package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*静止无功发生器(STATCOM)	*
***********************/
public class BpaSwi_VG  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线名称
  private String aCBus_Name;
  
  //母线基准电压(kV)
  private Double aCBus_KV;
  
  //额定容量
  private Double mvaBase;
  
  //滤波器和测量回路的时间常数(秒)
  private Double t1;
  
  //第一级超前时间常数(秒)
  private Double t2;
  
  //第一级滞后时间常数(秒)
  private Double t3;
  
  //第二级超前时间常数(秒)
  private Double t4;
  
  //第二级滞后时间常数(秒)
  private Double t5;
  
  //比例环节时间常数(秒)
  private Double tP;
  
  //STATCOM响应延迟(秒)
  private Double tS;
  
  //比例环节放大倍数
  private Double kP;
  
  //积分环节的放大倍数
  private Double kI;
  
  //STATCOM的V-I特性曲线的斜率
  private Double kD;
  
  //STATCOM与系统之间的等值电抗(pu)
  private Double xT;
  
  //电压限幅环节的上限(pu)
  private Double vMAX;
  
  //电压限幅环节的下限(pu)
  private Double vMIN;
  
  //最大容性电流(pu)
  private Double iCMAX;
  
  //最大感性电流(pu)
  private Double iLMAX;
  
  //与系统相连的节点电压低于此值
  private Double vSTANDBY;
  
  //被控母线名
  private String cON_NAME;
  
  //被控母线基准电压
  private Double cON_KV;
  
  //数据库主键
  private String keyName;
  
  //母线索引
  private Integer busPtr;
  
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
    
  public Double getACBus_KV()
  {
    return aCBus_KV;
  }
    
  public void setACBus_KV(Double aCBus_KV)
  {
    this.aCBus_KV = aCBus_KV;
  }
    
  public Double getMvaBase()
  {
    return mvaBase;
  }
    
  public void setMvaBase(Double mvaBase)
  {
    this.mvaBase = mvaBase;
  }
    
  public Double getT1()
  {
    return t1;
  }
    
  public void setT1(Double t1)
  {
    this.t1 = t1;
  }
    
  public Double getT2()
  {
    return t2;
  }
    
  public void setT2(Double t2)
  {
    this.t2 = t2;
  }
    
  public Double getT3()
  {
    return t3;
  }
    
  public void setT3(Double t3)
  {
    this.t3 = t3;
  }
    
  public Double getT4()
  {
    return t4;
  }
    
  public void setT4(Double t4)
  {
    this.t4 = t4;
  }
    
  public Double getT5()
  {
    return t5;
  }
    
  public void setT5(Double t5)
  {
    this.t5 = t5;
  }
    
  public Double getTP()
  {
    return tP;
  }
    
  public void setTP(Double tP)
  {
    this.tP = tP;
  }
    
  public Double getTS()
  {
    return tS;
  }
    
  public void setTS(Double tS)
  {
    this.tS = tS;
  }
    
  public Double getKP()
  {
    return kP;
  }
    
  public void setKP(Double kP)
  {
    this.kP = kP;
  }
    
  public Double getKI()
  {
    return kI;
  }
    
  public void setKI(Double kI)
  {
    this.kI = kI;
  }
    
  public Double getKD()
  {
    return kD;
  }
    
  public void setKD(Double kD)
  {
    this.kD = kD;
  }
    
  public Double getXT()
  {
    return xT;
  }
    
  public void setXT(Double xT)
  {
    this.xT = xT;
  }
    
  public Double getVMAX()
  {
    return vMAX;
  }
    
  public void setVMAX(Double vMAX)
  {
    this.vMAX = vMAX;
  }
    
  public Double getVMIN()
  {
    return vMIN;
  }
    
  public void setVMIN(Double vMIN)
  {
    this.vMIN = vMIN;
  }
    
  public Double getICMAX()
  {
    return iCMAX;
  }
    
  public void setICMAX(Double iCMAX)
  {
    this.iCMAX = iCMAX;
  }
    
  public Double getILMAX()
  {
    return iLMAX;
  }
    
  public void setILMAX(Double iLMAX)
  {
    this.iLMAX = iLMAX;
  }
    
  public Double getVSTANDBY()
  {
    return vSTANDBY;
  }
    
  public void setVSTANDBY(Double vSTANDBY)
  {
    this.vSTANDBY = vSTANDBY;
  }
    
  public String getCON_NAME()
  {
    return cON_NAME;
  }
    
  public void setCON_NAME(String cON_NAME)
  {
    this.cON_NAME = cON_NAME;
  }
    
  public Double getCON_KV()
  {
    return cON_KV;
  }
    
  public void setCON_KV(Double cON_KV)
  {
    this.cON_KV = cON_KV;
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
    
  public String toString()
  {
    return "BpaSwi_VG ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_KV = " + aCBus_KV
	 + ", mvaBase = " + mvaBase
	 + ", t1 = " + t1
	 + ", t2 = " + t2
	 + ", t3 = " + t3
	 + ", t4 = " + t4
	 + ", t5 = " + t5
	 + ", tP = " + tP
	 + ", tS = " + tS
	 + ", kP = " + kP
	 + ", kI = " + kI
	 + ", kD = " + kD
	 + ", xT = " + xT
	 + ", vMAX = " + vMAX
	 + ", vMIN = " + vMIN
	 + ", iCMAX = " + iCMAX
	 + ", iLMAX = " + iLMAX
	 + ", vSTANDBY = " + vSTANDBY
	 + ", cON_NAME = " + cON_NAME
	 + ", cON_KV = " + cON_KV
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr+"]";
  }
    
}
    
