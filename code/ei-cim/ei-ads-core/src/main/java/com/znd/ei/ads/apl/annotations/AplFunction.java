package com.znd.ei.ads.apl.annotations;

import java.lang.annotation.Documented;
import java.lang.annotation.ElementType;
import java.lang.annotation.Inherited;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * 应用方法，实际执行应用业务的地方，用于向应用管理注册业务
 * @author wangheng
 *  
 */
@Documented
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
@Inherited
public @interface AplFunction {
	public static String AND = "and";
	public static String OR = "or";
	String ccOper() default AND;
	String desc() default "";
	String value() default "";
}
