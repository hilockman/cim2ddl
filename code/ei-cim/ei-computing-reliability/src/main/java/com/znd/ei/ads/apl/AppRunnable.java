package com.znd.ei.ads.apl;

public interface AppRunnable<S,T> {
	T exec(S input);
}
