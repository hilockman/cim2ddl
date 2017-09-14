package com.znd.ei.ads.apl.annotations;

import java.lang.annotation.Documented;
import java.lang.annotation.ElementType;
import java.lang.annotation.Inherited;
import java.lang.annotation.Target;

@Documented
@Target(ElementType.METHOD)
@Inherited
public @interface AplFunction {
	public static String AND = "and";
	public static String OR = "or";
	
	String cc() default "";
	String[] ccArray() default {};
	String ccOper() default AND;
	@SuppressWarnings("rawtypes")
	Class dataFactory() default Object.class;
}
