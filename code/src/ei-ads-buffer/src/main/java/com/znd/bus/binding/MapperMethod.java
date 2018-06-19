package com.znd.bus.binding;

import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.reflection.TypeParameterResolver;
import com.znd.bus.type.TypeHandlerRegistry;

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
	
	private final TypeHandlerRegistry typeHandlerRegistry;
	private final MethodType methodType;
	private final Class<?> returnType;
	private Class<?> returnTypeArgument;
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
		} else if (name.startsWith("insert") || name.startsWith("add") || name.startsWith("write") || name.startsWith("save")) {
			methodType = MethodType.INSERT;
		} else if (name.startsWith("update")) {
			methodType = MethodType.UPDATE;
		} 
		return methodType;
	}
	
	//static Integer n = new Integer(0);
	public MapperMethod(Class<?> mapperInterface, Method method, TypeHandlerRegistry typeHandlerRegistry, String tableName) {
		this.typeHandlerRegistry = typeHandlerRegistry;
		methodType = getMethodType(method.getName());
		if (methodType == null) {
			throw new BindingException("Unkown method type : "+method.getName()+", in "+mapperInterface);
		}
		
		
		Type resolvedReturnType = TypeParameterResolver.resolveReturnType(method, mapperInterface);
		//Type type = method.getGenericReturnType();
		if (resolvedReturnType instanceof Class<?>) {
		    returnType = (Class<?>) resolvedReturnType;
		} else if (resolvedReturnType instanceof ParameterizedType) {
			returnType = (Class<?>) ((ParameterizedType)resolvedReturnType).getRawType();
			Type[] typeArguments = ((ParameterizedType)resolvedReturnType).getActualTypeArguments();
			if (typeArguments.length > 0) {
				returnTypeArgument = (Class<?>) typeArguments[0];
			}
		} else {
			returnType = method.getReturnType();
		}
		
		returnsVoid =  void.class.equals(returnType);
		returnsMany = (Collection.class.isAssignableFrom(this.returnType) || this.returnType.isArray());
		
		if (tableName == null)
			this.name = mapperInterface.getName()+"."+method.getName();
		else
			this.name = tableName+"."+method.getName();
		
		if (!parameterExists) {
			throw new BindingException("Unknown java.lang.reflect.Parameter");
		}
		Parameter[] parameters = method.getParameters();
		for (Parameter parameter : parameters) {
			argNames.add(parameter.getName());
		}
					
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
          Object arg = args[0];
          Class<? extends Object> argType = arg.getClass();
          if (typeHandlerRegistry.hasTypeHandler(argType)) {
        	  Map<String, Object> argMap = new HashMap<>();
        	  argMap.put(argNames.get(0), args[0]);
        	  return argMap;
          }
          return arg;
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

	public MethodType getMethodType() {
		return methodType;
	}

	public Class<?> getReturnTypeArgument() {
		return returnTypeArgument != null ? returnTypeArgument : returnType;
	}

	public String getName() {
		return name;
	}

}
