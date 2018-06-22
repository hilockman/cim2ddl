package com.znd.ads.service.impl;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Date;
import java.util.List;

import javax.annotation.PostConstruct;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import com.znd.ads.exception.JobException;
import com.znd.ads.mapper.CalcJobMapper;
import com.znd.ads.service.JobService;
import com.znd.bus.channel.Channel;
import com.znd.bus.channel.Message;
import com.znd.bus.channel.MessageCodeEnum;
import com.znd.bus.common.buffer.CalcJobBuffer;
import com.znd.bus.common.buffer.ModelFileBuffer;
import com.znd.bus.common.buffer.ModelSourceBuffer;
import com.znd.bus.common.model.CalcJob;
import com.znd.bus.common.model.CalcJobStateEnum;
import com.znd.bus.common.model.ModelFile;
import com.znd.ei.Utils;

@Service
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

	@Autowired
	private ModelSourceBuffer modelSourceBuffer;
	
	@Autowired
	private Channel jobChannel;
	
	

		
	
	public JobServiceImpl() {
		
	}
	
	@PostConstruct
	public void init() {
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
	public List getAll() {
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
	public void cancel(String jobId) {
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
	public void stop(String jobId) {
		
		CalcJob job = jobBuffer.findById(jobId);
		if (job == null)
			return;
		
		
//		if (job.getState() == CalcJobStateEnum.running) {
//			throw new JobException("Fail to cancel job :"+jobId+", job is running.");
//		}
		job.setState(CalcJobStateEnum.stop);
		jobMapper.update(job);
		jobBuffer.update(job);
		
		logger.info("Job : {} stopped.", jobId);
		
	}

	@Override
	public void pause(String jobId) {
		
		CalcJob job = jobBuffer.findById(jobId);
		if (job == null)
			return;
		
		
//		if (job.getState() == CalcJobStateEnum.running) {
//			throw new JobException("Fail to cancel job :"+jobId+", job is running.");
//		}
		job.setState(CalcJobStateEnum.suspend);
		jobMapper.update(job);
		jobBuffer.update(job);
		
		logger.info("Job : {} paused.", jobId);
	}


	private void prepareAndPublishJob(CalcJob job) {
		
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
		
		logger.info("sendMessage : cc = {}, content = {}. ",
		"created_ReliabilityJob", jobId);
		
		jobChannel.send(new Message(MessageCodeEnum.created_job, jobId));

	}
	@Override
	public void restart(String jobId) {
		CalcJob job = jobBuffer.findById(jobId);
		if (job == null) {
			throw new JobException("Unknown job id :" +jobId);
		}
		
		if (job.getState() == CalcJobStateEnum.running) {
			throw new JobException("Job  :" +jobId+", is running.");
		}
		
		prepareAndPublishJob(job);
		
		
	}

	@Override
	public void add(CalcJob job) {
		
		//check job is valid
		if (job.getModelId() == null) {
			throw new JobException("Job'model is null.");
		}
		
		if (job.getTypeId() == null) {
			throw new JobException("Job'type is null.");
		}
		
		if (job.getId() == null) {
			job.setId(Utils.randomKey());
		}
		job.setStart(new Date());
		//job.setState(CalcJobStateEnum.created);
		prepareAndPublishJob(job);
		
		jobBuffer.insert(job);
		jobMapper.insert(job);
	}

	@Override
	public CalcJob findJobByName(String name) {
		return jobBuffer.findByName(name);
	}

	@Override
	public List<CalcJob> findByModel(String modelId) {
		return jobBuffer.findByModel(modelId);
	}



}
