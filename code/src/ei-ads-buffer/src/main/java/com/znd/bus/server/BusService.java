package com.znd.bus.server;

public interface BusService extends ServiceInterface {

	void registAdapter(AdapterService adapter, AdapterInfo info);
	void registAdapter(AdapterService adapter, String name, Topic...topics );
}
