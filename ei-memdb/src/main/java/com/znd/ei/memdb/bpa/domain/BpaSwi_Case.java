package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*稳定计算控制卡(CASE)	*
***********************/
public class BpaSwi_Case  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //潮流方式名
  private String PFCASE;
  
  //写求解文件的步长
  private Integer ITSKP;
  
  //NOPRNT,为1时打印全部输入数据
  private Integer NOPRNT;
  
  //输出文件摇摆曲线显示开关
  private Integer DSW;
  
  //采用新减负荷卡减负荷标记
  private Integer IWSCC;
  
  //对零序卡进行检查标志
  private Integer ZSW;
  
  //不对称故障时发电机X2与Xdp之比
  private Double X2FAC;
  
  //发电机Xdpp与Xdp之比
  private Double XFACT;
  
  //隐级机的Tdopp(秒)
  private Double TDODPS;
  
  //隐级机的Tdopp(秒)
  private Double TQODPS;
  
  //凸级水轮机的Tqopp(秒)
  private Double TDODPH;
  
  //凸级水轮机的Tdopp(秒)
  private Double TQODPH;
  
  //负序负荷导纳(pu)
  private Double CFACL2;
  
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
    
  public String getPFCASE()
  {
    return PFCASE;
  }
    
  public void setPFCASE(String PFCASE)
  {
    this.PFCASE = PFCASE;
  }
    
  public Integer getITSKP()
  {
    return ITSKP;
  }
    
  public void setITSKP(Integer ITSKP)
  {
    this.ITSKP = ITSKP;
  }
    
  public Integer getNOPRNT()
  {
    return NOPRNT;
  }
    
  public void setNOPRNT(Integer NOPRNT)
  {
    this.NOPRNT = NOPRNT;
  }
    
  public Integer getDSW()
  {
    return DSW;
  }
    
  public void setDSW(Integer DSW)
  {
    this.DSW = DSW;
  }
    
  public Integer getIWSCC()
  {
    return IWSCC;
  }
    
  public void setIWSCC(Integer IWSCC)
  {
    this.IWSCC = IWSCC;
  }
    
  public Integer getZSW()
  {
    return ZSW;
  }
    
  public void setZSW(Integer ZSW)
  {
    this.ZSW = ZSW;
  }
    
  public Double getX2FAC()
  {
    return X2FAC;
  }
    
  public void setX2FAC(Double X2FAC)
  {
    this.X2FAC = X2FAC;
  }
    
  public Double getXFACT()
  {
    return XFACT;
  }
    
  public void setXFACT(Double XFACT)
  {
    this.XFACT = XFACT;
  }
    
  public Double getTDODPS()
  {
    return TDODPS;
  }
    
  public void setTDODPS(Double TDODPS)
  {
    this.TDODPS = TDODPS;
  }
    
  public Double getTQODPS()
  {
    return TQODPS;
  }
    
  public void setTQODPS(Double TQODPS)
  {
    this.TQODPS = TQODPS;
  }
    
  public Double getTDODPH()
  {
    return TDODPH;
  }
    
  public void setTDODPH(Double TDODPH)
  {
    this.TDODPH = TDODPH;
  }
    
  public Double getTQODPH()
  {
    return TQODPH;
  }
    
  public void setTQODPH(Double TQODPH)
  {
    this.TQODPH = TQODPH;
  }
    
  public Double getCFACL2()
  {
    return CFACL2;
  }
    
  public void setCFACL2(Double CFACL2)
  {
    this.CFACL2 = CFACL2;
  }
    
  public String toString()
  {
    return "BpaSwi_Case ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", PFCASE = " + PFCASE
	 + ", ITSKP = " + ITSKP
	 + ", NOPRNT = " + NOPRNT
	 + ", DSW = " + DSW
	 + ", IWSCC = " + IWSCC
	 + ", ZSW = " + ZSW
	 + ", X2FAC = " + X2FAC
	 + ", XFACT = " + XFACT
	 + ", TDODPS = " + TDODPS
	 + ", TQODPS = " + TQODPS
	 + ", TDODPH = " + TDODPH
	 + ", TQODPH = " + TQODPH
	 + ", CFACL2 = " + CFACL2+"]";
  }
    
}
    
