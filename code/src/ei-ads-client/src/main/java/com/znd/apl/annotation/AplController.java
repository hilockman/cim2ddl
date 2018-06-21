package com.znd.apl.annotation;

import java.lang.annotation.ElementType;
import java.lang.annotation.Inherited;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

import org.springframework.stereotype.Component;

/**
 * 应用类，用于注册业务方法
 * @author wangheng
 *
 */
@Retention(RetentionPolicy.RUNTIME)
@Target( ElementType.TYPE)
@Inherited
@Component
public @interface AplController {
	//job type
	String value();
	String desc() default "";
}
