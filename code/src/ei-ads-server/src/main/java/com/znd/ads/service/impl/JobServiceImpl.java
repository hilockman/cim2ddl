package com.znd.ads.service.impl;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Date;
import java.util.List;
import java.util.Map;

import javax.annotation.PostConstruct;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.DependsOn;
import org.springframework.stereotype.Service;

import com.znd.ads.exception.FactoryException;
import com.znd.ads.exception.JobException;
import com.znd.ads.mapper.CalcJobMapper;
import com.znd.ads.service.JobService;
import com.znd.bus.channel.Channel;
import com.znd.bus.common.buffer.CalcJobBuffer;
import com.znd.bus.common.buffer.ModelFileBuffer;
import com.znd.bus.common.model.CalcJob;
import com.znd.bus.common.model.CalcJobStateEnum;
import com.znd.bus.common.model.ModelFile;
import com.znd.bus.exception.AdsException;
import com.znd.bus.server.AdapterService;
import com.znd.bus.server.BusService;
import com.znd.bus.server.NounEnum;
import com.znd.bus.server.Topic;
import com.znd.bus.server.VerbEnum;
import com.znd.bus.server.message.EventMessageType;
import com.znd.bus.server.message.RequestMessageType;
import com.znd.bus.server.message.ResponseMessageType;
import com.znd.ei.Utils;

@Service
@DependsOn("defaultBufferConfig")
public class JobServiceImpl implements JobService {
	private final Logger logger = LoggerFactory
			.getLogger(JobService.class);
	
	@Autowired
	private CalcJobBuffer jobBuffer;

	@Autowired
	private CalcJobMapper jobMapper;

	@Value("${model.cachedDir}")
	private String cachedDir;
	
	@Autowired
	private ModelFileBuffer modelFileMapper;

//	@Autowired
//	private ModelSourceBuffer modelSourceBuffer;
	
	@Autowired
	private Channel jobChannel;
	
	@Autowired
	private BusService busService;
	
	
	private AdapterService adapter;
		
	
	@Autowired
	private MyBufferFactoryRegistory factoryRegistory;
	
	public JobServiceImpl() {
		
	}
	
	class JobAdapter extends AdapterService {

		@Override
		public ResponseMessageType publish(EventMessageType message) {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public ResponseMessageType request(RequestMessageType message) {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public ResponseMessageType response(ResponseMessageType message) {
			logger.debug("JobService receive:"+Utils.toJSon(message.getHeader()));
			return null;
		}
		
	}
	
	@PostConstruct
	public void init() {
		try {
			adapter = busService.registAdapter(new JobAdapter(), "JobControlAdapter", Topic.in(VerbEnum.execute, NounEnum.job));
		} catch (AdsException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		reload();
	}
	
	private void reload() {
		//synchronized(this) {
			
			//jobBuffer.deleteAll();
			List<CalcJob> jobs = jobMapper.findAll();
			for (CalcJob job : jobs) {
				if (jobBuffer.findById(job.getId()) == null) {
				   jobBuffer.insert(job);	
			    }
			}
	}

	@Override
	public List<CalcJob> getAll() {
		synchronized(this) {
			List<CalcJob> jobs = jobBuffer.findAll();
			
			return jobs;
		}
	}

	@Override
	public CalcJob findJob(String jobId) {
		return jobBuffer.findById(jobId);
	}

	@Override
	public void delete(String jobId) {
		CalcJob job = jobBuffer.findById(jobId);
		if (job == null)
			return;
				
//		if (job.getState() == CalcJobStateEnum.running) {
//			throw new JobException("Fail to cancel job :"+jobId+", job is running.");
//		}
		jobMapper.deleteById(jobId);
		jobBuffer.deleteById(jobId);
		logger.info("Job : {} canceled.", jobId);
	}
	

	@Override
	public void cancel(String jobId) {
		
		CalcJob job = jobBuffer.findById(jobId);
		if (job == null)
			return;
		
		
//		if (job.getState() == CalcJobStateEnum.running) {
//			throw new JobException("Fail to cancel job :"+jobId+", job is running.");
//		}
		job.setState(CalcJobStateEnum.stop);
		job.setStep(0);
		job.setMaxStep(0);
		job.setStart(null);
		job.setEnd(null);
		jobMapper.update(job);
		jobBuffer.update(job);
		
		logger.info("Job : {} stopped.", jobId);
		//adapter.sendPublish(VerbEnum., noun, content)
	}




	//准备并开始工作
	private void prepareAndStartJob(CalcJob job) {
		
		String jobId = job.getId();
		String modelId = job.getModelId();
		if (modelId == null) {
			throw new JobException(String.format("Model id is null.", job.getModelId()));
		}
		
		Path path = Paths.get(cachedDir, modelId);
		File rootDir = path.toFile();
		if (!rootDir.exists()) {			
			throw new JobException(String.format("Fail to find model dir : %s.", modelId));
		}
		
		
	 	//加载模型文件到buffer中		
		File[] files =  rootDir.listFiles();
		
		if (files != null && files.length > 0) {
			modelFileMapper.deleteByModel(modelId);
			byte[] buff = new byte[1024];
			try {
				for (File f : files) {
						String fileName = f.getName();
						InputStream is = new FileInputStream(f);
						//int off = 0;

						int readCount = 0;
						StringBuffer sb = new StringBuffer();
						while ((readCount = is.read(buff, 0, buff.length)) > 0) {
						
							sb.append(new String(buff, 0,readCount));
	
							//off += readCount;
						}
						is.close();
						
						int pos = fileName.lastIndexOf('.');
						String suffix = fileName.substring(pos+1);
						
					
						ModelFile modelFile = new ModelFile();
						modelFile.setId(Utils.randomKey());
						modelFile.setName(fileName);
						modelFile.setModelId(modelId);
						modelFile.setLastUpdate(new Date());
						modelFile.setType(suffix);
						
						modelFile.setContent(sb.toString());
						
						modelFileMapper.save(modelFile );
						logger.debug("Update file :"+fileName);
				}
			} catch (Exception e) {
				throw new RuntimeException("Fail to update model file :"+modelId);
			}		
		}
		
		
		//发送消息
		
		logger.info("sendMessage : verb = {}, noun = {}, content = {}. ",
				VerbEnum.execute, NounEnum.job, jobId);

		job.setStep(0);
		job.setMaxStep(0);		
		job.setStart(new Date());
		job.setElapse(null);
		job.setEnd(null);
		job.setState(CalcJobStateEnum.running);
		jobBuffer.update(job);
		
		//jobChannel.send(new ChannelMessage(MessageCodeEnum.start_job, jobId));
		adapter.sendRequest(VerbEnum.execute, NounEnum.job, jobId);
		

	}
	@Override
	public void start(String jobId) {
		CalcJob job = jobBuffer.findById(jobId);
		if (job == null) {
			throw new JobException("Unknown job id :" +jobId);
		}
		
		if (job.getState() == CalcJobStateEnum.running) {
			throw new JobException("Job  :" +jobId+", is running.");
		}
		
		prepareAndStartJob(job);
		
		
	}

	@Override
	public void create(CalcJob job) {
		
		//check job is valid
		if (job.getModelId() == null) {
			throw new JobException("Job'model is null.");
		}
		
		if (job.getTypeId() == null) {
			throw new JobException("Job'type is null.");
		}
		
		if (job.getId() == null) {
			job.setId(Utils.simpleRandomKey());
		}
		job.setStart(new Date());
		
		jobBuffer.insert(job);
		jobMapper.insert(job);
		
		prepareAndStartJob(job);
	}

	@Override
	public CalcJob findJobByName(String name) {
		return jobBuffer.findByName(name);
	}

	@Override
	public List<CalcJob> findByModel(String modelId) {
		return jobBuffer.findByModel(modelId);
	}

	@Override
	public Object getResult(String id) throws FactoryException {
		MyBufferFactory factory = factoryRegistory.getFactory(id);
		if (factory == null)
			return null;
		List<Map<String, String>> list = factory.getRecordMaps("System");
		if (list == null || list.size() < 1)
			return null;
		
		return list.get(0);
	}

	@Override
	public String getFile(String folder, String file) {
		Path path = Paths.get(cachedDir, folder);
		File rootDir = path.toFile();
		if (!rootDir.exists()) {			
			return null;
		}
		
		
	 	//加载模型文件到buffer中		
		File[] files =  rootDir.listFiles();
		
		if (files != null && files.length > 0) {
			byte[] buff = new byte[1024];
			try {
				for (File f : files) {
						String fileName = f.getName();
						if (fileName.compareTo(file) != 0)
							continue;
						
						InputStream is = new FileInputStream(f);
						//int off = 0;

						int readCount = 0;
						StringBuilder sb = new StringBuilder();
						while ((readCount = is.read(buff, 0, buff.length)) > 0) {
						
							sb.append(new String(buff, 0,readCount));
	
							//off += readCount;
						}
						is.close();
						
						return sb.toString();

				}
			} catch (Exception e) {
				throw new RuntimeException("Fail to update model file :"+folder);
			}		
		}
		
		return null;
		

	}



}
