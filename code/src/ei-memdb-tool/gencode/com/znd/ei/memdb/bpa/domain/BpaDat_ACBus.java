package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*节点表(ACBus)	*
***********************/
public class BpaDat_ACBus  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //所有者
  private String ACBus_Owner;
  
  //母线名称
  private String ACBus_Name;
  
  //基准电压(kV)
  private Double ACBus_kV;
  
  //分区名
  private String ACBus_Zone;
  
  //恒定有功负荷(MW)
  private Double ACBus_PLoad;
  
  //恒定无功负荷(MVAR),+感性
  private Double ACBus_QLoad;
  
  //并联导纳有功负荷(MW)
  private Double ACBus_PShunt;
  
  //并联导纳无功负荷(MVAR),+容性
  private Double ACBus_QShunt;
  
  //最大有功出力(MW)
  private Double ACBus_Pmax;
  
  //实际有功出力(MW)
  private Double ACBus_PGen;
  
  //安排的无功出力值,+容性
  private Double ACBus_Qsched_Qmax;
  
  //无功出力最小值(MVAR),此处填0
  private Double ACBus_Qmin;
  
  //安排的Vmax(pu)
  private Double ACBus_VHold_max;
  
  //安排的Vmin(pu)
  private Double ACBus_Vmin;
  
  //远方要控制的母线名称
  private String ACBus_RBusName;
  
  //远方要控制的基准电压(kV)
  private Double ACBus_RBusVolt;
  
  //提供的无功功率百分数(%)
  private Double ACBus_VarSppld;
  
  //延续节点负荷模型类型子代码
  private String ACBus_AddCode;
  
  //延续节点恒定有功负荷(MW)
  private Double ACBus_AddPLoad;
  
  //延续节点恒定无功负荷(MVAR),+感性
  private Double ACBus_AddQLoad;
  
  //延续节点并联导纳有功负荷(MW)
  private Double ACBus_AddPShunt;
  
  //延续节点并联导纳无功负荷(MVAR),+容性
  private Double ACBus_AddQShunt;
  
  //延续节点有功出力(MW)
  private Double ACBus_AddPGen;
  
  //延续节点无功出力(MVAR),+感性
  private Double ACBus_AddQGen;
  
  //母线所属BPA厂站
  private String ACBus_BpaSub;
  
  //交流母线别名
  private String ACBus_Alias;
  
  //母线电压
  private Double ACBus_V;
  
  //母线功角
  private Double ACBus_D;
  
  //母线计算发电有功
  private Double ACBus_PfoPGen;
  
  //母线计算发电无功
  private Double ACBus_PfoQGen;
  
  //母线计算负荷有功
  private Double ACBus_PfoPLoad;
  
  //母线计算负荷无功
  private Double ACBus_PfoQLoad;
  
  //母线计算补偿无功
  private Double ACBus_PfoQShunt;
  
  //母线计算注入有功
  private Double ACBus_PfoPNet;
  
  //母线计算注入无功
  private Double ACBus_PfoQNet;
  
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
  private Double ACBus_RtGenP;
  
  //RT安排的无功出力值
  private Double ACBus_RtGenQ;
  
  //RT恒定有功负荷(MW)
  private Double ACBus_RtLoadP;
  
  //RT恒定无功负荷(MVAR)
  private Double ACBus_RtLoadQ;
  
  //RT并联导纳无功负荷(MVAR)
  private Double ACBus_RtShuntQ;
  
  //RT安排的V(pu)
  private Double ACBus_RtVHold;
  
  //母线故障电流(A)
  private Double ACBus_SccA;
  
  //母线故障电压(kV)
  private Double ACBus_SccV;
  
  //母线正序等值阻抗(R1,pu)
  private Double ACBus_SccR1;
  
  //母线正序等值阻抗(X1,pu)
  private Double ACBus_SccX1;
  
  //母线负序等值阻抗(R2,pu)
  private Double ACBus_SccR2;
  
  //母线负序等值阻抗(X2,pu)
  private Double ACBus_SccX2;
  
  //母线零序等值阻抗(R0,pu)
  private Double ACBus_SccR0;
  
  //母线零序等值阻抗(X0,pu)
  private Double ACBus_SccX0;
  
  //正序故障电流实部(pu)
  private Double ACBus_SccA1Re;
  
  //正序故障电流虚部(pu)
  private Double ACBus_SccA1Im;
  
  //负序故障电流实部(pu)
  private Double ACBus_SccA2Re;
  
  //负序故障电流虚部(pu)
  private Double ACBus_SccA2Im;
  
  //零序故障电流实部(pu)
  private Double ACBus_SccA0Re;
  
  //零序故障电流虚部(pu)
  private Double ACBus_SccA0Im;
  
  //正序故障电压实部(pu)
  private Double ACBus_SccV1Re;
  
  //正序故障电压虚部(pu)
  private Double ACBus_SccV1Im;
  
  //负序故障电压实部(pu)
  private Double ACBus_SccV2Re;
  
  //负序故障电压虚部(pu)
  private Double ACBus_SccV2Im;
  
  //零序故障电压实部(pu)
  private Double ACBus_SccV0Re;
  
  //零序故障电压虚部(pu)
  private Double ACBus_SccV0Im;
  
  //母线单相接地暂降母线数
  private Integer ACBus_VDipBus1;
  
  //母线相间短路暂降母线数
  private Integer ACBus_VDipBus2;
  
  //母线三相短路暂降母线数
  private Integer ACBus_VDipBus3;
  
  //母线两相接地暂降母线数
  private Integer ACBus_VDipBus4;
  
  //Ini恒定有功负荷(MW)
  private Double ACBus_IniPLoad;
  
  //Ini恒定无功负荷(MVAR),+感性
  private Double ACBus_IniQLoad;
  
  //Ini并联导纳有功负荷(MW)
  private Double ACBus_IniPShunt;
  
  //Ini并联导纳无功负荷(MVAR),+容性
  private Double ACBus_IniQShunt;
  
  //Ini有功出力(MW)
  private Double ACBus_IniPGen;
  
  //Ini无功出力值,+容性
  private Double ACBus_IniQGen;
  
  //变压器中性点标记
  private Integer TMid;
  
  //发电机母线标记
  private Integer Generator;
  
  //并网风电机组机标记
  private Integer WTGen;
  
  //并网光伏机组机标记
  private Integer PVGen;
  
  //交直流边界母线
  private Integer DCBound;
  
  //等值发电机母线标记
  private Integer GenLn;
  
  //母线状态
  private Integer Status;
  
  //化简等值母线
  private Integer Redcution;
  
  //环网设备
  private Integer InRing;
  
  //所在辐射网
  private Integer Radiate;
  
  //交流岛
  private Integer ACIsland;
  
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
    return CardKey;
  }
    
  public void setCardKey(String CardKey)
  {
    this.CardKey = CardKey;
  }
    
  public String getACBus_Owner()
  {
    return ACBus_Owner;
  }
    
  public void setACBus_Owner(String ACBus_Owner)
  {
    this.ACBus_Owner = ACBus_Owner;
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
    
  public String getACBus_Zone()
  {
    return ACBus_Zone;
  }
    
  public void setACBus_Zone(String ACBus_Zone)
  {
    this.ACBus_Zone = ACBus_Zone;
  }
    
  public Double getACBus_PLoad()
  {
    return ACBus_PLoad;
  }
    
  public void setACBus_PLoad(Double ACBus_PLoad)
  {
    this.ACBus_PLoad = ACBus_PLoad;
  }
    
  public Double getACBus_QLoad()
  {
    return ACBus_QLoad;
  }
    
  public void setACBus_QLoad(Double ACBus_QLoad)
  {
    this.ACBus_QLoad = ACBus_QLoad;
  }
    
  public Double getACBus_PShunt()
  {
    return ACBus_PShunt;
  }
    
  public void setACBus_PShunt(Double ACBus_PShunt)
  {
    this.ACBus_PShunt = ACBus_PShunt;
  }
    
  public Double getACBus_QShunt()
  {
    return ACBus_QShunt;
  }
    
  public void setACBus_QShunt(Double ACBus_QShunt)
  {
    this.ACBus_QShunt = ACBus_QShunt;
  }
    
  public Double getACBus_Pmax()
  {
    return ACBus_Pmax;
  }
    
  public void setACBus_Pmax(Double ACBus_Pmax)
  {
    this.ACBus_Pmax = ACBus_Pmax;
  }
    
  public Double getACBus_PGen()
  {
    return ACBus_PGen;
  }
    
  public void setACBus_PGen(Double ACBus_PGen)
  {
    this.ACBus_PGen = ACBus_PGen;
  }
    
  public Double getACBus_Qsched_Qmax()
  {
    return ACBus_Qsched_Qmax;
  }
    
  public void setACBus_Qsched_Qmax(Double ACBus_Qsched_Qmax)
  {
    this.ACBus_Qsched_Qmax = ACBus_Qsched_Qmax;
  }
    
  public Double getACBus_Qmin()
  {
    return ACBus_Qmin;
  }
    
  public void setACBus_Qmin(Double ACBus_Qmin)
  {
    this.ACBus_Qmin = ACBus_Qmin;
  }
    
  public Double getACBus_VHold_max()
  {
    return ACBus_VHold_max;
  }
    
  public void setACBus_VHold_max(Double ACBus_VHold_max)
  {
    this.ACBus_VHold_max = ACBus_VHold_max;
  }
    
  public Double getACBus_Vmin()
  {
    return ACBus_Vmin;
  }
    
  public void setACBus_Vmin(Double ACBus_Vmin)
  {
    this.ACBus_Vmin = ACBus_Vmin;
  }
    
  public String getACBus_RBusName()
  {
    return ACBus_RBusName;
  }
    
  public void setACBus_RBusName(String ACBus_RBusName)
  {
    this.ACBus_RBusName = ACBus_RBusName;
  }
    
  public Double getACBus_RBusVolt()
  {
    return ACBus_RBusVolt;
  }
    
  public void setACBus_RBusVolt(Double ACBus_RBusVolt)
  {
    this.ACBus_RBusVolt = ACBus_RBusVolt;
  }
    
  public Double getACBus_VarSppld()
  {
    return ACBus_VarSppld;
  }
    
  public void setACBus_VarSppld(Double ACBus_VarSppld)
  {
    this.ACBus_VarSppld = ACBus_VarSppld;
  }
    
  public String getACBus_AddCode()
  {
    return ACBus_AddCode;
  }
    
  public void setACBus_AddCode(String ACBus_AddCode)
  {
    this.ACBus_AddCode = ACBus_AddCode;
  }
    
  public Double getACBus_AddPLoad()
  {
    return ACBus_AddPLoad;
  }
    
  public void setACBus_AddPLoad(Double ACBus_AddPLoad)
  {
    this.ACBus_AddPLoad = ACBus_AddPLoad;
  }
    
  public Double getACBus_AddQLoad()
  {
    return ACBus_AddQLoad;
  }
    
  public void setACBus_AddQLoad(Double ACBus_AddQLoad)
  {
    this.ACBus_AddQLoad = ACBus_AddQLoad;
  }
    
  public Double getACBus_AddPShunt()
  {
    return ACBus_AddPShunt;
  }
    
  public void setACBus_AddPShunt(Double ACBus_AddPShunt)
  {
    this.ACBus_AddPShunt = ACBus_AddPShunt;
  }
    
  public Double getACBus_AddQShunt()
  {
    return ACBus_AddQShunt;
  }
    
  public void setACBus_AddQShunt(Double ACBus_AddQShunt)
  {
    this.ACBus_AddQShunt = ACBus_AddQShunt;
  }
    
  public Double getACBus_AddPGen()
  {
    return ACBus_AddPGen;
  }
    
  public void setACBus_AddPGen(Double ACBus_AddPGen)
  {
    this.ACBus_AddPGen = ACBus_AddPGen;
  }
    
  public Double getACBus_AddQGen()
  {
    return ACBus_AddQGen;
  }
    
  public void setACBus_AddQGen(Double ACBus_AddQGen)
  {
    this.ACBus_AddQGen = ACBus_AddQGen;
  }
    
  public String getACBus_BpaSub()
  {
    return ACBus_BpaSub;
  }
    
  public void setACBus_BpaSub(String ACBus_BpaSub)
  {
    this.ACBus_BpaSub = ACBus_BpaSub;
  }
    
  public String getACBus_Alias()
  {
    return ACBus_Alias;
  }
    
  public void setACBus_Alias(String ACBus_Alias)
  {
    this.ACBus_Alias = ACBus_Alias;
  }
    
  public Double getACBus_V()
  {
    return ACBus_V;
  }
    
  public void setACBus_V(Double ACBus_V)
  {
    this.ACBus_V = ACBus_V;
  }
    
  public Double getACBus_D()
  {
    return ACBus_D;
  }
    
  public void setACBus_D(Double ACBus_D)
  {
    this.ACBus_D = ACBus_D;
  }
    
  public Double getACBus_PfoPGen()
  {
    return ACBus_PfoPGen;
  }
    
  public void setACBus_PfoPGen(Double ACBus_PfoPGen)
  {
    this.ACBus_PfoPGen = ACBus_PfoPGen;
  }
    
  public Double getACBus_PfoQGen()
  {
    return ACBus_PfoQGen;
  }
    
  public void setACBus_PfoQGen(Double ACBus_PfoQGen)
  {
    this.ACBus_PfoQGen = ACBus_PfoQGen;
  }
    
  public Double getACBus_PfoPLoad()
  {
    return ACBus_PfoPLoad;
  }
    
  public void setACBus_PfoPLoad(Double ACBus_PfoPLoad)
  {
    this.ACBus_PfoPLoad = ACBus_PfoPLoad;
  }
    
  public Double getACBus_PfoQLoad()
  {
    return ACBus_PfoQLoad;
  }
    
  public void setACBus_PfoQLoad(Double ACBus_PfoQLoad)
  {
    this.ACBus_PfoQLoad = ACBus_PfoQLoad;
  }
    
  public Double getACBus_PfoQShunt()
  {
    return ACBus_PfoQShunt;
  }
    
  public void setACBus_PfoQShunt(Double ACBus_PfoQShunt)
  {
    this.ACBus_PfoQShunt = ACBus_PfoQShunt;
  }
    
  public Double getACBus_PfoPNet()
  {
    return ACBus_PfoPNet;
  }
    
  public void setACBus_PfoPNet(Double ACBus_PfoPNet)
  {
    this.ACBus_PfoPNet = ACBus_PfoPNet;
  }
    
  public Double getACBus_PfoQNet()
  {
    return ACBus_PfoQNet;
  }
    
  public void setACBus_PfoQNet(Double ACBus_PfoQNet)
  {
    this.ACBus_PfoQNet = ACBus_PfoQNet;
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
    return ACBus_RtGenP;
  }
    
  public void setACBus_RtGenP(Double ACBus_RtGenP)
  {
    this.ACBus_RtGenP = ACBus_RtGenP;
  }
    
  public Double getACBus_RtGenQ()
  {
    return ACBus_RtGenQ;
  }
    
  public void setACBus_RtGenQ(Double ACBus_RtGenQ)
  {
    this.ACBus_RtGenQ = ACBus_RtGenQ;
  }
    
  public Double getACBus_RtLoadP()
  {
    return ACBus_RtLoadP;
  }
    
  public void setACBus_RtLoadP(Double ACBus_RtLoadP)
  {
    this.ACBus_RtLoadP = ACBus_RtLoadP;
  }
    
  public Double getACBus_RtLoadQ()
  {
    return ACBus_RtLoadQ;
  }
    
  public void setACBus_RtLoadQ(Double ACBus_RtLoadQ)
  {
    this.ACBus_RtLoadQ = ACBus_RtLoadQ;
  }
    
  public Double getACBus_RtShuntQ()
  {
    return ACBus_RtShuntQ;
  }
    
  public void setACBus_RtShuntQ(Double ACBus_RtShuntQ)
  {
    this.ACBus_RtShuntQ = ACBus_RtShuntQ;
  }
    
  public Double getACBus_RtVHold()
  {
    return ACBus_RtVHold;
  }
    
  public void setACBus_RtVHold(Double ACBus_RtVHold)
  {
    this.ACBus_RtVHold = ACBus_RtVHold;
  }
    
  public Double getACBus_SccA()
  {
    return ACBus_SccA;
  }
    
  public void setACBus_SccA(Double ACBus_SccA)
  {
    this.ACBus_SccA = ACBus_SccA;
  }
    
  public Double getACBus_SccV()
  {
    return ACBus_SccV;
  }
    
  public void setACBus_SccV(Double ACBus_SccV)
  {
    this.ACBus_SccV = ACBus_SccV;
  }
    
  public Double getACBus_SccR1()
  {
    return ACBus_SccR1;
  }
    
  public void setACBus_SccR1(Double ACBus_SccR1)
  {
    this.ACBus_SccR1 = ACBus_SccR1;
  }
    
  public Double getACBus_SccX1()
  {
    return ACBus_SccX1;
  }
    
  public void setACBus_SccX1(Double ACBus_SccX1)
  {
    this.ACBus_SccX1 = ACBus_SccX1;
  }
    
  public Double getACBus_SccR2()
  {
    return ACBus_SccR2;
  }
    
  public void setACBus_SccR2(Double ACBus_SccR2)
  {
    this.ACBus_SccR2 = ACBus_SccR2;
  }
    
  public Double getACBus_SccX2()
  {
    return ACBus_SccX2;
  }
    
  public void setACBus_SccX2(Double ACBus_SccX2)
  {
    this.ACBus_SccX2 = ACBus_SccX2;
  }
    
  public Double getACBus_SccR0()
  {
    return ACBus_SccR0;
  }
    
  public void setACBus_SccR0(Double ACBus_SccR0)
  {
    this.ACBus_SccR0 = ACBus_SccR0;
  }
    
  public Double getACBus_SccX0()
  {
    return ACBus_SccX0;
  }
    
  public void setACBus_SccX0(Double ACBus_SccX0)
  {
    this.ACBus_SccX0 = ACBus_SccX0;
  }
    
  public Double getACBus_SccA1Re()
  {
    return ACBus_SccA1Re;
  }
    
  public void setACBus_SccA1Re(Double ACBus_SccA1Re)
  {
    this.ACBus_SccA1Re = ACBus_SccA1Re;
  }
    
  public Double getACBus_SccA1Im()
  {
    return ACBus_SccA1Im;
  }
    
  public void setACBus_SccA1Im(Double ACBus_SccA1Im)
  {
    this.ACBus_SccA1Im = ACBus_SccA1Im;
  }
    
  public Double getACBus_SccA2Re()
  {
    return ACBus_SccA2Re;
  }
    
  public void setACBus_SccA2Re(Double ACBus_SccA2Re)
  {
    this.ACBus_SccA2Re = ACBus_SccA2Re;
  }
    
  public Double getACBus_SccA2Im()
  {
    return ACBus_SccA2Im;
  }
    
  public void setACBus_SccA2Im(Double ACBus_SccA2Im)
  {
    this.ACBus_SccA2Im = ACBus_SccA2Im;
  }
    
  public Double getACBus_SccA0Re()
  {
    return ACBus_SccA0Re;
  }
    
  public void setACBus_SccA0Re(Double ACBus_SccA0Re)
  {
    this.ACBus_SccA0Re = ACBus_SccA0Re;
  }
    
  public Double getACBus_SccA0Im()
  {
    return ACBus_SccA0Im;
  }
    
  public void setACBus_SccA0Im(Double ACBus_SccA0Im)
  {
    this.ACBus_SccA0Im = ACBus_SccA0Im;
  }
    
  public Double getACBus_SccV1Re()
  {
    return ACBus_SccV1Re;
  }
    
  public void setACBus_SccV1Re(Double ACBus_SccV1Re)
  {
    this.ACBus_SccV1Re = ACBus_SccV1Re;
  }
    
  public Double getACBus_SccV1Im()
  {
    return ACBus_SccV1Im;
  }
    
  public void setACBus_SccV1Im(Double ACBus_SccV1Im)
  {
    this.ACBus_SccV1Im = ACBus_SccV1Im;
  }
    
  public Double getACBus_SccV2Re()
  {
    return ACBus_SccV2Re;
  }
    
  public void setACBus_SccV2Re(Double ACBus_SccV2Re)
  {
    this.ACBus_SccV2Re = ACBus_SccV2Re;
  }
    
  public Double getACBus_SccV2Im()
  {
    return ACBus_SccV2Im;
  }
    
  public void setACBus_SccV2Im(Double ACBus_SccV2Im)
  {
    this.ACBus_SccV2Im = ACBus_SccV2Im;
  }
    
  public Double getACBus_SccV0Re()
  {
    return ACBus_SccV0Re;
  }
    
  public void setACBus_SccV0Re(Double ACBus_SccV0Re)
  {
    this.ACBus_SccV0Re = ACBus_SccV0Re;
  }
    
  public Double getACBus_SccV0Im()
  {
    return ACBus_SccV0Im;
  }
    
  public void setACBus_SccV0Im(Double ACBus_SccV0Im)
  {
    this.ACBus_SccV0Im = ACBus_SccV0Im;
  }
    
  public Integer getACBus_VDipBus1()
  {
    return ACBus_VDipBus1;
  }
    
  public void setACBus_VDipBus1(Integer ACBus_VDipBus1)
  {
    this.ACBus_VDipBus1 = ACBus_VDipBus1;
  }
    
  public Integer getACBus_VDipBus2()
  {
    return ACBus_VDipBus2;
  }
    
  public void setACBus_VDipBus2(Integer ACBus_VDipBus2)
  {
    this.ACBus_VDipBus2 = ACBus_VDipBus2;
  }
    
  public Integer getACBus_VDipBus3()
  {
    return ACBus_VDipBus3;
  }
    
  public void setACBus_VDipBus3(Integer ACBus_VDipBus3)
  {
    this.ACBus_VDipBus3 = ACBus_VDipBus3;
  }
    
  public Integer getACBus_VDipBus4()
  {
    return ACBus_VDipBus4;
  }
    
  public void setACBus_VDipBus4(Integer ACBus_VDipBus4)
  {
    this.ACBus_VDipBus4 = ACBus_VDipBus4;
  }
    
  public Double getACBus_IniPLoad()
  {
    return ACBus_IniPLoad;
  }
    
  public void setACBus_IniPLoad(Double ACBus_IniPLoad)
  {
    this.ACBus_IniPLoad = ACBus_IniPLoad;
  }
    
  public Double getACBus_IniQLoad()
  {
    return ACBus_IniQLoad;
  }
    
  public void setACBus_IniQLoad(Double ACBus_IniQLoad)
  {
    this.ACBus_IniQLoad = ACBus_IniQLoad;
  }
    
  public Double getACBus_IniPShunt()
  {
    return ACBus_IniPShunt;
  }
    
  public void setACBus_IniPShunt(Double ACBus_IniPShunt)
  {
    this.ACBus_IniPShunt = ACBus_IniPShunt;
  }
    
  public Double getACBus_IniQShunt()
  {
    return ACBus_IniQShunt;
  }
    
  public void setACBus_IniQShunt(Double ACBus_IniQShunt)
  {
    this.ACBus_IniQShunt = ACBus_IniQShunt;
  }
    
  public Double getACBus_IniPGen()
  {
    return ACBus_IniPGen;
  }
    
  public void setACBus_IniPGen(Double ACBus_IniPGen)
  {
    this.ACBus_IniPGen = ACBus_IniPGen;
  }
    
  public Double getACBus_IniQGen()
  {
    return ACBus_IniQGen;
  }
    
  public void setACBus_IniQGen(Double ACBus_IniQGen)
  {
    this.ACBus_IniQGen = ACBus_IniQGen;
  }
    
  public Integer getTMid()
  {
    return TMid;
  }
    
  public void setTMid(Integer TMid)
  {
    this.TMid = TMid;
  }
    
  public Integer getGenerator()
  {
    return Generator;
  }
    
  public void setGenerator(Integer Generator)
  {
    this.Generator = Generator;
  }
    
  public Integer getWTGen()
  {
    return WTGen;
  }
    
  public void setWTGen(Integer WTGen)
  {
    this.WTGen = WTGen;
  }
    
  public Integer getPVGen()
  {
    return PVGen;
  }
    
  public void setPVGen(Integer PVGen)
  {
    this.PVGen = PVGen;
  }
    
  public Integer getDCBound()
  {
    return DCBound;
  }
    
  public void setDCBound(Integer DCBound)
  {
    this.DCBound = DCBound;
  }
    
  public Integer getGenLn()
  {
    return GenLn;
  }
    
  public void setGenLn(Integer GenLn)
  {
    this.GenLn = GenLn;
  }
    
  public Integer getStatus()
  {
    return Status;
  }
    
  public void setStatus(Integer Status)
  {
    this.Status = Status;
  }
    
  public Integer getRedcution()
  {
    return Redcution;
  }
    
  public void setRedcution(Integer Redcution)
  {
    this.Redcution = Redcution;
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
    
  public Integer getACIsland()
  {
    return ACIsland;
  }
    
  public void setACIsland(Integer ACIsland)
  {
    this.ACIsland = ACIsland;
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
	 + ", CardKey = " + CardKey
	 + ", ACBus_Owner = " + ACBus_Owner
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", ACBus_Zone = " + ACBus_Zone
	 + ", ACBus_PLoad = " + ACBus_PLoad
	 + ", ACBus_QLoad = " + ACBus_QLoad
	 + ", ACBus_PShunt = " + ACBus_PShunt
	 + ", ACBus_QShunt = " + ACBus_QShunt
	 + ", ACBus_Pmax = " + ACBus_Pmax
	 + ", ACBus_PGen = " + ACBus_PGen
	 + ", ACBus_Qsched_Qmax = " + ACBus_Qsched_Qmax
	 + ", ACBus_Qmin = " + ACBus_Qmin
	 + ", ACBus_VHold_max = " + ACBus_VHold_max
	 + ", ACBus_Vmin = " + ACBus_Vmin
	 + ", ACBus_RBusName = " + ACBus_RBusName
	 + ", ACBus_RBusVolt = " + ACBus_RBusVolt
	 + ", ACBus_VarSppld = " + ACBus_VarSppld
	 + ", ACBus_AddCode = " + ACBus_AddCode
	 + ", ACBus_AddPLoad = " + ACBus_AddPLoad
	 + ", ACBus_AddQLoad = " + ACBus_AddQLoad
	 + ", ACBus_AddPShunt = " + ACBus_AddPShunt
	 + ", ACBus_AddQShunt = " + ACBus_AddQShunt
	 + ", ACBus_AddPGen = " + ACBus_AddPGen
	 + ", ACBus_AddQGen = " + ACBus_AddQGen
	 + ", ACBus_BpaSub = " + ACBus_BpaSub
	 + ", ACBus_Alias = " + ACBus_Alias
	 + ", ACBus_V = " + ACBus_V
	 + ", ACBus_D = " + ACBus_D
	 + ", ACBus_PfoPGen = " + ACBus_PfoPGen
	 + ", ACBus_PfoQGen = " + ACBus_PfoQGen
	 + ", ACBus_PfoPLoad = " + ACBus_PfoPLoad
	 + ", ACBus_PfoQLoad = " + ACBus_PfoQLoad
	 + ", ACBus_PfoQShunt = " + ACBus_PfoQShunt
	 + ", ACBus_PfoPNet = " + ACBus_PfoPNet
	 + ", ACBus_PfoQNet = " + ACBus_PfoQNet
	 + ", vd_Rerr = " + vd_Rerr
	 + ", vd_RScc1 = " + vd_RScc1
	 + ", vd_RScc2 = " + vd_RScc2
	 + ", vd_RScc3 = " + vd_RScc3
	 + ", vd_RScc4 = " + vd_RScc4
	 + ", ACBus_RtGenP = " + ACBus_RtGenP
	 + ", ACBus_RtGenQ = " + ACBus_RtGenQ
	 + ", ACBus_RtLoadP = " + ACBus_RtLoadP
	 + ", ACBus_RtLoadQ = " + ACBus_RtLoadQ
	 + ", ACBus_RtShuntQ = " + ACBus_RtShuntQ
	 + ", ACBus_RtVHold = " + ACBus_RtVHold
	 + ", ACBus_SccA = " + ACBus_SccA
	 + ", ACBus_SccV = " + ACBus_SccV
	 + ", ACBus_SccR1 = " + ACBus_SccR1
	 + ", ACBus_SccX1 = " + ACBus_SccX1
	 + ", ACBus_SccR2 = " + ACBus_SccR2
	 + ", ACBus_SccX2 = " + ACBus_SccX2
	 + ", ACBus_SccR0 = " + ACBus_SccR0
	 + ", ACBus_SccX0 = " + ACBus_SccX0
	 + ", ACBus_SccA1Re = " + ACBus_SccA1Re
	 + ", ACBus_SccA1Im = " + ACBus_SccA1Im
	 + ", ACBus_SccA2Re = " + ACBus_SccA2Re
	 + ", ACBus_SccA2Im = " + ACBus_SccA2Im
	 + ", ACBus_SccA0Re = " + ACBus_SccA0Re
	 + ", ACBus_SccA0Im = " + ACBus_SccA0Im
	 + ", ACBus_SccV1Re = " + ACBus_SccV1Re
	 + ", ACBus_SccV1Im = " + ACBus_SccV1Im
	 + ", ACBus_SccV2Re = " + ACBus_SccV2Re
	 + ", ACBus_SccV2Im = " + ACBus_SccV2Im
	 + ", ACBus_SccV0Re = " + ACBus_SccV0Re
	 + ", ACBus_SccV0Im = " + ACBus_SccV0Im
	 + ", ACBus_VDipBus1 = " + ACBus_VDipBus1
	 + ", ACBus_VDipBus2 = " + ACBus_VDipBus2
	 + ", ACBus_VDipBus3 = " + ACBus_VDipBus3
	 + ", ACBus_VDipBus4 = " + ACBus_VDipBus4
	 + ", ACBus_IniPLoad = " + ACBus_IniPLoad
	 + ", ACBus_IniQLoad = " + ACBus_IniQLoad
	 + ", ACBus_IniPShunt = " + ACBus_IniPShunt
	 + ", ACBus_IniQShunt = " + ACBus_IniQShunt
	 + ", ACBus_IniPGen = " + ACBus_IniPGen
	 + ", ACBus_IniQGen = " + ACBus_IniQGen
	 + ", TMid = " + TMid
	 + ", Generator = " + Generator
	 + ", WTGen = " + WTGen
	 + ", PVGen = " + PVGen
	 + ", DCBound = " + DCBound
	 + ", GenLn = " + GenLn
	 + ", Status = " + Status
	 + ", Redcution = " + Redcution
	 + ", InRing = " + InRing
	 + ", Radiate = " + Radiate
	 + ", ACIsland = " + ACIsland
	 + ", pRLine = " + pRLine
	 + ", pRTran = " + pRTran
	 + ", pRHG = " + pRHG
	 + ", pRSub = " + pRSub+"]";
  }
    
}
    
