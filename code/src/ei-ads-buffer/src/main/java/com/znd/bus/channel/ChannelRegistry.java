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

public class ChannelRegistry implements Closeable {

	
	private final Map<String, Channel> knownChannels = new HashMap<>();
	
	public ChannelRegistry() {
		
	}
	
	public Channel getChannel(String name) {
		return knownChannels.get(name);
	}


	public Collection<String> getChannels() {
		return Collections.unmodifiableCollection(knownChannels.keySet());
	}

	
	public void addChannels(BufferContext context, List<ChannelConfig> channels)
	{
		for (ChannelConfig config : channels) {
			Channel  c = context.registChannel(config);
			knownChannels.put(config.getName(), c);
		}
	}

	@Override
	public void close() throws IOException {
		for (Entry<String, Channel> e : knownChannels.entrySet()) {
			e.getValue().close();
		}
	}

}
