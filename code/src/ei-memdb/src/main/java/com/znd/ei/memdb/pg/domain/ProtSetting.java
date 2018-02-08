package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*保护设置	*
***********************/
public class ProtSetting  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //整定:互感器误差系数
  private Double ProtKer;
  
  //整定:线路瞬时电流速断可靠系数
  private Double ProtLineKkrel1;
  
  //整定:线路限时电流速断可靠系数
  private Double ProtLineKkrel2;
  
  //整定:线路限时电流速断灵敏系数
  private Double ProtLineKklm2;
  
  //整定:线路定时限过电流可靠系数(保护配合)
  private Double ProtLineKkrelp3;
  
  //整定:线路定时限过电流可靠系数(最大负荷)
  private Double ProtLineKkrell3;
  
  //整定:线路零序Ⅰ段可靠系数
  private Double ProtLineK0rel1;
  
  //整定:线路零序Ⅱ段整定灵敏系数
  private Double ProtLineK0rel2;
  
  //整定:线路零序Ⅲ段可靠系数
  private Double ProtLineK0rel3;
  
  //整定:线路零序Ⅳ段可靠系数
  private Double ProtLineK0rel4;
  
  //整定:线路相间距离Ⅰ段可靠系数
  private Double ProtLineKZrel1;
  
  //整定:线路相间距离Ⅰ段相邻变压器可靠系数
  private Double ProtLineKZTrel1;
  
  //整定:线路相间距离Ⅱ段配合系数
  private Double ProtLineKZp2;
  
  //整定:线路相间距离Ⅱ段灵敏系数
  private Double ProtLineKZlm2;
  
  //整定:线路相间距离Ⅲ段负荷可靠系数
  private Double ProtLineKZfh3;
  
  //整定:线路接地距离Ⅰ段可靠系数
  private Double ProtLineKZ0rel1;
  
  //整定:线路接地距离Ⅰ段相邻变压器可靠系数
  private Double ProtLineKZT0rel1;
  
  //整定:线路接地距离Ⅱ段配合系数
  private Double ProtLineKZ0p2;
  
  //整定:线路接地距离Ⅱ段灵敏系数
  private Double ProtLineKZ0lm2;
  
  //整定:线路接地距离Ⅲ段配合系数
  private Double ProtLineKZ0p3;
  
  //整定:线路接地距离Ⅲ段灵敏系数
  private Double ProtLineKZ0lm3;
  
  //整定:线路限时电流速断按灵敏度整定
  private Integer ProtLineIkdz2UsingKlm;
  
  //整定:线路过流保护与相邻线路配合
  private Integer ProtLineIkdz3Coord3;
  
  //整定:线路零序Ⅰ段整定到变压器内
  private Integer ProtLineI0ProtIntoTran;
  
  //整定:线路零序Ⅱ段与邻线Ⅱ段配合
  private Integer ProtLineI0dz2Coord2;
  
  //整定:线路零序Ⅲ段与邻线Ⅲ段配合
  private Integer ProtLineI0dz3Coord3;
  
  //整定:终端线路零序Ⅲ段按变压器不平衡电流
  private Integer ProtLineI0dz3Unb;
  
  //整定:线路相间距离Ⅰ段可整定到变压器内
  private Integer ProtLineZProtIntoTran;
  
  //整定:线路相间距离Ⅱ段与邻线Ⅱ段配合
  private Integer ProtLineZdz2Coord2;
  
  //整定:线路相间距离Ⅱ段按灵敏度整定
  private Integer ProtLineZdz2UsingKlm;
  
  //整定:线路相间距离Ⅲ段与邻线Ⅲ段配合
  private Integer ProtLineZdz3Coord3;
  
  //整定:线路相间距离Ⅲ段按负荷阻抗整定
  private Integer ProtLineZdz3UsingKfh;
  
  //整定:线路接地距离Ⅰ段可整定到变压器内
  private Integer ProtLineZ0ProtIntoTran;
  
  //整定:线路接地距离Ⅱ段与邻线Ⅱ段配合
  private Integer ProtLineZ0dz2Coord2;
  
  //整定:线路接地距离Ⅱ段按灵敏度整定
  private Integer ProtLineZ0dz2UsingKlm;
  
  //整定:线路接地距离Ⅲ段与邻线Ⅲ段配合
  private Integer ProtLineZ0dz3Coord3;
  
  //整定:线路接地距离Ⅲ段按灵敏度整定
  private Integer ProtLineZ0dz3UsingKlm;
  
  //整定:变压器电源侧速断保护灵敏系数
  private Double ProtTranKkslm1;
  
  //整定:变压器负荷侧速断保护灵敏系数
  private Double ProtTranKkllm1;
  
  //整定:变压器过流保护可靠系数
  private Double ProtTranKkrel3;
  
  //整定:变压器过流保护返回系数
  private Double ProtTranKkres3;
  
  //整定:变压器复压闭锁电压值
  private Double ProtTranKuop;
  
  //整定:变压器复压闭锁可靠系数
  private Double ProtTranKuoprel;
  
  //整定:变压器复压闭锁返回系数
  private Double ProtTranKuopres;
  
  //整定:变压器零序Ⅰ段灵敏系数
  private Double ProtTranK0lm1;
  
  //整定:变压器零序Ⅱ段可靠系数
  private Double ProtTranK0rel2;
  
  //整定:母线不平衡电流可靠系数
  private Double ProtBusKunbrel;
  
  //整定:母线二次断线可靠系数
  private Double ProtBusKbrkrel;
  
  //整定:母线不平衡电流使用短路电流计算
  private Integer ProtBusFaultUnb;
  
  //整定:发电机纵差保护可靠系数
  private Double ProtGenKdrel;
  
  //整定:发电机过流保护可靠系数
  private Double ProtGenKkrel;
  
  //整定:发电机过流保护返回系数
  private Double ProtGenKkres;
  
  //整定:发电机非周期分量影响系数
  private Double ProtGenKap;
  
  //整定:发电机电流互感器同型系数
  private Double ProtGenKss;
  
  //整定:电动机启动电流倍数
  private Double ProtLoadKst;
  
  //整定:电动机纵差保护可靠系数
  private Double ProtLoadKdrel;
  
  //整定:电动机过流保护可靠系数
  private Double ProtLoadKkrel;
  
  //整定:电动机过流保护返回系数
  private Double ProtLoadKkres;
  
  //整定:电动机非周期分量影响系数
  private Double ProtLoadKap;
  
  //整定:电动机电流互感器同型系数
  private Double ProtLoadKss;
  
  //整定:并联电容器延时电流速断可靠系数
  private Double ProtCapKkrel2;
  
  //整定:并联电容器过流保护可靠系数
  private Double ProtCapKkrel3;
  
  //整定:并联电容器过流保护返回系数
  private Double ProtCapKkres3;
  
  //整定:并联电抗器差动保护可靠系数
  private Double ProtReacKdrel;
  
  //整定:并联电抗器电流速断可靠系数
  private Double ProtReacKkrel1;
  
  //整定:并联电抗器过流保护可靠系数
  private Double ProtReacKkrel3;
  
  //整定:并联电抗器过流保护返回系数
  private Double ProtReacKkres3;
  
  //整定:母联/分段开关过流Ⅰ段配合系数
  private Double ProtBreakerKkp1;
  
  //整定:母联/分段开关过流Ⅰ段灵敏系数
  private Double ProtBreakerKklm1;
  
  //整定:母联/分段开关过流Ⅱ段配合系数
  private Double ProtBreakerKkp2;
  
  //整定:母联/分段开关合环保护可靠系数
  private Double ProtBreakerKkr;
  
  //校核:线路瞬时电流速断灵敏系数
  private Double ProtLineKksen1;
  
  //校核:线路限时电流速断灵敏系数
  private Double ProtLineKksen2;
  
  //校核:线路定时限过电流灵敏系数
  private Double ProtLineKksen3;
  
  //校核:线路零序Ⅰ段灵敏系数
  private Double ProtLineK0sen1;
  
  //校核:线路零序Ⅱ段灵敏系数
  private Double ProtLineK0sen2;
  
  //校核:线路零序Ⅲ段灵敏系数
  private Double ProtLineK0sen3;
  
  //校核:变压器过流保护灵敏系数
  private Double ProtTranKksen3;
  
  //校核:发电机近后备过流保护灵敏系数
  private Double ProtGenKksen3Near;
  
  //校核:发电机远后备过流保护灵敏系数
  private Double ProtGenKksen3Far;
  
  //校核:电动机过流保护灵敏系数
  private Double ProtLoadKksen3;
  
  //校核:并联电容器延时电流速断灵敏系数
  private Double ProtCapKksen2;
  
  //校核:并联电容器过流保护灵敏系数
  private Double ProtCapKksen3;
  
  //校核:并联电抗器电流速断灵敏系数
  private Double ProtReacKksen1;
  
  //校核:并联电抗器过流保护灵敏系数
  private Double ProtReacKksen3;
  
  //校核:母联/分段开关过流Ⅰ段灵敏系数
  private Double ProtBreakerKksen1;
  
  //校核:母联/分段开关过流Ⅱ段灵敏系数
  private Double ProtBreakerKksen2;
  
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
    
  public Double getProtKer()
  {
    return ProtKer;
  }
    
  public void setProtKer(Double ProtKer)
  {
    this.ProtKer = ProtKer;
  }
    
  public Double getProtLineKkrel1()
  {
    return ProtLineKkrel1;
  }
    
  public void setProtLineKkrel1(Double ProtLineKkrel1)
  {
    this.ProtLineKkrel1 = ProtLineKkrel1;
  }
    
  public Double getProtLineKkrel2()
  {
    return ProtLineKkrel2;
  }
    
  public void setProtLineKkrel2(Double ProtLineKkrel2)
  {
    this.ProtLineKkrel2 = ProtLineKkrel2;
  }
    
  public Double getProtLineKklm2()
  {
    return ProtLineKklm2;
  }
    
  public void setProtLineKklm2(Double ProtLineKklm2)
  {
    this.ProtLineKklm2 = ProtLineKklm2;
  }
    
  public Double getProtLineKkrelp3()
  {
    return ProtLineKkrelp3;
  }
    
  public void setProtLineKkrelp3(Double ProtLineKkrelp3)
  {
    this.ProtLineKkrelp3 = ProtLineKkrelp3;
  }
    
  public Double getProtLineKkrell3()
  {
    return ProtLineKkrell3;
  }
    
  public void setProtLineKkrell3(Double ProtLineKkrell3)
  {
    this.ProtLineKkrell3 = ProtLineKkrell3;
  }
    
  public Double getProtLineK0rel1()
  {
    return ProtLineK0rel1;
  }
    
  public void setProtLineK0rel1(Double ProtLineK0rel1)
  {
    this.ProtLineK0rel1 = ProtLineK0rel1;
  }
    
  public Double getProtLineK0rel2()
  {
    return ProtLineK0rel2;
  }
    
  public void setProtLineK0rel2(Double ProtLineK0rel2)
  {
    this.ProtLineK0rel2 = ProtLineK0rel2;
  }
    
  public Double getProtLineK0rel3()
  {
    return ProtLineK0rel3;
  }
    
  public void setProtLineK0rel3(Double ProtLineK0rel3)
  {
    this.ProtLineK0rel3 = ProtLineK0rel3;
  }
    
  public Double getProtLineK0rel4()
  {
    return ProtLineK0rel4;
  }
    
  public void setProtLineK0rel4(Double ProtLineK0rel4)
  {
    this.ProtLineK0rel4 = ProtLineK0rel4;
  }
    
  public Double getProtLineKZrel1()
  {
    return ProtLineKZrel1;
  }
    
  public void setProtLineKZrel1(Double ProtLineKZrel1)
  {
    this.ProtLineKZrel1 = ProtLineKZrel1;
  }
    
  public Double getProtLineKZTrel1()
  {
    return ProtLineKZTrel1;
  }
    
  public void setProtLineKZTrel1(Double ProtLineKZTrel1)
  {
    this.ProtLineKZTrel1 = ProtLineKZTrel1;
  }
    
  public Double getProtLineKZp2()
  {
    return ProtLineKZp2;
  }
    
  public void setProtLineKZp2(Double ProtLineKZp2)
  {
    this.ProtLineKZp2 = ProtLineKZp2;
  }
    
  public Double getProtLineKZlm2()
  {
    return ProtLineKZlm2;
  }
    
  public void setProtLineKZlm2(Double ProtLineKZlm2)
  {
    this.ProtLineKZlm2 = ProtLineKZlm2;
  }
    
  public Double getProtLineKZfh3()
  {
    return ProtLineKZfh3;
  }
    
  public void setProtLineKZfh3(Double ProtLineKZfh3)
  {
    this.ProtLineKZfh3 = ProtLineKZfh3;
  }
    
  public Double getProtLineKZ0rel1()
  {
    return ProtLineKZ0rel1;
  }
    
  public void setProtLineKZ0rel1(Double ProtLineKZ0rel1)
  {
    this.ProtLineKZ0rel1 = ProtLineKZ0rel1;
  }
    
  public Double getProtLineKZT0rel1()
  {
    return ProtLineKZT0rel1;
  }
    
  public void setProtLineKZT0rel1(Double ProtLineKZT0rel1)
  {
    this.ProtLineKZT0rel1 = ProtLineKZT0rel1;
  }
    
  public Double getProtLineKZ0p2()
  {
    return ProtLineKZ0p2;
  }
    
  public void setProtLineKZ0p2(Double ProtLineKZ0p2)
  {
    this.ProtLineKZ0p2 = ProtLineKZ0p2;
  }
    
  public Double getProtLineKZ0lm2()
  {
    return ProtLineKZ0lm2;
  }
    
  public void setProtLineKZ0lm2(Double ProtLineKZ0lm2)
  {
    this.ProtLineKZ0lm2 = ProtLineKZ0lm2;
  }
    
  public Double getProtLineKZ0p3()
  {
    return ProtLineKZ0p3;
  }
    
  public void setProtLineKZ0p3(Double ProtLineKZ0p3)
  {
    this.ProtLineKZ0p3 = ProtLineKZ0p3;
  }
    
  public Double getProtLineKZ0lm3()
  {
    return ProtLineKZ0lm3;
  }
    
  public void setProtLineKZ0lm3(Double ProtLineKZ0lm3)
  {
    this.ProtLineKZ0lm3 = ProtLineKZ0lm3;
  }
    
  public Integer getProtLineIkdz2UsingKlm()
  {
    return ProtLineIkdz2UsingKlm;
  }
    
  public void setProtLineIkdz2UsingKlm(Integer ProtLineIkdz2UsingKlm)
  {
    this.ProtLineIkdz2UsingKlm = ProtLineIkdz2UsingKlm;
  }
    
  public Integer getProtLineIkdz3Coord3()
  {
    return ProtLineIkdz3Coord3;
  }
    
  public void setProtLineIkdz3Coord3(Integer ProtLineIkdz3Coord3)
  {
    this.ProtLineIkdz3Coord3 = ProtLineIkdz3Coord3;
  }
    
  public Integer getProtLineI0ProtIntoTran()
  {
    return ProtLineI0ProtIntoTran;
  }
    
  public void setProtLineI0ProtIntoTran(Integer ProtLineI0ProtIntoTran)
  {
    this.ProtLineI0ProtIntoTran = ProtLineI0ProtIntoTran;
  }
    
  public Integer getProtLineI0dz2Coord2()
  {
    return ProtLineI0dz2Coord2;
  }
    
  public void setProtLineI0dz2Coord2(Integer ProtLineI0dz2Coord2)
  {
    this.ProtLineI0dz2Coord2 = ProtLineI0dz2Coord2;
  }
    
  public Integer getProtLineI0dz3Coord3()
  {
    return ProtLineI0dz3Coord3;
  }
    
  public void setProtLineI0dz3Coord3(Integer ProtLineI0dz3Coord3)
  {
    this.ProtLineI0dz3Coord3 = ProtLineI0dz3Coord3;
  }
    
  public Integer getProtLineI0dz3Unb()
  {
    return ProtLineI0dz3Unb;
  }
    
  public void setProtLineI0dz3Unb(Integer ProtLineI0dz3Unb)
  {
    this.ProtLineI0dz3Unb = ProtLineI0dz3Unb;
  }
    
  public Integer getProtLineZProtIntoTran()
  {
    return ProtLineZProtIntoTran;
  }
    
  public void setProtLineZProtIntoTran(Integer ProtLineZProtIntoTran)
  {
    this.ProtLineZProtIntoTran = ProtLineZProtIntoTran;
  }
    
  public Integer getProtLineZdz2Coord2()
  {
    return ProtLineZdz2Coord2;
  }
    
  public void setProtLineZdz2Coord2(Integer ProtLineZdz2Coord2)
  {
    this.ProtLineZdz2Coord2 = ProtLineZdz2Coord2;
  }
    
  public Integer getProtLineZdz2UsingKlm()
  {
    return ProtLineZdz2UsingKlm;
  }
    
  public void setProtLineZdz2UsingKlm(Integer ProtLineZdz2UsingKlm)
  {
    this.ProtLineZdz2UsingKlm = ProtLineZdz2UsingKlm;
  }
    
  public Integer getProtLineZdz3Coord3()
  {
    return ProtLineZdz3Coord3;
  }
    
  public void setProtLineZdz3Coord3(Integer ProtLineZdz3Coord3)
  {
    this.ProtLineZdz3Coord3 = ProtLineZdz3Coord3;
  }
    
  public Integer getProtLineZdz3UsingKfh()
  {
    return ProtLineZdz3UsingKfh;
  }
    
  public void setProtLineZdz3UsingKfh(Integer ProtLineZdz3UsingKfh)
  {
    this.ProtLineZdz3UsingKfh = ProtLineZdz3UsingKfh;
  }
    
  public Integer getProtLineZ0ProtIntoTran()
  {
    return ProtLineZ0ProtIntoTran;
  }
    
  public void setProtLineZ0ProtIntoTran(Integer ProtLineZ0ProtIntoTran)
  {
    this.ProtLineZ0ProtIntoTran = ProtLineZ0ProtIntoTran;
  }
    
  public Integer getProtLineZ0dz2Coord2()
  {
    return ProtLineZ0dz2Coord2;
  }
    
  public void setProtLineZ0dz2Coord2(Integer ProtLineZ0dz2Coord2)
  {
    this.ProtLineZ0dz2Coord2 = ProtLineZ0dz2Coord2;
  }
    
  public Integer getProtLineZ0dz2UsingKlm()
  {
    return ProtLineZ0dz2UsingKlm;
  }
    
  public void setProtLineZ0dz2UsingKlm(Integer ProtLineZ0dz2UsingKlm)
  {
    this.ProtLineZ0dz2UsingKlm = ProtLineZ0dz2UsingKlm;
  }
    
  public Integer getProtLineZ0dz3Coord3()
  {
    return ProtLineZ0dz3Coord3;
  }
    
  public void setProtLineZ0dz3Coord3(Integer ProtLineZ0dz3Coord3)
  {
    this.ProtLineZ0dz3Coord3 = ProtLineZ0dz3Coord3;
  }
    
  public Integer getProtLineZ0dz3UsingKlm()
  {
    return ProtLineZ0dz3UsingKlm;
  }
    
  public void setProtLineZ0dz3UsingKlm(Integer ProtLineZ0dz3UsingKlm)
  {
    this.ProtLineZ0dz3UsingKlm = ProtLineZ0dz3UsingKlm;
  }
    
  public Double getProtTranKkslm1()
  {
    return ProtTranKkslm1;
  }
    
  public void setProtTranKkslm1(Double ProtTranKkslm1)
  {
    this.ProtTranKkslm1 = ProtTranKkslm1;
  }
    
  public Double getProtTranKkllm1()
  {
    return ProtTranKkllm1;
  }
    
  public void setProtTranKkllm1(Double ProtTranKkllm1)
  {
    this.ProtTranKkllm1 = ProtTranKkllm1;
  }
    
  public Double getProtTranKkrel3()
  {
    return ProtTranKkrel3;
  }
    
  public void setProtTranKkrel3(Double ProtTranKkrel3)
  {
    this.ProtTranKkrel3 = ProtTranKkrel3;
  }
    
  public Double getProtTranKkres3()
  {
    return ProtTranKkres3;
  }
    
  public void setProtTranKkres3(Double ProtTranKkres3)
  {
    this.ProtTranKkres3 = ProtTranKkres3;
  }
    
  public Double getProtTranKuop()
  {
    return ProtTranKuop;
  }
    
  public void setProtTranKuop(Double ProtTranKuop)
  {
    this.ProtTranKuop = ProtTranKuop;
  }
    
  public Double getProtTranKuoprel()
  {
    return ProtTranKuoprel;
  }
    
  public void setProtTranKuoprel(Double ProtTranKuoprel)
  {
    this.ProtTranKuoprel = ProtTranKuoprel;
  }
    
  public Double getProtTranKuopres()
  {
    return ProtTranKuopres;
  }
    
  public void setProtTranKuopres(Double ProtTranKuopres)
  {
    this.ProtTranKuopres = ProtTranKuopres;
  }
    
  public Double getProtTranK0lm1()
  {
    return ProtTranK0lm1;
  }
    
  public void setProtTranK0lm1(Double ProtTranK0lm1)
  {
    this.ProtTranK0lm1 = ProtTranK0lm1;
  }
    
  public Double getProtTranK0rel2()
  {
    return ProtTranK0rel2;
  }
    
  public void setProtTranK0rel2(Double ProtTranK0rel2)
  {
    this.ProtTranK0rel2 = ProtTranK0rel2;
  }
    
  public Double getProtBusKunbrel()
  {
    return ProtBusKunbrel;
  }
    
  public void setProtBusKunbrel(Double ProtBusKunbrel)
  {
    this.ProtBusKunbrel = ProtBusKunbrel;
  }
    
  public Double getProtBusKbrkrel()
  {
    return ProtBusKbrkrel;
  }
    
  public void setProtBusKbrkrel(Double ProtBusKbrkrel)
  {
    this.ProtBusKbrkrel = ProtBusKbrkrel;
  }
    
  public Integer getProtBusFaultUnb()
  {
    return ProtBusFaultUnb;
  }
    
  public void setProtBusFaultUnb(Integer ProtBusFaultUnb)
  {
    this.ProtBusFaultUnb = ProtBusFaultUnb;
  }
    
  public Double getProtGenKdrel()
  {
    return ProtGenKdrel;
  }
    
  public void setProtGenKdrel(Double ProtGenKdrel)
  {
    this.ProtGenKdrel = ProtGenKdrel;
  }
    
  public Double getProtGenKkrel()
  {
    return ProtGenKkrel;
  }
    
  public void setProtGenKkrel(Double ProtGenKkrel)
  {
    this.ProtGenKkrel = ProtGenKkrel;
  }
    
  public Double getProtGenKkres()
  {
    return ProtGenKkres;
  }
    
  public void setProtGenKkres(Double ProtGenKkres)
  {
    this.ProtGenKkres = ProtGenKkres;
  }
    
  public Double getProtGenKap()
  {
    return ProtGenKap;
  }
    
  public void setProtGenKap(Double ProtGenKap)
  {
    this.ProtGenKap = ProtGenKap;
  }
    
  public Double getProtGenKss()
  {
    return ProtGenKss;
  }
    
  public void setProtGenKss(Double ProtGenKss)
  {
    this.ProtGenKss = ProtGenKss;
  }
    
  public Double getProtLoadKst()
  {
    return ProtLoadKst;
  }
    
  public void setProtLoadKst(Double ProtLoadKst)
  {
    this.ProtLoadKst = ProtLoadKst;
  }
    
  public Double getProtLoadKdrel()
  {
    return ProtLoadKdrel;
  }
    
  public void setProtLoadKdrel(Double ProtLoadKdrel)
  {
    this.ProtLoadKdrel = ProtLoadKdrel;
  }
    
  public Double getProtLoadKkrel()
  {
    return ProtLoadKkrel;
  }
    
  public void setProtLoadKkrel(Double ProtLoadKkrel)
  {
    this.ProtLoadKkrel = ProtLoadKkrel;
  }
    
  public Double getProtLoadKkres()
  {
    return ProtLoadKkres;
  }
    
  public void setProtLoadKkres(Double ProtLoadKkres)
  {
    this.ProtLoadKkres = ProtLoadKkres;
  }
    
  public Double getProtLoadKap()
  {
    return ProtLoadKap;
  }
    
  public void setProtLoadKap(Double ProtLoadKap)
  {
    this.ProtLoadKap = ProtLoadKap;
  }
    
  public Double getProtLoadKss()
  {
    return ProtLoadKss;
  }
    
  public void setProtLoadKss(Double ProtLoadKss)
  {
    this.ProtLoadKss = ProtLoadKss;
  }
    
  public Double getProtCapKkrel2()
  {
    return ProtCapKkrel2;
  }
    
  public void setProtCapKkrel2(Double ProtCapKkrel2)
  {
    this.ProtCapKkrel2 = ProtCapKkrel2;
  }
    
  public Double getProtCapKkrel3()
  {
    return ProtCapKkrel3;
  }
    
  public void setProtCapKkrel3(Double ProtCapKkrel3)
  {
    this.ProtCapKkrel3 = ProtCapKkrel3;
  }
    
  public Double getProtCapKkres3()
  {
    return ProtCapKkres3;
  }
    
  public void setProtCapKkres3(Double ProtCapKkres3)
  {
    this.ProtCapKkres3 = ProtCapKkres3;
  }
    
  public Double getProtReacKdrel()
  {
    return ProtReacKdrel;
  }
    
  public void setProtReacKdrel(Double ProtReacKdrel)
  {
    this.ProtReacKdrel = ProtReacKdrel;
  }
    
  public Double getProtReacKkrel1()
  {
    return ProtReacKkrel1;
  }
    
  public void setProtReacKkrel1(Double ProtReacKkrel1)
  {
    this.ProtReacKkrel1 = ProtReacKkrel1;
  }
    
  public Double getProtReacKkrel3()
  {
    return ProtReacKkrel3;
  }
    
  public void setProtReacKkrel3(Double ProtReacKkrel3)
  {
    this.ProtReacKkrel3 = ProtReacKkrel3;
  }
    
  public Double getProtReacKkres3()
  {
    return ProtReacKkres3;
  }
    
  public void setProtReacKkres3(Double ProtReacKkres3)
  {
    this.ProtReacKkres3 = ProtReacKkres3;
  }
    
  public Double getProtBreakerKkp1()
  {
    return ProtBreakerKkp1;
  }
    
  public void setProtBreakerKkp1(Double ProtBreakerKkp1)
  {
    this.ProtBreakerKkp1 = ProtBreakerKkp1;
  }
    
  public Double getProtBreakerKklm1()
  {
    return ProtBreakerKklm1;
  }
    
  public void setProtBreakerKklm1(Double ProtBreakerKklm1)
  {
    this.ProtBreakerKklm1 = ProtBreakerKklm1;
  }
    
  public Double getProtBreakerKkp2()
  {
    return ProtBreakerKkp2;
  }
    
  public void setProtBreakerKkp2(Double ProtBreakerKkp2)
  {
    this.ProtBreakerKkp2 = ProtBreakerKkp2;
  }
    
  public Double getProtBreakerKkr()
  {
    return ProtBreakerKkr;
  }
    
  public void setProtBreakerKkr(Double ProtBreakerKkr)
  {
    this.ProtBreakerKkr = ProtBreakerKkr;
  }
    
  public Double getProtLineKksen1()
  {
    return ProtLineKksen1;
  }
    
  public void setProtLineKksen1(Double ProtLineKksen1)
  {
    this.ProtLineKksen1 = ProtLineKksen1;
  }
    
  public Double getProtLineKksen2()
  {
    return ProtLineKksen2;
  }
    
  public void setProtLineKksen2(Double ProtLineKksen2)
  {
    this.ProtLineKksen2 = ProtLineKksen2;
  }
    
  public Double getProtLineKksen3()
  {
    return ProtLineKksen3;
  }
    
  public void setProtLineKksen3(Double ProtLineKksen3)
  {
    this.ProtLineKksen3 = ProtLineKksen3;
  }
    
  public Double getProtLineK0sen1()
  {
    return ProtLineK0sen1;
  }
    
  public void setProtLineK0sen1(Double ProtLineK0sen1)
  {
    this.ProtLineK0sen1 = ProtLineK0sen1;
  }
    
  public Double getProtLineK0sen2()
  {
    return ProtLineK0sen2;
  }
    
  public void setProtLineK0sen2(Double ProtLineK0sen2)
  {
    this.ProtLineK0sen2 = ProtLineK0sen2;
  }
    
  public Double getProtLineK0sen3()
  {
    return ProtLineK0sen3;
  }
    
  public void setProtLineK0sen3(Double ProtLineK0sen3)
  {
    this.ProtLineK0sen3 = ProtLineK0sen3;
  }
    
  public Double getProtTranKksen3()
  {
    return ProtTranKksen3;
  }
    
  public void setProtTranKksen3(Double ProtTranKksen3)
  {
    this.ProtTranKksen3 = ProtTranKksen3;
  }
    
  public Double getProtGenKksen3Near()
  {
    return ProtGenKksen3Near;
  }
    
  public void setProtGenKksen3Near(Double ProtGenKksen3Near)
  {
    this.ProtGenKksen3Near = ProtGenKksen3Near;
  }
    
  public Double getProtGenKksen3Far()
  {
    return ProtGenKksen3Far;
  }
    
  public void setProtGenKksen3Far(Double ProtGenKksen3Far)
  {
    this.ProtGenKksen3Far = ProtGenKksen3Far;
  }
    
  public Double getProtLoadKksen3()
  {
    return ProtLoadKksen3;
  }
    
  public void setProtLoadKksen3(Double ProtLoadKksen3)
  {
    this.ProtLoadKksen3 = ProtLoadKksen3;
  }
    
  public Double getProtCapKksen2()
  {
    return ProtCapKksen2;
  }
    
  public void setProtCapKksen2(Double ProtCapKksen2)
  {
    this.ProtCapKksen2 = ProtCapKksen2;
  }
    
  public Double getProtCapKksen3()
  {
    return ProtCapKksen3;
  }
    
  public void setProtCapKksen3(Double ProtCapKksen3)
  {
    this.ProtCapKksen3 = ProtCapKksen3;
  }
    
  public Double getProtReacKksen1()
  {
    return ProtReacKksen1;
  }
    
  public void setProtReacKksen1(Double ProtReacKksen1)
  {
    this.ProtReacKksen1 = ProtReacKksen1;
  }
    
  public Double getProtReacKksen3()
  {
    return ProtReacKksen3;
  }
    
  public void setProtReacKksen3(Double ProtReacKksen3)
  {
    this.ProtReacKksen3 = ProtReacKksen3;
  }
    
  public Double getProtBreakerKksen1()
  {
    return ProtBreakerKksen1;
  }
    
  public void setProtBreakerKksen1(Double ProtBreakerKksen1)
  {
    this.ProtBreakerKksen1 = ProtBreakerKksen1;
  }
    
  public Double getProtBreakerKksen2()
  {
    return ProtBreakerKksen2;
  }
    
  public void setProtBreakerKksen2(Double ProtBreakerKksen2)
  {
    this.ProtBreakerKksen2 = ProtBreakerKksen2;
  }
    
  public String toString()
  {
    return "ProtSetting ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ProtKer = " + ProtKer
	 + ", ProtLineKkrel1 = " + ProtLineKkrel1
	 + ", ProtLineKkrel2 = " + ProtLineKkrel2
	 + ", ProtLineKklm2 = " + ProtLineKklm2
	 + ", ProtLineKkrelp3 = " + ProtLineKkrelp3
	 + ", ProtLineKkrell3 = " + ProtLineKkrell3
	 + ", ProtLineK0rel1 = " + ProtLineK0rel1
	 + ", ProtLineK0rel2 = " + ProtLineK0rel2
	 + ", ProtLineK0rel3 = " + ProtLineK0rel3
	 + ", ProtLineK0rel4 = " + ProtLineK0rel4
	 + ", ProtLineKZrel1 = " + ProtLineKZrel1
	 + ", ProtLineKZTrel1 = " + ProtLineKZTrel1
	 + ", ProtLineKZp2 = " + ProtLineKZp2
	 + ", ProtLineKZlm2 = " + ProtLineKZlm2
	 + ", ProtLineKZfh3 = " + ProtLineKZfh3
	 + ", ProtLineKZ0rel1 = " + ProtLineKZ0rel1
	 + ", ProtLineKZT0rel1 = " + ProtLineKZT0rel1
	 + ", ProtLineKZ0p2 = " + ProtLineKZ0p2
	 + ", ProtLineKZ0lm2 = " + ProtLineKZ0lm2
	 + ", ProtLineKZ0p3 = " + ProtLineKZ0p3
	 + ", ProtLineKZ0lm3 = " + ProtLineKZ0lm3
	 + ", ProtLineIkdz2UsingKlm = " + ProtLineIkdz2UsingKlm
	 + ", ProtLineIkdz3Coord3 = " + ProtLineIkdz3Coord3
	 + ", ProtLineI0ProtIntoTran = " + ProtLineI0ProtIntoTran
	 + ", ProtLineI0dz2Coord2 = " + ProtLineI0dz2Coord2
	 + ", ProtLineI0dz3Coord3 = " + ProtLineI0dz3Coord3
	 + ", ProtLineI0dz3Unb = " + ProtLineI0dz3Unb
	 + ", ProtLineZProtIntoTran = " + ProtLineZProtIntoTran
	 + ", ProtLineZdz2Coord2 = " + ProtLineZdz2Coord2
	 + ", ProtLineZdz2UsingKlm = " + ProtLineZdz2UsingKlm
	 + ", ProtLineZdz3Coord3 = " + ProtLineZdz3Coord3
	 + ", ProtLineZdz3UsingKfh = " + ProtLineZdz3UsingKfh
	 + ", ProtLineZ0ProtIntoTran = " + ProtLineZ0ProtIntoTran
	 + ", ProtLineZ0dz2Coord2 = " + ProtLineZ0dz2Coord2
	 + ", ProtLineZ0dz2UsingKlm = " + ProtLineZ0dz2UsingKlm
	 + ", ProtLineZ0dz3Coord3 = " + ProtLineZ0dz3Coord3
	 + ", ProtLineZ0dz3UsingKlm = " + ProtLineZ0dz3UsingKlm
	 + ", ProtTranKkslm1 = " + ProtTranKkslm1
	 + ", ProtTranKkllm1 = " + ProtTranKkllm1
	 + ", ProtTranKkrel3 = " + ProtTranKkrel3
	 + ", ProtTranKkres3 = " + ProtTranKkres3
	 + ", ProtTranKuop = " + ProtTranKuop
	 + ", ProtTranKuoprel = " + ProtTranKuoprel
	 + ", ProtTranKuopres = " + ProtTranKuopres
	 + ", ProtTranK0lm1 = " + ProtTranK0lm1
	 + ", ProtTranK0rel2 = " + ProtTranK0rel2
	 + ", ProtBusKunbrel = " + ProtBusKunbrel
	 + ", ProtBusKbrkrel = " + ProtBusKbrkrel
	 + ", ProtBusFaultUnb = " + ProtBusFaultUnb
	 + ", ProtGenKdrel = " + ProtGenKdrel
	 + ", ProtGenKkrel = " + ProtGenKkrel
	 + ", ProtGenKkres = " + ProtGenKkres
	 + ", ProtGenKap = " + ProtGenKap
	 + ", ProtGenKss = " + ProtGenKss
	 + ", ProtLoadKst = " + ProtLoadKst
	 + ", ProtLoadKdrel = " + ProtLoadKdrel
	 + ", ProtLoadKkrel = " + ProtLoadKkrel
	 + ", ProtLoadKkres = " + ProtLoadKkres
	 + ", ProtLoadKap = " + ProtLoadKap
	 + ", ProtLoadKss = " + ProtLoadKss
	 + ", ProtCapKkrel2 = " + ProtCapKkrel2
	 + ", ProtCapKkrel3 = " + ProtCapKkrel3
	 + ", ProtCapKkres3 = " + ProtCapKkres3
	 + ", ProtReacKdrel = " + ProtReacKdrel
	 + ", ProtReacKkrel1 = " + ProtReacKkrel1
	 + ", ProtReacKkrel3 = " + ProtReacKkrel3
	 + ", ProtReacKkres3 = " + ProtReacKkres3
	 + ", ProtBreakerKkp1 = " + ProtBreakerKkp1
	 + ", ProtBreakerKklm1 = " + ProtBreakerKklm1
	 + ", ProtBreakerKkp2 = " + ProtBreakerKkp2
	 + ", ProtBreakerKkr = " + ProtBreakerKkr
	 + ", ProtLineKksen1 = " + ProtLineKksen1
	 + ", ProtLineKksen2 = " + ProtLineKksen2
	 + ", ProtLineKksen3 = " + ProtLineKksen3
	 + ", ProtLineK0sen1 = " + ProtLineK0sen1
	 + ", ProtLineK0sen2 = " + ProtLineK0sen2
	 + ", ProtLineK0sen3 = " + ProtLineK0sen3
	 + ", ProtTranKksen3 = " + ProtTranKksen3
	 + ", ProtGenKksen3Near = " + ProtGenKksen3Near
	 + ", ProtGenKksen3Far = " + ProtGenKksen3Far
	 + ", ProtLoadKksen3 = " + ProtLoadKksen3
	 + ", ProtCapKksen2 = " + ProtCapKksen2
	 + ", ProtCapKksen3 = " + ProtCapKksen3
	 + ", ProtReacKksen1 = " + ProtReacKksen1
	 + ", ProtReacKksen3 = " + ProtReacKksen3
	 + ", ProtBreakerKksen1 = " + ProtBreakerKksen1
	 + ", ProtBreakerKksen2 = " + ProtBreakerKksen2+"]";
  }
    
}
    
