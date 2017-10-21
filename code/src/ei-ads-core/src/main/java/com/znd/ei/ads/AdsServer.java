package com.znd.ei.ads;

/**
 * ads remote server interface
 * @author wangheng
 *
 */
public interface AdsServer {
	
	static final String ADS_GET_SERVERINFOS = "adsget_ServerInfos";
	static final String ADS_REPLY_SERVERINFOS = "adsreply_ServerInfos";
	static final String ADS_SERVERINFOS = "ads:server-infos";
	public static final String create_AllModel = "create_AllModel";
	public static final String create_BPAModel = "create_BPAModel";
	public static final String created_BPAModel = "created_BPAModel";
	public static final String created_PRModel = "created_PRModel";
	public static final String created_StateSampleTask = "created_StateSampleTask";
	public static final String created_StateEstimateTask = "created_StateEstimateTask";
	public static final String get_Reliability = "get_Reliability";
	public static final String created_StateSampleResult = "created_StateSampleResult";
	public static final String created_StateEsteimateResult = "created_StateEsteimateResult";
	public static final String created_ReliabilityIndexResult = "created_ReliabilityIndexResult";

	public final static String powersystem_reliability = "powersystem-reliability";

	public final static String state_estimate = "state-estimate";
	public final static String state_estimate_watch = "state-estimate-watch";
	public final static String state_sample = "state-sample";
	public final static String reliability_index = "reliability-index";
	String publish(String cc, String content);
}
