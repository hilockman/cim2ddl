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
  private String CardKey;
  
  //发电机名称
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //频率偏差放大倍数
  private Double GM_KW;
  
  //频率测量环节时间常数(秒)
  private Double GM_TR;
  
  //转速调节死区(负方向,相对于额定频率的标么值)
  private Double GM_Negative_DB1;
  
  //转速调节死区(正方向,相对于额定频率的标么值)
  private Double GM_DB1;
  
  //PID比例环节放大倍数
  private Double GM_KP;
  
  //PID微分环节放大倍数
  private Double GM_KD;
  
  //PID积分环节放大倍数
  private Double GM_KI;
  
  //PID微分环节时间常数(秒)
  private Double GM_TD;
  
  //PID积分环节限幅上限
  private Double GM_INTG_MAX;
  
  //PID积分环节限幅下限
  private Double GM_INTG_MIN;
  
  //PID输出限幅环节的上限
  private Double GM_PID_MAX;
  
  //PID输出限幅环节的下限
  private Double GM_PID_MIN;
  
  //DELT,转速测量的时迟(秒)
  private Double GM_DELT;
  
  //一次调频上限
  private Double GM_DB_MAX;
  
  //一次调频下限
  private Double GM_DB_MIN;
  
  //测量时迟(秒)
  private Double GM_DELT2;
  
  //测量环节时间常数(秒)
  private Double GM_TR2;
  
  //系数
  private Double GM_EP;
  
  //负方向死区
  private Double GM_Negative_DB2;
  
  //正方向死区
  private Double GM_DB2;
  
  //限幅上限
  private Double GM_DBMAX2;
  
  //限幅下限
  private Double GM_DBMIN2;
  
  //模式选择
  private Integer GM_ITYP;
  
  //开度模式选择
  private Integer GM_ITYP2;
  
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
    
  public Integer getGen_ID()
  {
    return Gen_ID;
  }
    
  public void setGen_ID(Integer Gen_ID)
  {
    this.Gen_ID = Gen_ID;
  }
    
  public Double getGM_KW()
  {
    return GM_KW;
  }
    
  public void setGM_KW(Double GM_KW)
  {
    this.GM_KW = GM_KW;
  }
    
  public Double getGM_TR()
  {
    return GM_TR;
  }
    
  public void setGM_TR(Double GM_TR)
  {
    this.GM_TR = GM_TR;
  }
    
  public Double getGM_Negative_DB1()
  {
    return GM_Negative_DB1;
  }
    
  public void setGM_Negative_DB1(Double GM_Negative_DB1)
  {
    this.GM_Negative_DB1 = GM_Negative_DB1;
  }
    
  public Double getGM_DB1()
  {
    return GM_DB1;
  }
    
  public void setGM_DB1(Double GM_DB1)
  {
    this.GM_DB1 = GM_DB1;
  }
    
  public Double getGM_KP()
  {
    return GM_KP;
  }
    
  public void setGM_KP(Double GM_KP)
  {
    this.GM_KP = GM_KP;
  }
    
  public Double getGM_KD()
  {
    return GM_KD;
  }
    
  public void setGM_KD(Double GM_KD)
  {
    this.GM_KD = GM_KD;
  }
    
  public Double getGM_KI()
  {
    return GM_KI;
  }
    
  public void setGM_KI(Double GM_KI)
  {
    this.GM_KI = GM_KI;
  }
    
  public Double getGM_TD()
  {
    return GM_TD;
  }
    
  public void setGM_TD(Double GM_TD)
  {
    this.GM_TD = GM_TD;
  }
    
  public Double getGM_INTG_MAX()
  {
    return GM_INTG_MAX;
  }
    
  public void setGM_INTG_MAX(Double GM_INTG_MAX)
  {
    this.GM_INTG_MAX = GM_INTG_MAX;
  }
    
  public Double getGM_INTG_MIN()
  {
    return GM_INTG_MIN;
  }
    
  public void setGM_INTG_MIN(Double GM_INTG_MIN)
  {
    this.GM_INTG_MIN = GM_INTG_MIN;
  }
    
  public Double getGM_PID_MAX()
  {
    return GM_PID_MAX;
  }
    
  public void setGM_PID_MAX(Double GM_PID_MAX)
  {
    this.GM_PID_MAX = GM_PID_MAX;
  }
    
  public Double getGM_PID_MIN()
  {
    return GM_PID_MIN;
  }
    
  public void setGM_PID_MIN(Double GM_PID_MIN)
  {
    this.GM_PID_MIN = GM_PID_MIN;
  }
    
  public Double getGM_DELT()
  {
    return GM_DELT;
  }
    
  public void setGM_DELT(Double GM_DELT)
  {
    this.GM_DELT = GM_DELT;
  }
    
  public Double getGM_DB_MAX()
  {
    return GM_DB_MAX;
  }
    
  public void setGM_DB_MAX(Double GM_DB_MAX)
  {
    this.GM_DB_MAX = GM_DB_MAX;
  }
    
  public Double getGM_DB_MIN()
  {
    return GM_DB_MIN;
  }
    
  public void setGM_DB_MIN(Double GM_DB_MIN)
  {
    this.GM_DB_MIN = GM_DB_MIN;
  }
    
  public Double getGM_DELT2()
  {
    return GM_DELT2;
  }
    
  public void setGM_DELT2(Double GM_DELT2)
  {
    this.GM_DELT2 = GM_DELT2;
  }
    
  public Double getGM_TR2()
  {
    return GM_TR2;
  }
    
  public void setGM_TR2(Double GM_TR2)
  {
    this.GM_TR2 = GM_TR2;
  }
    
  public Double getGM_EP()
  {
    return GM_EP;
  }
    
  public void setGM_EP(Double GM_EP)
  {
    this.GM_EP = GM_EP;
  }
    
  public Double getGM_Negative_DB2()
  {
    return GM_Negative_DB2;
  }
    
  public void setGM_Negative_DB2(Double GM_Negative_DB2)
  {
    this.GM_Negative_DB2 = GM_Negative_DB2;
  }
    
  public Double getGM_DB2()
  {
    return GM_DB2;
  }
    
  public void setGM_DB2(Double GM_DB2)
  {
    this.GM_DB2 = GM_DB2;
  }
    
  public Double getGM_DBMAX2()
  {
    return GM_DBMAX2;
  }
    
  public void setGM_DBMAX2(Double GM_DBMAX2)
  {
    this.GM_DBMAX2 = GM_DBMAX2;
  }
    
  public Double getGM_DBMIN2()
  {
    return GM_DBMIN2;
  }
    
  public void setGM_DBMIN2(Double GM_DBMIN2)
  {
    this.GM_DBMIN2 = GM_DBMIN2;
  }
    
  public Integer getGM_ITYP()
  {
    return GM_ITYP;
  }
    
  public void setGM_ITYP(Integer GM_ITYP)
  {
    this.GM_ITYP = GM_ITYP;
  }
    
  public Integer getGM_ITYP2()
  {
    return GM_ITYP2;
  }
    
  public void setGM_ITYP2(Integer GM_ITYP2)
  {
    this.GM_ITYP2 = GM_ITYP2;
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
    return "BpaSwi_GM ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", GM_KW = " + GM_KW
	 + ", GM_TR = " + GM_TR
	 + ", GM_Negative_DB1 = " + GM_Negative_DB1
	 + ", GM_DB1 = " + GM_DB1
	 + ", GM_KP = " + GM_KP
	 + ", GM_KD = " + GM_KD
	 + ", GM_KI = " + GM_KI
	 + ", GM_TD = " + GM_TD
	 + ", GM_INTG_MAX = " + GM_INTG_MAX
	 + ", GM_INTG_MIN = " + GM_INTG_MIN
	 + ", GM_PID_MAX = " + GM_PID_MAX
	 + ", GM_PID_MIN = " + GM_PID_MIN
	 + ", GM_DELT = " + GM_DELT
	 + ", GM_DB_MAX = " + GM_DB_MAX
	 + ", GM_DB_MIN = " + GM_DB_MIN
	 + ", GM_DELT2 = " + GM_DELT2
	 + ", GM_TR2 = " + GM_TR2
	 + ", GM_EP = " + GM_EP
	 + ", GM_Negative_DB2 = " + GM_Negative_DB2
	 + ", GM_DB2 = " + GM_DB2
	 + ", GM_DBMAX2 = " + GM_DBMAX2
	 + ", GM_DBMIN2 = " + GM_DBMIN2
	 + ", GM_ITYP = " + GM_ITYP
	 + ", GM_ITYP2 = " + GM_ITYP2
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
