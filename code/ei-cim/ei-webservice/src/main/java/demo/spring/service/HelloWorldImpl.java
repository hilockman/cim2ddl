package demo.spring.service;
 
import javax.jws.WebService;
 
@WebService(endpointInterface = "demo.spring.service.HelloWorld")
public class HelloWorldImpl implements HelloWorld {
 
    public String sayHi(String text) {
        System.out.println("sayHi called");
        return "Hello " + text;
    }
}