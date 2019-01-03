package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*负荷可靠性结果	*
***********************/
public class EnergyConsumerReliable  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //负荷索引
  private Integer LoadIdx;
  
  //摄动阶数
  private Integer Step;
  
  //年均综合停电次数(次/年)
  private Double ro_r;
  
  //综合停电平均持续时间(小时/次)
  private Double ro_t;
  
  //年均综合停电时间
  private Double ro_u;
  
  //年均故障停电次数(次/年)
  private Double ro_fr;
  
  //故障停电平均持续时间(小时/次)
  private Double ro_ft;
  
  //年均故障停电时间
  private Double ro_fu;
  
  //年均预安排停电次数(次/年)
  private Double ro_ar;
  
  //预安排停电平均持续时间(小时/次)
  private Double ro_at;
  
  //年均预安排停电时间
  private Double ro_au;
  
  //年均共模停电次数(次/年)
  private Double ro_cmr;
  
  //共模停电平均持续时间(小时/次)
  private Double ro_cmt;
  
  //年均共模停电时间
  private Double ro_cmu;
  
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
    
  public Integer getLoadIdx()
  {
    return LoadIdx;
  }
    
  public void setLoadIdx(Integer LoadIdx)
  {
    this.LoadIdx = LoadIdx;
  }
    
  public Integer getStep()
  {
    return Step;
  }
    
  public void setStep(Integer Step)
  {
    this.Step = Step;
  }
    
  public Double getro_r()
  {
    return ro_r;
  }
    
  public void setro_r(Double ro_r)
  {
    this.ro_r = ro_r;
  }
    
  public Double getro_t()
  {
    return ro_t;
  }
    
  public void setro_t(Double ro_t)
  {
    this.ro_t = ro_t;
  }
    
  public Double getro_u()
  {
    return ro_u;
  }
    
  public void setro_u(Double ro_u)
  {
    this.ro_u = ro_u;
  }
    
  public Double getro_fr()
  {
    return ro_fr;
  }
    
  public void setro_fr(Double ro_fr)
  {
    this.ro_fr = ro_fr;
  }
    
  public Double getro_ft()
  {
    return ro_ft;
  }
    
  public void setro_ft(Double ro_ft)
  {
    this.ro_ft = ro_ft;
  }
    
  public Double getro_fu()
  {
    return ro_fu;
  }
    
  public void setro_fu(Double ro_fu)
  {
    this.ro_fu = ro_fu;
  }
    
  public Double getro_ar()
  {
    return ro_ar;
  }
    
  public void setro_ar(Double ro_ar)
  {
    this.ro_ar = ro_ar;
  }
    
  public Double getro_at()
  {
    return ro_at;
  }
    
  public void setro_at(Double ro_at)
  {
    this.ro_at = ro_at;
  }
    
  public Double getro_au()
  {
    return ro_au;
  }
    
  public void setro_au(Double ro_au)
  {
    this.ro_au = ro_au;
  }
    
  public Double getro_cmr()
  {
    return ro_cmr;
  }
    
  public void setro_cmr(Double ro_cmr)
  {
    this.ro_cmr = ro_cmr;
  }
    
  public Double getro_cmt()
  {
    return ro_cmt;
  }
    
  public void setro_cmt(Double ro_cmt)
  {
    this.ro_cmt = ro_cmt;
  }
    
  public Double getro_cmu()
  {
    return ro_cmu;
  }
    
  public void setro_cmu(Double ro_cmu)
  {
    this.ro_cmu = ro_cmu;
  }
    
  public String toString()
  {
    return "EnergyConsumerReliable ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", LoadIdx = " + LoadIdx
	 + ", Step = " + Step
	 + ", ro_r = " + ro_r
	 + ", ro_t = " + ro_t
	 + ", ro_u = " + ro_u
	 + ", ro_fr = " + ro_fr
	 + ", ro_ft = " + ro_ft
	 + ", ro_fu = " + ro_fu
	 + ", ro_ar = " + ro_ar
	 + ", ro_at = " + ro_at
	 + ", ro_au = " + ro_au
	 + ", ro_cmr = " + ro_cmr
	 + ", ro_cmt = " + ro_cmt
	 + ", ro_cmu = " + ro_cmu+"]";
  }
    
}
    
