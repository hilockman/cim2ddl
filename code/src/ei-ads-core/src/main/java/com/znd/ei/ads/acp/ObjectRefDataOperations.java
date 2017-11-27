package com.znd.ei.ads.acp;


public interface ObjectRefDataOperations extends IOOperations {

 <T> T get(String key);
	
 <T> void set(String key, T value);
		
 <T>  void decr(String key);

}
