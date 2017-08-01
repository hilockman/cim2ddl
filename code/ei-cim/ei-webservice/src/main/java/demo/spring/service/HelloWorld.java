package demo.spring.service;
 
import javax.jws.WebService;
 
@WebService
public interface HelloWorld {
    String sayHi(String text);
}