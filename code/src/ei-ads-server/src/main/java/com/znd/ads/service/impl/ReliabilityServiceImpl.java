package com.znd.ads.service.impl;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Date;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ads.service.ReliabilityService;
import com.znd.bus.channel.Channel;
import com.znd.bus.channel.ChannelMessage;
import com.znd.bus.channel.MessageCodeEnum;
import com.znd.bus.common.buffer.CalcJobBuffer;
import com.znd.bus.common.buffer.ModelFileBuffer;
import com.znd.bus.common.model.CalcJob;
import com.znd.bus.common.model.CalcJobStateEnum;
import com.znd.bus.common.model.ModelFile;
import com.znd.ei.Utils;

@Service
public class ReliabilityServiceImpl implements ReliabilityService {
	private final Logger logger = LoggerFactory
			.getLogger(ReliabilityService.class);
	
	@Autowired
	private CalcJobBuffer calcJobMapper;
	
	@Autowired
	private ModelFileBuffer modelFileMapper;
	
	@Autowired
	private Channel commonChannel;
	
	
	@Override
	public String createJob(String modelName, String parameter, File[] files) {
		CalcJob info = new CalcJob();
		info.setDesc(modelName);
		info.setModelId(modelName);
		info.setStart(new Date());
		info.setParameter(parameter);
		//info.setState(CalcJobStateEnum.created);
		info.setId(Utils.randomKey());
		calcJobMapper.save(info);
		logger.debug("Created job :"+modelName);
		
		if (files != null && files.length > 0) {
			modelFileMapper.deleteByModel(modelName);
			byte[] buff = new byte[1024];
			try {
				for (File f : files) {
						String fileName = f.getName();
						InputStream is = new FileInputStream(f);
						int off = 0;

						int readCount = 0;
						StringBuffer sb = new StringBuffer();
						while ((readCount = is.read(buff, off, buff.length - off)) > 0) {
						
							sb.append(new String(buff, 0,readCount));
	
							off += readCount;
						}
						is.close();
						
						int pos = fileName.lastIndexOf('.');
						String suffix = fileName.substring(pos+1);
						
					
						ModelFile modelFile = new ModelFile();
						modelFile.setId(Utils.randomKey());
						modelFile.setName(fileName);
						modelFile.setModelId(modelName);
						modelFile.setLastUpdate(new Date());
						modelFile.setType(suffix);
						
						modelFile.setContent(sb.toString());
						
						modelFileMapper.save(modelFile );
						logger.debug("Update file :"+fileName);
				}
			} catch (Exception e) {
				throw new RuntimeException("Fail to update model file :"+modelName);
			}		
		}
		
		
		//发送消息
		
		logger.info("sendMessage : cc = {}, content = {}. ",
		"created_ReliabilityTask", modelName);
        sendMessage(new ChannelMessage(MessageCodeEnum.start_job, modelName));
		
		
		return info.getId();
	}
	
	
	private void sendMessage(ChannelMessage message) {
		commonChannel.send(message);
	}

}
