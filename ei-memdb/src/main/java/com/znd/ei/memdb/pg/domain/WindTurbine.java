package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*风电(场)	*
***********************/
public class WindTurbine  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源ID
  private String ResourceID;
  
  //厂站
  private String Substation;
  
  //电压等级
  private String VoltageLevel;
  
  //名称
  private String Name;
  
  //节点
  private String ConnectivityNode;
  
  //容量(兆伏安)
  private Double RatedMva;
  
  //计划有功(兆瓦)
  private Double PlanP;
  
  //计划无功(兆乏)
  private Double PlanQ;
  
  //切入风速(米/秒)
  private Double cutin_windspeed;
  
  //切出风速(米/秒)
  private Double cutout_windspeed;
  
  //额定风速(米/秒)
  private Double rate_windspeed;
  
  //额定功率(米/秒)
  private Double rate_power;
  
  //平均风速(米/秒)
  private Double mean_windspeed;
  
  //风速标准差(米/秒)
  private Double stddev_windspeed;
  
  //状态数
  private Integer state_num;
  
  //单相接地频率(次/年)
  private Double vd_RScc1;
  
  //相间短路频率(次/年)
  private Double vd_RScc2;
  
  //三相短路频率(次/年)
  private Double vd_RScc3;
  
  //两相接地频率(次/年)
  private Double vd_RScc4;
  
  //故障率(次/台.年)
  private Double ri_Rerr;
  
  //修复时间(小时/次)
  private Double ri_Trep;
  
  //计划检修率(次/台.年)
  private Double ri_Rchk;
  
  //检修时间(小时/次)
  private Double ri_Tchk;
  
  //故障定位隔离时间(小时)
  private Double ri_Tfloc;
  
  //投资费用(万元)
  private Double ei_Invest;
  
  //风机典型出力曲线
  private String TDCurve;
  
  //有功(兆瓦)
  private Double P;
  
  //无功(兆乏)
  private Double Q;
  
  //电流(安培)
  private Double A;
  
  //电压(千伏)
  private Double V;
  
  //功角(度)
  private Double D;
  
  //短路电流(安培)
  private Double scc;
  
  //N-1通过情况
  private Integer sa_Result;
  
  //N-1形成孤岛
  private Integer sa_Island;
  
  //N-1负荷损失(兆伏安)
  private Double sa_Failure;
  
  //N-1设备负荷损失(兆瓦)
  private Double sa_Outages;
  
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
  
  //电岛
  private Integer Island;
  
  //状态
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
    
  public String getConnectivityNode()
  {
    return ConnectivityNode;
  }
    
  public void setConnectivityNode(String ConnectivityNode)
  {
    this.ConnectivityNode = ConnectivityNode;
  }
    
  public Double getRatedMva()
  {
    return RatedMva;
  }
    
  public void setRatedMva(Double RatedMva)
  {
    this.RatedMva = RatedMva;
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
    
  public Double getcutin_windspeed()
  {
    return cutin_windspeed;
  }
    
  public void setcutin_windspeed(Double cutin_windspeed)
  {
    this.cutin_windspeed = cutin_windspeed;
  }
    
  public Double getcutout_windspeed()
  {
    return cutout_windspeed;
  }
    
  public void setcutout_windspeed(Double cutout_windspeed)
  {
    this.cutout_windspeed = cutout_windspeed;
  }
    
  public Double getrate_windspeed()
  {
    return rate_windspeed;
  }
    
  public void setrate_windspeed(Double rate_windspeed)
  {
    this.rate_windspeed = rate_windspeed;
  }
    
  public Double getrate_power()
  {
    return rate_power;
  }
    
  public void setrate_power(Double rate_power)
  {
    this.rate_power = rate_power;
  }
    
  public Double getmean_windspeed()
  {
    return mean_windspeed;
  }
    
  public void setmean_windspeed(Double mean_windspeed)
  {
    this.mean_windspeed = mean_windspeed;
  }
    
  public Double getstddev_windspeed()
  {
    return stddev_windspeed;
  }
    
  public void setstddev_windspeed(Double stddev_windspeed)
  {
    this.stddev_windspeed = stddev_windspeed;
  }
    
  public Integer getstate_num()
  {
    return state_num;
  }
    
  public void setstate_num(Integer state_num)
  {
    this.state_num = state_num;
  }
    
  public Double getvd_RScc1()
  {
    return vd_RScc1;
  }
    
  public void setvd_RScc1(Double vd_RScc1)
  {
    this.vd_RScc1 = vd_RScc1;
  }
    
  public Double getvd_RScc2()
  {
    return vd_RScc2;
  }
    
  public void setvd_RScc2(Double vd_RScc2)
  {
    this.vd_RScc2 = vd_RScc2;
  }
    
  public Double getvd_RScc3()
  {
    return vd_RScc3;
  }
    
  public void setvd_RScc3(Double vd_RScc3)
  {
    this.vd_RScc3 = vd_RScc3;
  }
    
  public Double getvd_RScc4()
  {
    return vd_RScc4;
  }
    
  public void setvd_RScc4(Double vd_RScc4)
  {
    this.vd_RScc4 = vd_RScc4;
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
    
  public String getTDCurve()
  {
    return TDCurve;
  }
    
  public void setTDCurve(String TDCurve)
  {
    this.TDCurve = TDCurve;
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
    
  public Double getscc()
  {
    return scc;
  }
    
  public void setscc(Double scc)
  {
    this.scc = scc;
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
    return "WindTurbine ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Substation = " + Substation
	 + ", VoltageLevel = " + VoltageLevel
	 + ", Name = " + Name
	 + ", ConnectivityNode = " + ConnectivityNode
	 + ", RatedMva = " + RatedMva
	 + ", PlanP = " + PlanP
	 + ", PlanQ = " + PlanQ
	 + ", cutin_windspeed = " + cutin_windspeed
	 + ", cutout_windspeed = " + cutout_windspeed
	 + ", rate_windspeed = " + rate_windspeed
	 + ", rate_power = " + rate_power
	 + ", mean_windspeed = " + mean_windspeed
	 + ", stddev_windspeed = " + stddev_windspeed
	 + ", state_num = " + state_num
	 + ", vd_RScc1 = " + vd_RScc1
	 + ", vd_RScc2 = " + vd_RScc2
	 + ", vd_RScc3 = " + vd_RScc3
	 + ", vd_RScc4 = " + vd_RScc4
	 + ", ri_Rerr = " + ri_Rerr
	 + ", ri_Trep = " + ri_Trep
	 + ", ri_Rchk = " + ri_Rchk
	 + ", ri_Tchk = " + ri_Tchk
	 + ", ri_Tfloc = " + ri_Tfloc
	 + ", ei_Invest = " + ei_Invest
	 + ", TDCurve = " + TDCurve
	 + ", P = " + P
	 + ", Q = " + Q
	 + ", A = " + A
	 + ", V = " + V
	 + ", D = " + D
	 + ", scc = " + scc
	 + ", sa_Result = " + sa_Result
	 + ", sa_Island = " + sa_Island
	 + ", sa_Failure = " + sa_Failure
	 + ", sa_Outages = " + sa_Outages
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
    
