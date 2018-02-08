package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*负荷模型	*
***********************/
public class LoadModel  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //名称
  private String Name;
  
  //描述
  private String Description;
  
  //恒定阻抗有功负荷比例(<1)
  private Double PIMP;
  
  //恒定电流有功负荷比例(<1)
  private Double PCUR;
  
  //恒定功率有功负荷比例(<1)
  private Double PCON;
  
  //电压指数相关的有功负荷比例(<1)
  private Double PV;
  
  //有功电压指数
  private Double NP;
  
  //频率变化1％的有功变化百分数(<1)
  private Double DPf;
  
  //恒定阻抗无功负荷比例(<1)
  private Double QIMP;
  
  //恒定电流无功负荷比例(<1)
  private Double QCUR;
  
  //恒定功率无功负荷比例(<1)
  private Double QCON;
  
  //电压指数相关的无功负荷比例(<1)
  private Double QV;
  
  //无功电压指数
  private Double NQ;
  
  //频率变化1％的无功变化百分数(<1)
  private Double DQF;
  
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
    
  public String getDescription()
  {
    return Description;
  }
    
  public void setDescription(String Description)
  {
    this.Description = Description;
  }
    
  public Double getPIMP()
  {
    return PIMP;
  }
    
  public void setPIMP(Double PIMP)
  {
    this.PIMP = PIMP;
  }
    
  public Double getPCUR()
  {
    return PCUR;
  }
    
  public void setPCUR(Double PCUR)
  {
    this.PCUR = PCUR;
  }
    
  public Double getPCON()
  {
    return PCON;
  }
    
  public void setPCON(Double PCON)
  {
    this.PCON = PCON;
  }
    
  public Double getPV()
  {
    return PV;
  }
    
  public void setPV(Double PV)
  {
    this.PV = PV;
  }
    
  public Double getNP()
  {
    return NP;
  }
    
  public void setNP(Double NP)
  {
    this.NP = NP;
  }
    
  public Double getDPf()
  {
    return DPf;
  }
    
  public void setDPf(Double DPf)
  {
    this.DPf = DPf;
  }
    
  public Double getQIMP()
  {
    return QIMP;
  }
    
  public void setQIMP(Double QIMP)
  {
    this.QIMP = QIMP;
  }
    
  public Double getQCUR()
  {
    return QCUR;
  }
    
  public void setQCUR(Double QCUR)
  {
    this.QCUR = QCUR;
  }
    
  public Double getQCON()
  {
    return QCON;
  }
    
  public void setQCON(Double QCON)
  {
    this.QCON = QCON;
  }
    
  public Double getQV()
  {
    return QV;
  }
    
  public void setQV(Double QV)
  {
    this.QV = QV;
  }
    
  public Double getNQ()
  {
    return NQ;
  }
    
  public void setNQ(Double NQ)
  {
    this.NQ = NQ;
  }
    
  public Double getDQF()
  {
    return DQF;
  }
    
  public void setDQF(Double DQF)
  {
    this.DQF = DQF;
  }
    
  public String toString()
  {
    return "LoadModel ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Name = " + Name
	 + ", Description = " + Description
	 + ", PIMP = " + PIMP
	 + ", PCUR = " + PCUR
	 + ", PCON = " + PCON
	 + ", PV = " + PV
	 + ", NP = " + NP
	 + ", DPf = " + DPf
	 + ", QIMP = " + QIMP
	 + ", QCUR = " + QCUR
	 + ", QCON = " + QCON
	 + ", QV = " + QV
	 + ", NQ = " + NQ
	 + ", DQF = " + DQF+"]";
  }
    
}
    
