package com.znd.ei.tcptest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.stereotype.Component;

import com.znd.ei.Utils;
import com.znd.ei.memdb.reliabilty.dao.FStateDao;
import com.znd.ei.memdb.reliabilty.domain.FState;

@Component
public class TCPClient {
	@Autowired
	private TcpTestProperties properties;

	@Autowired
	private TCPServer tcpServer;

	@Autowired
	private FStateDao fstateDao;

	@Autowired
	private ApplicationContext context;

	public static void main(String args[]) throws UnknownHostException,
			IOException {
		Socket s = new Socket("127.0.0.1", 6666);

		OutputStream os = s.getOutputStream();

		DataOutputStream dos = new DataOutputStream(os);
		dos.writeUTF("Hello, sever!");
		dos.flush();
		dos.close();
		s.close();

	}

	ExecutorService threadPool;

	public TCPClient() {
		threadPool = Executors.newCachedThreadPool();

	}
	
	private Byte sendFlag = new Byte((byte) 0);

	public void start() {

		final String serverIp = properties.getServerIp();
		final Integer serverPort = properties.getServerPort();

		//Runnable w = () -> {

			long count = 0;
			while ((count = fstateDao.count()) == 0) {
				try {
					Thread.sleep(1000);
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}

			Iterable<FState> records = fstateDao.findAll();

			for (final FState state : records) {

				//System.out.println("Load record : " + state.toString());

				synchronized(sendFlag) {
					
				}

				try {
					SocketProccess p = (ServerSocket serverSocket) -> {

						boolean responsed = false;
						Socket inputSocket = null;
						Socket ouputSocket = null;
						while (!responsed) {
							inputSocket = null;
							ouputSocket = null;
							synchronized(sendFlag) {
								while (ouputSocket == null) {
									System.out.println(String.format(
											"try to connect to server : ip:%s, port:%d",
											serverIp, serverPort));

									try {
										ouputSocket = new Socket(serverIp, serverPort);
									} catch (IOException e1) {
										System.err.println("Fail to connect to server.");
										try {
											Thread.sleep(2000);
										} catch (InterruptedException e) {
											// TODO Auto-generated catch block
											e.printStackTrace();
										}
									}
								}								
							}


							
							String str = Utils.toJSon(state);
							System.out.println("Send data :\n" + str);

							try {
								BufferedWriter bw = new BufferedWriter(
										new OutputStreamWriter(
												ouputSocket.getOutputStream()));
								bw.write(str);
								bw.flush();
								bw.close();
								ouputSocket.close();
							} catch (IOException e1) {
								// TODO Auto-generated catch block
								//e1.printStackTrace();
								System.out.println("Fail to send data, prepare to send data again:"+ e1.getMessage());
								continue;
							}
							Integer timeout = properties.getServerTimeOut();
							System.out.println(String.format(
									"Wait for result, timeout = %d ...", timeout));
							

							Future<Socket> rt = threadPool
									.submit(new Callable<Socket>() {

										@Override
										public Socket call() {
											synchronized (serverSocket) {
												Socket responseSocket = null;
												try {
													responseSocket = serverSocket
															.accept();
													System.out.println("A client connected from "
															+ responseSocket
																	.getInetAddress()
															+ ", port : "
															+ responseSocket.getPort());													
												} catch (Exception e) {
													// TODO Auto-generated catch
													// block
													//e.printStackTrace();
												}

												return responseSocket;
											}
											
										}
									});

							try {
								inputSocket = rt.get(timeout, TimeUnit.MILLISECONDS);
							} catch (Exception e1) {
								// TODO Auto-generated catch block
								//e1.printStackTrace();
								//System.err.println(e1.getMessage());
								System.err.println("Fail to get result, prepare to send data again.");
								try {
									Thread.sleep(2000);
								} catch (Exception e) {
									// TODO Auto-generated catch block
									e.printStackTrace();
								}
							}
							
							responsed = (inputSocket != null);
							//responsed = true;
						}

						try {
							char cbuff[] = new char[1024];
							BufferedReader br;

							br = new BufferedReader(new InputStreamReader(
									inputSocket.getInputStream()));
							StringBuffer buffer = new StringBuffer();
							int size = 0;
							while ((size = br.read(cbuff, 0, cbuff.length)) != -1) {
								buffer.append(new String(cbuff, 0, size));
							}

							System.out.println("Receive result : "+", size = "+buffer.length()
									+"\n "+ buffer.toString());

							br.close();
							inputSocket.close();

							StateEstimateResult result = Utils.toObject(
									buffer.toString(),
									StateEstimateResult.class);
							if (result != null) {
								System.out
										.println("Succeed to parse result : \n");
								System.out
										.println(String
												.format("   dev count= %d, ovlAd count = %d, ovlDev count = %d",
														(result.getDevs() != null ? result
																.getDevs()
																.size() : 0),
														(result.getOvlAds() != null ? result
																.getOvlAds()
																.size() : 0),
														(result.getOvlDevs() != null ? result
																.getOvlDevs()
																.size() : 0)));
							} else {
								System.err.println("Fail to parse result.");
							}
						} catch (Exception e) {
							System.err.println(e.getMessage());
							e.printStackTrace();
						}
					};

					tcpServer.execute(p);
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}

			System.out.println("Process finished : state count = " + count);

			//SpringApplication.exit(context);
//		};
//
//		Thread r = new Thread(w);
//		r.start();
		// try {
		// r.join();
		// } catch (InterruptedException e) {
		// // TODO Auto-generated catch block
		// e.printStackTrace();
		// }

	}
}
