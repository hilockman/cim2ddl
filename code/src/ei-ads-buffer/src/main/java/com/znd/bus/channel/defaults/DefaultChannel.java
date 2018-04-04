package com.znd.bus.channel.defaults;

import java.util.ArrayList;
import java.util.List;

import com.znd.bus.channel.Channel;
import com.znd.bus.channel.ChannelType;
import com.znd.bus.channel.Event;
import com.znd.bus.channel.Listener;
import com.znd.bus.channel.Message;

public class DefaultChannel implements Channel {

	private final String name;
	private final ChannelType type;
	private final List<Listener> listeners = new ArrayList<>();
	
	public DefaultChannel(String name, ChannelType type) {
		this.name = name;
		this.type = type;
		
	}
	@Override
	public void send(Message message) {
	}

	@Override
	public void register(Listener listener) {
		listeners.add(listener);
	}
	
	@Override
	public void receive(Event e) {
		for (Listener l : listeners) {
			l.receive(e);
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

}
