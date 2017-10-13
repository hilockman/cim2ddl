package com.znd.ei.ads;

import java.util.ArrayList;
import java.util.List;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Component
@ConfigurationProperties(prefix = "ads")
public class ADSProperties {

	private final List<String> aplSkip = new ArrayList<>();

	public List<String> getAplSkip() {
		return aplSkip;
	}

}
