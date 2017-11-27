package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*锅炉的主汽压力变化模型表(GX)	*
***********************/
public class BpaSwi_GX  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //发电机名称
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_KV;
  
  //发电机识别码ID
  private Integer Gen_ID;
  
  //过热器容积时间常数
  private Double GX_TSH;
  
  //汽包蓄热容积时间常数
  private Double GX_TD;
  
  //锅炉燃料释放的时间常数
  private Double GX_TW;
  
  //过热器及主汽管道流量系数
  private Double GX_K;
  
  //延时
  private Double GX_Tdelay;
  
  //输出限幅环节的最大值
  private Double GX_Limit_MAX;
  
  //输出限幅环节最小值
  private Double GX_Limit_MIN;
  
  //数据库主键
  private String KeyName;
  
  //发电机母线索引
  private Integer BusPtr;
  
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
    
  public Double getACBus_KV()
  {
    return ACBus_KV;
  }
    
  public void setACBus_KV(Double ACBus_KV)
  {
    this.ACBus_KV = ACBus_KV;
  }
    
  public Integer getGen_ID()
  {
    return Gen_ID;
  }
    
  public void setGen_ID(Integer Gen_ID)
  {
    this.Gen_ID = Gen_ID;
  }
    
  public Double getGX_TSH()
  {
    return GX_TSH;
  }
    
  public void setGX_TSH(Double GX_TSH)
  {
    this.GX_TSH = GX_TSH;
  }
    
  public Double getGX_TD()
  {
    return GX_TD;
  }
    
  public void setGX_TD(Double GX_TD)
  {
    this.GX_TD = GX_TD;
  }
    
  public Double getGX_TW()
  {
    return GX_TW;
  }
    
  public void setGX_TW(Double GX_TW)
  {
    this.GX_TW = GX_TW;
  }
    
  public Double getGX_K()
  {
    return GX_K;
  }
    
  public void setGX_K(Double GX_K)
  {
    this.GX_K = GX_K;
  }
    
  public Double getGX_Tdelay()
  {
    return GX_Tdelay;
  }
    
  public void setGX_Tdelay(Double GX_Tdelay)
  {
    this.GX_Tdelay = GX_Tdelay;
  }
    
  public Double getGX_Limit_MAX()
  {
    return GX_Limit_MAX;
  }
    
  public void setGX_Limit_MAX(Double GX_Limit_MAX)
  {
    this.GX_Limit_MAX = GX_Limit_MAX;
  }
    
  public Double getGX_Limit_MIN()
  {
    return GX_Limit_MIN;
  }
    
  public void setGX_Limit_MIN(Double GX_Limit_MIN)
  {
    this.GX_Limit_MIN = GX_Limit_MIN;
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
    
  public String toString()
  {
    return "BpaSwi_GX ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_KV = " + ACBus_KV
	 + ", Gen_ID = " + Gen_ID
	 + ", GX_TSH = " + GX_TSH
	 + ", GX_TD = " + GX_TD
	 + ", GX_TW = " + GX_TW
	 + ", GX_K = " + GX_K
	 + ", GX_Tdelay = " + GX_Tdelay
	 + ", GX_Limit_MAX = " + GX_Limit_MAX
	 + ", GX_Limit_MIN = " + GX_Limit_MIN
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr+"]";
  }
    
}
    
