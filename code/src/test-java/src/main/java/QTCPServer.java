import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class QTCPServer {
	@SuppressWarnings({ "resource" })
	public static void main(String[] args) throws IOException {
		
		File file = new File(System.getProperty("user.dir")+"/estimate_result.json"); 
		BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
		String line = null;
		StringBuffer bf = new StringBuffer();
		while ((line = r.readLine()) != null) {
			bf.append(line);
			System.out.println("line : "+line);
		}
		
		String testData = bf.toString();
		int port = 6666;
		if (args.length > 0)
			port = Integer.valueOf(args[0]);

		ServerSocket ss = new ServerSocket(port);
		System.out.println("Start server, listen on port:" + port);
		// byte cbuf[] = new byte[1024];
		char cbuff[] = new char[1024];
		while (true) {
			Socket s = ss.accept();
			System.out.println("A client connected from " + s.getInetAddress()
					+ ", port : " + s.getPort());
			BufferedReader br = new BufferedReader(new InputStreamReader(
					s.getInputStream()));
			StringBuffer buffer = new StringBuffer();
			int size = 0;
			while ((size = br.read(cbuff, 0, cbuff.length)) != -1) {
				buffer.append(new String(cbuff, 0, size));
			}

			System.out.println(buffer.toString());
			br.close();

			// DataInputStream dis = new DataInputStream(s.getInputStream());
			// System.out.println(dis.readUTF());
			// dis.close();
			// InputStream is = s.getInputStream();
			// int len = is.read(cbuf);
			// System.out.println(new String(cbuf,0, len, "UTF-8"));
			// is.close();
			// br.close();
			s.close();

			Socket client = null;
			String serverIp = "127.0.0.1";
			Integer serverPort = 9002;

			System.out.println(String.format(
					"try to connect to server : ip:%s, port:%d", serverIp,
					serverPort));

			try {
				client = new Socket(serverIp, serverPort);
			} catch (IOException e1) {
				System.err.println("Fail to connect to server.");
				try {
					Thread.sleep(2000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}

			
		
			System.out.println("Send data :\n" + testData);

			try {
				BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
						client.getOutputStream()));
				bw.write(testData);
				bw.flush();
				bw.close();
				client.close();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
	}


}
