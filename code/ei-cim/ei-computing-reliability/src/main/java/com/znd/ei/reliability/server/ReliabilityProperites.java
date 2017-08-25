package com.znd.ei.reliability.server;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.boot.context.properties.EnableConfigurationProperties;

@ConfigurationProperties("storage")
@EnableConfigurationProperties(ReliabilityProperites.class)
public class ReliabilityProperites {

}
