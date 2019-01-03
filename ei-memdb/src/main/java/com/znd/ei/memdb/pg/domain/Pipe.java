package com.znd.ei.memdb.pg.domain;

import com.znd.ei.memdb.MemIndexable;

/**********************
*电缆管线	*
***********************/
public class Pipe  implements MemIndexable 
{
  private Integer id;
  
  private Integer memIndex;
  
  //资源ID
  private String ResourceID;
  
  //名称
  private String Name;
  
  //规格
  private String Model;
  
  //长度(千米)
  private Double Length;
  
  //单位投资费用(万元/千米)
  private Double ei_UnitInvest;
  
  //建造日期(年月日)
  private Integer BuildDate;
  
  //改造日期(年月日)
  private Integer ReBuildDate;
  
  //停运日期(年月日)
  private Integer OutageDate;
  
  //运行时间
  private Integer TimeSpan;
  
  //规划性质
  private Integer PlanCharacter;
  
  //工程性质
  private Integer ProjCharacter;
  
  //高压电压等级
  private String VoltageLevelH;
  
  //中压电压等级
  private String VoltageLevelM;
  
  //低压电压等级
  private String VoltageLevelL;
  
  //高压到中压换算
  private Integer HV2MV;
  
  //高压到低压换算
  private Integer HV2LV;
  
  //中压到低压换算
  private Integer MV2LV;
  
  //高压电缆容量
  private Integer MaxHVCableNum;
  
  //中压电缆容量
  private Integer MaxMVCableNum;
  
  //低压电缆容量
  private Integer MaxLVCableNum;
  
  //高压电缆1
  private String HVCable1;
  
  //高压电缆2
  private String HVCable2;
  
  //高压电缆3
  private String HVCable3;
  
  //高压电缆4
  private String HVCable4;
  
  //中压电缆1
  private String MVCable1;
  
  //中压电缆2
  private String MVCable2;
  
  //中压电缆3
  private String MVCable3;
  
  //中压电缆4
  private String MVCable4;
  
  //中压电缆5
  private String MVCable5;
  
  //中压电缆6
  private String MVCable6;
  
  //中压电缆7
  private String MVCable7;
  
  //中压电缆8
  private String MVCable8;
  
  //低压电缆1
  private String LVCable1;
  
  //低压电缆2
  private String LVCable2;
  
  //低压电缆3
  private String LVCable3;
  
  //低压电缆4
  private String LVCable4;
  
  //低压电缆5
  private String LVCable5;
  
  //低压电缆6
  private String LVCable6;
  
  //低压电缆7
  private String LVCable7;
  
  //低压电缆8
  private String LVCable8;
  
  //低压电缆9
  private String LVCable9;
  
  //低压电缆10
  private String LVCable10;
  
  //低压电缆11
  private String LVCable11;
  
  //低压电缆12
  private String LVCable12;
  
  //低压电缆13
  private String LVCable13;
  
  //低压电缆14
  private String LVCable14;
  
  //低压电缆15
  private String LVCable15;
  
  //低压电缆16
  private String LVCable16;
  
  //低压电缆17
  private String LVCable17;
  
  //低压电缆18
  private String LVCable18;
  
  //低压电缆19
  private String LVCable19;
  
  //低压电缆20
  private String LVCable20;
  
  //低压电缆21
  private String LVCable21;
  
  //低压电缆22
  private String LVCable22;
  
  //低压电缆23
  private String LVCable23;
  
  //低压电缆24
  private String LVCable24;
  
  //低压电缆25
  private String LVCable25;
  
  //低压电缆26
  private String LVCable26;
  
  //低压电缆27
  private String LVCable27;
  
  //低压电缆28
  private String LVCable28;
  
  //低压电缆29
  private String LVCable29;
  
  //低压电缆30
  private String LVCable30;
  
  //低压电缆31
  private String LVCable31;
  
  //低压电缆32
  private String LVCable32;
  
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
    
  public String getResourceID()
  {
    return ResourceID;
  }
    
  public void setResourceID(String ResourceID)
  {
    this.ResourceID = ResourceID;
  }
    
  public String getName()
  {
    return Name;
  }
    
  public void setName(String Name)
  {
    this.Name = Name;
  }
    
  public String getModel()
  {
    return Model;
  }
    
  public void setModel(String Model)
  {
    this.Model = Model;
  }
    
  public Double getLength()
  {
    return Length;
  }
    
  public void setLength(Double Length)
  {
    this.Length = Length;
  }
    
  public Double getei_UnitInvest()
  {
    return ei_UnitInvest;
  }
    
  public void setei_UnitInvest(Double ei_UnitInvest)
  {
    this.ei_UnitInvest = ei_UnitInvest;
  }
    
  public Integer getBuildDate()
  {
    return BuildDate;
  }
    
  public void setBuildDate(Integer BuildDate)
  {
    this.BuildDate = BuildDate;
  }
    
  public Integer getReBuildDate()
  {
    return ReBuildDate;
  }
    
  public void setReBuildDate(Integer ReBuildDate)
  {
    this.ReBuildDate = ReBuildDate;
  }
    
  public Integer getOutageDate()
  {
    return OutageDate;
  }
    
  public void setOutageDate(Integer OutageDate)
  {
    this.OutageDate = OutageDate;
  }
    
  public Integer getTimeSpan()
  {
    return TimeSpan;
  }
    
  public void setTimeSpan(Integer TimeSpan)
  {
    this.TimeSpan = TimeSpan;
  }
    
  public Integer getPlanCharacter()
  {
    return PlanCharacter;
  }
    
  public void setPlanCharacter(Integer PlanCharacter)
  {
    this.PlanCharacter = PlanCharacter;
  }
    
  public Integer getProjCharacter()
  {
    return ProjCharacter;
  }
    
  public void setProjCharacter(Integer ProjCharacter)
  {
    this.ProjCharacter = ProjCharacter;
  }
    
  public String getVoltageLevelH()
  {
    return VoltageLevelH;
  }
    
  public void setVoltageLevelH(String VoltageLevelH)
  {
    this.VoltageLevelH = VoltageLevelH;
  }
    
  public String getVoltageLevelM()
  {
    return VoltageLevelM;
  }
    
  public void setVoltageLevelM(String VoltageLevelM)
  {
    this.VoltageLevelM = VoltageLevelM;
  }
    
  public String getVoltageLevelL()
  {
    return VoltageLevelL;
  }
    
  public void setVoltageLevelL(String VoltageLevelL)
  {
    this.VoltageLevelL = VoltageLevelL;
  }
    
  public Integer getHV2MV()
  {
    return HV2MV;
  }
    
  public void setHV2MV(Integer HV2MV)
  {
    this.HV2MV = HV2MV;
  }
    
  public Integer getHV2LV()
  {
    return HV2LV;
  }
    
  public void setHV2LV(Integer HV2LV)
  {
    this.HV2LV = HV2LV;
  }
    
  public Integer getMV2LV()
  {
    return MV2LV;
  }
    
  public void setMV2LV(Integer MV2LV)
  {
    this.MV2LV = MV2LV;
  }
    
  public Integer getMaxHVCableNum()
  {
    return MaxHVCableNum;
  }
    
  public void setMaxHVCableNum(Integer MaxHVCableNum)
  {
    this.MaxHVCableNum = MaxHVCableNum;
  }
    
  public Integer getMaxMVCableNum()
  {
    return MaxMVCableNum;
  }
    
  public void setMaxMVCableNum(Integer MaxMVCableNum)
  {
    this.MaxMVCableNum = MaxMVCableNum;
  }
    
  public Integer getMaxLVCableNum()
  {
    return MaxLVCableNum;
  }
    
  public void setMaxLVCableNum(Integer MaxLVCableNum)
  {
    this.MaxLVCableNum = MaxLVCableNum;
  }
    
  public String getHVCable1()
  {
    return HVCable1;
  }
    
  public void setHVCable1(String HVCable1)
  {
    this.HVCable1 = HVCable1;
  }
    
  public String getHVCable2()
  {
    return HVCable2;
  }
    
  public void setHVCable2(String HVCable2)
  {
    this.HVCable2 = HVCable2;
  }
    
  public String getHVCable3()
  {
    return HVCable3;
  }
    
  public void setHVCable3(String HVCable3)
  {
    this.HVCable3 = HVCable3;
  }
    
  public String getHVCable4()
  {
    return HVCable4;
  }
    
  public void setHVCable4(String HVCable4)
  {
    this.HVCable4 = HVCable4;
  }
    
  public String getMVCable1()
  {
    return MVCable1;
  }
    
  public void setMVCable1(String MVCable1)
  {
    this.MVCable1 = MVCable1;
  }
    
  public String getMVCable2()
  {
    return MVCable2;
  }
    
  public void setMVCable2(String MVCable2)
  {
    this.MVCable2 = MVCable2;
  }
    
  public String getMVCable3()
  {
    return MVCable3;
  }
    
  public void setMVCable3(String MVCable3)
  {
    this.MVCable3 = MVCable3;
  }
    
  public String getMVCable4()
  {
    return MVCable4;
  }
    
  public void setMVCable4(String MVCable4)
  {
    this.MVCable4 = MVCable4;
  }
    
  public String getMVCable5()
  {
    return MVCable5;
  }
    
  public void setMVCable5(String MVCable5)
  {
    this.MVCable5 = MVCable5;
  }
    
  public String getMVCable6()
  {
    return MVCable6;
  }
    
  public void setMVCable6(String MVCable6)
  {
    this.MVCable6 = MVCable6;
  }
    
  public String getMVCable7()
  {
    return MVCable7;
  }
    
  public void setMVCable7(String MVCable7)
  {
    this.MVCable7 = MVCable7;
  }
    
  public String getMVCable8()
  {
    return MVCable8;
  }
    
  public void setMVCable8(String MVCable8)
  {
    this.MVCable8 = MVCable8;
  }
    
  public String getLVCable1()
  {
    return LVCable1;
  }
    
  public void setLVCable1(String LVCable1)
  {
    this.LVCable1 = LVCable1;
  }
    
  public String getLVCable2()
  {
    return LVCable2;
  }
    
  public void setLVCable2(String LVCable2)
  {
    this.LVCable2 = LVCable2;
  }
    
  public String getLVCable3()
  {
    return LVCable3;
  }
    
  public void setLVCable3(String LVCable3)
  {
    this.LVCable3 = LVCable3;
  }
    
  public String getLVCable4()
  {
    return LVCable4;
  }
    
  public void setLVCable4(String LVCable4)
  {
    this.LVCable4 = LVCable4;
  }
    
  public String getLVCable5()
  {
    return LVCable5;
  }
    
  public void setLVCable5(String LVCable5)
  {
    this.LVCable5 = LVCable5;
  }
    
  public String getLVCable6()
  {
    return LVCable6;
  }
    
  public void setLVCable6(String LVCable6)
  {
    this.LVCable6 = LVCable6;
  }
    
  public String getLVCable7()
  {
    return LVCable7;
  }
    
  public void setLVCable7(String LVCable7)
  {
    this.LVCable7 = LVCable7;
  }
    
  public String getLVCable8()
  {
    return LVCable8;
  }
    
  public void setLVCable8(String LVCable8)
  {
    this.LVCable8 = LVCable8;
  }
    
  public String getLVCable9()
  {
    return LVCable9;
  }
    
  public void setLVCable9(String LVCable9)
  {
    this.LVCable9 = LVCable9;
  }
    
  public String getLVCable10()
  {
    return LVCable10;
  }
    
  public void setLVCable10(String LVCable10)
  {
    this.LVCable10 = LVCable10;
  }
    
  public String getLVCable11()
  {
    return LVCable11;
  }
    
  public void setLVCable11(String LVCable11)
  {
    this.LVCable11 = LVCable11;
  }
    
  public String getLVCable12()
  {
    return LVCable12;
  }
    
  public void setLVCable12(String LVCable12)
  {
    this.LVCable12 = LVCable12;
  }
    
  public String getLVCable13()
  {
    return LVCable13;
  }
    
  public void setLVCable13(String LVCable13)
  {
    this.LVCable13 = LVCable13;
  }
    
  public String getLVCable14()
  {
    return LVCable14;
  }
    
  public void setLVCable14(String LVCable14)
  {
    this.LVCable14 = LVCable14;
  }
    
  public String getLVCable15()
  {
    return LVCable15;
  }
    
  public void setLVCable15(String LVCable15)
  {
    this.LVCable15 = LVCable15;
  }
    
  public String getLVCable16()
  {
    return LVCable16;
  }
    
  public void setLVCable16(String LVCable16)
  {
    this.LVCable16 = LVCable16;
  }
    
  public String getLVCable17()
  {
    return LVCable17;
  }
    
  public void setLVCable17(String LVCable17)
  {
    this.LVCable17 = LVCable17;
  }
    
  public String getLVCable18()
  {
    return LVCable18;
  }
    
  public void setLVCable18(String LVCable18)
  {
    this.LVCable18 = LVCable18;
  }
    
  public String getLVCable19()
  {
    return LVCable19;
  }
    
  public void setLVCable19(String LVCable19)
  {
    this.LVCable19 = LVCable19;
  }
    
  public String getLVCable20()
  {
    return LVCable20;
  }
    
  public void setLVCable20(String LVCable20)
  {
    this.LVCable20 = LVCable20;
  }
    
  public String getLVCable21()
  {
    return LVCable21;
  }
    
  public void setLVCable21(String LVCable21)
  {
    this.LVCable21 = LVCable21;
  }
    
  public String getLVCable22()
  {
    return LVCable22;
  }
    
  public void setLVCable22(String LVCable22)
  {
    this.LVCable22 = LVCable22;
  }
    
  public String getLVCable23()
  {
    return LVCable23;
  }
    
  public void setLVCable23(String LVCable23)
  {
    this.LVCable23 = LVCable23;
  }
    
  public String getLVCable24()
  {
    return LVCable24;
  }
    
  public void setLVCable24(String LVCable24)
  {
    this.LVCable24 = LVCable24;
  }
    
  public String getLVCable25()
  {
    return LVCable25;
  }
    
  public void setLVCable25(String LVCable25)
  {
    this.LVCable25 = LVCable25;
  }
    
  public String getLVCable26()
  {
    return LVCable26;
  }
    
  public void setLVCable26(String LVCable26)
  {
    this.LVCable26 = LVCable26;
  }
    
  public String getLVCable27()
  {
    return LVCable27;
  }
    
  public void setLVCable27(String LVCable27)
  {
    this.LVCable27 = LVCable27;
  }
    
  public String getLVCable28()
  {
    return LVCable28;
  }
    
  public void setLVCable28(String LVCable28)
  {
    this.LVCable28 = LVCable28;
  }
    
  public String getLVCable29()
  {
    return LVCable29;
  }
    
  public void setLVCable29(String LVCable29)
  {
    this.LVCable29 = LVCable29;
  }
    
  public String getLVCable30()
  {
    return LVCable30;
  }
    
  public void setLVCable30(String LVCable30)
  {
    this.LVCable30 = LVCable30;
  }
    
  public String getLVCable31()
  {
    return LVCable31;
  }
    
  public void setLVCable31(String LVCable31)
  {
    this.LVCable31 = LVCable31;
  }
    
  public String getLVCable32()
  {
    return LVCable32;
  }
    
  public void setLVCable32(String LVCable32)
  {
    this.LVCable32 = LVCable32;
  }
    
  public String toString()
  {
    return "Pipe ["+"id = " + id
	 + ", memIndex = " + memIndex
	 + ", ResourceID = " + ResourceID
	 + ", Name = " + Name
	 + ", Model = " + Model
	 + ", Length = " + Length
	 + ", ei_UnitInvest = " + ei_UnitInvest
	 + ", BuildDate = " + BuildDate
	 + ", ReBuildDate = " + ReBuildDate
	 + ", OutageDate = " + OutageDate
	 + ", TimeSpan = " + TimeSpan
	 + ", PlanCharacter = " + PlanCharacter
	 + ", ProjCharacter = " + ProjCharacter
	 + ", VoltageLevelH = " + VoltageLevelH
	 + ", VoltageLevelM = " + VoltageLevelM
	 + ", VoltageLevelL = " + VoltageLevelL
	 + ", HV2MV = " + HV2MV
	 + ", HV2LV = " + HV2LV
	 + ", MV2LV = " + MV2LV
	 + ", MaxHVCableNum = " + MaxHVCableNum
	 + ", MaxMVCableNum = " + MaxMVCableNum
	 + ", MaxLVCableNum = " + MaxLVCableNum
	 + ", HVCable1 = " + HVCable1
	 + ", HVCable2 = " + HVCable2
	 + ", HVCable3 = " + HVCable3
	 + ", HVCable4 = " + HVCable4
	 + ", MVCable1 = " + MVCable1
	 + ", MVCable2 = " + MVCable2
	 + ", MVCable3 = " + MVCable3
	 + ", MVCable4 = " + MVCable4
	 + ", MVCable5 = " + MVCable5
	 + ", MVCable6 = " + MVCable6
	 + ", MVCable7 = " + MVCable7
	 + ", MVCable8 = " + MVCable8
	 + ", LVCable1 = " + LVCable1
	 + ", LVCable2 = " + LVCable2
	 + ", LVCable3 = " + LVCable3
	 + ", LVCable4 = " + LVCable4
	 + ", LVCable5 = " + LVCable5
	 + ", LVCable6 = " + LVCable6
	 + ", LVCable7 = " + LVCable7
	 + ", LVCable8 = " + LVCable8
	 + ", LVCable9 = " + LVCable9
	 + ", LVCable10 = " + LVCable10
	 + ", LVCable11 = " + LVCable11
	 + ", LVCable12 = " + LVCable12
	 + ", LVCable13 = " + LVCable13
	 + ", LVCable14 = " + LVCable14
	 + ", LVCable15 = " + LVCable15
	 + ", LVCable16 = " + LVCable16
	 + ", LVCable17 = " + LVCable17
	 + ", LVCable18 = " + LVCable18
	 + ", LVCable19 = " + LVCable19
	 + ", LVCable20 = " + LVCable20
	 + ", LVCable21 = " + LVCable21
	 + ", LVCable22 = " + LVCable22
	 + ", LVCable23 = " + LVCable23
	 + ", LVCable24 = " + LVCable24
	 + ", LVCable25 = " + LVCable25
	 + ", LVCable26 = " + LVCable26
	 + ", LVCable27 = " + LVCable27
	 + ", LVCable28 = " + LVCable28
	 + ", LVCable29 = " + LVCable29
	 + ", LVCable30 = " + LVCable30
	 + ", LVCable31 = " + LVCable31
	 + ", LVCable32 = " + LVCable32+"]";
  }
    
}
    
