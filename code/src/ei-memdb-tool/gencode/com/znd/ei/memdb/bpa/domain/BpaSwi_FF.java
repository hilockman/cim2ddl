package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*稳定计算控制卡(FF)	*
***********************/
public class BpaSwi_FF  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //计算开始时间(周)
  private Double T;
  
  //计算步长(周)
  private Double DT;
  
  //计算终止时间(周)
  private Double ENDT;
  
  //新的步长(周)
  private Double DTC;
  
  //开始改变步长的时刻(周)
  private Integer ISTP;
  
  //两次迭代间最大加速功率误差范围
  private Double TOLI;
  
  //一步内网络方程与微分方程最大交替迭代次数
  private Integer ILIM;
  
  //两次迭代间最大角度误差范围
  private Double DELANG;
  
  //交流积分步长与直流积分步长之比
  private Double DTDV;
  
  //发电机阻尼因子
  private Double DMPMLT;
  
  //系统基准频率
  private Double FRQBSE;
  
  //=1无低电压检查,否则进行检查
  private Integer LOVTEX;
  
  //马达滑差达到1时的处理方法
  private Integer IMBLOK;
  
  //摇摆方程与定子方程与频率的关系
  private Integer MFDEP;
  
  //非零时,所有调速器模型GS都采用外限幅
  private Integer IGSLIM;
  
  //=1：迭代不收敛,停止计算
  private Integer LSOLQIT;
  
  //=1：无最大角度限制,否则机组间角度超过500度停算
  private Integer NOANGLIM;
  
  //=1：所有发电机改为无穷大惯性电机
  private Integer INFBUS;
  
  //非零时,所有发电机都不考虑次暂态参数
  private Integer NOPP;
  
  //=1：所有发电机改为经典模型
  private Integer NODQ;
  
  //非零时,所有的发电机不考虑饱和
  private Integer NOSAT;
  
  //=1：所有发电机不计调速器
  private Integer NOGV;
  
  //非零时,所有发电机的磁链恒定
  private Integer IEQPC;
  
  //=1：所有发电机不计调压器
  private Integer NOEX;
  
  //非零时,所有的发电机卡MF卡都转换为MG卡
  private Integer MFTOMG;
  
  //=1：不计所有辅助信号
  private Integer NOSC;
  
  //非零时,所有的发电机卡MG卡都转换为MF卡
  private Integer MGTOMF;
  
  //=1：所有负荷为恒定阻抗
  private Integer NOLOAD;
  
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
    
  public Double getT()
  {
    return T;
  }
    
  public void setT(Double T)
  {
    this.T = T;
  }
    
  public Double getDT()
  {
    return DT;
  }
    
  public void setDT(Double DT)
  {
    this.DT = DT;
  }
    
  public Double getENDT()
  {
    return ENDT;
  }
    
  public void setENDT(Double ENDT)
  {
    this.ENDT = ENDT;
  }
    
  public Double getDTC()
  {
    return DTC;
  }
    
  public void setDTC(Double DTC)
  {
    this.DTC = DTC;
  }
    
  public Integer getISTP()
  {
    return ISTP;
  }
    
  public void setISTP(Integer ISTP)
  {
    this.ISTP = ISTP;
  }
    
  public Double getTOLI()
  {
    return TOLI;
  }
    
  public void setTOLI(Double TOLI)
  {
    this.TOLI = TOLI;
  }
    
  public Integer getILIM()
  {
    return ILIM;
  }
    
  public void setILIM(Integer ILIM)
  {
    this.ILIM = ILIM;
  }
    
  public Double getDELANG()
  {
    return DELANG;
  }
    
  public void setDELANG(Double DELANG)
  {
    this.DELANG = DELANG;
  }
    
  public Double getDTDV()
  {
    return DTDV;
  }
    
  public void setDTDV(Double DTDV)
  {
    this.DTDV = DTDV;
  }
    
  public Double getDMPMLT()
  {
    return DMPMLT;
  }
    
  public void setDMPMLT(Double DMPMLT)
  {
    this.DMPMLT = DMPMLT;
  }
    
  public Double getFRQBSE()
  {
    return FRQBSE;
  }
    
  public void setFRQBSE(Double FRQBSE)
  {
    this.FRQBSE = FRQBSE;
  }
    
  public Integer getLOVTEX()
  {
    return LOVTEX;
  }
    
  public void setLOVTEX(Integer LOVTEX)
  {
    this.LOVTEX = LOVTEX;
  }
    
  public Integer getIMBLOK()
  {
    return IMBLOK;
  }
    
  public void setIMBLOK(Integer IMBLOK)
  {
    this.IMBLOK = IMBLOK;
  }
    
  public Integer getMFDEP()
  {
    return MFDEP;
  }
    
  public void setMFDEP(Integer MFDEP)
  {
    this.MFDEP = MFDEP;
  }
    
  public Integer getIGSLIM()
  {
    return IGSLIM;
  }
    
  public void setIGSLIM(Integer IGSLIM)
  {
    this.IGSLIM = IGSLIM;
  }
    
  public Integer getLSOLQIT()
  {
    return LSOLQIT;
  }
    
  public void setLSOLQIT(Integer LSOLQIT)
  {
    this.LSOLQIT = LSOLQIT;
  }
    
  public Integer getNOANGLIM()
  {
    return NOANGLIM;
  }
    
  public void setNOANGLIM(Integer NOANGLIM)
  {
    this.NOANGLIM = NOANGLIM;
  }
    
  public Integer getINFBUS()
  {
    return INFBUS;
  }
    
  public void setINFBUS(Integer INFBUS)
  {
    this.INFBUS = INFBUS;
  }
    
  public Integer getNOPP()
  {
    return NOPP;
  }
    
  public void setNOPP(Integer NOPP)
  {
    this.NOPP = NOPP;
  }
    
  public Integer getNODQ()
  {
    return NODQ;
  }
    
  public void setNODQ(Integer NODQ)
  {
    this.NODQ = NODQ;
  }
    
  public Integer getNOSAT()
  {
    return NOSAT;
  }
    
  public void setNOSAT(Integer NOSAT)
  {
    this.NOSAT = NOSAT;
  }
    
  public Integer getNOGV()
  {
    return NOGV;
  }
    
  public void setNOGV(Integer NOGV)
  {
    this.NOGV = NOGV;
  }
    
  public Integer getIEQPC()
  {
    return IEQPC;
  }
    
  public void setIEQPC(Integer IEQPC)
  {
    this.IEQPC = IEQPC;
  }
    
  public Integer getNOEX()
  {
    return NOEX;
  }
    
  public void setNOEX(Integer NOEX)
  {
    this.NOEX = NOEX;
  }
    
  public Integer getMFTOMG()
  {
    return MFTOMG;
  }
    
  public void setMFTOMG(Integer MFTOMG)
  {
    this.MFTOMG = MFTOMG;
  }
    
  public Integer getNOSC()
  {
    return NOSC;
  }
    
  public void setNOSC(Integer NOSC)
  {
    this.NOSC = NOSC;
  }
    
  public Integer getMGTOMF()
  {
    return MGTOMF;
  }
    
  public void setMGTOMF(Integer MGTOMF)
  {
    this.MGTOMF = MGTOMF;
  }
    
  public Integer getNOLOAD()
  {
    return NOLOAD;
  }
    
  public void setNOLOAD(Integer NOLOAD)
  {
    this.NOLOAD = NOLOAD;
  }
    
  public String toString()
  {
    return "BpaSwi_FF ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", T = " + T
	 + ", DT = " + DT
	 + ", ENDT = " + ENDT
	 + ", DTC = " + DTC
	 + ", ISTP = " + ISTP
	 + ", TOLI = " + TOLI
	 + ", ILIM = " + ILIM
	 + ", DELANG = " + DELANG
	 + ", DTDV = " + DTDV
	 + ", DMPMLT = " + DMPMLT
	 + ", FRQBSE = " + FRQBSE
	 + ", LOVTEX = " + LOVTEX
	 + ", IMBLOK = " + IMBLOK
	 + ", MFDEP = " + MFDEP
	 + ", IGSLIM = " + IGSLIM
	 + ", LSOLQIT = " + LSOLQIT
	 + ", NOANGLIM = " + NOANGLIM
	 + ", INFBUS = " + INFBUS
	 + ", NOPP = " + NOPP
	 + ", NODQ = " + NODQ
	 + ", NOSAT = " + NOSAT
	 + ", NOGV = " + NOGV
	 + ", IEQPC = " + IEQPC
	 + ", NOEX = " + NOEX
	 + ", MFTOMG = " + MFTOMG
	 + ", NOSC = " + NOSC
	 + ", MGTOMF = " + MGTOMF
	 + ", NOLOAD = " + NOLOAD+"]";
  }
    
}
    
