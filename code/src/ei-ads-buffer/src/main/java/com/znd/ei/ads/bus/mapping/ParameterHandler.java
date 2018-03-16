package com.znd.ei.ads.bus.mapping;

import java.lang.reflect.Method;
import java.util.Map;

import com.znd.ei.ads.bus.binding.BindingException;
import com.znd.ei.ads.bus.config.BufferConfig;

/**
 * 实现对象到字符串数组的转换
 * 输入参数条件转换成Map
 * @author wangheng
 * @date 2018年3月16日
 * @time 上午10:53:21
 * @type_name ParamerterHandler
 */
public interface ParameterHandler {
	public final static ParameterHandler DefaultParameterHandler = new ParameterHandler() {
		
		@Override
		public String[] toArrayValues(Object o) {
			return (String[])o; 
		}
			
		@Override
		public Map<String, String> toArgsMap(Object[] args) {
			if (args.length == 0)
				return null;
			
			Object arg = args[0];
			if (arg instanceof Map) {
				return (Map<String, String>)arg;
			} else {
				throw new BindingException("Unknown arg type : "+arg.getClass().getName());
			}
		}

		@Override
		public Object toObject(String[] values) {
			return values;
		}
	};
	
	public static class ObjectParameterHandler implements ParameterHandler
	{
		public ObjectParameterHandler(BufferConfig config, Method method, String tableName, Class<?> returnType, Class<?>[] argTypes) {
			ObjectReflector reflector = config.getReflector(returnType);
			
			
		}

		@Override
		public String[] toArrayValues(Object o) {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public Map<String, String> toArgsMap(Object[] args) {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public Object toObject(String[] values) {
			// TODO Auto-generated method stub
			return null;
		}
		
	}
	

	/**
	 * 值数组转换成对象
	 * @param values
	 * @return
	 */
	Object toObject(String[] values);
	
	
	/**
	 * 对象转换成字符数组
	 * @param o
	 * @return
	 */
	String[] toArrayValues(Object o);
	
	/**
	 * 输入参数转换成Map
	 * @param args
	 * @return
	 */
	Map<String, String> toArgsMap(Object[] args);
	
}
