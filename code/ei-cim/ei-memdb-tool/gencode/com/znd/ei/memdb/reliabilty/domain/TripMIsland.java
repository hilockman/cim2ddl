package com.znd.ei.memdb.reliabilty.domain;


/**********************
*开断故障下孤岛信息	*
***********************/
public class TripMIsland
{
  private Integer id;
  
  private Integer memIndex;
  
  //开断故障索引
  private Integer trip;
  
  //孤岛母线
  private Integer outageBus;
  
  //孤岛负荷功率(MW)
  private Double outageLoadP;
  
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
    
  public Integer getTrip()
  {
    return trip;
  }
    
  public void setTrip(Integer trip)
  {
    this.trip = trip;
  }
    
  public Integer getOutageBus()
  {
    return outageBus;
  }
    
  public void setOutageBus(Integer outageBus)
  {
    this.outageBus = outageBus;
  }
    
  public Double getOutageLoadP()
  {
    return outageLoadP;
  }
    
  public void setOutageLoadP(Double outageLoadP)
  {
    this.outageLoadP = outageLoadP;
  }
    
  public String toString()
  {
    return "TripMIsland ["+	"id"=id,
	"memIndex"=memIndex,
	"trip"=trip,
	"outageBus"=outageBus,
	"outageLoadP"=outageLoadP+"]"
  }
    
}
    
