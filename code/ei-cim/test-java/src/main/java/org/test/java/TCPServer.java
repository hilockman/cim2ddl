package org.test.java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServer {

//	public static void main(String [] args) throws IOException {
//	
//		ServerSocket ss = new ServerSocket(6666);
//		while (true) {
//			Socket s = ss.accept();
//			DataInputStream dis = new DataInputStream(s.getInputStream());
//			String str = null;
//			while ((str = dis.readUTF()) != null) {
//				System.out.println(dis.readUTF());
//			}
//			
//			dis.close();
//			//System.out.println("A client accepted!");
//			s.close();
//		}
//
//	}
	
	
	
	public static void main(String [] args) throws IOException {
		
		ServerSocket ss = new ServerSocket(6666);
		while (true) {
			Socket s = ss.accept();
			System.out.println("Accept : ip ="+s.getInetAddress()+", port="+s.getPort());
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			String str = null;
			while ((str = br.readLine()) != null) {
				str = str.trim();
				if (str.isEmpty())
					System.out.println("(nil)");
				else
					System.out.println("Rec :  "+str);
			}
			
			br.close();
			//System.out.println("A client accepted!");
			s.close();
		}

	}
}
