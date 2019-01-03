package com.znd.bus.channel;

import java.io.Closeable;
import java.io.IOException;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import com.znd.bus.buffer.BufferContext;
import com.znd.bus.exception.MessageException;

public class ChannelRegistry implements Closeable {

	
	private final Map<String, Channel> knownChannels = new HashMap<>();
	private BufferContext context;
	public ChannelRegistry(BufferContext context) {
		this.context = context;
	}
	
	public Channel getChannel(String name) {
		return knownChannels.get(name);
	}


	public Collection<String> getChannels() {
		return Collections.unmodifiableCollection(knownChannels.keySet());
	}

	public Channel addChannel(ChannelConfig config) throws MessageException
	{
		Channel  c = context.registChannel(config);
		knownChannels.put(config.getName(), c);
		return c;
	}
	
	public void addChannels(List<ChannelConfig> channels) throws MessageException
	{
		if (channels == null || channels.isEmpty())
			return;
		
		for (ChannelConfig config : channels) {
			addChannel(config);
		}
	}

	@Override
	public void close() throws IOException {
		for (Entry<String, Channel> e : knownChannels.entrySet()) {
			e.getValue().close();
		}
	}

}
