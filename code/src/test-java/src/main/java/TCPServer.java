import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServer {

	@SuppressWarnings("deprecation")
	public static void main(String[] args) throws IOException {
		ServerSocket ss = new ServerSocket(6666);

		byte cbuf[] = new byte[1024];
		while (true) {
			Socket s = ss.accept();
			System.out.println("A client connected");

			InputStream is = s.getInputStream();
			//DataInputStream dis = new DataInputStream(s.getInputStream());
			//System.out.println(dis.readUTF());

			//dis.close();
			int len = is.read(cbuf, 0, cbuf.length);
			System.out.println(new String(cbuf));
			is.close();
			//br.close();
			s.close();
		}
	}
}
