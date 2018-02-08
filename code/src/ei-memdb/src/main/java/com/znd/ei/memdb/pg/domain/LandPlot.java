package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*地块	*
***********************/
public class LandPlot  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源ID
  private String ResourceID;
  
  //地块名称
  private String Name;
  
  //中心点坐标X
  private Double LocateX;
  
  //中心点坐标Y
  private Double LocateY;
  
  //地块面积(平方米)
  private Double LandArea;
  
  //建筑面积(平方米)
  private Double BuildingArea;
  
  //指标类型
  private String LandIndex;
  
  //地块类型
  private String LandType;
  
  //同时率
  private Double Samerate;
  
  //负荷密度(W/m2)
  private Double Density;
  
  //需用系数
  private Double Demand;
  
  //容积率
  private Double Volume;
  
  //图元类型
  private Integer MetaType;
  
  //地块层号
  private String Layer;
  
  //地块颜色
  private Integer Color;
  
  //负荷密度法(MW)
  private Double DensityLoad;
  
  //分布预测法(MW)
  private Double DistribLoad;
  
  //参与预测
  private Integer InCalculate;
  
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
    
  public String getResourceID()
  {
    return ResourceID;
  }
    
  public void setResourceID(String ResourceID)
  {
    this.ResourceID = ResourceID;
  }
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public Double getLocateX()
  {
    return LocateX;
  }
    
  public void setLocateX(Double LocateX)
  {
    this.LocateX = LocateX;
  }
    
  public Double getLocateY()
  {
    return LocateY;
  }
    
  public void setLocateY(Double LocateY)
  {
    this.LocateY = LocateY;
  }
    
  public Double getLandArea()
  {
    return LandArea;
  }
    
  public void setLandArea(Double LandArea)
  {
    this.LandArea = LandArea;
  }
    
  public Double getBuildingArea()
  {
    return BuildingArea;
  }
    
  public void setBuildingArea(Double BuildingArea)
  {
    this.BuildingArea = BuildingArea;
  }
    
  public String getLandIndex()
  {
    return LandIndex;
  }
    
  public void setLandIndex(String LandIndex)
  {
    this.LandIndex = LandIndex;
  }
    
  public String getLandType()
  {
    return LandType;
  }
    
  public void setLandType(String LandType)
  {
    this.LandType = LandType;
  }
    
  public Double getSamerate()
  {
    return Samerate;
  }
    
  public void setSamerate(Double Samerate)
  {
    this.Samerate = Samerate;
  }
    
  public Double getDensity()
  {
    return Density;
  }
    
  public void setDensity(Double Density)
  {
    this.Density = Density;
  }
    
  public Double getDemand()
  {
    return Demand;
  }
    
  public void setDemand(Double Demand)
  {
    this.Demand = Demand;
  }
    
  public Double getVolume()
  {
    return Volume;
  }
    
  public void setVolume(Double Volume)
  {
    this.Volume = Volume;
  }
    
  public Integer getMetaType()
  {
    return MetaType;
  }
    
  public void setMetaType(Integer MetaType)
  {
    this.MetaType = MetaType;
  }
    
  public String getLayer()
  {
    return Layer;
  }
    
  public void setLayer(String Layer)
  {
    this.Layer = Layer;
  }
    
  public Integer getColor()
  {
    return Color;
  }
    
  public void setColor(Integer Color)
  {
    this.Color = Color;
  }
    
  public Double getDensityLoad()
  {
    return DensityLoad;
  }
    
  public void setDensityLoad(Double DensityLoad)
  {
    this.DensityLoad = DensityLoad;
  }
    
  public Double getDistribLoad()
  {
    return DistribLoad;
  }
    
  public void setDistribLoad(Double DistribLoad)
  {
    this.DistribLoad = DistribLoad;
  }
    
  public Integer getInCalculate()
  {
    return InCalculate;
  }
    
  public void setInCalculate(Integer InCalculate)
  {
    this.InCalculate = InCalculate;
  }
    
  public String toString()
  {
    return "LandPlot ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Name = " + Name
	 + ", LocateX = " + LocateX
	 + ", LocateY = " + LocateY
	 + ", LandArea = " + LandArea
	 + ", BuildingArea = " + BuildingArea
	 + ", LandIndex = " + LandIndex
	 + ", LandType = " + LandType
	 + ", Samerate = " + Samerate
	 + ", Density = " + Density
	 + ", Demand = " + Demand
	 + ", Volume = " + Volume
	 + ", MetaType = " + MetaType
	 + ", Layer = " + Layer
	 + ", Color = " + Color
	 + ", DensityLoad = " + DensityLoad
	 + ", DistribLoad = " + DistribLoad
	 + ", InCalculate = " + InCalculate+"]";
  }
    
}
    
