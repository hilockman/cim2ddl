package com.znd.ei.ads.apl.annotations;

import java.lang.annotation.Documented;
import java.lang.annotation.ElementType;
import java.lang.annotation.Inherited;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * 业务输出参数，用于与数据域绑定
 * @author ThinkPad
 *
 */
@Documented
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.PARAMETER)
@Inherited
public @interface Out {
	/**
	 * 内容控制码，在ContentCodeDefines中定义
	 * @return
	 */
	String value();
	
	/**
	 * 是否自动创建数据域中的key，用于数据发布，默认为创建，
	 * 自动生成一个,组成规则为cc:uuid；
	 * 如果指定为false，则由业务决定key值
	 * @return
	 */
	boolean autoGenerateKey() default true;
}
