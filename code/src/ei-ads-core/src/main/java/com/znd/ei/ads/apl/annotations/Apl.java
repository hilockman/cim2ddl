package com.znd.ei.ads.apl.annotations;

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
//Retention注解决定MyAnnotation注解的生命周期
@Target( { ElementType.METHOD, ElementType.TYPE })
@Inherited
@Component
public @interface Apl {
	String value() default "";
	String desc() default "";
}
