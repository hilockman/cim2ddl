package com.znd.ei.memdb.bpa.domain;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;


/**********************
*线路故障点移动计算结果	*
***********************/
@Entity
public class BpaScc_FMove
{
  @Id
  @GeneratedValue(strategy=GenerationType.AUTO)
  private Integer id;
  
  private Integer memIndex;
  
  //故障类型
  private Integer faultType;
  
  //故障线路
  private String faultLine;
  
  //监视线路
  private String monLine;
  
  //监视母线
  private String monBus;
  
  //数据类型
  private Integer dataType;
  
  //值000
  private Double value000;
  
  //值001
  private Double value001;
  
  //值002
  private Double value002;
  
  //值003
  private Double value003;
  
  //值004
  private Double value004;
  
  //值005
  private Double value005;
  
  //值006
  private Double value006;
  
  //值007
  private Double value007;
  
  //值008
  private Double value008;
  
  //值009
  private Double value009;
  
  //值010
  private Double value010;
  
  //值011
  private Double value011;
  
  //值012
  private Double value012;
  
  //值013
  private Double value013;
  
  //值014
  private Double value014;
  
  //值015
  private Double value015;
  
  //值016
  private Double value016;
  
  //值017
  private Double value017;
  
  //值018
  private Double value018;
  
  //值019
  private Double value019;
  
  //值020
  private Double value020;
  
  //值021
  private Double value021;
  
  //值022
  private Double value022;
  
  //值023
  private Double value023;
  
  //值024
  private Double value024;
  
  //值025
  private Double value025;
  
  //值026
  private Double value026;
  
  //值027
  private Double value027;
  
  //值028
  private Double value028;
  
  //值029
  private Double value029;
  
  //值030
  private Double value030;
  
  //值031
  private Double value031;
  
  //值032
  private Double value032;
  
  //值033
  private Double value033;
  
  //值034
  private Double value034;
  
  //值035
  private Double value035;
  
  //值036
  private Double value036;
  
  //值037
  private Double value037;
  
  //值038
  private Double value038;
  
  //值039
  private Double value039;
  
  //值040
  private Double value040;
  
  //值041
  private Double value041;
  
  //值042
  private Double value042;
  
  //值043
  private Double value043;
  
  //值044
  private Double value044;
  
  //值045
  private Double value045;
  
  //值046
  private Double value046;
  
  //值047
  private Double value047;
  
  //值048
  private Double value048;
  
  //值049
  private Double value049;
  
  //值050
  private Double value050;
  
  //值051
  private Double value051;
  
  //值052
  private Double value052;
  
  //值053
  private Double value053;
  
  //值054
  private Double value054;
  
  //值055
  private Double value055;
  
  //值056
  private Double value056;
  
  //值057
  private Double value057;
  
  //值058
  private Double value058;
  
  //值059
  private Double value059;
  
  //值060
  private Double value060;
  
  //值061
  private Double value061;
  
  //值062
  private Double value062;
  
  //值063
  private Double value063;
  
  //值064
  private Double value064;
  
  //值065
  private Double value065;
  
  //值066
  private Double value066;
  
  //值067
  private Double value067;
  
  //值068
  private Double value068;
  
  //值069
  private Double value069;
  
  //值070
  private Double value070;
  
  //值071
  private Double value071;
  
  //值072
  private Double value072;
  
  //值073
  private Double value073;
  
  //值074
  private Double value074;
  
  //值075
  private Double value075;
  
  //值076
  private Double value076;
  
  //值077
  private Double value077;
  
  //值078
  private Double value078;
  
  //值079
  private Double value079;
  
  //值080
  private Double value080;
  
  //值081
  private Double value081;
  
  //值082
  private Double value082;
  
  //值083
  private Double value083;
  
  //值084
  private Double value084;
  
  //值085
  private Double value085;
  
  //值086
  private Double value086;
  
  //值087
  private Double value087;
  
  //值088
  private Double value088;
  
  //值089
  private Double value089;
  
  //值090
  private Double value090;
  
  //值091
  private Double value091;
  
  //值092
  private Double value092;
  
  //值093
  private Double value093;
  
  //值094
  private Double value094;
  
  //值095
  private Double value095;
  
  //值096
  private Double value096;
  
  //值097
  private Double value097;
  
  //值098
  private Double value098;
  
  //值099
  private Double value099;
  
  //值100
  private Double value100;
  
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
    
  public Integer getFaultType() 
  {
    return faultType;
  }
    
  public void setFaultType(Integer faultType)
  {
    this.faultType = faultType;
  }
    
  public String getFaultLine() 
  {
    return faultLine;
  }
    
  public void setFaultLine(String faultLine)
  {
    this.faultLine = faultLine;
  }
    
  public String getMonLine() 
  {
    return monLine;
  }
    
  public void setMonLine(String monLine)
  {
    this.monLine = monLine;
  }
    
  public String getMonBus() 
  {
    return monBus;
  }
    
  public void setMonBus(String monBus)
  {
    this.monBus = monBus;
  }
    
  public Integer getDataType() 
  {
    return dataType;
  }
    
  public void setDataType(Integer dataType)
  {
    this.dataType = dataType;
  }
    
  public Double getValue000() 
  {
    return value000;
  }
    
  public void setValue000(Double value000)
  {
    this.value000 = value000;
  }
    
  public Double getValue001() 
  {
    return value001;
  }
    
  public void setValue001(Double value001)
  {
    this.value001 = value001;
  }
    
  public Double getValue002() 
  {
    return value002;
  }
    
  public void setValue002(Double value002)
  {
    this.value002 = value002;
  }
    
  public Double getValue003() 
  {
    return value003;
  }
    
  public void setValue003(Double value003)
  {
    this.value003 = value003;
  }
    
  public Double getValue004() 
  {
    return value004;
  }
    
  public void setValue004(Double value004)
  {
    this.value004 = value004;
  }
    
  public Double getValue005() 
  {
    return value005;
  }
    
  public void setValue005(Double value005)
  {
    this.value005 = value005;
  }
    
  public Double getValue006() 
  {
    return value006;
  }
    
  public void setValue006(Double value006)
  {
    this.value006 = value006;
  }
    
  public Double getValue007() 
  {
    return value007;
  }
    
  public void setValue007(Double value007)
  {
    this.value007 = value007;
  }
    
  public Double getValue008() 
  {
    return value008;
  }
    
  public void setValue008(Double value008)
  {
    this.value008 = value008;
  }
    
  public Double getValue009() 
  {
    return value009;
  }
    
  public void setValue009(Double value009)
  {
    this.value009 = value009;
  }
    
  public Double getValue010() 
  {
    return value010;
  }
    
  public void setValue010(Double value010)
  {
    this.value010 = value010;
  }
    
  public Double getValue011() 
  {
    return value011;
  }
    
  public void setValue011(Double value011)
  {
    this.value011 = value011;
  }
    
  public Double getValue012() 
  {
    return value012;
  }
    
  public void setValue012(Double value012)
  {
    this.value012 = value012;
  }
    
  public Double getValue013() 
  {
    return value013;
  }
    
  public void setValue013(Double value013)
  {
    this.value013 = value013;
  }
    
  public Double getValue014() 
  {
    return value014;
  }
    
  public void setValue014(Double value014)
  {
    this.value014 = value014;
  }
    
  public Double getValue015() 
  {
    return value015;
  }
    
  public void setValue015(Double value015)
  {
    this.value015 = value015;
  }
    
  public Double getValue016() 
  {
    return value016;
  }
    
  public void setValue016(Double value016)
  {
    this.value016 = value016;
  }
    
  public Double getValue017() 
  {
    return value017;
  }
    
  public void setValue017(Double value017)
  {
    this.value017 = value017;
  }
    
  public Double getValue018() 
  {
    return value018;
  }
    
  public void setValue018(Double value018)
  {
    this.value018 = value018;
  }
    
  public Double getValue019() 
  {
    return value019;
  }
    
  public void setValue019(Double value019)
  {
    this.value019 = value019;
  }
    
  public Double getValue020() 
  {
    return value020;
  }
    
  public void setValue020(Double value020)
  {
    this.value020 = value020;
  }
    
  public Double getValue021() 
  {
    return value021;
  }
    
  public void setValue021(Double value021)
  {
    this.value021 = value021;
  }
    
  public Double getValue022() 
  {
    return value022;
  }
    
  public void setValue022(Double value022)
  {
    this.value022 = value022;
  }
    
  public Double getValue023() 
  {
    return value023;
  }
    
  public void setValue023(Double value023)
  {
    this.value023 = value023;
  }
    
  public Double getValue024() 
  {
    return value024;
  }
    
  public void setValue024(Double value024)
  {
    this.value024 = value024;
  }
    
  public Double getValue025() 
  {
    return value025;
  }
    
  public void setValue025(Double value025)
  {
    this.value025 = value025;
  }
    
  public Double getValue026() 
  {
    return value026;
  }
    
  public void setValue026(Double value026)
  {
    this.value026 = value026;
  }
    
  public Double getValue027() 
  {
    return value027;
  }
    
  public void setValue027(Double value027)
  {
    this.value027 = value027;
  }
    
  public Double getValue028() 
  {
    return value028;
  }
    
  public void setValue028(Double value028)
  {
    this.value028 = value028;
  }
    
  public Double getValue029() 
  {
    return value029;
  }
    
  public void setValue029(Double value029)
  {
    this.value029 = value029;
  }
    
  public Double getValue030() 
  {
    return value030;
  }
    
  public void setValue030(Double value030)
  {
    this.value030 = value030;
  }
    
  public Double getValue031() 
  {
    return value031;
  }
    
  public void setValue031(Double value031)
  {
    this.value031 = value031;
  }
    
  public Double getValue032() 
  {
    return value032;
  }
    
  public void setValue032(Double value032)
  {
    this.value032 = value032;
  }
    
  public Double getValue033() 
  {
    return value033;
  }
    
  public void setValue033(Double value033)
  {
    this.value033 = value033;
  }
    
  public Double getValue034() 
  {
    return value034;
  }
    
  public void setValue034(Double value034)
  {
    this.value034 = value034;
  }
    
  public Double getValue035() 
  {
    return value035;
  }
    
  public void setValue035(Double value035)
  {
    this.value035 = value035;
  }
    
  public Double getValue036() 
  {
    return value036;
  }
    
  public void setValue036(Double value036)
  {
    this.value036 = value036;
  }
    
  public Double getValue037() 
  {
    return value037;
  }
    
  public void setValue037(Double value037)
  {
    this.value037 = value037;
  }
    
  public Double getValue038() 
  {
    return value038;
  }
    
  public void setValue038(Double value038)
  {
    this.value038 = value038;
  }
    
  public Double getValue039() 
  {
    return value039;
  }
    
  public void setValue039(Double value039)
  {
    this.value039 = value039;
  }
    
  public Double getValue040() 
  {
    return value040;
  }
    
  public void setValue040(Double value040)
  {
    this.value040 = value040;
  }
    
  public Double getValue041() 
  {
    return value041;
  }
    
  public void setValue041(Double value041)
  {
    this.value041 = value041;
  }
    
  public Double getValue042() 
  {
    return value042;
  }
    
  public void setValue042(Double value042)
  {
    this.value042 = value042;
  }
    
  public Double getValue043() 
  {
    return value043;
  }
    
  public void setValue043(Double value043)
  {
    this.value043 = value043;
  }
    
  public Double getValue044() 
  {
    return value044;
  }
    
  public void setValue044(Double value044)
  {
    this.value044 = value044;
  }
    
  public Double getValue045() 
  {
    return value045;
  }
    
  public void setValue045(Double value045)
  {
    this.value045 = value045;
  }
    
  public Double getValue046() 
  {
    return value046;
  }
    
  public void setValue046(Double value046)
  {
    this.value046 = value046;
  }
    
  public Double getValue047() 
  {
    return value047;
  }
    
  public void setValue047(Double value047)
  {
    this.value047 = value047;
  }
    
  public Double getValue048() 
  {
    return value048;
  }
    
  public void setValue048(Double value048)
  {
    this.value048 = value048;
  }
    
  public Double getValue049() 
  {
    return value049;
  }
    
  public void setValue049(Double value049)
  {
    this.value049 = value049;
  }
    
  public Double getValue050() 
  {
    return value050;
  }
    
  public void setValue050(Double value050)
  {
    this.value050 = value050;
  }
    
  public Double getValue051() 
  {
    return value051;
  }
    
  public void setValue051(Double value051)
  {
    this.value051 = value051;
  }
    
  public Double getValue052() 
  {
    return value052;
  }
    
  public void setValue052(Double value052)
  {
    this.value052 = value052;
  }
    
  public Double getValue053() 
  {
    return value053;
  }
    
  public void setValue053(Double value053)
  {
    this.value053 = value053;
  }
    
  public Double getValue054() 
  {
    return value054;
  }
    
  public void setValue054(Double value054)
  {
    this.value054 = value054;
  }
    
  public Double getValue055() 
  {
    return value055;
  }
    
  public void setValue055(Double value055)
  {
    this.value055 = value055;
  }
    
  public Double getValue056() 
  {
    return value056;
  }
    
  public void setValue056(Double value056)
  {
    this.value056 = value056;
  }
    
  public Double getValue057() 
  {
    return value057;
  }
    
  public void setValue057(Double value057)
  {
    this.value057 = value057;
  }
    
  public Double getValue058() 
  {
    return value058;
  }
    
  public void setValue058(Double value058)
  {
    this.value058 = value058;
  }
    
  public Double getValue059() 
  {
    return value059;
  }
    
  public void setValue059(Double value059)
  {
    this.value059 = value059;
  }
    
  public Double getValue060() 
  {
    return value060;
  }
    
  public void setValue060(Double value060)
  {
    this.value060 = value060;
  }
    
  public Double getValue061() 
  {
    return value061;
  }
    
  public void setValue061(Double value061)
  {
    this.value061 = value061;
  }
    
  public Double getValue062() 
  {
    return value062;
  }
    
  public void setValue062(Double value062)
  {
    this.value062 = value062;
  }
    
  public Double getValue063() 
  {
    return value063;
  }
    
  public void setValue063(Double value063)
  {
    this.value063 = value063;
  }
    
  public Double getValue064() 
  {
    return value064;
  }
    
  public void setValue064(Double value064)
  {
    this.value064 = value064;
  }
    
  public Double getValue065() 
  {
    return value065;
  }
    
  public void setValue065(Double value065)
  {
    this.value065 = value065;
  }
    
  public Double getValue066() 
  {
    return value066;
  }
    
  public void setValue066(Double value066)
  {
    this.value066 = value066;
  }
    
  public Double getValue067() 
  {
    return value067;
  }
    
  public void setValue067(Double value067)
  {
    this.value067 = value067;
  }
    
  public Double getValue068() 
  {
    return value068;
  }
    
  public void setValue068(Double value068)
  {
    this.value068 = value068;
  }
    
  public Double getValue069() 
  {
    return value069;
  }
    
  public void setValue069(Double value069)
  {
    this.value069 = value069;
  }
    
  public Double getValue070() 
  {
    return value070;
  }
    
  public void setValue070(Double value070)
  {
    this.value070 = value070;
  }
    
  public Double getValue071() 
  {
    return value071;
  }
    
  public void setValue071(Double value071)
  {
    this.value071 = value071;
  }
    
  public Double getValue072() 
  {
    return value072;
  }
    
  public void setValue072(Double value072)
  {
    this.value072 = value072;
  }
    
  public Double getValue073() 
  {
    return value073;
  }
    
  public void setValue073(Double value073)
  {
    this.value073 = value073;
  }
    
  public Double getValue074() 
  {
    return value074;
  }
    
  public void setValue074(Double value074)
  {
    this.value074 = value074;
  }
    
  public Double getValue075() 
  {
    return value075;
  }
    
  public void setValue075(Double value075)
  {
    this.value075 = value075;
  }
    
  public Double getValue076() 
  {
    return value076;
  }
    
  public void setValue076(Double value076)
  {
    this.value076 = value076;
  }
    
  public Double getValue077() 
  {
    return value077;
  }
    
  public void setValue077(Double value077)
  {
    this.value077 = value077;
  }
    
  public Double getValue078() 
  {
    return value078;
  }
    
  public void setValue078(Double value078)
  {
    this.value078 = value078;
  }
    
  public Double getValue079() 
  {
    return value079;
  }
    
  public void setValue079(Double value079)
  {
    this.value079 = value079;
  }
    
  public Double getValue080() 
  {
    return value080;
  }
    
  public void setValue080(Double value080)
  {
    this.value080 = value080;
  }
    
  public Double getValue081() 
  {
    return value081;
  }
    
  public void setValue081(Double value081)
  {
    this.value081 = value081;
  }
    
  public Double getValue082() 
  {
    return value082;
  }
    
  public void setValue082(Double value082)
  {
    this.value082 = value082;
  }
    
  public Double getValue083() 
  {
    return value083;
  }
    
  public void setValue083(Double value083)
  {
    this.value083 = value083;
  }
    
  public Double getValue084() 
  {
    return value084;
  }
    
  public void setValue084(Double value084)
  {
    this.value084 = value084;
  }
    
  public Double getValue085() 
  {
    return value085;
  }
    
  public void setValue085(Double value085)
  {
    this.value085 = value085;
  }
    
  public Double getValue086() 
  {
    return value086;
  }
    
  public void setValue086(Double value086)
  {
    this.value086 = value086;
  }
    
  public Double getValue087() 
  {
    return value087;
  }
    
  public void setValue087(Double value087)
  {
    this.value087 = value087;
  }
    
  public Double getValue088() 
  {
    return value088;
  }
    
  public void setValue088(Double value088)
  {
    this.value088 = value088;
  }
    
  public Double getValue089() 
  {
    return value089;
  }
    
  public void setValue089(Double value089)
  {
    this.value089 = value089;
  }
    
  public Double getValue090() 
  {
    return value090;
  }
    
  public void setValue090(Double value090)
  {
    this.value090 = value090;
  }
    
  public Double getValue091() 
  {
    return value091;
  }
    
  public void setValue091(Double value091)
  {
    this.value091 = value091;
  }
    
  public Double getValue092() 
  {
    return value092;
  }
    
  public void setValue092(Double value092)
  {
    this.value092 = value092;
  }
    
  public Double getValue093() 
  {
    return value093;
  }
    
  public void setValue093(Double value093)
  {
    this.value093 = value093;
  }
    
  public Double getValue094() 
  {
    return value094;
  }
    
  public void setValue094(Double value094)
  {
    this.value094 = value094;
  }
    
  public Double getValue095() 
  {
    return value095;
  }
    
  public void setValue095(Double value095)
  {
    this.value095 = value095;
  }
    
  public Double getValue096() 
  {
    return value096;
  }
    
  public void setValue096(Double value096)
  {
    this.value096 = value096;
  }
    
  public Double getValue097() 
  {
    return value097;
  }
    
  public void setValue097(Double value097)
  {
    this.value097 = value097;
  }
    
  public Double getValue098() 
  {
    return value098;
  }
    
  public void setValue098(Double value098)
  {
    this.value098 = value098;
  }
    
  public Double getValue099() 
  {
    return value099;
  }
    
  public void setValue099(Double value099)
  {
    this.value099 = value099;
  }
    
  public Double getValue100() 
  {
    return value100;
  }
    
  public void setValue100(Double value100)
  {
    this.value100 = value100;
  }
    
}
    
