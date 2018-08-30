package com.znd.bus.server.message;

import java.util.List;

import com.znd.bus.message.OperationSet;

/**
 * 消息体
 * @author wangheng
 * @date 2018年8月28日
 * @time 上午9:33:06
 * @type_name Payload
 */
public class PayloadType {

    protected OperationSet operationSet;
    
	/**
	 * 默认不压缩，如果压缩采用gzip+base64，解压时用unbase64+ungzip
	 */

    protected Boolean compressed;
 
    
    protected List<ID> id;
	

	public Boolean getCompressed() {
		return compressed;
	}

	public void setCompressed(Boolean compressed) {
		this.compressed = compressed;
	}

}
