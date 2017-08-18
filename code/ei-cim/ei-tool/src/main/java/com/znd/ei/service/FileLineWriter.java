package com.znd.ei.service;


public interface FileLineWriter {
	void write(String line, int dent);
	void write(String line);
	void write();
}
