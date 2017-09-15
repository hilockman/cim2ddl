package com.znd.ei.ads.apl.annotations;

import java.lang.annotation.ElementType;
import java.lang.annotation.Inherited;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Retention(RetentionPolicy.RUNTIME)
//Retention注解决定MyAnnotation注解的生命周期
@Target( { ElementType.METHOD, ElementType.TYPE })
@Inherited
public @interface Apl {
	String value() default "";
	String desc() default "";
//	String outputCC() default "";//输出内容码
//	@SuppressWarnings("rawtypes")
//	Class outputData() default Object.class;
}
