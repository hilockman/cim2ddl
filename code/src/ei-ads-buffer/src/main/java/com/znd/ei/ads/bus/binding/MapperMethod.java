package com.znd.ei.ads.bus.binding;

import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import com.znd.ei.ads.bus.buffer.Buffer;
import com.znd.ei.ads.bus.config.BufferConfig;

public class MapperMethod {

	
	public static final boolean parameterExists;

	  static {
	    boolean available = false;
	    try {
	      Class.forName("java.lang.reflect.Parameter");
	      available = true;
	    } catch (ClassNotFoundException e) {
	      // ignore
	    }
	    parameterExists = available;
	  }
	  
	private final MethodType methodType;
	private final Class<?> returnType;
	private final String name;
	private final List<String> argNames = new ArrayList<String>();
	
	private final boolean returnsMany;
	private final boolean returnsVoid;
	
	
	public static MethodType getMethodType(String methodName) {
		MethodType methodType = null;
		String name = methodName.toLowerCase();
		if (name.startsWith("get") || name.startsWith("find") || name.startsWith("query")) {
			methodType = MethodType.SELECT;
		} else if (name.startsWith("delete") || name.startsWith("remove")) {
			methodType = MethodType.DELETE;
		} else if (name.startsWith("insert") || name.startsWith("add") || name.startsWith("write")) {
			methodType = MethodType.INSERT;
		} else if (name.startsWith("update")) {
			methodType = MethodType.UPDATE;
		} 
		return methodType;
	}
	
	public MapperMethod(Class<?> mapperInterface, Method method,
			BufferConfig config) {
		methodType = getMethodType(method.getName());
		if (methodType == null) {
			throw new BindingException("Unkown method type : "+method.getName());
		}
		
		Type type = method.getGenericReturnType();
		if (type instanceof Class<?>) {
		    this.returnType = (Class<?>) type;
		} else if (type instanceof ParameterizedType) {
			returnType = (Class<?>) ((ParameterizedType)type).getRawType();
		} else {
			returnType = method.getReturnType();
		}
		
		returnsVoid =  void.class.equals(returnType);
		returnsMany = (Collection.class.isAssignableFrom(this.returnType) || this.returnType.isArray());
		
		this.name = mapperInterface.getName()+"."+method.getName();
		
		if (parameterExists) {
			throw new BindingException("Unknown java.lang.reflect.Parameter");
		}
		Parameter[] parameters = method.getParameters();
		for (Parameter parameter : parameters) {
			argNames.add(parameter.getName());
		}
		
		config.initMappedStatement(this.name, method, returnType);	
		
		
		
	}
	  private Object rowCountResult(int rowCount) {
		    final Object result;
		    if (returnsVoid) {
		      result = null;
		    } else if (Integer.class.equals(returnType) || Integer.TYPE.equals(returnType)) {
		      result = rowCount;
		    } else if (Long.class.equals(returnType) || Long.TYPE.equals(returnType)) {
		      result = (long)rowCount;
		    } else if (Boolean.class.equals(returnType) || Boolean.TYPE.equals(returnType)) {
		      result = rowCount > 0;
		    } else {
		      throw new BindingException("Mapper method '" + name + "' has an unsupported return type: " + returnType);
		    }
		    return result;
		  }
	  
	  
	    public Object convertArgsToCommandParam(Object[] args) {
	        final int paramCount = argNames.size();
	        if (args == null || paramCount == 0) {
	          return null;
	        } else if (paramCount == 1) {
	          return args[0];
	        } else {
	          final Map<String, Object> param = new TreeMap<String, Object>();
	          int i = 0;
	          for (String str : argNames) {
	            param.put(str, args[i]);
	            i++;
	          }
	          return param;
	        }
	      
	      }
	    
	public Object execute(Buffer buffer, Object[] args) {
		
		Object result;
		switch (methodType) {
		  case DELETE:
			result = rowCountResult(buffer.delete(name, convertArgsToCommandParam(args)));
			break;
		  case UPDATE:
			result = rowCountResult(buffer.update(name, convertArgsToCommandParam(args)));
			break;		   
		  case INSERT:
			result = rowCountResult(buffer.insert(name, convertArgsToCommandParam(args)));
			break;				
		  case SELECT: {
			  if (returnsMany) {
				  result = buffer.selectList(name, convertArgsToCommandParam(args));
			  } else {
				  result = buffer.selectOne(name, convertArgsToCommandParam(args));
			  }
			  break;
		  }
			  
		default:
		    throw new BindingException("Unknown execution method for: " + name);				
		}
		
	    if (result == null && returnType.isPrimitive() && !returnsVoid) {
	        throw new BindingException("Mapper method '" + name 
	            + " attempted to return null from a method with a primitive return type (" + returnType + ").");
	    }
	    
		return result;
	}

}
