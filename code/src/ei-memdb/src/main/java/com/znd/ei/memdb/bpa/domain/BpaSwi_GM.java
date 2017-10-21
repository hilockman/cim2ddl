package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*调节系统模型4表(GM)	*
***********************/
public class BpaSwi_GM  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //发电机名称
  private String aCBus_Name;
  
  //发电机基准电压(kV)
  private Double aCBus_kV;
  
  //发电机识别码
  private Integer gen_ID;
  
  //频率偏差放大倍数
  private Double gM_KW;
  
  //频率测量环节时间常数(秒)
  private Double gM_TR;
  
  //转速调节死区(负方向,相对于额定频率的标么值)
  private Double gM_Negative_DB1;
  
  //转速调节死区(正方向,相对于额定频率的标么值)
  private Double gM_DB1;
  
  //PID比例环节放大倍数
  private Double gM_KP;
  
  //PID微分环节放大倍数
  private Double gM_KD;
  
  //PID积分环节放大倍数
  private Double gM_KI;
  
  //PID微分环节时间常数(秒)
  private Double gM_TD;
  
  //PID积分环节限幅上限
  private Double gM_INTG_MAX;
  
  //PID积分环节限幅下限
  private Double gM_INTG_MIN;
  
  //PID输出限幅环节的上限
  private Double gM_PID_MAX;
  
  //PID输出限幅环节的下限
  private Double gM_PID_MIN;
  
  //DELT,转速测量的时迟(秒)
  private Double gM_DELT;
  
  //一次调频上限
  private Double gM_DB_MAX;
  
  //一次调频下限
  private Double gM_DB_MIN;
  
  //测量时迟(秒)
  private Double gM_DELT2;
  
  //测量环节时间常数(秒)
  private Double gM_TR2;
  
  //系数
  private Double gM_EP;
  
  //负方向死区
  private Double gM_Negative_DB2;
  
  //正方向死区
  private Double gM_DB2;
  
  //限幅上限
  private Double gM_DBMAX2;
  
  //限幅下限
  private Double gM_DBMIN2;
  
  //模式选择
  private Integer gM_ITYP;
  
  //开度模式选择
  private Integer gM_ITYP2;
  
  //数据库主键
  private String keyName;
  
  //发电机母线索引
  private Integer busPtr;
  
  //新增记录标记
  private Integer appendTag;
  
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
    
  public Double getACBus_kV()
  {
    return aCBus_kV;
  }
    
  public void setACBus_kV(Double aCBus_kV)
  {
    this.aCBus_kV = aCBus_kV;
  }
    
  public Integer getGen_ID()
  {
    return gen_ID;
  }
    
  public void setGen_ID(Integer gen_ID)
  {
    this.gen_ID = gen_ID;
  }
    
  public Double getGM_KW()
  {
    return gM_KW;
  }
    
  public void setGM_KW(Double gM_KW)
  {
    this.gM_KW = gM_KW;
  }
    
  public Double getGM_TR()
  {
    return gM_TR;
  }
    
  public void setGM_TR(Double gM_TR)
  {
    this.gM_TR = gM_TR;
  }
    
  public Double getGM_Negative_DB1()
  {
    return gM_Negative_DB1;
  }
    
  public void setGM_Negative_DB1(Double gM_Negative_DB1)
  {
    this.gM_Negative_DB1 = gM_Negative_DB1;
  }
    
  public Double getGM_DB1()
  {
    return gM_DB1;
  }
    
  public void setGM_DB1(Double gM_DB1)
  {
    this.gM_DB1 = gM_DB1;
  }
    
  public Double getGM_KP()
  {
    return gM_KP;
  }
    
  public void setGM_KP(Double gM_KP)
  {
    this.gM_KP = gM_KP;
  }
    
  public Double getGM_KD()
  {
    return gM_KD;
  }
    
  public void setGM_KD(Double gM_KD)
  {
    this.gM_KD = gM_KD;
  }
    
  public Double getGM_KI()
  {
    return gM_KI;
  }
    
  public void setGM_KI(Double gM_KI)
  {
    this.gM_KI = gM_KI;
  }
    
  public Double getGM_TD()
  {
    return gM_TD;
  }
    
  public void setGM_TD(Double gM_TD)
  {
    this.gM_TD = gM_TD;
  }
    
  public Double getGM_INTG_MAX()
  {
    return gM_INTG_MAX;
  }
    
  public void setGM_INTG_MAX(Double gM_INTG_MAX)
  {
    this.gM_INTG_MAX = gM_INTG_MAX;
  }
    
  public Double getGM_INTG_MIN()
  {
    return gM_INTG_MIN;
  }
    
  public void setGM_INTG_MIN(Double gM_INTG_MIN)
  {
    this.gM_INTG_MIN = gM_INTG_MIN;
  }
    
  public Double getGM_PID_MAX()
  {
    return gM_PID_MAX;
  }
    
  public void setGM_PID_MAX(Double gM_PID_MAX)
  {
    this.gM_PID_MAX = gM_PID_MAX;
  }
    
  public Double getGM_PID_MIN()
  {
    return gM_PID_MIN;
  }
    
  public void setGM_PID_MIN(Double gM_PID_MIN)
  {
    this.gM_PID_MIN = gM_PID_MIN;
  }
    
  public Double getGM_DELT()
  {
    return gM_DELT;
  }
    
  public void setGM_DELT(Double gM_DELT)
  {
    this.gM_DELT = gM_DELT;
  }
    
  public Double getGM_DB_MAX()
  {
    return gM_DB_MAX;
  }
    
  public void setGM_DB_MAX(Double gM_DB_MAX)
  {
    this.gM_DB_MAX = gM_DB_MAX;
  }
    
  public Double getGM_DB_MIN()
  {
    return gM_DB_MIN;
  }
    
  public void setGM_DB_MIN(Double gM_DB_MIN)
  {
    this.gM_DB_MIN = gM_DB_MIN;
  }
    
  public Double getGM_DELT2()
  {
    return gM_DELT2;
  }
    
  public void setGM_DELT2(Double gM_DELT2)
  {
    this.gM_DELT2 = gM_DELT2;
  }
    
  public Double getGM_TR2()
  {
    return gM_TR2;
  }
    
  public void setGM_TR2(Double gM_TR2)
  {
    this.gM_TR2 = gM_TR2;
  }
    
  public Double getGM_EP()
  {
    return gM_EP;
  }
    
  public void setGM_EP(Double gM_EP)
  {
    this.gM_EP = gM_EP;
  }
    
  public Double getGM_Negative_DB2()
  {
    return gM_Negative_DB2;
  }
    
  public void setGM_Negative_DB2(Double gM_Negative_DB2)
  {
    this.gM_Negative_DB2 = gM_Negative_DB2;
  }
    
  public Double getGM_DB2()
  {
    return gM_DB2;
  }
    
  public void setGM_DB2(Double gM_DB2)
  {
    this.gM_DB2 = gM_DB2;
  }
    
  public Double getGM_DBMAX2()
  {
    return gM_DBMAX2;
  }
    
  public void setGM_DBMAX2(Double gM_DBMAX2)
  {
    this.gM_DBMAX2 = gM_DBMAX2;
  }
    
  public Double getGM_DBMIN2()
  {
    return gM_DBMIN2;
  }
    
  public void setGM_DBMIN2(Double gM_DBMIN2)
  {
    this.gM_DBMIN2 = gM_DBMIN2;
  }
    
  public Integer getGM_ITYP()
  {
    return gM_ITYP;
  }
    
  public void setGM_ITYP(Integer gM_ITYP)
  {
    this.gM_ITYP = gM_ITYP;
  }
    
  public Integer getGM_ITYP2()
  {
    return gM_ITYP2;
  }
    
  public void setGM_ITYP2(Integer gM_ITYP2)
  {
    this.gM_ITYP2 = gM_ITYP2;
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
    
  public Integer getAppendTag()
  {
    return appendTag;
  }
    
  public void setAppendTag(Integer appendTag)
  {
    this.appendTag = appendTag;
  }
    
  public String toString()
  {
    return "BpaSwi_GM ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", gen_ID = " + gen_ID
	 + ", gM_KW = " + gM_KW
	 + ", gM_TR = " + gM_TR
	 + ", gM_Negative_DB1 = " + gM_Negative_DB1
	 + ", gM_DB1 = " + gM_DB1
	 + ", gM_KP = " + gM_KP
	 + ", gM_KD = " + gM_KD
	 + ", gM_KI = " + gM_KI
	 + ", gM_TD = " + gM_TD
	 + ", gM_INTG_MAX = " + gM_INTG_MAX
	 + ", gM_INTG_MIN = " + gM_INTG_MIN
	 + ", gM_PID_MAX = " + gM_PID_MAX
	 + ", gM_PID_MIN = " + gM_PID_MIN
	 + ", gM_DELT = " + gM_DELT
	 + ", gM_DB_MAX = " + gM_DB_MAX
	 + ", gM_DB_MIN = " + gM_DB_MIN
	 + ", gM_DELT2 = " + gM_DELT2
	 + ", gM_TR2 = " + gM_TR2
	 + ", gM_EP = " + gM_EP
	 + ", gM_Negative_DB2 = " + gM_Negative_DB2
	 + ", gM_DB2 = " + gM_DB2
	 + ", gM_DBMAX2 = " + gM_DBMAX2
	 + ", gM_DBMIN2 = " + gM_DBMIN2
	 + ", gM_ITYP = " + gM_ITYP
	 + ", gM_ITYP2 = " + gM_ITYP2
	 + ", keyName = " + keyName
	 + ", busPtr = " + busPtr
	 + ", appendTag = " + appendTag+"]";
  }
    
}
    
