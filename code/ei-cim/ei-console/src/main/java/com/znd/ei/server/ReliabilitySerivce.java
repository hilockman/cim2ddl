package com.znd.ei.server;

/**
 * 可靠性服务
 * @author ThinkPad
 *
 */
public interface ReliabilitySerivce {
	/**
	 * 抽样
	 */
	void sample();
	
	/**
	 * 后评估
	 */
	void evaluate();
}
