package com.znd.ei.memdb;

import java.io.Serializable;

public interface MemIndexable extends  Serializable {
	 void setMemIndex(Integer memIndex);
	 Integer getMemIndex();
}
