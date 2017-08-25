package com.znd.ei.codegen.service;


public  interface FileLineWriter
{
  public  void write(String paramString, int paramInt);

  public  void write(String paramString);

  public  void write();

  public  void setDent(int pos);
}