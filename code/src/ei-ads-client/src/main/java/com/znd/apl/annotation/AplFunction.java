package com.znd.apl.annotation;

import java.lang.annotation.Documented;
import java.lang.annotation.ElementType;
import java.lang.annotation.Inherited;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

import com.znd.bus.channel.MessageCodeEnum;

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
	//输入消息
	MessageCodeEnum in();
	
	//方法功能描述
	String desc() default "";
	
	//输出消息
	MessageCodeEnum out() default MessageCodeEnum.none;

}
