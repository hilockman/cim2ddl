package com.znd.ei.adf.apl;

public interface AppRunnable<S,T> {
	T exec(S input);
}
