package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*计算节点	*
***********************/
public class TopoBus  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //岛
  private Integer Island;
  
  //有功发电(MW)
  private Double GenP;
  
  //无功发电(MVar)
  private Double GenQ;
  
  //有功负荷(MW)
  private Double LoadP;
  
  //无功负荷(MVar)
  private Double LoadQ;
  
  //并联无功(MVar)
  private Double ShuntQ;
  
  //电压(kV)
  private Double V;
  
  //功角(度)
  private Double D;
  
  //正序等值电阻(PU)
  private Double ScR1;
  
  //正序等值电抗(PU)
  private Double ScX1;
  
  //负序等值电阻(PU)
  private Double ScR2;
  
  //负序等值电抗(PU)
  private Double ScX2;
  
  //零序等值电阻(PU)
  private Double ScR0;
  
  //零序等值电抗(PU)
  private Double ScX0;
  
  //正序短路电流实部(PU)
  private Double ScI1Re;
  
  //正序短路电流虚部(PU)
  private Double ScI1Im;
  
  //负序短路电流实部(PU)
  private Double ScI2Re;
  
  //负序短路电流虚部(PU)
  private Double ScI2Im;
  
  //零序短路电流实部(PU)
  private Double ScI0Re;
  
  //零序短路电流虚部(PU)
  private Double ScI0Im;
  
  //正序短路电压实部(PU)
  private Double ScV1Re;
  
  //正序短路电压虚部(PU)
  private Double ScV1Im;
  
  //负序短路电压实部(PU)
  private Double ScV2Re;
  
  //负序短路电压虚部(PU)
  private Double ScV2Im;
  
  //零序短路电压实部(PU)
  private Double ScV0Re;
  
  //零序短路电压虚部(PU)
  private Double ScV0Im;
  
  //因母线故障引起的电压暂降数
  private Integer VDipNum;
  
  //电压等级索引
  private Integer VoltPtr;
  
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
    
  public Integer getIsland()
  {
    return Island;
  }
    
  public void setIsland(Integer Island)
  {
    this.Island = Island;
  }
    
  public Double getGenP()
  {
    return GenP;
  }
    
  public void setGenP(Double GenP)
  {
    this.GenP = GenP;
  }
    
  public Double getGenQ()
  {
    return GenQ;
  }
    
  public void setGenQ(Double GenQ)
  {
    this.GenQ = GenQ;
  }
    
  public Double getLoadP()
  {
    return LoadP;
  }
    
  public void setLoadP(Double LoadP)
  {
    this.LoadP = LoadP;
  }
    
  public Double getLoadQ()
  {
    return LoadQ;
  }
    
  public void setLoadQ(Double LoadQ)
  {
    this.LoadQ = LoadQ;
  }
    
  public Double getShuntQ()
  {
    return ShuntQ;
  }
    
  public void setShuntQ(Double ShuntQ)
  {
    this.ShuntQ = ShuntQ;
  }
    
  public Double getV()
  {
    return V;
  }
    
  public void setV(Double V)
  {
    this.V = V;
  }
    
  public Double getD()
  {
    return D;
  }
    
  public void setD(Double D)
  {
    this.D = D;
  }
    
  public Double getScR1()
  {
    return ScR1;
  }
    
  public void setScR1(Double ScR1)
  {
    this.ScR1 = ScR1;
  }
    
  public Double getScX1()
  {
    return ScX1;
  }
    
  public void setScX1(Double ScX1)
  {
    this.ScX1 = ScX1;
  }
    
  public Double getScR2()
  {
    return ScR2;
  }
    
  public void setScR2(Double ScR2)
  {
    this.ScR2 = ScR2;
  }
    
  public Double getScX2()
  {
    return ScX2;
  }
    
  public void setScX2(Double ScX2)
  {
    this.ScX2 = ScX2;
  }
    
  public Double getScR0()
  {
    return ScR0;
  }
    
  public void setScR0(Double ScR0)
  {
    this.ScR0 = ScR0;
  }
    
  public Double getScX0()
  {
    return ScX0;
  }
    
  public void setScX0(Double ScX0)
  {
    this.ScX0 = ScX0;
  }
    
  public Double getScI1Re()
  {
    return ScI1Re;
  }
    
  public void setScI1Re(Double ScI1Re)
  {
    this.ScI1Re = ScI1Re;
  }
    
  public Double getScI1Im()
  {
    return ScI1Im;
  }
    
  public void setScI1Im(Double ScI1Im)
  {
    this.ScI1Im = ScI1Im;
  }
    
  public Double getScI2Re()
  {
    return ScI2Re;
  }
    
  public void setScI2Re(Double ScI2Re)
  {
    this.ScI2Re = ScI2Re;
  }
    
  public Double getScI2Im()
  {
    return ScI2Im;
  }
    
  public void setScI2Im(Double ScI2Im)
  {
    this.ScI2Im = ScI2Im;
  }
    
  public Double getScI0Re()
  {
    return ScI0Re;
  }
    
  public void setScI0Re(Double ScI0Re)
  {
    this.ScI0Re = ScI0Re;
  }
    
  public Double getScI0Im()
  {
    return ScI0Im;
  }
    
  public void setScI0Im(Double ScI0Im)
  {
    this.ScI0Im = ScI0Im;
  }
    
  public Double getScV1Re()
  {
    return ScV1Re;
  }
    
  public void setScV1Re(Double ScV1Re)
  {
    this.ScV1Re = ScV1Re;
  }
    
  public Double getScV1Im()
  {
    return ScV1Im;
  }
    
  public void setScV1Im(Double ScV1Im)
  {
    this.ScV1Im = ScV1Im;
  }
    
  public Double getScV2Re()
  {
    return ScV2Re;
  }
    
  public void setScV2Re(Double ScV2Re)
  {
    this.ScV2Re = ScV2Re;
  }
    
  public Double getScV2Im()
  {
    return ScV2Im;
  }
    
  public void setScV2Im(Double ScV2Im)
  {
    this.ScV2Im = ScV2Im;
  }
    
  public Double getScV0Re()
  {
    return ScV0Re;
  }
    
  public void setScV0Re(Double ScV0Re)
  {
    this.ScV0Re = ScV0Re;
  }
    
  public Double getScV0Im()
  {
    return ScV0Im;
  }
    
  public void setScV0Im(Double ScV0Im)
  {
    this.ScV0Im = ScV0Im;
  }
    
  public Integer getVDipNum()
  {
    return VDipNum;
  }
    
  public void setVDipNum(Integer VDipNum)
  {
    this.VDipNum = VDipNum;
  }
    
  public Integer getVoltPtr()
  {
    return VoltPtr;
  }
    
  public void setVoltPtr(Integer VoltPtr)
  {
    this.VoltPtr = VoltPtr;
  }
    
  public String toString()
  {
    return "TopoBus ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Island = " + Island
	 + ", GenP = " + GenP
	 + ", GenQ = " + GenQ
	 + ", LoadP = " + LoadP
	 + ", LoadQ = " + LoadQ
	 + ", ShuntQ = " + ShuntQ
	 + ", V = " + V
	 + ", D = " + D
	 + ", ScR1 = " + ScR1
	 + ", ScX1 = " + ScX1
	 + ", ScR2 = " + ScR2
	 + ", ScX2 = " + ScX2
	 + ", ScR0 = " + ScR0
	 + ", ScX0 = " + ScX0
	 + ", ScI1Re = " + ScI1Re
	 + ", ScI1Im = " + ScI1Im
	 + ", ScI2Re = " + ScI2Re
	 + ", ScI2Im = " + ScI2Im
	 + ", ScI0Re = " + ScI0Re
	 + ", ScI0Im = " + ScI0Im
	 + ", ScV1Re = " + ScV1Re
	 + ", ScV1Im = " + ScV1Im
	 + ", ScV2Re = " + ScV2Re
	 + ", ScV2Im = " + ScV2Im
	 + ", ScV0Re = " + ScV0Re
	 + ", ScV0Im = " + ScV0Im
	 + ", VDipNum = " + VDipNum
	 + ", VoltPtr = " + VoltPtr+"]";
  }
    
}
    
