import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;
import java.net.UnknownHostException;


public class ConnectTest {
    public ConnectTest(){
   	 try {
   		Socket s = new Socket("127.0.0.1",8888);
//   		DataInputStream dr =new DataInputStream(s.getInputStream());
//   		String str = dr.readUTF();
//   		System.out.println(str);
   		InputStream is = s.getInputStream();
   		 byte[] by=new byte[1024];
   		 is.read(by);
   		 String str=new String(by, "utf-8");
   		 System.out.println(str);
   		 is.close();
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
    }
    
    public static void main(String[] args){
   	 new ConnectTest();
    }
}
