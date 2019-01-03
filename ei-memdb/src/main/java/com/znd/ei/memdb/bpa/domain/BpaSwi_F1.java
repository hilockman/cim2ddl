package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*稳定计算控制继续卡(F1)	*
***********************/
public class BpaSwi_F1  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //母线频率滤波器缺省时间常数
  private Double TBUSF;
  
  //测量回路缺省时间常数
  private Double TZERO;
  
  //母线负荷开关
  private Integer IBLOD;
  
  //缺省发电机阻尼因子
  private Double DMPALL;
  
  //如果该值不为0,且F1卡中的XFACT也不为0,无论发电机的次暂态参数是否已经用M卡指定,都要采用缺省的参数来计算发电机的次暂态参数
  private Integer IAMRTS;
  
  //如果负荷母线电压低于该值,则负荷将转换为恒阻抗负荷,缺省值为0.5pu
  private Double VCHGL;
  
  //SP卡为以加速功率作为输入信号的PSS,而SG卡为以电磁功率为输入信号的PSS;如果该值不为0,则将稳定数据中所有的SP卡改为SG卡
  private Integer SPTOSG;
  
  //如果该值不为零,则数据文件中所有GH卡和GS卡的死区的大小都为该值
  private Double GSIQU;
  
  //从本时间开始,按照本卡中的48-49列填写的步数进行存储
  private Double TITSKP;
  
  //从本卡43-47列规定的时间TITSKP开始每隔ITSKP1步存储一次数据
  private Integer ITSKP1;
  
  //FM、FO、FP、FQ、FR、FS、FT和FG型励磁模型的调压器限幅环节为外限幅,如果VRLIM不为0,则将其改为内限幅
  private Integer VRLIM;
  
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
    
  public Double getTBUSF()
  {
    return TBUSF;
  }
    
  public void setTBUSF(Double TBUSF)
  {
    this.TBUSF = TBUSF;
  }
    
  public Double getTZERO()
  {
    return TZERO;
  }
    
  public void setTZERO(Double TZERO)
  {
    this.TZERO = TZERO;
  }
    
  public Integer getIBLOD()
  {
    return IBLOD;
  }
    
  public void setIBLOD(Integer IBLOD)
  {
    this.IBLOD = IBLOD;
  }
    
  public Double getDMPALL()
  {
    return DMPALL;
  }
    
  public void setDMPALL(Double DMPALL)
  {
    this.DMPALL = DMPALL;
  }
    
  public Integer getIAMRTS()
  {
    return IAMRTS;
  }
    
  public void setIAMRTS(Integer IAMRTS)
  {
    this.IAMRTS = IAMRTS;
  }
    
  public Double getVCHGL()
  {
    return VCHGL;
  }
    
  public void setVCHGL(Double VCHGL)
  {
    this.VCHGL = VCHGL;
  }
    
  public Integer getSPTOSG()
  {
    return SPTOSG;
  }
    
  public void setSPTOSG(Integer SPTOSG)
  {
    this.SPTOSG = SPTOSG;
  }
    
  public Double getGSIQU()
  {
    return GSIQU;
  }
    
  public void setGSIQU(Double GSIQU)
  {
    this.GSIQU = GSIQU;
  }
    
  public Double getTITSKP()
  {
    return TITSKP;
  }
    
  public void setTITSKP(Double TITSKP)
  {
    this.TITSKP = TITSKP;
  }
    
  public Integer getITSKP1()
  {
    return ITSKP1;
  }
    
  public void setITSKP1(Integer ITSKP1)
  {
    this.ITSKP1 = ITSKP1;
  }
    
  public Integer getVRLIM()
  {
    return VRLIM;
  }
    
  public void setVRLIM(Integer VRLIM)
  {
    this.VRLIM = VRLIM;
  }
    
  public String toString()
  {
    return "BpaSwi_F1 ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", TBUSF = " + TBUSF
	 + ", TZERO = " + TZERO
	 + ", IBLOD = " + IBLOD
	 + ", DMPALL = " + DMPALL
	 + ", IAMRTS = " + IAMRTS
	 + ", VCHGL = " + VCHGL
	 + ", SPTOSG = " + SPTOSG
	 + ", GSIQU = " + GSIQU
	 + ", TITSKP = " + TITSKP
	 + ", ITSKP1 = " + ITSKP1
	 + ", VRLIM = " + VRLIM+"]";
  }
    
}
    
