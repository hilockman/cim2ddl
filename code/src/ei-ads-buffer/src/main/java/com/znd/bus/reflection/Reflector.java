package com.znd.bus.reflection;

import java.lang.reflect.Array;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.GenericArrayType;
import java.lang.reflect.Method;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.ReflectPermission;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Map.Entry;

public class Reflector {
	
	public final static class PropertyNamer {

		  private PropertyNamer() {
		    // Prevent Instantiation of Static Class
		  }

		  public static String methodToProperty(String name) {
		    if (name.startsWith("is")) {
		      name = name.substring(2);
		    } else if (name.startsWith("get") || name.startsWith("set")) {
		      name = name.substring(3);
		    } else {
		      throw new ReflectionException("Error parsing property name '" + name + "'.  Didn't start with 'is', 'get' or 'set'.");
		    }

		    if (name.length() == 1 || (name.length() > 1 && !Character.isUpperCase(name.charAt(1)))) {
		      name = name.substring(0, 1).toLowerCase(Locale.ENGLISH) + name.substring(1);
		    }

		    return name;
		  }

		  public static boolean isProperty(String name) {
		    return name.startsWith("get") || name.startsWith("set") || name.startsWith("is");
		  }

		  public static boolean isGetter(String name) {
		    return name.startsWith("get") || name.startsWith("is");
		  }

		  public static boolean isSetter(String name) {
		    return name.startsWith("set");
		  }

		}


  private final Class<?> type;
  private final String[] readablePropertyNames;
  private final String[] writeablePropertyNames;	
 // private final Map<String, Field> fieldMap = new HashMap<>();
  private Constructor<?> defaultConstructor;	
  private final Map<String, Method> setMethods = new HashMap<>();
  private final Map<String, Method> getMethods = new HashMap<>();
  private final Map<String, Class<?>> setTypes = new HashMap<String, Class<?>>();
  private final Map<String, Class<?>> getTypes = new HashMap<String, Class<?>>();
	  
	public Reflector(Class<?> type) {
		this.type = type;
		addDefaultConstructor(type);
	    addGetMethods(type);
	    addSetMethods(type);
	    readablePropertyNames = getMethods.keySet().toArray(new String[getMethods.keySet().size()]);
	    writeablePropertyNames = setMethods.keySet().toArray(new String[setMethods.keySet().size()]);
	 	    
//		Field[] fields = type.getFields();
//		for (Field field: fields) {
//			fieldMap.put(field.getName(), field);
//		}
	}
	

	  
	
	  private void addDefaultConstructor(Class<?> clazz) {
	    Constructor<?>[] consts = clazz.getDeclaredConstructors();
	    for (Constructor<?> constructor : consts) {
	      if (constructor.getParameterTypes().length == 0) {
	        if (canAccessPrivateMethods()) {
	          try {
	            constructor.setAccessible(true);
	          } catch (Exception e) {
	            // Ignored. This is only a final precaution, nothing we can do.
	          }
	        }
	        if (constructor.isAccessible()) {
	          this.defaultConstructor = constructor;
	        }
	      }
	    }
	  }	
	  private void addMethodConflict(Map<String, List<Method>> conflictingMethods, String name, Method method) {
	    List<Method> list = conflictingMethods.get(name);
	    if (list == null) {
	      list = new ArrayList<Method>();
	      conflictingMethods.put(name, list);
	    }
	    list.add(method);
	  }
	  /*
	   * This method returns an array containing all methods
	   * declared in this class and any superclass.
	   * We use this method, instead of the simpler Class.getMethods(),
	   * because we want to look for private methods as well.
	   *
	   * @param cls The class
	   * @return An array containing all methods in this class
	   */
	  private Method[] getClassMethods(Class<?> cls) {
	    Map<String, Method> uniqueMethods = new HashMap<String, Method>();
	    Class<?> currentClass = cls;
	    while (currentClass != null) {
	      addUniqueMethods(uniqueMethods, currentClass.getDeclaredMethods());

	      // we also need to look for interface methods -
	      // because the class may be abstract
	      Class<?>[] interfaces = currentClass.getInterfaces();
	      for (Class<?> anInterface : interfaces) {
	        addUniqueMethods(uniqueMethods, anInterface.getMethods());
	      }

	      currentClass = currentClass.getSuperclass();
	    }

	    Collection<Method> methods = uniqueMethods.values();

	    return methods.toArray(new Method[methods.size()]);
	  }
	  private String getSignature(Method method) {
	    StringBuilder sb = new StringBuilder();
	    Class<?> returnType = method.getReturnType();
	    if (returnType != null) {
	      sb.append(returnType.getName()).append('#');
	    }
	    sb.append(method.getName());
	    Class<?>[] parameters = method.getParameterTypes();
	    for (int i = 0; i < parameters.length; i++) {
	      if (i == 0) {
	        sb.append(':');
	      } else {
	        sb.append(',');
	      }
	      sb.append(parameters[i].getName());
	    }
	    return sb.toString();
	  }
	  
	  private static boolean canAccessPrivateMethods() {
	    try {
	      SecurityManager securityManager = System.getSecurityManager();
	      if (null != securityManager) {
	        securityManager.checkPermission(new ReflectPermission("suppressAccessChecks"));
	      }
	    } catch (SecurityException e) {
	      return false;
	    }
	    return true;
	  }
	  
	  public Constructor<?> getDefaultConstructor() {
	    if (defaultConstructor != null) {
	      return defaultConstructor;
	    } else {
	      throw new ReflectionException("There is no default constructor for " + type);
	    }
	  }
	  
  private void addUniqueMethods(Map<String, Method> uniqueMethods, Method[] methods) {
    for (Method currentMethod : methods) {
      if (!currentMethod.isBridge()) {
        String signature = getSignature(currentMethod);
        // check to see if the method is already known
        // if it is known, then an extended class must have
        // overridden a method
        if (!uniqueMethods.containsKey(signature)) {
          if (canAccessPrivateMethods()) {
            try {
              currentMethod.setAccessible(true);
            } catch (Exception e) {
              // Ignored. This is only a final precaution, nothing we can do.
            }
          }

          uniqueMethods.put(signature, currentMethod);
        }
      }
    }
  }	  
  

  private boolean isValidPropertyName(String name) {
    return !(name.startsWith("$") || "serialVersionUID".equals(name) || "class".equals(name));
  }
  
  private Class<?> typeToClass(Type src) {
    Class<?> result = null;
    if (src instanceof Class) {
      result = (Class<?>) src;
    } else if (src instanceof ParameterizedType) {
      result = (Class<?>) ((ParameterizedType) src).getRawType();
    } else if (src instanceof GenericArrayType) {
      Type componentType = ((GenericArrayType) src).getGenericComponentType();
      if (componentType instanceof Class) {
        result = Array.newInstance((Class<?>) componentType, 0).getClass();
      } else {
        Class<?> componentClass = typeToClass(componentType);
        result = Array.newInstance((Class<?>) componentClass, 0).getClass();
      }
    }
    if (result == null) {
      result = Object.class;
    }
    return result;
  }  
  
  private void addGetMethod(String name, Method method) {
    if (isValidPropertyName(name)) {
      getMethods.put(name, method);
      Type returnType = TypeParameterResolver.resolveReturnType(method, type);
      getTypes.put(name, typeToClass(returnType));
    }
  }
  private void resolveGetterConflicts(Map<String, List<Method>> conflictingGetters) {
    for (Entry<String, List<Method>> entry : conflictingGetters.entrySet()) {
      Method winner = null;
      String propName = entry.getKey();
      for (Method candidate : entry.getValue()) {
        if (winner == null) {
          winner = candidate;
          continue;
        }
        Class<?> winnerType = winner.getReturnType();
        Class<?> candidateType = candidate.getReturnType();
        if (candidateType.equals(winnerType)) {
          if (!boolean.class.equals(candidateType)) {
            throw new ReflectionException(
                "Illegal overloaded getter method with ambiguous type for property "
                    + propName + " in class " + winner.getDeclaringClass()
                    + ". This breaks the JavaBeans specification and can cause unpredictable results.");
          } else if (candidate.getName().startsWith("is")) {
            winner = candidate;
          }
        } else if (candidateType.isAssignableFrom(winnerType)) {
          // OK getter type is descendant
        } else if (winnerType.isAssignableFrom(candidateType)) {
          winner = candidate;
        } else {
          throw new ReflectionException(
              "Illegal overloaded getter method with ambiguous type for property "
                  + propName + " in class " + winner.getDeclaringClass()
                  + ". This breaks the JavaBeans specification and can cause unpredictable results.");
        }
      }
      addGetMethod(propName, winner);
    }
  }  
	private void addGetMethods(Class<?> cls) {
	    Map<String, List<Method>> conflictingGetters = new HashMap<String, List<Method>>();
	    Method[] methods = getClassMethods(cls);
	    for (Method method : methods) {
	      if (method.getParameterTypes().length > 0) {
	        continue;
	      }
	      String name = method.getName();
	      if ((name.startsWith("get") && name.length() > 3)
	          || (name.startsWith("is") && name.length() > 2)) {
	        name = PropertyNamer.methodToProperty(name);
	        addMethodConflict(conflictingGetters, name, method);
	      }
	    }
	    resolveGetterConflicts(conflictingGetters);
	}
	 private void resolveSetterConflicts(Map<String, List<Method>> conflictingSetters) {
	    for (String propName : conflictingSetters.keySet()) {
	      List<Method> setters = conflictingSetters.get(propName);
	      Class<?> getterType = getTypes.get(propName);
	      Method match = null;
	      ReflectionException exception = null;
	      for (Method setter : setters) {
	        Class<?> paramType = setter.getParameterTypes()[0];
	        if (paramType.equals(getterType)) {
	          // should be the best match
	          match = setter;
	          break;
	        }
	        if (exception == null) {
	          try {
	            match = pickBetterSetter(match, setter, propName);
	          } catch (ReflectionException e) {
	            // there could still be the 'best match'
	            match = null;
	            exception = e;
	          }
	        }
	      }
	      if (match == null) {
	        throw exception;
	      } else {
	        addSetMethod(propName, match);
	      }
	    }
	  }

	  private Method pickBetterSetter(Method setter1, Method setter2, String property) {
	    if (setter1 == null) {
	      return setter2;
	    }
	    Class<?> paramType1 = setter1.getParameterTypes()[0];
	    Class<?> paramType2 = setter2.getParameterTypes()[0];
	    if (paramType1.isAssignableFrom(paramType2)) {
	      return setter2;
	    } else if (paramType2.isAssignableFrom(paramType1)) {
	      return setter1;
	    }
	    throw new ReflectionException("Ambiguous setters defined for property '" + property + "' in class '"
	        + setter2.getDeclaringClass() + "' with types '" + paramType1.getName() + "' and '"
	        + paramType2.getName() + "'.");
	  }

	  private void addSetMethod(String name, Method method) {
	    if (isValidPropertyName(name)) {
	      setMethods.put(name, method);
	      Type[] paramTypes = TypeParameterResolver.resolveParamTypes(method, type);
	      setTypes.put(name, typeToClass(paramTypes[0]));
	    }
	  }
		  
	private void addSetMethods(Class<?> cls) {
	    Map<String, List<Method>> conflictingSetters = new HashMap<String, List<Method>>();
	    Method[] methods = getClassMethods(cls);
	    for (Method method : methods) {
	      String name = method.getName();
	      if (name.startsWith("set") && name.length() > 3) {
	        if (method.getParameterTypes().length == 1) {
	          name = PropertyNamer.methodToProperty(name);
	          addMethodConflict(conflictingSetters, name, method);
	        }
	      }
	    }
	    resolveSetterConflicts(conflictingSetters);
	}
//	public Field getField(String property) {
//		return fieldMap.get(property);
//	}
	public Class<?> getType() {
		return type;
	}
//	public Field[] getFields() {
//		return fieldMap.values().toArray(new Field[0]);
//	}
	
	
  public Method getGetInvoker(String propertyName) {
    Method method = getMethods.get(propertyName);
    if (method == null) {
      throw new ReflectionException("There is no getter for property named '" + propertyName + "' in '" + type + "'");
    }
    return method;
  }
  
  
  public Method getSetInvoker(String propertyName) {
    Method method = setMethods.get(propertyName);
    if (method == null) {
      throw new ReflectionException("There is no setter for property named '" + propertyName + "' in '" + type + "'");
    }
    return method;
  }

  /*
   * Gets an array of the readable properties for an object
   *
   * @return The array
   */
  public String[] getGetablePropertyNames() {
    return readablePropertyNames;
  }

  /*
   * Gets an array of the writeable properties for an object
   *
   * @return The array
   */
  public String[] getSetablePropertyNames() {
    return writeablePropertyNames;
  }
  /*
   * Gets the type for a property getter
   *
   * @param propertyName - the name of the property
   * @return The Class of the propery getter
   */
  public Class<?> getGetterType(String propertyName) {
    Class<?> clazz = getTypes.get(propertyName);
    if (clazz == null) {
      throw new ReflectionException("There is no getter for property named '" + propertyName + "' in '" + type + "'");
    }
    return clazz;
  }  
}

