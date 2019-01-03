package com.znd.reliability.utils;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;

/**
 * 
 * @author wangheng
 *
 */
public class AppUtil {

	public static final String GC_BPA_LOADER = "GCBPALoader";
	public static final String GC_BPA_2_PR = "GCBPA2PR";
	public static final String GC_STATE_SAMPLE = "GCStateSample";

	public static final String GC_STATE_ESTIMATE = "GCStateEstimate";
	public static final String GC_RELIABILITY_INDEX = "GCReliabilityIndex";

	public static Process executeWithLogger(String appPath, AppLogger appLogger,
			Object... args) {
		StringBuffer cmd = new StringBuffer();
		cmd.append(appPath);

		List<Object> params = Arrays.asList(args);
		for (Object param : params) {
			cmd.append(" " + param);
		}
		if (appLogger != null) {
			appLogger.print("Exec: "+cmd.toString());
		} else
			System.out.println("Exec: "+cmd);

		try {
			Process process = Runtime.getRuntime().exec(cmd.toString());
			if (appLogger != null) {
				InputStream is = process.getInputStream();
				print(is, appLogger);

				InputStream eis = process.getErrorStream();
				print(eis, appLogger);
			}
			return process;
		} catch (IOException e) {
			e.printStackTrace();
		}

		return null;
	}

	/**
	 * 
	 * @param appPath
	 * @param T
	 */
	public static Process executeWithoutLogger(String appPath, Object... args) {
		return executeWithLogger(appPath, null, args);
	}
	
	
	public static Process execute(String appPath, Object... args) {
		return executeWithLogger(appPath, (log) -> {
			System.out.println(log);
		}, args);
	}
	
//	public static void print(InputStream is, AppLogger appLogger)
//			throws IOException {
//		BufferedReader bri = new BufferedReader(
//				new InputStreamReader(is, "gbk"));
//
//		String message = new String("<exec:app> ");
//		
//		for (int i = 0; i < is.available(); i++) {
//			message = bri.readLine();
//			if (appLogger == null)
//				System.out.println(message);
//			else
//				appLogger.print(message);
//		}
//
//
//		bri.close();
//	}
	public static void print(InputStream is, AppLogger appLogger)
			throws IOException {
		BufferedReader bri = new BufferedReader(
				new InputStreamReader(is, "gbk"));

		String message = new String("<exec:app> ");
		
		while ((message = bri.readLine()) != null) {
			if (appLogger == null)
				System.out.println(message);
			else
				appLogger.print(message);
		}

		bri.close();
	}

	public static void print(InputStream is) throws IOException {
		print(is, null);
	}

	public static AppExecuteBuilder execBuilder(String appPath) {
		return execBuilder(appPath, true);
	}

	public static AppExecuteBuilder execBuilder(String appPath,
			boolean appendAppPath) {
		return new AppExecuteBuilder(appPath, appendAppPath);
	}

	public static void main(String[] args) {
		boolean rt = isRunning("mysqld");
		System.out.println(rt);
	}

	public static boolean isRunning(String appName) {
		String line;
		String pidInfo = "";

		Process p;
		try {
			p = Runtime.getRuntime().exec(
					System.getenv("windir") + "\\system32\\" + "tasklist.exe");
			BufferedReader input = new BufferedReader(new InputStreamReader(
					p.getInputStream()));

			while ((line = input.readLine()) != null) {
				pidInfo += line;
			}

			input.close();

			if (pidInfo.contains(appName.endsWith(".exe") ? appName : appName
					+ ".exe")) {
				return true;
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return false;
	}

	public static void kill(String appName) {
		Runtime rt = Runtime.getRuntime();
		Process p = null;
		if (System.getProperty("os.name").toLowerCase().indexOf("windows") > -1) {
			try {

				p = rt.exec("taskkill /f /im " + appName
						+ (appName.endsWith(".exe") ? "" : ".exe"));

			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} else {
			try {
				p = rt.exec("kill -9 " + appName);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		if (p != null) {
			String line;
			try {
				BufferedReader input = new BufferedReader(
						new InputStreamReader(p.getInputStream(), "gbk"));
				while ((line = input.readLine()) != null) {
					System.out.println(line);
				}
				input.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

}
