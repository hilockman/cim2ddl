package com.znd.ei.memdb.reliabilty.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*设备多状态	*
***********************/
public class DevMState  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //设备类型
  private Integer Type;
  
  //设备名称
  private String Name;
  
  //状态数
  private Integer StateNum;
  
  //状态1出力(比率)
  private Double State1Rate;
  
  //状态2出力(比率)
  private Double State2Rate;
  
  //状态3出力(比率)
  private Double State3Rate;
  
  //状态4出力(比率)
  private Double State4Rate;
  
  //状态5出力(比率)
  private Double State5Rate;
  
  //状态6出力(比率)
  private Double State6Rate;
  
  //状态7出力(比率)
  private Double State7Rate;
  
  //状态8出力(比率)
  private Double State8Rate;
  
  //状态1概率
  private Double State1Prob;
  
  //状态2概率
  private Double State2Prob;
  
  //状态3概率
  private Double State3Prob;
  
  //状态4概率
  private Double State4Prob;
  
  //状态5概率
  private Double State5Prob;
  
  //状态6概率
  private Double State6Prob;
  
  //状态7概率
  private Double State7Prob;
  
  //状态8概率
  private Double State8Prob;
  
  //状态1-1转移率(次/年)
  private Double State1Freq1;
  
  //状态1-2转移率(次/年)
  private Double State1Freq2;
  
  //状态1-3转移率(次/年)
  private Double State1Freq3;
  
  //状态1-4转移率(次/年)
  private Double State1Freq4;
  
  //状态1-5转移率(次/年)
  private Double State1Freq5;
  
  //状态1-6转移率(次/年)
  private Double State1Freq6;
  
  //状态1-7转移率(次/年)
  private Double State1Freq7;
  
  //状态1-8转移率(次/年)
  private Double State1Freq8;
  
  //状态2-1转移率(次/年)
  private Double State2Freq1;
  
  //状态2-2转移率(次/年)
  private Double State2Freq2;
  
  //状态2-3转移率(次/年)
  private Double State2Freq3;
  
  //状态2-4转移率(次/年)
  private Double State2Freq4;
  
  //状态2-5转移率(次/年)
  private Double State2Freq5;
  
  //状态2-6转移率(次/年)
  private Double State2Freq6;
  
  //状态2-7转移率(次/年)
  private Double State2Freq7;
  
  //状态2-8转移率(次/年)
  private Double State2Freq8;
  
  //状态3-1转移率(次/年)
  private Double State3Freq1;
  
  //状态3-2转移率(次/年)
  private Double State3Freq2;
  
  //状态3-3转移率(次/年)
  private Double State3Freq3;
  
  //状态3-4转移率(次/年)
  private Double State3Freq4;
  
  //状态3-5转移率(次/年)
  private Double State3Freq5;
  
  //状态3-6转移率(次/年)
  private Double State3Freq6;
  
  //状态3-7转移率(次/年)
  private Double State3Freq7;
  
  //状态3-8转移率(次/年)
  private Double State3Freq8;
  
  //状态4-1转移率(次/年)
  private Double State4Freq1;
  
  //状态4-2转移率(次/年)
  private Double State4Freq2;
  
  //状态4-3转移率(次/年)
  private Double State4Freq3;
  
  //状态4-4转移率(次/年)
  private Double State4Freq4;
  
  //状态4-5转移率(次/年)
  private Double State4Freq5;
  
  //状态4-6转移率(次/年)
  private Double State4Freq6;
  
  //状态4-7转移率(次/年)
  private Double State4Freq7;
  
  //状态4-8转移率(次/年)
  private Double State4Freq8;
  
  //状态5-1转移率(次/年)
  private Double State5Freq1;
  
  //状态5-2转移率(次/年)
  private Double State5Freq2;
  
  //状态5-3转移率(次/年)
  private Double State5Freq3;
  
  //状态5-4转移率(次/年)
  private Double State5Freq4;
  
  //状态5-5转移率(次/年)
  private Double State5Freq5;
  
  //状态5-6转移率(次/年)
  private Double State5Freq6;
  
  //状态5-7转移率(次/年)
  private Double State5Freq7;
  
  //状态5-8转移率(次/年)
  private Double State5Freq8;
  
  //状态6-1转移率(次/年)
  private Double State6Freq1;
  
  //状态6-2转移率(次/年)
  private Double State6Freq2;
  
  //状态6-3转移率(次/年)
  private Double State6Freq3;
  
  //状态6-4转移率(次/年)
  private Double State6Freq4;
  
  //状态6-5转移率(次/年)
  private Double State6Freq5;
  
  //状态6-6转移率(次/年)
  private Double State6Freq6;
  
  //状态6-7转移率(次/年)
  private Double State6Freq7;
  
  //状态6-8转移率(次/年)
  private Double State6Freq8;
  
  //状态7-1转移率(次/年)
  private Double State7Freq1;
  
  //状态7-2转移率(次/年)
  private Double State7Freq2;
  
  //状态7-3转移率(次/年)
  private Double State7Freq3;
  
  //状态7-4转移率(次/年)
  private Double State7Freq4;
  
  //状态7-5转移率(次/年)
  private Double State7Freq5;
  
  //状态7-6转移率(次/年)
  private Double State7Freq6;
  
  //状态7-7转移率(次/年)
  private Double State7Freq7;
  
  //状态7-8转移率(次/年)
  private Double State7Freq8;
  
  //状态8-1转移率(次/年)
  private Double State8Freq1;
  
  //状态8-2转移率(次/年)
  private Double State8Freq2;
  
  //状态8-3转移率(次/年)
  private Double State8Freq3;
  
  //状态8-4转移率(次/年)
  private Double State8Freq4;
  
  //状态8-5转移率(次/年)
  private Double State8Freq5;
  
  //状态8-6转移率(次/年)
  private Double State8Freq6;
  
  //状态8-7转移率(次/年)
  private Double State8Freq7;
  
  //状态8-8转移率(次/年)
  private Double State8Freq8;
  
  //设备索引
  private Integer SerialNo;
  
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
    
  public Integer getType()
  {
    return Type;
  }
    
  public void setType(Integer Type)
  {
    this.Type = Type;
  }
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public Integer getStateNum()
  {
    return StateNum;
  }
    
  public void setStateNum(Integer StateNum)
  {
    this.StateNum = StateNum;
  }
    
  public Double getState1Rate()
  {
    return State1Rate;
  }
    
  public void setState1Rate(Double State1Rate)
  {
    this.State1Rate = State1Rate;
  }
    
  public Double getState2Rate()
  {
    return State2Rate;
  }
    
  public void setState2Rate(Double State2Rate)
  {
    this.State2Rate = State2Rate;
  }
    
  public Double getState3Rate()
  {
    return State3Rate;
  }
    
  public void setState3Rate(Double State3Rate)
  {
    this.State3Rate = State3Rate;
  }
    
  public Double getState4Rate()
  {
    return State4Rate;
  }
    
  public void setState4Rate(Double State4Rate)
  {
    this.State4Rate = State4Rate;
  }
    
  public Double getState5Rate()
  {
    return State5Rate;
  }
    
  public void setState5Rate(Double State5Rate)
  {
    this.State5Rate = State5Rate;
  }
    
  public Double getState6Rate()
  {
    return State6Rate;
  }
    
  public void setState6Rate(Double State6Rate)
  {
    this.State6Rate = State6Rate;
  }
    
  public Double getState7Rate()
  {
    return State7Rate;
  }
    
  public void setState7Rate(Double State7Rate)
  {
    this.State7Rate = State7Rate;
  }
    
  public Double getState8Rate()
  {
    return State8Rate;
  }
    
  public void setState8Rate(Double State8Rate)
  {
    this.State8Rate = State8Rate;
  }
    
  public Double getState1Prob()
  {
    return State1Prob;
  }
    
  public void setState1Prob(Double State1Prob)
  {
    this.State1Prob = State1Prob;
  }
    
  public Double getState2Prob()
  {
    return State2Prob;
  }
    
  public void setState2Prob(Double State2Prob)
  {
    this.State2Prob = State2Prob;
  }
    
  public Double getState3Prob()
  {
    return State3Prob;
  }
    
  public void setState3Prob(Double State3Prob)
  {
    this.State3Prob = State3Prob;
  }
    
  public Double getState4Prob()
  {
    return State4Prob;
  }
    
  public void setState4Prob(Double State4Prob)
  {
    this.State4Prob = State4Prob;
  }
    
  public Double getState5Prob()
  {
    return State5Prob;
  }
    
  public void setState5Prob(Double State5Prob)
  {
    this.State5Prob = State5Prob;
  }
    
  public Double getState6Prob()
  {
    return State6Prob;
  }
    
  public void setState6Prob(Double State6Prob)
  {
    this.State6Prob = State6Prob;
  }
    
  public Double getState7Prob()
  {
    return State7Prob;
  }
    
  public void setState7Prob(Double State7Prob)
  {
    this.State7Prob = State7Prob;
  }
    
  public Double getState8Prob()
  {
    return State8Prob;
  }
    
  public void setState8Prob(Double State8Prob)
  {
    this.State8Prob = State8Prob;
  }
    
  public Double getState1Freq1()
  {
    return State1Freq1;
  }
    
  public void setState1Freq1(Double State1Freq1)
  {
    this.State1Freq1 = State1Freq1;
  }
    
  public Double getState1Freq2()
  {
    return State1Freq2;
  }
    
  public void setState1Freq2(Double State1Freq2)
  {
    this.State1Freq2 = State1Freq2;
  }
    
  public Double getState1Freq3()
  {
    return State1Freq3;
  }
    
  public void setState1Freq3(Double State1Freq3)
  {
    this.State1Freq3 = State1Freq3;
  }
    
  public Double getState1Freq4()
  {
    return State1Freq4;
  }
    
  public void setState1Freq4(Double State1Freq4)
  {
    this.State1Freq4 = State1Freq4;
  }
    
  public Double getState1Freq5()
  {
    return State1Freq5;
  }
    
  public void setState1Freq5(Double State1Freq5)
  {
    this.State1Freq5 = State1Freq5;
  }
    
  public Double getState1Freq6()
  {
    return State1Freq6;
  }
    
  public void setState1Freq6(Double State1Freq6)
  {
    this.State1Freq6 = State1Freq6;
  }
    
  public Double getState1Freq7()
  {
    return State1Freq7;
  }
    
  public void setState1Freq7(Double State1Freq7)
  {
    this.State1Freq7 = State1Freq7;
  }
    
  public Double getState1Freq8()
  {
    return State1Freq8;
  }
    
  public void setState1Freq8(Double State1Freq8)
  {
    this.State1Freq8 = State1Freq8;
  }
    
  public Double getState2Freq1()
  {
    return State2Freq1;
  }
    
  public void setState2Freq1(Double State2Freq1)
  {
    this.State2Freq1 = State2Freq1;
  }
    
  public Double getState2Freq2()
  {
    return State2Freq2;
  }
    
  public void setState2Freq2(Double State2Freq2)
  {
    this.State2Freq2 = State2Freq2;
  }
    
  public Double getState2Freq3()
  {
    return State2Freq3;
  }
    
  public void setState2Freq3(Double State2Freq3)
  {
    this.State2Freq3 = State2Freq3;
  }
    
  public Double getState2Freq4()
  {
    return State2Freq4;
  }
    
  public void setState2Freq4(Double State2Freq4)
  {
    this.State2Freq4 = State2Freq4;
  }
    
  public Double getState2Freq5()
  {
    return State2Freq5;
  }
    
  public void setState2Freq5(Double State2Freq5)
  {
    this.State2Freq5 = State2Freq5;
  }
    
  public Double getState2Freq6()
  {
    return State2Freq6;
  }
    
  public void setState2Freq6(Double State2Freq6)
  {
    this.State2Freq6 = State2Freq6;
  }
    
  public Double getState2Freq7()
  {
    return State2Freq7;
  }
    
  public void setState2Freq7(Double State2Freq7)
  {
    this.State2Freq7 = State2Freq7;
  }
    
  public Double getState2Freq8()
  {
    return State2Freq8;
  }
    
  public void setState2Freq8(Double State2Freq8)
  {
    this.State2Freq8 = State2Freq8;
  }
    
  public Double getState3Freq1()
  {
    return State3Freq1;
  }
    
  public void setState3Freq1(Double State3Freq1)
  {
    this.State3Freq1 = State3Freq1;
  }
    
  public Double getState3Freq2()
  {
    return State3Freq2;
  }
    
  public void setState3Freq2(Double State3Freq2)
  {
    this.State3Freq2 = State3Freq2;
  }
    
  public Double getState3Freq3()
  {
    return State3Freq3;
  }
    
  public void setState3Freq3(Double State3Freq3)
  {
    this.State3Freq3 = State3Freq3;
  }
    
  public Double getState3Freq4()
  {
    return State3Freq4;
  }
    
  public void setState3Freq4(Double State3Freq4)
  {
    this.State3Freq4 = State3Freq4;
  }
    
  public Double getState3Freq5()
  {
    return State3Freq5;
  }
    
  public void setState3Freq5(Double State3Freq5)
  {
    this.State3Freq5 = State3Freq5;
  }
    
  public Double getState3Freq6()
  {
    return State3Freq6;
  }
    
  public void setState3Freq6(Double State3Freq6)
  {
    this.State3Freq6 = State3Freq6;
  }
    
  public Double getState3Freq7()
  {
    return State3Freq7;
  }
    
  public void setState3Freq7(Double State3Freq7)
  {
    this.State3Freq7 = State3Freq7;
  }
    
  public Double getState3Freq8()
  {
    return State3Freq8;
  }
    
  public void setState3Freq8(Double State3Freq8)
  {
    this.State3Freq8 = State3Freq8;
  }
    
  public Double getState4Freq1()
  {
    return State4Freq1;
  }
    
  public void setState4Freq1(Double State4Freq1)
  {
    this.State4Freq1 = State4Freq1;
  }
    
  public Double getState4Freq2()
  {
    return State4Freq2;
  }
    
  public void setState4Freq2(Double State4Freq2)
  {
    this.State4Freq2 = State4Freq2;
  }
    
  public Double getState4Freq3()
  {
    return State4Freq3;
  }
    
  public void setState4Freq3(Double State4Freq3)
  {
    this.State4Freq3 = State4Freq3;
  }
    
  public Double getState4Freq4()
  {
    return State4Freq4;
  }
    
  public void setState4Freq4(Double State4Freq4)
  {
    this.State4Freq4 = State4Freq4;
  }
    
  public Double getState4Freq5()
  {
    return State4Freq5;
  }
    
  public void setState4Freq5(Double State4Freq5)
  {
    this.State4Freq5 = State4Freq5;
  }
    
  public Double getState4Freq6()
  {
    return State4Freq6;
  }
    
  public void setState4Freq6(Double State4Freq6)
  {
    this.State4Freq6 = State4Freq6;
  }
    
  public Double getState4Freq7()
  {
    return State4Freq7;
  }
    
  public void setState4Freq7(Double State4Freq7)
  {
    this.State4Freq7 = State4Freq7;
  }
    
  public Double getState4Freq8()
  {
    return State4Freq8;
  }
    
  public void setState4Freq8(Double State4Freq8)
  {
    this.State4Freq8 = State4Freq8;
  }
    
  public Double getState5Freq1()
  {
    return State5Freq1;
  }
    
  public void setState5Freq1(Double State5Freq1)
  {
    this.State5Freq1 = State5Freq1;
  }
    
  public Double getState5Freq2()
  {
    return State5Freq2;
  }
    
  public void setState5Freq2(Double State5Freq2)
  {
    this.State5Freq2 = State5Freq2;
  }
    
  public Double getState5Freq3()
  {
    return State5Freq3;
  }
    
  public void setState5Freq3(Double State5Freq3)
  {
    this.State5Freq3 = State5Freq3;
  }
    
  public Double getState5Freq4()
  {
    return State5Freq4;
  }
    
  public void setState5Freq4(Double State5Freq4)
  {
    this.State5Freq4 = State5Freq4;
  }
    
  public Double getState5Freq5()
  {
    return State5Freq5;
  }
    
  public void setState5Freq5(Double State5Freq5)
  {
    this.State5Freq5 = State5Freq5;
  }
    
  public Double getState5Freq6()
  {
    return State5Freq6;
  }
    
  public void setState5Freq6(Double State5Freq6)
  {
    this.State5Freq6 = State5Freq6;
  }
    
  public Double getState5Freq7()
  {
    return State5Freq7;
  }
    
  public void setState5Freq7(Double State5Freq7)
  {
    this.State5Freq7 = State5Freq7;
  }
    
  public Double getState5Freq8()
  {
    return State5Freq8;
  }
    
  public void setState5Freq8(Double State5Freq8)
  {
    this.State5Freq8 = State5Freq8;
  }
    
  public Double getState6Freq1()
  {
    return State6Freq1;
  }
    
  public void setState6Freq1(Double State6Freq1)
  {
    this.State6Freq1 = State6Freq1;
  }
    
  public Double getState6Freq2()
  {
    return State6Freq2;
  }
    
  public void setState6Freq2(Double State6Freq2)
  {
    this.State6Freq2 = State6Freq2;
  }
    
  public Double getState6Freq3()
  {
    return State6Freq3;
  }
    
  public void setState6Freq3(Double State6Freq3)
  {
    this.State6Freq3 = State6Freq3;
  }
    
  public Double getState6Freq4()
  {
    return State6Freq4;
  }
    
  public void setState6Freq4(Double State6Freq4)
  {
    this.State6Freq4 = State6Freq4;
  }
    
  public Double getState6Freq5()
  {
    return State6Freq5;
  }
    
  public void setState6Freq5(Double State6Freq5)
  {
    this.State6Freq5 = State6Freq5;
  }
    
  public Double getState6Freq6()
  {
    return State6Freq6;
  }
    
  public void setState6Freq6(Double State6Freq6)
  {
    this.State6Freq6 = State6Freq6;
  }
    
  public Double getState6Freq7()
  {
    return State6Freq7;
  }
    
  public void setState6Freq7(Double State6Freq7)
  {
    this.State6Freq7 = State6Freq7;
  }
    
  public Double getState6Freq8()
  {
    return State6Freq8;
  }
    
  public void setState6Freq8(Double State6Freq8)
  {
    this.State6Freq8 = State6Freq8;
  }
    
  public Double getState7Freq1()
  {
    return State7Freq1;
  }
    
  public void setState7Freq1(Double State7Freq1)
  {
    this.State7Freq1 = State7Freq1;
  }
    
  public Double getState7Freq2()
  {
    return State7Freq2;
  }
    
  public void setState7Freq2(Double State7Freq2)
  {
    this.State7Freq2 = State7Freq2;
  }
    
  public Double getState7Freq3()
  {
    return State7Freq3;
  }
    
  public void setState7Freq3(Double State7Freq3)
  {
    this.State7Freq3 = State7Freq3;
  }
    
  public Double getState7Freq4()
  {
    return State7Freq4;
  }
    
  public void setState7Freq4(Double State7Freq4)
  {
    this.State7Freq4 = State7Freq4;
  }
    
  public Double getState7Freq5()
  {
    return State7Freq5;
  }
    
  public void setState7Freq5(Double State7Freq5)
  {
    this.State7Freq5 = State7Freq5;
  }
    
  public Double getState7Freq6()
  {
    return State7Freq6;
  }
    
  public void setState7Freq6(Double State7Freq6)
  {
    this.State7Freq6 = State7Freq6;
  }
    
  public Double getState7Freq7()
  {
    return State7Freq7;
  }
    
  public void setState7Freq7(Double State7Freq7)
  {
    this.State7Freq7 = State7Freq7;
  }
    
  public Double getState7Freq8()
  {
    return State7Freq8;
  }
    
  public void setState7Freq8(Double State7Freq8)
  {
    this.State7Freq8 = State7Freq8;
  }
    
  public Double getState8Freq1()
  {
    return State8Freq1;
  }
    
  public void setState8Freq1(Double State8Freq1)
  {
    this.State8Freq1 = State8Freq1;
  }
    
  public Double getState8Freq2()
  {
    return State8Freq2;
  }
    
  public void setState8Freq2(Double State8Freq2)
  {
    this.State8Freq2 = State8Freq2;
  }
    
  public Double getState8Freq3()
  {
    return State8Freq3;
  }
    
  public void setState8Freq3(Double State8Freq3)
  {
    this.State8Freq3 = State8Freq3;
  }
    
  public Double getState8Freq4()
  {
    return State8Freq4;
  }
    
  public void setState8Freq4(Double State8Freq4)
  {
    this.State8Freq4 = State8Freq4;
  }
    
  public Double getState8Freq5()
  {
    return State8Freq5;
  }
    
  public void setState8Freq5(Double State8Freq5)
  {
    this.State8Freq5 = State8Freq5;
  }
    
  public Double getState8Freq6()
  {
    return State8Freq6;
  }
    
  public void setState8Freq6(Double State8Freq6)
  {
    this.State8Freq6 = State8Freq6;
  }
    
  public Double getState8Freq7()
  {
    return State8Freq7;
  }
    
  public void setState8Freq7(Double State8Freq7)
  {
    this.State8Freq7 = State8Freq7;
  }
    
  public Double getState8Freq8()
  {
    return State8Freq8;
  }
    
  public void setState8Freq8(Double State8Freq8)
  {
    this.State8Freq8 = State8Freq8;
  }
    
  public Integer getSerialNo()
  {
    return SerialNo;
  }
    
  public void setSerialNo(Integer SerialNo)
  {
    this.SerialNo = SerialNo;
  }
    
  public String toString()
  {
    return "DevMState ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", Type = " + Type
	 + ", Name = " + Name
	 + ", StateNum = " + StateNum
	 + ", State1Rate = " + State1Rate
	 + ", State2Rate = " + State2Rate
	 + ", State3Rate = " + State3Rate
	 + ", State4Rate = " + State4Rate
	 + ", State5Rate = " + State5Rate
	 + ", State6Rate = " + State6Rate
	 + ", State7Rate = " + State7Rate
	 + ", State8Rate = " + State8Rate
	 + ", State1Prob = " + State1Prob
	 + ", State2Prob = " + State2Prob
	 + ", State3Prob = " + State3Prob
	 + ", State4Prob = " + State4Prob
	 + ", State5Prob = " + State5Prob
	 + ", State6Prob = " + State6Prob
	 + ", State7Prob = " + State7Prob
	 + ", State8Prob = " + State8Prob
	 + ", State1Freq1 = " + State1Freq1
	 + ", State1Freq2 = " + State1Freq2
	 + ", State1Freq3 = " + State1Freq3
	 + ", State1Freq4 = " + State1Freq4
	 + ", State1Freq5 = " + State1Freq5
	 + ", State1Freq6 = " + State1Freq6
	 + ", State1Freq7 = " + State1Freq7
	 + ", State1Freq8 = " + State1Freq8
	 + ", State2Freq1 = " + State2Freq1
	 + ", State2Freq2 = " + State2Freq2
	 + ", State2Freq3 = " + State2Freq3
	 + ", State2Freq4 = " + State2Freq4
	 + ", State2Freq5 = " + State2Freq5
	 + ", State2Freq6 = " + State2Freq6
	 + ", State2Freq7 = " + State2Freq7
	 + ", State2Freq8 = " + State2Freq8
	 + ", State3Freq1 = " + State3Freq1
	 + ", State3Freq2 = " + State3Freq2
	 + ", State3Freq3 = " + State3Freq3
	 + ", State3Freq4 = " + State3Freq4
	 + ", State3Freq5 = " + State3Freq5
	 + ", State3Freq6 = " + State3Freq6
	 + ", State3Freq7 = " + State3Freq7
	 + ", State3Freq8 = " + State3Freq8
	 + ", State4Freq1 = " + State4Freq1
	 + ", State4Freq2 = " + State4Freq2
	 + ", State4Freq3 = " + State4Freq3
	 + ", State4Freq4 = " + State4Freq4
	 + ", State4Freq5 = " + State4Freq5
	 + ", State4Freq6 = " + State4Freq6
	 + ", State4Freq7 = " + State4Freq7
	 + ", State4Freq8 = " + State4Freq8
	 + ", State5Freq1 = " + State5Freq1
	 + ", State5Freq2 = " + State5Freq2
	 + ", State5Freq3 = " + State5Freq3
	 + ", State5Freq4 = " + State5Freq4
	 + ", State5Freq5 = " + State5Freq5
	 + ", State5Freq6 = " + State5Freq6
	 + ", State5Freq7 = " + State5Freq7
	 + ", State5Freq8 = " + State5Freq8
	 + ", State6Freq1 = " + State6Freq1
	 + ", State6Freq2 = " + State6Freq2
	 + ", State6Freq3 = " + State6Freq3
	 + ", State6Freq4 = " + State6Freq4
	 + ", State6Freq5 = " + State6Freq5
	 + ", State6Freq6 = " + State6Freq6
	 + ", State6Freq7 = " + State6Freq7
	 + ", State6Freq8 = " + State6Freq8
	 + ", State7Freq1 = " + State7Freq1
	 + ", State7Freq2 = " + State7Freq2
	 + ", State7Freq3 = " + State7Freq3
	 + ", State7Freq4 = " + State7Freq4
	 + ", State7Freq5 = " + State7Freq5
	 + ", State7Freq6 = " + State7Freq6
	 + ", State7Freq7 = " + State7Freq7
	 + ", State7Freq8 = " + State7Freq8
	 + ", State8Freq1 = " + State8Freq1
	 + ", State8Freq2 = " + State8Freq2
	 + ", State8Freq3 = " + State8Freq3
	 + ", State8Freq4 = " + State8Freq4
	 + ", State8Freq5 = " + State8Freq5
	 + ", State8Freq6 = " + State8Freq6
	 + ", State8Freq7 = " + State8Freq7
	 + ", State8Freq8 = " + State8Freq8
	 + ", SerialNo = " + SerialNo+"]";
  }
    
}
    
