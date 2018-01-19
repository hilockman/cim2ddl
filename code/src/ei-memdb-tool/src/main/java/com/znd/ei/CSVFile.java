package com.znd.ei;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class CSVFile {
	private BufferedWriter  bufferWriter;
	private String path;
	public final class CSVLine {
		int pos = -1;
		public CSVLine() {
			
		}
		
		public  CSVLine add(String v) {
			try {
				if (pos++>=0) {
					bufferWriter.write(',');
				}				
				if (v == null)
					return this;
				
				v = v.trim();
				boolean f = (v.indexOf(',') >= 0);
				if (f)
					bufferWriter.write('"');
				bufferWriter.write(v);
				if (f)
				   bufferWriter.write('"');
			
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			return this;
		}
		
		public void end() {
			try {
				bufferWriter.newLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		public CSVLine add(Integer v) {
			return add(String.valueOf(v));
		}


		
	}
	

	
	public CSVFile(String fileName) {
		try {
			bufferWriter = new BufferedWriter(new FileWriter(fileName));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		path = fileName;
	}
	
	public CSVLine line() {
		return new CSVLine();
	}
	
	public void close() {
		try {
			if (bufferWriter != null)
			  bufferWriter.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public String getPath() {
		return path;
	}
	
}
