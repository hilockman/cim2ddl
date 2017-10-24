import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;


public class QTCPServer {
	@SuppressWarnings({ "resource" })
	public static void main(String[] args) throws IOException {
		int port = 6666;
		if (args.length > 0)
			port = Integer.valueOf(args[0]);
		
		ServerSocket ss = new ServerSocket(port);
		System.out.println("Start server, listen on port:"+port);
		//byte cbuf[] = new byte[1024];
		char cbuff[] = new char[1024];
		while (true) {
			Socket s = ss.accept();
			System.out.println("A client connected");
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			StringBuffer buffer = new StringBuffer();
			int size = 0;
			while ((size = br.read(cbuff, 0, cbuff.length)) != -1) {
				buffer.append(new String(cbuff, 0, size));
			}
			
			System.out.println(buffer.toString());
			br.close();
			
//			DataInputStream dis = new DataInputStream(s.getInputStream());
//			System.out.println(dis.readUTF());
//			dis.close();
//			InputStream is = s.getInputStream();
//			int len = is.read(cbuf);
//			System.out.println(new String(cbuf,0, len, "UTF-8"));
//			is.close();
			//br.close();
			s.close();
		}
	}
}
