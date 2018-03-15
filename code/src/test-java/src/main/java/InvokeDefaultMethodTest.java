import java.lang.invoke.MethodHandles;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.HashMap;
import java.util.Map;
import java.util.function.BiFunction;


interface ExampleMixin {
	  String getText();

	  default void printInfo(){
	    System.out.println(getText());
	  }
}
public class InvokeDefaultMethodTest {
	public static void main(String... args) throws Exception {

	    Object target = new Object();

	    Map<String, BiFunction<Object, Object[], Object>> behavior = new HashMap<>();

	    ExampleMixin dynamic =
	            (ExampleMixin) Proxy.newProxyInstance(Thread.currentThread().getContextClassLoader(),new Class[]{ExampleMixin.class}, (Object proxy, Method method, Object[] arguments) -> {

	                //custom mixin behavior
	                if(behavior.containsKey(method.getName())) {
	                    return behavior.get(method.getName()).apply(target, arguments);
	                //default mixin behavior
	                } else if (method.isDefault()) {
	                	final Constructor<MethodHandles.Lookup> constructor = MethodHandles.Lookup.class
	                	        .getDeclaredConstructor(Class.class, int.class);
	                	    if (!constructor.isAccessible()) {
	                	      constructor.setAccessible(true);
	                	    }
	                	    
	                    //this block throws java.lang.IllegalAccessException: no private access for invokespecial
	                    return constructor.newInstance(method.getDeclaringClass(),
	                            MethodHandles.Lookup.PRIVATE | MethodHandles.Lookup.PROTECTED
	                            | MethodHandles.Lookup.PACKAGE | MethodHandles.Lookup.PUBLIC)
	                    .unreflectSpecial(method, method.getDeclaringClass())
	                                        .bindTo(proxy)
	                                        .invokeWithArguments();
	                //no mixin behavior
	                } else if (ExampleMixin.class == method.getDeclaringClass()) {
	                    throw new UnsupportedOperationException(method.getName() + " is not supported");
	                //base class behavior
	                } else{
	                    return method.invoke(target, arguments);
	                }
	            });

	    //define behavior for abstract method getText()
	    behavior.put("getText", (o, a) -> o.toString() + " myText");

	    System.out.println(dynamic.getClass());
	    System.out.println(dynamic.toString());
	    System.out.println(dynamic.getText());

	    //print info should by default implementation
	    dynamic.printInfo();
	  }
}
