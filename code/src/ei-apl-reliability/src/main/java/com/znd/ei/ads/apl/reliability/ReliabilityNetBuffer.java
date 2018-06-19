package com.znd.ei.ads.apl.reliability;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

import com.znd.ads.model.dto.FileInfo;
import com.znd.ei.Utils;
import com.znd.ei.ads.acp.AbstractConnectionFactory;
import com.znd.ei.ads.acp.ListDataOperations;
import com.znd.ei.ads.acp.MapDataOperations;
import com.znd.ei.ads.acp.ObjectRefDataOperations;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.MapData;

public class ReliabilityNetBuffer {		
	private String modelName;

	public static final String  STATLE_FILE = "file:swi";
	public static final String  FLOW_FILE = "file:dat";
	public static final String  PARAM_FILE = "file:xml";
	
	public static final String STATE_ESTIMATE_CONFIG = "config:StateSampleConfig";
	public static final String STATE_SAMPLE_CONFIG = "config:StateEstimateConfig";
	
	public static final String PR_ADEQUACY_SETTING = "config:PRAdequacySetting";
	
	public static final String FSTATE_LIST = "FStates";
	public static final String FDEV_LIST = "FDevStates";
	public static final String ESTIMATE_TASK_LIST = "EstimateTasks";
	public static final String ESTIMATE_RESULT_MAP = "EstimateResultMap";
	
	private ObjectRefDataOperations strOps;
	private MapDataOperations mapOps;
	private ListDataOperations listOps;
	private AbstractConnectionFactory connectionFactory;
	public ReliabilityNetBuffer(AbstractConnectionFactory connectionFactory, String modelName) {
		this.setModelName(modelName);
		strOps = connectionFactory.getObjectRefOperations();
		mapOps = connectionFactory.getMapDataOperations();
		listOps = connectionFactory.getListDataOperations();
		this.connectionFactory = connectionFactory;
	}
	
	
	public void removeKeys(String... keys) {
		for (String key : keys) {
			connectionFactory.deleteKeys(formInternalKey(key));
		}
	}
	private String prefix() {
		return modelName;
	}
	public String getModelName() {
		return modelName;
	}
	public void setModelName(String modelName) {
		this.modelName = modelName;
	}
		
	public <T> void set(String key, T value) {
		strOps.set(formInternalKey(key), Utils.toJSon(value));
	}

	public  void set(String key, String value) {
		strOps.set(formInternalKey(key), value);
	}
	
	public <T> T get(String key, Class<T> clazz) {
		String str = null;
		return ((str = strOps.get(formInternalKey(key))) != null) ? Utils.toObject(str, clazz) : null;
	}

	public String get(String key) {
		
		return strOps.get(formInternalKey(key));
	}
	
	private String formInternalKey(String key) {
		return prefix() +":"+ key;
	}
	
	public <T> T get(Class<T> clazz) {
		return get(clazz.getSimpleName(), clazz);
	}
	
	public <T> void pushAll(String key, List<T> values) {
		if (values == null || values.isEmpty())
			return;
		
		int offset = 0;
		int batch = 1000;
		String internalKey = formInternalKey(key);
		while (offset < values.size()) {
			int incre = batch;
			int left = values.size() - offset; 
			if (incre > left )
				incre = left;
			listOps.pushAll(internalKey, values.subList(offset, offset+incre));
			offset += incre;		
		}
	}
	
	public <T> void pushAll(List<T> values) {
		if (values == null || values.isEmpty())
			return;
		
		Class<?> clazz = values.get(0).getClass();
		pushAll(clazz.getSimpleName(), values);
	}

	public <T> ListData<T> getList(String name) {
		ListData<T> l = new ListData<T>(formInternalKey(name));
		l.setOperations(listOps);
		return l;
	}
	
	public <K, V> MapData<K, V> getMap(String name) {
		MapData<K, V> m = new MapData<K, V>(formInternalKey(name));
		m.setOperations(mapOps);
		return m;
	}

	public File saveStableFile(String cachedDir) {
		return saveFile(cachedDir, STATLE_FILE);
	}

	
	public File saveFile(String cachedDir, String fileRx) {
		Path path = Paths.get(cachedDir);
		File pathFile = path.toFile();
		if (!pathFile.exists()) {
			//LOGGER.info("mkdir {}. ", tempDir);
			pathFile.mkdirs();
		}
		
		
		FileInfo fileInfo = Utils.toObject(strOps.get(formInternalKey(fileRx+":info")), FileInfo.class);
		
		List<String> fileKeys = new ArrayList<String>();
		fileKeys.add(fileRx);
		if (fileInfo.getBlockSize() > 1) {
			for (int i = 1; i < fileInfo.getBlockSize(); i++) {
				fileKeys.add(fileRx +":"+i);
			}
		}
	
		
		Path filePath = Paths.get(cachedDir, fileInfo.getName());
		File file = filePath.toFile();
		//LOGGER.info("save file : {} ", file.getAbsolutePath());
		FileWriter fw = null;
		try {
			fw = new FileWriter(file);
			
			for (int i = 0; i < fileKeys.size(); i++) {
				String fileContent = strOps.get(formInternalKey(fileKeys.get(0)));
				fw.write(fileContent);				
			}
			
			fw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}
		
		return file;
		
	}
	
}