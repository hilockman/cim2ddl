package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*可靠性公共参数	*
***********************/
public class CommRParam  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //设备类型
  private Integer DevType;
  
  //关键字
  private String KeyWord;
  
  //容量上限
  private Double UpCapLmt;
  
  //容量下限
  private Double DnCapLmt;
  
  //电压上限
  private Double UpVLmt;
  
  //电压下限
  private Double DnVLmt;
  
  //故障率
  private Double Rerr;
  
  //修复时间
  private Double Trep;
  
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
    
  public Integer getDevType()
  {
    return DevType;
  }
    
  public void setDevType(Integer DevType)
  {
    this.DevType = DevType;
  }
    
  public String getKeyWord()
  {
    return KeyWord;
  }
    
  public void setKeyWord(String KeyWord)
  {
    this.KeyWord = KeyWord;
  }
    
  public Double getUpCapLmt()
  {
    return UpCapLmt;
  }
    
  public void setUpCapLmt(Double UpCapLmt)
  {
    this.UpCapLmt = UpCapLmt;
  }
    
  public Double getDnCapLmt()
  {
    return DnCapLmt;
  }
    
  public void setDnCapLmt(Double DnCapLmt)
  {
    this.DnCapLmt = DnCapLmt;
  }
    
  public Double getUpVLmt()
  {
    return UpVLmt;
  }
    
  public void setUpVLmt(Double UpVLmt)
  {
    this.UpVLmt = UpVLmt;
  }
    
  public Double getDnVLmt()
  {
    return DnVLmt;
  }
    
  public void setDnVLmt(Double DnVLmt)
  {
    this.DnVLmt = DnVLmt;
  }
    
  public Double getRerr()
  {
    return Rerr;
  }
    
  public void setRerr(Double Rerr)
  {
    this.Rerr = Rerr;
  }
    
  public Double getTrep()
  {
    return Trep;
  }
    
  public void setTrep(Double Trep)
  {
    this.Trep = Trep;
  }
    
  public String toString()
  {
    return "CommRParam ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", DevType = " + DevType
	 + ", KeyWord = " + KeyWord
	 + ", UpCapLmt = " + UpCapLmt
	 + ", DnCapLmt = " + DnCapLmt
	 + ", UpVLmt = " + UpVLmt
	 + ", DnVLmt = " + DnVLmt
	 + ", Rerr = " + Rerr
	 + ", Trep = " + Trep+"]";
  }
    
}
    
