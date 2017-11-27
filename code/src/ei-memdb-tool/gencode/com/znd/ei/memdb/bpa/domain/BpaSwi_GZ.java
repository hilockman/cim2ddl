package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电调型(功率反馈)调速器模型表(GZ)	*
***********************/
public class BpaSwi_GZ  implements MemIndexable 
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
  
  //伺服系统时间常数(秒)	
  private Double GZ_Tsm;
  
  //汽门最大开启速度(p.u.gate/sec)
  private Double GZ_Ropen;
  
  //汽门最大关闭速度(p.u.gate/sec)
  private Double GZ_Rclose;
  
  //EHC最大位置限制(pu)
  private Double GZ_EHC_MAX;
  
  //EHC最小位置限制(pu)
  private Double GZ_EHC_MIN;
  
  //控制阀开启时间常数(sec)
  private Double GZ_T_Open;
  
  //控制阀关闭时间常数(sec)
  private Double GZ_T_Close;
  
  //阀的死区(pu)
  private Double GZ_DB_Value;
  
  //阀的死区(pu)
  private Double GZ_CV_MAX;
  
  //控制阀下限(pu)
  private Double GZ_CV_MIN;
  
  //电磁功率反馈增益(pu/pu)	
  private Double GZ_Kpe;
  
  //电磁功率反馈时间常数(sec)
  private Double GZ_Tpe;
  
  //控制模式
  private Integer GZ_Mode;
  
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
    
  public Double getGZ_Tsm()
  {
    return GZ_Tsm;
  }
    
  public void setGZ_Tsm(Double GZ_Tsm)
  {
    this.GZ_Tsm = GZ_Tsm;
  }
    
  public Double getGZ_Ropen()
  {
    return GZ_Ropen;
  }
    
  public void setGZ_Ropen(Double GZ_Ropen)
  {
    this.GZ_Ropen = GZ_Ropen;
  }
    
  public Double getGZ_Rclose()
  {
    return GZ_Rclose;
  }
    
  public void setGZ_Rclose(Double GZ_Rclose)
  {
    this.GZ_Rclose = GZ_Rclose;
  }
    
  public Double getGZ_EHC_MAX()
  {
    return GZ_EHC_MAX;
  }
    
  public void setGZ_EHC_MAX(Double GZ_EHC_MAX)
  {
    this.GZ_EHC_MAX = GZ_EHC_MAX;
  }
    
  public Double getGZ_EHC_MIN()
  {
    return GZ_EHC_MIN;
  }
    
  public void setGZ_EHC_MIN(Double GZ_EHC_MIN)
  {
    this.GZ_EHC_MIN = GZ_EHC_MIN;
  }
    
  public Double getGZ_T_Open()
  {
    return GZ_T_Open;
  }
    
  public void setGZ_T_Open(Double GZ_T_Open)
  {
    this.GZ_T_Open = GZ_T_Open;
  }
    
  public Double getGZ_T_Close()
  {
    return GZ_T_Close;
  }
    
  public void setGZ_T_Close(Double GZ_T_Close)
  {
    this.GZ_T_Close = GZ_T_Close;
  }
    
  public Double getGZ_DB_Value()
  {
    return GZ_DB_Value;
  }
    
  public void setGZ_DB_Value(Double GZ_DB_Value)
  {
    this.GZ_DB_Value = GZ_DB_Value;
  }
    
  public Double getGZ_CV_MAX()
  {
    return GZ_CV_MAX;
  }
    
  public void setGZ_CV_MAX(Double GZ_CV_MAX)
  {
    this.GZ_CV_MAX = GZ_CV_MAX;
  }
    
  public Double getGZ_CV_MIN()
  {
    return GZ_CV_MIN;
  }
    
  public void setGZ_CV_MIN(Double GZ_CV_MIN)
  {
    this.GZ_CV_MIN = GZ_CV_MIN;
  }
    
  public Double getGZ_Kpe()
  {
    return GZ_Kpe;
  }
    
  public void setGZ_Kpe(Double GZ_Kpe)
  {
    this.GZ_Kpe = GZ_Kpe;
  }
    
  public Double getGZ_Tpe()
  {
    return GZ_Tpe;
  }
    
  public void setGZ_Tpe(Double GZ_Tpe)
  {
    this.GZ_Tpe = GZ_Tpe;
  }
    
  public Integer getGZ_Mode()
  {
    return GZ_Mode;
  }
    
  public void setGZ_Mode(Integer GZ_Mode)
  {
    this.GZ_Mode = GZ_Mode;
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
    return "BpaSwi_GZ ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", GZ_Tsm = " + GZ_Tsm
	 + ", GZ_Ropen = " + GZ_Ropen
	 + ", GZ_Rclose = " + GZ_Rclose
	 + ", GZ_EHC_MAX = " + GZ_EHC_MAX
	 + ", GZ_EHC_MIN = " + GZ_EHC_MIN
	 + ", GZ_T_Open = " + GZ_T_Open
	 + ", GZ_T_Close = " + GZ_T_Close
	 + ", GZ_DB_Value = " + GZ_DB_Value
	 + ", GZ_CV_MAX = " + GZ_CV_MAX
	 + ", GZ_CV_MIN = " + GZ_CV_MIN
	 + ", GZ_Kpe = " + GZ_Kpe
	 + ", GZ_Tpe = " + GZ_Tpe
	 + ", GZ_Mode = " + GZ_Mode
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
