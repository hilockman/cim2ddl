package com.znd.ads.annotation;

import java.lang.annotation.Documented;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Documented
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.ANNOTATION_TYPE)
public @interface ForeignColumn {
	/**
	 * 表名
	 * @return
	 */
	String table() ;
	/**
	 * 值解释列
	 * @return
	 */
	String value() ;
	
	/**
	 * 外键列
	 * @return
	 */
	String key() default "id";
	
}
