package com.znd.ei.adf.annotations;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Retention(RetentionPolicy.RUNTIME)
//Retention注解决定MyAnnotation注解的生命周期
@Target( { ElementType.METHOD, ElementType.TYPE })
public @interface Application {
	String value() default "";
	String desc() default "";
	String inputCC() default "";//输入内容码
	@SuppressWarnings("rawtypes")
	Class inputData() default Object.class;
	String outputCC() default "";//输出内容码
	@SuppressWarnings("rawtypes")
	Class outputData() default Object.class;
}
