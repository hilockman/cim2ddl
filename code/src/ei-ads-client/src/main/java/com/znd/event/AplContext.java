package com.znd.event;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicBoolean;

/**
 * apl执行的上下层
 * @author wangheng
 * @date 2018年6月19日
 * @time 上午11:27:53
 * @type_name AplContext
 */
public class AplContext {

	private final AtomicBoolean running = new AtomicBoolean(true);
	
	private  final AtomicBoolean quit  = new AtomicBoolean(false);
	
	private final Map<String, Object> attributeMap = new HashMap<>();
	
	
	private final Byte waitFlag = 0;
	
	public boolean setRunning(boolean flag) {
		return running.getAndSet(flag);
	}
	
	public boolean isRunning() {
		return running.get();
	}
	
	public void setAttribute(String name, Object object) {
		attributeMap.put(name, object);	
	}
	
	public Object getAttribute(String name) {
		return attributeMap.get(name);
	}

	public boolean getQuit() {
		return quit.get();
	}
	
	public void setQuit() {		
		quit.set(true);
	}

	public void stopWait() {
		waitFlag.notifyAll();
		setRunning(false);
	}
	
	public void waitForJobQuit(long timeout) throws InterruptedException {
		waitFlag.wait(timeout);
	}
	
	public void clear() {
		attributeMap.clear();
		stopWait();
	}
}
