package com.znd.ei.ads.acp;

import java.util.ArrayList;
import java.util.List;

import com.znd.ei.ads.adf.ListData;


public abstract class AbstractConnectionFactory implements ConnectionFactory {
	/**
	 * 
	 * @param contentCode
	 * @param key
	 * @param 接收者不唯一
	 * @throws ACPException
	 */
	public void publishData(String contentCode, String key, String content) throws ACPException {
		publishData(contentCode, key, content, false);
	}
	
	/**
	 * 发送消息和数据
	 * @param contentCode
	 * @param key
	 * @param content
	 * @param singleton , true 表示接收者唯一, false 表示接收者不唯一
	 * @throws ACPException
	 */
	public void publishData(String contentCode, String key, String content, boolean singleton) throws ACPException
	{
		if (singleton) {
			ListData data = new ListData();
			List<String> list = new ArrayList<String>();
			list.add(content);
			data.setContent(list);
			ListDataOperations ops = getListDataOperations();
			try {
				ops.write(data);
			} catch (UnsupportedOperation e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException(e);
			}
			ops.close();
		}
		publishData(contentCode, key);
	}
	
}
