import java.lang.reflect.Method;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.util.List;


public class ReflectionTest {

	public static void main(String[] args) throws NoSuchMethodException, SecurityException {
		Method method = MyClass.class.getMethod("getStringList", null);

		System.out.println("getReturnType="+method.getReturnType());
		Type returnType = method.getGenericReturnType();

		if(returnType instanceof ParameterizedType){
		    ParameterizedType type = (ParameterizedType) returnType;
		    System.out.println("returnType = "+type);
		    System.out.println("rawType = "+type.getRawType());
		    Type[] typeArguments = type.getActualTypeArguments();
		    for(Type typeArgument : typeArguments){
		        Class typeArgClass = (Class) typeArgument;
		        System.out.println("typeArgClass = " + typeArgClass);
		    }
		}
	}

}


class MyClass {

  protected List<String> stringList;

  public List<String> getStringList(){
    return this.stringList;
  }
}