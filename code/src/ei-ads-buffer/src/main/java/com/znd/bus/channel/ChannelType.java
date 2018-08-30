package com.znd.bus.channel;

/**
 * 通道类型
 * @author wangheng
 * @date 2018年8月30日
 * @time 上午10:35:38
 * @type_name ChannelType
 */
public enum ChannelType {
	/**
	 * 发送队列，只发送
	 */
	SendOnly,
	
	/**
	 * 共享队列，只有一个订阅此通道的接口会收到消息
	 */
	Share,
	
	/**
	 * 独立队列, 每个订阅此通道的回调接口都会收到消息
	 */
	StandAlone
}
