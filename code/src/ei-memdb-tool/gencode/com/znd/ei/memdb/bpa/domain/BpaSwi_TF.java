package com.znd.ei.memdb.bpa.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*双再热器汽轮机模型表(TF)	*
***********************/
public class BpaSwi_TF  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //卡类型
  private String CardKey;
  
  //发电机名称
  private String ACBus_Name;
  
  //发电机基准电压(kV)
  private Double ACBus_kV;
  
  //发电机识别码
  private Integer Gen_ID;
  
  //蒸汽容积时间常数(秒)
  private Double TF_TCH;
  
  //超高压缸功率比例
  private Double TF_FVHP;
  
  //第一再热器时间常数
  private Double TF_TRH1;
  
  //高压缸功率比例
  private Double TF_FHP;
  
  //第二再热器时间常数
  private Double TF_TRH2;
  
  //中压缸功率比例或比例一半
  private Double TF_FIP_1;
  
  //中压缸功率比例或比例一半
  private Double TF_FIP_2;
  
  //交叉管时间常数
  private Double TF_TCO;
  
  //低压缸功率比例或比例一半
  private Double TF_FLP_1;
  
  //低压缸功率比例或比例一半
  private Double TF_FLP_2;
  
  //数据库主键
  private String KeyName;
  
  //发电机母线索引
  private Integer BusPtr;
  
  //新增记录标记
  private Integer AppendTag;
  
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
    
  public Integer getGen_ID()
  {
    return Gen_ID;
  }
    
  public void setGen_ID(Integer Gen_ID)
  {
    this.Gen_ID = Gen_ID;
  }
    
  public Double getTF_TCH()
  {
    return TF_TCH;
  }
    
  public void setTF_TCH(Double TF_TCH)
  {
    this.TF_TCH = TF_TCH;
  }
    
  public Double getTF_FVHP()
  {
    return TF_FVHP;
  }
    
  public void setTF_FVHP(Double TF_FVHP)
  {
    this.TF_FVHP = TF_FVHP;
  }
    
  public Double getTF_TRH1()
  {
    return TF_TRH1;
  }
    
  public void setTF_TRH1(Double TF_TRH1)
  {
    this.TF_TRH1 = TF_TRH1;
  }
    
  public Double getTF_FHP()
  {
    return TF_FHP;
  }
    
  public void setTF_FHP(Double TF_FHP)
  {
    this.TF_FHP = TF_FHP;
  }
    
  public Double getTF_TRH2()
  {
    return TF_TRH2;
  }
    
  public void setTF_TRH2(Double TF_TRH2)
  {
    this.TF_TRH2 = TF_TRH2;
  }
    
  public Double getTF_FIP_1()
  {
    return TF_FIP_1;
  }
    
  public void setTF_FIP_1(Double TF_FIP_1)
  {
    this.TF_FIP_1 = TF_FIP_1;
  }
    
  public Double getTF_FIP_2()
  {
    return TF_FIP_2;
  }
    
  public void setTF_FIP_2(Double TF_FIP_2)
  {
    this.TF_FIP_2 = TF_FIP_2;
  }
    
  public Double getTF_TCO()
  {
    return TF_TCO;
  }
    
  public void setTF_TCO(Double TF_TCO)
  {
    this.TF_TCO = TF_TCO;
  }
    
  public Double getTF_FLP_1()
  {
    return TF_FLP_1;
  }
    
  public void setTF_FLP_1(Double TF_FLP_1)
  {
    this.TF_FLP_1 = TF_FLP_1;
  }
    
  public Double getTF_FLP_2()
  {
    return TF_FLP_2;
  }
    
  public void setTF_FLP_2(Double TF_FLP_2)
  {
    this.TF_FLP_2 = TF_FLP_2;
  }
    
  public String getKeyName()
  {
    return KeyName;
  }
    
  public void setKeyName(String KeyName)
  {
    this.KeyName = KeyName;
  }
    
  public Integer getBusPtr()
  {
    return BusPtr;
  }
    
  public void setBusPtr(Integer BusPtr)
  {
    this.BusPtr = BusPtr;
  }
    
  public Integer getAppendTag()
  {
    return AppendTag;
  }
    
  public void setAppendTag(Integer AppendTag)
  {
    this.AppendTag = AppendTag;
  }
    
  public String toString()
  {
    return "BpaSwi_TF ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", CardKey = " + CardKey
	 + ", ACBus_Name = " + ACBus_Name
	 + ", ACBus_kV = " + ACBus_kV
	 + ", Gen_ID = " + Gen_ID
	 + ", TF_TCH = " + TF_TCH
	 + ", TF_FVHP = " + TF_FVHP
	 + ", TF_TRH1 = " + TF_TRH1
	 + ", TF_FHP = " + TF_FHP
	 + ", TF_TRH2 = " + TF_TRH2
	 + ", TF_FIP_1 = " + TF_FIP_1
	 + ", TF_FIP_2 = " + TF_FIP_2
	 + ", TF_TCO = " + TF_TCO
	 + ", TF_FLP_1 = " + TF_FLP_1
	 + ", TF_FLP_2 = " + TF_FLP_2
	 + ", KeyName = " + KeyName
	 + ", BusPtr = " + BusPtr
	 + ", AppendTag = " + AppendTag+"]";
  }
    
}
    
