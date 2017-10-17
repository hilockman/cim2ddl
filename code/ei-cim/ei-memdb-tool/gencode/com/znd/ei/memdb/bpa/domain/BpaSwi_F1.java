package com.znd.ei.memdb.bpa.domain;


/**********************
*稳定计算控制继续卡(F1)	*
***********************/
public class BpaSwi_F1
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String cardKey;
  
  //母线频率滤波器缺省时间常数
  private Double tBUSF;
  
  //测量回路缺省时间常数
  private Double tZERO;
  
  //母线负荷开关
  private Integer iBLOD;
  
  //缺省发电机阻尼因子
  private Double dMPALL;
  
  //如果该值不为0,且F1卡中的XFACT也不为0,无论发电机的次暂态参数是否已经用M卡指定,都要采用缺省的参数来计算发电机的次暂态参数
  private Integer iAMRTS;
  
  //如果负荷母线电压低于该值,则负荷将转换为恒阻抗负荷,缺省值为0.5pu
  private Double vCHGL;
  
  //SP卡为以加速功率作为输入信号的PSS,而SG卡为以电磁功率为输入信号的PSS;如果该值不为0,则将稳定数据中所有的SP卡改为SG卡
  private Integer sPTOSG;
  
  //如果该值不为零,则数据文件中所有GH卡和GS卡的死区的大小都为该值
  private Double gSIQU;
  
  //从本时间开始,按照本卡中的48-49列填写的步数进行存储
  private Double tITSKP;
  
  //从本卡43-47列规定的时间TITSKP开始每隔ITSKP1步存储一次数据
  private Integer iTSKP1;
  
  //FM、FO、FP、FQ、FR、FS、FT和FG型励磁模型的调压器限幅环节为外限幅,如果VRLIM不为0,则将其改为内限幅
  private Integer vRLIM;
  
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
    
  public Double getTBUSF()
  {
    return tBUSF;
  }
    
  public void setTBUSF(Double tBUSF)
  {
    this.tBUSF = tBUSF;
  }
    
  public Double getTZERO()
  {
    return tZERO;
  }
    
  public void setTZERO(Double tZERO)
  {
    this.tZERO = tZERO;
  }
    
  public Integer getIBLOD()
  {
    return iBLOD;
  }
    
  public void setIBLOD(Integer iBLOD)
  {
    this.iBLOD = iBLOD;
  }
    
  public Double getDMPALL()
  {
    return dMPALL;
  }
    
  public void setDMPALL(Double dMPALL)
  {
    this.dMPALL = dMPALL;
  }
    
  public Integer getIAMRTS()
  {
    return iAMRTS;
  }
    
  public void setIAMRTS(Integer iAMRTS)
  {
    this.iAMRTS = iAMRTS;
  }
    
  public Double getVCHGL()
  {
    return vCHGL;
  }
    
  public void setVCHGL(Double vCHGL)
  {
    this.vCHGL = vCHGL;
  }
    
  public Integer getSPTOSG()
  {
    return sPTOSG;
  }
    
  public void setSPTOSG(Integer sPTOSG)
  {
    this.sPTOSG = sPTOSG;
  }
    
  public Double getGSIQU()
  {
    return gSIQU;
  }
    
  public void setGSIQU(Double gSIQU)
  {
    this.gSIQU = gSIQU;
  }
    
  public Double getTITSKP()
  {
    return tITSKP;
  }
    
  public void setTITSKP(Double tITSKP)
  {
    this.tITSKP = tITSKP;
  }
    
  public Integer getITSKP1()
  {
    return iTSKP1;
  }
    
  public void setITSKP1(Integer iTSKP1)
  {
    this.iTSKP1 = iTSKP1;
  }
    
  public Integer getVRLIM()
  {
    return vRLIM;
  }
    
  public void setVRLIM(Integer vRLIM)
  {
    this.vRLIM = vRLIM;
  }
    
  public String toString()
  {
    return "BpaSwi_F1 ["+	"id"=id,
	"memIndex"=memIndex,
	"cardKey"=cardKey,
	"tBUSF"=tBUSF,
	"tZERO"=tZERO,
	"iBLOD"=iBLOD,
	"dMPALL"=dMPALL,
	"iAMRTS"=iAMRTS,
	"vCHGL"=vCHGL,
	"sPTOSG"=sPTOSG,
	"gSIQU"=gSIQU,
	"tITSKP"=tITSKP,
	"iTSKP1"=iTSKP1,
	"vRLIM"=vRLIM+"]"
  }
    
}
    
