package com.znd.ei.memdb.domain;

/**********************
*设备多状态	*
***********************/
class DevMState
{
  //设备类型
  private Integer type;

  //设备名称
  private String name;

  //状态数
  private Integer stateNum;

  //状态1出力(比率)
  private Double state1Rate;

  //状态2出力(比率)
  private Double state2Rate;

  //状态3出力(比率)
  private Double state3Rate;

  //状态4出力(比率)
  private Double state4Rate;

  //状态5出力(比率)
  private Double state5Rate;

  //状态6出力(比率)
  private Double state6Rate;

  //状态7出力(比率)
  private Double state7Rate;

  //状态8出力(比率)
  private Double state8Rate;

  //状态1概率
  private Double state1Prob;

  //状态2概率
  private Double state2Prob;

  //状态3概率
  private Double state3Prob;

  //状态4概率
  private Double state4Prob;

  //状态5概率
  private Double state5Prob;

  //状态6概率
  private Double state6Prob;

  //状态7概率
  private Double state7Prob;

  //状态8概率
  private Double state8Prob;

  //状态1-1转移率(次/年)
  private Double state1Freq1;

  //状态1-2转移率(次/年)
  private Double state1Freq2;

  //状态1-3转移率(次/年)
  private Double state1Freq3;

  //状态1-4转移率(次/年)
  private Double state1Freq4;

  //状态1-5转移率(次/年)
  private Double state1Freq5;

  //状态1-6转移率(次/年)
  private Double state1Freq6;

  //状态1-7转移率(次/年)
  private Double state1Freq7;

  //状态1-8转移率(次/年)
  private Double state1Freq8;

  //状态2-1转移率(次/年)
  private Double state2Freq1;

  //状态2-2转移率(次/年)
  private Double state2Freq2;

  //状态2-3转移率(次/年)
  private Double state2Freq3;

  //状态2-4转移率(次/年)
  private Double state2Freq4;

  //状态2-5转移率(次/年)
  private Double state2Freq5;

  //状态2-6转移率(次/年)
  private Double state2Freq6;

  //状态2-7转移率(次/年)
  private Double state2Freq7;

  //状态2-8转移率(次/年)
  private Double state2Freq8;

  //状态3-1转移率(次/年)
  private Double state3Freq1;

  //状态3-2转移率(次/年)
  private Double state3Freq2;

  //状态3-3转移率(次/年)
  private Double state3Freq3;

  //状态3-4转移率(次/年)
  private Double state3Freq4;

  //状态3-5转移率(次/年)
  private Double state3Freq5;

  //状态3-6转移率(次/年)
  private Double state3Freq6;

  //状态3-7转移率(次/年)
  private Double state3Freq7;

  //状态3-8转移率(次/年)
  private Double state3Freq8;

  //状态4-1转移率(次/年)
  private Double state4Freq1;

  //状态4-2转移率(次/年)
  private Double state4Freq2;

  //状态4-3转移率(次/年)
  private Double state4Freq3;

  //状态4-4转移率(次/年)
  private Double state4Freq4;

  //状态4-5转移率(次/年)
  private Double state4Freq5;

  //状态4-6转移率(次/年)
  private Double state4Freq6;

  //状态4-7转移率(次/年)
  private Double state4Freq7;

  //状态4-8转移率(次/年)
  private Double state4Freq8;

  //状态5-1转移率(次/年)
  private Double state5Freq1;

  //状态5-2转移率(次/年)
  private Double state5Freq2;

  //状态5-3转移率(次/年)
  private Double state5Freq3;

  //状态5-4转移率(次/年)
  private Double state5Freq4;

  //状态5-5转移率(次/年)
  private Double state5Freq5;

  //状态5-6转移率(次/年)
  private Double state5Freq6;

  //状态5-7转移率(次/年)
  private Double state5Freq7;

  //状态5-8转移率(次/年)
  private Double state5Freq8;

  //状态6-1转移率(次/年)
  private Double state6Freq1;

  //状态6-2转移率(次/年)
  private Double state6Freq2;

  //状态6-3转移率(次/年)
  private Double state6Freq3;

  //状态6-4转移率(次/年)
  private Double state6Freq4;

  //状态6-5转移率(次/年)
  private Double state6Freq5;

  //状态6-6转移率(次/年)
  private Double state6Freq6;

  //状态6-7转移率(次/年)
  private Double state6Freq7;

  //状态6-8转移率(次/年)
  private Double state6Freq8;

  //状态7-1转移率(次/年)
  private Double state7Freq1;

  //状态7-2转移率(次/年)
  private Double state7Freq2;

  //状态7-3转移率(次/年)
  private Double state7Freq3;

  //状态7-4转移率(次/年)
  private Double state7Freq4;

  //状态7-5转移率(次/年)
  private Double state7Freq5;

  //状态7-6转移率(次/年)
  private Double state7Freq6;

  //状态7-7转移率(次/年)
  private Double state7Freq7;

  //状态7-8转移率(次/年)
  private Double state7Freq8;

  //状态8-1转移率(次/年)
  private Double state8Freq1;

  //状态8-2转移率(次/年)
  private Double state8Freq2;

  //状态8-3转移率(次/年)
  private Double state8Freq3;

  //状态8-4转移率(次/年)
  private Double state8Freq4;

  //状态8-5转移率(次/年)
  private Double state8Freq5;

  //状态8-6转移率(次/年)
  private Double state8Freq6;

  //状态8-7转移率(次/年)
  private Double state8Freq7;

  //状态8-8转移率(次/年)
  private Double state8Freq8;

  //设备索引
  private Integer index;

  //设备类型
  public Integer getType( ){
    return type;
  }

  public void setType(Integer type){
    this.type = type;
  }

  //设备名称
  public String getName( ){
    return name;
  }

  public void setName(String name){
    this.name = name;
  }

  //状态数
  public Integer getStateNum( ){
    return stateNum;
  }

  public void setStateNum(Integer stateNum){
    this.stateNum = stateNum;
  }

  //状态1出力(比率)
  public Double getState1Rate( ){
    return state1Rate;
  }

  public void setState1Rate(Double state1Rate){
    this.state1Rate = state1Rate;
  }

  //状态2出力(比率)
  public Double getState2Rate( ){
    return state2Rate;
  }

  public void setState2Rate(Double state2Rate){
    this.state2Rate = state2Rate;
  }

  //状态3出力(比率)
  public Double getState3Rate( ){
    return state3Rate;
  }

  public void setState3Rate(Double state3Rate){
    this.state3Rate = state3Rate;
  }

  //状态4出力(比率)
  public Double getState4Rate( ){
    return state4Rate;
  }

  public void setState4Rate(Double state4Rate){
    this.state4Rate = state4Rate;
  }

  //状态5出力(比率)
  public Double getState5Rate( ){
    return state5Rate;
  }

  public void setState5Rate(Double state5Rate){
    this.state5Rate = state5Rate;
  }

  //状态6出力(比率)
  public Double getState6Rate( ){
    return state6Rate;
  }

  public void setState6Rate(Double state6Rate){
    this.state6Rate = state6Rate;
  }

  //状态7出力(比率)
  public Double getState7Rate( ){
    return state7Rate;
  }

  public void setState7Rate(Double state7Rate){
    this.state7Rate = state7Rate;
  }

  //状态8出力(比率)
  public Double getState8Rate( ){
    return state8Rate;
  }

  public void setState8Rate(Double state8Rate){
    this.state8Rate = state8Rate;
  }

  //状态1概率
  public Double getState1Prob( ){
    return state1Prob;
  }

  public void setState1Prob(Double state1Prob){
    this.state1Prob = state1Prob;
  }

  //状态2概率
  public Double getState2Prob( ){
    return state2Prob;
  }

  public void setState2Prob(Double state2Prob){
    this.state2Prob = state2Prob;
  }

  //状态3概率
  public Double getState3Prob( ){
    return state3Prob;
  }

  public void setState3Prob(Double state3Prob){
    this.state3Prob = state3Prob;
  }

  //状态4概率
  public Double getState4Prob( ){
    return state4Prob;
  }

  public void setState4Prob(Double state4Prob){
    this.state4Prob = state4Prob;
  }

  //状态5概率
  public Double getState5Prob( ){
    return state5Prob;
  }

  public void setState5Prob(Double state5Prob){
    this.state5Prob = state5Prob;
  }

  //状态6概率
  public Double getState6Prob( ){
    return state6Prob;
  }

  public void setState6Prob(Double state6Prob){
    this.state6Prob = state6Prob;
  }

  //状态7概率
  public Double getState7Prob( ){
    return state7Prob;
  }

  public void setState7Prob(Double state7Prob){
    this.state7Prob = state7Prob;
  }

  //状态8概率
  public Double getState8Prob( ){
    return state8Prob;
  }

  public void setState8Prob(Double state8Prob){
    this.state8Prob = state8Prob;
  }

  //状态1-1转移率(次/年)
  public Double getState1Freq1( ){
    return state1Freq1;
  }

  public void setState1Freq1(Double state1Freq1){
    this.state1Freq1 = state1Freq1;
  }

  //状态1-2转移率(次/年)
  public Double getState1Freq2( ){
    return state1Freq2;
  }

  public void setState1Freq2(Double state1Freq2){
    this.state1Freq2 = state1Freq2;
  }

  //状态1-3转移率(次/年)
  public Double getState1Freq3( ){
    return state1Freq3;
  }

  public void setState1Freq3(Double state1Freq3){
    this.state1Freq3 = state1Freq3;
  }

  //状态1-4转移率(次/年)
  public Double getState1Freq4( ){
    return state1Freq4;
  }

  public void setState1Freq4(Double state1Freq4){
    this.state1Freq4 = state1Freq4;
  }

  //状态1-5转移率(次/年)
  public Double getState1Freq5( ){
    return state1Freq5;
  }

  public void setState1Freq5(Double state1Freq5){
    this.state1Freq5 = state1Freq5;
  }

  //状态1-6转移率(次/年)
  public Double getState1Freq6( ){
    return state1Freq6;
  }

  public void setState1Freq6(Double state1Freq6){
    this.state1Freq6 = state1Freq6;
  }

  //状态1-7转移率(次/年)
  public Double getState1Freq7( ){
    return state1Freq7;
  }

  public void setState1Freq7(Double state1Freq7){
    this.state1Freq7 = state1Freq7;
  }

  //状态1-8转移率(次/年)
  public Double getState1Freq8( ){
    return state1Freq8;
  }

  public void setState1Freq8(Double state1Freq8){
    this.state1Freq8 = state1Freq8;
  }

  //状态2-1转移率(次/年)
  public Double getState2Freq1( ){
    return state2Freq1;
  }

  public void setState2Freq1(Double state2Freq1){
    this.state2Freq1 = state2Freq1;
  }

  //状态2-2转移率(次/年)
  public Double getState2Freq2( ){
    return state2Freq2;
  }

  public void setState2Freq2(Double state2Freq2){
    this.state2Freq2 = state2Freq2;
  }

  //状态2-3转移率(次/年)
  public Double getState2Freq3( ){
    return state2Freq3;
  }

  public void setState2Freq3(Double state2Freq3){
    this.state2Freq3 = state2Freq3;
  }

  //状态2-4转移率(次/年)
  public Double getState2Freq4( ){
    return state2Freq4;
  }

  public void setState2Freq4(Double state2Freq4){
    this.state2Freq4 = state2Freq4;
  }

  //状态2-5转移率(次/年)
  public Double getState2Freq5( ){
    return state2Freq5;
  }

  public void setState2Freq5(Double state2Freq5){
    this.state2Freq5 = state2Freq5;
  }

  //状态2-6转移率(次/年)
  public Double getState2Freq6( ){
    return state2Freq6;
  }

  public void setState2Freq6(Double state2Freq6){
    this.state2Freq6 = state2Freq6;
  }

  //状态2-7转移率(次/年)
  public Double getState2Freq7( ){
    return state2Freq7;
  }

  public void setState2Freq7(Double state2Freq7){
    this.state2Freq7 = state2Freq7;
  }

  //状态2-8转移率(次/年)
  public Double getState2Freq8( ){
    return state2Freq8;
  }

  public void setState2Freq8(Double state2Freq8){
    this.state2Freq8 = state2Freq8;
  }

  //状态3-1转移率(次/年)
  public Double getState3Freq1( ){
    return state3Freq1;
  }

  public void setState3Freq1(Double state3Freq1){
    this.state3Freq1 = state3Freq1;
  }

  //状态3-2转移率(次/年)
  public Double getState3Freq2( ){
    return state3Freq2;
  }

  public void setState3Freq2(Double state3Freq2){
    this.state3Freq2 = state3Freq2;
  }

  //状态3-3转移率(次/年)
  public Double getState3Freq3( ){
    return state3Freq3;
  }

  public void setState3Freq3(Double state3Freq3){
    this.state3Freq3 = state3Freq3;
  }

  //状态3-4转移率(次/年)
  public Double getState3Freq4( ){
    return state3Freq4;
  }

  public void setState3Freq4(Double state3Freq4){
    this.state3Freq4 = state3Freq4;
  }

  //状态3-5转移率(次/年)
  public Double getState3Freq5( ){
    return state3Freq5;
  }

  public void setState3Freq5(Double state3Freq5){
    this.state3Freq5 = state3Freq5;
  }

  //状态3-6转移率(次/年)
  public Double getState3Freq6( ){
    return state3Freq6;
  }

  public void setState3Freq6(Double state3Freq6){
    this.state3Freq6 = state3Freq6;
  }

  //状态3-7转移率(次/年)
  public Double getState3Freq7( ){
    return state3Freq7;
  }

  public void setState3Freq7(Double state3Freq7){
    this.state3Freq7 = state3Freq7;
  }

  //状态3-8转移率(次/年)
  public Double getState3Freq8( ){
    return state3Freq8;
  }

  public void setState3Freq8(Double state3Freq8){
    this.state3Freq8 = state3Freq8;
  }

  //状态4-1转移率(次/年)
  public Double getState4Freq1( ){
    return state4Freq1;
  }

  public void setState4Freq1(Double state4Freq1){
    this.state4Freq1 = state4Freq1;
  }

  //状态4-2转移率(次/年)
  public Double getState4Freq2( ){
    return state4Freq2;
  }

  public void setState4Freq2(Double state4Freq2){
    this.state4Freq2 = state4Freq2;
  }

  //状态4-3转移率(次/年)
  public Double getState4Freq3( ){
    return state4Freq3;
  }

  public void setState4Freq3(Double state4Freq3){
    this.state4Freq3 = state4Freq3;
  }

  //状态4-4转移率(次/年)
  public Double getState4Freq4( ){
    return state4Freq4;
  }

  public void setState4Freq4(Double state4Freq4){
    this.state4Freq4 = state4Freq4;
  }

  //状态4-5转移率(次/年)
  public Double getState4Freq5( ){
    return state4Freq5;
  }

  public void setState4Freq5(Double state4Freq5){
    this.state4Freq5 = state4Freq5;
  }

  //状态4-6转移率(次/年)
  public Double getState4Freq6( ){
    return state4Freq6;
  }

  public void setState4Freq6(Double state4Freq6){
    this.state4Freq6 = state4Freq6;
  }

  //状态4-7转移率(次/年)
  public Double getState4Freq7( ){
    return state4Freq7;
  }

  public void setState4Freq7(Double state4Freq7){
    this.state4Freq7 = state4Freq7;
  }

  //状态4-8转移率(次/年)
  public Double getState4Freq8( ){
    return state4Freq8;
  }

  public void setState4Freq8(Double state4Freq8){
    this.state4Freq8 = state4Freq8;
  }

  //状态5-1转移率(次/年)
  public Double getState5Freq1( ){
    return state5Freq1;
  }

  public void setState5Freq1(Double state5Freq1){
    this.state5Freq1 = state5Freq1;
  }

  //状态5-2转移率(次/年)
  public Double getState5Freq2( ){
    return state5Freq2;
  }

  public void setState5Freq2(Double state5Freq2){
    this.state5Freq2 = state5Freq2;
  }

  //状态5-3转移率(次/年)
  public Double getState5Freq3( ){
    return state5Freq3;
  }

  public void setState5Freq3(Double state5Freq3){
    this.state5Freq3 = state5Freq3;
  }

  //状态5-4转移率(次/年)
  public Double getState5Freq4( ){
    return state5Freq4;
  }

  public void setState5Freq4(Double state5Freq4){
    this.state5Freq4 = state5Freq4;
  }

  //状态5-5转移率(次/年)
  public Double getState5Freq5( ){
    return state5Freq5;
  }

  public void setState5Freq5(Double state5Freq5){
    this.state5Freq5 = state5Freq5;
  }

  //状态5-6转移率(次/年)
  public Double getState5Freq6( ){
    return state5Freq6;
  }

  public void setState5Freq6(Double state5Freq6){
    this.state5Freq6 = state5Freq6;
  }

  //状态5-7转移率(次/年)
  public Double getState5Freq7( ){
    return state5Freq7;
  }

  public void setState5Freq7(Double state5Freq7){
    this.state5Freq7 = state5Freq7;
  }

  //状态5-8转移率(次/年)
  public Double getState5Freq8( ){
    return state5Freq8;
  }

  public void setState5Freq8(Double state5Freq8){
    this.state5Freq8 = state5Freq8;
  }

  //状态6-1转移率(次/年)
  public Double getState6Freq1( ){
    return state6Freq1;
  }

  public void setState6Freq1(Double state6Freq1){
    this.state6Freq1 = state6Freq1;
  }

  //状态6-2转移率(次/年)
  public Double getState6Freq2( ){
    return state6Freq2;
  }

  public void setState6Freq2(Double state6Freq2){
    this.state6Freq2 = state6Freq2;
  }

  //状态6-3转移率(次/年)
  public Double getState6Freq3( ){
    return state6Freq3;
  }

  public void setState6Freq3(Double state6Freq3){
    this.state6Freq3 = state6Freq3;
  }

  //状态6-4转移率(次/年)
  public Double getState6Freq4( ){
    return state6Freq4;
  }

  public void setState6Freq4(Double state6Freq4){
    this.state6Freq4 = state6Freq4;
  }

  //状态6-5转移率(次/年)
  public Double getState6Freq5( ){
    return state6Freq5;
  }

  public void setState6Freq5(Double state6Freq5){
    this.state6Freq5 = state6Freq5;
  }

  //状态6-6转移率(次/年)
  public Double getState6Freq6( ){
    return state6Freq6;
  }

  public void setState6Freq6(Double state6Freq6){
    this.state6Freq6 = state6Freq6;
  }

  //状态6-7转移率(次/年)
  public Double getState6Freq7( ){
    return state6Freq7;
  }

  public void setState6Freq7(Double state6Freq7){
    this.state6Freq7 = state6Freq7;
  }

  //状态6-8转移率(次/年)
  public Double getState6Freq8( ){
    return state6Freq8;
  }

  public void setState6Freq8(Double state6Freq8){
    this.state6Freq8 = state6Freq8;
  }

  //状态7-1转移率(次/年)
  public Double getState7Freq1( ){
    return state7Freq1;
  }

  public void setState7Freq1(Double state7Freq1){
    this.state7Freq1 = state7Freq1;
  }

  //状态7-2转移率(次/年)
  public Double getState7Freq2( ){
    return state7Freq2;
  }

  public void setState7Freq2(Double state7Freq2){
    this.state7Freq2 = state7Freq2;
  }

  //状态7-3转移率(次/年)
  public Double getState7Freq3( ){
    return state7Freq3;
  }

  public void setState7Freq3(Double state7Freq3){
    this.state7Freq3 = state7Freq3;
  }

  //状态7-4转移率(次/年)
  public Double getState7Freq4( ){
    return state7Freq4;
  }

  public void setState7Freq4(Double state7Freq4){
    this.state7Freq4 = state7Freq4;
  }

  //状态7-5转移率(次/年)
  public Double getState7Freq5( ){
    return state7Freq5;
  }

  public void setState7Freq5(Double state7Freq5){
    this.state7Freq5 = state7Freq5;
  }

  //状态7-6转移率(次/年)
  public Double getState7Freq6( ){
    return state7Freq6;
  }

  public void setState7Freq6(Double state7Freq6){
    this.state7Freq6 = state7Freq6;
  }

  //状态7-7转移率(次/年)
  public Double getState7Freq7( ){
    return state7Freq7;
  }

  public void setState7Freq7(Double state7Freq7){
    this.state7Freq7 = state7Freq7;
  }

  //状态7-8转移率(次/年)
  public Double getState7Freq8( ){
    return state7Freq8;
  }

  public void setState7Freq8(Double state7Freq8){
    this.state7Freq8 = state7Freq8;
  }

  //状态8-1转移率(次/年)
  public Double getState8Freq1( ){
    return state8Freq1;
  }

  public void setState8Freq1(Double state8Freq1){
    this.state8Freq1 = state8Freq1;
  }

  //状态8-2转移率(次/年)
  public Double getState8Freq2( ){
    return state8Freq2;
  }

  public void setState8Freq2(Double state8Freq2){
    this.state8Freq2 = state8Freq2;
  }

  //状态8-3转移率(次/年)
  public Double getState8Freq3( ){
    return state8Freq3;
  }

  public void setState8Freq3(Double state8Freq3){
    this.state8Freq3 = state8Freq3;
  }

  //状态8-4转移率(次/年)
  public Double getState8Freq4( ){
    return state8Freq4;
  }

  public void setState8Freq4(Double state8Freq4){
    this.state8Freq4 = state8Freq4;
  }

  //状态8-5转移率(次/年)
  public Double getState8Freq5( ){
    return state8Freq5;
  }

  public void setState8Freq5(Double state8Freq5){
    this.state8Freq5 = state8Freq5;
  }

  //状态8-6转移率(次/年)
  public Double getState8Freq6( ){
    return state8Freq6;
  }

  public void setState8Freq6(Double state8Freq6){
    this.state8Freq6 = state8Freq6;
  }

  //状态8-7转移率(次/年)
  public Double getState8Freq7( ){
    return state8Freq7;
  }

  public void setState8Freq7(Double state8Freq7){
    this.state8Freq7 = state8Freq7;
  }

  //状态8-8转移率(次/年)
  public Double getState8Freq8( ){
    return state8Freq8;
  }

  public void setState8Freq8(Double state8Freq8){
    this.state8Freq8 = state8Freq8;
  }

  //设备索引
  public Integer getIndex( ){
    return index;
  }

  public void setIndex(Integer index){
    this.index = index;
  }

}
