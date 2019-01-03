package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*节点	*
***********************/
public class ConnectivityNode  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //厂站
  private String Substation;
  
  //电压等级
  private String VoltageLevel;
  
  //名称
  private String Name;
  
  //交流线路段范围
  private Integer ACLineSegmentRange;
  
  //直流线路段范围
  private Integer DCLineSegmentRange;
  
  //变压器绕组范围
  private Integer TransformerWindingRange;
  
  //串联补偿范围
  private Integer SeriesCompensatorRange;
  
  //断路器范围
  private Integer BreakerRange;
  
  //隔离开关范围
  private Integer DisconnectorRange;
  
  //交直变换器范围
  private Integer ADConverterRange;
  
  //直直变换器范围
  private Integer DDConverterRange;
  
  //直流断路器范围
  private Integer DCBreakerRange;
  
  //直流短路电流限制器范围
  private Integer DCShortCircuitLimitRange;
  
  //电压等级索引
  private Integer VoltageLevelPtr;
  
  //母线索引
  private Integer BusbarSectionPtr;
  
  //拓扑节点
  private Integer TopoBus;
  
  //岛
  private Integer Island;
  
  //节点转电能力(兆瓦)
  private Double sa_Ability;
  
  //环网标记
  private Integer InRing;
  
  //辐射网号
  private Integer Radiate;
  
  //拓扑状态
  private Integer Open;
  
  //变压器中点
  private Integer TMid;
  
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
    
  public String getSubstation()
  {
    return Substation;
  }
    
  public void setSubstation(String Substation)
  {
    this.Substation = Substation;
  }
    
  public String getVoltageLevel()
  {
    return VoltageLevel;
  }
    
  public void setVoltageLevel(String VoltageLevel)
  {
    this.VoltageLevel = VoltageLevel;
  }
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public Integer getACLineSegmentRange()
  {
    return ACLineSegmentRange;
  }
    
  public void setACLineSegmentRange(Integer ACLineSegmentRange)
  {
    this.ACLineSegmentRange = ACLineSegmentRange;
  }
    
  public Integer getDCLineSegmentRange()
  {
    return DCLineSegmentRange;
  }
    
  public void setDCLineSegmentRange(Integer DCLineSegmentRange)
  {
    this.DCLineSegmentRange = DCLineSegmentRange;
  }
    
  public Integer getTransformerWindingRange()
  {
    return TransformerWindingRange;
  }
    
  public void setTransformerWindingRange(Integer TransformerWindingRange)
  {
    this.TransformerWindingRange = TransformerWindingRange;
  }
    
  public Integer getSeriesCompensatorRange()
  {
    return SeriesCompensatorRange;
  }
    
  public void setSeriesCompensatorRange(Integer SeriesCompensatorRange)
  {
    this.SeriesCompensatorRange = SeriesCompensatorRange;
  }
    
  public Integer getBreakerRange()
  {
    return BreakerRange;
  }
    
  public void setBreakerRange(Integer BreakerRange)
  {
    this.BreakerRange = BreakerRange;
  }
    
  public Integer getDisconnectorRange()
  {
    return DisconnectorRange;
  }
    
  public void setDisconnectorRange(Integer DisconnectorRange)
  {
    this.DisconnectorRange = DisconnectorRange;
  }
    
  public Integer getADConverterRange()
  {
    return ADConverterRange;
  }
    
  public void setADConverterRange(Integer ADConverterRange)
  {
    this.ADConverterRange = ADConverterRange;
  }
    
  public Integer getDDConverterRange()
  {
    return DDConverterRange;
  }
    
  public void setDDConverterRange(Integer DDConverterRange)
  {
    this.DDConverterRange = DDConverterRange;
  }
    
  public Integer getDCBreakerRange()
  {
    return DCBreakerRange;
  }
    
  public void setDCBreakerRange(Integer DCBreakerRange)
  {
    this.DCBreakerRange = DCBreakerRange;
  }
    
  public Integer getDCShortCircuitLimitRange()
  {
    return DCShortCircuitLimitRange;
  }
    
  public void setDCShortCircuitLimitRange(Integer DCShortCircuitLimitRange)
  {
    this.DCShortCircuitLimitRange = DCShortCircuitLimitRange;
  }
    
  public Integer getVoltageLevelPtr()
  {
    return VoltageLevelPtr;
  }
    
  public void setVoltageLevelPtr(Integer VoltageLevelPtr)
  {
    this.VoltageLevelPtr = VoltageLevelPtr;
  }
    
  public Integer getBusbarSectionPtr()
  {
    return BusbarSectionPtr;
  }
    
  public void setBusbarSectionPtr(Integer BusbarSectionPtr)
  {
    this.BusbarSectionPtr = BusbarSectionPtr;
  }
    
  public Integer getTopoBus()
  {
    return TopoBus;
  }
    
  public void setTopoBus(Integer TopoBus)
  {
    this.TopoBus = TopoBus;
  }
    
  public Integer getIsland()
  {
    return Island;
  }
    
  public void setIsland(Integer Island)
  {
    this.Island = Island;
  }
    
  public Double getsa_Ability()
  {
    return sa_Ability;
  }
    
  public void setsa_Ability(Double sa_Ability)
  {
    this.sa_Ability = sa_Ability;
  }
    
  public Integer getInRing()
  {
    return InRing;
  }
    
  public void setInRing(Integer InRing)
  {
    this.InRing = InRing;
  }
    
  public Integer getRadiate()
  {
    return Radiate;
  }
    
  public void setRadiate(Integer Radiate)
  {
    this.Radiate = Radiate;
  }
    
  public Integer getOpen()
  {
    return Open;
  }
    
  public void setOpen(Integer Open)
  {
    this.Open = Open;
  }
    
  public Integer getTMid()
  {
    return TMid;
  }
    
  public void setTMid(Integer TMid)
  {
    this.TMid = TMid;
  }
    
  public String toString()
  {
    return "ConnectivityNode ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", ACLineSegmentRange = " + ACLineSegmentRange
	 + ", DCLineSegmentRange = " + DCLineSegmentRange
	 + ", TransformerWindingRange = " + TransformerWindingRange
	 + ", SeriesCompensatorRange = " + SeriesCompensatorRange
	 + ", BreakerRange = " + BreakerRange
	 + ", DisconnectorRange = " + DisconnectorRange
	 + ", ADConverterRange = " + ADConverterRange
	 + ", DDConverterRange = " + DDConverterRange
	 + ", DCBreakerRange = " + DCBreakerRange
	 + ", DCShortCircuitLimitRange = " + DCShortCircuitLimitRange
	 + ", VoltageLevelPtr = " + VoltageLevelPtr
	 + ", BusbarSectionPtr = " + BusbarSectionPtr
	 + ", TopoBus = " + TopoBus
	 + ", Island = " + Island
	 + ", sa_Ability = " + sa_Ability
	 + ", InRing = " + InRing
	 + ", Radiate = " + Radiate
	 + ", Open = " + Open
	 + ", TMid = " + TMid+"]";
  }
    
}
    
