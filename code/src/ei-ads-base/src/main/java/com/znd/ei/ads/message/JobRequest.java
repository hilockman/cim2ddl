package com.znd.ei.ads.message;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.znd.ei.Utils;
import com.znd.ei.ads.config.StateEstimateConfig;

public class JobRequest<T> {

	
	public static void main(String [] args) {
		StateEstimateConfig config = new StateEstimateConfig();
		
		ReliabilityRequest request = new ReliabilityRequest();
		request.setConfig(config);
		request.setId("1");
		request.setType("test");
		request.getFiles().add(new JobFile("file1", "redisKey1"));
		String str = Utils.toJSon(request);
		
		
		ReliabilityRequest request1 = Utils.toObject(str, ReliabilityRequest.class);
		Map<String, String> valueMap = new HashMap<String, String>();
		valueMap.put("type", "v1");
		valueMap.put("id", "v2");
		str = Utils.toJSon(valueMap);
		JobRequest j = Utils.toObject(str, JobRequest.class);
		System.out.println(str);
	}
	
	private String type;
	private String id;
	private T config;
	private List<JobFile> files = new ArrayList<JobFile>();
	
	static final public class JobFile {
		private String name;
		private String redisKey;
		public JobFile(String name, String redisKey) {
			this.name = name;
			this.redisKey = redisKey;
		}
		public String getName() {
			return name;
		}
		public void setName(String name) {
			this.name = name;
		}
		public String getRedisKey() {
			return redisKey;
		}
		public void setRedisKey(String redisKey) {
			this.redisKey = redisKey;
		}
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}


	public List<JobFile> getFiles() {
		return files;
	}

	public void setFiles(List<JobFile> files) {
		this.files = files;
	}

	public T getConfig() {
		return config;
	}

	public void setConfig(T config) {
		this.config = config;
	}
	

}
