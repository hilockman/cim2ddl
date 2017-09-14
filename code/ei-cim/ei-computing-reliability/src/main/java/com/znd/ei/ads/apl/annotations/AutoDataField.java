package com.znd.ei.ads.apl.annotations;

public @interface AutoDataField {
	/**
	 * 内容控制码，在ContentCodeDefines中定义
	 * @return
	 */
	String cc();
	
	/**
	 * 从DF中序列化反序列化方法
	 * @return
	 */
	String io() default "DefaultSimpleOperations";
	
	/**
	 * 是否是启动条件
	 * @return
	 */
	boolean bootCondition() default false;
}
