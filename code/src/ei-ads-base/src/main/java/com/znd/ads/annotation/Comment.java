package com.znd.ads.annotation;

import java.lang.annotation.Documented;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * 用于界面显示属性名称
 * @author wangheng
 * @date 2018年6月1日
 * @time 下午1:26:02
 * @type_name Comment
 */
@Documented
@Retention(RetentionPolicy.RUNTIME)
@Target({ElementType.FIELD, ElementType.TYPE})
public @interface Comment {

	public static String OPT_SPLIT = ",";
	/**
	 * 名称
	 * @return
	 */
	String name() default "";
	
	/**
	 * 所属组
	 * @return
	 */
    String group() default "";
    
	/**
	 *别名
	 * @return
	 */
	String alias() default "";

	/**
	 可选值
	 */
	;
	String tr() default "";
	
	int order() default 0;
	
	ForeignColumn fk() default  @ForeignColumn(table="", value="") ;
	
	/**
	 * 显示类型
	 */
	ShowType showType() default ShowType.Undefined;
	
}
