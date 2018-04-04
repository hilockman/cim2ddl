package com.znd.bus.channel;

import java.io.Closeable;

public interface Channel extends Closeable {
     void send(Message message);
     void register(Listener listener);
     
     void receive(Event e);
     
     @Override
     void close();
     
	ChannelType getType();
	String getName();
}
