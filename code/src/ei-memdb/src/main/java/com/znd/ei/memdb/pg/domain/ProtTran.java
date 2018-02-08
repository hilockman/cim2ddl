package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*变压器保护	*
***********************/
public class ProtTran  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //变压器名称
  private String Name;
  
  //厂站
  private String Sub;
  
  //高压卷电压等级
  private String VoltH;
  
  //中压卷电压等级
  private String VoltM;
  
  //低压卷电压等级
  private String VoltL;
  
  //三卷变标记
  private Integer ThreeWind;
  
  //高压卷拓扑母线
  private Integer TopoBusH;
  
  //中压卷拓扑母线
  private Integer TopoBusM;
  
  //低压卷拓扑母线
  private Integer TopoBusL;
  
  //高压卷额定电压(kV)
  private Double RateVoltH;
  
  //中压卷额定电压(kV)
  private Double RateVoltM;
  
  //低压卷额定电压(kV)
  private Double RateVoltL;
  
  //高压卷额定电流(A)
  private Double RateH;
  
  //中压卷额定电流(A)
  private Double RateM;
  
  //低压卷额定电流(A)
  private Double RateL;
  
  //负荷变压器
  private Integer LoadTran;
  
  //高压侧电源标记
  private Integer PowerH;
  
  //中压侧电源标记
  private Integer PowerM;
  
  //低压侧电源标记
  private Integer PowerL;
  
  //高压侧零序标记
  private Integer ZGStatH;
  
  //中压侧零序标记
  private Integer ZGStatM;
  
  //低压侧零序标记
  private Integer ZGStatL;
  
  //高压侧变压器内部最大短路电流(A)
  private Double ItmaxH;
  
  //中压侧变压器内部最大短路电流(A)
  private Double ItmaxM;
  
  //低压侧变压器内部最大短路电流(A)
  private Double ItmaxL;
  
  //高压侧变压器内部最小短路电流(A)
  private Double ItminH;
  
  //中压侧变压器内部最小短路电流(A)
  private Double ItminM;
  
  //低压侧变压器内部最小短路电流(A)
  private Double ItminL;
  
  //高压侧变压器内部最大零序电流(A)
  private Double I0tmaxH;
  
  //中压侧变压器内部最大零序电流(A)
  private Double I0tmaxM;
  
  //低压侧变压器内部最大零序电流(A)
  private Double I0tmaxL;
  
  //高压侧变压器内部最小零序电流(A)
  private Double I0tminH;
  
  //中压侧变压器内部最小零序电流(A)
  private Double I0tminM;
  
  //低压侧变压器内部最小零序电流(A)
  private Double I0tminL;
  
  //高压侧对侧故障最大短路电流(A)
  private Double IobmaxH;
  
  //中压侧对侧故障最大短路电流(A)
  private Double IobmaxM;
  
  //低压侧对侧故障最大短路电流(A)
  private Double IobmaxL;
  
  //高压侧对侧故障最小短路电流(A)
  private Double IobminH;
  
  //中压侧对侧故障最小短路电流(A)
  private Double IobminM;
  
  //低压侧对侧故障最小短路电流(A)
  private Double IobminL;
  
  //高压侧母线故障最大短路电流(A)
  private Double IkmaxHNear;
  
  //中压侧母线故障最大短路电流(A)
  private Double IkmaxMNear;
  
  //低压侧母线故障最大短路电流(A)
  private Double IkmaxLNear;
  
  //高压侧母线故障最小短路电流(A)
  private Double IkminHNear;
  
  //中压侧母线故障最小短路电流(A)
  private Double IkminMNear;
  
  //低压侧母线故障最小短路电流(A)
  private Double IkminLNear;
  
  //高压侧母线故障最大零序电流(A)
  private Double I0kmaxHNear;
  
  //中压侧母线故障最大零序电流(A)
  private Double I0kmaxMNear;
  
  //低压侧母线故障最大零序电流(A)
  private Double I0kmaxLNear;
  
  //高压侧母线故障最小零序电流(A)
  private Double I0kminHNear;
  
  //中压侧母线故障最小零序电流(A)
  private Double I0kminMNear;
  
  //低压侧母线故障最小零序电流(A)
  private Double I0kminLNear;
  
  //高压侧一级相邻线路末故障最大短路电流(A)
  private Double IkmaxHFar;
  
  //中压侧一级相邻线路末故障最大短路电流(A)
  private Double IkmaxMFar;
  
  //低压侧一级相邻线路末故障最大短路电流(A)
  private Double IkmaxLFar;
  
  //高压侧一级相邻线路末故障最小短路电流(A)
  private Double IkminHFar;
  
  //中压侧一级相邻线路末故障最小短路电流(A)
  private Double IkminMFar;
  
  //低压侧一级相邻线路末故障最小短路电流(A)
  private Double IkminLFar;
  
  //高压侧一级相邻线路末故障最大零序电流(A)
  private Double I0kmaxHFar;
  
  //中压侧一级相邻线路末故障最大零序电流(A)
  private Double I0kmaxMFar;
  
  //低压侧一级相邻线路末故障最大零序电流(A)
  private Double I0kmaxLFar;
  
  //高压侧一级相邻线路末故障最小零序电流(A)
  private Double I0kminHFar;
  
  //中压侧一级相邻线路末故障最小零序电流(A)
  private Double I0kminMFar;
  
  //低压侧一级相邻线路末故障最小零序电流(A)
  private Double I0kminLFar;
  
  //高压侧不平衡电流(A)
  private Double IkunbH;
  
  //中压侧不平衡电流(A)
  private Double IkunbM;
  
  //低压侧不平衡电流(A)
  private Double IkunbL;
  
  //整定:电源侧过流Ⅰ段保护灵敏系数
  private Double Kkslm1;
  
  //整定:负荷侧过流Ⅰ段保护灵敏系数
  private Double Kkllm1;
  
  //整定:过流保护可靠系数
  private Double Kkrel3;
  
  //整定:过流保护返回系数
  private Double Kkres3;
  
  //整定:复压闭锁电压值
  private Double Kuop;
  
  //整定:复压闭锁可靠系数
  private Double Kuoprel;
  
  //整定:复压闭锁返回系数
  private Double Kuopres;
  
  //整定:零序Ⅰ段灵敏系数
  private Double K0lm1;
  
  //整定:零序Ⅱ段可靠系数
  private Double K0rel2;
  
  //高压侧负荷侧电流保护Ⅰ段整定电流(A)
  private Double Ikdz1H;
  
  //中压侧负荷侧电流保护Ⅰ段整定电流(A)
  private Double Ikdz1M;
  
  //低压侧负荷侧电流保护Ⅰ段整定电流(A)
  private Double Ikdz1L;
  
  //高压侧过流保护整定电流(A)
  private Double Ikdz3H;
  
  //中压侧过流保护整定电流(A)
  private Double Ikdz3M;
  
  //低压侧过流保护整定电流(A)
  private Double Ikdz3L;
  
  //高压侧复压闭锁整定电压(kV)
  private Double UopH;
  
  //中压侧复压闭锁整定电压(kV)
  private Double UopM;
  
  //低压侧复压闭锁整定电压(kV)
  private Double UopL;
  
  //高压侧零序Ⅰ段整定电流(A)
  private Double I0dz1H;
  
  //中压侧零序Ⅰ段整定电流(A)
  private Double I0dz1M;
  
  //低压侧零序Ⅰ段整定电流(A)
  private Double I0dz1L;
  
  //高压侧零序Ⅱ段整定电流(A)
  private Double I0dz2H;
  
  //中压侧零序Ⅱ段整定电流(A)
  private Double I0dz2M;
  
  //低压侧零序Ⅱ段整定电流(A)
  private Double I0dz2L;
  
  //校核:高压侧过流保护灵敏系数
  private Double Kksen3H;
  
  //校核:中压侧过流保护灵敏系数
  private Double Kksen3M;
  
  //校核:低压侧过流保护灵敏系数
  private Double Kksen3L;
  
  //变压器索引
  private Integer PowerTransformerPtr;
  
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
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public String getSub()
  {
    return Sub;
  }
    
  public void setSub(String Sub)
  {
    this.Sub = Sub;
  }
    
  public String getVoltH()
  {
    return VoltH;
  }
    
  public void setVoltH(String VoltH)
  {
    this.VoltH = VoltH;
  }
    
  public String getVoltM()
  {
    return VoltM;
  }
    
  public void setVoltM(String VoltM)
  {
    this.VoltM = VoltM;
  }
    
  public String getVoltL()
  {
    return VoltL;
  }
    
  public void setVoltL(String VoltL)
  {
    this.VoltL = VoltL;
  }
    
  public Integer getThreeWind()
  {
    return ThreeWind;
  }
    
  public void setThreeWind(Integer ThreeWind)
  {
    this.ThreeWind = ThreeWind;
  }
    
  public Integer getTopoBusH()
  {
    return TopoBusH;
  }
    
  public void setTopoBusH(Integer TopoBusH)
  {
    this.TopoBusH = TopoBusH;
  }
    
  public Integer getTopoBusM()
  {
    return TopoBusM;
  }
    
  public void setTopoBusM(Integer TopoBusM)
  {
    this.TopoBusM = TopoBusM;
  }
    
  public Integer getTopoBusL()
  {
    return TopoBusL;
  }
    
  public void setTopoBusL(Integer TopoBusL)
  {
    this.TopoBusL = TopoBusL;
  }
    
  public Double getRateVoltH()
  {
    return RateVoltH;
  }
    
  public void setRateVoltH(Double RateVoltH)
  {
    this.RateVoltH = RateVoltH;
  }
    
  public Double getRateVoltM()
  {
    return RateVoltM;
  }
    
  public void setRateVoltM(Double RateVoltM)
  {
    this.RateVoltM = RateVoltM;
  }
    
  public Double getRateVoltL()
  {
    return RateVoltL;
  }
    
  public void setRateVoltL(Double RateVoltL)
  {
    this.RateVoltL = RateVoltL;
  }
    
  public Double getRateH()
  {
    return RateH;
  }
    
  public void setRateH(Double RateH)
  {
    this.RateH = RateH;
  }
    
  public Double getRateM()
  {
    return RateM;
  }
    
  public void setRateM(Double RateM)
  {
    this.RateM = RateM;
  }
    
  public Double getRateL()
  {
    return RateL;
  }
    
  public void setRateL(Double RateL)
  {
    this.RateL = RateL;
  }
    
  public Integer getLoadTran()
  {
    return LoadTran;
  }
    
  public void setLoadTran(Integer LoadTran)
  {
    this.LoadTran = LoadTran;
  }
    
  public Integer getPowerH()
  {
    return PowerH;
  }
    
  public void setPowerH(Integer PowerH)
  {
    this.PowerH = PowerH;
  }
    
  public Integer getPowerM()
  {
    return PowerM;
  }
    
  public void setPowerM(Integer PowerM)
  {
    this.PowerM = PowerM;
  }
    
  public Integer getPowerL()
  {
    return PowerL;
  }
    
  public void setPowerL(Integer PowerL)
  {
    this.PowerL = PowerL;
  }
    
  public Integer getZGStatH()
  {
    return ZGStatH;
  }
    
  public void setZGStatH(Integer ZGStatH)
  {
    this.ZGStatH = ZGStatH;
  }
    
  public Integer getZGStatM()
  {
    return ZGStatM;
  }
    
  public void setZGStatM(Integer ZGStatM)
  {
    this.ZGStatM = ZGStatM;
  }
    
  public Integer getZGStatL()
  {
    return ZGStatL;
  }
    
  public void setZGStatL(Integer ZGStatL)
  {
    this.ZGStatL = ZGStatL;
  }
    
  public Double getItmaxH()
  {
    return ItmaxH;
  }
    
  public void setItmaxH(Double ItmaxH)
  {
    this.ItmaxH = ItmaxH;
  }
    
  public Double getItmaxM()
  {
    return ItmaxM;
  }
    
  public void setItmaxM(Double ItmaxM)
  {
    this.ItmaxM = ItmaxM;
  }
    
  public Double getItmaxL()
  {
    return ItmaxL;
  }
    
  public void setItmaxL(Double ItmaxL)
  {
    this.ItmaxL = ItmaxL;
  }
    
  public Double getItminH()
  {
    return ItminH;
  }
    
  public void setItminH(Double ItminH)
  {
    this.ItminH = ItminH;
  }
    
  public Double getItminM()
  {
    return ItminM;
  }
    
  public void setItminM(Double ItminM)
  {
    this.ItminM = ItminM;
  }
    
  public Double getItminL()
  {
    return ItminL;
  }
    
  public void setItminL(Double ItminL)
  {
    this.ItminL = ItminL;
  }
    
  public Double getI0tmaxH()
  {
    return I0tmaxH;
  }
    
  public void setI0tmaxH(Double I0tmaxH)
  {
    this.I0tmaxH = I0tmaxH;
  }
    
  public Double getI0tmaxM()
  {
    return I0tmaxM;
  }
    
  public void setI0tmaxM(Double I0tmaxM)
  {
    this.I0tmaxM = I0tmaxM;
  }
    
  public Double getI0tmaxL()
  {
    return I0tmaxL;
  }
    
  public void setI0tmaxL(Double I0tmaxL)
  {
    this.I0tmaxL = I0tmaxL;
  }
    
  public Double getI0tminH()
  {
    return I0tminH;
  }
    
  public void setI0tminH(Double I0tminH)
  {
    this.I0tminH = I0tminH;
  }
    
  public Double getI0tminM()
  {
    return I0tminM;
  }
    
  public void setI0tminM(Double I0tminM)
  {
    this.I0tminM = I0tminM;
  }
    
  public Double getI0tminL()
  {
    return I0tminL;
  }
    
  public void setI0tminL(Double I0tminL)
  {
    this.I0tminL = I0tminL;
  }
    
  public Double getIobmaxH()
  {
    return IobmaxH;
  }
    
  public void setIobmaxH(Double IobmaxH)
  {
    this.IobmaxH = IobmaxH;
  }
    
  public Double getIobmaxM()
  {
    return IobmaxM;
  }
    
  public void setIobmaxM(Double IobmaxM)
  {
    this.IobmaxM = IobmaxM;
  }
    
  public Double getIobmaxL()
  {
    return IobmaxL;
  }
    
  public void setIobmaxL(Double IobmaxL)
  {
    this.IobmaxL = IobmaxL;
  }
    
  public Double getIobminH()
  {
    return IobminH;
  }
    
  public void setIobminH(Double IobminH)
  {
    this.IobminH = IobminH;
  }
    
  public Double getIobminM()
  {
    return IobminM;
  }
    
  public void setIobminM(Double IobminM)
  {
    this.IobminM = IobminM;
  }
    
  public Double getIobminL()
  {
    return IobminL;
  }
    
  public void setIobminL(Double IobminL)
  {
    this.IobminL = IobminL;
  }
    
  public Double getIkmaxHNear()
  {
    return IkmaxHNear;
  }
    
  public void setIkmaxHNear(Double IkmaxHNear)
  {
    this.IkmaxHNear = IkmaxHNear;
  }
    
  public Double getIkmaxMNear()
  {
    return IkmaxMNear;
  }
    
  public void setIkmaxMNear(Double IkmaxMNear)
  {
    this.IkmaxMNear = IkmaxMNear;
  }
    
  public Double getIkmaxLNear()
  {
    return IkmaxLNear;
  }
    
  public void setIkmaxLNear(Double IkmaxLNear)
  {
    this.IkmaxLNear = IkmaxLNear;
  }
    
  public Double getIkminHNear()
  {
    return IkminHNear;
  }
    
  public void setIkminHNear(Double IkminHNear)
  {
    this.IkminHNear = IkminHNear;
  }
    
  public Double getIkminMNear()
  {
    return IkminMNear;
  }
    
  public void setIkminMNear(Double IkminMNear)
  {
    this.IkminMNear = IkminMNear;
  }
    
  public Double getIkminLNear()
  {
    return IkminLNear;
  }
    
  public void setIkminLNear(Double IkminLNear)
  {
    this.IkminLNear = IkminLNear;
  }
    
  public Double getI0kmaxHNear()
  {
    return I0kmaxHNear;
  }
    
  public void setI0kmaxHNear(Double I0kmaxHNear)
  {
    this.I0kmaxHNear = I0kmaxHNear;
  }
    
  public Double getI0kmaxMNear()
  {
    return I0kmaxMNear;
  }
    
  public void setI0kmaxMNear(Double I0kmaxMNear)
  {
    this.I0kmaxMNear = I0kmaxMNear;
  }
    
  public Double getI0kmaxLNear()
  {
    return I0kmaxLNear;
  }
    
  public void setI0kmaxLNear(Double I0kmaxLNear)
  {
    this.I0kmaxLNear = I0kmaxLNear;
  }
    
  public Double getI0kminHNear()
  {
    return I0kminHNear;
  }
    
  public void setI0kminHNear(Double I0kminHNear)
  {
    this.I0kminHNear = I0kminHNear;
  }
    
  public Double getI0kminMNear()
  {
    return I0kminMNear;
  }
    
  public void setI0kminMNear(Double I0kminMNear)
  {
    this.I0kminMNear = I0kminMNear;
  }
    
  public Double getI0kminLNear()
  {
    return I0kminLNear;
  }
    
  public void setI0kminLNear(Double I0kminLNear)
  {
    this.I0kminLNear = I0kminLNear;
  }
    
  public Double getIkmaxHFar()
  {
    return IkmaxHFar;
  }
    
  public void setIkmaxHFar(Double IkmaxHFar)
  {
    this.IkmaxHFar = IkmaxHFar;
  }
    
  public Double getIkmaxMFar()
  {
    return IkmaxMFar;
  }
    
  public void setIkmaxMFar(Double IkmaxMFar)
  {
    this.IkmaxMFar = IkmaxMFar;
  }
    
  public Double getIkmaxLFar()
  {
    return IkmaxLFar;
  }
    
  public void setIkmaxLFar(Double IkmaxLFar)
  {
    this.IkmaxLFar = IkmaxLFar;
  }
    
  public Double getIkminHFar()
  {
    return IkminHFar;
  }
    
  public void setIkminHFar(Double IkminHFar)
  {
    this.IkminHFar = IkminHFar;
  }
    
  public Double getIkminMFar()
  {
    return IkminMFar;
  }
    
  public void setIkminMFar(Double IkminMFar)
  {
    this.IkminMFar = IkminMFar;
  }
    
  public Double getIkminLFar()
  {
    return IkminLFar;
  }
    
  public void setIkminLFar(Double IkminLFar)
  {
    this.IkminLFar = IkminLFar;
  }
    
  public Double getI0kmaxHFar()
  {
    return I0kmaxHFar;
  }
    
  public void setI0kmaxHFar(Double I0kmaxHFar)
  {
    this.I0kmaxHFar = I0kmaxHFar;
  }
    
  public Double getI0kmaxMFar()
  {
    return I0kmaxMFar;
  }
    
  public void setI0kmaxMFar(Double I0kmaxMFar)
  {
    this.I0kmaxMFar = I0kmaxMFar;
  }
    
  public Double getI0kmaxLFar()
  {
    return I0kmaxLFar;
  }
    
  public void setI0kmaxLFar(Double I0kmaxLFar)
  {
    this.I0kmaxLFar = I0kmaxLFar;
  }
    
  public Double getI0kminHFar()
  {
    return I0kminHFar;
  }
    
  public void setI0kminHFar(Double I0kminHFar)
  {
    this.I0kminHFar = I0kminHFar;
  }
    
  public Double getI0kminMFar()
  {
    return I0kminMFar;
  }
    
  public void setI0kminMFar(Double I0kminMFar)
  {
    this.I0kminMFar = I0kminMFar;
  }
    
  public Double getI0kminLFar()
  {
    return I0kminLFar;
  }
    
  public void setI0kminLFar(Double I0kminLFar)
  {
    this.I0kminLFar = I0kminLFar;
  }
    
  public Double getIkunbH()
  {
    return IkunbH;
  }
    
  public void setIkunbH(Double IkunbH)
  {
    this.IkunbH = IkunbH;
  }
    
  public Double getIkunbM()
  {
    return IkunbM;
  }
    
  public void setIkunbM(Double IkunbM)
  {
    this.IkunbM = IkunbM;
  }
    
  public Double getIkunbL()
  {
    return IkunbL;
  }
    
  public void setIkunbL(Double IkunbL)
  {
    this.IkunbL = IkunbL;
  }
    
  public Double getKkslm1()
  {
    return Kkslm1;
  }
    
  public void setKkslm1(Double Kkslm1)
  {
    this.Kkslm1 = Kkslm1;
  }
    
  public Double getKkllm1()
  {
    return Kkllm1;
  }
    
  public void setKkllm1(Double Kkllm1)
  {
    this.Kkllm1 = Kkllm1;
  }
    
  public Double getKkrel3()
  {
    return Kkrel3;
  }
    
  public void setKkrel3(Double Kkrel3)
  {
    this.Kkrel3 = Kkrel3;
  }
    
  public Double getKkres3()
  {
    return Kkres3;
  }
    
  public void setKkres3(Double Kkres3)
  {
    this.Kkres3 = Kkres3;
  }
    
  public Double getKuop()
  {
    return Kuop;
  }
    
  public void setKuop(Double Kuop)
  {
    this.Kuop = Kuop;
  }
    
  public Double getKuoprel()
  {
    return Kuoprel;
  }
    
  public void setKuoprel(Double Kuoprel)
  {
    this.Kuoprel = Kuoprel;
  }
    
  public Double getKuopres()
  {
    return Kuopres;
  }
    
  public void setKuopres(Double Kuopres)
  {
    this.Kuopres = Kuopres;
  }
    
  public Double getK0lm1()
  {
    return K0lm1;
  }
    
  public void setK0lm1(Double K0lm1)
  {
    this.K0lm1 = K0lm1;
  }
    
  public Double getK0rel2()
  {
    return K0rel2;
  }
    
  public void setK0rel2(Double K0rel2)
  {
    this.K0rel2 = K0rel2;
  }
    
  public Double getIkdz1H()
  {
    return Ikdz1H;
  }
    
  public void setIkdz1H(Double Ikdz1H)
  {
    this.Ikdz1H = Ikdz1H;
  }
    
  public Double getIkdz1M()
  {
    return Ikdz1M;
  }
    
  public void setIkdz1M(Double Ikdz1M)
  {
    this.Ikdz1M = Ikdz1M;
  }
    
  public Double getIkdz1L()
  {
    return Ikdz1L;
  }
    
  public void setIkdz1L(Double Ikdz1L)
  {
    this.Ikdz1L = Ikdz1L;
  }
    
  public Double getIkdz3H()
  {
    return Ikdz3H;
  }
    
  public void setIkdz3H(Double Ikdz3H)
  {
    this.Ikdz3H = Ikdz3H;
  }
    
  public Double getIkdz3M()
  {
    return Ikdz3M;
  }
    
  public void setIkdz3M(Double Ikdz3M)
  {
    this.Ikdz3M = Ikdz3M;
  }
    
  public Double getIkdz3L()
  {
    return Ikdz3L;
  }
    
  public void setIkdz3L(Double Ikdz3L)
  {
    this.Ikdz3L = Ikdz3L;
  }
    
  public Double getUopH()
  {
    return UopH;
  }
    
  public void setUopH(Double UopH)
  {
    this.UopH = UopH;
  }
    
  public Double getUopM()
  {
    return UopM;
  }
    
  public void setUopM(Double UopM)
  {
    this.UopM = UopM;
  }
    
  public Double getUopL()
  {
    return UopL;
  }
    
  public void setUopL(Double UopL)
  {
    this.UopL = UopL;
  }
    
  public Double getI0dz1H()
  {
    return I0dz1H;
  }
    
  public void setI0dz1H(Double I0dz1H)
  {
    this.I0dz1H = I0dz1H;
  }
    
  public Double getI0dz1M()
  {
    return I0dz1M;
  }
    
  public void setI0dz1M(Double I0dz1M)
  {
    this.I0dz1M = I0dz1M;
  }
    
  public Double getI0dz1L()
  {
    return I0dz1L;
  }
    
  public void setI0dz1L(Double I0dz1L)
  {
    this.I0dz1L = I0dz1L;
  }
    
  public Double getI0dz2H()
  {
    return I0dz2H;
  }
    
  public void setI0dz2H(Double I0dz2H)
  {
    this.I0dz2H = I0dz2H;
  }
    
  public Double getI0dz2M()
  {
    return I0dz2M;
  }
    
  public void setI0dz2M(Double I0dz2M)
  {
    this.I0dz2M = I0dz2M;
  }
    
  public Double getI0dz2L()
  {
    return I0dz2L;
  }
    
  public void setI0dz2L(Double I0dz2L)
  {
    this.I0dz2L = I0dz2L;
  }
    
  public Double getKksen3H()
  {
    return Kksen3H;
  }
    
  public void setKksen3H(Double Kksen3H)
  {
    this.Kksen3H = Kksen3H;
  }
    
  public Double getKksen3M()
  {
    return Kksen3M;
  }
    
  public void setKksen3M(Double Kksen3M)
  {
    this.Kksen3M = Kksen3M;
  }
    
  public Double getKksen3L()
  {
    return Kksen3L;
  }
    
  public void setKksen3L(Double Kksen3L)
  {
    this.Kksen3L = Kksen3L;
  }
    
  public Integer getPowerTransformerPtr()
  {
    return PowerTransformerPtr;
  }
    
  public void setPowerTransformerPtr(Integer PowerTransformerPtr)
  {
    this.PowerTransformerPtr = PowerTransformerPtr;
  }
    
  public String toString()
  {
    return "ProtTran ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", Sub = " + Sub
	 + ", VoltH = " + VoltH
	 + ", VoltM = " + VoltM
	 + ", VoltL = " + VoltL
	 + ", ThreeWind = " + ThreeWind
	 + ", TopoBusH = " + TopoBusH
	 + ", TopoBusM = " + TopoBusM
	 + ", TopoBusL = " + TopoBusL
	 + ", RateVoltH = " + RateVoltH
	 + ", RateVoltM = " + RateVoltM
	 + ", RateVoltL = " + RateVoltL
	 + ", RateH = " + RateH
	 + ", RateM = " + RateM
	 + ", RateL = " + RateL
	 + ", LoadTran = " + LoadTran
	 + ", PowerH = " + PowerH
	 + ", PowerM = " + PowerM
	 + ", PowerL = " + PowerL
	 + ", ZGStatH = " + ZGStatH
	 + ", ZGStatM = " + ZGStatM
	 + ", ZGStatL = " + ZGStatL
	 + ", ItmaxH = " + ItmaxH
	 + ", ItmaxM = " + ItmaxM
	 + ", ItmaxL = " + ItmaxL
	 + ", ItminH = " + ItminH
	 + ", ItminM = " + ItminM
	 + ", ItminL = " + ItminL
	 + ", I0tmaxH = " + I0tmaxH
	 + ", I0tmaxM = " + I0tmaxM
	 + ", I0tmaxL = " + I0tmaxL
	 + ", I0tminH = " + I0tminH
	 + ", I0tminM = " + I0tminM
	 + ", I0tminL = " + I0tminL
	 + ", IobmaxH = " + IobmaxH
	 + ", IobmaxM = " + IobmaxM
	 + ", IobmaxL = " + IobmaxL
	 + ", IobminH = " + IobminH
	 + ", IobminM = " + IobminM
	 + ", IobminL = " + IobminL
	 + ", IkmaxHNear = " + IkmaxHNear
	 + ", IkmaxMNear = " + IkmaxMNear
	 + ", IkmaxLNear = " + IkmaxLNear
	 + ", IkminHNear = " + IkminHNear
	 + ", IkminMNear = " + IkminMNear
	 + ", IkminLNear = " + IkminLNear
	 + ", I0kmaxHNear = " + I0kmaxHNear
	 + ", I0kmaxMNear = " + I0kmaxMNear
	 + ", I0kmaxLNear = " + I0kmaxLNear
	 + ", I0kminHNear = " + I0kminHNear
	 + ", I0kminMNear = " + I0kminMNear
	 + ", I0kminLNear = " + I0kminLNear
	 + ", IkmaxHFar = " + IkmaxHFar
	 + ", IkmaxMFar = " + IkmaxMFar
	 + ", IkmaxLFar = " + IkmaxLFar
	 + ", IkminHFar = " + IkminHFar
	 + ", IkminMFar = " + IkminMFar
	 + ", IkminLFar = " + IkminLFar
	 + ", I0kmaxHFar = " + I0kmaxHFar
	 + ", I0kmaxMFar = " + I0kmaxMFar
	 + ", I0kmaxLFar = " + I0kmaxLFar
	 + ", I0kminHFar = " + I0kminHFar
	 + ", I0kminMFar = " + I0kminMFar
	 + ", I0kminLFar = " + I0kminLFar
	 + ", IkunbH = " + IkunbH
	 + ", IkunbM = " + IkunbM
	 + ", IkunbL = " + IkunbL
	 + ", Kkslm1 = " + Kkslm1
	 + ", Kkllm1 = " + Kkllm1
	 + ", Kkrel3 = " + Kkrel3
	 + ", Kkres3 = " + Kkres3
	 + ", Kuop = " + Kuop
	 + ", Kuoprel = " + Kuoprel
	 + ", Kuopres = " + Kuopres
	 + ", K0lm1 = " + K0lm1
	 + ", K0rel2 = " + K0rel2
	 + ", Ikdz1H = " + Ikdz1H
	 + ", Ikdz1M = " + Ikdz1M
	 + ", Ikdz1L = " + Ikdz1L
	 + ", Ikdz3H = " + Ikdz3H
	 + ", Ikdz3M = " + Ikdz3M
	 + ", Ikdz3L = " + Ikdz3L
	 + ", UopH = " + UopH
	 + ", UopM = " + UopM
	 + ", UopL = " + UopL
	 + ", I0dz1H = " + I0dz1H
	 + ", I0dz1M = " + I0dz1M
	 + ", I0dz1L = " + I0dz1L
	 + ", I0dz2H = " + I0dz2H
	 + ", I0dz2M = " + I0dz2M
	 + ", I0dz2L = " + I0dz2L
	 + ", Kksen3H = " + Kksen3H
	 + ", Kksen3M = " + Kksen3M
	 + ", Kksen3L = " + Kksen3L
	 + ", PowerTransformerPtr = " + PowerTransformerPtr+"]";
  }
    
}
    
