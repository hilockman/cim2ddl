package com.znd.bus.server;

public enum Direction {
	/**
	 * 相对总线，总线接收的消息成为上行消息
	 */
	in,
	/**
	 * 相对总线，总线发出的消息称为下行消息
	 */
	out,
	/**
	 * 相对总线，总线接收的消息成为上下行消息
	 */
	in_and_out,

	
}
