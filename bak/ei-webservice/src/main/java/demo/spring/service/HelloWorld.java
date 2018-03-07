package demo.spring.service;
 
import javax.jws.WebParam;
import javax.jws.WebService;
 
@WebService
public interface HelloWorld {
    String sayHi(@WebParam(name="username")String username);
    
    String nullOper();
}