package demo.spring.service;
 
import javax.jws.WebService;
 
@WebService(endpointInterface = "demo.spring.service.HelloWorld")
public class HelloWorldImpl implements HelloWorld {
 
    public String sayHi(String username) {
        System.out.println("sayHi called");
        return "Hello, " + username;
    }

	@Override
	public String nullOper() {
		// TODO Auto-generated method stub
		return "Hello!";
	}
}