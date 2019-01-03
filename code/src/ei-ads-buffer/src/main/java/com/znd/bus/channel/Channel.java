package com.znd.bus.channel;

import java.io.Closeable;

import com.znd.bus.server.Topic;

public interface Channel extends Closeable {
     void send(ChannelMessage message);
     void register(Listener listener);
     
     void receive(ChannelMessage e);
     
     @Override
     void close();
     
	ChannelType getType();
	String getName();
	
	Topic getTopic();
	
}
