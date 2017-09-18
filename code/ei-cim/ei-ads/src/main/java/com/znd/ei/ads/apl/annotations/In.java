package com.znd.ei.ads.apl.annotations;

import java.lang.annotation.Documented;
import java.lang.annotation.ElementType;
import java.lang.annotation.Inherited;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * 业务输入参数，用于与数据域绑定
 * @author ThinkPad
 *
 */
@Documented
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.PARAMETER)
@Inherited
public @interface In {
	/**
	 * 内容控制码，在ContentCodeDefines中定义
	 * @return
	 */
	String value() default "";
}
