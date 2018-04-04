package com.znd.bus.channel;

import java.io.Closeable;
import java.util.Collection;

public interface ChannelFactory  extends Closeable {

	Channel getChannel(String name);
	
	Collection<String> getChannels();

}
