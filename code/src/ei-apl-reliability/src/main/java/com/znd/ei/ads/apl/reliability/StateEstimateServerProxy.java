package com.znd.ei.ads.apl.reliability;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import com.znd.ei.Utils;
import com.znd.ei.ads.apl.reliability.bean.DataReady;

@Component
public class StateEstimateServerProxy {
	private static final Logger logger = LoggerFactory
			.getLogger(StateEstimateServerProxy.class);

	@Value("${ads.appDir}")
	private String baseDir;

	private AppExecuteBuilder appExec;

	private ExecutorService pool;

	private ServerSocket socketServer;

	@Autowired
	StateEstimateProperties properties;

	// private boolean quit = false;
	@PostConstruct
	public void init() {
		pool = Executors.newCachedThreadPool();
		new Thread(
				() -> {
					if (AppUtil.checkAppIsRunning("GCStateEstimateServer")) {
						logger.info("***********StateEstimateServer is running ****************");
					} else {
						logger.info("***********StateEstimateServer start****************");
						appExec = AppUtil.execBuilder(baseDir
								+ "/GCStateEstimateServer");
						appExec.exec();
					}
				}).start();
	}

	@PreDestroy
	public void destory() {
		new Thread(
				() -> {
					if (appExec != null) {
						appExec.terminate();
						logger.info("***********StateEstimateServer exit****************");
					}
					stopListenResult();

				}).start();
	}

	private void sendData(Object data) {
		Socket client = null;

		logger.info(String.format(
				"Try to connect to estimate server : ip:%s, port:%d",
				properties.getServerIp(), properties.getServerPort()));

		try {
			client = new Socket(properties.getServerIp(),
					properties.getServerPort());
		} catch (IOException e1) {
			logger.error("Fail to connect to server.");
			try {
				Thread.sleep(2000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String sendData = Utils.toJSon(data);

		System.out.println("Send data :\n" + sendData);

		try {
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
					client.getOutputStream()));
			bw.write(sendData);
			bw.flush();
			bw.close();
			client.close();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	}

	private String waitForDataReadyResponse(final long timeout) {

		Future<String> rt = pool.submit(new Callable<String>() {

			@Override
			public String call() throws Exception {
				try {
					Socket s = socketServer.accept();
					logger.info("A client connected from " + s.getInetAddress()
							+ ", port : " + s.getPort());
					return readData(s);
				} catch (IOException e1) {
					logger.info("Socket server interrupte!");
				}

				return null;
			}

		});

		try {
			return rt.get(timeout, TimeUnit.SECONDS);
		} catch (InterruptedException | ExecutionException | TimeoutException e) {

			try {
				socketServer.close();
				socketServer = null;
			} catch (IOException e1) {

				e1.printStackTrace();
			}
		}

		return null;
	}

	private void startListen() {
		try {
			socketServer = new ServerSocket(properties.getListenPort());
		} catch (IOException e1) {
			e1.printStackTrace();
			return;
		}
		logger.info("Start state estimate listen on port:"
				+ properties.getListenPort());

	}

	private String readData(Socket s) {
		char cbuff[] = new char[1024];
		BufferedReader br;
		try {
			br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			StringBuffer buffer = new StringBuffer();
			int size = 0;
			while ((size = br.read(cbuff, 0, cbuff.length)) != -1) {
				buffer.append(new String(cbuff, 0, size));
			}

			br.close();
			return buffer.toString();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return null;
	}

	public void stopListenResult() {
		if (socketServer != null) {
			try {
				socketServer.close();
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			socketServer = null;
		}
	}

	private <T> void startListenResult(MessageListener<T> l) {
		new Thread(() -> {
			try {
				while (true) {
					final Socket s = socketServer.accept();
					System.out.println("A client connected from "
							+ s.getInetAddress() + ", port : " + s.getPort());
					pool.execute(() -> {
						String data = readData(s);
						if (data != null) {
							logger.info("Received data : " + data);
							T obj = Utils.toObject(data, l.getMessageClass());
							l.onMessage(obj);
						}

					});
				}
			} catch (Exception e) {
				logger.error(e.getMessage());
			} finally {
				stopListenResult();
			}
		}).start();
	}

	public <T> void sendDataReady(MessageListener<T> l) {
		startListen();
		sendData(new DataReady());
		String response = waitForDataReadyResponse(properties.getReadyResponseTimeOut());
		if (!response.contains(DataReady.DATA_READY)) {
			logger.info("Response data is not : " + DataReady.DATA_READY);
			return;
		}
		startListenResult(l);
	}

}
