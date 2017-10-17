package com.znd.ei.codegen.service;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;

public class CodeTemplateContext {

	private List<CodeBlockNode> topNodes;
	
	private int dent;
	

	
	public CodeTemplateContext()
	{
		topNodes = new ArrayList<CodeBlockNode>();
		dent = 2;
	}
	
	public CodeBlockNode add(CodeBlock block) {
		CodeBlockNode node = new CodeBlockNode(block);
		topNodes.add(node);
		return node;
	}
	

	public int getDent() {
		return dent;
	}

	public void setDent(int dent) {
		this.dent = dent;
	}
	
	private void write(CodeBlockNode node, FileLineWriter w, int pos){  
        List<CodeBlockNode> children = node.getChilds();  
    	w.setDent(pos);
        node.getBlock().write(w);
        if (children != null && !children.isEmpty()) {  
            w.write("{", pos);
            for (CodeBlockNode child : children) {  
                write(child, w, pos+dent);  
            }  
            
            w.write("}", pos);  
            w.write("");
        }   
    }  
	
	class MyLineWriter implements FileLineWriter {
		private OutputStreamWriter out;
		private int dent;

		public MyLineWriter(OutputStreamWriter o) {
			this.out = o;
			dent = 0;
		}

		@Override
		public void write(String line) {
			write(line, dent);
		}

		@Override
		public void write() {
			write("");
		}

		@Override
		public void write(String line, int dent) {
			try {
				String sdent = "";
				if (dent > 0) {
					char[] cs = new char[dent];
					for (int i = 0; i < dent; i++) {
						cs[i] = ' ';
					}

					sdent = new String(cs);
				}
				out.append(sdent + line + "\r\n");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		@Override
		public void setDent(int pos) {
			dent = pos;
		}

		@Override
		public void writeln(String paramString) {
			write(paramString+";");
		}
	};

	
	public void save(String fileName) {
		if (topNodes == null || topNodes.isEmpty())
			return;
		
		File file = new File(fileName);

		FileOutputStream out = null;
		try {

			out = new FileOutputStream(file);
			OutputStreamWriter oStreamWriter = new OutputStreamWriter(out,
					"utf-8");
			FileLineWriter w = new MyLineWriter(oStreamWriter);
			int pos = 0;
	        for (CodeBlockNode node : topNodes) {  
	            write(node, w, pos); 
	        } 
	        
			oStreamWriter.flush();
			oStreamWriter.close();
			out.close();

		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally {
			try {
				out.close();
			} catch (Exception e) {
				e.printStackTrace();
			}

		}

		
		

		
 	
	}



}
