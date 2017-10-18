package org.test.java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class TCPClient {

//	public static void main(String [] args) throws UnknownHostException, IOException {
//		Socket s = new Socket("127.0.0.1", 6666);
//		
//		OutputStream os = s.getOutputStream();
//		//BufferedInputStream bis = new BufferedInputStream(System.in);
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		String str = null;
//		System.out.print("Input > ");
//		DataOutputStream dos = new DataOutputStream(os);
//		
//		while ((str = br.readLine()) != null) {		
//			
//			System.out.println("Inputed :  "+str);
//			dos.writeUTF(str);
//			dos.flush();
//			System.out.print("Input > ");
//		}
//		
//		
//		dos.close();
//	}
	public static void main(String [] args) throws UnknownHostException, IOException {
		Socket s = new Socket("127.0.0.1", 6666);
		
		//OutputStream os = s.getOutputStream();
		//BufferedInputStream bis = new BufferedInputStream(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = null;
		System.out.print("Input > ");
		//DataOutputStream dos = new DataOutputStream(os);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "UTF-8"));
		while ((str = br.readLine()) != null) {		
			str = str.trim();
			if (str.isEmpty())
				System.out.println("nil");
			else
				System.out.println("Inputed :  "+str);
			bw.write(str+"\n");
			bw.flush();
			System.out.print("Input > ");
		}
		
		
		bw.close();
		s.close();
	}


}
