package com.znd.ei.memdb.reliabilty.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*可靠性公共参数	*
***********************/
@Entity
public class CommRParam
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  //设备类型
  private Integer devType;
  
  //关键字
  private String keyWord;
  
  //容量上限
  private Double upCapLmt;
  
  //容量下限
  private Double dnCapLmt;
  
  //电压上限
  private Double upVLmt;
  
  //电压下限
  private Double dnVLmt;
  
  //故障率
  private Double rerr;
  
  //修复时间
  private Double trep;
  
  public Integer getId() 
  {
    return id;
  }
    
  public void setId(Integer id)
  {
    this.id = id;
  }
    
  public Integer getDevType() 
  {
    return devType;
  }
    
  public void setDevType(Integer devType)
  {
    this.devType = devType;
  }
    
  public String getKeyWord() 
  {
    return keyWord;
  }
    
  public void setKeyWord(String keyWord)
  {
    this.keyWord = keyWord;
  }
    
  public Double getUpCapLmt() 
  {
    return upCapLmt;
  }
    
  public void setUpCapLmt(Double upCapLmt)
  {
    this.upCapLmt = upCapLmt;
  }
    
  public Double getDnCapLmt() 
  {
    return dnCapLmt;
  }
    
  public void setDnCapLmt(Double dnCapLmt)
  {
    this.dnCapLmt = dnCapLmt;
  }
    
  public Double getUpVLmt() 
  {
    return upVLmt;
  }
    
  public void setUpVLmt(Double upVLmt)
  {
    this.upVLmt = upVLmt;
  }
    
  public Double getDnVLmt() 
  {
    return dnVLmt;
  }
    
  public void setDnVLmt(Double dnVLmt)
  {
    this.dnVLmt = dnVLmt;
  }
    
  public Double getRerr() 
  {
    return rerr;
  }
    
  public void setRerr(Double rerr)
  {
    this.rerr = rerr;
  }
    
  public Double getTrep() 
  {
    return trep;
  }
    
  public void setTrep(Double trep)
  {
    this.trep = trep;
  }
    
}
    
