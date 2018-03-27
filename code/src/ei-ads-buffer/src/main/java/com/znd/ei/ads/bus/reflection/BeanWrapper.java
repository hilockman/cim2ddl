package com.znd.ei.ads.bus.reflection;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.UndeclaredThrowableException;


public class BeanWrapper implements ObjectWrapper {
	protected static final Object[] NO_ARGUMENTS = new Object[0];
	private final Reflector objectReflector;
	private final Object object;
	public BeanWrapper(MetaObject metaObject, Object object, ReflectorFactory reflectorFactory) {
		this.object = object;
		this.objectReflector = reflectorFactory.findForClass(object.getClass());
	}

	@Override
	public Object get(String prop) {
	  try {
        Method method = objectReflector.getGetInvoker(prop);
        try {
          return method.invoke(object, NO_ARGUMENTS);
        } catch (Throwable t) {
          throw unwrapThrowable(t);
        }
      } catch (RuntimeException e) {
        throw e;
      } catch (Throwable t) {
        throw new ReflectionException("Could not get property '" + prop + "' from " + object.getClass() + ".  Cause: " + t.toString(), t);
      }
	}
  public static Throwable unwrapThrowable(Throwable wrapped) {
    Throwable unwrapped = wrapped;
    while (true) {
      if (unwrapped instanceof InvocationTargetException) {
        unwrapped = ((InvocationTargetException) unwrapped).getTargetException();
      } else if (unwrapped instanceof UndeclaredThrowableException) {
        unwrapped = ((UndeclaredThrowableException) unwrapped).getUndeclaredThrowable();
      } else {
        return unwrapped;
      }
    }
  }
	@Override
	public void set(String prop, Object value) {
		try {
			Method method = objectReflector.getSetInvoker(prop);
			 Object[] params = {value};
			try {
				method.invoke(object, params);
			} catch (Throwable t) {
				unwrapThrowable(t);
			}
		
	    } catch (Throwable t) {
	      throw new ReflectionException("Could not set property '" + prop + "' of '" + object.getClass() + "' with value '" + value + "' Cause: " + t.toString(), t);
	    }
	}

}
