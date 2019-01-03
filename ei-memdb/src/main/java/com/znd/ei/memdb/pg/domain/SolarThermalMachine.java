package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*光热发电	*
***********************/
public class SolarThermalMachine  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源Id
  private String ResourceID;
  
  //ObjectId
  private String ObjectID;
  
  //变电站
  private String Substation;
  
  //电压等级
  private String VoltageLevel;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //节点
  private String ConnectivityNode;
  
  //额定充放电功率(兆瓦)
  private Double RatedPower;
  
  //额定容量(兆瓦时)
  private Double RatedCapacity;
  
  //计划有功(兆瓦)
  private Double PlanP;
  
  //计划无功(兆乏)
  private Double PlanQ;
  
  //设备费用(万元)
  private Double ei_Invest;
  
  //额定开路电压(千伏)
  private Double RatedVoc;
  
  //循环寿命(小时)
  private Double LifeCycle;
  
  //充电效率(%)
  private Double Effc;
  
  //放电效率(%)
  private Double Effd;
  
  //光照面积
  private Double S;
  
  //光强阈值
  private Double Kc;
  
  //最大能量转换率ηc
  private Double Tr;
  
  //1月正午光照强度
  private Double Imax1;
  
  //2月正午光照强度
  private Double Imax2;
  
  //3月正午光照强度
  private Double Imax3;
  
  //4月正午光照强度
  private Double Imax4;
  
  //5月正午光照强度
  private Double Imax5;
  
  //6月正午光照强度
  private Double Imax6;
  
  //7月正午光照强度
  private Double Imax7;
  
  //8月正午光照强度
  private Double Imax8;
  
  //9月正午光照强度
  private Double Imax9;
  
  //10月正午光照强度
  private Double Imax10;
  
  //11月正午光照强度
  private Double Imax11;
  
  //12月正午光照强度
  private Double Imax12;
  
  //有功(兆瓦)
  private Double P;
  
  //无功(兆乏)
  private Double Q;
  
  //电流
  private Double A;
  
  //电压
  private Double V;
  
  //功角
  private Double D;
  
  //短路电流(安培)
  private Double SccA;
  
  //N-1通过情况
  private Integer sa_Result;
  
  //N-1形成孤岛
  private Integer sa_Island;
  
  //N-1负荷损失(兆伏安)
  private Double sa_Failure;
  
  //N-1设备负荷损失(兆瓦)
  private Double sa_Outages;
  
  //状态数
  private Integer state_num;
  
  //输出功率1
  private Double output_power1;
  
  //输出功率2
  private Double output_power2;
  
  //输出功率3
  private Double output_power3;
  
  //输出功率4
  private Double output_power4;
  
  //输出功率5
  private Double output_power5;
  
  //输出功率6
  private Double output_power6;
  
  //输出功率7
  private Double output_power7;
  
  //输出功率8
  private Double output_power8;
  
  //输出功率9
  private Double output_power9;
  
  //输出功率10
  private Double output_power10;
  
  //输出功率11
  private Double output_power11;
  
  //输出功率12
  private Double output_power12;
  
  //状态概率1
  private Double state_prob1;
  
  //状态概率2
  private Double state_prob2;
  
  //状态概率3
  private Double state_prob3;
  
  //状态概率4
  private Double state_prob4;
  
  //状态概率5
  private Double state_prob5;
  
  //状态概率6
  private Double state_prob6;
  
  //状态概率7
  private Double state_prob7;
  
  //状态概率8
  private Double state_prob8;
  
  //状态概率9
  private Double state_prob9;
  
  //状态概率10
  private Double state_prob10;
  
  //状态概率11
  private Double state_prob11;
  
  //状态概率12
  private Double state_prob12;
  
  //节点索引
  private Integer NodePtr;
  
  //拓扑节点
  private Integer TopoBus;
  
  //岛
  private Integer Island;
  
  //计算状态
  private Integer Outage;
  
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
    
  public String getObjectID()
  {
    return ObjectID;
  }
    
  public void setObjectID(String ObjectID)
  {
    this.ObjectID = ObjectID;
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
    
  public String getDescription()
  {
    return Description;
  }
    
  public void setDescription(String Description)
  {
    this.Description = Description;
  }
    
  public String getConnectivityNode()
  {
    return ConnectivityNode;
  }
    
  public void setConnectivityNode(String ConnectivityNode)
  {
    this.ConnectivityNode = ConnectivityNode;
  }
    
  public Double getRatedPower()
  {
    return RatedPower;
  }
    
  public void setRatedPower(Double RatedPower)
  {
    this.RatedPower = RatedPower;
  }
    
  public Double getRatedCapacity()
  {
    return RatedCapacity;
  }
    
  public void setRatedCapacity(Double RatedCapacity)
  {
    this.RatedCapacity = RatedCapacity;
  }
    
  public Double getPlanP()
  {
    return PlanP;
  }
    
  public void setPlanP(Double PlanP)
  {
    this.PlanP = PlanP;
  }
    
  public Double getPlanQ()
  {
    return PlanQ;
  }
    
  public void setPlanQ(Double PlanQ)
  {
    this.PlanQ = PlanQ;
  }
    
  public Double getei_Invest()
  {
    return ei_Invest;
  }
    
  public void setei_Invest(Double ei_Invest)
  {
    this.ei_Invest = ei_Invest;
  }
    
  public Double getRatedVoc()
  {
    return RatedVoc;
  }
    
  public void setRatedVoc(Double RatedVoc)
  {
    this.RatedVoc = RatedVoc;
  }
    
  public Double getLifeCycle()
  {
    return LifeCycle;
  }
    
  public void setLifeCycle(Double LifeCycle)
  {
    this.LifeCycle = LifeCycle;
  }
    
  public Double getEffc()
  {
    return Effc;
  }
    
  public void setEffc(Double Effc)
  {
    this.Effc = Effc;
  }
    
  public Double getEffd()
  {
    return Effd;
  }
    
  public void setEffd(Double Effd)
  {
    this.Effd = Effd;
  }
    
  public Double getS()
  {
    return S;
  }
    
  public void setS(Double S)
  {
    this.S = S;
  }
    
  public Double getKc()
  {
    return Kc;
  }
    
  public void setKc(Double Kc)
  {
    this.Kc = Kc;
  }
    
  public Double getTr()
  {
    return Tr;
  }
    
  public void setTr(Double Tr)
  {
    this.Tr = Tr;
  }
    
  public Double getImax1()
  {
    return Imax1;
  }
    
  public void setImax1(Double Imax1)
  {
    this.Imax1 = Imax1;
  }
    
  public Double getImax2()
  {
    return Imax2;
  }
    
  public void setImax2(Double Imax2)
  {
    this.Imax2 = Imax2;
  }
    
  public Double getImax3()
  {
    return Imax3;
  }
    
  public void setImax3(Double Imax3)
  {
    this.Imax3 = Imax3;
  }
    
  public Double getImax4()
  {
    return Imax4;
  }
    
  public void setImax4(Double Imax4)
  {
    this.Imax4 = Imax4;
  }
    
  public Double getImax5()
  {
    return Imax5;
  }
    
  public void setImax5(Double Imax5)
  {
    this.Imax5 = Imax5;
  }
    
  public Double getImax6()
  {
    return Imax6;
  }
    
  public void setImax6(Double Imax6)
  {
    this.Imax6 = Imax6;
  }
    
  public Double getImax7()
  {
    return Imax7;
  }
    
  public void setImax7(Double Imax7)
  {
    this.Imax7 = Imax7;
  }
    
  public Double getImax8()
  {
    return Imax8;
  }
    
  public void setImax8(Double Imax8)
  {
    this.Imax8 = Imax8;
  }
    
  public Double getImax9()
  {
    return Imax9;
  }
    
  public void setImax9(Double Imax9)
  {
    this.Imax9 = Imax9;
  }
    
  public Double getImax10()
  {
    return Imax10;
  }
    
  public void setImax10(Double Imax10)
  {
    this.Imax10 = Imax10;
  }
    
  public Double getImax11()
  {
    return Imax11;
  }
    
  public void setImax11(Double Imax11)
  {
    this.Imax11 = Imax11;
  }
    
  public Double getImax12()
  {
    return Imax12;
  }
    
  public void setImax12(Double Imax12)
  {
    this.Imax12 = Imax12;
  }
    
  public Double getP()
  {
    return P;
  }
    
  public void setP(Double P)
  {
    this.P = P;
  }
    
  public Double getQ()
  {
    return Q;
  }
    
  public void setQ(Double Q)
  {
    this.Q = Q;
  }
    
  public Double getA()
  {
    return A;
  }
    
  public void setA(Double A)
  {
    this.A = A;
  }
    
  public Double getV()
  {
    return V;
  }
    
  public void setV(Double V)
  {
    this.V = V;
  }
    
  public Double getD()
  {
    return D;
  }
    
  public void setD(Double D)
  {
    this.D = D;
  }
    
  public Double getSccA()
  {
    return SccA;
  }
    
  public void setSccA(Double SccA)
  {
    this.SccA = SccA;
  }
    
  public Integer getsa_Result()
  {
    return sa_Result;
  }
    
  public void setsa_Result(Integer sa_Result)
  {
    this.sa_Result = sa_Result;
  }
    
  public Integer getsa_Island()
  {
    return sa_Island;
  }
    
  public void setsa_Island(Integer sa_Island)
  {
    this.sa_Island = sa_Island;
  }
    
  public Double getsa_Failure()
  {
    return sa_Failure;
  }
    
  public void setsa_Failure(Double sa_Failure)
  {
    this.sa_Failure = sa_Failure;
  }
    
  public Double getsa_Outages()
  {
    return sa_Outages;
  }
    
  public void setsa_Outages(Double sa_Outages)
  {
    this.sa_Outages = sa_Outages;
  }
    
  public Integer getstate_num()
  {
    return state_num;
  }
    
  public void setstate_num(Integer state_num)
  {
    this.state_num = state_num;
  }
    
  public Double getoutput_power1()
  {
    return output_power1;
  }
    
  public void setoutput_power1(Double output_power1)
  {
    this.output_power1 = output_power1;
  }
    
  public Double getoutput_power2()
  {
    return output_power2;
  }
    
  public void setoutput_power2(Double output_power2)
  {
    this.output_power2 = output_power2;
  }
    
  public Double getoutput_power3()
  {
    return output_power3;
  }
    
  public void setoutput_power3(Double output_power3)
  {
    this.output_power3 = output_power3;
  }
    
  public Double getoutput_power4()
  {
    return output_power4;
  }
    
  public void setoutput_power4(Double output_power4)
  {
    this.output_power4 = output_power4;
  }
    
  public Double getoutput_power5()
  {
    return output_power5;
  }
    
  public void setoutput_power5(Double output_power5)
  {
    this.output_power5 = output_power5;
  }
    
  public Double getoutput_power6()
  {
    return output_power6;
  }
    
  public void setoutput_power6(Double output_power6)
  {
    this.output_power6 = output_power6;
  }
    
  public Double getoutput_power7()
  {
    return output_power7;
  }
    
  public void setoutput_power7(Double output_power7)
  {
    this.output_power7 = output_power7;
  }
    
  public Double getoutput_power8()
  {
    return output_power8;
  }
    
  public void setoutput_power8(Double output_power8)
  {
    this.output_power8 = output_power8;
  }
    
  public Double getoutput_power9()
  {
    return output_power9;
  }
    
  public void setoutput_power9(Double output_power9)
  {
    this.output_power9 = output_power9;
  }
    
  public Double getoutput_power10()
  {
    return output_power10;
  }
    
  public void setoutput_power10(Double output_power10)
  {
    this.output_power10 = output_power10;
  }
    
  public Double getoutput_power11()
  {
    return output_power11;
  }
    
  public void setoutput_power11(Double output_power11)
  {
    this.output_power11 = output_power11;
  }
    
  public Double getoutput_power12()
  {
    return output_power12;
  }
    
  public void setoutput_power12(Double output_power12)
  {
    this.output_power12 = output_power12;
  }
    
  public Double getstate_prob1()
  {
    return state_prob1;
  }
    
  public void setstate_prob1(Double state_prob1)
  {
    this.state_prob1 = state_prob1;
  }
    
  public Double getstate_prob2()
  {
    return state_prob2;
  }
    
  public void setstate_prob2(Double state_prob2)
  {
    this.state_prob2 = state_prob2;
  }
    
  public Double getstate_prob3()
  {
    return state_prob3;
  }
    
  public void setstate_prob3(Double state_prob3)
  {
    this.state_prob3 = state_prob3;
  }
    
  public Double getstate_prob4()
  {
    return state_prob4;
  }
    
  public void setstate_prob4(Double state_prob4)
  {
    this.state_prob4 = state_prob4;
  }
    
  public Double getstate_prob5()
  {
    return state_prob5;
  }
    
  public void setstate_prob5(Double state_prob5)
  {
    this.state_prob5 = state_prob5;
  }
    
  public Double getstate_prob6()
  {
    return state_prob6;
  }
    
  public void setstate_prob6(Double state_prob6)
  {
    this.state_prob6 = state_prob6;
  }
    
  public Double getstate_prob7()
  {
    return state_prob7;
  }
    
  public void setstate_prob7(Double state_prob7)
  {
    this.state_prob7 = state_prob7;
  }
    
  public Double getstate_prob8()
  {
    return state_prob8;
  }
    
  public void setstate_prob8(Double state_prob8)
  {
    this.state_prob8 = state_prob8;
  }
    
  public Double getstate_prob9()
  {
    return state_prob9;
  }
    
  public void setstate_prob9(Double state_prob9)
  {
    this.state_prob9 = state_prob9;
  }
    
  public Double getstate_prob10()
  {
    return state_prob10;
  }
    
  public void setstate_prob10(Double state_prob10)
  {
    this.state_prob10 = state_prob10;
  }
    
  public Double getstate_prob11()
  {
    return state_prob11;
  }
    
  public void setstate_prob11(Double state_prob11)
  {
    this.state_prob11 = state_prob11;
  }
    
  public Double getstate_prob12()
  {
    return state_prob12;
  }
    
  public void setstate_prob12(Double state_prob12)
  {
    this.state_prob12 = state_prob12;
  }
    
  public Integer getNodePtr()
  {
    return NodePtr;
  }
    
  public void setNodePtr(Integer NodePtr)
  {
    this.NodePtr = NodePtr;
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
    
  public Integer getOutage()
  {
    return Outage;
  }
    
  public void setOutage(Integer Outage)
  {
    this.Outage = Outage;
  }
    
  public String toString()
  {
    return "SolarThermalMachine ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", ObjectID = " + ObjectID
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", ConnectivityNode = " + ConnectivityNode
	 + ", RatedPower = " + RatedPower
	 + ", RatedCapacity = " + RatedCapacity
	 + ", PlanP = " + PlanP
	 + ", PlanQ = " + PlanQ
	 + ", ei_Invest = " + ei_Invest
	 + ", RatedVoc = " + RatedVoc
	 + ", LifeCycle = " + LifeCycle
	 + ", Effc = " + Effc
	 + ", Effd = " + Effd
	 + ", S = " + S
	 + ", Kc = " + Kc
	 + ", Tr = " + Tr
	 + ", Imax1 = " + Imax1
	 + ", Imax2 = " + Imax2
	 + ", Imax3 = " + Imax3
	 + ", Imax4 = " + Imax4
	 + ", Imax5 = " + Imax5
	 + ", Imax6 = " + Imax6
	 + ", Imax7 = " + Imax7
	 + ", Imax8 = " + Imax8
	 + ", Imax9 = " + Imax9
	 + ", Imax10 = " + Imax10
	 + ", Imax11 = " + Imax11
	 + ", Imax12 = " + Imax12
	 + ", P = " + P
	 + ", Q = " + Q
	 + ", A = " + A
	 + ", V = " + V
	 + ", D = " + D
	 + ", SccA = " + SccA
	 + ", sa_Result = " + sa_Result
	 + ", sa_Island = " + sa_Island
	 + ", sa_Failure = " + sa_Failure
	 + ", sa_Outages = " + sa_Outages
	 + ", state_num = " + state_num
	 + ", output_power1 = " + output_power1
	 + ", output_power2 = " + output_power2
	 + ", output_power3 = " + output_power3
	 + ", output_power4 = " + output_power4
	 + ", output_power5 = " + output_power5
	 + ", output_power6 = " + output_power6
	 + ", output_power7 = " + output_power7
	 + ", output_power8 = " + output_power8
	 + ", output_power9 = " + output_power9
	 + ", output_power10 = " + output_power10
	 + ", output_power11 = " + output_power11
	 + ", output_power12 = " + output_power12
	 + ", state_prob1 = " + state_prob1
	 + ", state_prob2 = " + state_prob2
	 + ", state_prob3 = " + state_prob3
	 + ", state_prob4 = " + state_prob4
	 + ", state_prob5 = " + state_prob5
	 + ", state_prob6 = " + state_prob6
	 + ", state_prob7 = " + state_prob7
	 + ", state_prob8 = " + state_prob8
	 + ", state_prob9 = " + state_prob9
	 + ", state_prob10 = " + state_prob10
	 + ", state_prob11 = " + state_prob11
	 + ", state_prob12 = " + state_prob12
	 + ", NodePtr = " + NodePtr
	 + ", TopoBus = " + TopoBus
	 + ", Island = " + Island
	 + ", Outage = " + Outage+"]";
  }
    
}
    
