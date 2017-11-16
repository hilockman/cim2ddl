package com.znd.ei.ads.acp;

import com.znd.ei.ads.adf.ObjectRefData;

public interface ObjectRefDataOperations<T> extends IOOperations<ObjectRefData<T>> {

  T get(String key);
	
  void set(String key, T value);
		
  void decr(String key);

}
