package com.znd.bus.server.message;

import java.util.ArrayList;
import java.util.List;

import com.znd.bus.server.CompressUtils;


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

    private Boolean compressed;
 
    
    private List<ID> id;
	
    
    private List<Object> any = new ArrayList<>();    



	public Boolean getCompressed() {
		return compressed;
	}

	public void setCompressed(Boolean compressed) {
		this.compressed = compressed;
	}

	public List<Object> getAny() {
		return any;
	}

	public void setAny(List<Object> any) {
		this.any = any;
	}

	public List<ID> getId() {
		return id;
	}

	public void setId(List<ID> id) {
		this.id = id;
	}
	
	
	public String getSimpleContent() {
		if (any == null || any.isEmpty() || any.get(0) == null)
			return null;
		
		String obj = any.get(0).toString();
		if (compressed != null && compressed) {
			return  CompressUtils.decodeAndUncompressToString(obj);
		} else {
			return obj;
		}
	}
	
	public static class Builder {
	    protected OperationSet operationSet;
	    
		/**
		 * 默认不压缩，如果压缩采用gzip+base64，解压时用unbase64+ungzip
		 */
	    private Boolean compressed;
	 
	    
	    private List<ID> id;
		
	    
	    private List<Object> any = new ArrayList<>(); 
	    
	    public Builder() {
	    	
	    }
	    	    
	    public Builder operationSet(OperationSet operationSet) {
	    	this.operationSet = operationSet;
	    	return this;
	    }
	    
	    public Builder id(List<ID> id) {
	    	this.id = id;
	    	return this;
	    }
	    
	    public Builder compressed(Boolean compressed) {
	    	this.compressed = compressed;
	    	return this;
	    }
	    
	    public Builder any(Object...objects) {
	    	for (Object object : objects) {
	    		this.any.add(object);
	    	}
	    	return this;
	    }
	    
		public Builder content(String content) {
			this.any.add(content);
			return this;
		}
		
	    public Builder  any(List<Object> any) {
	    	this.any = any;
	    	return this;
	    }
	    
	    public PayloadType build() {
	    	if (compressed != null && compressed) {
	    		int i = 0;
				for (Object o : this.any) {
					
					String c ;
					if (o instanceof String) {
						c = (String)o;
						
					} else {
						c = o.toString();
						
					}
					c = CompressUtils.compressAndEncodeToString(c);
					this.any.set(i, c);
					i++;
				}
	    	}

			
	    	return new PayloadType(this);
	    }
	    
	}
	
	public PayloadType(Builder b) {
		this.operationSet = b.operationSet;
		this.compressed = b.compressed;
		this.any = b.any;
		this.id = b.id;
	}
	
	
	

}
