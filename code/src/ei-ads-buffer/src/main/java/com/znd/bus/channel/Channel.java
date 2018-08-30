package com.znd.bus.channel;

import java.io.Closeable;

public interface Channel extends Closeable {
     void send(ChannelMessage message);
     void register(Listener listener);
     
     void receive(ChannelMessage e);
     
     @Override
     void close();
     
	ChannelType getType();
	String getName();
}
