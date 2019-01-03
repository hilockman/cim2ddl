package com.znd.bus.channel.defaults;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import com.znd.bus.channel.Channel;
import com.znd.bus.channel.ChannelMessage;
import com.znd.bus.channel.ChannelType;
import com.znd.bus.channel.Listener;
import com.znd.bus.server.Topic;
import com.znd.ei.Utils;

public class DefaultChannel implements Channel {

	private final String name;
	private final ChannelType type;
	private final List<Listener> listeners = new ArrayList<>();
	private final Topic topic;
	
	private static final ExecutorService pool = Utils.threadPool();
	
	public DefaultChannel(String name, ChannelType type) {
		this.name = name;
		this.topic = Topic.parse(name);
		this.type = type;
		
	}
	@Override
	public void send(ChannelMessage message) {
	}

	@Override
	public void register(Listener listener) {
		listeners.add(listener);
	}
	
	@Override
	public void receive(ChannelMessage e) {
		if (listeners.isEmpty())
			return;
		
		if (type == ChannelType.Share) { //共享只有一个listener处理
		    int index = (int) Math.floor(Math.random() * listeners.size());
		    pool.execute(()->{listeners.get(index).receive(e);});
		} else {
			for (Listener l : listeners) {
				 pool.execute(()->{
					 l.receive(e);
					 });
			}
		}
	}
	@Override
	public void close() {
		
	}
	@Override
	public ChannelType getType() {
		return type;
	}
	@Override
	public String getName() {
		return name;
	}
	@Override
	public Topic getTopic() {
		return this.topic;
	}

}
