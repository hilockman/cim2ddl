package com.znd.ei.ads.bus.statement;

import java.util.Map;

public interface RowUpdateHandler {
	void update(Map<Short, String> columns, Map<String, String> conditions);
}
