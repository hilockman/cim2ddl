package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;


/**********************
*节点表(ACBus)	*
***********************/
public class BpaDat_ACBus implements MemIndexable
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //所有者
  private String aCBus_Owner;
  
  //母线名称
  private String aCBus_Name;
  
  //基准电压(kV)
  private Double aCBus_kV;
  
  //分区名
  private String aCBus_Zone;
  
  //恒定有功负荷(MW)
  private Double aCBus_PLoad;
  
  //恒定无功负荷(MVAR),+感性
  private Double aCBus_QLoad;
  
  //并联导纳有功负荷(MW)
  private Double aCBus_PShunt;
  
  //并联导纳无功负荷(MVAR),+容性
  private Double aCBus_QShunt;
  
  //最大有功出力(MW)
  private Double aCBus_Pmax;
  
  //实际有功出力(MW)
  private Double aCBus_PGen;
  
  //安排的无功出力值,+容性
  private Double aCBus_Qsched_Qmax;
  
  //无功出力最小值(MVAR),此处填0
  private Double aCBus_Qmin;
  
  //安排的Vmax(pu)
  private Double aCBus_VHold_max;
  
  //安排的Vmin(pu)
  private Double aCBus_Vmin;
  
  //远方要控制的母线名称
  private String aCBus_RBusName;
  
  //远方要控制的基准电压(kV)
  private Double aCBus_RBusVolt;
  
  //提供的无功功率百分数(%)
  private Double aCBus_VarSppld;
  
  //延续节点负荷模型类型子代码
  private String aCBus_AddCode;
  
  //延续节点恒定有功负荷(MW)
  private Double aCBus_AddPLoad;
  
  //延续节点恒定无功负荷(MVAR),+感性
  private Double aCBus_AddQLoad;
  
  //延续节点并联导纳有功负荷(MW)
  private Double aCBus_AddPShunt;
  
  //延续节点并联导纳无功负荷(MVAR),+容性
  private Double aCBus_AddQShunt;
  
  //延续节点有功出力(MW)
  private Double aCBus_AddPGen;
  
  //延续节点无功出力(MVAR),+感性
  private Double aCBus_AddQGen;
  
  //母线所属BPA厂站
  private String aCBus_BpaSub;
  
  //交流母线别名
  private String aCBus_Alias;
  
  //母线电压
  private Double aCBus_V;
  
  //母线功角
  private Double aCBus_D;
  
  //母线计算发电有功
  private Double aCBus_PfoPGen;
  
  //母线计算发电无功
  private Double aCBus_PfoQGen;
  
  //母线计算负荷有功
  private Double aCBus_PfoPLoad;
  
  //母线计算负荷无功
  private Double aCBus_PfoQLoad;
  
  //母线计算补偿无功
  private Double aCBus_PfoQShunt;
  
  //母线计算注入有功
  private Double aCBus_PfoPNet;
  
  //母线计算注入无功
  private Double aCBus_PfoQNet;
  
  //母线故障率(次/年)
  private Double vd_Rerr;
  
  //单相接地频率(次/年)
  private Double vd_RScc1;
  
  //相间短路频率(次/年)
  private Double vd_RScc2;
  
  //三相短路频率(次/年)
  private Double vd_RScc3;
  
  //两相接地频率(次/年)
  private Double vd_RScc4;
  
  //RT实际有功出力(MW)
  private Double aCBus_RtGenP;
  
  //RT安排的无功出力值
  private Double aCBus_RtGenQ;
  
  //RT恒定有功负荷(MW)
  private Double aCBus_RtLoadP;
  
  //RT恒定无功负荷(MVAR)
  private Double aCBus_RtLoadQ;
  
  //RT并联导纳无功负荷(MVAR)
  private Double aCBus_RtShuntQ;
  
  //RT安排的V(pu)
  private Double aCBus_RtVHold;
  
  //母线故障电流(A)
  private Double aCBus_SccA;
  
  //母线故障电压(kV)
  private Double aCBus_SccV;
  
  //母线正序等值阻抗(R1,pu)
  private Double aCBus_SccR1;
  
  //母线正序等值阻抗(X1,pu)
  private Double aCBus_SccX1;
  
  //母线负序等值阻抗(R2,pu)
  private Double aCBus_SccR2;
  
  //母线负序等值阻抗(X2,pu)
  private Double aCBus_SccX2;
  
  //母线零序等值阻抗(R0,pu)
  private Double aCBus_SccR0;
  
  //母线零序等值阻抗(X0,pu)
  private Double aCBus_SccX0;
  
  //正序故障电流实部(pu)
  private Double aCBus_SccA1Re;
  
  //正序故障电流虚部(pu)
  private Double aCBus_SccA1Im;
  
  //负序故障电流实部(pu)
  private Double aCBus_SccA2Re;
  
  //负序故障电流虚部(pu)
  private Double aCBus_SccA2Im;
  
  //零序故障电流实部(pu)
  private Double aCBus_SccA0Re;
  
  //零序故障电流虚部(pu)
  private Double aCBus_SccA0Im;
  
  //正序故障电压实部(pu)
  private Double aCBus_SccV1Re;
  
  //正序故障电压虚部(pu)
  private Double aCBus_SccV1Im;
  
  //负序故障电压实部(pu)
  private Double aCBus_SccV2Re;
  
  //负序故障电压虚部(pu)
  private Double aCBus_SccV2Im;
  
  //零序故障电压实部(pu)
  private Double aCBus_SccV0Re;
  
  //零序故障电压虚部(pu)
  private Double aCBus_SccV0Im;
  
  //母线单相接地暂降母线数
  private Integer aCBus_VDipBus1;
  
  //母线相间短路暂降母线数
  private Integer aCBus_VDipBus2;
  
  //母线三相短路暂降母线数
  private Integer aCBus_VDipBus3;
  
  //母线两相接地暂降母线数
  private Integer aCBus_VDipBus4;
  
  //Ini恒定有功负荷(MW)
  private Double aCBus_IniPLoad;
  
  //Ini恒定无功负荷(MVAR),+感性
  private Double aCBus_IniQLoad;
  
  //Ini并联导纳有功负荷(MW)
  private Double aCBus_IniPShunt;
  
  //Ini并联导纳无功负荷(MVAR),+容性
  private Double aCBus_IniQShunt;
  
  //Ini有功出力(MW)
  private Double aCBus_IniPGen;
  
  //Ini无功出力值,+容性
  private Double aCBus_IniQGen;
  
  //变压器中性点标记
  private Integer tMid;
  
  //发电机母线标记
  private Integer generator;
  
  //并网风电机组机标记
  private Integer wTGen;
  
  //并网光伏机组机标记
  private Integer pVGen;
  
  //交直流边界母线
  private Integer dCBound;
  
  //等值发电机母线标记
  private Integer genLn;
  
  //母线状态
  private Integer status;
  
  //化简等值母线
  private Integer redcution;
  
  //环网设备
  private Integer inRing;
  
  //所在辐射网
  private Integer radiate;
  
  //交流岛
  private Integer aCIsland;
  
  //母线线路索引
  private Integer pRLine;
  
  //母线变压器索引
  private Integer pRTran;
  
  //母线高抗索引
  private Integer pRHG;
  
  //母线厂站索引
  private Integer pRSub;
  
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
    
  public String getACBus_Owner()
  {
    return aCBus_Owner;
  }
    
  public void setACBus_Owner(String aCBus_Owner)
  {
    this.aCBus_Owner = aCBus_Owner;
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
    
  public String getACBus_Zone()
  {
    return aCBus_Zone;
  }
    
  public void setACBus_Zone(String aCBus_Zone)
  {
    this.aCBus_Zone = aCBus_Zone;
  }
    
  public Double getACBus_PLoad()
  {
    return aCBus_PLoad;
  }
    
  public void setACBus_PLoad(Double aCBus_PLoad)
  {
    this.aCBus_PLoad = aCBus_PLoad;
  }
    
  public Double getACBus_QLoad()
  {
    return aCBus_QLoad;
  }
    
  public void setACBus_QLoad(Double aCBus_QLoad)
  {
    this.aCBus_QLoad = aCBus_QLoad;
  }
    
  public Double getACBus_PShunt()
  {
    return aCBus_PShunt;
  }
    
  public void setACBus_PShunt(Double aCBus_PShunt)
  {
    this.aCBus_PShunt = aCBus_PShunt;
  }
    
  public Double getACBus_QShunt()
  {
    return aCBus_QShunt;
  }
    
  public void setACBus_QShunt(Double aCBus_QShunt)
  {
    this.aCBus_QShunt = aCBus_QShunt;
  }
    
  public Double getACBus_Pmax()
  {
    return aCBus_Pmax;
  }
    
  public void setACBus_Pmax(Double aCBus_Pmax)
  {
    this.aCBus_Pmax = aCBus_Pmax;
  }
    
  public Double getACBus_PGen()
  {
    return aCBus_PGen;
  }
    
  public void setACBus_PGen(Double aCBus_PGen)
  {
    this.aCBus_PGen = aCBus_PGen;
  }
    
  public Double getACBus_Qsched_Qmax()
  {
    return aCBus_Qsched_Qmax;
  }
    
  public void setACBus_Qsched_Qmax(Double aCBus_Qsched_Qmax)
  {
    this.aCBus_Qsched_Qmax = aCBus_Qsched_Qmax;
  }
    
  public Double getACBus_Qmin()
  {
    return aCBus_Qmin;
  }
    
  public void setACBus_Qmin(Double aCBus_Qmin)
  {
    this.aCBus_Qmin = aCBus_Qmin;
  }
    
  public Double getACBus_VHold_max()
  {
    return aCBus_VHold_max;
  }
    
  public void setACBus_VHold_max(Double aCBus_VHold_max)
  {
    this.aCBus_VHold_max = aCBus_VHold_max;
  }
    
  public Double getACBus_Vmin()
  {
    return aCBus_Vmin;
  }
    
  public void setACBus_Vmin(Double aCBus_Vmin)
  {
    this.aCBus_Vmin = aCBus_Vmin;
  }
    
  public String getACBus_RBusName()
  {
    return aCBus_RBusName;
  }
    
  public void setACBus_RBusName(String aCBus_RBusName)
  {
    this.aCBus_RBusName = aCBus_RBusName;
  }
    
  public Double getACBus_RBusVolt()
  {
    return aCBus_RBusVolt;
  }
    
  public void setACBus_RBusVolt(Double aCBus_RBusVolt)
  {
    this.aCBus_RBusVolt = aCBus_RBusVolt;
  }
    
  public Double getACBus_VarSppld()
  {
    return aCBus_VarSppld;
  }
    
  public void setACBus_VarSppld(Double aCBus_VarSppld)
  {
    this.aCBus_VarSppld = aCBus_VarSppld;
  }
    
  public String getACBus_AddCode()
  {
    return aCBus_AddCode;
  }
    
  public void setACBus_AddCode(String aCBus_AddCode)
  {
    this.aCBus_AddCode = aCBus_AddCode;
  }
    
  public Double getACBus_AddPLoad()
  {
    return aCBus_AddPLoad;
  }
    
  public void setACBus_AddPLoad(Double aCBus_AddPLoad)
  {
    this.aCBus_AddPLoad = aCBus_AddPLoad;
  }
    
  public Double getACBus_AddQLoad()
  {
    return aCBus_AddQLoad;
  }
    
  public void setACBus_AddQLoad(Double aCBus_AddQLoad)
  {
    this.aCBus_AddQLoad = aCBus_AddQLoad;
  }
    
  public Double getACBus_AddPShunt()
  {
    return aCBus_AddPShunt;
  }
    
  public void setACBus_AddPShunt(Double aCBus_AddPShunt)
  {
    this.aCBus_AddPShunt = aCBus_AddPShunt;
  }
    
  public Double getACBus_AddQShunt()
  {
    return aCBus_AddQShunt;
  }
    
  public void setACBus_AddQShunt(Double aCBus_AddQShunt)
  {
    this.aCBus_AddQShunt = aCBus_AddQShunt;
  }
    
  public Double getACBus_AddPGen()
  {
    return aCBus_AddPGen;
  }
    
  public void setACBus_AddPGen(Double aCBus_AddPGen)
  {
    this.aCBus_AddPGen = aCBus_AddPGen;
  }
    
  public Double getACBus_AddQGen()
  {
    return aCBus_AddQGen;
  }
    
  public void setACBus_AddQGen(Double aCBus_AddQGen)
  {
    this.aCBus_AddQGen = aCBus_AddQGen;
  }
    
  public String getACBus_BpaSub()
  {
    return aCBus_BpaSub;
  }
    
  public void setACBus_BpaSub(String aCBus_BpaSub)
  {
    this.aCBus_BpaSub = aCBus_BpaSub;
  }
    
  public String getACBus_Alias()
  {
    return aCBus_Alias;
  }
    
  public void setACBus_Alias(String aCBus_Alias)
  {
    this.aCBus_Alias = aCBus_Alias;
  }
    
  public Double getACBus_V()
  {
    return aCBus_V;
  }
    
  public void setACBus_V(Double aCBus_V)
  {
    this.aCBus_V = aCBus_V;
  }
    
  public Double getACBus_D()
  {
    return aCBus_D;
  }
    
  public void setACBus_D(Double aCBus_D)
  {
    this.aCBus_D = aCBus_D;
  }
    
  public Double getACBus_PfoPGen()
  {
    return aCBus_PfoPGen;
  }
    
  public void setACBus_PfoPGen(Double aCBus_PfoPGen)
  {
    this.aCBus_PfoPGen = aCBus_PfoPGen;
  }
    
  public Double getACBus_PfoQGen()
  {
    return aCBus_PfoQGen;
  }
    
  public void setACBus_PfoQGen(Double aCBus_PfoQGen)
  {
    this.aCBus_PfoQGen = aCBus_PfoQGen;
  }
    
  public Double getACBus_PfoPLoad()
  {
    return aCBus_PfoPLoad;
  }
    
  public void setACBus_PfoPLoad(Double aCBus_PfoPLoad)
  {
    this.aCBus_PfoPLoad = aCBus_PfoPLoad;
  }
    
  public Double getACBus_PfoQLoad()
  {
    return aCBus_PfoQLoad;
  }
    
  public void setACBus_PfoQLoad(Double aCBus_PfoQLoad)
  {
    this.aCBus_PfoQLoad = aCBus_PfoQLoad;
  }
    
  public Double getACBus_PfoQShunt()
  {
    return aCBus_PfoQShunt;
  }
    
  public void setACBus_PfoQShunt(Double aCBus_PfoQShunt)
  {
    this.aCBus_PfoQShunt = aCBus_PfoQShunt;
  }
    
  public Double getACBus_PfoPNet()
  {
    return aCBus_PfoPNet;
  }
    
  public void setACBus_PfoPNet(Double aCBus_PfoPNet)
  {
    this.aCBus_PfoPNet = aCBus_PfoPNet;
  }
    
  public Double getACBus_PfoQNet()
  {
    return aCBus_PfoQNet;
  }
    
  public void setACBus_PfoQNet(Double aCBus_PfoQNet)
  {
    this.aCBus_PfoQNet = aCBus_PfoQNet;
  }
    
  public Double getvd_Rerr()
  {
    return vd_Rerr;
  }
    
  public void setvd_Rerr(Double vd_Rerr)
  {
    this.vd_Rerr = vd_Rerr;
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
    
  public Double getACBus_RtGenP()
  {
    return aCBus_RtGenP;
  }
    
  public void setACBus_RtGenP(Double aCBus_RtGenP)
  {
    this.aCBus_RtGenP = aCBus_RtGenP;
  }
    
  public Double getACBus_RtGenQ()
  {
    return aCBus_RtGenQ;
  }
    
  public void setACBus_RtGenQ(Double aCBus_RtGenQ)
  {
    this.aCBus_RtGenQ = aCBus_RtGenQ;
  }
    
  public Double getACBus_RtLoadP()
  {
    return aCBus_RtLoadP;
  }
    
  public void setACBus_RtLoadP(Double aCBus_RtLoadP)
  {
    this.aCBus_RtLoadP = aCBus_RtLoadP;
  }
    
  public Double getACBus_RtLoadQ()
  {
    return aCBus_RtLoadQ;
  }
    
  public void setACBus_RtLoadQ(Double aCBus_RtLoadQ)
  {
    this.aCBus_RtLoadQ = aCBus_RtLoadQ;
  }
    
  public Double getACBus_RtShuntQ()
  {
    return aCBus_RtShuntQ;
  }
    
  public void setACBus_RtShuntQ(Double aCBus_RtShuntQ)
  {
    this.aCBus_RtShuntQ = aCBus_RtShuntQ;
  }
    
  public Double getACBus_RtVHold()
  {
    return aCBus_RtVHold;
  }
    
  public void setACBus_RtVHold(Double aCBus_RtVHold)
  {
    this.aCBus_RtVHold = aCBus_RtVHold;
  }
    
  public Double getACBus_SccA()
  {
    return aCBus_SccA;
  }
    
  public void setACBus_SccA(Double aCBus_SccA)
  {
    this.aCBus_SccA = aCBus_SccA;
  }
    
  public Double getACBus_SccV()
  {
    return aCBus_SccV;
  }
    
  public void setACBus_SccV(Double aCBus_SccV)
  {
    this.aCBus_SccV = aCBus_SccV;
  }
    
  public Double getACBus_SccR1()
  {
    return aCBus_SccR1;
  }
    
  public void setACBus_SccR1(Double aCBus_SccR1)
  {
    this.aCBus_SccR1 = aCBus_SccR1;
  }
    
  public Double getACBus_SccX1()
  {
    return aCBus_SccX1;
  }
    
  public void setACBus_SccX1(Double aCBus_SccX1)
  {
    this.aCBus_SccX1 = aCBus_SccX1;
  }
    
  public Double getACBus_SccR2()
  {
    return aCBus_SccR2;
  }
    
  public void setACBus_SccR2(Double aCBus_SccR2)
  {
    this.aCBus_SccR2 = aCBus_SccR2;
  }
    
  public Double getACBus_SccX2()
  {
    return aCBus_SccX2;
  }
    
  public void setACBus_SccX2(Double aCBus_SccX2)
  {
    this.aCBus_SccX2 = aCBus_SccX2;
  }
    
  public Double getACBus_SccR0()
  {
    return aCBus_SccR0;
  }
    
  public void setACBus_SccR0(Double aCBus_SccR0)
  {
    this.aCBus_SccR0 = aCBus_SccR0;
  }
    
  public Double getACBus_SccX0()
  {
    return aCBus_SccX0;
  }
    
  public void setACBus_SccX0(Double aCBus_SccX0)
  {
    this.aCBus_SccX0 = aCBus_SccX0;
  }
    
  public Double getACBus_SccA1Re()
  {
    return aCBus_SccA1Re;
  }
    
  public void setACBus_SccA1Re(Double aCBus_SccA1Re)
  {
    this.aCBus_SccA1Re = aCBus_SccA1Re;
  }
    
  public Double getACBus_SccA1Im()
  {
    return aCBus_SccA1Im;
  }
    
  public void setACBus_SccA1Im(Double aCBus_SccA1Im)
  {
    this.aCBus_SccA1Im = aCBus_SccA1Im;
  }
    
  public Double getACBus_SccA2Re()
  {
    return aCBus_SccA2Re;
  }
    
  public void setACBus_SccA2Re(Double aCBus_SccA2Re)
  {
    this.aCBus_SccA2Re = aCBus_SccA2Re;
  }
    
  public Double getACBus_SccA2Im()
  {
    return aCBus_SccA2Im;
  }
    
  public void setACBus_SccA2Im(Double aCBus_SccA2Im)
  {
    this.aCBus_SccA2Im = aCBus_SccA2Im;
  }
    
  public Double getACBus_SccA0Re()
  {
    return aCBus_SccA0Re;
  }
    
  public void setACBus_SccA0Re(Double aCBus_SccA0Re)
  {
    this.aCBus_SccA0Re = aCBus_SccA0Re;
  }
    
  public Double getACBus_SccA0Im()
  {
    return aCBus_SccA0Im;
  }
    
  public void setACBus_SccA0Im(Double aCBus_SccA0Im)
  {
    this.aCBus_SccA0Im = aCBus_SccA0Im;
  }
    
  public Double getACBus_SccV1Re()
  {
    return aCBus_SccV1Re;
  }
    
  public void setACBus_SccV1Re(Double aCBus_SccV1Re)
  {
    this.aCBus_SccV1Re = aCBus_SccV1Re;
  }
    
  public Double getACBus_SccV1Im()
  {
    return aCBus_SccV1Im;
  }
    
  public void setACBus_SccV1Im(Double aCBus_SccV1Im)
  {
    this.aCBus_SccV1Im = aCBus_SccV1Im;
  }
    
  public Double getACBus_SccV2Re()
  {
    return aCBus_SccV2Re;
  }
    
  public void setACBus_SccV2Re(Double aCBus_SccV2Re)
  {
    this.aCBus_SccV2Re = aCBus_SccV2Re;
  }
    
  public Double getACBus_SccV2Im()
  {
    return aCBus_SccV2Im;
  }
    
  public void setACBus_SccV2Im(Double aCBus_SccV2Im)
  {
    this.aCBus_SccV2Im = aCBus_SccV2Im;
  }
    
  public Double getACBus_SccV0Re()
  {
    return aCBus_SccV0Re;
  }
    
  public void setACBus_SccV0Re(Double aCBus_SccV0Re)
  {
    this.aCBus_SccV0Re = aCBus_SccV0Re;
  }
    
  public Double getACBus_SccV0Im()
  {
    return aCBus_SccV0Im;
  }
    
  public void setACBus_SccV0Im(Double aCBus_SccV0Im)
  {
    this.aCBus_SccV0Im = aCBus_SccV0Im;
  }
    
  public Integer getACBus_VDipBus1()
  {
    return aCBus_VDipBus1;
  }
    
  public void setACBus_VDipBus1(Integer aCBus_VDipBus1)
  {
    this.aCBus_VDipBus1 = aCBus_VDipBus1;
  }
    
  public Integer getACBus_VDipBus2()
  {
    return aCBus_VDipBus2;
  }
    
  public void setACBus_VDipBus2(Integer aCBus_VDipBus2)
  {
    this.aCBus_VDipBus2 = aCBus_VDipBus2;
  }
    
  public Integer getACBus_VDipBus3()
  {
    return aCBus_VDipBus3;
  }
    
  public void setACBus_VDipBus3(Integer aCBus_VDipBus3)
  {
    this.aCBus_VDipBus3 = aCBus_VDipBus3;
  }
    
  public Integer getACBus_VDipBus4()
  {
    return aCBus_VDipBus4;
  }
    
  public void setACBus_VDipBus4(Integer aCBus_VDipBus4)
  {
    this.aCBus_VDipBus4 = aCBus_VDipBus4;
  }
    
  public Double getACBus_IniPLoad()
  {
    return aCBus_IniPLoad;
  }
    
  public void setACBus_IniPLoad(Double aCBus_IniPLoad)
  {
    this.aCBus_IniPLoad = aCBus_IniPLoad;
  }
    
  public Double getACBus_IniQLoad()
  {
    return aCBus_IniQLoad;
  }
    
  public void setACBus_IniQLoad(Double aCBus_IniQLoad)
  {
    this.aCBus_IniQLoad = aCBus_IniQLoad;
  }
    
  public Double getACBus_IniPShunt()
  {
    return aCBus_IniPShunt;
  }
    
  public void setACBus_IniPShunt(Double aCBus_IniPShunt)
  {
    this.aCBus_IniPShunt = aCBus_IniPShunt;
  }
    
  public Double getACBus_IniQShunt()
  {
    return aCBus_IniQShunt;
  }
    
  public void setACBus_IniQShunt(Double aCBus_IniQShunt)
  {
    this.aCBus_IniQShunt = aCBus_IniQShunt;
  }
    
  public Double getACBus_IniPGen()
  {
    return aCBus_IniPGen;
  }
    
  public void setACBus_IniPGen(Double aCBus_IniPGen)
  {
    this.aCBus_IniPGen = aCBus_IniPGen;
  }
    
  public Double getACBus_IniQGen()
  {
    return aCBus_IniQGen;
  }
    
  public void setACBus_IniQGen(Double aCBus_IniQGen)
  {
    this.aCBus_IniQGen = aCBus_IniQGen;
  }
    
  public Integer getTMid()
  {
    return tMid;
  }
    
  public void setTMid(Integer tMid)
  {
    this.tMid = tMid;
  }
    
  public Integer getGenerator()
  {
    return generator;
  }
    
  public void setGenerator(Integer generator)
  {
    this.generator = generator;
  }
    
  public Integer getWTGen()
  {
    return wTGen;
  }
    
  public void setWTGen(Integer wTGen)
  {
    this.wTGen = wTGen;
  }
    
  public Integer getPVGen()
  {
    return pVGen;
  }
    
  public void setPVGen(Integer pVGen)
  {
    this.pVGen = pVGen;
  }
    
  public Integer getDCBound()
  {
    return dCBound;
  }
    
  public void setDCBound(Integer dCBound)
  {
    this.dCBound = dCBound;
  }
    
  public Integer getGenLn()
  {
    return genLn;
  }
    
  public void setGenLn(Integer genLn)
  {
    this.genLn = genLn;
  }
    
  public Integer getStatus()
  {
    return status;
  }
    
  public void setStatus(Integer status)
  {
    this.status = status;
  }
    
  public Integer getRedcution()
  {
    return redcution;
  }
    
  public void setRedcution(Integer redcution)
  {
    this.redcution = redcution;
  }
    
  public Integer getInRing()
  {
    return inRing;
  }
    
  public void setInRing(Integer inRing)
  {
    this.inRing = inRing;
  }
    
  public Integer getRadiate()
  {
    return radiate;
  }
    
  public void setRadiate(Integer radiate)
  {
    this.radiate = radiate;
  }
    
  public Integer getACIsland()
  {
    return aCIsland;
  }
    
  public void setACIsland(Integer aCIsland)
  {
    this.aCIsland = aCIsland;
  }
    
  public Integer getpRLine()
  {
    return pRLine;
  }
    
  public void setpRLine(Integer pRLine)
  {
    this.pRLine = pRLine;
  }
    
  public Integer getpRTran()
  {
    return pRTran;
  }
    
  public void setpRTran(Integer pRTran)
  {
    this.pRTran = pRTran;
  }
    
  public Integer getpRHG()
  {
    return pRHG;
  }
    
  public void setpRHG(Integer pRHG)
  {
    this.pRHG = pRHG;
  }
    
  public Integer getpRSub()
  {
    return pRSub;
  }
    
  public void setpRSub(Integer pRSub)
  {
    this.pRSub = pRSub;
  }
    
  public String toString()
  {
    return "BpaDat_ACBus ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", cardKey = " + cardKey
	 + ", aCBus_Owner = " + aCBus_Owner
	 + ", aCBus_Name = " + aCBus_Name
	 + ", aCBus_kV = " + aCBus_kV
	 + ", aCBus_Zone = " + aCBus_Zone
	 + ", aCBus_PLoad = " + aCBus_PLoad
	 + ", aCBus_QLoad = " + aCBus_QLoad
	 + ", aCBus_PShunt = " + aCBus_PShunt
	 + ", aCBus_QShunt = " + aCBus_QShunt
	 + ", aCBus_Pmax = " + aCBus_Pmax
	 + ", aCBus_PGen = " + aCBus_PGen
	 + ", aCBus_Qsched_Qmax = " + aCBus_Qsched_Qmax
	 + ", aCBus_Qmin = " + aCBus_Qmin
	 + ", aCBus_VHold_max = " + aCBus_VHold_max
	 + ", aCBus_Vmin = " + aCBus_Vmin
	 + ", aCBus_RBusName = " + aCBus_RBusName
	 + ", aCBus_RBusVolt = " + aCBus_RBusVolt
	 + ", aCBus_VarSppld = " + aCBus_VarSppld
	 + ", aCBus_AddCode = " + aCBus_AddCode
	 + ", aCBus_AddPLoad = " + aCBus_AddPLoad
	 + ", aCBus_AddQLoad = " + aCBus_AddQLoad
	 + ", aCBus_AddPShunt = " + aCBus_AddPShunt
	 + ", aCBus_AddQShunt = " + aCBus_AddQShunt
	 + ", aCBus_AddPGen = " + aCBus_AddPGen
	 + ", aCBus_AddQGen = " + aCBus_AddQGen
	 + ", aCBus_BpaSub = " + aCBus_BpaSub
	 + ", aCBus_Alias = " + aCBus_Alias
	 + ", aCBus_V = " + aCBus_V
	 + ", aCBus_D = " + aCBus_D
	 + ", aCBus_PfoPGen = " + aCBus_PfoPGen
	 + ", aCBus_PfoQGen = " + aCBus_PfoQGen
	 + ", aCBus_PfoPLoad = " + aCBus_PfoPLoad
	 + ", aCBus_PfoQLoad = " + aCBus_PfoQLoad
	 + ", aCBus_PfoQShunt = " + aCBus_PfoQShunt
	 + ", aCBus_PfoPNet = " + aCBus_PfoPNet
	 + ", aCBus_PfoQNet = " + aCBus_PfoQNet
	 + ", vd_Rerr = " + vd_Rerr
	 + ", vd_RScc1 = " + vd_RScc1
	 + ", vd_RScc2 = " + vd_RScc2
	 + ", vd_RScc3 = " + vd_RScc3
	 + ", vd_RScc4 = " + vd_RScc4
	 + ", aCBus_RtGenP = " + aCBus_RtGenP
	 + ", aCBus_RtGenQ = " + aCBus_RtGenQ
	 + ", aCBus_RtLoadP = " + aCBus_RtLoadP
	 + ", aCBus_RtLoadQ = " + aCBus_RtLoadQ
	 + ", aCBus_RtShuntQ = " + aCBus_RtShuntQ
	 + ", aCBus_RtVHold = " + aCBus_RtVHold
	 + ", aCBus_SccA = " + aCBus_SccA
	 + ", aCBus_SccV = " + aCBus_SccV
	 + ", aCBus_SccR1 = " + aCBus_SccR1
	 + ", aCBus_SccX1 = " + aCBus_SccX1
	 + ", aCBus_SccR2 = " + aCBus_SccR2
	 + ", aCBus_SccX2 = " + aCBus_SccX2
	 + ", aCBus_SccR0 = " + aCBus_SccR0
	 + ", aCBus_SccX0 = " + aCBus_SccX0
	 + ", aCBus_SccA1Re = " + aCBus_SccA1Re
	 + ", aCBus_SccA1Im = " + aCBus_SccA1Im
	 + ", aCBus_SccA2Re = " + aCBus_SccA2Re
	 + ", aCBus_SccA2Im = " + aCBus_SccA2Im
	 + ", aCBus_SccA0Re = " + aCBus_SccA0Re
	 + ", aCBus_SccA0Im = " + aCBus_SccA0Im
	 + ", aCBus_SccV1Re = " + aCBus_SccV1Re
	 + ", aCBus_SccV1Im = " + aCBus_SccV1Im
	 + ", aCBus_SccV2Re = " + aCBus_SccV2Re
	 + ", aCBus_SccV2Im = " + aCBus_SccV2Im
	 + ", aCBus_SccV0Re = " + aCBus_SccV0Re
	 + ", aCBus_SccV0Im = " + aCBus_SccV0Im
	 + ", aCBus_VDipBus1 = " + aCBus_VDipBus1
	 + ", aCBus_VDipBus2 = " + aCBus_VDipBus2
	 + ", aCBus_VDipBus3 = " + aCBus_VDipBus3
	 + ", aCBus_VDipBus4 = " + aCBus_VDipBus4
	 + ", aCBus_IniPLoad = " + aCBus_IniPLoad
	 + ", aCBus_IniQLoad = " + aCBus_IniQLoad
	 + ", aCBus_IniPShunt = " + aCBus_IniPShunt
	 + ", aCBus_IniQShunt = " + aCBus_IniQShunt
	 + ", aCBus_IniPGen = " + aCBus_IniPGen
	 + ", aCBus_IniQGen = " + aCBus_IniQGen
	 + ", tMid = " + tMid
	 + ", generator = " + generator
	 + ", wTGen = " + wTGen
	 + ", pVGen = " + pVGen
	 + ", dCBound = " + dCBound
	 + ", genLn = " + genLn
	 + ", status = " + status
	 + ", redcution = " + redcution
	 + ", inRing = " + inRing
	 + ", radiate = " + radiate
	 + ", aCIsland = " + aCIsland
	 + ", pRLine = " + pRLine
	 + ", pRTran = " + pRTran
	 + ", pRHG = " + pRHG
	 + ", pRSub = " + pRSub+"]";
  }
    
}
    
