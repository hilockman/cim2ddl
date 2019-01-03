package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电力电子变压器	*
***********************/
public class ElectronicTransformer  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //厂站
  private String Substation;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //交流变换器数
  private Integer ACConverterNum;
  
  //直流变换器数
  private Integer DCConverterNum;
  
  //交流高电压等级
  private String VoltagelevelACH;
  
  //交流低电压等级1
  private String VoltagelevelACL1;
  
  //交流低电压等级2
  private String VoltagelevelACL2;
  
  //直流低电压等级1
  private String VoltagelevelDCL1;
  
  //直流低电压等级2
  private String VoltagelevelDCL2;
  
  //直流中性点电压等级
  private String VoltagelevelDCT;
  
  //高压交直变换器
  private String ADConverterH;
  
  //低压交直变换器1
  private String ADConverterL1;
  
  //低压交直变换器2
  private String ADConverterL2;
  
  //低压直直变换器1
  private String DDConverterL1;
  
  //低压直直变换器2
  private String DDConverterL2;
  
  //高压交流节点
  private String ConnectivityNodeACH;
  
  //低压交流节点1
  private String ConnectivityNodeACL1;
  
  //低压交流节点2
  private String ConnectivityNodeACL2;
  
  //低压直流节点1
  private String ConnectivityNodeDCL1;
  
  //低压直流节点2
  private String ConnectivityNodeDCL2;
  
  //直流中性点
  private String ConnectivityNodeDCT;
  
  //故障率(次/年)
  private Double ri_Rerr;
  
  //修复时间(小时/次)
  private Double ri_Trep;
  
  //计划检修率(次/年)
  private Double ri_Rchk;
  
  //检修时间(小时/次)
  private Double ri_Tchk;
  
  //故障定位隔离时间(小时)
  private Double ri_Tfloc;
  
  //投资费用(万元)
  private Double ei_Invest;
  
  //停运率贡献(%)
  private Double ro_RContribution;
  
  //停运时间贡献(%)
  private Double ro_UContribution;
  
  //停电电量贡献(%)
  private Double ro_EnsContribution;
  
  //交流高电压等级索引
  private Integer VoltACHPtr;
  
  //交流低电压等级1索引
  private Integer VoltACL1Ptr;
  
  //交流低电压等级2索引
  private Integer VoltACL2Ptr;
  
  //直流低电压等级1索引
  private Integer VoltDCL1Ptr;
  
  //直流低电压等级2索引
  private Integer VoltDCL2Ptr;
  
  //直流中性点电压等级索引
  private Integer VoltDCTPtr;
  
  //高压交直变换器索引
  private Integer ADConverterHPtr;
  
  //低压交直变换器1索引
  private Integer ADConverterL1Ptr;
  
  //低压交直变换器2索引
  private Integer ADConverterL2Ptr;
  
  //低压直直变换器1索引
  private Integer DDConverterL1Ptr;
  
  //低压直直变换器2索引
  private Integer DDConverterL2Ptr;
  
  //高压交流节点索引
  private Integer NodeACHPtr;
  
  //低压交流节点1索引
  private Integer NodeACL1Ptr;
  
  //低压交流节点2索引
  private Integer NodeACL2Ptr;
  
  //低压直流节点1索引
  private Integer NodeDCL1Ptr;
  
  //低压直流节点2索引
  private Integer NodeDCL2Ptr;
  
  //直流中性点索引
  private Integer NodeDCTPtr;
  
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
    
  public String getSubstation()
  {
    return Substation;
  }
    
  public void setSubstation(String Substation)
  {
    this.Substation = Substation;
  }
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public String getDescription()
  {
    return Description;
  }
    
  public void setDescription(String Description)
  {
    this.Description = Description;
  }
    
  public Integer getACConverterNum()
  {
    return ACConverterNum;
  }
    
  public void setACConverterNum(Integer ACConverterNum)
  {
    this.ACConverterNum = ACConverterNum;
  }
    
  public Integer getDCConverterNum()
  {
    return DCConverterNum;
  }
    
  public void setDCConverterNum(Integer DCConverterNum)
  {
    this.DCConverterNum = DCConverterNum;
  }
    
  public String getVoltagelevelACH()
  {
    return VoltagelevelACH;
  }
    
  public void setVoltagelevelACH(String VoltagelevelACH)
  {
    this.VoltagelevelACH = VoltagelevelACH;
  }
    
  public String getVoltagelevelACL1()
  {
    return VoltagelevelACL1;
  }
    
  public void setVoltagelevelACL1(String VoltagelevelACL1)
  {
    this.VoltagelevelACL1 = VoltagelevelACL1;
  }
    
  public String getVoltagelevelACL2()
  {
    return VoltagelevelACL2;
  }
    
  public void setVoltagelevelACL2(String VoltagelevelACL2)
  {
    this.VoltagelevelACL2 = VoltagelevelACL2;
  }
    
  public String getVoltagelevelDCL1()
  {
    return VoltagelevelDCL1;
  }
    
  public void setVoltagelevelDCL1(String VoltagelevelDCL1)
  {
    this.VoltagelevelDCL1 = VoltagelevelDCL1;
  }
    
  public String getVoltagelevelDCL2()
  {
    return VoltagelevelDCL2;
  }
    
  public void setVoltagelevelDCL2(String VoltagelevelDCL2)
  {
    this.VoltagelevelDCL2 = VoltagelevelDCL2;
  }
    
  public String getVoltagelevelDCT()
  {
    return VoltagelevelDCT;
  }
    
  public void setVoltagelevelDCT(String VoltagelevelDCT)
  {
    this.VoltagelevelDCT = VoltagelevelDCT;
  }
    
  public String getADConverterH()
  {
    return ADConverterH;
  }
    
  public void setADConverterH(String ADConverterH)
  {
    this.ADConverterH = ADConverterH;
  }
    
  public String getADConverterL1()
  {
    return ADConverterL1;
  }
    
  public void setADConverterL1(String ADConverterL1)
  {
    this.ADConverterL1 = ADConverterL1;
  }
    
  public String getADConverterL2()
  {
    return ADConverterL2;
  }
    
  public void setADConverterL2(String ADConverterL2)
  {
    this.ADConverterL2 = ADConverterL2;
  }
    
  public String getDDConverterL1()
  {
    return DDConverterL1;
  }
    
  public void setDDConverterL1(String DDConverterL1)
  {
    this.DDConverterL1 = DDConverterL1;
  }
    
  public String getDDConverterL2()
  {
    return DDConverterL2;
  }
    
  public void setDDConverterL2(String DDConverterL2)
  {
    this.DDConverterL2 = DDConverterL2;
  }
    
  public String getConnectivityNodeACH()
  {
    return ConnectivityNodeACH;
  }
    
  public void setConnectivityNodeACH(String ConnectivityNodeACH)
  {
    this.ConnectivityNodeACH = ConnectivityNodeACH;
  }
    
  public String getConnectivityNodeACL1()
  {
    return ConnectivityNodeACL1;
  }
    
  public void setConnectivityNodeACL1(String ConnectivityNodeACL1)
  {
    this.ConnectivityNodeACL1 = ConnectivityNodeACL1;
  }
    
  public String getConnectivityNodeACL2()
  {
    return ConnectivityNodeACL2;
  }
    
  public void setConnectivityNodeACL2(String ConnectivityNodeACL2)
  {
    this.ConnectivityNodeACL2 = ConnectivityNodeACL2;
  }
    
  public String getConnectivityNodeDCL1()
  {
    return ConnectivityNodeDCL1;
  }
    
  public void setConnectivityNodeDCL1(String ConnectivityNodeDCL1)
  {
    this.ConnectivityNodeDCL1 = ConnectivityNodeDCL1;
  }
    
  public String getConnectivityNodeDCL2()
  {
    return ConnectivityNodeDCL2;
  }
    
  public void setConnectivityNodeDCL2(String ConnectivityNodeDCL2)
  {
    this.ConnectivityNodeDCL2 = ConnectivityNodeDCL2;
  }
    
  public String getConnectivityNodeDCT()
  {
    return ConnectivityNodeDCT;
  }
    
  public void setConnectivityNodeDCT(String ConnectivityNodeDCT)
  {
    this.ConnectivityNodeDCT = ConnectivityNodeDCT;
  }
    
  public Double getri_Rerr()
  {
    return ri_Rerr;
  }
    
  public void setri_Rerr(Double ri_Rerr)
  {
    this.ri_Rerr = ri_Rerr;
  }
    
  public Double getri_Trep()
  {
    return ri_Trep;
  }
    
  public void setri_Trep(Double ri_Trep)
  {
    this.ri_Trep = ri_Trep;
  }
    
  public Double getri_Rchk()
  {
    return ri_Rchk;
  }
    
  public void setri_Rchk(Double ri_Rchk)
  {
    this.ri_Rchk = ri_Rchk;
  }
    
  public Double getri_Tchk()
  {
    return ri_Tchk;
  }
    
  public void setri_Tchk(Double ri_Tchk)
  {
    this.ri_Tchk = ri_Tchk;
  }
    
  public Double getri_Tfloc()
  {
    return ri_Tfloc;
  }
    
  public void setri_Tfloc(Double ri_Tfloc)
  {
    this.ri_Tfloc = ri_Tfloc;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Double getro_RContribution()
  {
    return ro_RContribution;
  }
    
  public void setro_RContribution(Double ro_RContribution)
  {
    this.ro_RContribution = ro_RContribution;
  }
    
  public Double getro_UContribution()
  {
    return ro_UContribution;
  }
    
  public void setro_UContribution(Double ro_UContribution)
  {
    this.ro_UContribution = ro_UContribution;
  }
    
  public Double getro_EnsContribution()
  {
    return ro_EnsContribution;
  }
    
  public void setro_EnsContribution(Double ro_EnsContribution)
  {
    this.ro_EnsContribution = ro_EnsContribution;
  }
    
  public Integer getVoltACHPtr()
  {
    return VoltACHPtr;
  }
    
  public void setVoltACHPtr(Integer VoltACHPtr)
  {
    this.VoltACHPtr = VoltACHPtr;
  }
    
  public Integer getVoltACL1Ptr()
  {
    return VoltACL1Ptr;
  }
    
  public void setVoltACL1Ptr(Integer VoltACL1Ptr)
  {
    this.VoltACL1Ptr = VoltACL1Ptr;
  }
    
  public Integer getVoltACL2Ptr()
  {
    return VoltACL2Ptr;
  }
    
  public void setVoltACL2Ptr(Integer VoltACL2Ptr)
  {
    this.VoltACL2Ptr = VoltACL2Ptr;
  }
    
  public Integer getVoltDCL1Ptr()
  {
    return VoltDCL1Ptr;
  }
    
  public void setVoltDCL1Ptr(Integer VoltDCL1Ptr)
  {
    this.VoltDCL1Ptr = VoltDCL1Ptr;
  }
    
  public Integer getVoltDCL2Ptr()
  {
    return VoltDCL2Ptr;
  }
    
  public void setVoltDCL2Ptr(Integer VoltDCL2Ptr)
  {
    this.VoltDCL2Ptr = VoltDCL2Ptr;
  }
    
  public Integer getVoltDCTPtr()
  {
    return VoltDCTPtr;
  }
    
  public void setVoltDCTPtr(Integer VoltDCTPtr)
  {
    this.VoltDCTPtr = VoltDCTPtr;
  }
    
  public Integer getADConverterHPtr()
  {
    return ADConverterHPtr;
  }
    
  public void setADConverterHPtr(Integer ADConverterHPtr)
  {
    this.ADConverterHPtr = ADConverterHPtr;
  }
    
  public Integer getADConverterL1Ptr()
  {
    return ADConverterL1Ptr;
  }
    
  public void setADConverterL1Ptr(Integer ADConverterL1Ptr)
  {
    this.ADConverterL1Ptr = ADConverterL1Ptr;
  }
    
  public Integer getADConverterL2Ptr()
  {
    return ADConverterL2Ptr;
  }
    
  public void setADConverterL2Ptr(Integer ADConverterL2Ptr)
  {
    this.ADConverterL2Ptr = ADConverterL2Ptr;
  }
    
  public Integer getDDConverterL1Ptr()
  {
    return DDConverterL1Ptr;
  }
    
  public void setDDConverterL1Ptr(Integer DDConverterL1Ptr)
  {
    this.DDConverterL1Ptr = DDConverterL1Ptr;
  }
    
  public Integer getDDConverterL2Ptr()
  {
    return DDConverterL2Ptr;
  }
    
  public void setDDConverterL2Ptr(Integer DDConverterL2Ptr)
  {
    this.DDConverterL2Ptr = DDConverterL2Ptr;
  }
    
  public Integer getNodeACHPtr()
  {
    return NodeACHPtr;
  }
    
  public void setNodeACHPtr(Integer NodeACHPtr)
  {
    this.NodeACHPtr = NodeACHPtr;
  }
    
  public Integer getNodeACL1Ptr()
  {
    return NodeACL1Ptr;
  }
    
  public void setNodeACL1Ptr(Integer NodeACL1Ptr)
  {
    this.NodeACL1Ptr = NodeACL1Ptr;
  }
    
  public Integer getNodeACL2Ptr()
  {
    return NodeACL2Ptr;
  }
    
  public void setNodeACL2Ptr(Integer NodeACL2Ptr)
  {
    this.NodeACL2Ptr = NodeACL2Ptr;
  }
    
  public Integer getNodeDCL1Ptr()
  {
    return NodeDCL1Ptr;
  }
    
  public void setNodeDCL1Ptr(Integer NodeDCL1Ptr)
  {
    this.NodeDCL1Ptr = NodeDCL1Ptr;
  }
    
  public Integer getNodeDCL2Ptr()
  {
    return NodeDCL2Ptr;
  }
    
  public void setNodeDCL2Ptr(Integer NodeDCL2Ptr)
  {
    this.NodeDCL2Ptr = NodeDCL2Ptr;
  }
    
  public Integer getNodeDCTPtr()
  {
    return NodeDCTPtr;
  }
    
  public void setNodeDCTPtr(Integer NodeDCTPtr)
  {
    this.NodeDCTPtr = NodeDCTPtr;
  }
    
  public String toString()
  {
    return "ElectronicTransformer ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Substation = " + Substation
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", ACConverterNum = " + ACConverterNum
	 + ", DCConverterNum = " + DCConverterNum
	 + ", VoltagelevelACH = " + VoltagelevelACH
	 + ", VoltagelevelACL1 = " + VoltagelevelACL1
	 + ", VoltagelevelACL2 = " + VoltagelevelACL2
	 + ", VoltagelevelDCL1 = " + VoltagelevelDCL1
	 + ", VoltagelevelDCL2 = " + VoltagelevelDCL2
	 + ", VoltagelevelDCT = " + VoltagelevelDCT
	 + ", ADConverterH = " + ADConverterH
	 + ", ADConverterL1 = " + ADConverterL1
	 + ", ADConverterL2 = " + ADConverterL2
	 + ", DDConverterL1 = " + DDConverterL1
	 + ", DDConverterL2 = " + DDConverterL2
	 + ", ConnectivityNodeACH = " + ConnectivityNodeACH
	 + ", ConnectivityNodeACL1 = " + ConnectivityNodeACL1
	 + ", ConnectivityNodeACL2 = " + ConnectivityNodeACL2
	 + ", ConnectivityNodeDCL1 = " + ConnectivityNodeDCL1
	 + ", ConnectivityNodeDCL2 = " + ConnectivityNodeDCL2
	 + ", ConnectivityNodeDCT = " + ConnectivityNodeDCT
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ei_Invest = " + ei_Invest
	 + ", ro_RContribution = " + ro_RContribution
	 + ", ro_UContribution = " + ro_UContribution
	 + ", ro_EnsContribution = " + ro_EnsContribution
	 + ", VoltACHPtr = " + VoltACHPtr
	 + ", VoltACL1Ptr = " + VoltACL1Ptr
	 + ", VoltACL2Ptr = " + VoltACL2Ptr
	 + ", VoltDCL1Ptr = " + VoltDCL1Ptr
	 + ", VoltDCL2Ptr = " + VoltDCL2Ptr
	 + ", VoltDCTPtr = " + VoltDCTPtr
	 + ", ADConverterHPtr = " + ADConverterHPtr
	 + ", ADConverterL1Ptr = " + ADConverterL1Ptr
	 + ", ADConverterL2Ptr = " + ADConverterL2Ptr
	 + ", DDConverterL1Ptr = " + DDConverterL1Ptr
	 + ", DDConverterL2Ptr = " + DDConverterL2Ptr
	 + ", NodeACHPtr = " + NodeACHPtr
	 + ", NodeACL1Ptr = " + NodeACL1Ptr
	 + ", NodeACL2Ptr = " + NodeACL2Ptr
	 + ", NodeDCL1Ptr = " + NodeDCL1Ptr
	 + ", NodeDCL2Ptr = " + NodeDCL2Ptr
	 + ", NodeDCTPtr = " + NodeDCTPtr+"]";
  }
    
}
    
