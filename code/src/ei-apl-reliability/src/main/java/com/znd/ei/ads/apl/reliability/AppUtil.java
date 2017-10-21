package com.znd.ei.ads.apl.reliability;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;

import com.znd.ei.memdb.MemTableRepository;

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
	public static <T> void clearTable( MemTableRepository<T> dao)
	{
		dao.deleteAll();
	}
	
	public static <T> void clearAndSave(List<T> records, MemTableRepository<T> dao) {
		
		
		if (records == null) {
			return;
		}

		
		if (records.isEmpty()) {	
			dao.deleteAll();
			return;
		}
		Class<T> clazz = null;
		try {
		 clazz = (Class<T>) records.get(0).getClass();
		} catch (SecurityException e) {
			e.printStackTrace();
		}
		System.out.println(String.format("clear %s table.", clazz.getName()));
		dao.deleteAll();
		
		System.out.println(String.format("write %d records into %s table.", records.size(), clazz.getName()));
		dao.saveOrUpdate(records);
	}
	
	public static void execute(String appPath, AppLogger appLogger, String... args) {
		StringBuffer cmd = new StringBuffer();
		cmd.append(appPath);

		List<String> params = Arrays.asList(args);
		for (String param : params) {
			cmd.append(" "+param);
		}
		if (appLogger != null) {
			appLogger.print(cmd.toString());
		} else
			System.out.println(cmd);
		
		try {
			Process process = Runtime.getRuntime().exec(cmd.toString());
			InputStream is = process.getInputStream();
			print(is, appLogger);
			
			InputStream eis = process.getErrorStream();
			print(eis, appLogger);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}	
	}
	
	/**
	 * 
	 * @param appPath
	 * @param T
	 */
	public static void execute(String appPath, String... args) {
		execute(appPath, null, args);
	}

	public static void print(InputStream is, AppLogger appLogger) throws IOException {
		BufferedReader bri = new BufferedReader(new InputStreamReader(is, "gbk"));
		
		String message = new String("");
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
		return new AppExecuteBuilder(appPath);
	}


}
