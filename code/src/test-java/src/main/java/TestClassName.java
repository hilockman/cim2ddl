import org.test.java.TestObjectIO;


public class TestClassName {

	public static void main(String [] args) {
		System.out.println("CanonicalName = "+TestObjectIO.class.getCanonicalName());
		System.out.println("Name = "+TestObjectIO.class.getName());
		System.out.println("SimpleName = "+TestObjectIO.class.getSimpleName());
	}
}
